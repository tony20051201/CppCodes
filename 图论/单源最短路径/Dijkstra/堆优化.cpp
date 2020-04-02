#define PII pair<int, int>

const int N = 100010, M = 1000010;

int h[N], e[M], ne[M], w[M], idx, n, m;
int d[N];
bool st[N];

void add(int x, int y, int z) {
	e[++idx] = y, w[idx] = z, ne[idx] = h[x], h[x] = idx;
}

int dijkstra() {
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push({0, 1});
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	while (!q.empty()) {
		int x = q.top().second; q.pop();
		st[x] = 1;
		for (int i = h[x]; i; i = ne[i]) {
			int y = e[i], z = w[i];
			if (d[y] > d[x] + z) {
				d[y] = d[x] + z;
				q.push({d[y], y});
			}
		}
	}
	return d[n];
}

add(x, y, z); // 连接点x到点y的一条有向边，边权为z
dijkstra(); // 从点1到点n的单源最短路径，若值等于0x3f3f3f3f则没有有效路径 
 
 
