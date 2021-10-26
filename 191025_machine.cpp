#include<iostream> 
#define MAX 1000007
using namespace std;

int N;
int a[MAX][2];
int maxC[MAX];

bool userCMP(pair<int, int> x, pair<int, int> y){
    return x.se < y.se;
}

void heapify(int b[][2], int i, int n){
	// array to be heapified is a[i..n]
	int U = 2*i; // upper element
	int L = 2*i + 1; // lower element
	int max = i;
	if (U <= n && b[U][1] > b[i][1]) max = U;
	if (L <= n && b[L][1] > b[max][1]) max = L;
	if (max != i){
		swap(b[i][1], b[max][1]);
		swap(b[i][2], b[max][2]);
		heapify(b, max, n);
	}
}

void buildHeap(int b[][2], int n){
	for (int i = n/2; i >= 1; i--){
		heapify(b, i, n);
	}
}

void heapSort(int b[][2], int n){
	buildHeap(b, n);
	for (int i = n; i > 1; i--){
		swap(b[1][1], b[i][1]);
		swap(b[1][2], b[i][2]);
		heapify(b, 1, i-1);
	}
}

int findMaxSub(int target, int up_bound){
	// find the maximum value in the satisfied position of the sub-array
	int low_bound = 1;
	while (low_bound <= up_bound){
		int mid = (low_bound + up_bound) / 2;
		if (a[mid][2] < target) low_bound = mid + 1;
		else up_bound = mid - 1;
	}
	return up_bound;
}

int solve(){
	int c = -1;
	for (int i = 2; i <= N; i++){
		int j = findMaxSub(a[i][1], i-1);
		// find the maximum value j (from 1 to i-1) that is smaller than a[i][1]
		if (j > 0 && a[j][2] < a[i][1])
			c = max(c, maxC[j] + a[i][2] - a[i][1]);
	}
	return c;
}

int main(){
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= 2; j++)
			cin >> a[i][j];
	heapSort(a, N);
	for (int i = 1; i <= N; i++)
		maxC[i] = max(maxC[i-1], a[i][2] - a[i][1]);
	cout << solve();
	return 0;
}
