#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void seat_input(int n, int x, int seat[][10]) {
  printf("�ڸ� ��ġ�� *�� �Է��� �ּ���. �Էµ� �ڸ� ��ġ�� ���� �ڸ��� "
         "�����ص帳�ϴ�.\n");
  printf("\n���� �Է�\n** **\n** **\n���� ���\n������ ��ä��\t��ä�� "
         "�ȼ���\t\n�弭�� ȫ����\t�ǿ��� �赵��\n");
  printf("\n�ڸ� ��ġ�� 6x10 ���Ͽ��� �մϴ�.\n\n");
  int i, sum = 0;
  char s[11];
if(n%2==1) printf("�л� ���� Ȧ���̹Ƿ�, �ڸ�ǥ�� �Է��� �� ȥ�� �ɴ� �ڸ��� ���� �Է����ּ���. ������ ���� ����� �� �ڿ� ��µ˴ϴ�.\n");
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
            "���� ���񽺴� ¦ ���� �˰����� �������� �ڸ��� ��ġ���ֱ� "
            "������, 2���� �پ��ִ� �ڸ� ǥ�� ��ġ�� �����մϴ�. ����, ������ "
            "�� ���� �� ĭ���� �Է��� �ֽʽÿ�. �ڸ��� �ٽ� �Է��� �ּ���.\n");
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
      printf("�ڸ� ���� �Է��Ͻ� �л� ���� ���� �ʽ��ϴ�. �ڸ��� ó������ �ٽ� "
             "�Է��� �ּ���.\n");
    }
    }
  }
  return;
}
void seat_output(int x, int n, char namelist[][50], int jjag[][2], int seat[][10]) {
  printf("�ڸ� ��ġ ��� ǥ(�̴� �ܼ��� ¦ ���⸦ �̿��� �ڸ� ��ġ�� ���� ���� ������ �� �ֽ��ϴ�.)\n\n\n");
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
