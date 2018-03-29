C++:
---------------------square and multiply mod n--------------
long sma( long x,  long H,  long n){
        long h;
        unsigned long long r;
        int bin[32];
        int i;
        r = x;
        i = 0;
        /* Converts H in Binary */
        while( H > 0 ){

                if (H % 2 == 0){
                        bin[i] = 0;
                }else{
                        bin[i] = 1;
                }

                H = H/2;
                i++;
        }
        i--; //t-1
        while(i>0){
                r = (r * r) % n;
                if( bin[--i] == 1 ){
                        r = (r * x) % n;
                }    
        }
        return r;
}
-------------------array sorting and printing---------------------
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)      
 
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
--------------------sieve of eratostenes---------------------
void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
 
    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
    // Print all prime numbers
    for (int p=2; p<=n; p++)
       if (prime[p])
          cout << p << " ";
}
----------------------------sort-------------
int a[10]= {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    cout << "\n The array before sorting is : ";
    show(a);
 
    sort(a, a+10);


//binary search for element k
binary_search(a, a + 10, k);
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
-----------------hypotenusa-----------------
Syntax:
double hypot(double x, double y);
float hypot(float x, float y);
long double hypot(long double x, long double y);
//also enables a third parameter (to calculate distance from origin)
----------------iterator for loop-------------------
int array[]= {1, 2, 3, 4, 5};
    for (const auto &value: array)
        cout << value << " ";
returns 1 2 3 4 5
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