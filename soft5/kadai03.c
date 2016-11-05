#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define HEIGHT 15
#define WIDTH  30
#define TEXT_SIZE HEIGHT*WIDTH+1 //\0のために+1

void initialize(char matrix[HEIGHT][WIDTH]);
void file_save(FILE *fp,char matrix[HEIGHT][WIDTH]);
void file_read(FILE *fp,char s[TEXT_SIZE]);
void file_deployment(char matrix[HEIGHT][WIDTH],char string[TEXT_SIZE]);
void drawing(char matrix[HEIGHT][WIDTH]);
void matrix_update(char matrix[HEIGHT][WIDTH]);


int main(){
  char matrix[HEIGHT][WIDTH];
  FILE *fp;
  fp = fopen("data.txt","w");
  fclose(fp);//初期化
  char s[TEXT_SIZE]; 

  initialize(matrix);
  file_save(fp,matrix);
 
  while(1){
    system("clear");

    file_read(fp,s);
    file_deployment(matrix,s);     
    drawing(matrix);

    matrix_update(matrix);
    
    file_save(fp,matrix);
  }
  return 0;
}


void initialize(char matrix[HEIGHT][WIDTH]){
  int i,j;
  for(i = 0;i < HEIGHT;i++){
    for(j = 0;j < WIDTH;j++){
      matrix[i][j] = '.';
    }
  }
}


void file_save(FILE *fp,char matrix[HEIGHT][WIDTH]){  //その１ 書き込み
  int i,j;
  fp = fopen("data.txt","w");
  for(i = 0; i < HEIGHT; i++){
    for(j = 0; j < WIDTH; j++){
      fprintf(fp,"%c",matrix[i][j]);
    }
  }
  fclose(fp);
}


void file_read(FILE *fp,char str[TEXT_SIZE]){
  if((fp = fopen("data.txt","r")) == NULL){     //その２ 読み込み
    printf("ファイルが見つかりません");
    exit(EXIT_FAILURE);
  }    
  fgets(str,TEXT_SIZE,fp);   
  fclose(fp);
}


void file_deployment(char matrix[HEIGHT][WIDTH],char str[TEXT_SIZE]){
  //読み込んだ文字列を配列に戻す
  int i,j;
  for(i = 0; i < HEIGHT; i++){
    for(j = 0; j < WIDTH; j++){
      matrix[i][j]=str[i*WIDTH + j];         //!! i*HEIGHTではない...
    }
  }
}


void drawing(char matrix[HEIGHT][WIDTH]){
  int i,j;
  for(i = 0; i < HEIGHT; i++){
    for(j = 0; j < WIDTH; j++){
      putchar(matrix[i][j]);
      putchar(' ');
    }
    putchar('\n');
  }
}


void matrix_update(char matrix[HEIGHT][WIDTH]){
  int i = -1,j = -1;
  int cnt_error = 0;
  char *input;
  input = (char *)malloc(sizeof(char));
  while (i<0||j<0||i>=HEIGHT||j>=WIDTH){
    //形式に沿わない or matrixサイズ以上の入力 でエラー
    if(cnt_error > 0){
      printf("入力に誤りがありました!\n");
      exit(EXIT_FAILURE);
    }
    scanf("%d %d %c",&i,&j,input);
    cnt_error++;
  }
  matrix[i][j] = *input;
  free(input);
}
