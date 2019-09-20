bool check(int m){
	//check here
	
}

//smallest solution
int bsmin(int l, int r){
	while(l<r){
		int m = (l+r)/2;
		if(check(m)) r=m;
		else l=m+1;
	}
	return l;
}

//biggest solution
int bsmax(int l, int r){
	while(l<r){
		int m = (l+r+1)/2;
		if(check(m)) l=m;
		else r=m-1;
	}
	return r;
}