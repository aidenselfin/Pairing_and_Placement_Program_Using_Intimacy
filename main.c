#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "algorithms.h"
#include "seats.h"
#include "sets.h" //남녀분리여부숫자 고쳐 

int main() {
  int jjag[50][2];
  char gender[100];
  int seat[6][10] = {0,};
  int choice = 10;
  while(1){
  printf("짝 배정을 원한다면 1을 자리 배치를 원한다면 2을 선택해 주세요. 프로그램을 종료하려면 0을 눌러주세요.\n");
  scanf("%d", &choice);
  if(choice==0) break;
  else if (choice != 1 && choice != 2 && choice != 0) {
    printf("잘못된 선택입니다. 1또는 2를 입력해 주세요\n");
  }
  if (choice == 1)
    jjagset_gender(jjag,gender,seat);
  else if(choice == 2)
    seatjjagset(jjag,gender,seat);
}
printf("\n");
printf("프로그램 종료");
printf("\n프로그램 명: 짝짓기\n 제작일: 2023.11.6\n 제작자:\n 김지혁 kevin070209@gmail.com\n 김주현 aidenselfin@gmail.com \n 전북과학고 \n\n \"짝짓기\"를 이용해주셔서 감사합니다");
return 0;
}
