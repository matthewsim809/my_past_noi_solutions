#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
 int city_number;
 cin >> city_number;
 
 
 vector<int> train_time;
 vector<int> bus_time;
 
 for(int i=1;i<=city_number;++i){
  int time_for_train; cin >> time_for_train;
  train_time.push_back(time_for_train);
 }
 
 for(int i=1;i<=city_number;++i){
  int time_for_bus; cin >> time_for_bus;
  bus_time.push_back(time_for_bus);
 }
 
 int time_taken = 0;
 
 for(int i=0;i<=city_number;++i){
  if (train_time[i] < bus_time[i]) {
   time_taken += train_time[i];
  }
  else {
   time_taken += bus_time[i];
  }
 }
 
 cout << time_taken;
 
}
