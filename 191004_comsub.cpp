// Longest Common Subsequence
 
#include<iostream>
#define MAX 10001
using namespace std;
 
int n, m;
int x[MAX], y[MAX];
int s[MAX][MAX];
/* 
 * Smallest sub-problem:
 * s[1][j] = 1 if x[1] appears in y[1..m].
 * s[i][1] = 1 if y[1] appears in x[1..n].
 * Before the appearance, s[i][j] = 0.
 */
int comSubseq(){
	for (int i = 1; i <= n; i++){
		if (x[i] == y[1] || s[i-1][1] == 1) s[i][1] = 1;
	}
	for (int j = 1; j <= m; j++){
		if (x[1] == y[j] || s[1][j-1] == 1) s[1][j] = 1;
	}
	for (int i = 2; i <= n; i++){
		for (int j = 2; j <= m; j++){
			if (x[i] == y[j]) s[i][j] = s[i-1][j-1] + 1;
			else s[i][j] = s[i-1][j] > s[i][j-1] ? s[i-1][j] : s[i][j-1];
		//	else s[i][j] = max(s[i-1][j], s[i][j-1]);
		}
	}
	return s[n][m];
}
 
int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int j = 1; j <= m; j++) cin >> y[j];
	cout << comSubseq();
	return 0;
}
