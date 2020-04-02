const int N = 100010, M = 1000010;

int h[N], e[M], ne[M], idx, n;
int color[N];

void add(int x, int y) {
	e[++idx] = y, ne[idx] = h[x], h[x] = idx;
}

bool dfs(int x, int c) {
	color[x] = c;
	for (int i = h[x]; i; i = ne[i]) {
		int y = e[i];
		if (!color[y]) {
			if (!dfs(y, 3 - c)) return 0;
		} else if (color[y] == c) return 0;
	} 
	return 1;
}

bool bipartite() {
	for (int i = 1; i <= n; i++) 
		if (!color[i]) if (!dfs(i, 1)) return 0;
	return 1;
}

add(x, y); // 连接点x至点y的一条有向边
bipartite(); // 若此图为二分图则返回1，否则返回0 
