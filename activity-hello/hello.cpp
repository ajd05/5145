#include <iostream>
#include <unistd.h>

int main () {
  char hostname[20];
  int hnlen = 19;
  gethostname(hostname, hnlen);
  printf("Hostname is %s \n", hostname);
  return 0;
}
