#include <bits/stdc++.h>
using namespace std;
template <class T>
class Edmonds_Karp {
    T inf = numeric_limits<T> :: max() / 2;
    class edge {
        public:
        int nxt, to;
        T c, f;
    };
    vector<edge> e;
    vector<T> d;
    vector<int> head;
    vector<int> prev;
    vector<int> pree;
    vector<int> vis;
    int cnt;
    int source;
    int sink;

    public:
    Edmonds_Karp() {}
    Edmonds_Karp(int N, int M, int _source, int _sink) : source(_source), sink(_sink), head(N + 1), vis(N + 1), d(N + 1), prev(N + 1), pree(N + 1), e(M * 2 + 3) {
        cnt = 1;
    }

    void link(int u, int v, T f, T c) {
        e[++cnt].nxt = head[u];
        head[u] = cnt;
        e[cnt].f = f;
        e[cnt].to = v;
        e[cnt].c = c;
    }
    void add_edge(int u, int v, T f, T c) {
        link(u, v, f, c);
        link(v, u, 0, -c);
    }  
    bool spfa() {
        d.assign(d.size(), -1);
        d[source] = 0;
        queue<int> q;
        q.push(source);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = 0;
            for(int i = head[u]; i; i = e[i].nxt) { 
                if(e[i].f && (d[e[i].to] > d[u] + e[i].c || d[e[i].to] == -1)) {
                    pree[e[i].to] = i;
                    prev[e[i].to] = u;
                    d[e[i].to] = d[u] + e[i].c;
                    if(vis[e[i].to] == 0) {
                        q.push(e[i].to);
                        vis[e[i].to] = 1;
                    }
                }
            }
        }
        return ~d[sink]; 
    }
    T _Edmonds_Karp() {
        T cost = 0;
        T flow = 0;
        while(spfa()) {
            int now = sink;
            T delta = inf;
            while(now != source) {
                delta = min(delta, (T)e[pree[now]].f);
                now = prev[now];
            }
            now = sink;
            while(now != source) {
                e[pree[now]].f -= delta;
                e[pree[now] ^ 1].f += delta; 
                now = prev[now];
            }
            flow += delta;
            cost += (T)delta * d[sink];
        } 
        return cost;
    }
    void print(vector<string> S) {
      vector<tuple<int, int, string>> Ans;
      int N = S.size();
      for (int i = 0; i < N; ++i) {
        for (int j = head[i]; j; j = e[j].nxt) {
          if (e[j].f == 0) {
            int k = e[j].to - N;
            if (0 <= k && k < N) {
              if (S[i][k] == 'o') {
                for (int P = 0; P < N; ++P) {
                  if (P != k && S[i][P] == 'o') {
                    Ans.emplace_back(i, P, "erase");
                  }
                }
                break;
              } else {
                for (int P = 0; P < N; ++P) {
                  if (S[i][P] == 'o') {
                    Ans.emplace_back(i, P, "erase");
                  }
                }
                Ans.emplace_back(i, k, "write");
              }
            }
          }
        }
      }
      cout << Ans.size() << '\n';
      for (auto [X, Y, O] : Ans) {
        cout << X + 1 << ' ' << Y + 1 << ' ' << O << '\n';
      }
    }
};
int main() {
  int N;
  cin >> N;
  vector<vector<int>> W(N, vector<int> (N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> W[i][j];
    }
  }
  vector<vector<int>> E(N, vector<int> (N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> E[i][j];
    }
  }
  vector<string> S(N);
  for (int i = 0; i < N; ++i) {
    cin >> S[i];
  }
  int source = N + N;
  int sink = N + N + 1;
  Edmonds_Karp<int> flow(N + N + 2, N * N * 5, source, sink);
  for (int i = 0; i < N; ++i) {
    int V = 0;
    for (int j = 0; j < N; ++j) {
      if (S[i][j] == 'o') {
        V += E[i][j]; 
      }
    }
    for (int j = 0; j < N; ++j) {
      if (S[i][j] == 'o') {
        flow.add_edge(i, j + N, 1, V - E[i][j]);
      } else {
        flow.add_edge(i, j + N, 1, V + W[i][j]); 
      } 
    }
  }
  for (int i = 0; i < N; ++i) {
    flow.add_edge(source, i, 1, 0);
  }
  for (int i = 0; i < N; ++i) {
    flow.add_edge(i + N, sink, 1, 0);
  }
  cout << flow._Edmonds_Karp() << '\n';
  flow.print(S);
}
