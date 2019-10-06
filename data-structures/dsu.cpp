
const int ms = 233333;
int ds[ms],sz[ms];
void makeset(int v=ms){
	for(int i=0;i<v;i++){ ds[i]=i; sz[i]=1;}
}

int find(int i){//find
	if(ds[i]!=i) ds[i]=find(ds[i]);
	return i;
}

bool uni(int a, int b){//union
	a=find(a), b=find(b);
	if(a==b) return false;
	if(sz[a]<sz[b])swap(a,b);
	sz[a]+=sz[b];
	ds[b]=a;
	return true;
}
