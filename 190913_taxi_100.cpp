#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
 
int N;
int c_min; // minimum distance
int c[MAX][MAX];
unsigned int psg; // number of passenger on bus
 
int x[MAX];
int appear[MAX];
int f; // accumulate distance of the route under construction
int f_best; // shortest distance found so far
//int x_best[MAX]; // record the best route
 
void input(){
	scanf("%d", &N);
	c_min = 1000000;
	for (int i = 0; i <= 2*N; i++){
		for (int j = 0; j <= 2*N; j++){
			scanf("%d", &c[i][j]);
			if (i != j && c_min > c[i][j]) c_min = c[i][j];
		}
	}
}
 
void solution(){
	if (f + c[x[2*N]][0] < f_best){
		f_best = f + c[x[2*N]][0];
/*		for (int i = 1; i <= 2*N; i++){
			x_best[i] = x[i];
		}*/
	}
}
 
int check(int v, int k){
	if (k == 1){
		if (v <= N) return 1;
	}
	if (!appear[v]) {
		if (v <= N && psg < 1) return 1;
		if (v > N) return (appear[v - N]);
	}
	return 0;
}
 
void TRY(int k){
	for (int v = 1; v <= 2*N; v++){
		if (check(v, k)){
			x[k] = v;
			if (v <= N) psg++;
			else psg--;
			f += c[x[k-1]][x[k]];
			appear[v] = 1;
			
			if (k == 2*N) solution();
			else {
				if (f + (2*N + 1 - k) * c_min < f_best)
					TRY(k + 1);
			}
			
			if (v <= N) psg--;
			else psg++;
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
	psg = 0;
	TRY(1);
	printf("\n%d\n", f_best);
/*	for (int i = 0; i <= 2*N+1; i++) printf("%d ", x_best[i]);
	printf("\n");
	for (int i = 0; i <= 2*N; i++){
			printf(" %d", c[x_best[i]][x_best[i+1]]);
	}*/
	return 0;
}
