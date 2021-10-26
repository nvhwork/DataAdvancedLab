// Max Sub-sequence

#include<stdio.h>
#define MAX 1000001
 
int n;
int a[MAX] = {0};
int S[MAX] = {0};
 
int maxSubseq(int a[], int S[]){
	S[1] = a[1];
	int ans = S[1];
	for (int i = 2; i <= n; i++){
		if (S[i-1] > 0) S[i] = S[i-1] + a[i];
		else S[i] = a[i];
		if (ans < S[i]) ans = S[i];
	}
	return ans;
}
 
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	printf("%d", maxSubseq(a, S));
	return 0;
}
