#pragma once
#include<iostream>
using namespace std;

#if 0
enum Color{ RED, BLACK };

template<class T>
struct RBTreeNode{
	RBTreeNode(const T& data=T(), Color color= RED) :
	_pLeft(nullptr),
	_pRight(nullptr),
	_pParent(nullptr),
	_color(color),
	_data(data)
	{}

	RBTreeNode<T>* _pLeft;
	RBTreeNode<T>* _pRight;
	RBTreeNode<T>* _pParent;
	T _data;
	Color _color;
};

template<class T>
class RBTree{
	typedef RBTreeNode<T> Node;
public:
	RBTree(){
		_pHead = new Node;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;

	}
	bool Insert(const T& data){
		Node*& pRoot = GetRoot();
		if (pRoot == nullptr){
			pRoot = new Node(data, BLACK);
			pRoot->_pParent = _pHead;
		}
		else{
		//找到待插入节点的位置
		Node* pCur = pRoot;
		Node* pParent = _pHead;
		while (pCur){
			pParent = pCur;
			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data > pCur->_data)
				pCur = pCur->_pRight;
			else
				return false;
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

		while (pParent->_color == RED&&pParent != _pHead){
			Node* gf = pParent->_pParent;
			if (pParent == gf->_pLeft){
				Node* uncle = gf->_pRight;
				if (uncle&&uncle->_color == RED){
					pParent->_color = RED;
					uncle->_color = pParent->_color = BLACK;
					pCur = gf;
					pParent = pCur->_pParent;
				}
				else{
					if (pCur == pParent->_pRight){
						RotateL(pParent);
						swap(pParent, pCur);
					}

					pParent->_color = BLACK;
					gf->_color = RED;
					RotateR(gf);
				}
			}

			else{
				Node* uncle = gf->_pLeft;
				if (uncle&&uncle->_color == RED){
					pParent->_color = uncle->_color = BLACK;
					gf->_color = RED;
					pCur = gf;
					pParent = pCur->_pParent;
				}
				else{
					if (pCur == pParent->_pLeft){
						RotateR(pParent);
						swap(pParent, pCur);
					}
					pParent->_color = BLACK;
					gf->_color = RED;
					RotateL(gf);
				}

			}
		}
	}
		pRoot->_color = BLACK;
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		return true;
	}

	Node*& GetRoot(){
		return _pHead->_pParent;
	}

	Node* LeftMost(){
		Node* pRoot = GetRoot();
		if (pRoot == nullptr){
			return _pHead;
		}
		Node* pCur = pRoot;
		while (pCur->_pLeft)
			pCur = pCur->_pLeft;

		return pCur;
	}

	Node* RightMost(){
		Node* pRoot = GetRoot();
		if (pRoot == nullptr){
			return _pHead;
		}
		Node* pCur = pRoot;
		while (pCur->_pRight)
			pCur = pCur->_pRight;

		return pCur;
	}
	void Inorder(){
		_Inorder(GetRoot());
		cout << endl;
	}

	void RotateL(Node* pParent){
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pParent->_pLeft;

		pParent->_pRight = pSubRL;
		if (pSubRL)
			pSubRL->_pParent = pParent;

		pSubR->_pLeft = pParent;
		Node* gf = pParent->_pParent;
		pSubR->_pParent = gf;
		pParent->_pParent = pSubR;

		if (gf == _pHead){
			_pHead->_pParent = pSubR;
		}
		else{
			if (pParent == gf->_pLeft)
				gf->_pLeft = pSubR;
			else
				gf->_pRight = pSubR;
		}
	}

	void RotateR(Node* pParent){
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;
		 
		pParent->_pLeft = pSubLR;
		if (pSubLR)
			pSubL->_pParent = pParent;

		pSubL->_pRight = pParent;
		Node* gf = pParent->_pParent;
		pParent->_pParent = pSubL;
		pSubL->_pParent = gf;

		if (gf == _pHead){
			_pHead->_pParent = pSubL;
		}
		else{
			if (pParent == gf->_pLeft)
				gf->_pLeft = pSubL;
			
			else
				gf->_pRight = pSubL;
			
		}
	}

