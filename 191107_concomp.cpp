// Connected Component
#include<bits/stdc++.h>
#include<vector>
// #include<iostream>
#define MAX_N 1000001

using namespace std;

int N, M; // number of nodes and edges
vector<int> A[MAX_N]; // A[v]: the list of adjacent nodes to v

// Data stucture for DFS
int d[MAX_N]; // d[v]: the visiting time point of v
int f[MAX_N]; // f[v]: the finished-exploration time point of v
int p[MAX_N]; // p[v]: the pre-decessor of v
char color[MAX_N]; // color[v]: the color of v (to determine whether or not v is visited or finish-explored)
int t = 0; // global discrete time point (augmented by 1 each step)

//Extra part:
int cc[MAX_N];
int nbCC = 0;

void printCC(){
	for (int k = 1; k <= nbCC; k++){
		cout << "Connected component " << k << ": ";
		for (int u = 1; u <= N; u++)
			if (cc[u] == k) cout << u << " ";
		cout << endl;
	}
}

void DFS(int u){
	t++;	d[u] = t;	color[u] = 'G';
	cc[u] = nbCC;
	for (int i = 0; i < A[u].size(); i++){
		int v = A[u][i];
		if (color[v] == 'W'){
			p[v] = u;
			DFS(v);
		}
	}
	t++;	f[u] = t;	color[u] = 'B'; // finished-exploration of u
}

void init(){	
	for (int u = 1; u <= N; u++) color[u] = 'W'; // not visited
}

void DFS(){
	init();
	for (int u = 1; u <= N; u++){
		if (color[u] == 'W'){
			nbCC++;  // start exploring nodes of the nbCC-th connected component
			DFS(u);
		}
	}
	/*for (int u = 1; u <= N; u++){
		cout << endl <<  "d[" << u << "] = " << d[u]
					<< ", f[" << u << "] = " << f[u]
					<< ", p[" << u << "] = " << p[u];
	}*/
	cout << "Number of connected component: " << nbCC << endl;
}

void input(){
	cin >> N >> M;
	for (int i = 1; i <= M; i++){
		int u, v;
		cin >> u >> v;
		A[u].push_back(v);
		A[v].push_back(u);
	}
}

void printGraph(){
	for (int u = 1; u <= N; u++){
		cout << endl << "A[" << u << "] = ";
		for (int i = 0; i < A[u].size(); i++)
			cout << A[u][i] << " ";
	}
	cout << endl;
}

void findPath(int s, int t){
	init();
	DFS(s);
	stack<int> S;
	int x = t;
	while (x != s){
		S.push(x);
		x = p[x];
	}
	cout << "Path from " << s << " to " << t << ": " << s << " ";
	while (!S.empty()){
		int x = S.top();
		S.pop();
		cout << x << " ";
	}
	cout << endl;
}

int main(){
	input();
	printGraph();
	DFS();
	printCC();
	findPath(2, 8);
	return 0;
}

/* Input:
9 9
1 2
1 7
1 8
2 7
4 5
4 6
5 6
7 8
7 9
*/
