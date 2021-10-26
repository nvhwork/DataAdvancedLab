// A. Sequence

#include<iostream>
#define MAX 10001
using namespace std;

int N, K;
int a[MAX];

void input(){
	cin >> N >> K;
	for (int i = 1; i <= N; i++){
		cin >> a[i];
	}
}

int seq(){
	int cnt = 0;
	for (int i = 1; i <= N; i++){
		int m = 0;
		for (int j = i; j >= 1; j--){
			m += a[j];
			if (m % K == 0) cnt++;
		}
	}
	return cnt;
}

int main(){
	input();
	cout << seq();
	return 0;
}
