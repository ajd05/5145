#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include <chrono>
#include "omp_loop.hpp"

#ifdef __cplusplus
extern "C" {
#endif

  void generateMergeSortData (int* arr, size_t n);
  void checkMergeSortResult (const int* arr, size_t n);

#ifdef __cplusplus
}
#endif

void swapped(int* arr, int i, int j){
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int main (int argc, char* argv[]) {
  if (argc < 3) { std::cerr<<"usage: "<<argv[0]<<" <n> <nbthreads>"<<std::endl;
    return -1;
  }

  OmpLoop omp;

  int n = atoi(argv[1]);
  int threads = atoi(argv[2]);
  
  // get arr data
  int * arr = new int [n];
  generateMergeSortData (arr, n);

  //insert sorting code here.
  std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

  int swap = 1;
  while(swap){
    swap = 0;

    for(int k = 0; k < n; k++){
      if(k % 2 == 0){
	omp.parfor<float>(0, (n/2), 1,
			  [&] (float& tls) -> void { },
			  [&] (int i, float& tls) -> void {
			    if(arr[2*i] > arr[(2*i) + 1]){
			      swapped(arr, 2*i, (2*i) + 1);
			      swap = 1;
			    }
			  },
			  [&] (float tls) -> void { });
      } else {
		omp.parfor<float>(1, (n/2) + n % 2, 1,
			  [&] (float& tls) -> void { },
			  [&] (int i, float& tls) -> void {
			    if(arr[(2*i) - 1] > arr[(2*i)]){
			      swapped(arr, (2*i) - 1, (2*i));
			      swap = 1;
			    }
			  },
			  [&] (float tls) -> void { });
      }
    }
  }

  std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
  std::chrono::duration<double> elpased_seconds = end-start;
  
  checkMergeSortResult (arr, n);
  
  std::cerr<<elpased_seconds.count()<<std::endl;
  delete[] arr;

  return 0;
}
