//====================================================
string p, t;
vector<int> b(p.size()+1); 

void kmpdebug(string &p, vector<int>&b){//for debugging
	cout<<"    ";
	for(int i=0;i<p.size();i++)cout<<p[i]<<"  ";
	cout<<endl;
	for(int i=0;i<b.size();i++)cout<<b[i]<<"  ";
	cout<<endl;
}

vector<int> kmppre(string &p) {
	int m=p.size();
	vector<int> b(m+1);
	int i = 0, j = b[0] = -1;
	while(i < m) {
		while(j >= 0 and p[i] != p[j]) j = b[j];
		b[++i] = ++j;
	}
}

int kmpfind() {
	int i = 0, j = 0, ans = 0;
	while(i < n) {
		while(j >= 0 and t[i] != p[j]) j = b[j];
		i++; j++;
		if(j == m) {
			//ocorrencia aqui comecando em i - j
			ans++;
			j = b[j];
		}
	}
	return ans;
}
//====================================================
