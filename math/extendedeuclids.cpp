
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

void makePositive(ll &x,ll &y, ll d, ll a, ll b){
	//recode this
}
//ax+by=k
int positiveSolution(ll a, ll b, ll k, ll &x, ll &y, ll &d){
	euclides(a,b,x,y,d);
	ll g = __gcd(a,b);
	if(k%g!=0) return 0; // no solution at all
	x = k / g * x;
	y = k / g * y;
	if(makePositive(x,y,d,a,b)) return 2;//positive solution exists
	return 1;//integer solution exists
}
