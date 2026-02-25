#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n, s; cin>>n>>s;
  
  vector<pair<int, int>> students;
  //height, class
  
  for(int i=0; i<n; i++) {
    for(int j=0; j<s; j++) {
      int height; cin>>height;
      students.push_back({height, i});
    }
  }
  
  sort(students.begin(), students.end());
  
  int left = 0;
  
  int min_diff = LLONG_MAX;
  
  vector<int> s_from_class(n, 0);
  int class_counter = 0;
  
  for(int right=0; right<n*s; right++) {
    if (s_from_class[students[right].second] == 0) {
      class_counter++;
    }
    
    s_from_class[students[right].second]++;
    
    while(class_counter == n) {
      min_diff = min(min_diff, abs(students[left].first-students[right].first));
      
      if (s_from_class[students[left].second] == 1) {
        class_counter--;
      }
      
      s_from_class[students[left].second]--;
      left++;
    }
  }
  
  cout << min_diff;

}
