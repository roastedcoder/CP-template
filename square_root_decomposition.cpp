template <class X>
class sqrt_dec {
	private:
	int arrSize;
	int chunkSize;
	int sqroot;
	vector <X> arr;
	vector <X> chunk;
	
	public:
	sqrt_dec(vector <X> a) {
		arr = a;
		arrSize = a.size();
		sqroot = sqrt(arrSize);
		chunkSize = (arrSize+sqroot-1)/sqroot;
		chunk.resize(chunkSize, 0);
	}
	
	void preProcessRmQ() {
		X pre = ULTRA;
		int j = 0;
		for(int i = 0; i<arrSize; i++) {
			pre = min(pre, arr[i]);
			if(i%sqroot == sqroot-1) {
				chunk[j++] = pre;
				pre = ULTRA;
			}
		}
		chunk[j] = pre;
	}
	
	void preProcessRMQ() {
		X pre = -ULTRA;
		int j = 0;
		for(int i = 0; i<arrSize; i++) {
			pre = max(pre, arr[i]);
			if(i%sqroot == sqroot-1) {
				chunk[j++] = pre;
				pre = -ULTRA;
			}
		}
		chunk[j] = pre;
	}
	
	void preProcessSum() {
		X pre = 0;
		int j = 0;
		for(int i = 0; i<arrSize; i++) {
			pre += arr[i];
			if(i%sqroot == sqroot-1) {
				chunk[j++] = pre;
				pre = 0;
			}
		}
		chunk[j] = pre;
	}
	
	int getMin(int l, int r) {
		int left = l/sqroot;
		int right = r/sqroot;
		if(left == right) {
			X res = ULTRA;
			for(int i = l; i<=r; i++) res = min(res, arr[i]);
			return res;
		}
		X res = ULTRA;
		for(int i = l; i<sqroot*(left+1); i++) res = min(res, arr[i]);
		for(int i = left+1; i<right; i++) res = min(res, chunk[i]);
		for(int i = sqroot*right; i<=r; i++) res = min(res, arr[i]);
		return res;
	}
	
	int getMax(int l, int r) {
		int left = l/sqroot;
		int right = r/sqroot;
		if(left == right) {
			X res = -ULTRA;
			for(int i = l; i<=r; i++) res = max(res, arr[i]);
			return res;
		}
		X res = -ULTRA;
		for(int i = l; i<sqroot*(left+1); i++) res = max(res, arr[i]);
		for(int i = left+1; i<right; i++) res = max(res, chunk[i]);
		for(int i = sqroot*right; i<=r; i++) res = max(res, arr[i]);
		return res;
	}
	
	int getSum(int l, int r) {
		int left = l/sqroot;
		int right = r/sqroot;
		if(left == right) {
			X res = 0;
			for(int i = l; i<=r; i++) res += arr[i];
			return res;
		}
		X res = 0;
		for(int i = l; i<sqroot*(left+1); i++) res += arr[i];
		for(int i = left+1; i<right; i++) res += chunk[i];
		for(int i = sqroot*right; i<=r; i++) res += arr[i];
		return res;
	}
	
	/*
		-> can solve static RmQ, RMQ, Range Sum
		-> not suitable for string, char and non-primitive dt
		-> pass the initial array as constructor argument
		-> for range minimum query, use preProcessRmQ and getMin
		-> for range maximum query, use preProcessRMQ and getMax
		-> for range sum, use preProcessSum and getSum
	*/
};