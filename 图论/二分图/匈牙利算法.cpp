const int N = 510, M = 100010;

int n1, n2, m;
int h[N], ne[M], e[M], idx;
int match[N];
bool st[N];

void add(int x, int y) {
	e[++idx] = y, ne[idx] = h[x], h[x] = idx;
}

int find(int x) {
	for (int i = h[x]; i; i = ne[i]) {
		int y = e[i];
		if (!st[y]) {
			st[y] = 1;
			if (!match[y] || find(match[y])) {
				match[y] = x;
				return 1;
			}
		}
	}
	return 0;
}

int result() {
	int ret = 0;
	for (int i = 1; i <= n1; i++) {
		memset(st, 0, sizeof st);
		if (find(i)) ret++; 
	}
	return ret;
}

add(x, y); // 连接点i到点j的一条有向边
result(); // 返回二分图的最大匹配 
