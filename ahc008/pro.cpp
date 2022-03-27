#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ff first
#define ss second
#define all(x) x.begin(), x.end()

int n, m;
int grid[31][31];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    memset(grid, -1, sizeof(grid));

    int n, m;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int px, py, pt;
        cin >> px >> py >> pt;
        grid[px][py] = pt;
    }

    for(int i = 0; i < m; i++) {
        int hx, hy;
        cin >> hx >> hy;

        grid[hx][hy] = 0;
    }

    for(int i = 0; i < 300; i++) {
    }

}