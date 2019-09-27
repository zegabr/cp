#include <cstring>
const int ms = 111111;
char T[ms];
char P[ms];
int ra[ms], tra[ms];
int sa[ms], tsa[ms];
int c[ms];

void countingSort(int k){
	int n = (int)strlen(T);
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
	int n = (int)strlen(T);
	T[n++]='$';
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
	
	for(int i=0;i<n;i++) printf("%2d\t%s\n",sa[i], T+sa[i]);
		cout << sa[i] << "  " << T+sa[i] << endl;

}

pair<int,int> stringMatching(char P[]){
	int n = (int)strlen(T);//because when it is called, $ is at end of T
	int m = (int)strlen(P);
	int lo=0, hi=n-1, mid = lo;
	while(lo < hi){
		mid = (lo+hi)/2;
		int res = strncmp(T+sa[mid],P,m);
		if(res>=0)hi=mid;
		else lo = mid+1;
	}
	if(strncmp(T+sa[lo], P, m)!=0) return ii(-1,-1);//fail
	ii ans; ans.first = lo;
	lo = 0; hi = n-1; mid = lo;
	while(lo < hi){
		mid = (lo+hi)/2;
		int res = strncmp(T+sa[mid],P,m);
		if(res>0)hi=mid;
		else lo = mid+1;
	}
	if(strncmp(T+sa[lo], P, m)!=0) hi--;
	ans.second = hi;
	return ans;
}

void stringCopy(char t[], string &s){
	for(int i=0;i<s.size();i++)
		t[i]=s[i];
}
