#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100

int N, M;
int c_min;
int c[MAX][MAX];
 
int x[MAX];
int appear[MAX];
int f = 0;
int count = 0;
 
void input(){
	scanf("%d %d", &N, &M);
	c_min = 100; // c_min = 1000000;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			scanf("%d", &c[i][j]);
			if (i != j && c_min > c[i][j]) c_min = c[i][j];
		}
	}
}
 
int check(int v){
	return (!appear[v]);
}

void solution(){
	if (f + c[x[N]][1] <= M) count++;
}
 
void TRY(int k){
	for (int v = 2; v <= N; v++){
		if (check(v)){
			x[k] = v;
			f += c[x[k-1]][x[k]];
			appear[v] = 1;
			if (k == N) solution();
			else {
				if (f + (N+1-k)*c_min < M) // <= M
					TRY(k + 1);
			}
			appear[v] = 0;
			f -= c[x[k-1]][x[k]];
		}
	}
}
 
int main(){
	input();
	x[1] = 1;
	TRY(2);
	printf("%d", count);
	return 0;
}
