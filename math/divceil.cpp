template<typename T>
T divceil(T a, T b){
    return (a + b - 1)/b;
    /**
     * ceil(a/b) =(a + b - 1) / b
     * proof: if a = bk + 0, then 
     * bk == (a+b-1), then ceil = k.
     * Otherwise, a = bk + r, 0 < r < b,
     * then (a+b-1) = (bk + r + b - 1) == b(k+1) + r.
     * Since 0 < r < b, we have b(k+1) < b(k+1) + r, then ceil((b(k+1)+r)/b) == k+1 as expected (for integer divisions)
}