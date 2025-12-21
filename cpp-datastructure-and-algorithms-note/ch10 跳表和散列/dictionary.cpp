
template<class K, class E>
class Dictionary {

	public:
	virtual ~Dictionary() {}
	virtual int size() const = 0;
	virtual bool isEmpty() const = 0;
	virtual E* find(const K& key) const = 0;
	virtual void insert(const K& key, const E& element) = 0;
	virtual E* remove(const K& key) = 0;
};

