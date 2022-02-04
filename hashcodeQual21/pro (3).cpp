#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

map<string, int> vehAtInt;
unordered_map<int, int> incomAtInt;

struct Street {
    int begin, end;
    string name;
    int len;

    void read() {
        cin >> begin >> end;
        cin >> name >> len;
        incomAtInt[end]++;
    }
};

struct Veh {
    vector<string> path;

    void read() {
        int path_cnt;
        cin >> path_cnt;

        path.resize(path_cnt);
        for(int i = 0; i < path_cnt; i++) {
             cin >> path[i];
             vehAtInt[path[i]]++;
        } 
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int D, I, S, V, F;
    cin >> D >> I >> S >> V >> F;
     
    vector<Street> streets(S);
    for(int i = 0; i < S; i++)
        streets[i].read();

    vector<Veh> vehs(V);
    for(int i = 0; i < V; i++)
        vehs[i].read();

    //no of incoming street at intersection
    vector<int> incom(I, 0);
    for(int i = 0; i < S; i++) {
        incom[streets[i].end]++;
    }


    vector<vector< pair<string, int> > > res;
    vector<int> resrep;
    int k = 0;

    for(int i = 0; i < I; i++) {
        // if(D / (I*incom[i]) < 1)
        //     continue;
            
        vector< pair<string, int> > temp;
        

        for(int j = 0; j < S; j++) {
            if(streets[j].end == i && ( (D / incomAtInt[i]) * (vehAtInt[streets[j].name] / pow(V, 0.5)) ) > 0) {
                // res[k].push_back(make_pair(streets[j].name, D / (I*incom[i]) ));
                temp.push_back(make_pair(streets[j].name, (D / incomAtInt[i]) * ( (vehAtInt[streets[j].name]) / pow(V, 0.8) ) ) );
            }
        }
        if(!temp.empty()) {
            resrep.push_back(i);
            res.push_back(temp);
            temp.clear();
            k++;
        }      
    }

    //output
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++) {
        cout << resrep[i] << endl;
        cout << res[i].size() << endl;

        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j].first << " " << res[i][j].second << endl;

        }
    }
}