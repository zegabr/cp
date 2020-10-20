
#define TAM 3 // base size
long long mod = 1e9+9;
long long base[TAM] = {0,1,2};//base cases
long long Tbase[TAM][TAM] = {//transformation
	{0,1,0},
	{0,0,1},
	{1,1,1}
};

struct Matrix { 
	long long mat[TAM][TAM];
	Matrix operator * (const Matrix &p) {
		Matrix ans;
		for(int i = 0; i < TAM; i++)
			for(int j = 0; j < TAM; j++)
				for(int k = ans.mat[i][j] = 0; k < TAM; k++)
					ans.mat[i][j] = (ans.mat[i][j] + mat[i][k] * p.mat[k][j]) % mod;
		return ans;
	}
};

Matrix fexp(Matrix a, long long b) {
	b-=TAM-1;//subtracts some value that gives right answer(generally is TAM-1 so it returns base cases if is less than TAM)
	Matrix ans;//identity matrix
	for(int i = 0; i < TAM; i++) 
		for(int j = 0; j < TAM; j++)
			ans.mat[i][j] = (i == j);
	while(b) {
		if(b & 1) ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}

Matrix T;
long long solve(long long n){
	n--;//depends on indexing
	if(n < TAM) return base[n];//base case

	memcpy(T.mat, Tbase, sizeof T.mat);//T = Tbase
	T = fexp(T, n);//T = T^n

	long long ans = 0;
	for(int i=0;i<TAM;i++)
		ans=(ans+ T.mat[TAM-1][i] * base[i] % mod  )%mod;

	return ans;
}
