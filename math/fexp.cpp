
/**
 * a ^ 6 = a ^ 110 == a ^ (0*2⁰+1*2¹+1*2²)
 * == a⁰ * a² * a⁴ == a⁰ * a² * (a²)²
 * So, we keep squaring the base a, 
 * and multiply it by the answer every time we encounter a 1 bit in the power binary's representation
 * 
 * */
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
