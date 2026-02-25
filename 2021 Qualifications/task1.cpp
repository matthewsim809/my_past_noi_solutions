#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
	
 int n, a, b; cin>>n>>a>>b;
	
 vector<int> p_list;
 vector<int> b_list;
	
 for(int i=0; i<n; i++){
  int p_score; cin>>p_score;
  p_list.push_back(p_score);
 }
	
 int bio_sum = 0;

 for(int i=0; i<n; i++){
  int b_score; cin>>b_score;
  bio_sum += b_score;
  p_list[i] = p_list[i] - b_score;
 }
	
 sort(p_list.begin(), p_list.end());
 reverse(p_list.begin(), p_list.end());
	
 int phys_sum = 0;
	
 for(int i=0; i<a; i++){
  phys_sum += p_list[i];	 
 }
	
 cout << phys_sum+bio_sum;

}
