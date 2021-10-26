// Complete Graph

#include<iostream>
#define MAX 1001
using namespace std;

int N;
int a[MAX][MAX];

void input(){
	cin >> N;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++)
			cin >> a[i][j];
	}
}

int solve(){
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (i != j){
				if (a[i][j] == 0) return 0;
			}
		}
	}
	return 1;
}

int main(){
	input();
	cout << solve();
	return 0;
}
