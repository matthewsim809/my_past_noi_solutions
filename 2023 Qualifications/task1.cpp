#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  
  int n; cin >> n;
  int largest_area;
  
  for(int i=0; i<=n; ++i){
    int h, w;
    cin >> h >> w;
    if (h*w > largest_area){
       largest_area = h*w;
    }
  }
	
  cout << largest_area;
	
}
