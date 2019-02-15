/////////////Z-ALGORITHM////
//z[i] is the length of the biggest prefix of s, beggining from position i
//z[0] is by definition s.size(), however never used, so leaving zero there is the best option
//to search for a pattern p in a text t, run zfunc(p+'¨'+t), so p will be prefix
vector<int> zfunc(const string &s){//O(n)
	int n = s.size();
	vector<int> z(n);
	for(int i=1, l=0, r=0; i<n; i++){
		if(i<=r) z[i] = min(r - i + 1, z[i - l]);
		while(i + z[i] < n and s[z[i]] == s[i+z[i]]) z[i]++;
		if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}
	return z;//z-array
}
