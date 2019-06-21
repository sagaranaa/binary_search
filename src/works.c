#include <stdio.h>

int n;
int k;
int A[100000];

unsigned int p(int m){
  int current_work = 0;
  int current_number = 1;
  int i;

  for (i=0;i<n;i++){
    if(A[i] > m){
      return(0);
    }else if(current_work + A[i] > m){
      current_work = 0;
      current_number += 1;
    }
    current_work += A[i];
  }
  return(current_number <= k);
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1000000000;
  while(ub - lb > 1){
    int m = (ub + lb) / 2;
    if (p(m))ub = m;
    else lb = m;
  }
  printf("%d\n",ub);
  return 0;
}
