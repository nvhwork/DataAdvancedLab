#include<iostream>
#define MAX 3001
using namespace std;

int N, K;
int a[MAX], c[MAX];
int f[MAX][101];	// f[i][j]: maximal amount of goods the Drone takes when it flies from point 1 to point i and by k steps 
					// (stops at k+1 points)

int solve(){
	int maxS = -1;
	f[1][1] = c[1];
    for (int i = 2; i <= N; i++){
        for (int j = 1; j <= i - 1; j++){
            // check whether from position j can go to position i 
            if (j + a[j] >= i){
                for (int k = 2; k <= K + 1; k++){
                    // check whether this route exists (f[j][k - 1] > 0 means that
					// from begining to position j, through k - 1 steps, Drone has took a number of goods > 0) 
                    if (f[j][k - 1] > 0){
                        f[i][k] = max(f[i][k], f[j][k - 1] + c[i]);
                        // in the end, we just need to find at position N (final stop),
						// which route (steps from 1 to k + 1) has the biggest number of goods
                        if (i == N){
                            maxS = max(maxS, f[i][k]);
                        }
                    }
                }
            }
        }
    }
    return maxS;
}

int main(){
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> c[i];
	for (int i = 1; i <= N; i++) cin >> a[i];
	cout << solve();
	return 0;
}
