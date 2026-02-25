#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n; cin>>n;
	vector<int> stick_len;
	
	while (n--) {
		int a; cin>>a;
		stick_len.push_back(a);
	}
	
	sort(stick_len.begin(), stick_len.end());
	reverse(stick_len.begin(), stick_len.end());
	
	cout << stick_len[0] * stick_len[1];
}
