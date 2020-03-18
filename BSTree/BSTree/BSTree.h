#pragma once
#include<iostream>
using namespace std;

template<class T>
struct BSTNode{
	BSTNode(const T& data=T()) 
	:_pleft(nullptr), _pright(nullptr), _data(data)
	{}

	BSTNode<T>* _pleft;
	BSTNode<T>* _pright;
	T _data;
};

template<class T>

class BSTree{
	typedef BSTNode<T> Node;
public:
	BSTree():_pRoot(nullptr){
	
	}
	~BSTree(){
		_Destory(_pRoot);
	}

	Node* Find(const T& data){
		Node* pCur = _pRoot;
		while (pCur){
			if (data == pCur->_data){
				return  pCur;
			}
			else if (data > pCur->_data){
				pCur = pCur->_pright;
			}
			else{
				pCur = pCur->_pleft;
			}
		}
		return nullptr;
	 }

	bool Insert(const T& data){
		if (_pRoot == nullptr){
			_pRoot = new Node(data);
			return true;
		}
		Node* pCur = _pRoot;
		Node* pParent=nullptr;
		while (pCur){
			pParent = pCur;
			if (data < pCur->_data){
				pCur = pCur->_pleft;
			}
			else if (data > pCur->_data){
				pCur = pCur->_pright;
			}
			else return false;
		}
		pCur = new Node(data);
		if (data < pParent->_data){
			pParent->_pleft = pCur;
		}
		else{
			pParent->_pright = pCur;
		}
		return true;
	}

	Node* LeftMost(){
		if (_pRoot == nullptr){
			return nullptr;
		}
		Node* pCur = _pRoot;
		while (pCur->_pleft){
			pCur = pCur->_pleft;
		}
		return pCur;
	}

	Node* RightMost(){
		if (_pRoot == nullptr){
			return nullptr;
		}
		Node* pCur = _pRoot;
		while (pCur->_pright){
			pCur = pCur->_pright;
		}
		return pCur;
	}

	void InOrder(){
		_InOrder(_pRoot);
	}

private:
	void _InOrder(Node* _pRoot){
		if(_pRoot){
			_InOrder(_pRoot->_pleft);
			cout << _pRoot->_data << endl;
			_InOrder(_pRoot->_pright);
		}
	}

	void _Destory(Node*& pRoot){
		if (pRoot){
			_Destory(pRoot->_pleft);
			_Destory(pRoot->_pright);
			delete pRoot;
			pRoot = nullptr;
		}
	}
private:
		Node* _pRoot;
};

