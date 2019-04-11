//=============FAST IO===================
#include<iostream>
ios::sync_with_stdio(0);
cin.tie(0);
//===========SETPRECISION=========================
#include <iomanip>
int main(){
	cout<<fixed<<setprecision(48);
}
//=================GETLINE================
char str[20];
str[0]=cin.get();//get 1 char
cin.getline(str, 20);//get at most 20 chars 
string str;
cin>>str; // get next word and return true. return false if there is no input 
getline (cin, str);//get full line and return true r return false if there is no line
cin.ignore(150, '\n');//jump blank lines
///how to get non empty lines
int main()
{
	string str;
	int t = 4;
	while (t--)
	{
		getline(cin, str);

		while (str.size()==0 )
			// Keep reading a new line while there is a blank line
			getline(cin, str);

		cout << str << " : newline" << endl;
	}
	return 0;
}

//=============STRINGSTREAM================
#include <sstream>
string line;
getline(cin,line);//pega linha
stringstream ss; ss.str(line);
while(ss>>word){
	//pega uma palavra de line e coloca em word

} 

//==============PERMUTATIONS==============
#include <numeric>
vector<int> v(n);
iota(v.begin(),v.end(),0);
do{
	get(v);//processa permutacao
}while(next_permutation(v.begin(),v.end()));

//================BITWISE OPERATIONS================
1<<n //2^n
mask | (1<<n)// seta iesimo bit
(mask>>i)&1// testa se o iesimo bit ta setado
(1<<n)-1 // seta os n bits menos significativos
mask ^ (1<<i) //troca o iesimo bit
num&1 //num é ímpar?
~num&1 //num é par?

//===================RANDOM=======================
//---safe hash-map----https://codeforces.com/blog/entry/62393
#include<chrono>
#include<random>
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
unordered_map<long long, int, custom_hash> safe_map;

//----safe random---https://codeforces.com/blog/entry/61675
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
cout<<rng()<<endl; //printa numero randomico


//==================BITSET=========================
bitset<10> a(10);//bitset de tamanho 10 com o valor 10 atribuido
bitset<10> a("0111100000");//funciona com zeros a esquerda
a = bitset<10>(val);//tbm funciona
a.count();//retorna quantidade de bits 1

a.test(i);//retorna 1 se o i-ésimo bit está setado
a.any();//true se algum bit está setado
a.none();// true se nenhum bit setado
a.all;//true se todos os bits setados

a.set(k,i);//seta k bits partindo do i-
a.set(i);//seta i-esimo
a.set();//seta todos os bits
a.reset();//funciona igual ao set
a.flip();//mesmos parametros, porém troca bits



//===============NUMTheory=========================
raízes primitivas:
	ord(a,m) = menor inteiro positivo tal que a^k==1modm
	ord(a,m)|phi(m) //ordem de a mod m divide phi(m)
	se ord(a,m)==phi(m) , a é raíz primitiva
	gcd(a,m) tem q ser 1 para a possuir ordem modulo m
	se k=ord(a,m), ord(a^t,m)=k/gcd(k,t);//logo se a for raíz primitiva, vc consegue ordem de qualquer potencia dele, logo de qualquer nmero q possui ordem
	um número tem raíz primitiva se for da forma 2,4,p^k ou 2p^k com k inteiro positivo e p PRIMO ÍMPAR
