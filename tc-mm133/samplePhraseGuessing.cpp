// C++11
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <string>

using namespace std;



int main() 
{
  string line;
  vector<string> WordList;
  
  ifstream in("words_alpha_filtered.txt");
  getline(in, line);    //skip the header
  while(getline(in, line))  WordList.push_back(line);
  in.close();
      
  
  int N;
  int P;
  int elapsedTime;
  string result;
  double C;

  cin >> N;
  cin >> P;
  cin >> C;
  
  
  int primes[]={113, 131, 197, 199, 311, 337, 373, 719, 733, 919};
  
  for (int i=1, guesses=1; guesses<=20; i++)
  {      
    string guess="";
    for (int n=0; n<N; n++)
    {
      int id=(i*primes[n]) % WordList.size();
      guess += WordList[id];
      if (n<N-1) guess += " ";
    }
    
    //valid guess
    if (guess.length()==P)
    {
      guesses++;
      cout << guess << endl;
      cout.flush();
      
      //read elapsed time and result
      cin >> elapsedTime;
      getline(cin, result);
    }

    // if(elapsedTime > 1)
    //   break;
  }

  cout << "-1" << endl;
  cout << elapsedTime;
  cout.flush();
}
