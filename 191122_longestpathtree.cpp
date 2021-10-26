// Longest Path on a Tree

#include<bits/stdc++.h>
#include<vector>
#include<list>
#define MAX 100009
using namespace std;

int N;
int d[MAX]; // d[v]: the distance from the source node to node v 
vector<int> A[MAX];
vector<int> W[MAX];
int max_node = 0;
int max_path = 0;

void input(){
	cin >> N;
	for (int i = 1; i <= N-1; i++){
		int u, v, w;
		cin >> u >> v >> w;
		A[u].push_back(v);
		A[v].push_back(u);
		W[u].push_back(w);
		W[v].push_back(w);
	}
}

int BFS(int s){
	list<int> Q;
	Q.push_back(s);
	
	for (int i = 1; i <= N; i++) d[i] = -1;
	d[s] = 0;
	
	while(!Q.empty()){
		int v = Q.front();
		Q.pop_front();
		for (int i = 0; i < A[v].size(); i++){
			int x = A[v][i];
			int w = W[v][i];
			if (d[x] == -1){
				Q.push_back(x);
				d[x] = d[v] + w;
			}
			if (max_path < d[x]){
				max_path = d[x];
				max_node = x;
			}
		}
	}
	
	return max_node;
}

int main(){
	input();
	int x = BFS(1);
	int y = BFS(x);
	cout << max_path;
	return 0;
}
