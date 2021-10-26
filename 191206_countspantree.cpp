// Count Spanning Tree

#include<bits/stdc++.h>
#define MAX 30
using namespace std;
typedef pair<int, int> ii; // ii: double int for getting 2 values
int N, M, rs = 0, cnt;
int parentNode[MAX];
vector<ii> edge;

void input(){
    cin >> N >> M;
    int u, v;
    for (int i = 1; i <= M; i++){
        cin >> u >> v;
        edge.push_back(ii(u, v));
    }
}

void init(){
    for (int i = 1; i <= N; i++) parentNode[i] = i;
    cnt = N;
}

int findAncestor(int p){
    return (parentNode[p] == p) ? p : findAncestor(parentNode[p]);
}

void join2Branches(int p, int q){
    parentNode[findAncestor(p)] = findAncestor(q);
}

void TRY(int k){
    if (k == M){
        rs += (cnt == 1);
        return;   
    }
    int u = edge[k].first;
    int v = edge[k].second;
    if (findAncestor(u) != findAncestor(v)){
        int parentNodeU = findAncestor(u);
        join2Branches(u, v);
        cnt--;
        TRY(k + 1);
        cnt++;
        parentNode[parentNodeU] = parentNodeU;
    }
    TRY(k + 1);
}


int main(){
    input();
    init();
    TRY(0);
    cout << rs;
}

/*
#include<iostream>
#define MAX_N 101
#define MAX_M 1001
using namespace std;

int N, M;
int b[MAX_N]; // begin
int e[MAX_N]; // end
int X[MAX_M]; // model solution, set of indices of edges of spanning trees
int ans;

// Data structure for disjoint set
int r[MAX_N]; // r[v]: rank of set v
int p[MAX_N]; // p[v]: parent of v
long long rs;

void link(int x, int y){
	if (r[x] > r[y]) p[y] = x;
	else {
		p[x] = y;
		if (r[x] == r[y]) r[y] = r[y] + 1;
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

int checkNoCycle(int val, int k){
	// check if set edges (b[X[1]], e[X[1]]), (b[X[2]], e[X[2]]), ... , (b[X[val]], e[X[val]])
	// induces a cycle
	for (int i = 1; i <= N; i++) makeSet(i);
	for (int j = 1; j < k; j++){
		int u = b[X[j]], v = e[X[j]];
		int ru = findSet(u), rv = findSet(v);
		if (ru == rv) return 0; // node u and v belong to the same set => create a cycle
		link(ru, rv); // otherwise, link 2 sets together
	}
	if (findSet(b[val]) == findSet(e[val])) return 0;
	return 1;
}

void solution(){
	ans++;
	cout << ans << ": ";
	for (int i = 1; i <= N-1; i++)
		cout << "(" << b[X[i]] <<", " << e[X[i]] << ") ";
	cout << endl;
}

void TRY(int k){
	for (int v = X[k-1] + 1; v <= M; v++){
		if (checkNoCycle(v, k)){
			X[k] = v;
			if (k == N-1) solution();
			else TRY(k+1);
		}
	}
}

void input(){
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
		cin >> b[i] >> e[i];
}

int main(){
	input();
	TRY(1);
	cout << ans;
	return 0;
}
*/
