#include<iostream>
#define MAX_N 1001
#define MAX_T 101
#define MAX_D 11
#define MAX_VALUE 100
using namespace std;

int N, T, D, rs = 0;
int a[MAX_N], t[MAX_N];
int S[MAX_N][MAX_T];
// S[i][t]: max amount of goods 0 picked up
// until point i, total pickup time = t

void solve(){
	for (int k = 0; k <= T; k++){
		if (k != t[0]) S[0][k] = 0;
		else S[0][k] = a[0];
	}
	for (int i = 1; i < N; i++){
		for (int k = 0; k <= T; k++){
			if (k != t[i]) S[i][k] = 0;
			else S[i][k] = a[i];
			for (int d = 1; d <= D; d++){
				int j = i-d;
				if (j >= 0 && k >= t[i] && S[j][k-t[i]] > 0)
					S[i][k] = max(S[i][k], S[j][k-t[i]] + a[i]);
			}
		}
	}
	for (int i = 0; i < N; i++){
		for (int k = 0; k <= T; k++){
			rs = max(rs, S[i][k]);
		}
	}
	cout << rs;
}

int main(){
	cin >> N >> T >> D;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N; i++) cin >> t[i];
	solve();
	return 0;
}