	bool IsRBTree(){
		Node* pRoot = GetRoot();
		if ( pRoot== nullptr){
			return true;
		}

		if (pRoot->_color != BLACK){
			cout << "违反规则二：根节点颜色是黑色。" << endl;
			return false;
		}

		//获取一条路径上的黑色节点个数
		size_t blackCount = 0;
		Node* pCur = pRoot;
		while (pCur){
			if (pCur->_color == BLACK)
				++blackCount;
			pCur = pCur->_pLeft;
		}

		size_t pathCount = 0;
		return _IsRBTree(pRoot, blackCount, pathCount);
	}
private:
	void _Inorder(Node* pRoot){
		if (pRoot){
			_Inorder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_Inorder(pRoot->_pRight);
		}
	}

	bool _IsRBTree(Node* pRoot,size_t blackCount,size_t pathCount){
		if (pRoot == nullptr){
			return true;
		}
		if (pRoot->_color == BLACK){
			++pathCount;
		}

		Node* pParent = pRoot->_pParent;
		if (pParent != _pHead&&pParent->_color == RED&&pRoot->_color == RED){
			cout << "违反了规则三：父子节点都为红色节点。" << endl;
			return false;
		}
		//叶子节点
		if (pRoot->_pLeft == nullptr&&pRoot->_pRight == nullptr){
			if (pathCount != blackCount){
				cout << "违反了性质四：每条路径上的黑色节点个数相同。" << endl;
				return false;
			}
		}

		return _IsRBTree(pRoot->_pLeft, blackCount, pathCount) && _IsRBTree(pRoot->_pRight, blackCount, pathCount);
	}

private:
	Node* _pHead;
};
#endif



enum Color{ RED, BLACK };

template<class T>
struct RBTreeNode{
	RBTreeNode(const T& data = T(), Color color = RED) :
		_pLeft(nullptr),
		_pRight(nullptr),
		_pParent(nullptr),
		_color(color),
		_data(data)
	{}

	RBTreeNode<T>* _pLeft;
	RBTreeNode<T>* _pRight;
	RBTreeNode<T>* _pParent;
	T _data;
	Color _color;
};

template<class T>
struct RBTreeIterator{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T> Self;

	RBTreeIterator(Node * pNode):_pNode(pNode)
	{}

	T& operator*(){
		return _pNode->_data;
	}
	T* operator->(){
		return &(operator*());
	}
	Self& operator++(){
	
	}

};


