#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
 int n, m;
 cin >> n >> m;
	
 vector<int> v;
 for(int i=1; i<=m; ++i){
  int k;
  cin >> k;
  v.push_back(k);
 }
	
 sort(v.begin(), v.end());
	
 int current_given = 0;
 int school_number = 0;
 for(int i: v) {
  if (current_given + i <= n) {
   current_given += i;
   school_number += 1;
  }
  else {
   break;
  }
 }
	
 cout << school_number;
	
}
