
long long sumdiv(long long n){
	long long pri = 0, prf = primes[pri], ans=1;
	while(prf*prf <= n){
		long long power=0;
		while(n%prf==0){n/=prf; power++;}
		ans*=((ll)pow((double)prf, power+1.0) - 1)/(prf-1);
		prf = primes[++pri];
	}
	if(n!=1) ans*=((ll)pow((double)n, 2.0) - 1)/(n-1);
	return ans;
}

long long countdiv(long long n){//O(sqrt(n))
	long long c=0;
	for(long long i=1; i*i<=n; i++){
		if(n%i==0){
			if(n/i==i)c++; //count one divisor
			else c+=2; // count 2 divisors: i and n/i
		}
	}
	return c;
}
