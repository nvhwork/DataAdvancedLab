// PRODMOD

#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000007

long long n;
int a[1000009];

long long prodmod(long long k){
	if (k == 1) return a[1];
	return ((a[k] * prodmod(k-1))%MAX);
}

int main(){
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	printf("%lld", prodmod(n%MAX));
	return 0;
}
