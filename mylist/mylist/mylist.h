#include<iostream>
#include<vector>
using namespace std;

template<class T>
struct list_node{

	list_node(const T& val=T())
		:date(x)
		, _next(nullptr)
		, _prev(nullptr)
	{}

	list_node<T>* _next;
	list_node<T>* _prev;
	T data;

};

template<class T>
class list_iterator
{

	typedef list_node<T> node;
	typedef list_iterator<T> self;
public:
	node* _pNode;
	list_iterator(node *pNode = nullptr)
		:_pNode
	{}

	self& operator++(){
	
		_pNode = _pNode->next;	
		return *this;
	}

	self operator++(int){

		self tmp(*this);
		_pNode = _pNode->next;
		return tmp;
	}

	T& operator*(){

		return _pNode->data;
	
	}
	self operator--()
	{
		_pNode = _pNode->prev;
		return temp;
	}

	self operator--(int){

		self tmp(*this);
		_pNode = _pNode->prev;
		return tmp;
	}

	//迭代器具有比较操作
	bool operator!=(const self& it){

		return _pNode != it.pNode;
	
	}
	bool operator==(const self& it){

		return _pNode != it.pNode;

	}

};

template<class T>
class mylist{
	typedef list_node<T> node;
public:
	typedef list_iterator<T> iterator;
	T& front(){
		return _pHead->next->data;
	}
	const T& front()const{
		return _pHead->next->data;
	}
	T& back(){
		return _pHead->prev->data;
	}
	const T& back()const{
		return _pHead->prev->data;
	}
	void creathead(){
		_head = new node(T());
		_head->_next = _head;
		_head->_prev = _head;
	}

	mylist(){
		creathead();
	}

	mylist(int n, const T& val){
		creathead();
		for (int i = 0; i < n; i++){

			push_back(val);

		}
	}

	template<class Iterator >
	mylist(Iterator first, Iterator last){

		creathead();
		while (first != last){
			push_back(*first);
			++first;
		}

	}
	mylist(const mylist<T>& l){

			creathead();
			node* pCur = L._pHead->next;

			while (pCur != L._pHead){
			
				push_back(pCur->data)
					pCur = pCur->next;
			}
		}

	~mylist(){

			delete _head;
			_head = nullptr;

		}


	iterator begin(){

			return iterator _pHead->next;

		}

	iterator end(){

			return iterator _pHead;

		}

	//capacity
	size_t size()const{

		size_t count = 0;
		node* pCur = _phead->next;
		while (pCur != _phead){
			count++;
			pCur = pCur->_next;

		}
		return count;
	}
	
	bool empty()const{

		return _pHead->next == _pHead;

	}

	void resize(size_t newsize, const T& val = T()){
	
		size_t oldsize = size();
		if (newsize > oldsize){
			for (size_t i = oldsize; i < newsize; ++i){
				push_back(val);
			}
		}
		else{
			for (size_t i = oldsize; i > newsize; --i){
				pop_back();

			}
		}

		}
	
	
	

	void push_back(const T& val){
			/*node* tail = _pHead->_prev;
			node* newnode = new node(x);

			newnode->_next = _pHead;
			newnode->_prev = tail;
			_pHead->_prev = newnode;
			tail->_next = newnode;*/

		insert(end(), val);
		}

	void pop_back(){

		erase(--end());

		}

	void push_front(const T& val){
		/*node* tail = _pHead->_next;
		node* newnode = new node(x);

		newnode->_next = tail;
		newnode->_prev = _pHead;
		_pHead->_next = newnode;
		tail->_prev = newnode;*/

		insert(begin(), val);
	}

	void pop_front(){

		erase(begin());

	}

	iterator insert(iterator pos, const T& val){
			node* newnode = new node(val);
			node* pCur = pos._pNode;
			newnode->_prev = _pCur->prev;
			newnode->_next = _pCur;
			_pCur->prev = newnode;
			newnode->_prev->next = newnode;

			return iterator newnode;
	}

	iterator erase(iterator pos){
	
	
		if (pos == end()){
		
			return;
		}
		node* delnode = pos._pNode;
		node* nextnode = delnode->next;
		delnode->prev->next = delnode->next;
		delnode->next->prev = delnode->prev;

		delete delnode;
		return iterator(nextnode);
	
	}

	void clear(){
	
		node* node = _pHead->next;
		while (node != _pHead){
		
			_pHead->next = node->next;
		
			delete node;
			node = _pHead;
		}
		_pHead->next = _pHead;
		_pHead->prev = _pHead;
	}


	void swap(const mylist<T>& l){
	
		swap(_pHead, l._pHead);
	
	}

private:

	node* _pHead;

};



void test1(){
	mylist<int> L1;
	mylist<int> L2(5, 10);

	vector<int> v{ 11, 22, 33, 44, 55, 66, 77, 88, 99 };
	mylist<int> L3(v.begin(), v.end());

	mylist<int> L4(L3);
	


	L1.push_back(1);
	L1.push_back(2);
	L1.push_back(3);
	L1.push_back(4);

	for (auto e : L1){
	
		cout << e << " ";
	
	}
	cout << endl;
}

