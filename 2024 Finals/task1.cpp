#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int c, p; cin>>c>>p;

  vector<pair<int, int>> conts;
  
  for(int i=0; i<c; i++) {
    int minqual, satis; cin>>minqual>>satis;
    conts.push_back({satis, minqual});
  }
  
  sort(conts.begin(), conts.end(), greater<pair<int, int>>());
  
  int max_satis = 0;
  
  for(int i=0; i<p; i++) {
    int qual, sasloss; cin>>qual>>sasloss;
    for(auto p: conts) {
      if (qual >= p.second) {
        max_satis += max(0LL, p.first-sasloss);
        break;
      }
    }
  }
  
  cout << max_satis;
}
