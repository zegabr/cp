
//=========EUCLIDES ESTENDIDO==============
// acha x e y da equacao:
// a * x + b * y = gcd(a, b) = d;
// x eh inverso modular de a no modulo y (se d == 1)
// y eh inverso modular de b no modulo x (se d == 1)
//ll x,y,d;
void euclides(ll a, ll b, ll &x, ll &y, ll &d) {
	if(b==0){x=1; y=0; d=a; return;}
	euclides(b, a % b, x, y, d);
	int x1 = y;
	int y1 = x - ( a / b ) * y;
	x = x1; y = y1;

}

void makePositive(ll &x,ll &y,ll a, ll b){
	if(x<0){
		ll g = __gcd(a,b);
		ll n = (ll)ceil((double)-x * g / b);
		x = x + n * b / g;
		y = y - n * a / g;
	}else if(y<0){
		ll g = __gcd(a,b);
		ll n = (ll)ceil((double)-y * g / a);
		x = x - n * b / g;
		y = y + n * a / g;
	}
}
//ax+by=k
void positiveSolution(ll a, ll b, ll k, ll &x, ll &y, ll &d){
	euclides(a,b,x,y,d);
	ll g = __gcd(a,b);
	x = k * x / g;
	y = k * y / g;
	makePositive(x,y,a,b);
}
