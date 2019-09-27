#include <cstring>
const int ms = 111111;
string T;
int ra[ms], tra[ms];
int sa[ms], tsa[ms];
int c[ms];
void countingSort(int k){
	int n = T.size();
	int i, sum, maxi = max(300, n);
	memset(c, 0 , sizeof c);
	for(i=0;i<n;i++)
		c[i+k < n ? ra[i+k] : 0]++;
	for(i=sum=0; i < maxi; i++){
		int t = c[i];
		c[i]=sum;
		sum+=t;
	}
	for(i=0;i<n;i++)
		tsa[c[sa[i]+k < n ? ra[sa[i]+k] : 0]++] = sa[i];
	for(i=0; i< n; i++)
		sa[i] = tsa[i];
}

void buildSA(){
	int i, k, r;
	T+='$';
	int n = T.size();
	for(i=0;i<n;i++) ra[i]=T[i];
	for(i=0;i<n;i++) sa[i]=i;
	for(k=1;k<n;k<<=1){
		countingSort(k);
		countingSort(0);
		tra[sa[0]] = r = 0;
		for(i=1;i<n;i++)
			tra[sa[i]]=(ra[sa[i]]==ra[sa[i-1]] and ra[sa[i]+k]==ra[sa[i-1]+k]) ? r : ++r;
		for(i=0;i<n;i++)
			ra[i]=tra[i];
		if(ra[sa[n-1]]==n-1) break;
	}
/*	
	for(int i=0;i<n;i++)
		cout << sa[i] << "  " << T.substr(sa[i]) << endl;
*/
}

