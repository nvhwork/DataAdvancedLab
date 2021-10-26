// Maze Problem

#include<stdio.h>
#include<list>
#define MAX 901
using namespace std;

int N, M; // the size of maze
int i0, j0; // the initial position a[i0][j0]
int ans; // the minimum steps to escape the maze

list<int> Qi;
list<int> Qj;

int a[MAX][MAX];	// a[i][j] = 0 -> the position is free
					// a[i][j] = 1 -> the position has an obstacle
int steps[MAX][MAX]; // steps[i][j] = the shortest distance from state (0,0) to state (i,j)

void input(){
	scanf("%d %d %d %d", &N, &M, &i0, &j0);
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			scanf("%d", &a[i][j]);
		}
	}
}

int up(int i, int j){
	if (a[i-1][j]) return 0;
	else {
		if (i == 1){
			ans = steps[i][j] + 1;
			return 1;
		} else {
			Qi.push_back(i-1);
			Qj.push_back(j);
			steps[i-1][j] = steps[i][j] + 1;
			a[i-1][j] = 1;
			return 0;
		}
	}
}

int down(int i, int j){
	if (a[i+1][j]) return 0;
	else {
		if (i == N){
			ans = steps[i][j] + 1;
			return 1;
		} else {
			Qi.push_back(i+1);
			Qj.push_back(j);
			steps[i+1][j] = steps[i][j] + 1;
			a[i+1][j] = 1;
			return 0;
		}
	}
}

int left(int i, int j){
	if (a[i][j-1]) return 0;
	else {
		if (j == 1){
			ans = steps[i][j] + 1;
			return 1;
		} else {
			Qi.push_back(i);
			Qj.push_back(j-1);
			steps[i][j-1] = steps[i][j] + 1;
			a[i][j-1] = 1;
			return 0;
		}
	}
}

int right(int i, int j){
	if (a[i][j+1]) return 0;
	else {
		if (j == M){
			ans = steps[i][j] + 1;
			return 1;
		} else {
			Qi.push_back(i);
			Qj.push_back(j+1);
			steps[i][j+1] = steps[i][j] + 1;
			a[i][j+1] = 1;
			return 0;
		}
	}
}

void solve(){
	Qi.push_back(i0);
	Qj.push_back(j0);
	steps[i0][j0] = 0;
	ans = -1;
	
	while (!Qi.empty()){
		int i = Qi.front(); Qi.pop_front();
		int j = Qj.front(); Qj.pop_front();
		if (up(i, j)) break;
		if (down(i, j)) break;
		if (left(i, j)) break;
		if (right(i, j)) break;
	}
	
	printf("%d", ans);
}

int main(){
	input();
	solve();
	return 0;
}
