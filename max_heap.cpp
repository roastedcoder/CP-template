template <class X>
class max_heap {
private:
	int n = 0;
	vector <X> a;
	
public:
	max_heap() {}
	
	void heapify(int i) {
		int largest = i;
		int left = 2*i + 1;
		int right = 2*i + 2;
		
		if(left < n && a[left] > a[largest]) largest = left;
		if(right < n && a[right] > a[largest]) largest = right;
		
		if(largest != i) {
			swap(a[i], a[largest]);
			heapify(largest);
		}
	}
	
	void buildHeap(vector <X> a) {
		this->a = a;
		this->n = a.size();
		int nonLeaf = ((n-1)-1)/2;
		for(int i = nonLeaf; i>=0; i--)
			heapify(i);
	}
	
	int top() {
		return a[0];
	}
	
	int size() {
		return this->n;
	}
	
	void push(int val) {
		this->a.push_back(val);
		this->n += 1;
		int i = n-1;
		int parent = (i-1)/2;
		while(i != 0 && a[parent] < a[i]) {
			swap(a[parent], a[i]);
			i = parent;
			parent = (parent-1)/2;
		}
	}
	
	void pop() {
		swap(a[0], a[n-1]);
		this->n -= 1;
		heapify(0);
	}
	
	void print() {
		for(int i = 0; i<n; i++) cout<<a[i]<<" ";
		cout<<endl;
	}
};