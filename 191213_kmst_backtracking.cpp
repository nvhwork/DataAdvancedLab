#include <bits/stdc++.h>
#define MAX 35
using namespace std;
  
int n, m, t;
int u[MAX], v[MAX], c[MAX];
int w = 10000;
int x[MAX];
int instantWeight;
int minWeight = 10000;
  
void input()
{
    cin >> n >> m >> t;
    for (int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i] >> c[i];
        minWeight = min(minWeight, c[i]);
    }
}
  
int check(int v, int k)
{
    return (v > x[k - 1]) && (instantWeight + c[v] + minWeight * (t - k - 1) < w);
}
  
void solution()
{
    int we = 0;
    int check[MAX] = {0};
    int c_node = 0;
    for (int i = 1; i <= t; i++)
    {
        if (check[u[x[i]]] == 0)
        {
            check[u[x[i]]] = 1;
            c_node++;
        }
        if (check[v[x[i]]] == 0)
        {
            check[v[x[i]]] = 1;
            c_node++;
        }
        we += c[x[i]];
    }
    if (c_node == t + 1)
    {
        w = min(we, w);
    }
}
  
void solve(int k)
{
    for (int v = 1; v <= m; v++)
    {
        if (check(v, k))
        {
            instantWeight += c[v];
            x[k] = v;
            if (k == t)
                solution();
            else if (instantWeight + minWeight * (t - k) < w)
                solve(k + 1);
            instantWeight -= c[v];
        }
    }
}
  
int main()
{
    input();
    solve(1);
    if (w == 10000) w = -1;
    cout << w << endl;
}
