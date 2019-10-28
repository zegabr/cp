
#define none 0x3f3f3f3f //valor que nao atrapalhe
vector<int> seg;//0 indexed
int SZ;

int merge(int e, int d){
	return min(e,d);
}

void update(int a, int val, int x = 1, int l = 0, int r = SZ - 1) {
	if(l > a or r < a) return;
	if(l == r) {
		seg[x] = val;
		return;
	}
	int m = (l+r)/2, e = x+x, d = e+1;
	update(a,val, e, l, m); update(a, val, d, m + 1, r);
	seg[x] = merge(seg[e] , seg[d]); 
}

int query(int a, int b, int x = 1, int l = 0, int r = SZ - 1) {
	if(b < l || a > r) return none; // Valor que nao atrapalhe
	if(a <= l && r <= b) return seg[x];
	int m = (l+r)>>1, e=x+x, d=e+1; 
	return merge(query(a, b, e, l, m), query(a, b, d, m + 1, r)); 
}

void build(vector<int> &v, int x, int l, int r) {
	if(l == r) {
		seg[x] = v[l];
		return;
	}
	int m = (l+r)>>1,e=x+x, d=e+1;
	build(v, e, l, m); build(v, d, m + 1, r);
	seg[x] = merge(seg[e], seg[d]);
}

void build(vector<int> &v){//chamar build(inputVector) no main
	seg.resize(4*v.size());
	SZ = v.size();
	int x = 1, l = 0, r = SZ - 1;
	build(v, x, l, r);
}