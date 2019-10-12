
#define mp make_pair
vector<int> droot(int k,int a,int n){//find x where x^k==a mod n
	if(a==0){
		//0 is the only solution
		vector<int> ans={0};
		return ans;
	}

	int g = generator(n);

	//baby-step giant-step discrete log algorithm
	int sq = (int)sqrt(n+.0)+1;
	vector<pair<int,int>> dec(sq);
	for(int i=1;i<=sq;i++)
		dec[i-1] = {fexp(g, i*sq*k%(n-1), n), i};
	sort(dec.begin(), dec.end());
	int any_ans=-1;
	for(int i=0;i<sq;i++){
		int my = fexp(g,i*k%(n-1),n)*a%n;
		auto it = lower_bound(dec.begin(),dec.end(), mp(my, 0));
		if(it != dec.end() and it->first == my){
			any_ans = it->second*sq -i;
			break;
		}
	}	
	if(any_ans == -1){
		vector<int> ans;//no solutions
		return ans;
	}

	int delta = (n-1)/__gcd(k,n-1);
	vector<int>ans;
	for(int cur=any_ans%delta; cur< n-1;cur+=delta)
		ans.push_back(fexp(g,cur,n));
	sort(ans.begin(),ans.end());
	return ans;
}
