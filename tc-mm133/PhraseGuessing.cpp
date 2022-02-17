#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(x) x.begin(), x.end()
using ll = long long;
const ll MX = 1e16 + 7;

// EARIOTNSLCUDPMHGBFYWKVXZJQ -> freq of letters in dict

string line;
vector<string> WordList;
int N;
int P;
int elapsedTime;
string result = "";
double C;

int primes[] = {113, 131, 197, 199, 311, 337, 373, 719, 733, 919};

template<typename T>
T uniRand(T range_from, T range_to) {
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<T>    distr(range_from, range_to);
    return distr(generator);
}

ll score(string &s)
{
    // cerr << s;
    ll ded = 10.0*C;
    ll sc = (100LL - ded) * count(all(s), '.') + (20LL - ded) * count(all(s), '+') + (ded) * count(all(s), '*');
    // sc *=(10LL*C);
    return sc;
}

ll scoreInv(string &s)
{
    ll ded = 10.0*(10.0 - C);
    ll sc = (100LL - ded) * count(all(s), '*') + (20LL - ded) * count(all(s), '+') + (ded) * count(all(s), '.');
    // sc *=(10LL*C);
    return sc;
}

ll scoreEq(string &s)
{
    ll st = count(all(s), '*');
    ll dot = count(all(s), '.');
    ll plus = s.size() - st - dot;

    vector<ll> val = {st, dot, plus};
    sort(all(val));

    return (val[1] - val[0] + val[2] - val[1]);
}

int getRand(int beg, int end)
{
    return (beg + rand() % (end - beg + 1));
}


void calc(int dir)
{
    string best = "";
    ll best_score = MX;

    for (int i = 1, guesses = 1; i < 2e3 && guesses <= min(35, max(2, P - 3)); i++) {

        string guess = "";
        for (int n = 0; n < N; n++) {
            // int id = (i * primes[n]) % WordList.size();
            int id = uniRand(0, (int)WordList.size() - 1);
            guess += WordList[id];
            if (n < N - 1)
                guess += " ";
        }
        // valid guess
        if (guess.length() == P) {
            guesses++;
            cout << guess << endl;

            // read elapsed time and result
            cin >> elapsedTime;
            cin >> result;

            ll val;
            if (dir < 0) {
                val = score(result);
            } else if (dir > 0) {
                val = scoreInv(result);
            } else {
                val = scoreEq(result);
            }

            // cerr << result << " ";
            if (val < best_score) {
                best = guess;
                best_score = val;
            }
        }
    }

    // cerr << best << " " << best_score << " ";
    cout << best << endl;
    cin >> elapsedTime;
    cin >> result;

    // cerr << result << " ";

    cout << "-1" << endl;
}

int main()
{
    srand(unsigned(time(0)));

    ifstream in("words_alpha_filtered.txt");
    getline(in, line); // skip the header
    while (getline(in, line))
        WordList.push_back(line);
    in.close();

    cin >> N;
    cin >> P;
    cin >> C;

    // calc(-1);
    if (C < 0.42) {
        calc(-1);
    } else if (C > 0.58) {
        calc(1);
    } else {
        calc(0);
    }
}
