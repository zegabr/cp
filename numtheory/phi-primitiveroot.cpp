//================EULER FUNCTION ===============
vector<ll> phi(N);
void PHI(){//get prime factors and calculate phi
	for(ll i=1;i<N;i++)phi[i]=i;
	for(ll i=2;i<N;i++){//O(N)
		if(phi[i]==i){//n is prime
			for(ll j=i;j<N;j+=i){//O(logi)
				//i is a prime factor of j
				phi[j]=phi[j]/i*(i-1);
			}
		}
	}
}
ll PHI(ll n){//OTHER EULER FUNCTION///////
	ll ans = n;
	for(ll i=2;i*i<=n;i++){
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
//===========PRIMITIVE ROOT=================//requires fexp e PHI()
int generator (int p) {//find a primitive root modulo p
	//talvez seja interessante fazer uma condicional aqui pra saber se o p tem raíz primitiva
	vector<int> fact;
	int tot = PHI(p),  n = tot;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			fact.push_back (i);//fatores de phi
			while (n % i == 0)
				n /= i;
		}
	if (n > 1)
		fact.push_back (n);


	for (int res=2; res<=p; ++res) {
		bool ok = true;
		for (int i=0; i<fact.size() && ok; ++i)
			ok &= fexp (res, tot / fact[i], p) != 1;
		if (ok)  return res;//primitive root
	}
	return -1;//there is none
}
//=================raízes primitivas=======================
// 	ord(a,m) = menor inteiro positivo tal que a^k==1modm
// ord(a,m)|phi(m) //ordem de a mod m divide phi(m)
// 	se ord(a,m)==phi(m) , a é raíz primitiva
// 	gcd(a,m) tem q ser 1 para a possuir ordem modulo m
// 	se k=ord(a,m), ord(a^t,m)=k/gcd(k,t);//logo se a for raíz primitiva, vc consegue ordem de qualquer potencia dele, logo de qualquer nmero q possui ordem
// 	um número tem raíz primitiva se for da forma 2,4,p^k ou 2p^k com k inteiro positivo e p PRIMO ÍMPAR
