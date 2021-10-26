// Diameter

#include<bits/stdc++.h>
#include<vector>
#include<set>
#define MAX 200001
using namespace std;

int N, M, k;
int c[101];
vector<int> A[MAX];
vector<int> W[MAX];

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

int distancepath(int s, int t){
	sH = 0;
	for (int v = 1; v <= N; v++){
		Fixed[v] = false;
		idx[v] = -1;
	}
	d[s] = 0;
	Fixed[s] = true;
	for (int i = 0; i < A[s].size(); i++){
		int v = A[s][i];
		insert(v, W[s][i]);
	}
	
	while (sH > 0){
		int u = deleteMin();
		Fixed[u] = true;
		for (int i = 0; i < A[u].size(); i++){
			int v = A[u][i];
			if (Fixed[v]) continue;
			if (!inHeap(v)){
				int w = d[u] + W[u][i];
				insert(v, w);
			} else {
				if (d[v] > d[u] + W[u][i])
					updateKey(v, d[u] + W[u][i]);
			}
		}
	}
	int rs = d[t];
//	if (!Fixed[t]) rs = -1;
	return rs;
}

int solve(){
	int result = -1;
	for (int i = 1; i < k; i++){
		for (int j = i+1 ; j <= k; j++)
			result = max(result, distancepath(c[i], c[j]));
	}
	return result;
}

void input(){
	cin >> N >> M;
	for (int i = 1; i <= M; i++){
		int u, v, w;
		cin >> u >> v >> w;
		A[u].push_back(v);
		A[v].push_back(u);
		W[u].push_back(w);
		W[v].push_back(w);
	}
	cin >> k;
	for (int i = 1; i <= k; i++)
		cin >> c[i];
}

int main(){
	input();
	cout << solve();
	return 0;
}

/*
6 10
1 2 2
1 5 6
1 6 1
2 3 8
2 6 4
3 4 7
3 6 2
4 5 3
4 6 5
5 6 4
3
1 3 4
*/
