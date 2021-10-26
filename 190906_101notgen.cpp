// generate all binary strings of length n (n > 3) that do not contain 101

#include <stdio.h>
#define MAX 100

int N;
int x[MAX];

int check(int v, int k){
	if (k < 3) return 1;
	if (x[k-2] == 1 && x[k-1] == 0 && v == 1) return 0;
	else return 1;
}

void solution(){
	printf("\n");
	for (int i = 1; i <= N; i++) printf("%d", x[i]);
}

void TRY(int k){
	for (int v = 0; v <= 1; v++){
		if (check(v, k)){
			x[k] = v;
			if (k == N) solution();
			else TRY(k + 1);
		}
	}
}


int main(){
	scanf("%d", &N);
	TRY(1);
	return 0;
}
