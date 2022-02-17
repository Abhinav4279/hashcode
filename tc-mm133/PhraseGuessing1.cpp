// C++11
#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(x) x.begin(), x.end()
using ll = long long;
const ll MX = 1e15 + 7;

// EARIOTNSLCUDPMHGBFYWKVXZJQ -> freq of letters in dict

ll score(string& s) {
    ll sc = 100LL*count(all(s), '.') + 20LL*count(all(s), '+');
    return sc;
}

ll scoreInv(string& s) {
    ll sc = 100LL*count(all(s), '*') + 20LL*count(all(s), '+');
    return sc;
}

ll scoreEq(string& s) {
    ll st = count(all(s), '*');
    ll dot = count(all(s), '.');
    ll plus = s.size() - st - dot;

    vector<ll> val = {st, dot, plus};
    sort(all(val));

    return (val[1] - val[0] + val[2] - val[1]);
}

int getRand(int beg, int end) {
    return (beg + rand()%(end - beg + 1));
}

// std::chrono::steady_clock::time_point begin;


string line;
vector<string> WordList;
int N;
int P;
int elapsedTime;
string result;
double C;
map<int, vector<string>> words;

int primes[]={113, 131, 197, 199, 311, 337, 373, 719, 733, 919};

void calc(int dir) {
        string best;
        ll best_score = MX;

        for (int i = 1, guesses = 1; guesses <= 20; i++)
        {
            // std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            // if(std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count > std::chrono::duration_cast<std::chrono::microseconds>(5*1000000))
                // break;
            // string guess = "";
            // int tot_len = P;
            // bool fnd = 1;
            // for (int n = 0; n < N;)
            // {
            //     // int id=(i*primes[n]) % WordList.size();

            //     if(tot_len == 0) {
            //         fnd = 0;
            //         break;
            //     }

            //     int cur_len = getRand(1, max(3, tot_len - (N - n - 1)*6));
            //     if(tot_len < 7 && n == N - 1)
            //         cur_len = tot_len;
            //     if(words.find(cur_len) == words.end())
            //         continue;

            //     int id = getRand(0, words[cur_len].size() - 1);

            //     guess += words[cur_len][id];

            //     tot_len -=(cur_len);
            //     if (n < N - 1) {
            //         guess += " ";
            //         tot_len--;
            //     }

            //     n++;
            // }

            // if(fnd == 0)
            //     continue;

                string guess="";
    for (int n=0; n<N; n++)
    {
      int id=(i*primes[n]) % WordList.size();
      guess += WordList[id];
      if (n<N-1) guess += " ";
    }
            // valid guess
            if (guess.length() == P)
            {
                guesses++;
                cout << guess << endl;
                cout.flush();

                // read elapsed time and result
                cin >> elapsedTime;
                getline(cin, result);

                ll val;
                if(dir < 0) {
                    val = score(result);
                } else if(dir > 0) {
                    val = scoreInv(result);
                } else {
                    val = scoreEq(result);
                }

                cerr << guesses << " ";
                if(val < best_score) {
                    best = guess;
                    best_score = val;
                }
            }

            // for(int i = 0; i < 100; i++) {}

            if (elapsedTime > 7)
                break;
        }

        if(best != result) {
            cout << best << endl;
            cin >> elapsedTime;
            getline(cin, result);
        }
            
        cout << "-1" << endl;
        cout.flush();
}

int main()
{
    srand(unsigned (time(0)));

    // begin = std::chrono::steady_clock::now();
    ifstream in("words_alpha_filtered.txt");
    getline(in, line); // skip the header
    while (getline(in, line))
        words[(int)line.size()].push_back(line);
    in.close();

    cin >> N;
    cin >> P;
    cin >> C;

    if (C < 0.4) {
        calc(-1);
    } else if (C > 0.6) {
        calc(1);
    } else {
        calc(0);
    }
}
