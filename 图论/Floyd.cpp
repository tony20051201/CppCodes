const int N = 210;

int adj[N][N], n;

void init() {
	memset(adj, 0x3f, sizeof adj);
	for (int i = 1; i <= n; i++)
		adj[i][i] = 0;	
}

void floyd() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

adj[x][y] = min(adj[x][y], z); // 连接点x至点y的一条边权为z的有向边
adj[x][y]; // 在floyd();函数执行后点x至点y的最短路径，若值大于0x3f3f3f3f/2则没有有效路径 
