#include<stdio.h>
#include<stdlib.h>
#define HEIGHT 15
#define WIDTH  30
#define TEXT_SIZE 2*HEIGHT*WIDTH+1 //最大で200%

void initialize(char matrix[HEIGHT][WIDTH]);
void runlength_save(FILE *fp,char matrix[HEIGHT][WIDTH]);
void file_read(FILE *fp,char s[TEXT_SIZE]);
void file_deployment(char matrix[HEIGHT][WIDTH],char string[TEXT_SIZE]);
void drawing(char matrix[HEIGHT][WIDTH]);
void matrix_update(char matrix[HEIGHT][WIDTH]);

int main(){
  char matrix[HEIGHT][WIDTH];
  FILE *fp;
  fp = fopen("data.txt","w");
  fclose(fp);//初期化
  char str[TEXT_SIZE];

  initialize(matrix);
  runlength_save(fp,matrix);
  while(1){
    system("clear");
    file_read(fp,str);
    file_deployment(matrix,str);
    drawing(matrix);
    matrix_update(matrix);
    runlength_save(fp,matrix);
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


void runlength_save(FILE *fp,char matrix[HEIGHT][WIDTH]){  //その１
  int i,j;
  char w = matrix[0][0]; //直前の文字
  char int_char[1] = " ";//繰り返し回数　最大9回まで
  int rep = 0;//繰り返し回数のカウント

  fp = fopen("data.txt","w");
  for(i = 0; i < HEIGHT; i++){
    for(j = 0; j < WIDTH; j++){
      if(w == matrix[i][j]){
       	rep++;       //直前の文字と同じだったら
      }else{
	sprintf(int_char,"%d",rep);
	fprintf(fp,"%c%c",w,int_char[0]);
	w = matrix[i][j];
	rep = 1;
      }
    }
  }
  sprintf(int_char,"%d",rep);
  fprintf(fp,"%c%c",w,int_char[0]);
 fclose(fp);
}

void file_read(FILE *fp,char str[TEXT_SIZE]){
  if((fp = fopen("data.txt","r")) == NULL){     //その２ 課題３のまま
    printf("ファイルが見つかりません");
    exit(EXIT_FAILURE);
  }
  fgets(str,TEXT_SIZE,fp);
  fclose(fp);
}


void file_deployment(char matrix[HEIGHT][WIDTH],char str[TEXT_SIZE]){
  //読み込んだ文字列を配列に戻す
  int i,j;
  int rep = 0;//繰り返し回数(最大9回)
  int cnt = 0;//展開位置
  char a[] = " ";//現在の文字

  for(i = 0; i < HEIGHT; i++){
    for(j = 0; j < WIDTH; j++){
      if(rep == 0||rep > 9){
	a[0] = str[cnt];
	rep = atoi(&str[++cnt]);
	cnt++;

	matrix[i][j] = a[0];
	rep--;
      }else{
	matrix[i][j] = a[0];
	rep--;
      }
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
