ll sumdiv(ll n){
	ll pri = 0, prf = primes[pri], ans=1;
	while(prf*prf <= n){
		ll power=0;
		while(n%prf==0){n/=prf; power++;}
		ans*=((ll)pow((double)prf, power+1.0) - 1)/(prf-1);
		prf = primes[++pri];
	}
	if(n!=1) ans*=((ll)pow((double)n, 2.0) - 1)/(n-1);
	return ans;
}

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
