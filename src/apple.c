#include <stdio.h>

int n;
int k;
int A[100000];

unsigned int p(int total_bags, int people, int size_bag){
  int current_bags = 0;
  int i;

  for (i=0;i<people;i++){
    current_bags += (A[i] + size_bag - 1)/size_bag;
  }

  return(current_bags <= total_bags);
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = A[i-1] + 1;
  while (ub - lb > 1){
    int m = (ub + lb) / 2;
    if (p(k, n, m))ub = m;
    else lb = m;
  }

  printf("%d\n", ub);
  return 0;
}
