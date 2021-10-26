// K - Cycle
 
#include<iostream>
#include<set>
#include<vector>
#define MAX 60
using namespace std;

int N, M, K;
int ans = 0;
vector<int> A[MAX];
int X[MAX];
int visited[MAX];

int check(int v, int k){
	if (visited[v]) return 0;
	if (v < X[1]) return 0;
	if (k == K){
		if (v < X[2]) return 0;
		for (int i = 0; i < A[X[1]].size(); i++){
			if (v == A[X[1]][i]) return 1;
		}
		return 0;
	}
	return 1;
}

void TRY(int k){
	for (int i = 0; i < A[X[k-1]].size(); i++){
		int v = A[X[k-1]][i];
		if (check(v, k)){
			X[k] = v;
			visited[v] = 1;
			if (k == K) ans++;
			else TRY(k+1);
			visited[v] = 0;
		}
	}
}

void solve(){
	for (int v = 1; v <= N; v++) visited[v] = 0;
	for (int v = 1; v <= N; v++){
		X[1] = v;
		visited[v] = 1;
		TRY(2);
		visited[v] = 0;
	}
	cout << ans;
}

void input(){
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++){
		int u, v;
		cin >> u >> v;
		A[u].push_back(v);
		A[v].push_back(u);
	}
}

int main(){
	input();
	solve();
}
