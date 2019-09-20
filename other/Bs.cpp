bool check(int x){

}

int ssol(int l, int r){
	while(l<r){
		int m = (l+r)/2;
		if(check(m)) r=m;//ans is in [l,m]
		else l=m+1;//ans is in [m+1, r]
	}
	return l;
}


int bsol(int l, int r){
	while(l<r){
		int m = (l+r)/2;
		if(check(m)) l=m;//ans is in [m,r]
		else r=m-1;//ans is in [l,m-1]
	}
	return r;
}

