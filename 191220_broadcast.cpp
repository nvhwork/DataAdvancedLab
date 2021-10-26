// K-Path

#include<bits/stdc++.h>
#define MAX 51
using namespace std;

int N, M, s, L;
int u[MAX], v[MAX], c[MAX], l[MAX];
int x[MAX];
int visited[MAX];
int cost = 10000;
int minCost = 10000;
int instantCost, instantLate;

void input(){
	cin >> N >> M >> s >> L;
	for (int i = 1; i <= M; i++){
		cin >> u[i] >> v[i] >> c[i] >> l[i];
		minCost = min(minCost, c[i]);
	}
}

int check(int i, int j){
	return( (u[x[1]] == s || v[x[1]] == s) && (i != x[j-1]) && (instantCost + c[i] + minCost * (N-j-2) < cost) && (l[i] <= L) );
}

void solution(){
	int ct = 0;
	int check[MAX] = {0};
	int node = 0;
	for (int i = 1; i <= N-1; i++){
		if (check[u[x[i]]] == 0){
			check[u[x[i]]] = 1;
			node++;
		}
		if (check[v[x[i]]] == 0){
			check[v[x[i]]] = 1;
			node++;
		}
		ct += c[x[i]];
	}
	if (node == N){
		cost = min(cost, ct);
	}
}

void TRY(int j){
	for (int i = 1; i <= M; i++){
		if (check(i, j)){
			x[j] = i;
			instantCost += c[i];
			instantLate += l[i];
			if (j == N-1) solution();
			else if (instantCost + minCost * (N-j-1) < cost)
				TRY(j+1);
			instantCost -= c[i];
			instantLate -= l[i];
		}
	}
}

int main(){
	input();
	TRY(1);
	if (cost == 10000) cost = -1;
	cout << cost;
	return 0;
}
