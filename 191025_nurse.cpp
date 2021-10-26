#include<iostream>
#define MAX 1007
#define INF 1000000007
using namespace std;

int N, K1, K2;
int s[2][MAX] = {0};

int solve(){
	s[0][0] = 1;
	s[0][1] = 1;
	s[1][K1] = 1;
	
	for (int i = K1 + 1; i <= N; i++){
		s[0][i] = s[1][i-1];
		s[1][i] = 0;
		for (int j = K1; j <= K2; j++){
			if (i - j >= 0) s[1][i] += s[0][i-j];
		}
	}
	
	return s[1][N] + s[0][N];
}

int main(){
	cin >> N >> K1 >> K2;
	cout << solve();
	return 0;
}
