const int N = 510, M = 10010;

int d[N], f[N], n, m, k;
int x[M], y[M], w[M];

int bellman_ford() {
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	
	for (int i = 0; i < k; i++) {
		memcpy(b, d, sizeof d);
		for (int j = 1; j <= m; j++) 
			d[y[j]] = min(d[y[j]], b[x[j]] + w[j]);
	}
	
	return d[n];
} 

x[i] = a, y[i] = b, w[i] = z; // 连接点i至点j边权为z的有向边
bellman_ford(); // 求点1至点n最多经过k条边的最短路，若值大于0x3f3f3f3f/2则没有有效路径
 
