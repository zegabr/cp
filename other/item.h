
class item {
    public:
        int x;
        int y;

        item(int a, int b) : x(a), y(b) {}

        bool operator<(const item &other) const {
            return x < other.x || x == other.x && y < other.y;
        }
};
