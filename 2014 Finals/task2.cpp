#include <bits/stdc++.h>

using namespace std;
#define int long long

struct DSU {
	vector<int> parent, size;

	DSU(int n) {
		parent.resize(n);
		size.assign(n, 1);
		iota(parent.begin(), parent.end(), 0);
	}
	int find(int x) {
		if (parent[x] == x)
			return x;
		return parent[x] = find(parent[x]); // path compression
	}
	bool unite(int a, int b) {
		a = find(a);
		b = find(b);

		if (a == b) {
			return false;
		}
		if (size[a] < size[b]) {
			swap(a, b);
		}

		parent[b] = a;
		size[a] += size[b];
		return true;
	}
};


struct Edge {
	int u, v;
	long long w;

	// For minimum spanning tree
	bool operator<(const Edge& other) const {
	  return w > other.w;
	}

};

pair<long long, vector<Edge>> kruskal(int n, vector<Edge>& edges) {
	// Sort edges by weight
	sort(edges.begin(), edges.end());

	DSU dsu(n);
	long long total_weight = 0;
	vector<Edge> mst_edges;

	for (const Edge& e : edges) {
		// If adding this edge doesn't form a cycle
		if (dsu.unite(e.u, e.v)) {
			total_weight += e.w;
			mst_edges.push_back(e);
			if ((int)mst_edges.size() == n - 1)
				break;
		}
	}

	return {total_weight, mst_edges};
}


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int v, e, q; cin>>v>>e>>q;
  
  vector<Edge> edges;
  
  for(int i=0; i<e; i++) {
    int a, b, qual; cin>>a>>b>>qual;
    edges.push_back({a, b, qual});
  }
  
	auto [total, mst] = kruskal(v+1, edges);
	
	vector<vector<pair<int,int>>> adj(v+1);
	
	for(auto &e: mst) {
	  adj[e.u].push_back({e.v, e.w});
	  adj[e.v].push_back({e.u, e.w});
	}
	
	vector<int> visited(v+1, false);
	vector<int> distance(v+1);
	
	queue<pair<int, int>> unexplored;
	unexplored.push({1, INT_MAX});
	visited[1] = true;
	
	while(!unexplored.empty()) {
	  auto [node, dist] = unexplored.front();
	  for(auto p: adj[node]) {
	    if (!visited[p.first]) {
	      unexplored.push({p.first, min(dist,p.second)});
	      visited[p.first] = true;
	      distance[p.first] = min(dist,p.second);
	    }
	  }
	  unexplored.pop();
	}
	
	while(q--) {
	  int dest; cin>>dest;
	  cout << distance[dest] << "\n";
	}
}
