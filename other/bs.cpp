//====================================================
bool check(int m){
	//check here
	return 1;
}
int smallestSolution(int l, int r) {
	while(l < r) {
		int m = (l+r)/2;
		if(check(m)) r = m;
		else l = m + 1;
	}
	return l;
}

int biggestSolution(int l, int r) {
	while(r - l > 1) {
		int m = (l+r)/2;
		if(check(m)) l = m;
		else r = m;
	}
	return check(r) ? r : l;
}

int bs(int l, int r, int k){
	while(l<=r){
		m=(l+r)/2;
		if(arr[m]==k) return m;
		if(arr[m]<k) l=m+1;
		else r=m-1;
	}
}
//====================================================