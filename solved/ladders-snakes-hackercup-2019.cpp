#define debug 
#include <set>
#include <map>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <complex>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;


#define sc1(a) scanf("%d", &(a))
#define sc2(a,b) scanf("%d%d", &(a),&(b))
#define sc3(a,b,c) scanf("%d%d%d", &(a),&(b),&(c))
#define pri(a) printf("%d\n",(a))

#define endl '\n'
#define dif !=
#define x first
#define y second
#define pb push_back
#define sz(x) (int)(x).size()
#define fauto(k,c) for(auto &k : c)
#define all(k) (k).begin(),(k).end()
#define rall(k) (k).rbegin(),(k).rend()
#define db(k) cerr << #k<< " = " << k << endl
#define popcount(a) __builtin_popcountll((long long)a)
#define pqueue priority_queue
#define uset unordered_set
#define umap unordered_map
#define ld long double
#define ll long long
// #define int ll


//====================================================
ll inf = 0x3f3f3f3f;//atualizar com fluxo maximo possivel em caso de runtime error
const int ms = 50+10+100; // Quantidade maxima de vertices
const int me = ms*2+ms*ms+100; // Quantidade maxima de arestas

int to[me], ant[me], z;
int adj[ms], copy_adj[ms], fila[ms], level[ms];
ll wt[me];

void add(int u, int v, ll k,ll rev =0) {//adiciona aresta e aresta residual (2 arestas)
	//chamar add(a,b,cap) se direcionado
	//chamar add(a,b,cap,cap) se nao direcionado
	to[z] = v;
	ant[z] = adj[u];
	wt[z] = k;
	adj[u] = z++;
	swap(u, v);
	to[z] = v;
	ant[z] = adj[u];
	wt[z] = rev;
	adj[u] = z++;
}

int bfs(int source, int sink) {
	memset(level, -1, sizeof level);
	level[source] = 0;
	int front = 0, size = 0, v;
	fila[size++] = source;
	while(front < size) {
		v = fila[front++];
		for(int i = adj[v]; i != -1; i = ant[i]) {//percorre adjacencia de v (existem arestas v->to[i])
			if(wt[i] && level[to[i]] == -1) {
				level[to[i]] = level[v] + 1;
				fila[size++] = to[i];
			}
		}
	}
	return level[sink] != -1;
}

ll dfs(int v, int sink, ll flow) {
	if(v == sink) return flow;
	ll f;
	for(int &i = copy_adj[v]; i != -1; i = ant[i]) {
		if(wt[i] && level[to[i]] == level[v] + 1 and
		(f = dfs(to[i], sink, min(flow, wt[i])))) {
			wt[i] -= f;
			wt[i ^ 1] += f;
			return f;
		}
	}
	return 0;
}

ll maxflow(int source, int sink) {
	ll ret = 0, flow;
	while(bfs(source, sink)) {
		memcpy(copy_adj, adj, sizeof adj);
		while((flow = dfs(source, sink, inf))) {
			ret += flow;
		}
	}
	return ret;
}

void clear() { // Lembrar de chamar no main
	memset(adj, -1, sizeof adj);
	z = 0;
}
//====================================================
vector<pair<int,pair<int,int>>> ladd;
int t,n,h, S=ms-1,T=ms-2;

bool pass(int p, int i, int j){
	for(int k=i+1;k<j;k++){//k = {i+1,...,j-1}
		// cout<<"CHECKING COLLISION OF "<<p<<" IN "<<ladd[k].y.x<<"--"<<ladd[k].y.y<<endl;
		if(p<ladd[k].y.y and p>ladd[k].y.x) return 0;//colidiu com alguem
	}
	return 1;//passa direto da escada i pra a j
}

int propagate(int i,int j){//pega intersecao final entre i e j
	auto a = ladd[i].y, b = ladd[j].y;
	int beg = max(a.x,b.x);
	int end = min(a.y,b.y);
	
	int cap = 0;
	while(beg<end){//se beg >= end nao faz nada
		cap+= (pass(beg,i,j) and pass(beg+1,i,j));//checa se o intervalo beg,beg+1 passa de i pra j
		beg++;
	}
	return cap;
}

main(){
 	ios::sync_with_stdio(0); cin.tie(0);
	bool alwayspossible;
	cin>>t;
	for(int caso = 1;caso<=t;caso++){
		clear();
		cin>>n>>h;
		ladd.clear();
		alwayspossible=0;
		for(int i=0;i<n;i++){
			int x,y1,y2;
			cin>>x>>y1>>y2;
			ladd.pb({x,{y1,y2}});
			if(y1==0 and y2==h)alwayspossible=1;
		}

		sort(all(ladd));	
		// fauto(t,ladd){
		// 	cout<<t.x<<' '<<t.y.x<<' '<<t.y.y<<endl;
		// }

		//construir grafo
		for(int i=0;i<n;i++){
			if(ladd[i].y.x==0){ add(S,i,inf);}
			if(ladd[i].y.y==h){ add(i,T,inf);} 
		}
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				int cap =propagate(i,j);
			//	cout<<i<<" <-> "<<j<<" == "<<cap<<endl;
				add(i,j,cap,cap);
			
			}

		}

		cout<<"Case #"<<caso<<": "<<(alwayspossible? -1 : maxflow(S,T))<<endl;


	}
	

}
