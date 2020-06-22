//===============file input output=================
main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	fclose(stdin);
	fclose(stdout);
}
//=============FAST IO===================
#include<iostream>
main(){
	ios::sync_with_stdio(0);cin.tie(0);
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
main()
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
string line, word;
char carac;
getline(cin,line);//pega linha
stringstream ss; ss.str(line);//redeclarar pra cada nova query de linha
while(ss>>word){
	//pega uma palavra de line e coloca em word
} 
while(ss>>carac){
	//pega o prox char de ss e guarda em carac
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
	mask |= (1<<i)	// seta iesimo bit
	mask &= ~(1<<i)	// reseta o iesimo bit
	mask ^= (1<<i) 	//troca o iesimo bit
	mask & (1<<i)	// testa se o iesimo bit ta setado
	(1<<n)-1 		// seta os n bits menos significativos
	num&1 			//num é ímpar?
	~num&1 			//num é par?

//==================BITSET=========================
bitset<10> a(10);//bitset de tamanho 10 com o valor 10 atribuido
bitset<10> a("0111100000");//funciona com zeros a esquerda
a = bitset<10>(val);//tbm funciona
a.count();//retorna quantidade de bits 1

a.test(i);//retorna 1 se o i-ésimo bit está setado
a.any();//true se algum bit está setado
a.none();// true se nenhum bit setado
a.all();//true se todos os bits setados

a.set(k,i);//seta k bits partindo do i-esimo
a.set(i);//seta i-esimo
a.set();//seta todos os bits
a.reset();//funciona igual ao set
a.flip();//mesmos parametros, porém troca bits
