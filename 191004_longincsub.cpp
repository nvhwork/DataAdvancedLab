// Longest Increasing Subsequence
 
#include<iostream>
#define MAX 100001
using namespace std;
 
int n;
int a[MAX];
int s[MAX];
 
int incSubseq(){
	s[1] = 1;
	int ans = s[1];
	for (int i = 2; i <= n; i++){
		s[i] = 1;
		for (int j = 1; j <= i-1; j++){
			if (a[j] < a[i] && s[i] < s[j] + 1) s[i] = s[j] + 1;
		}
		if (ans < s[i]) ans = s[i];
	}
	return ans;
	
/*	// For consecutive increasing sequence
	int ans = 1, max = 1;
	for (int i = 2; i <= n; i++){
		if (a[i-1] < a[i]) ans++;
		else {
			if (max < ans) max = ans;
			ans = 1;
		}
	}
	return max;*/
}
 
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cout << incSubseq();
	return 0;
}
