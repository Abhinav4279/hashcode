#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ff first
#define ss second
#define rep(i, s, n) for (int i = s; i < n; i++)
#define all(x) x.begin(), x.end()

int n, m, s, bmove;
vector<vector<int>> adj;

int myrandom (int first, int last) { return rand()%(last - first + 1);}

bool get(vector<int>& deg, vector<int>& flags) {
    string s;
    cin >> s;

    if(s == "AC" || s == "F")
        return 0;
    int len;
    cin >> len;

    deg.resize(len);
    flags.resize(len);
    rep(i, 0, len) {
        cin >> deg[i] >> flags[i];
    }
}

void solve() {
    cin >> n >> m >> s >> bmove;

    adj.resize(n + 1);
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> deg, flags;
    int cnt = 0;
    while(get(deg, flags)) {
        int len = deg.size();

        if(find(all(flags), 0) == flags.end()) {

            
            int len = deg.size();
            int mx = 0;
            rep(i, 0, len) {
                if(deg[i] < deg[mx])
                    mx = i;
            }

            if(cnt%2)
                cout << 1 + myrandom(1, len) << endl;
            else 
                cout << mx + 1 << endl;

            cnt = 1 - cnt;
        } else {
            int mx = -1;
            rep(i, 0, len) {
                if(flags[i] == 0 && (mx == -1 || deg[i] > deg[mx]))
                    mx = i;
            }

            cout << mx + 1 << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    srand ( unsigned ( std::time(0) ) );
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}