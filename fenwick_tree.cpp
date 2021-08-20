template <class X>
class fenwick_tree {
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
	void add(int i, X val) {
		for(; i<=size; i += (i&-i)) {
			fenwick[i] += val;
		}
	}
	void updateTo(int i, X val) {
		X old = sum(i)-sum(i-1);
		val -= old;
		update(i, val);
	}
	
	/*
		-> eg: fenwick_tree <int> bit;
		-> used to find online prefix sum in O(log(n)) time
		-> use O(n) space
		-> indexing is 1-based
		-> sum(i) will return prefix sum till i
		-> rangeSum(l, r) will return sum(arr[l..r])
		-> add(i, x) will add x to arr[i] i.e. arr[i] += x
		-> updateTo(i, x) will update arr[i] to x i.e. arr[i] = x
	*/
};