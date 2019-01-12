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
string text;
stringstream ss = stringstream(text);
ss>>word; //pega uma palavra de text

///////////////PERMUTATIONS//////////
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
