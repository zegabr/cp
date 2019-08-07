//====================================================
const int ms=100;
string p="SEVENTY SEVEN", t;
int b[ms]; 

void kmpdebug(){//for debugging
	cout<<"    ";
	for(int i=0;i<p.size();i++)cout<<p[i]<<"  ";
	cout<<endl;
	for(int i=0;i<p.size()+1;i++)cout<<b[i]<<"  ";
	cout<<endl;
}

void kmppre() {
	int m=p.size();
	int i = 0, j = b[0] = -1;
	while(i < m) {
		while(j >= 0 and p[i] != p[j]) j = b[j];
		b[++i] = ++j;
	}
}

int kmpfind() {
	int i = 0, j = 0, ans = 0;
	while(i < t.size()) {
		while(j >= 0 and t[i] != p[j]) j = b[j];
		i++; j++;
		if(j == p.size()) {
			//ocorrencia aqui comecando em i - j
			ans++;
			j = b[j];
		}
	}
	return ans;
}
//====================================================

