// Shortest Path Problem - Dijkstra

#include<bits/stdc++.h>
#include<set>
#include<vector>
#define INF 1000000000
#define MAX 1000001
using namespace std;

int N, M, s, t;
vector<int> A[MAX];
vector<int> c[MAX];
int d[MAX];
int p[MAX];

void input(){
	cin >> N >> M;
	int u, v, w;
	for (int i = 1; i <= M; i++){
		cin >> u >> v >> w;
		A[u].push_back(v);
		c[u].push_back(w);
	}
	cin >> s >> t;
}

void init(){
	for (int v = 1; v <= N; v++){
		d[v] = INF;
		p[v] = s;
	}
	for (int i = 0; i < A[s].size(); i++){
		int v = A[s][i];
		int w = c[s][i];
		d[v] = w;
	}
}

int selectMin(set<int> &S){
	int u = -1;
	int minD = INF;
	for (set<int>::iterator it = S.begin(); it != S.end(); it++){
		int v = *it;
		if (d[v] < minD){
			minD = d[v];
			u = v;
		}
	}
	return u;
}

void solve(){
	init();
	set<int> S;
	for (int v = 1; v <= N; v++) S.insert(v);
	while (!S.empty()){
		int u = selectMin(S);
		if (u == t) break;
		S.erase(u);
		for (int i = 0; i < A[u].size(); i++){
			int v = A[u][i];
			int w = c[u][i];
			if (S.find(v) != S.end()){ // S contains v
				if (d[v] > d[u] + w){
					d[v] = d[u] + w;
					p[v] = u;
				}
			}
		}
	}
	cout << d[t];
}

int main(){
	input();
	solve();
	return 0;
}
