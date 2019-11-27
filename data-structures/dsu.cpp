
class dsu{
	vector<int> ds, sz;
	public:	
	dsu(int v){
		sz.assign(v+1, 1);
		ds.resize(v+1);
		for(int i=0;i<=v;i++){ ds[i]=i;}
	}

	int pai(int i){//find
		if(ds[i]!=i) ds[i]=pai(ds[i]);
		return ds[i];
	}

	bool uni(int a, int b){//union
		a=pai(a), b=pai(b);
		if(a==b) return false;
		if(sz[a]<sz[b])swap(a,b);
		sz[a]+=sz[b];
		ds[b]=a;
		return true;
	}

	int size(int a){
		return sz[pai(a)];
	}
};

