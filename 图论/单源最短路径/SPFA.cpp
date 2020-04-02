const int N = 100010, M = 1000010;

int h[N], w[M], e[M], ne[M], idx, n, m;
int d[N];
bool st[N];

void add(int x, int y, int z) {
	e[++idx] = y, w[idx] = z, ne[idx] = h[x], h[x] = idx;
}

int spfa() {
	queue<int> q;
	q.push(1);
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		st[x] = 0;
		for (int i = h[x]; i; i = ne[i]) {
			int y = e[i], z = w[i];
			if (d[y] > d[x] + z) {
				d[y] = d[x] + z;
				if (!st[y]) {
					q.push(y);
					st[y] = 1;
				}
			}
		}
	}
	return d[n];
}

add(x, y, z); // 连接点x到点y的一条有向边，边权为z
spfa(s); // 从点1到点n的单源最短路径，若值等于0x3f3f3f3f则没有有效路径 
