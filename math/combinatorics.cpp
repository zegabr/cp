//====================================================
const int ms=10000;
ll c[ms][ms];

ll comb(int n,int k){//combinacao de n, escolhendo k
	if(k==0 or k==n) return 1;
	if(c[n][k]) return c[n][k];
	return c[n][k] = comb(n-1,k-1)+comb(n-1,k);
}

void pascaltriangle(int n){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			cout<<comb(i,j)<<' ';
		}
		cout<<endl;
	}
}

ll catalan(ll n){
	return comb(2*n, n)/(n+1); 
}

ll catalan(ll n, ll mod){ //import numtheory.cpp
	return comb(2*n, n)*invmod(n+1,mod);
}


//========CATALAN NUMBERS=========
/*
	 -numero de Dyck words de tamanho 2n (strings com n X's e n Y's tal que nenhum prefixo tem mais X's do que Y's)
	 -fazendo X==>'(' e Y==>')', catalan(n) é o numero de expressoes de parenteses válidas (com n pares de parenteses)
	 -numero de maneiras de aplicar n operacoes binarias em n+1 fatores utilizando associatividade (numero de maneiras de parentizar n+1 fatores)
	 -numero de arvores binarias com n+1 folhas
	 -numero de caminhos monotonicos numa grid nxn
	 -numero de maneiras de triangular polígono convexo de n+2 lados
	 -numero de permutacoes de {1,2,...,n} tal que nao haja sequencias de 3 elementos consecutivos
	 -numero de non crossing partitions do conjunto {1,...,n}
	 - Hankel Matric eh uma matriz nxn tal que a posicao i,j contem o valor catalan(i+j-2). Essa matriz sempre terá determinante igual a 1.
	 -trocando catalan(i+j-2) por catalan(i+j-1) o determinante continua sendo 1
	 */

//====================================================