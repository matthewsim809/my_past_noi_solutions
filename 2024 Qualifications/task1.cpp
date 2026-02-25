#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
 int n;
 int x, y;

 cin >> n >> x >> y;

 int minimum_cost = 0;
 for(int i=1; i<=n; ++i){
  int trips; cin >> trips;
  minimum_cost += min(x*trips,y);
 }
	
 cout << minimum_cost;
	
}
