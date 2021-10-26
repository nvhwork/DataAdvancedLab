#include <bits/stdc++.h>
#define fi first
#define se second
#define MAX 1000100
using namespace std;
pair<int, int> a[MAX];
int maxV[MAX];
int n;

bool userCMP(pair<int, int> x, pair<int, int> y){
    return x.se < y.se;
}

int searchForMaxTj(int target, int up_bound){
    // need to find the maximum value of Tj that smaller than target
    int low_bound = 1;
    while (low_bound <= up_bound){
        int mid = (up_bound + low_bound) / 2;
        if (a[mid].se < target) low_bound = mid + 1;
        else up_bound = mid - 1;
    }
    return up_bound;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    // sort the vector following the increment of t[]
    sort(a + 1, a + 1 + n, userCMP);
    // store the max C from 0 to i into maxV[i]
    for (int i = 1; i <= n; i++){
        maxV[i] = max(maxV[i - 1], a[i].se - a[i].fi);
    }
    int ans = -1;
    for (int i = 2; i <= n; i++){
        // find maximum value j (from 0 to i - 1) that smaller than a[i].fi
        int j = searchForMaxTj(a[i].fi, i - 1);
        if (j > 0 && a[i].fi > a[j].se){
            ans = max(ans, maxV[j] + a[i].se - a[i].fi);
        }
    }
    cout << ans;
}
