#include <bits/stdc++.h>

using namespace std;
#define int long long

int main() {
 int n;
 cin >> n;
	
 int seats = ceil(n/2.0);
	
 vector<int> v = {};
	
 for(int i=1; i<=n; ++i){
  int h; cin >> h;
  v.push_back(h);
 }

 sort(v.begin(), v.end());
 reverse(v.begin(), v.end());
	
 int max_happiness = 0;
 for(int i=0; i<seats; ++i){
  if (v[i] >= 0) {
   max_happiness += v[i];
  }
 }
 
 cout << max_happiness;
}
