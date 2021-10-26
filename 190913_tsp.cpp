#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100

int N;
int c_min; // minimum distance
int c[MAX][MAX];
 
int x[MAX];
int appear[MAX];
int f; // accumulate distance of the route under construction
int f_best; // shortest distance found so far
//int x_best[MAX]; // record the best route
 
void input(){
	scanf("%d", &N);
	c_min = 100;
	for (int i = 0; i <= N; i++){
		for (int j = 0; j <= N; j++){
			scanf("%d", &c[i][j]);
			if (i != j && c_min > c[i][j]) c_min = c[i][j];
		}
	}
}
 
int check(int v){
	return (appear[v] == 0);
}
 
void solution(){
	if (f + c[x[N]][0] < f_best){
		f_best = f + c[x[N]][0];
/*		for (int i = 0; i <= N; i++){
			x_best[i] = x[i];
		}*/
	}
}
 
void TRY(int k){
	for (int v = 1; v <= N; v++){
		if (check(v)){
			x[k] = v;
			f += c[x[k-1]][x[k]];
			appear[v] = 1;
			if (k == N) solution();
			else {
				if (f + (N+1-k)*c_min < f_best)
					TRY(k + 1);
			}
			appear[v] = 0;
			f -= c[x[k-1]][x[k]];
		}
	}
}
 
int main(){
	input();
	f = 0;
	f_best = 1000000;
//	for (int i = 1; i <= N; i++) appear[i] = 0;
	x[0] = 0; // starting point
	TRY(1);
	printf("\n%d\n", f_best);
//	for (int i = 0; i <= N+1; i++) printf("%d ", x_best[i]);
	return 0;
}
