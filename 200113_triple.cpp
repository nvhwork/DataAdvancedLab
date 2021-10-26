// B. Triple

#include<bits/stdc++.h>
#define MAX_N 10001
#define MAX_K 100009
using namespace std;

int N, K, T;
int cnt = 0;
int numK = 0;
//int minK = MAX_K;
int a[MAX_N];

void input(){
	cin >> N >> K;
	for (int i = 1; i <= N; i++){
		cin >> a[i];
//		minK = min(minK, a[i]);
	}
}

int check(int v){
	if (cnt >= 3 && v == 1) return 0;
	return 1;
}

int findMin(int k){
	int m = MAX_K;
	for (int i = k; i <= N; i++){
		m = min(m, a[i]);
	}
	return m;
}

void TRY(int k){
	if (k > N) return;
	for (int v = 0; v <= 1; v++){
		if (check(v)){
			if (v == 1) {
				cnt++;
				T += a[k];
			}
			if (cnt == 3) {
				if (T == K) numK++;
			} else {
				if (T + findMin(k)*(3-cnt) < K) TRY(k+1);
			}
			if (v == 1) {
				cnt--;
				T -= a[k];
			}
		}
	}
}

int main(){
	input();
	TRY(1);
	cout << numK;
	return 0;
}
