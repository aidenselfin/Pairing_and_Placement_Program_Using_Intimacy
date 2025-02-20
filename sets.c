#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "algorithms.h"
#include "seats.h"

void seatjjagset(int jjag[][2],char gender[],int seat[][10]) {
  int n, sepgen, a; // n은 사람수
  int i, j, e, x; //restart는 다시 시작 할지 안할지를 판단 
  int *y = &a; // y는 생성된 짝의 수
  a = 0;
  double aeo[100][100] = {0};
  int data[100][100] = {0};
  char namelist[100][50];
  sepgen = 0;
  printf("사람 수를 입력하세요: ");
  scanf("%d", &n);
  while (n < 1 && n > 100) {
    printf("1~100명 사이만 입력 가능합니다.: ");
    scanf("%d", &n);
  }
  for (i = 0; i < n; i++) {
    printf("학생 %d의 이름을 입력하세요. : ",i+1);
    scanf("%s",namelist[i]);
    }


  printf("자리의 세로 줄 개수를 입력하세요: ");
  scanf("%d", &x);
  while (x > n / 2) {
    printf("줄이 사람 수에 비해 너무 많습니다. 다시 입력해 주세요. :");
    scanf("%d", &x);
  }
  seat_input(n, x, seat);
    system("cls");
  for (i = 0; i < n; i++) {
  	int re=0;
  	printf("%s의 친밀도 입력을 시작합니다. 친밀도는 무조건 1에서 10 사이의 정수로 입력해 주세요. 만약 처음부터 친밀도를 다시 입력하고 싶으시다면 404를 입력하세요.\n",namelist[i]);
      for (j = 0; j < n; j++) {
      if (i != j) {
        printf("%s의 %s에 대한 친밀도 입력 (1~10): ", namelist[i],
           namelist[j]);
        scanf("%d", &data[i][j]);
        fflush(stdin); 
        if(data[i][j]==404){
          	  i--;
			  break;
		  } 
        while (data[i][j] < 1 || data[i][j] > 10) {

          printf("친밀도 값은 1~10 사이의 정수로 입력해주세요. \n");
          printf("%s의 %s에 대한 친밀도 다시 입력: ", namelist[i],
                 namelist[j]);
          scanf("%d", &data[i][j]);
        if(data[i][j]==404){
          	  i--;
          	  re++;
			  break;
		  } 

        }
        if(re==1) break;
      }
    }
    system("cls");
  }
  
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i != j) {
        aeo[i][j] = (double)(data[i][j] + data[j][i]) / 2 -
                    (double)(sqrt(abs(data[i][j] - data[j][i]))) +
                    (double)(rand() % 100) / 1000;
      } else
        aeo[i][j] = 0.05;
    }
  }
	match(aeo, data, n, y, sepgen, jjag, gender);
  for (i = 0; i < n; i++) {
    if (aeo[i][i] == 0.05) {
      aeo[i][i] = 0;
      jjag[*y][0] = i;
      jjag[*y][1] = 101;
      (*y)++;
    }
  }
  seat_output(x, n, namelist, jjag, seat);
}
void jjagset_gender(int jjag[][2],char gender[],int seat[][10]) {
  int n, sepgen, a=0; // n은 사람수
  int i, j, e;
  int *y = &a;
  double aeo[100][100] = {0};
  int data[100][100] = {0};
  char namelist[100][20];
  printf("남녀 분리 여부를 알려주세요. 0을 누르면 남녀 랜덤으로 친밀도만을 기준으로 배정되고, 1을 누르면 같은 성별끼리만, 2를 누르면 다른 성별끼리만 배정됩니다.\n");
  scanf("%d", &sepgen);
  while (sepgen!=0 && sepgen!=1 && sepgen!=2) {
    printf("0 또는 1 또는 2 중 하나를 입력해주세요. : ");
    scanf("%d", &sepgen);
    fflush(stdin);
  }
  printf("사람 수를 입력하세요. 사람 수는 1~100명 사이의 정수여야 합니다. : ");
  scanf("%d", &n);
  while (n < 1 && n > 100) {
    printf("1~100명 사이만 입력 가능합니다.: ");
    scanf("%d", &n);
    fflush(stdin); 
  }
  for (i = 0; i < n; i++) {
    printf("학생 %d의 이름을 입력하세요. : ",i+1);
    scanf("%s",namelist[i]);
    }
    system("cls");
  for (i = 0; i < n; i++) {
    if (sepgen > 0) {
      printf("%s의 성별을 입력하세요 (M: 남성, F: 여성): ", namelist[i]);
      if(i==0) getchar();
      scanf("%c", &gender[i]);
      while (gender[i] != 'M' && gender[i] != 'F') {
        printf("%s의 성별 다시 입력하세요 M또는 F만 입력 가능합니다.: ",
               namelist[i]);
        getchar();
        scanf("%c", &gender[i]);
      }
    }

    int re = 0;
  	printf("%s의 친밀도 입력을 시작합니다. 친밀도는 무조건 1에서 10 사이의 정수로 입력해 주세요. 만약 처음부터 친밀도를 다시 입력하고 싶으시다면 404를 입력하세요.\n",namelist[i]);
      for (j = 0; j < n; j++) {
      if (i != j) {
        printf("%s의 %s에 대한 친밀도 입력 (1~10): ", namelist[i],
           namelist[j]);
        scanf("%d", &data[i][j]);
        fflush(stdin);
        if(data[i][j]==404){
          	  i--;
			  break;
		  } 
        while (data[i][j] < 1 || data[i][j] > 10) {

          printf("친밀도 값은 1~10 사이의 정수로 입력해주세요. \n");
          printf("%s의 %s에 대한 친밀도 다시 입력: ", namelist[i],
                 namelist[j]);
          scanf("%d", &data[i][j]);
        if(data[i][j]==404){
          	  re++;
          	  i--;
			  break;
		  } 

        }
        if(re==1) break;
      }
    }
    system("cls");
}
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i != j) {
        aeo[i][j] = (double)(data[i][j] + data[j][i]) / 2 -
                    (double)(sqrt(abs(data[i][j] - data[j][i]))) +
                    (double)(rand() % 100) / 1000;
      } else
        aeo[i][j] = 0.05;
    }
  }

	match(aeo, data, n, y, sepgen, jjag, gender);

  for (i = 0; i < n; i++) {
    if (aeo[i][i] == 0.05) {
      aeo[i][i] = 0;
      jjag[*y][0] = i;
      jjag[*y][1] = 101;
      (*y)++;
    }
  }
	printf("짝 배정 결과: \n");
  for (e = 0; e < *y; e++) { //짝출력
    printf("%s ", namelist[jjag[e][0]]);
    if (jjag[e][1] != 101)
      printf("%s\n", namelist[jjag[e][1]]);
    else
      printf("\n");
  }
}

