
#include <iostream>
namespace FastInput{
    inline void sc(int &num){//scan int
        num=0;
        bool neg=0;
        int c = getchar();
        while(c==' ' or c=='\n')c=getchar();
        if(c=='-')neg=1,c=getchar();
        else if(c=='+') c=getchar();
        for(;c<='9' and c>='0';c=getchar())
            num=(num<<1)+(num<<3)+c-'0';
        if(neg)num*=-1;
    }

    inline void sc(long long &num){//scan ll
        num=0ll;
        bool neg=0;
        int c = getchar();
        while(c==' ' or c=='\n')c=getchar();
        if(c=='-')neg=1,c=getchar();
        else if(c=='+') c=getchar();
        for(;c<='9' and c>='0';c=getchar())
            num=(num<<1)+(num<<3)+c-'0';
        if(neg)num*=-1ll;
    }
};
