
long long fexp(long long a, long long b) {//O(logb)
	long long ans = 1;
	while(b) {
		if(b & 1) ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}

long long fexp(long long a, long long b, long long mod) {//O(logb)
	long long ans = 1;
	while(b) {
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

long long invmod(long long a, long long mod){//mod has to be prime
	return fexp(a,mod-2,mod);
}
