/////////KRUSKAL///////

//int ds[N];
//vector <iii> edges;
//iii ed;

void makeset(){
	for(int i=0;i<v;i++) ds[i]=i;
}
int find(int i){//find
	if(ds[i]==i) return i;
	return ds[i]=find(ds[i]);
}
bool uni(int a, int b){//union
	if(find(a)==find(b)) 
		return false;
	ds[find(b)]=find(a); 
	return true;
}
int main(){
	//salva arestas em edges
	sort(edges.begin(),edges.end());
	makeset();
	for(auto ed : edges){
		a=ed.second.first; b=ed.second.second;
		if(uni(a,b)){
			mst+=ed.first;//aqui uma aresta foi adicionada na mst
		}
	}
	cout<<mst<<endl;
	return 0;
}