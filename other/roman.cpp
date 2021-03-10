string AtoR(int A) {
    vector<pair<int,string>> vals = {
        {1000,  "M"},
        {900,   "CM"},
        {500,   "D"},
        {400,   "CD"},
        {100,   "C"},
        {90,    "XC"},
        {50,    "L"},
        {40,    "XL"},
        {10,    "X"},
        {9,     "IX"},
        {5,     "V"},
        {4,     "IV"},
        {1,     "I"}
    };
    string res = "";
    int pos = 0;
    while(num){
        if(num >= vals[pos].first){
            num -= vals[pos].first; // integer
            res += vals[pos].second; // string
        }else{
            pos++;
        }
    }
    return res;
}

int RtoA(string R) {// TODO: understand this
    map<char, int> RtoA;
    RtoA['I'] = 1;   RtoA['V'] = 5;   RtoA['X'] = 10;   RtoA['L'] = 50;
    RtoA['C'] = 100; RtoA['D'] = 500; RtoA['M'] = 1000;

    int value = 0;
    for (int i = 0; R[i]; i++)
        if (R[i+1] && RtoA[R[i]] < RtoA[R[i+1]]) {     // check next char first
            value += RtoA[R[i+1]] - RtoA[R[i]];       // by definition
            i++;                                      //skip this char
        }
        else value += RtoA[R[i]];
    return value;
}

