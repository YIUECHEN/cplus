#pragma once
#include<iostream>
using namespace std;
template<class T>
struct AVLNode{

	AVLNode(const T& data=T()) :
		_pLeft(nullptr),_pRight(nullptr),_pParent(nullptr),_data(data),_bf(0){
	
	}	
	AVLNode<T>* _pLeft;
	AVLNode<T>* _pRight;
	AVLNode<T>* _pParent;

	T _data;
	int _bf;//平衡因子
};

template<class T>
class AVLTree{
	typedef AVLNode<T> Node;
public:
	AVLTree():_pRoot(nullptr){}
	~AVLTree(){}

	bool Insert(const T& data){
		if (_pRoot == nullptr){
			_pRoot = new Node(data);
			return true;
		}
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur){
			pParent = pCur;
			if (data > pCur->_data){
				pCur = pCur->_pRight;
			} 
			else if (data < pCur->_data){
				pCur = pCur->_pLeft;
			}
			else{
				return false;
			}
		}

		//插入新节点
		pCur = new Node(data);
		if (data < pParent->_data){
			pParent->_pLeft = pCur;
		}
		else{
			pParent->_pRight = pCur;
		}
		pCur->_pParent = pParent;

		//更新平衡因子
		while (pParent){
			if (pCur == pParent->_pLeft)
				pParent->_bf--;
			else
				pParent->_bf++;
		
			if (pParent->_bf == 0)
				break;

			else if (pParent->_bf == 1 || pParent->_bf == -1){
				pCur = pParent;
				pParent = pCur->_pParent;
			}
			else{
		        //pParent->_bf=2||-2 节点失去平衡
				if (pParent->_bf == 2){
					if (pCur->_bf == 1)
						RotateL(pParent);
					else
						RotateRL(pParent);
				}
				else{
					if (pCur->_bf == -1)
						RotateR(pParent);

					else
						RotateLR(pParent);
				}

			}
		}
		return true;
	}

	void InOrder(){
		_InOrder(_pRoot);
		cout << endl;
	}

	bool IsAVLTREE(){
		return _IsAVLTree(_pRoot);
	}
private:
	void RotateR(Node* pParent){
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;

		//改变pParent和pSubL孩子的指向
		pParent->_pLeft = pSubLR;
		if (pSubLR)
     		pSubLR->_pParent = pParent;

		pSubL->_pRight = pParent;

		//改变pParent和pSubL的双亲
		Node* pPParent = pParent->_pParent;
		pParent->_pParent = pSubL;
		pSubL->_pParent = pPParent;

		if (pPParent == nullptr){
			_pRoot = pSubL;
		}
		else{
			if (pParent == pPParent->_pLeft)
				pPParent->_pLeft = pSubL;
			else
				pPParent->_pRight = pSubL;
		}
		pParent->_bf = pSubL->_bf = 0;
	}

	void RotateL(Node* pParent){
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;

		pParent->_pRight = pSubRL;
		if (pSubRL)
			pSubRL->_pParent = pParent;

		pSubR->_pLeft = pParent;
		Node* pPParent = pParent->_pParent;
		pParent->_pParent = pSubR;
		pSubR->_pParent = pPParent;
		
		if (pPParent == nullptr){
			_pRoot = pSubR;
		}
		else{
			if (pParent == pPParent->_pLeft)
				pPParent->_pLeft = pSubR;
			else
				pPParent->_pRight = pSubR;
		}

		pParent->_bf = pSubR->_bf = 0;
	}

	void RotateRL(Node* pParent){
		RotateR(pParent->_pRight);
		RotateL(pParent);
	}

	void RotateLR(Node* pParent){
		RotateL(pParent->_pLeft);
		RotateR(pParent);
	}

	void _InOrder(Node* pRoot){
		if (pRoot){
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data<<" ";
			_InOrder(pRoot->_pRight);
		}
	}
	size_t _Height(Node* pRoot){
		if (pRoot==nullptr){
			return 0;
		}
		size_t leftHeight = _Height(pRoot->_pLeft);
		size_t rightHeight = _Height(pRoot->_pRight);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	bool _IsAVLTree(Node* pRoot){
		if (_pRoot == nullptr){
			return true;
		}
		size_t leftHeight = _Height(pRoot->_pLeft);
		size_t rightHeight = _Height(pRoot->_pRight);

		int bf = rightHeight - leftHeight;
		if (abs(bf) > 1 || bf != pRoot->_bf){
			return false;
		}
		return _IsAVLTree(pRoot->_pLeft) && _IsAVLTree(pRoot->_pRight);
	}
private:
	Node* _pRoot;
};