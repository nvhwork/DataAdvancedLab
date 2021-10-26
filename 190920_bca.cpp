//Balanced Course Teacher Assignment (BCA)
 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
#define MAX 50
 
// INPUT DATA STRUCTURES
int n; // number of classes
int m; // number of teachers
int sz[MAX]; // sz[i]: the number of teachers for the course i
int t[MAX][MAX]; // t[i][j]: the j-th teacher that can teach course i
int h[MAX]; // h[i]: the duration (hours) of the course i each week
int a[MAX][MAX]; // a[i][j] == 1 -> class i and j are conflict
 
// VARIABLES
int x[MAX]; // x[i]: the teacher assigned to course i
int f[MAX]; // f[j]: the total duration of courses (load) of a teacher j
int f_best; // best objective value
 
void input(){
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%d", &h[i]);
	}
	for (int i = 1; i <= n; i++){
		scanf("%d", &sz[i]);
		for (int j = 0; j < sz[i]; j++){
			scanf("%d", &t[i][j]);
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	}
}
 
int check(int v, int k){
	for (int i = 1; i <= k-1; i++){
		if (a[i][k] == 1 && x[i] == v) return 0;
	}
	return 1;
}
 
void solution(){
	int max = 0;
	for (int i = 1; i <= m; i++){
		if (max < f[i]) max = f[i];
	}
	if (max < f_best) f_best = max;
}
 
void TRY(int k){ // try to find a teacher (v) the course k
	for (int i = 0; i < sz[k]; i++){
		int v = t[k][i];
		if (check(v, k)){
			x[k] = v;
			f[v] += h[k]; // accumulate load for the teacher v
			if (k == n) solution();
			else TRY(k+1);
			f[v] -= h[k]; // recover when backtracking
		}
	}
}
 
void solve(){
	f_best = 1000000;
	for (int i = 1; i <= m; i++){
		f[i] = 0;
	}
	TRY(1);
	if (f_best == 1000000) printf("-1"); // no solution found
	else printf("%d", f_best);
}
 
int main(){
	input();
	solve();
	return 0;
}
