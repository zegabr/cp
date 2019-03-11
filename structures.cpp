//============BIT============
//const int N = 21212414;
//int bit[N],n;
int sum(int i){//O(logn)
	int res =0;
	while (i){
		res += bit[i];
		i-= i&-i;
	}
	return res;
}

void ad(int i,int val){//O(logn)
	while(i<n){
		bit[i]+=val;
		i+= i&-i;
	}
}

//============DISJOINT SET UNION==============
//int ds[N],rank[N];
void makeset(){
	for(int i=0;i<v;i++){ ds[i]=i; rank[i]=0;}
}

int find(int i){//find
	if(ds[i]==i) return i;
	return ds[i]=find(ds[i]);
}

bool uni(int a, int b){//union
	if(find(a)==find(b)) 
		return false;
	int x=find(a), y=find(b);
	if(rank[x]>rank[y]) ds[y]=x;
	else{
		ds[x]=y;
		rank[y] += rank[x]==rank[y];
	} 
	return true;
}

//============RECURSIVE SEGMENT TREE==================
//int arr[4 * N], seg[4 * N], n;
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
