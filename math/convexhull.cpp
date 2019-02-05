//CONVEX HULL WITH COMPLEX
#include<complex>
#include<vetor>
#define x real()
#define y imag()
#define PI 3.1415926535897932384626

typedef long double ld;
typedef complex<ld> P;
const ld eps=1e-16;

ld cross(const P &p,const P &q){//use long long if possible
	return (conj(p)*q).y;
}

P orig;
bool comp(const P &a, const P &b){//works on leftmost
	//compare by angles and distance between a-orig and b-orig
	ld arg1 = arg(a-orig), arg2 = arg(b-orig), abs1 = abs(a-orig), abs2 = abs(b-orig);
	if(fabs(arg1-arg2)<eps){
		if(fabs(arg1-PI/2.0)<eps)return abs1-abs2>eps;
		return abs1-abs2<eps;
	}else return arg1<arg2;
}

void convexhull(vector<P> &v){//O(nlogn)
	if(v.size()<3) return v;
	int	ind = 0;
	for(int i=1;i<v.size();i++){ //get leftmost
		if(v[i].x<v[ind].x or (v[i].x==v[ind].x and v[i].y<v[ind].y)) ind=i;
	}
	orig=v[ind];
	swap(v[0],v[ind]);
	sort(v.begin()+1,v.end(),comp);//counterclockwise
	int s=3;
	for(int i=3; i<v.size(); i++){
		//while turn right or collinear
		while(s>=3 and cross(v[s-1]-v[s-2], v[i]-v[s-1])<=0.0)	s--;
		
		v[s]=v[i];
		s++;
	}
	v.resize(s);//hull here
}
