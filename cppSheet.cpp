C++:
---------------------------------------getline----------------------------
char str[20];
str[0]=cin.get();//get 1 char
cin.getline(str, 20);//get at most 20 chars 
string str;
cin>>str; // get next word
getline (cin, str);//get full line
cin.ignore(150, '\n');//jump blank lines
///how to get non empty lines
int main()
{
    string str;
    int t = 4;
    while (t--)
    {
        getline(cin, str);
        // Keep reading a new line while there is
        // a blank line
        while (str.length()==0 )
            getline(cin, str);
 
        cout << str << " : newline" << endl;
    }
    return 0;
}
---------------------string-----------
string s;
s.find(char k); //return first index of char k in s or string::npos if didnt find
int c = std::cin.peek(); // peek next char without extracting it
bool std::isdigit(c) //== true if c is digit, false if it is char
--------------------algoritms--------
int a[n];
bool next_permutation(a,a+n); //return true if array a was trasnformed to its next lexographicaly permutation
bool prev_permutation(a,a+n) //the same but inverted
bool is_permutation(a,a+n,b)//true if b[0]b[1]...b[n] is a permutation of a[0]a[1]...a[n]
int mycount = std::count (myints, myints+8, 10);//count how many 10's exists in myints array
std::replace (myvector.begin(), myvector.end(), 20, 99);//replace every 20 with a 90
std::reverse(myvector.begin(),myvector.end());//reverse myvector
bool is_sorted (ForwardIterator first, ForwardIterator last)//return true if it is sorted in asceding order
bool std::lexicographical_compare(foo,foo+5,bar,bar+9);//return true if foo<bar
