#include<complex>
#include<stack>
#include<vetor>
#define x real()
#define y imag()
typedef complex<double> P;

double cross(P p, P q){
	return (conj(p)*q).y;
}
P orig;
bool comp(const P &a, const P &b){
	//compare by angle between a-orig and b-orig
	return arg(a-orig)<arg(b-orig) or (arg(a-orig)-arg(b-orig)<=1e-5 and abs(a-orig)>abs(b-orig) );
}
vector<P> convexhull(vector<P> &v){
	if(v.size()<3) return v;

	int	ind = 0;
	for(int i=1;i<v.size();i++){//get bottommost
		if(v[i].x<v[ind].x or (v[i].x==v[ind].x and v[i].y<v[ind].y))
			ind=i;
	}
	orig=v[ind];
	swap(v[0],v[ind]);
	sort(v.begin()+1,v.end(),comp);//counterclockwise
    stack<P> h;
	P middle, prev;
	h.push(v[0]); h.push(v[1]);
	for(int i=2; i<v.size(); i++){
			middle=h.top(); h.pop();
			prev=h.top();
		while(h.size()>=2 and cross(middle-prev, v[i]-middle)<=0){//while turn right
			middle=h.top(); h.pop();
			prev=h.top();
		}
		h.push(middle);
		h.push(v[i]);

	}
	vector<P> ans(h.size());
	while(h.size()){
		ans[h.size()-1]=h.top();
		h.pop();
	}
	return ans;
}
