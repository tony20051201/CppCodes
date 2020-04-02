const int N = 1005;

int adj[N][N], d[N];
bool st[N];

int dijkstra(int s) {
	memset(d, 0x3f, sizeof d);
	d[s] = 0;
	for (int i = 1; i < n; i++) {
		int t = -1;
		for (int j = 1; j <= n; j++)
			if (!st[j] && (t == -1 || d[t] > d[j]))
				t = j;
		st[j] = 1;
		for (int j = 1; j <= n; j++)
			d[j] = min(d[j], d[t] + adj[t][j]); 
	}
	return d[n];
}

adj[i][j] = v; // 连接点i到点j的一条有向边，边权为v
dijkstra(s); // 求点s到其余个点的单源最短路径，若值等于0x3f3f3f3f则没有有效路径 
