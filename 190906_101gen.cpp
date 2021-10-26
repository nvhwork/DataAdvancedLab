// generate all binary strings of length n (n > 3) containing 101

#include <stdio.h>
#define MAX 100

int N;
int x[MAX];

void solution(){
	printf("\n");
	for(int i = 1; i <= N; i++) printf("%d", x[i]);
}

void TRY(int k, int i){
	if (i != k && i != k+1 && i != k+2){
		for (int v = 0; v <= 1; v++){
			x[i] = v;
			if (i == N) solution();
			else TRY(k, i+1);
		}
	} else if (i == N) solution();
	else TRY(k, i+1);
}

void get101(int k){
	x[k] = 1;
	x[k+1] = 0;
	x[k+2] = 1;
	TRY(k, 1);
	if (k+2 < N) get101(k+1);
}


int main(){
	scanf("%d", &N);
	get101(1);
	return 0;
}
