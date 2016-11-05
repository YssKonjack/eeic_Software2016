#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define WIDTH  30
#define HEIGHT 15

int main(){
  char matrix[HEIGHT][WIDTH];
  int i,j,sec;
  
  //initialization
  
  for(i = 0;i < HEIGHT;i++){
    for(j = 0;j < WIDTH;j++){
      matrix[i][j] = '.';
    }
  }
  
  //print
  for(sec = 0;sec <= HEIGHT;sec++){
    system("clear");
    for(i = 0;i < HEIGHT;i++){
      for(j = 0;j < WIDTH;j++){
	putchar(matrix[i][j]);
	putchar(' ');
      }
      putchar('\n');
    }
    sleep(1);

    matrix[sec][sec] = '*';
  }
  
  return 0;
}

