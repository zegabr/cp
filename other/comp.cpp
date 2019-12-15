
struct item {
	int x, y;
	bool operator<(const item &o) const {
		return x < o.x || x == o.x && y < o.y;
	}
};

