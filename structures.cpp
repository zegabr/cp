//////////BIT/////////
int bit[maxn];
int sum(int i){
	int res =0;
	while (i){
		res += bit[i];
		i-= i&-i;
	}
	return res;
}
void ad(int i,int val){
	while(i<n){//'n' eh o tamanho utilizado
		bit[i]+=val;
		i+= i&-i;
	}
}

//////////////RECURSIVE SEGMENT TREE /////////
int arr[4 * N], seg[4 * N], n;

void build(int x = 1, int l = 0, int r = n - 1) {
	if(l == r) {
		seg[x] = arr[l];
		return;
	}
	int m = (l+r)>>1,e=x+x, d=e+1;
	build(e, l, m); build(d, m + 1, r);
	seg[x] = seg[e] + seg[d]; // Merge
}

int query(int a, int b, int x = 1, int l = 0, int r = n - 1) {
	if(b < l || a > r) return 0; // Valor que nao atrapalhe
	if(a <= l && r <= b) return seg[x];
	int m = (l+r)>>1, e=x+x, d=e+1; 
	return query(a, b, e, l, m) + query(a, b, d, m + 1, r); // Merge
}

void update(int a, int val, int x = 1, int l = 0, int r = n -1) {
	if(l > a or r < a) return;
	if(l == r) {
		seg[x] = val;
		return;
	}
	int m = (l+r)/2, e = x+x, d = e+1;
	update(a,val, e, l, m); update(a, val, d, m + 1, r);
	seg[x] = seg[e] + seg[d]; // Merge
}
