//////////////////////////FAST IO/////////////////////////////
#include<iostream>
ios::sync_with_stdio(0);
cin.tie(0);
//////////////////////////GETLINE/////////////////////////////
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

		while (str.length()==0 )
			// Keep reading a new line while there is a blank line
			getline(cin, str);

		cout << str << " : newline" << endl;
	}
	return 0;
}

//////////////STRINGSTREAM//////////
#include <sstream>
string text;
stringstream ss; ss.str(line);
ss>>word; //pega uma palavra de text

///////////////PERMUTATIONS//////////
#include <numeric>
vector<int> v(n);
iota(v.begin(),v.end(),0);
do{
	get(v);
}while(next_permutation(v.begin(),v.end()));

//////////////BITWISE OPERATIONS////////////
1<<n //2^n
mask | (1<<n)// seta iesimo bit
(mask>>i)&1// testa se o iesimo bit ta setado
(1<<n)-1 // seta os n bits menos significativos
mask ^ (1<<i) //troca o iesimo bit
num&1 //num é ímpar?
~num&1 //num é par?

////////////////RANDOM////////////////////////
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

///////////////////////////////////////////////////
#include <iomanip>
int main(){
	cout<<fixed<<setprecision(48);
}
