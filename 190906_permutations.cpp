// write a program to generate all permutations of 1, 2, 3, ....n

#include <stdio.h>
#define MAX 100

int n;
int x[MAX];
int appeared[MAX]; // technique for marking. If equal to 1 then has already appeared. else then has not

void init(){
	for(int i = 0; i < MAX; i++) appeared[i] = 0;
}

void solution(){
	for(int i = 1; i <= n; i++) printf("%d ", x[i]);
	printf("\n");
}

void TRY(int k){
	for(int v = 1; v <= n; v++){
		if(!appeared[v]){
			x[k] = v;
			appeared[v] = 1;
			if(k == n) solution();
			else TRY(k+1);
			appeared[v] = 0; // backtrack
		}
	}
}


int main(){
	scanf("%d", &n);
	init();
	TRY(1);
}
