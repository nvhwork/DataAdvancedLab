// C. MST grid graph

#include<bits/stdc++.h>
#define MAX 1001
#define INF 1000000007
using namespace std;

int N, cnt;
long long int Q = 0;
typedef pair<int, int> ii;
vector<ii> G;
int pNode[MAX];

void input(){
	cin >> N;
	G.push_back(ii(1, 2));
	if (N >= 2){
		for (int j = 3; j <= 2*N; j++){
			G.push_back(ii(j-2, j));
			if (j % 2 == 0) G.push_back(ii(j-1, j));
		}
	}
}

void init(){
    for (int i = 1; i <= 2*N; i++) pNode[i] = i;
    cnt = 2*N;
}

int findAncestor(int p){
    return (pNode[p] == p) ? p : findAncestor(pNode[p]);
}

void join2Branches(int p, int q){
    pNode[findAncestor(p)] = findAncestor(q);
}

void TRY(int k){
    if (k == 3*N-2){
        Q = (Q + (cnt == 1))%INF;
        return;   
    }
    int u = G[k].first;
    int v = G[k].second;
    if (findAncestor(u) != findAncestor(v)){
        int pNodeU = findAncestor(u);
        join2Branches(u, v);
        cnt--;
        TRY(k + 1);
        cnt++;
        pNode[pNodeU] = pNodeU;
    }
    TRY(k + 1);
}

int main(){
	input();
	init();
	TRY(0);
	cout << Q%INF;
	return 0;
}
