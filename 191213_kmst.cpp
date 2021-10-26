// K - Minimum Spanning Tree
 
#include<iostream>
#include<list>
#include<vector>
#define MAX 40
using namespace std;

// Data structure for input graph
int N, M, K;
int u[MAX];	// u[i] is one node/vertice
int v[MAX]; // v[i] is another node/vertice
int w[MAX]; // c[i] is the egde connecting u[i] and v[i]
int nET;	// number of ET

// Data structure for disjoint set
int r[MAX]; // r[v]: the rank of the set v
int p[MAX]; // p[v]: the parent of v
long long rs;

void link(int x, int y){
	if (r[x] > r[y]) p[y] = x;
	else {
		p[x] = y;
		if (r[x] == r[y]) r[y]++;
	}
}

void makeSet(int x){
	p[x] = x;
	r[x] = 0;
}

int findSet(int x){
	// Return the set containing x (Return the root of that set)
	if (x != p[x]) p[x] = findSet(p[x]);
	return p[x];
}

// QuickSort algorithm: Sorting the edges (c[i]) in increasing order
void swap(int &a, int &b){
	int tmp = a; a = b; b = tmp;
}

void swapEdge(int i, int j){
	swap(w[i], w[j]);
	swap(u[i], u[j]);
	swap(v[i], v[j]);
}

int partition(int L, int R, int index){
	int pivot = w[index];
	swapEdge(index, R);
	int storeIndex = L;
	for (int i = L; i < R; i++){
		if (w[i] > pivot){
			swapEdge(storeIndex, i);
			storeIndex++;
		}
	}
	swapEdge(storeIndex, R);
	return storeIndex;
}

void quickSort(int L, int R){
	if (L < R){
		int index = (L+R)/2;
		index = partition(L, R, index);
		if (L < index) quickSort(L, index - 1);
		if (index < R) quickSort(index + 1, R);
	}
}

void quickSort(){
	quickSort(0, M-1);
}

// Solution
void solve(){
	for (int x = 1; x <= N; x++) makeSet(x);
	quickSort();
	rs = 0;
	nET = 0;
	for (int i = 0; i < M; i++){
		int ru = findSet(u[i]);
		int rv = findSet(v[i]);
		if (ru != rv){
			link(ru, rv);
			nET++;
			rs += w[i];
			if (nET == K+1) break;
		}
	}
	if (rs == 0) rs = -1;
	cout << rs;
}

void input(){
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++){
		cin >> u[i] >> v[i] >> w[i];
	}
}

int main(){
	input();
	solve();
	return 0;
}
