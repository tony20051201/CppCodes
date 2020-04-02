const int N = 100010, M = 1000010;

int h[N], w[M], e[M], ne[M], idx, n, m;
int d[N], cnt[N];
bool st[N];

void add(int x, int y, int z) {
	e[++idx] = y, w[idx] = z, ne[idx] = h[x], h[x] = idx;
}

bool spfa(int s) {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
		st[i] = 1;
	}
	while (!q.empty()) {
		int x = q.front(); q.pop();
		st[x] = 0;
		for (int i = h[x]; i; i = ne[i]) {
			int y = e[i], z = w[i];
			if (d[y] > d[x] + z) {
				d[y] = d[x] + z;
				cnt[y] = cnt[x] + 1;
				if (cnt[y] >= n) return 1;
				if (!st[y]) {
					q.push(y);
					st[y] = 1;
				}
			}
		}
	}
	return 0;
}

add(x, y, z); // 连接点x到点y的一条有向边，边权为z
spfa(s); // 如果有负环则返回1，没有则返回0 
