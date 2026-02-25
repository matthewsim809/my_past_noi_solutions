#include <bits/stdc++.h>

using namespace std;
#define int long long

int normal[1000][1000];
int x_dir[1000][1000];
int y_dir[1000][1000];

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n, m; cin>>n>>m;
  
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      int num; cin>>num;
      normal[i][j] = num;
    }
  }
  
  for(int i=0; i<n; i++) {
    int max_x_right = INT_MIN;
    for(int j=0; j<m; j++) {
      max_x_right = max(max_x_right+normal[i][j],normal[i][j]);
      x_dir[i][j] = max_x_right;
    }
  }
  
  for(int i=0; i<n; i++) {
    int max_x_left = INT_MIN;
    for(int j=0; j<m; j++) {
      max_x_left = max(max_x_left+normal[i][m-j-1],normal[i][m-j-1]);
      x_dir[i][m-j-1] = max(x_dir[i][m-j-1], max_x_left);
    }
  }
  
  for(int i=0; i<m; i++) {
    int max_y_up = INT_MIN;
    for(int j=0; j<n; j++) {
      max_y_up = max(max_y_up+normal[n-j-1][i],normal[n-j-1][i]);
      y_dir[n-j-1][i] = max_y_up;
    }
  }

  for(int i=0; i<m; i++) {
    int max_y_down = INT_MIN;
    for(int j=0; j<n; j++) {
      max_y_down = max(max_y_down+normal[j][i],normal[j][i]);
      y_dir[j][i] = max(y_dir[j][i], max_y_down);
    }
  }
  
  int max_l_sum = INT_MIN;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      max_l_sum = max(max_l_sum, x_dir[i][j]+y_dir[i][j]-normal[i][j]);
    }
  }
  
  cout << max_l_sum;
  
}
