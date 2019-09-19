//============MATRIX FAST EXPONENTIATION=========== for recurrence problems
//this one is for uva tribonacci
#define TAM 3

ll mod= 1e9+9;

struct Matrix { 
	ll mat[TAM][TAM];
	Matrix operator * (const Matrix &p) {
		Matrix ans;
		for(int i = 0; i < TAM; i++)
			for(int j = 0; j < TAM; j++)
				for(int k = ans.mat[i][j] = 0; k < TAM; k++)
					ans.mat[i][j] = (ans.mat[i][j] + mat[i][k] * p.mat[k][j]) % mod;
		return ans;
	}
};

Matrix fExp(Matrix a, ll b) {
	b-=TAM-1;//retirar de b uma qntidade q sirva pra questao (geralmente é TAM-1 e depende da indexacao)
	Matrix ans;//identidade	
	for(int i = 0; i < TAM; i++) for(int j = 0; j < TAM; j++)
		ans.mat[i][j] = (i == j);
	while(b) {
		if(b & 1) ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}
//====================================================

/*
main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll ans;
	ll base[TAM] = {0,
		1,
		2};


	ll Tbase[TAM][TAM]={ {0, 1, 0},
		{0, 0, 1},
		{1, 1, 1}};
	ll n, val,k;
	while(cin>>n and n){
		n--;// pois n>=1 na questao
		if(n<3){
			cout<<n<<pl;
			continue;
		}
		Matrix T;
		for(int i=0;i<TAM;i++)for(int j=0;j<TAM;j++)T.mat[i][j]=Tbase[i][j]; //T=Tbase

	
		T=fExp(T, n); 	//T=T^n

		ans=0;
		for(int i=0;i<3;i++)
			ans=(ans+ (T.mat[TAM-1][i]*base[i])%mod)%mod;
		cout<<ans<<pl;
	}
}
 */
