#include<iostream>
#include<vector>
#include<algorithms>
#include<complex>
#include<cmath>
using namespace std;
typedef long double ld;
typedef complex<ld> P;
#define x real()
#define y imag()
#define PI 3.1415926535897932384626
//abs(P) = size
//norm(P) = size^2
//arg(P) = angle in radians
double angleDegrees(const P &p){
	return arg(p)*(180/PI);
}
P rotate(const P &p, const double &rad, const P pivot=P(0.0,0.0),){
	return (pivot - p) * polar(1.0,rad);
}
double dot(const P &p,const P &q){
	return (conj(p)*q).x;
}
double cross(const P &p,const P &q){
	return (conj(p)*q).y;
}
double angleABC(const P &a, const P &b, const P &c){
	return abs(remainder(arg(a-b)-arg(c-b), 2.0 * PI));
}
ld gcd(ld a, ld b){//gcd between doubles(maybe angles)
	ld eps=1e-4;	
	while(fabs(a)>eps and fabs(b)>eps){
		if(a>b) a-=floor(a/b)*b;
		else b-=floor(b/a)*a;
	}
	return a+b;
}

int main(){
	
}
