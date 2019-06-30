//============DISJOINT SET UNION==============
int ds[N],sz[N];
void makeset(int v=N){
	for(int i=0;i<v;i++){ ds[i]=i; sz[i]=1;}
}

int find(int i){//find
	if(ds[i]==i) return i;
	return ds[i]=find(ds[i]);
}

bool uni(int a, int b){//union
	int x=find(a), y=find(b);
	if(x==y) return false;
	ds[x]=y;
	sz[y]+=sz[x];
	return true;
}
