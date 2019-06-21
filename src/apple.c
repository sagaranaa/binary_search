#include <stdio.h>

int n;
int k;
int A[100000];

unsigned int p(int m){
  int current_bags = 0;
  int i;

  for (i=0;i<n;i++){
    current_bags += (A[i] + m - 1)/m;
  }

  return(current_bags <= k);
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000;
  while (ub - lb > 1){
    int m = (ub + lb) / 2;
    if (p(m))ub = m;
    else lb = m;
  }

  printf("%d\n", ub);
  return 0;
}
