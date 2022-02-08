#include <stdio.h>
#include <string.h>
#include <unistd.h>    // Unix-like system calls read and write
#include <fcntl.h>     // Unix-like system calls to open and close
#include <stdlib.h>    // For rand() 

#include "myutils.h"

int main(int argc, char* argv[]) {
  int num, fd, i;

  if(argc < 2) {
  	printf("usage: %s 30   // to generate a binary file with 30 integers\n", argv[0]);
  	_exit(-1);
  }
  sscanf(argv[1], "%d", &num);
  printf("The first argument is %s and its conversion to int is = %d\n", argv[1], num);


  int* a = malloc(sizeof(int)*num); 
  for(i=0;i<num;i++) {
    a[i] = rand()%100;
  }

  fd = open("nums.dat", O_CREAT | O_RDWR, 0644); 
  write(fd,a,sizeof(int)*num);
  close(fd);

  printf("File nums.dat has been written with total size of %d bytes\n", get_file_size("nums.dat"));

  free(a);

  return 0;
}
