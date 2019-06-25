//CONVEX HULL TRICK
struct line{
	ll m,c;
};

deque<line> hull;

inline ld inter(line &t1,line &t2){
	return (ld)(t2.c - t1.c)/(t1.m - t2.m);
}

void add(ll m, ll c){

	line novo,L1,L2;
	novo.m=m;
	novo.c=c;
	ld p1,p2;
	bool ok = true;

	while(hull.size() > 1 and ok){
		L1 = hull.back();
		hull.pop_back();
		L2 = hull.back();

		p1 = inter(L1,L2);
		p2 = inter(L1,novo);

		if(p2 < p1){
			hull.push_back(L1);
			ok = false;
		}
	}
	hull.push_back(novo);
}

ll get(ll &x){
	if(hull.size() == 0) return 0;

	int l = 0;
	int r = hull.size() - 1;
	int m = (l+r)/2;
	ld p;

	while(l < r){
		p = inter(hull[m],hull[m+1]);
		if(p < x){
			r = m;
			m = (l+r)/2;
		}
		else{
			l = m+1;
			m = (l+r)/2;
		}
	}
	return (hull[m].m * x) + hull[m].c;
}
