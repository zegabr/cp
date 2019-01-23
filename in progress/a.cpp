
int main(){
	addedge(0, 1, 16 ); 
	addedge(0, 2, 13 ); 
	addedge(1, 2, 10 ); 
	addedge(1, 3, 12 ); 
	addedge(2, 1, 4 ); 
	addedge(2, 4, 14); 
	addedge(3, 2, 9 ); 
	addedge(3, 5, 20 ); 
	addedge(4, 3, 7 ); 
	addedge(4, 5, 4); 
	cout << "Maximum flow " << maxflow(0, 5);
}
