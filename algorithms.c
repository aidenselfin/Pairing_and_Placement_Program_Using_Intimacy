#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int max_aeo(double aeo[][100], int x, int n, int sepgen, char gender[]) {
  double max_val = 0;
  int max_idx = 404, i;
  for (i = 0; i < n; i++) {
    if (x != i) {

      if (aeo[x][i] > max_val) {
        if (sepgen == 1) {
          if (gender[i] == gender[x]) {
            max_val = aeo[x][i];
            max_idx = i;
          }
        } else if (sepgen == 2) {
          if (gender[i] != gender[x]) {
            max_val = aeo[x][i];
            max_idx = i;
          }
        } else {
          max_val = aeo[x][i];
          max_idx = i;
        }
      }
    }
  }
  return max_idx;
}

void match(double aeo[][100], int data[][100], int n, int *y,
           int sepgen, int jjag[][2],char gender[]) {
  int x,cnt=0;
  for(x = 0; x < n; x++) {
  	cnt = 0;
    int i = max_aeo(aeo, x, n, sepgen, gender);
    int k;
    if (*y > n / 2) {
      continue;
    }
    else if (i == 404) {
      continue;
    }
  	else if (max_aeo(aeo, i, n, sepgen, gender) == x) {
    jjag[*y][0] = i;
    jjag[*y][1] = x;
    for (k = 0; k < n; k++){
      aeo[x][k] = 0;
      aeo[k][x] = 0;
      aeo[i][k] = 0;
      aeo[k][i] = 0;
    }
    (*y)++;

  } 	
  int I,X;
	for(X=0;X<n;X++){
		I = max_aeo(aeo, X, n, sepgen, gender);
		if(I!=404){
			cnt++;
			break;	
		}
		else if(X==n-1){
			return;
		}
	}
	if(x==n-1&&cnt!=0) x = 0;  
}
}


