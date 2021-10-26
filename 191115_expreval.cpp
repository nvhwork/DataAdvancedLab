#include<bits/stdc++.h>
#include<list>
#define INF 1000000007
#define MAX 200007
using namespace std;

int N;
int a[MAX];
int b[MAX];
list<int> Q;
list<int> P;

int mod(int b){
	if (b >= 0) return b % INF;
	if (abs(b) <= INF) return b + INF;
	b = abs(b);
	int k = b / INF;
	b = b - k * INF;
	return INF - b;
}

void solve(){
	Q.push_back(a[0] % INF);
	for (int i = 1; i < N; i++){
		if (b[i] != 2){
			P.push_back(b[i]);
			Q.push_back(a[i]);
		}
		else {
			int k = Q.back();
			Q.pop_back();
			Q.push_back(mod(k*a[i]));
		}
	}
	int ans = mod(Q.front());
//	cout << ans << " ";
	Q.pop_front();
	while (!Q.empty()){
		int q = mod(Q.front());
		int p = P.front();
//		cout << p << " " << q << " ";
		Q.pop_front();
		P.pop_front();
		if (p == 0) ans = mod(ans - q);
		if (p == 1) ans = mod(ans + q);
	}
	cout << ans;
}

int main(){
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int j = 1; j < N; j++) cin >> b[j];
	solve();
	return 0;
}

/*
6
3 5 3 2 7 4
0 1 2 2 1
*/
