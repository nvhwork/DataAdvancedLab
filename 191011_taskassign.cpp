// TASK ASSIGNMENT

#include<iostream>
#define MAX 100
using namespace std;

int n, m, k;
int c[MAX][MAX];
int c_min = 100;

int appear[MAX];
int task[MAX];
int cost = 0;
int cost_best;

void input(){
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			scanf("%d", &c[i][j]);
			if (c_min > c[i][j]) c_min = c[i][j];
		}
	}
}

int check(int i, int j){
	return (!appear[j] && task[i] < k);
}

void solution(){
	if (cost < cost_best) cost_best = cost;
}

void TRY(int j){
	for (int i = 1; i <= m; i++){
		if (check(i, j)){
			cost += c[i][j];
			appear[j] = 1;
			task[i]++;
			if (j == n) solution();
			else {
				if (cost + (n-j+1)*c_min < cost_best) TRY(j+1);
			}
			cost -= c[i][j];
			appear[j] = 0;
			task[i]--;
		}
	}
}

int main(){
	input();
	cost_best = 1000000;
	TRY(1);
	printf("%d", cost_best);
	return 0;
}
