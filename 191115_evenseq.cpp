#include<bits/stdc++.h>
#define MAX 100007
#define INF 1000007
using namespace std;

int N;
int a[MAX];
int S0[MAX]; // even-sub
int S1[MAX]; // odd-sub

void solve(){
	if (a[1] % 2 == 0) S0[1] = a[1];
	else S1[1] = a[1];
	int ans = 0 - INF;
	for (int i = 2; i <= N; i++){
		if (a[i] % 2 == 0) { // a[i] is even
			if (S0[i-1] > 0) S0[i] = S0[i-1] + a[i];
			else /*if (a[i] > 0 || a[i] > S0[i])*/ S0[i] = a[i];
			
			if (S1[i-1] > 0) S1[i] = S1[i-1] + a[i];
	//		else S1[i] = S1[i-1];
			ans = max(ans, S0[i]);
		}
		else { // a[i] is odd
			if (S0[i-1] > 0) S1[i] = S0[i-1] + a[i];
			else /*if (a[i] > 0 || a[i] > S1[i])*/ S1[i] = a[i];
			
			if (S1[i-1] > 0) S0[i] = S1[i-1] + a[i];
	//		else S0[i] = S0[i-1];
			ans = max(ans, S0[i]);
		}
	}
	cout << ans;
}

int main(){
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> a[i];
	solve();
	return 0;
}

/* 6
-3 9 -1 7 -4 5

*/
