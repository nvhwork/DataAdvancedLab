#include<stdio.h>
#define MAX 1000000007

int main(){
	long int a, b;
	scanf("%ld %ld", &a, &b);
	
	a = a % MAX;
	b = b % MAX;
	
	printf("%ld", (a + b) % MAX);
	return 0;
}
