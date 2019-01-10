---------------------------------------getline----------------------------
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
