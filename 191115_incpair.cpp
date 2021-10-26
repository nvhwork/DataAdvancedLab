#include<bits/stdc++.h>
#define MAX 1001
using namespace std;

int N;
int a[MAX];

void solve(){
	int ans = 0;
	for (int i = 2; i <= N; i++){
		for (int j = 1; j <= i-1; j++){
			if (a[j] < a[i]) ans++;
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
