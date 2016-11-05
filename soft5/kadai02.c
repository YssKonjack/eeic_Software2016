#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define WIDTH  30
#define HEIGHT 15

int main(){
  char matrix[HEIGHT][WIDTH];
  int i,j;
  
  //initialization
  for(i = 0;i < HEIGHT;i++){
    for(j = 0;j < WIDTH;j++){
      matrix[i][j] = '.';
    }
  }
  

  int mati,matj;
  char *input;
  input = (char *)malloc(sizeof(char));
    
  while(1){
    system("clear");
    for(i = 0;i < HEIGHT;i++){
      for(j = 0;j < WIDTH;j++){
	putchar(matrix[i][j]);
	putchar(' ');
      }
      putchar('\n');
    }

    scanf("%d %d %c",&mati,&matj,input);
    matrix[mati][matj] = *input;
  }
  
  return 0;
}

