#include<map>
#include <string>
#include<tuple>
#include<vector>
namespace Roman{

    inline std::string AtoR(int A) {
        std::vector<std::pair<int,std::string>> vals = {
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
        std::string res = "";
        int pos = 0;
        while(A){
            if(A >= vals[pos].first){
                A -= vals[pos].first; // integer
                res += vals[pos].second; // string
            }else{
                pos++;
            }
        }
        return res;
    }

    inline int RtoA(std::string R) {// TODO: understand this
        std::map<char, int> RtoA;
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
};
