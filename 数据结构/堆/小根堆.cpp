const int N = 100010;

int heap[N], s = 0;

void down(int u) {
	while ((u << 1) <= s) {
		int v = u << 1;
		if (v < n && heap[v + 1] < heap[v]) v++;
		if (heap[v] >= heap[u]) break;
		swap(heap[u], heap[v]);
		u = v;
	}
}

void up(int u) {
	while (u > 1 && heap[u] < heap[fa(u)]) {
		swap(heap[u], heap[fa(u)]);
		u = fa(u);
	}
}

void pop() {
	heap[1] = heap[s--];
	down(1);
}

int top() {
	return heap[1];
}

void insert(int x) {
	heap[++s] = x;
	up(s);
}

void build() {
	for (int i = (n >> 1); i; i--) down(i);
}

insert(x); // 往堆里插入数x 
top(); // 堆中的最小值
pop(); // 删除堆中最小值
heap[k] = heap[s--]; down(k); up(k); // 删除第k位的元素
heap[k] = x; down(k); up(k); // 修改第k位的元素为x 
build(); // 建堆 
