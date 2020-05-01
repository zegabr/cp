
bool check(int m){
	//check here
	
}

//biggest solution
int bsmax(int l, int r){
	while(l<r){
		ll m = l+r+1 >> 1;
		if(check(m)) l=m;
		else r=m-1;
	}
	return r;
}
