#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n, d; cin>>n>>d;
  
  deque<int> weights;
  
  for(int i=0; i<n; i++) {
    int w; cin>>w;
    weights.push_back(w);
  }
  
  weights[0] = 0;
  int len = n-1;
  int curr_sum = 0;
  int dist_sum = 0;
  
  while(!weights.empty()) {
    if (weights.back()>curr_sum) {
      dist_sum += (weights.back()-curr_sum) * len;
      curr_sum += (weights.back()-curr_sum);
    }
    len--;
    weights.pop_back();
  }
  
  cout << dist_sum;
  
}
