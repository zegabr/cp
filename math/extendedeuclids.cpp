
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

/////positive solution
bool makePositive(ll &x,ll &y, ll d, ll a, ll b){
	if(x<0){
		//x+ t*b/d >= 0 ==> t >= -x*d/b
		ll t = ceil((double)-x*d/(double)b);
		x += b/d * t;
		y -= a/d * t;
	}

	if(y<0){
		//y+ t*a/d >= 0 ==> t >= -x*d/a
		ll t = ceil((double)-y*d/(double)a);
		x -= b/d * t;
		y += a/d * t;
	}

	return x>=0 and y>=0;
}

//ax+by=k
int solve(ll a, ll b, ll k, ll &x, ll &y, ll &d){
	euclides(a,b,x,y,d);
	if(k%d!=0) return 0; // no solution at all
	x = k / d * x;
	y = k / d * y;
	if(makePositive(x,y,d,a,b)) return 2;//positive solution exists (comment this if any solution is good)
	return 1;//integer solution exists
}


