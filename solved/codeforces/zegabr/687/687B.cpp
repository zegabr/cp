#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pl '\n'
#define sp ' '
const int N = 1e6+10;

vector<bool> prime(N, 1);
vector<int> primes,lcmfac(N), kfac(N);

inline void getfac(int n, vector<int> &fac){
	for(int i=0;primes[i]*primes[i]<=n;i++){
		int c=0;
		while(n%primes[i]==0){
			n/=primes[i];
			c++;//pega potencias dos fatores primos
		}
		fac[primes[i]] = max(fac[primes[i]], c);
	}
	if(n!=1){
		fac[n] = fac[n] ? fac[n]: 1;
	}
}

int main(){
	//sieve
	primes.push_back(2);
	for (ll p=3; p<N;p+=2){
		if(prime[p]){
			primes.emplace_back(p);
			for(ll i=p*p; i<=N; i+=p)
				prime[i]=0; 
		}
	}   
	
	vector<bool>used (N,0);
	int n,k,v;
	scanf("%d %d",&n,&k);
	while(n--){
		scanf("%d",&v);
		if(v==k){
			cout<<"Yes\n";
			return 0;
		}
		used[v]=1;
	}
	getfac(k,kfac);
	for(int c=2;c<N;c++) if(used[c]) getfac(c,lcmfac);
	
	for(int c=2;c<N;c++) {
		if(kfac[c]>lcmfac[c]){
			printf("No\n");
			return 0;
		}
	}
	
	
	printf("Yes\n");
	
	
	
	
	
	
}