#include<stdio.h>
#define MAX 501
#define MOD 1000000007
int n, m;
int a[MAX];
 
int s[MAX][MAX];
int t[MAX];
void input(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		t[i] = t[i-1] + a[i];
	}
}
 
int solve(){
	//first row of the matrix
	for(int k = 1; k <= m; k++){
		if (k % a[1] == 0) s[1][k] = 1;
		else s[1][k] = 0;
	}
	
	for(int i = 2; i <= n; i++){
		for(int k = 1; k <= m; k++){
			int ub = (k - t[i-1]) / a[i];
			for (int v = 1; v <= ub; v++){
				s[i][k] = (s[i][k]%MOD + s[i-1][k-v*a[i]]%MOD) % MOD;
			}
		}
	}
	return s[n][m];
}
 
int main(){
	t[0] = 0;
	input();
	printf("%d\n", solve());
	for (int i = 1; i <= n; i++){
		printf("\n");
		for (int k = 1; k <= m; k++){
			printf("%d ", s[i][k]);
		}
	}
}

/*#include<iostream>
#define INF 1000000007
#define MAX 501
using namespace std;

int N, M;
int min = 11;
int a[MAX];
int r[MAX][MAX];

int solve(){
	int Q;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= (int)M/min; j++){
			r[i][j] = a[i]*j;
		}
	}
	return Q%INF;
}

int main(){
	cin >> N >> M;
	for (int i = 1; i <= N; i++){
		cin >> a[i];
		if (min < a[i]) min = a[i];
	}
	cout << solve();
	return 0;
}*/
