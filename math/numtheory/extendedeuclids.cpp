
#define gcd __gcd
//=========EUCLIDES ESTENDIDO==============
// acha x e y da equacao:
// a * x + b * y = gcd(a, b);
// x eh inverso modular de a no modulo y
// y eh inverso modular de b no modulo x
//ll x,y,d;
void euclides(ll a, ll b, ll &x, ll &y, ll &d) {
	if(b==0){x=1; y=0; d=a; return;}
	euclides(b,a%b,x,y,d);
	int x1=y;
	int y1=x-(a/b)*y;
	x=x1; y=y1;

}

void makePositive(ll &x,ll &y,ll a, ll b){
	if(x<0){
		ll g = gcd(a,b);
		ll n = (ll)ceil((double)-x*g/b);
		x = x+n*b/g;
		y = y-n*a/g;
	}else if(y<0){
		ll g = gcd(a,b);
		ll n = (ll)ceil((double)-y*g/a);
		x = x-n*b/g;
		y = y+n*a/g;
	}
}
//ax+by=k
void positiveSolution(ll a, ll b, ll k, ll &x, ll &y, ll &d){
	euclides(a,b,x,y,d);
	ll g=gcd(a,b);
	x=k*x/g;
	y=k*y/g;
	makePositive(x,y,a,b);
}
