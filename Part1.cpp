#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include <ctime>
using namespace std;


int main() {

  int n, no; // n is the guess of the opponent
  int gn[4]; // array to store the guessed number
  int sn[4]; // my secret number array
  int guess[4];

  // for generating a distinct 4-digit random number
  srand(unsigned(time(NULL)));
    
  vector<bool> checks(10, false);
  for (int i = 0; i < 4; i++) {
    int d;
    while(true){
      d = (rand() % 10);
      if(d!=0)
	break;
    }
    if (checks[d]) {
      i--;
      continue; // Skip duplicated digit
    }

    sn[i] = 0 + d;
    checks[d] = true;
  }

  for (int i = 0; i < 4; i++) {
    cout << sn[i]; //writing a valid secret number
  }
  cout << endl;
  int toss;
  int opponent_bull, opponent_cow;

  cin >> toss; //reading either 0 or 1

  if(toss == 0) {
    cin >> n;
    no = n;
    for (int i = 3; i >= 0; i--) {
      gn[i] = n % 10;
      n = n / 10;
    }

    int bulls = 0, cows = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
	if (sn[i] == gn[j]) {
	  if (i == j) {
	    bulls++; break;
	  }
	  else cows++;
	}
      }
    }
    cout << bulls << endl;
    cout << cows << endl;

  }

  while(true) {
    vector<bool> check(10, false);
    for (int i = 0; i < 4; i++) {
      int c = (rand() % 10);

      if (check[c]) {
	i--;
	continue;
      }

      guess[i] = 0 + c;
      check[c] = true;
    }
		
    for (int i = 0; i < 4; i++) {
      cout << guess[i];
    }
    cout << endl;
    cin >> opponent_bull >> opponent_cow;


    cin >> n;
    no = n;
    for (int i = 3; i >= 0; i--) {
      gn[i] = n % 10;
      n = n / 10;
    }

    int bulls = 0, cows = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
	if (sn[i] == gn[j]) {
	  if (i == j) {
	    bulls++; break;
	  }
	  else cows++;
	}
      }
    }
    cout << bulls << endl;
    cout << cows << endl;
  }

}




