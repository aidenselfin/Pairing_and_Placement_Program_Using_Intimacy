#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void seat_input(int n, int x, int seat[][10]) {
  printf("자리 배치를 *로 입력해 주세요. 입력된 자리 배치에 따라 자리를 "
         "배정해드립니다.\n");
  printf("\n예시 입력\n** **\n** **\n예시 출력\n박지은 송채정\t신채연 "
         "안수빈\t\n장서희 홍예주\t권용현 김도윤\n");
  printf("\n자리 배치는 6x10 이하여야 합니다.\n\n");
  int i, sum = 0;
  char s[11];
if(n%2==1) printf("학생 수가 홀수이므로, 자리표를 입력할 때 혼자 앉는 자리만 빼고 입력해주세요. 마지막 남은 사람은 맨 뒤에 출력됩니다.\n");
  for (i = 0; i <= x; i++) {
    fgets(s, 10, stdin);
    int k = 0;
    int j;
    for (j = 0; s[j] != 0; j++) {
      if ((s[j] == '*' && s[j + 1] == '*' && s[j + 2] == '*') ||
          (s[j] == '*' && s[j + 1] == ' ' && j == 0) ||
          (s[j] == '*' && s[j + 1] == ' ' && s[j - 1] == ' ') ||
          (s[j] == '*' && s[j - 1] == ' ' && s[j + 1] != '*') ||
          (s[j] == ' ' && s[j + 1] == ' ')) {
        printf(
            "저희 서비스는 짝 짓기 알고리즘을 바탕으로 자리를 배치해주기 "
            "때문에, 2명이 붙어있는 자리 표만 배치가 가능합니다. 또한, 공백은 "
            "한 번에 한 칸씩만 입력해 주십시오. 자리를 다시 입력해 주세요.\n");
        k++;
        break;
      }
    }
    if (k == 1)
      i--;
    else {
      for (j = 0; s[j] != 0; j++) {
        if (s[j] == '*') {
          seat[i - 1][j] = 1;
          sum++;
        }
      }
    }

    if (i == x) {
      if(n%2==1) sum++;
      if(sum!=n){
      i = 0;
      sum = 0;
      int i0, j0;
      for (i0 = 0; i0 < 7; i0++) {
        for (j0 = 0; j0 < 11; j0++)
          seat[i0][j0] = 0;
      }
      printf("자리 수와 입력하신 학생 수가 맞지 않습니다. 자리를 처음부터 다시 "
             "입력해 주세요.\n");
    }
    }
  }
  return;
}
void seat_output(int x, int n, char namelist[][50], int jjag[][2], int seat[][10]) {
  printf("자리 배치 결과 표(이는 단순한 짝 짓기를 이용한 자리 배치로 순서 등은 랜덤일 수 있습니다.)\n\n\n");
  int i, j, k = 0;
  for (i = 0; i < x; i++) {
    for (j = 0; j < 10; j++) {

      if (j != 0 && seat[i][j] == 0 && seat[i][j + 1] == 1 &&
          seat[i][j - 1] == 1)
        printf("\t");
      else if (seat[i][j] == 1 && seat[i][j + 1] == 1) {
        printf("%s %s", namelist[jjag[k][0]], namelist[jjag[k][1]]);
        k++;
      } else if (seat[i][j] == 0)
        printf(" ");
    }
    printf("\n\n\n");
  }
  if (jjag[k][1] == 101)
    printf("%s\n", namelist[jjag[k][0]]);
}
