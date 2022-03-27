#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ff first
#define ss second
#define all(x) x.begin(), x.end()

int C, P; //contributors, projects
vector<string> cont_m;
vector<string> proj_m;
// map<string, int> skill_m;
int cnt_skill = 0;

// struct Skills {
//     int id;
//     vector<int> proj_s;
//     vector<int> cont_s;

//     Skills(int _id) {
//         id = _id;
//     }
// };
// vector<Skills> skills;

struct Contributor {
    string name;
    int id;
    int n_skills;
    vector<string> c_skills;
    vector<int> lev;

    void read(int _id) {
        id = _id;
        cin >> name >> n_skills;

        cont_m.push_back(name);        
        c_skills.resize(n_skills);
        lev.resize(n_skills);
        string skill;
        for(int i = 0; i < n_skills; i++) {
            cin >> skill >> lev[i];
            c_skills[i] = skill;
            // if(skill_m.find(skill) == skill_m.end()) {
            //     skill_m[skill] = cnt_skill;
            //     // Skills sk = Skills(cnt_skill);
            //     // skills.push_back(sk);
            //     cnt_skill++;
            // } 
            
            // c_skills[i] = skill_m[skill];
        }
    }
};
vector<Contributor> conts;

struct Project {
    string name;
    int id;
    int d; //days to complete
    int s; //score
    int b; //best before
    int n_skills; //num of skills

    vector<string> p_skills; //basically skill req for this role
    vector<int> lev;

    void read(int _id) {
        id = _id;
        cin >> name >> d >> s >> b >> n_skills;

        proj_m.push_back(name);

        p_skills.resize(n_skills);
        lev.resize(n_skills);
        string skill;
        for(int i = 0; i < n_skills; i++) {
            cin >> skill >> lev[i];
            p_skills[i] = skill;
            // if(skill_m.find(skill) == skill_m.end()) {
            //     skill_m[skill] = cnt_skill++;
            // } 

            // skills[i] = skill_m[skill];
        }
    }
};
vector<Project> projs;


void read() {
    cin >> C >> P;

    conts.resize(C);
    projs.resize(P);
    for(int i = 0; i < C; i++) {
        conts[i].read(i);
    }

    for(int i = 0; i < P; i++) {
        projs[i].read(i);
    }
}

// struct Output {
//     int proj_id;
//     vector<int> 
// }

vector<pair<int, vector<int>>> output() {
    vector<pair<int, vector<int>>> op;

    int iter = 0;
    for(Project& p: projs) {
        // if(p.name != "WebChat")
        //     continue;

        // for(auto& s: p.p_skills)
        //     cout << s << " ";
        vector<int> proj_conts;
        bool done = 1;

        vector<bool> mark(C, 0);
        for(int rol = 0; rol < p.n_skills; rol++) {
            for(Contributor& c: conts) {
                if(mark[c.id])
                    continue;
                for(int i = 0; i < c.n_skills; i++) {
                    iter++;
                    if(iter > 1e6)
                        return op;
                        
                    if(c.c_skills[i] == p.p_skills[rol] && c.lev[i] >= p.lev[rol]) {
                        c.lev[i]++;
                        mark[c.id] = 1;
                        proj_conts.push_back(c.id);

                        // cout << c.c_skills[i] << " " << c.name << '\n';
                        break;
                    }
                }
            }
        }

        if(proj_conts.size() == p.n_skills) {
            // cout << p.name << " ";
            pair<int, vector<int>> ins;
            ins.ff = p.id;
            // reverse(all(proj_conts));
            ins.ss = proj_conts;
            op.push_back(ins);
        }
    }

    return op;
}

// void outp(Contributor& p) {
//     cout << p.name << p.n_skills;
// }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    read();

    sort(all(projs), [](Project a, Project b) {
        return a.s > b.s;
    });

    // cout << projs.size() << " ";
    // for(int i = 0; i < C; i++) {
    //     outp(conts[i]);
    //     cout << '\n';
    // }

    vector<pair<int, vector<int>>> ans = output();
    cout << ans.size() << '\n';

    for(int i = 0; i < ans.size(); i++) {
        pair<int, vector<int>> here = ans[i];
        cout << projs[here.ff].name << '\n';
        for(auto& contrib: here.ss) {
            cout << conts[contrib].name << " ";
        }
        cout << '\n';
    }
}