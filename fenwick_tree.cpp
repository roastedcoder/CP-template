template <class X> class fenwick_tree {
	private:
	int size;
	vector <X> fenwick;
	
	public:
	fenwick_tree(int size) {
		this->size = size;
		fenwick.resize(size+1, 0);
	}
	X sum(int i) {
		X res = 0;
		for(; i>0; i -= (i&-i)) {
			res += fenwick[i];
		}
		return res;
	}
	X rangeSum(int l, int r) {
		return (sum(r)-sum(l-1));
	}
	void update(int i, X val) {
		for(; i<=size; i += (i&-i)) {
			fenwick[i] += val;
		}
	}
	void updateTo(int i, X val) {
		X old = sum(i)-sum(i-1);
		val -= old;
		update(i, val);
	}
};