#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ff first
#define ss second
#define rep(i, s, n) for (int i = s; i < n; i++)
#define all(x) x.begin(), x.end()

// vector<int> getRand(int sz) {
//     vector<int> v(sz);
//     iota(all(v), 0);

//     random_shuffle(all(v));
// }

vector<string> getDelim() {
    int len;
    cin >> len;

    vector<string> ret;
    unordered_set<string> vis;
    string str;
    rep(i, 0, len) {
        cin >> str;
        if(vis.find(str) == vis.end()) {
            ret.push_back(str);
            vis.insert(str);
        }
    }

    return ret;
}

int myrandom (int first, int last) { return rand()%(last - first + 1);}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    std::srand ( unsigned ( std::time(0) ) );
    
    int c;
    cin >> c;

    int cnt = 0;
    vector<vector<string>> l, d;
    rep(i, 0, c) {
        vector<string> a, b;
        a = getDelim();
        b = getDelim();

        bool flag = 0;
        for(auto& s: a){
            if(find(all(b), s) != b.end()) {
                flag = 1;
                cnt++;
                break;
            }
        }

        if(flag == 0) {
            l.push_back(a);
            d.push_back(b);
        }
    }

    c -=cnt;

    map<string, int> lik, dlik;
    rep(i, 0, c) {
        for(auto& s: l[i])
            lik[s]++;
        for(auto& s: d[i])
            dlik[s]++;
    }
    vector<double> score(c, 0);
    rep(i, 0, c) {
        for(auto& s: l[i])
            score[i] +=dlik[s];
        for(auto& s: d[i])
            score[i] +=lik[s];
    }

        //     for(auto& s: l[i])
        //     score[i] +=2LL*dlik[s];
        // for(auto& s: d[i])
        //     score[i] +=2.03*lik[s];

    vector<int> id(c);
    iota(all(id), 0);
    sort(all(id), [&] (int o, int t) {
        return (score[o] < score[t]);
    });

    // cout << c << endl;
    int mxsc = 0;

    for(int i = 0; i < 1; i++) {
        
        // set<int> leave;
        // rep(i, 0, 500) {
        //     leave.insert(myrandom(5000, 6000));
        // }
        // sort(all(leave), greater<int>());
        // rotate(id.begin(), id.begin() + (i + 97*i) % c, id.end());

        set<string> likes, dislikes;
        int sc = 0;
        for(int i = 0; i < 9000; i++) {
            // if(leave.find(id[i]) != leave.end()) {
            //     // leave.erase(id[i]);
            //     continue;
            // }

            bool good = 1;
            for(auto& s: l[id[i]]) {
                if(dislikes.find(s) != dislikes.end()) {
                    good = 0;
                    break;
                }
            }

            for(auto& s: d[id[i]]) {
                if(likes.find(s) != likes.end()) {
                    good = 0;
                    break;
                }
            }

            if(good) {
                for(auto& s: l[id[i]])
                    likes.insert(s);
                for(auto& s: d[id[i]])
                    dislikes.insert(s);
                sc++;
            }

        }

        mxsc = max(mxsc, sc);

    }

    cout << mxsc << '\n';
    // cout << likes.size() << ' ';
    // for(auto& s: likes)
    //     cout << s << " ";
}