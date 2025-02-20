#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "algorithms.h"
#include "seats.h"

void seatjjagset(int jjag[][2],char gender[],int seat[][10]) {
  int n, sepgen, a; // n�� �����
  int i, j, e, x; //restart�� �ٽ� ���� ���� �������� �Ǵ� 
  int *y = &a; // y�� ������ ¦�� ��
  a = 0;
  double aeo[100][100] = {0};
  int data[100][100] = {0};
  char namelist[100][50];
  sepgen = 0;
  printf("��� ���� �Է��ϼ���: ");
  scanf("%d", &n);
  while (n < 1 && n > 100) {
    printf("1~100�� ���̸� �Է� �����մϴ�.: ");
    scanf("%d", &n);
  }
  for (i = 0; i < n; i++) {
    printf("�л� %d�� �̸��� �Է��ϼ���. : ",i+1);
    scanf("%s",namelist[i]);
    }


  printf("�ڸ��� ���� �� ������ �Է��ϼ���: ");
  scanf("%d", &x);
  while (x > n / 2) {
    printf("���� ��� ���� ���� �ʹ� �����ϴ�. �ٽ� �Է��� �ּ���. :");
    scanf("%d", &x);
  }
  seat_input(n, x, seat);
    system("cls");
  for (i = 0; i < n; i++) {
  	int re=0;
  	printf("%s�� ģ�е� �Է��� �����մϴ�. ģ�е��� ������ 1���� 10 ������ ������ �Է��� �ּ���. ���� ó������ ģ�е��� �ٽ� �Է��ϰ� �����ôٸ� 404�� �Է��ϼ���.\n",namelist[i]);
      for (j = 0; j < n; j++) {
      if (i != j) {
        printf("%s�� %s�� ���� ģ�е� �Է� (1~10): ", namelist[i],
           namelist[j]);
        scanf("%d", &data[i][j]);
        fflush(stdin); 
        if(data[i][j]==404){
          	  i--;
			  break;
		  } 
        while (data[i][j] < 1 || data[i][j] > 10) {

          printf("ģ�е� ���� 1~10 ������ ������ �Է����ּ���. \n");
          printf("%s�� %s�� ���� ģ�е� �ٽ� �Է�: ", namelist[i],
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
  int n, sepgen, a=0; // n�� �����
  int i, j, e;
  int *y = &a;
  double aeo[100][100] = {0};
  int data[100][100] = {0};
  char namelist[100][20];
  printf("���� �и� ���θ� �˷��ּ���. 0�� ������ ���� �������� ģ�е����� �������� �����ǰ�, 1�� ������ ���� ����������, 2�� ������ �ٸ� ���������� �����˴ϴ�.\n");
  scanf("%d", &sepgen);
  while (sepgen!=0 && sepgen!=1 && sepgen!=2) {
    printf("0 �Ǵ� 1 �Ǵ� 2 �� �ϳ��� �Է����ּ���. : ");
    scanf("%d", &sepgen);
    fflush(stdin);
  }
  printf("��� ���� �Է��ϼ���. ��� ���� 1~100�� ������ �������� �մϴ�. : ");
  scanf("%d", &n);
  while (n < 1 && n > 100) {
    printf("1~100�� ���̸� �Է� �����մϴ�.: ");
    scanf("%d", &n);
    fflush(stdin); 
  }
  for (i = 0; i < n; i++) {
    printf("�л� %d�� �̸��� �Է��ϼ���. : ",i+1);
    scanf("%s",namelist[i]);
    }
    system("cls");
  for (i = 0; i < n; i++) {
    if (sepgen > 0) {
      printf("%s�� ������ �Է��ϼ��� (M: ����, F: ����): ", namelist[i]);
      if(i==0) getchar();
      scanf("%c", &gender[i]);
      while (gender[i] != 'M' && gender[i] != 'F') {
        printf("%s�� ���� �ٽ� �Է��ϼ��� M�Ǵ� F�� �Է� �����մϴ�.: ",
               namelist[i]);
        getchar();
        scanf("%c", &gender[i]);
      }
    }

    int re = 0;
  	printf("%s�� ģ�е� �Է��� �����մϴ�. ģ�е��� ������ 1���� 10 ������ ������ �Է��� �ּ���. ���� ó������ ģ�е��� �ٽ� �Է��ϰ� �����ôٸ� 404�� �Է��ϼ���.\n",namelist[i]);
      for (j = 0; j < n; j++) {
      if (i != j) {
        printf("%s�� %s�� ���� ģ�е� �Է� (1~10): ", namelist[i],
           namelist[j]);
        scanf("%d", &data[i][j]);
        fflush(stdin);
        if(data[i][j]==404){
          	  i--;
			  break;
		  } 
        while (data[i][j] < 1 || data[i][j] > 10) {

          printf("ģ�е� ���� 1~10 ������ ������ �Է����ּ���. \n");
          printf("%s�� %s�� ���� ģ�е� �ٽ� �Է�: ", namelist[i],
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
	printf("¦ ���� ���: \n");
  for (e = 0; e < *y; e++) { //¦���
    printf("%s ", namelist[jjag[e][0]]);
    if (jjag[e][1] != 101)
      printf("%s\n", namelist[jjag[e][1]]);
    else
      printf("\n");
  }
}

