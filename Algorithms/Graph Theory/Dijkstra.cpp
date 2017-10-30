#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = (1 << 30);

vector < vector < pair <int,int> > > g;
vector <int> dist;

void dijkstra(int b) {
	
	priority_queue < pair <int,int> > q;
	pair <int,int> s, v;
	q.push(make_pair(0, b));
	dist[b] = 0;
	
	while(!q.empty()) {
		
		s = q.top();
		q.pop();
		
		for(int i = 0; i < (int)g[s.second].size(); ++i) {
			v = g[s.second][i];
			
			if((v.first * -1) + (s.first * -1) < dist[v.second]) {
				dist[v.second] = (v.first * -1) + abs(s.first * -1);
				q.push(make_pair(dist[v.second] * -1, v.second));
			}
		}
	}
}

int main() {
	
	int v, e, s, f, w;
		
	cin >> v >> e;
	g.assign(v + 5, vector < pair <int,int> >());
	dist.assign(v + 5, inf);
	
	for(int i = 0; i < e; ++i) {
		cin >> s >> f >> w;
		g[s].push_back(make_pair(-w, f));
		// g[f].push_back(make_pair(-w, s)); // Uncomment for bidirectional Graphs
	}
	
	cin >> s >> f; // First and Last Node
	dijkstra(s);
	if(dist[f] == inf)
		cout << "NO\n"; //You cant go from 's' to 'f'
	else
		cout << dist[f] << '\n'; //Else, Distance
	
	return 0;
}
