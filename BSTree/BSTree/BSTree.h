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
	bool Delete(const T& data){
		if (_pRoot == nullptr){
			return false;
		}

		//按照二叉搜索树的规则找待删除节点的位置
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur){
			if (data == pCur->_data){
				break;
			}
			else if (data < pCur->_data){
				pParent = pCur;
				pCur = pCur->_pleft;
			}
			else{
				pParent = pCur;
				pCur = pCur->_pright;
			}
		}
		if (pCur == nullptr){
			return false;
		}
		/*
		1.叶子节点：直接删除
		2.左子树为空：直接删除
		3.右子树为空：直接删除
		4.左右孩子都在：找一个替代节点
		*/

		if (pCur->_pleft == nullptr){
			if (pCur == _pRoot)
				_pRoot = pCur->_pright;

			else{
				if (pCur == pParent->_pleft)
					pParent->_pleft = pCur->_pright;

				else
					pParent->_pright = pCur->_pright;
			}
		}

		else if (pCur->_pright == nullptr){
			if (pCur == _pRoot)
				_pRoot = pCur->_pleft;
			else{
				if (pCur == pParent->_pleft)
					pParent->_pleft = pCur->_pleft;

				else
					pParent->_pright = pCur->_pleft;
			}

		}

		else{
			//左右孩子都在
			//在右子树找替代节点（最小）
			Node* ptmp = pCur->_pright;
			pParent = pCur;
			while (ptmp->_pleft){
				pParent = ptmp;
				ptmp = ptmp->_pleft;
			}
			pCur->_data = ptmp->_data;
			if (ptmp == pParent->_pleft)
				pParent->_pleft = ptmp->_pleft;
			else
				pParent->_pright = ptmp->_pright;

			pCur = ptmp;
		}
		delete pCur;
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
		cout << endl;
	}

private:
	void _InOrder(Node* _pRoot){
		if(_pRoot){
			_InOrder(_pRoot->_pleft);
			cout << _pRoot->_data;
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

