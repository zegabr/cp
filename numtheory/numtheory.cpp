//====================================================
#define mdc(a,b) __gcd(a,b)

//==========MMC(LCM)================
inline ll mmc(const ll &a, const ll &b) {
	return (a / mdc(a, b)) * b; 
}
//=============DIVISORES================
ll countdiv(ll n){//O(sqrt(n))
	ll c=0;
	for(ll i=1; i*i<=n; i++){
		if(n%i==0){
			if(n/i==i)c++; //conta um divisor
			else c+=2; // conta 2 divisores: i  e n/i
		}
	}
	return c;
}

//=========EUCLIDES ESTENDIDmO==============
// acha x e y da equacao:
// a * x + b * y = gcd(a, b);
// x eh inverso modular de a no modulo y
// y eh inverso modular de b no modulo x
//ll x,y,d;
void euclides(ll a, ll b, ll &x, ll &y, ll &d) {
	if(b==0){x=1; y=0; d=a; return;}
	euclides(b,a%b);
	int x1=y;
	int y1=x-(a/b)*y;
	x=x1; y=y1;

}



//===============FAST EXPONENTIATION=================
ll fexp(ll a, ll b, ll mod) {//O(logb)
	ll ans = 1;
	while(b) {
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}
//===========MULTIPLICATIVE INVERSE=================
ll invmod(ll a, ll mod){//mod has to be prime
	return fexp(a,mod-2,mod);
}
//====================================================