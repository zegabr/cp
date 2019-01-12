int ds[maxn];
void makeset(){
	for(int i=0;i<v;i++) ds[i]=i;
}
int find(int i){//find
	if(ds[i]==i)
		return i;
	return ds[i]=find(ds[i]);
}
bool uni(int a, int b){//union
	
	if(find(a)==find(b)) 
        return false;

    ds[find(b)]=find(a); 
    return true;
	
}