#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int h, w, k; cin>>h>>w>>k;
	
	priority_queue<int> cols;
	
	for(int i=0; i<k; i++) {
		int c; cin>>c;
		cols.push(c);
	}
	
	int initial_col = cols.top();
	cols.pop();
	
	int left = 1;
	int right = 2e9;
	int mid;
	int ans = -1;
	
	int init_col;
	int init_row;
	int curr_row;
	int needed_rows;
	
	bool possible_construction;
	
	while(left <= right) {
		mid = left+(right-left)/2;
		priority_queue<int> cols_copy = cols;
		init_col = initial_col;
		init_row = 1;
		curr_row = 1;
		
		possible_construction = true;
		
		while(!cols_copy.empty() && possible_construction==true) {
			if (init_col == cols_copy.top()) {
				curr_row++;
			}
			
			needed_rows = 1;
			
			if (abs(init_col-cols_copy.top()) + abs(curr_row-init_row) <= mid) {
				needed_rows = mid - init_col + cols_copy.top() - curr_row + init_row + 1;
			}
			
			if (curr_row + needed_rows > h+1) {
				possible_construction = false;
				break;
			}
			else {
				curr_row += needed_rows-1;
			}
			
			init_row = curr_row;
			init_col = cols_copy.top();
			cols_copy.pop();
		}
		
		if (possible_construction==true) {
			ans = mid;
			left = mid+1;
		}
		else {
			right = mid-1;
		}
	}
	
	cout << ans;
	
}
