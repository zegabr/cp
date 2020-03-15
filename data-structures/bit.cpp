
template<typename T>
class BIT{
  private:
    vector<T> bit;

  public:
    BIT(vector<T> &v){
      bit.assign(v.size()+2,0);
      for(int i=0;i<v.size();i++)
        upd(i,v[i]);
    }
    BIT(int tam){
      bit.assign(tam+2,0);
    }

    T get(int i){
      i++	;
      T res = 0;
      while (i){
        res += bit[i];
        i-= i&-i;
      }
      return res;
    }

    T get(int i, int j){
      return get(j+1) - get(i);
    }

    void upd(int i,T val){
      i++;
      while(i<bit.size()-1){
        bit[i]+=val;
        i+= i&-i;
      }
    }
};

