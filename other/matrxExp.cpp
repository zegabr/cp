//matrix fast exponentiation for recurrence problems
//this one is for uva tribonacci
#include <bits/stdc++.h>
using namespace std;
char pl = '\n',sp=' ';
typedef long long ll;
#define tam 3

ll mod= 1e9+9;; 
ll n,i,j,val,k,t;

struct Matrix { 
	ll mat[tam][tam];
	Matrix operator * (const Matrix &p) {
		Matrix ans;
		for(int i = 0; i < tam; i++)
			for(int j = 0; j < tam; j++)
				for(int k = ans.mat[i][j] = 0; k < tam; k++)
					ans.mat[i][j] = (ans.mat[i][j] + mat[i][k] * p.mat[k][j]) % mod;
		return ans;
	}
};

Matrix fExp(Matrix a, ll b) {
	b-=tam-1;//retirar de b uma qntidade q sirva pra questao (geralmente é tam-1 e depende da indexacao)
	Matrix ans;//identidade	
	for(int i = 0; i < tam; i++) for(int j = 0; j < tam; j++)
		ans.mat[i][j] = (i == j);
	while(b) {
		if(b & 1) ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll ans;
	ll base[tam] = {0,
		1,
		2};


	ll Tbase[tam][tam]={ {0, 1, 0},
		{0, 0, 1},
		{1, 1, 1}};
	ll n, val,k;
	while(cin>>n and n){
		n--;// pois n>=1 na questao
		if(n<3){
			cout<<n<<pl;
			continue;
		}
		Matrix T;//T=Tbase
		for(int i=0;i<tam;i++)for(int j=0;j<tam;j++)T.mat[i][j]=Tbase[i][j];

		//T=T^n
		T=fExp(T, n);

		ans=0;
		for(i=0;i<3;i++)
			ans=(ans+ (T.mat[tam-1][i]*base[i])%mod)%mod;
		cout<<ans<<pl;
	}
}
