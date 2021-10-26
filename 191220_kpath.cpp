// K-Path

#include<bits/stdc++.h>
#define MAX 201
using namespace std;

int N, M, K, Q;
int u[MAX], v[MAX], w1[MAX], w2[MAX];
int x[MAX];
int visited[MAX];
int w = 10000;
int minWeight1 = 10000;
int instantWeight1, instantWeight2;

void input(){
	cin >> N >> M >> K >> Q;
	for (int i = 1; i <= M; i++){
		cin >> u[i] >> v[i] >> w1[i] >> w2[i];
		minWeight1 = min(minWeight1, w1[i]);
	}
}

int check(int i, int j){
	return( (i > x[j-1]) && (instantWeight1 + w1[i] + minWeight1 * (K-j-1) < w) && (instantWeight2 + w2[i] <= Q) );
}

void solution(){
	int we = 0;
	int check[MAX] = {0};
	int c_node = 0;
	for (int i = 1; i <= K; i++){
		if (check[u[x[i]]] == 0){
			check[u[x[i]]] = 1;
			c_node++;
		}
		if (check[v[x[i]]] == 0){
			check[v[x[i]]] = 1;
			c_node++;
		}
		we += w1[x[i]];
	}
	if (c_node == K + 1){
		w = min(we, w);
	}
}

void TRY(int j){
	for (int i = 1; i <= M; i++){
		if (check(i, j)){
			x[j] = i;
			instantWeight1 += w1[i];
			instantWeight2 += w2[i];
			if (j == K) solution();
			else if (instantWeight1 + minWeight1 * (K-j) < w)
				TRY(j+1);
			instantWeight1 -= w1[i];
			instantWeight2 -= w2[i];
		}
	}
}

int main(){
	input();
	TRY(1);
	cout << w;
	return 0;
}
