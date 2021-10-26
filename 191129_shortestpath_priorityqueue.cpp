// Shortest Path Priority Queue

#include<bits/stdc++.h>
#include<set>
#include<vector>
#define INF 1000000000
#define MAX 1000001
using namespace std;

int N, M; // number of nodes and arcs of the given graph
int s, t; // source and destination nodes
vector<int> A[MAX]; // A[v][i]: the i-th adjacent node to v
vector<int> c[MAX]; // c[v][i]: the weight of the i-th adjacent arc (v, A[v][i]) to v

// priority queue data structure (BINARY HEAP)
int d[MAX]; // d[v]: the upper bound of the length of the shortest path from s to v (key)
int node[MAX]; // node[i]: the i-th element in the HEAP
int idx[MAX]; // idx[v]: the index of v in the HEAP (idex[node[i]] = i)
int sH; // size of the HEAP
bool Fixed[MAX];

void swap(int i, int j){
	int tmp = node[i];
	node[i] = node[j];
	node[j] = tmp;
	idx[node[i]] = i;
	idx[node[j]] = j;
}

void upHeap(int i){
	if (i == 0) return;
	while (i > 0){
		int pi = (i - 1) / 2;
		if (d[node[i]] < d[node[pi]]) swap(i, pi);
		else break;
		i = pi;
	}
}

void downHeap(int i){
	int L = 2*i + 1;
	int R = 2*i + 2;
	int maxIdx = i;
	if (L < sH && d[node[L]] < d[node[maxIdx]]) maxIdx = L;
	if (R < sH && d[node[R]] < d[node[maxIdx]]) maxIdx = R;
	if (maxIdx != i){
		swap(i, maxIdx);
		downHeap(maxIdx);
	}
}

void insert(int v, int k){
	// add element key = k, value = v
	d[v] = k;
	node[sH] = v;
	idx[node[sH]] = sH;
	upHeap(sH);
	sH++;
}

int inHeap(int v){ // check if a node belongs to the priority queue
	return idx[v] >= 0;
}

void updateKey(int v, int k){
	if (d[v] > k){
		d[v] = k;
		upHeap(idx[v]);
	} else {
		d[v] = k;
		downHeap(idx[v]);
	}
}

int deleteMin(){
	int sel_node = node[0];
	swap(0, sH - 1);
	sH--;
	downHeap(0);
	return sel_node;
}

void printQueue(){
	for (int i = 0; i < sH; i++)
		cout << "(" << node[i] << ", " << d[node[i]] << ") ";
	cout << endl;
}

void solve(){
	sH = 0;
	for (int v = 1; v <= N; v++){
		Fixed[v] = false;
		idx[v] = -1;
	}
	d[s] = 0;
	Fixed[s] = true;
	for (int i = 0; i < A[s].size(); i++){
		int v = A[s][i];
		insert(v, c[s][i]);
		cout << "Init queue insert (" << v << ", " << c[s][i] << ")" << endl;
	}
	printQueue();
	
	while (sH > 0){
		int u = deleteMin();
		Fixed[u] = true;
		for (int i = 0; i < A[u].size(); i++){
			int v = A[u][i];
			if (Fixed[v]) continue;
			if (!inHeap(v)){
				int w = d[u] + c[u][i];
				insert(v, w);
			} else {
				if (d[v] > d[u] + c[u][i])
					updateKey(v, d[u] + c[u][i]);
			}
		}
	}
	int rs = d[t];
	if (!Fixed[t]) rs = -1;
	cout << rs;
}

void input(){
	cin >> N >> M;
	for (int k = 1; k <= M; k++){
		int u, v, w;
		cin >> u >> v >> w;
		A[u].push_back(v);
		c[u].push_back(w);
	}
	cin >> s >> t;
}

int main(){
	input();
	solve();
	return 0;
}
