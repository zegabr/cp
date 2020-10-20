
const int P = 2e7+5;
vector<long long> phi(P+1);
void PHI(){//get prime factors and calculate phi
	for(long long i=1;i<P;i++)phi[i]=i;
	for(long long i=2;i<P;i++){//O(N)
		if(phi[i]==i){//n is prime
			for(long long j=i;j<P;j+=i){//O(logi)
				//i is a prime factor of j
				phi[j]=phi[j]/i*(i-1);
			}
		}
	}
}

long long PHI(long long n){//calculates one phi
    long long ans = n;
	for(long long i=2;i*i<=n;i++){
		if(n%i==0){
			ans-=ans/i;
			while(n%i==0)n/=i;
		}
	}
	if(n>1){//n is prime
		ans-=ans/n;
	}	
	return ans;
}
