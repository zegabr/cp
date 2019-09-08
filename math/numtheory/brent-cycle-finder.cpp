//======================
int f(int x){

	return x;
}

pair<int,int> brent(int x0){
	int power,lam,tor,hare;
	power=lam=1;
	tor = x0;
	hare=f(x0);
	while(tor!=hare){
		if(power==lam){
			tor=hare;
			power*=2;
			lam=0;
		}
		hare=f(hare);
		lam++;
	}

	tor = hare = x0;
	for(int i=0;i<lam;i++)
		hare = f(hare);

	int mu = 0;
	while(tor != hare){
		tor = f(tor);
		hare = f(hare);
		mu++;
	}

	return {lam, mu};//periodo,indice onde comeca o periodo
}
//==========================================
