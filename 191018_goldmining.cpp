#include<iostream>
#define MAX 100009
using namespace std;
 
int n, L1, L2;
int a[MAX];
int S[MAX];
 
int solve(){
	S[1] = a[1];
	int max = S[1];
	for (int i = 2; i <= n; i++){
		S[i] = a[i];
		for (int j = i - L1; j >= i - L2; j--){
			if (j > 0 && S[i] < S[j] + a[i])
				S[i] = S[j] + a[i];
		}
		if (max < S[i]) max = S[i];
	}
	return max;
}
 
int main(){
	cin >> n >> L1 >> L2;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cout << solve();
	return 0;
}
