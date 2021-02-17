#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

float f1(float x, int intensity);
float f2(float x, int intensity);
float f3(float x, int intensity);
float f4(float x, int intensity);

#ifdef __cplusplus
}
#endif

  
int main (int argc, char* argv[]) {

  if (argc < 6) {
    std::cerr<<"usage: "<<argv[0]<<" <functionid> <a> <b> <n> <intensity>"<<std::endl;
    return -1;
  }

  int functionID = atoi(argv[1]);
  float lowerBound = std::stof(argv[2]);
  float upperBound = std::stof(argv[3]);
  int numOfPoints = atoi(argv[4]);
  int intensity = atoi(argv[5]);
  float functionResult = 0.0;
  float x = 0.0;
  float sumValue = 0.0;
  float finalValue = 0.0;

   auto start = std::chrono::steady_clock::now();
  
    switch(functionID)
      {
      case 1:
	for (int i = 0; i < numOfPoints; i++)
	  {
	    x = lowerBound + (i + 0.5) * (((upperBound-lowerBound)/numOfPoints));
	    functionResult = f1(x, intensity);
	    sumValue = sumValue + functionResult;
	  }
	finalValue = ((upperBound-lowerBound)/numOfPoints) * sumValue;
	break;
      case 2:
	for (int i = 0; i < numOfPoints; i++)
	  {
x = lowerBound + (i + 0.5) * (((upperBound-lowerBound)/numOfPoints));
	     functionResult = f2(x, intensity);
	    sumValue = sumValue + functionResult;
	  }
	finalValue = ((upperBound-lowerBound)/numOfPoints) * sumValue;
	break;
      case 3:
	for (int i = 0; i < numOfPoints; i++)
	  {
	    x = lowerBound + (i + 0.5) * (((upperBound-lowerBound)/numOfPoints));
	     functionResult = f3(x, intensity);
	    sumValue = sumValue + functionResult;
	  }
	finalValue = ((upperBound-lowerBound)/numOfPoints) * sumValue;
	break;
      case 4:
	for (int i = 0; i < numOfPoints; i++)
	  {
	    x = lowerBound + (i + 0.5) * (((upperBound-lowerBound)/numOfPoints));
	     functionResult = f4(x, intensity);
	    sumValue = sumValue + functionResult;
	  }
	finalValue = ((upperBound-lowerBound)/numOfPoints) * sumValue;
	break;
      default:
	std::cerr<<"Invalid function ID."<<std::endl;
      }
    
  auto end = std::chrono::steady_clock::now();

  std::cout<<finalValue;
	
  std::chrono::duration<double> seconds_elapsed = end-start;
  std::cerr<<seconds_elapsed.count();
	    
  return 0;
}
