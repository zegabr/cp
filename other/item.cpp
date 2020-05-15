
//modifiable class
class item {
    public:
        int x;
        int y;

        item(int a, int b){//constructor 
            //instantiate as auto obj = item(12,321) or item obj(12,321) 
            x=a;
            y=b;
        }

        bool operator<(const item &o) const {//use this if is using a heap or set
            return x < o.x || x == o.x && y < o.y;
        }
};

