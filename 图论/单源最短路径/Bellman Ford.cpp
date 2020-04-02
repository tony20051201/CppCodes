const int N = 10010;

int d[N], n, m, x[N], y[N], w[N];

int bellman_ford() {
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= m; j++) 
			d[y[j]] = min(d[y[j]], d[x[j]] + w[j]);
	return d[n];
}

x[i] = a, y[i] = b, w[i] = z; // 连接点a到点b的一条有向边，边权为z 
bellman_ford(); // 求点1到点n的单源最短路径，若值大于0x3f3f3f3f/2则两点之间没有有效路径 
