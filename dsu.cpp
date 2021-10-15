template <class X>
class dsu {
    private:
    int n;
    vector <int> parent;
    vector <int> size;

    public:
    dsu(int n) {
        this->n = n;
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i<n; i++) parent[i] = i;
    }

    int Find(int a) { // path compression
        if(parent[a] == a) return a;
        return Find(parent[a]);
    }

    void Union(int a, int b) { // union by size
        a = Find(a);
        b = Find(b);
        if(a != b) {
            if(size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
    /*
	->  pass the size as constructor argument
        ->  uses: dsu <int> objectName(n);
        ->  if we combine path-compression with union by size,
            we get an amortized time complexity of O(alpha(n))
    */
};