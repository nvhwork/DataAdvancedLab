#include<bits/stdc++.h>
#define INF 1000000007
#define MAX 31
using namespace std;

int n, b, q = 0;
int a[MAX];
int x[MAX];

int mod(int b){
	if (b >= 0) return b % INF;
	if (abs(b) <= INF) return b + INF;
	b = abs(b);
	int k = b / INF;
	b = b - k * INF;
	return INF - b;
}

int check(int v, int k){
	if (k < n-1) return 1;
	if (v == 1) return 1;
	else {
		for (int i = 1; i <= k-1; i++){
			if (x[k] == 1) return 1;
		}
		return 0;
	}
}

void solution(){
	int tmp = a[0];
	for (int i = 1; i < n; i++){
		if (x[i] == 0) tmp = mod(tmp - a[i]);
		else tmp = mod(tmp + a[i]);
	}
	if (tmp == b) q++;
}

void TRY(int k){
	for (int v = 0; v <= 1; v++){
		if (check(v, k)){
			x[k] = v;
			if (k == n - 1) solution();
			else TRY(k+1);
		}
	}
}

int main(){
	cin >> n >> b;
	for (int i = 0; i < n; i++) cin >> a[i];
	TRY(1);
	cout << q;
	return 0;
}
