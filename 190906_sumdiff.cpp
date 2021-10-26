#include<stdio.h>
#define MAX 100

int x[MAX];
int appear[MAX];
int N, t;

void init(int k){
	for (int i = k; i <= N/3 + 1; i++){
		x[i] = 0;
	}
}

int check(int v, int k){
	if (k == 1) return 1;
	else return (t - v >= 0 && x[k-1] > v && !appear[v]);
}

void solution(){
	printf("\n%d = %d", N, x[1]);
	for (int i = 2; i <= N/3 + 1; i++){
		if (x[i] == 0) break;
		else printf(" + %d", x[i]);
	}
}

void TRY(int k){
	for (int v = N; v >= 1; v--){
		if (check(v, k)){
			x[k] = v;
			appear[v] = 1;
			t -= v;
			if (t == 0) solution();
			else TRY(k+1);
			init(k); // clear the result of the previous section
			appear[v] = 0;
			t += v;
		}
	}
}

int main(){
	scanf("%d", &N);
	t = N;
	TRY(1);
	return 0;
}
