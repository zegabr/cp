
bool check(int m){
	//check here
	
}

//smallest solution
int bsmin(int l, int r){
	while(l<r){
		int m = l + (r-l)/2;
		if(check(m)) r=m;
		else l=m+1;
	}
	return l;
}
