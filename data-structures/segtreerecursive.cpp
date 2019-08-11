///=====================================================
int a[4 * ms], seg[4 * ms], n;
const int none = 0x3f3f3f3f;//padrao retornado pela query tal que nao interfira

inline int merge(int e, int d){
	return min(e,d);
}

void update(int a, int val, int x = 1, int l = 0, int r = n -1) {
	if(l > a or r < a) return;
	if(l == r) {
		seg[x] = val;
		return;
	}
	int m = (l+r)/2, e = x+x, d = e+1;
	update(a,val, e, l, m); update(a, val, d, m + 1, r);
	seg[x] = merge(seg[e] , seg[d]); 
}

int query(int a, int b, int x = 1, int l = 0, int r = n - 1) {
	if(b < l || a > r) return none; // Valor que nao atrapalhe
	if(a <= l && r <= b) return seg[x];
	int m = (l+r)>>1, e=x+x, d=e+1; 
	return merge(query(a, b, e, l, m), query(a, b, d, m + 1, r)); 
}

void build(int x = 1, int l = 0, int r = n - 1) {
	if(l == r) {
		seg[x] = a[l];
		return;
	}
	int m = (l+r)>>1,e=x+x, d=e+1;
	build(e, l, m); build(d, m + 1, r);
	seg[x] = merge(seg[e], seg[d]);
}
//====================================================
