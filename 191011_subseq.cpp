// SUBSEQ

#include<stdio.h>
#include<stdlib.h>
#define MAX 100007

int n, m;
int a[MAX];
int x[MAX];

void input(){
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
}

int subseq(int a[], int x[]){
	int c = 0;
	x[1] = a[1];
	if (x[1] <= m) c++;
	for (int i = 2; i <= n; i++){
		x[i] = a[i];
		if (x[i] <= m) c++;
		for (int j = i-1; j > 0; j--){
			x[i] += a[j];
			if (x[i] <= m) c++;
		}
	}
	return c;
}

int main(){
	input();
	printf("%d", subseq(a, x));
	return 0;
}
