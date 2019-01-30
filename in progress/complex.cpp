#include<iostream>
#include<vector>
#include<algorithms>
#include<complex>
using namespace std;
typedef long long ll;
typedef complex<ll> P;
#define X real()
#define Y imag()



#include<cmath>
#include<complex>
typedef complex<double>P;
#define x real()
#define y imag()
#define PI 3.1415926535897932384626
//abs(P) = size
//norm(P) = size^2
//arg(P) = angle in radians
double angleDegrees(P p){
	return arg(p)*(180/PI);
}
P rotation(P p, double radians){
	return p*polar(1.0,radians);
}
double dotProduct(P p, P q){
	return (conj(p)*q).x;
}
double crossProduct(P p, P q){
	return abs((conj(p)*q).y);
}
P lineintersection(P a,P b,P c,P d){
	b=b-a; d=c-d; c=c-a;
	return a+b*crossProduct(c,d)/crossProduct(b,d);
}
P circlecenter(P a, P b,P c){
	b=(a+b)/2.0;
	c=(a+c)/2.0;
	return lineintersection(b,b+rotation(a-b,3*PI/2),c,c+rotation(a-c,3*PI/2));
}
ld gcd(ld a, ld b){//gcd between doubles
	ld eps=1e-4;	
	while(fabs(a) > eps and fabs(b)>eps){
		if(a>b) a-=floor(a/b)*b;
		else b-=floor(b/a)*a;
	}
	return a+b;
}
int main(){
	
}
