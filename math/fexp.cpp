
ll fexp(ll a, ll b) {//O(logb)
	ll ans = 1;
	while(b) {
		if(b & 1) ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}

ll fexp(ll a, ll b, ll mod) {//O(logb)
	ll ans = 1;
	while(b) {
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

ll invmod(ll a, ll mod){//mod has to be prime
	return fexp(a,mod-2,mod);
}
