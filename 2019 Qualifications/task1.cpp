#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
 int s, e;
 cin >> s >> e;
 for(int i = s; i <= e; ++i){
  string a = to_string(i);
  string b = a;
  reverse(b.begin(), b.end());
  if (a == b) {
   cout << "Palindrome!\n";
  }
  else {
   cout << a << "\n";
  }
 }
}