template<class T>
class RBTree{
	typedef RBTreeNode<T> Node;
public:
	RBTree(){
		_pHead = new Node;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;

	}
	bool Insert(const T& data){
		Node*& pRoot = GetRoot();
		if (pRoot == nullptr){
			pRoot = new Node(data, BLACK);
			pRoot->_pParent = _pHead;
		}
		else{
			//找到待插入节点的位置
			Node* pCur = pRoot;
			Node* pParent = _pHead;
			while (pCur){
				pParent = pCur;
				if (data < pCur->_data)
					pCur = pCur->_pLeft;
				else if (data > pCur->_data)
					pCur = pCur->_pRight;
				else
					return false;
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

			while (pParent->_color == RED&&pParent != _pHead){
				Node* gf = pParent->_pParent;
				if (pParent == gf->_pLeft){
					Node* uncle = gf->_pRight;
					if (uncle&&uncle->_color == RED){
						pParent->_color = RED;
						uncle->_color = pParent->_color = BLACK;
						pCur = gf;
						pParent = pCur->_pParent;
					}
					else{
						if (pCur == pParent->_pRight){
							RotateL(pParent);
							swap(pParent, pCur);
						}

						pParent->_color = BLACK;
						gf->_color = RED;
						RotateR(gf);
					}
				}

				else{
					Node* uncle = gf->_pLeft;
					if (uncle&&uncle->_color == RED){
						pParent->_color = uncle->_color = BLACK;
						gf->_color = RED;
						pCur = gf;
						pParent = pCur->_pParent;
					}
					else{
						if (pCur == pParent->_pLeft){
							RotateR(pParent);
							swap(pParent, pCur);
						}
						pParent->_color = BLACK;
						gf->_color = RED;
						RotateL(gf);
					}

				}
			}
		}
		pRoot->_color = BLACK;
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		return true;
	}

	Node*& GetRoot(){
		return _pHead->_pParent;
	}

	Node* LeftMost(){
		Node* pRoot = GetRoot();
		if (pRoot == nullptr){
			return _pHead;
		}
		Node* pCur = pRoot;
		while (pCur->_pLeft)
			pCur = pCur->_pLeft;

		return pCur;
	}

	Node* RightMost(){
		Node* pRoot = GetRoot();
		if (pRoot == nullptr){
			return _pHead;
		}
		Node* pCur = pRoot;
		while (pCur->_pRight)
			pCur = pCur->_pRight;

		return pCur;
	}
	void Inorder(){
		_Inorder(GetRoot());
		cout << endl;
	}

	void RotateL(Node* pParent){
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pParent->_pLeft;

		pParent->_pRight = pSubRL;
		if (pSubRL)
			pSubRL->_pParent = pParent;

		pSubR->_pLeft = pParent;
		Node* gf = pParent->_pParent;
		pSubR->_pParent = gf;
		pParent->_pParent = pSubR;

		if (gf == _pHead){
			_pHead->_pParent = pSubR;
		}
		else{
			if (pParent == gf->_pLeft)
				gf->_pLeft = pSubR;
			else
				gf->_pRight = pSubR;
		}
	}

	void RotateR(Node* pParent){
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;

		pParent->_pLeft = pSubLR;
		if (pSubLR)
			pSubL->_pParent = pParent;

		pSubL->_pRight = pParent;
		Node* gf = pParent->_pParent;
		pParent->_pParent = pSubL;
		pSubL->_pParent = gf;

		if (gf == _pHead){
			_pHead->_pParent = pSubL;
		}
		else{
			if (pParent == gf->_pLeft)
				gf->_pLeft = pSubL;

			else
				gf->_pRight = pSubL;

		}
	}

	bool IsRBTree(){
		Node* pRoot = GetRoot();
		if (pRoot == nullptr){
			return true;
		}

		if (pRoot->_color != BLACK){
			cout << "违反规则二：根节点颜色是黑色。" << endl;
			return false;
		}

		//获取一条路径上的黑色节点个数
		size_t blackCount = 0;
		Node* pCur = pRoot;
		while (pCur){
			if (pCur->_color == BLACK)
				++blackCount;
			pCur = pCur->_pLeft;
		}

		size_t pathCount = 0;
		return _IsRBTree(pRoot, blackCount, pathCount);
	}
private:
	void _Inorder(Node* pRoot){
		if (pRoot){
			_Inorder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_Inorder(pRoot->_pRight);
		}
	}

	bool _IsRBTree(Node* pRoot, size_t blackCount, size_t pathCount){
		if (pRoot == nullptr){
			return true;
		}
		if (pRoot->_color == BLACK){
			++pathCount;
		}

		Node* pParent = pRoot->_pParent;
		if (pParent != _pHead&&pParent->_color == RED&&pRoot->_color == RED){
			cout << "违反了规则三：父子节点都为红色节点。" << endl;
			return false;
		}
		//叶子节点
		if (pRoot->_pLeft == nullptr&&pRoot->_pRight == nullptr){
			if (pathCount != blackCount){
				cout << "违反了性质四：每条路径上的黑色节点个数相同。" << endl;
				return false;
			}
		}

		return _IsRBTree(pRoot->_pLeft, blackCount, pathCount) && _IsRBTree(pRoot->_pRight, blackCount, pathCount);
	}

private:
	Node* _pHead;
};