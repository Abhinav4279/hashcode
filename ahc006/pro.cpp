#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ff first
#define ss second
#define rep(i, s, n) for (int i = s; i < n; i++)
#define all(x) x.begin(), x.end()

const int N = 800;
const ll MX = 1e17 + 5;
const ll oN = 1000;
pair<int, int> src[oN + 1];
pair<int, int> dest[oN + 1];

struct Point {
    pair<int, int> rc;
    int ord_id;

    Point(pair<int, int> rc, int ord_id) {
        this->rc = rc;
        this->ord_id = ord_id;
    }
};

int getRand(int l, int r) {
    return rand() % (r - l + 1);
}

bool inside(int pos, int l, int r) {
    return (pos >= l && pos <= r);
}

//manhattan dist
ll dist(pair<int, int> from, pair<int, int> to) {
    return ((ll)abs(from.ff - to.ff) + abs(from.ss - to.ss));
}

ll getTime(vector<Point>& arr) {
    ll here = 0;
    rep(i, 1, 50) {
        here +=dist(arr[i - 1].rc, arr[i].rc);
    }

    return here;
}

pair<ll, vector<Point>> perf(int x, int y, int sz) {
    vector<Point> ret;

    int begx = x - sz, endx = x + sz;
    int begy = y - sz, endy = y + sz;

    vector<Point> src_av, dest_av;
    // if(sz*sz < 1000) {
    //     for(int i = bega; i <= enda; i++) {
    //         for(int j = bega; j < enda; j++) {
    //             if()
    //         }
    //     }
    // }
    // else {
        for(int i = 1; i <= 1000; i++) {
            if(inside(src[i].ff, begx, endx) && inside(src[i].ss, begy, endy) && inside(dest[i].ff, begx, endx) && inside(dest[i].ss, begy, endy)) {
                Point s(src[i], i);
                Point d(dest[i], i);
                src_av.push_back(s);
                dest_av.push_back(d);
            }
        }
    // }

    if(src_av.size() < 50)
        return make_pair(MX, ret);

    vector<Point> src50(src_av.begin(), src_av.begin() + 50), dest50(dest_av.begin(), dest_av.begin() + 50);

    sort(all(src50), [](Point a, Point b) {
        // return (100LL*(a.rc.ff + a.rc.ss)) < (100LL*(b.rc.ff + b.rc.ss));
        return (100LL*(a.rc.ff + a.rc.ss) + 10LL*a.rc.ff + a.rc.ss) < (100LL*(b.rc.ff + b.rc.ss) + 10LL*b.rc.ff + b.rc.ss);
    });


    sort(all(dest50), [](Point a, Point b) {
        // return (100LL*(a.rc.ff + a.rc.ss)) > (100LL*(b.rc.ff + b.rc.ss));
        return (100LL*(a.rc.ff + a.rc.ss) + 10LL*a.rc.ff + a.rc.ss) < (100LL*(b.rc.ff + b.rc.ss) + 10LL*b.rc.ff + b.rc.ss);
    });

        
    ll time = dist({400, 400}, src50[0].rc) + getTime(src50);
    time += dist(src50.back().rc, dest[0]) + getTime(dest50) + dist(dest50.back().rc, {400, 400});

    ret = src50;
    for(auto& val: dest50)
        ret.push_back(val);

    return {time, ret};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(unsigned (time(0)));
    
    rep(i, 1, 1001) {
        cin >> src[i].ff >> src[i].ss;
        cin >> dest[i].ff >> dest[i].ss;
    }

    ll mn_time = MX;
    vector<Point> ans;
    // int sz = 500;
    for(double mul = 1.2; mul <= 2; mul +=0.3) {
        for(int sz = 90; sz <= N; sz *=mul) {
            // cout << sz << " " << endl;

    //         set<pair<int, int>> seen;
            rep(i, 0, 100) {
                int x = getRand(0 + sz / 2, N - sz / 2);
                int y = getRand(0 + sz / 2, N - sz / 2);

                // if(seen.find({x, y}) != seen.end()) {
                //     i--;
                //     continue;
                // }

                pair<ll, vector<Point>> gt = perf(x, y, sz);
                // cout << gt.ff << " ";
                if(mn_time > gt.ff) {
                    //TODO: set global best
                    mn_time = gt.ff;
                    ans = gt.ss;
                }
            }
        }
    }

    //o/p
    // cout << ans.size() << " ";
    set<int> op;
    for(auto& pt: ans) {
        op.insert(pt.ord_id);
    }

    cout << op.size() << " ";
    for(auto& val: op)
        cout << val << " ";
    cout << '\n';

    cout << ans.size() + 2 << " " << "400 400 ";
    for(auto& pt: ans) {
        cout << pt.rc.ff << " " << pt.rc.ss << " ";
    }
    cout << "400 400";
}