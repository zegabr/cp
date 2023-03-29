
namespace bitsetUtils {
inline void setBit(int &num, int pos) { num |= (1 << pos); }
inline void unsetBit(int &num, int pos) { num &= ~(1 << pos); }
inline void toggleBit(int &num, int pos) { num ^= (1 << pos); }
inline bool bitIsSet(int &num, int pos) { return num & (1 << pos); }
inline void setNlessSignificativeBits(int &num, int n) { num |= (1 << n) - 1; }
inline bool is_even(int num) { return num & 1; }
inline bool is_odd(int num) { return ~num & 1; }
} // namespace bitset
