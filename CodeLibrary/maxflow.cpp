const long long inf = 1000000000000000000;

class edge {
	public:
	int nxt, to;
	long long f;

	edge() = default;

	edge(int _nxt, int _to, long long _f) : nxt(_nxt), to(_to), f(_f) {}
};

class max_flow {
	vector<int> d;
	vector<int> h;
	vector<int> iter;
	vector<edge> e;

	int cnt, source, sink;

	public:

	max_flow(int n, int m, int _source, int _sink) {
		h.resize(n + 1);
		e.resize(m * 2 + 5);

		cnt = 1;
		source = _source;
		sink = _sink;
	}

    void link(int u, int v, int f) {
        e[++cnt].nxt = h[u];
        h[u] = cnt;
        e[cnt].to = v;
        e[cnt].f = f;
    }

    void add_edge(int u, int v, int f) {
        link(u, v, f);
        link(v, u, 0);
    }

    bool bfs() {
		d.assign(h.size(), -1);
		d[source] = 0;

        queue<int> q;
        q.emplace(source);

        while(!q.empty()) {
            int u = q.front(); 
			q.pop();
            
			for(int i = h[u]; i; i = e[i].nxt) {
				if(d[e[i].to] == -1 && e[i].f) {
                	d[e[i].to] = d[u] + 1;
                	q.emplace(e[i].to);
            	}
			}
        }
        return ~d[sink];
    }

    long long dfs(int u, long long f) {
        if(u == sink) return f;

        long long ret = 0;
        
		for(int &i = iter[u]; i && f; i = e[i].nxt) {
			if(d[e[i].to] == d[u] + 1 && e[i].f) {
            	long long x = dfs(e[i].to, min(f, e[i].f));
           		ret += x;
            	f -= x;
            	e[i].f -= x;
            	e[i ^ 1].f += x;
        	}
		}

        return ret;
    }

    long long dinic() {
        long long ret = 0;
    
		while(bfs()) {
			iter = h;
            ret += dfs(source, inf);
        }

        return ret;
    }
};
