//https://sites.google.com/site/indy256/algo_cpp/segment_tree
const int ms = 200000;

const int INIT_VALUE = 0;
const int NEUTRAL_VALUE = INT_MIN;
const int NEUTRAL_DELTA = 0;
//specific code
int merge(int ll, int rr) {
  return max(ll, rr);
}

int deltamerge(int old, int newDelta) {
  return old + newDelta;
}

int incdelta(int val, int delta, int length) {
  return val + delta;
}

// generic code
int n;
int seg[4 * ms];
int delta[4 * ms]; // affects only child roots

void init(int p=0, int l=0, int r=n-1) {
  if (l == r) {
    seg[p] = INIT_VALUE;
    delta[p] = NEUTRAL_DELTA;
  } else {
    init(2 * p + 1, l, (l + r) / 2);
    init(2 * p + 2, (l + r) / 2 + 1, r);
    seg[p] = merge(seg[2 * p + 1], seg[2 * p + 2]);
    delta[p] = NEUTRAL_DELTA;
  }
}

void pushDelta(int p, int l, int r) {
  delta[2 * p + 1] = deltamerge(delta[2 * p + 1], delta[p]);
  delta[2 * p + 2] = deltamerge(delta[2 * p + 2], delta[p]);
  int m = (l + r) / 2;
  seg[2 * p + 1] = incdelta(seg[2 * p + 1], delta[p], m - l + 1);
  seg[2 * p + 2] = incdelta(seg[2 * p + 2], delta[p], r - m);
  delta[p] = NEUTRAL_DELTA;
}

int query(int a, int b, int p=0, int l=0, int r=n-1) {
  if (a > r || b < l)
    return NEUTRAL_VALUE;
  if (a <= l && r <= b)
    return seg[p];
  pushDelta(p, l, r);
  return merge(query(a, b, p * 2 + 1, l, (l + r) / 2),
    query(a, b, p * 2 + 2, (l + r) / 2 + 1, r));
}

void modify(int a, int b, int delta, int p=0, int l=0, int r=n-1) {
  if (a > r || b < l)
    return;
  if (a <= l && r <= b) {
    delta[p] = deltamerge(delta[p], delta);
    seg[p] = incdelta(seg[p], delta, r - l + 1);
    return;
  }
  pushDelta(p, l, r);
  modify(a, b, delta, 2 * p + 1, l, (l + r) / 2);
  modify(a, b, delta, 2 * p + 2, (l + r) / 2 + 1, r);
  seg[p] = merge(seg[2 * p + 1], seg[2 * p + 2]);
}
