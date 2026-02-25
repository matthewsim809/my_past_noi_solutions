#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n; cin>>n;
	priority_queue<int, vector<int>, greater<int>> cats;
	
	while(n--){
		int h; cin>>h;
		cats.push(h);
	}
	
	string possible = "YES";
	int prev_cat = cats.top()-1;
	
	while(cats.size()!=1){
		cats.pop();
		if (cats.top() > prev_cat+1) {
			prev_cat = cats.top();
			continue;
		}
		else {
			possible = "NO";
			break;
		}
	}
	
	cout << possible;
}
