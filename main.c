#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "algorithms.h"
#include "seats.h"
#include "sets.h" //����и����μ��� ���� 

int main() {
  int jjag[50][2];
  char gender[100];
  int seat[6][10] = {0,};
  int choice = 10;
  while(1){
  printf("¦ ������ ���Ѵٸ� 1�� �ڸ� ��ġ�� ���Ѵٸ� 2�� ������ �ּ���. ���α׷��� �����Ϸ��� 0�� �����ּ���.\n");
  scanf("%d", &choice);
  if(choice==0) break;
  else if (choice != 1 && choice != 2 && choice != 0) {
    printf("�߸��� �����Դϴ�. 1�Ǵ� 2�� �Է��� �ּ���\n");
  }
  if (choice == 1)
    jjagset_gender(jjag,gender,seat);
  else if(choice == 2)
    seatjjagset(jjag,gender,seat);
}
printf("\n");
printf("���α׷� ����");
printf("\n���α׷� ��: ¦����\n ������: 2023.11.6\n ������:\n ������ kevin070209@gmail.com\n ������ aidenselfin@gmail.com \n ���ϰ��а� \n\n \"¦����\"�� �̿����ּż� �����մϴ�");
return 0;
}
