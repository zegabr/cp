#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;
#define int ll
//===================SIEVE==================
const int P = 2750135;
bitset<P+1> prime;
vector<int> primes;
vector<int> generator(P);
void sieve (int n){
	prime.set();
	prime[0]=prime[1]=0;
	for (int p=2; p<=n;p++) if(prime[p]){
		primes.push_back(p);
		for(int i=p*p; i<=n; i+=p)
			prime[i]=0; 
	}
	for(int i=0;i<primes.size();i++){
		generator[primes[i]]=i+1;
	}

}
//==============IS PRIME===============
bool isPrime(int n){
	if(n<prime.size()) return prime[n];
	for(int i=0;i<primes.size();i++) if(n%primes[i]==0) return 0;
	return 1;
}
//=============DIVISORES================
int bigdiv(int n){//O(sqrt(n))
	int c=0;
	for(int i=2; i*i<=n; i++){
		if(n%i==0){
			return n/i; 
		}
	}
	return 1;
}
vector<int> ans;
vector<int> freq(P,0);
vector<int>aux;
main(){
	ios::sync_with_stdio(0); cin.tie(0);
	sieve(P);
	
	int n,v;	
	cin>>n;
	
	int t = n*2;
	while(t--){
		cin>>v;
		freq[v]++;
		aux.push_back(v);
	}
	sort(aux.rbegin(),aux.rend());
	for(int v : aux){
		// cout<<v<<pl;
		if(ans.size()==n) break;
		if(freq[v]==0)continue;
		
		if(isPrime(v)){

		if(freq[generator[v]]){
			ans.push_back(generator[v]);
			freq[v]--;
			freq[generator[v]]--;

		}
		}else{
			int d = bigdiv(v);
		
		if(freq[v]==0)continue;
		if(freq[d]){

		ans.push_back(v);
		freq[v]--;
		freq[d]--;
		}
		}
	}

	
	for(auto &p : ans) cout<<p<<sp;
	cout<<pl;
	
}
