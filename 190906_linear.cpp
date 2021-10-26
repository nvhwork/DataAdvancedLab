#include<stdio.h>
#define MAX 100
int x[MAX];

int N, M;
int T; //use to check the sum. update incrementally and will be recovered when backtracking

void solution(){
	printf("\n");
	for (int i = 1; i < N; i++) printf("%d + ", x[i]);
	printf("%d = %d", x[N], M);
}

int check(int v, int k){
	if (k < N) return (T + v < M);
	return (T + v == M);
}

void TRY(int k){
  for (int v = 1; v <= M - T - (N - k); v++ ){
  	/*
  		x[1] + x[2] + ... + x[k-1] + x[k] + x[k+1] + ... + x[N] = M
  		<-----------T------------>  <-v->   <--- >=(n-k)*1 --->
  	*/
	if (check(v, k)){
		x[k] = v;
		T = T + v;
		if (k == N) solution();
		else TRY(k+1);
		T = T - v; // recover when backtracking  -- update incrementally
    }
  }
}

int main(){
	scanf("%d %d", &N, &M);
	T = 0;
	TRY(1);
}
