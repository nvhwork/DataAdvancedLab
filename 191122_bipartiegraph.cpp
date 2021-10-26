// Bipartie Graph

#include<bits/stdc++.h>
#include<vector>
#include<list>
#define MAX 1000007

using namespace std;

int N, M;
int d[MAX]; // d[v]: the level of node v
vector<int> A[MAX];

void input(){
	cin >> N >> M;
	for (int i = 1; i <= M; i++){
		int u, v;
		cin >> u >> v;
		A[u].push_back(v);
		A[v].push_back(u);
	}
}

bool BFS(int s){
	list<int> Q;
	Q.push_back(s);
	d[s] = 0;
	while (!Q.empty()){
		int v = Q.front();
		Q.pop_front();
		for (int i = 0; i < A[v].size(); i++){
			int x = A[v][i];
			if (d[x] > -1){
				if (d[v] % 2 == d[x] % 2) return false;
			}
			else {
				Q.push_back(x);
				d[x] = d[v] + 1;
			}
		}
	}
	return true;
}

int bipartie(){
	for (int s = 1; s <= N; s++){
		if (d[s] == -1)
			if (BFS(s) == false)
				return 0;
	}
	return 1;
}

int main(){
	input();
	for (int i = 1; i <= N; i++) d[i] = -1;
	cout << bipartie();
	return 0;
}
