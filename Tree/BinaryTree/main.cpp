#pragma once
#include <iostream>
#include <assert.h>
#include <queue>
#include <stack>

using namespace std;
template <class T>
struct BinaryTreeNode
{
	T _data;
	BinaryTreeNode<T>* _leftchild;
	BinaryTreeNode<T>* _rightchild;
    T _mark;
	BinaryTreeNode(const T& x)//���캯��
		: _data(x)
		, _leftchild(NULL)
		, _rightchild(NULL)
		, _mark(0)
	{}
};

template <class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
public:
	BinaryTree()//�޲ι��캯��
		:_root(NULL)
	{}
	BinaryTree(T* a, size_t n, const T& invalid = T())//���캯��
	{
		size_t index = 0;
		_root = _GreateTree(a, n, invalid, index);
	}
	BinaryTree(const BinaryTree<T>& t)//��������
	{
		_root = _copy(t._root);
	}
	BinaryTree<T>& operator=(const BinaryTree<T>& t)
	{
		if (this != &t)
		{
			Node* newRoot = _copy(t._root);
			_Destroy(_root);
			_root = newRoot;
		}
		return *this;
	}
	~BinaryTree()//��������
	{
	void _Destory();
	}
	void PrevOrder()//ǰ������ݹ�
	{
		_PrevOrder2(_root);
		cout << endl;
	}
	void InOrder()//��������ݹ�
	{
		_InOrder(_root);
		cout << endl;
	}
	void PostOrder()//��������ݹ�
	{
		_PostOrder(_root);
		cout << endl;
	}
	void LeveIOrder()//�������,���ö��У��Ե�ǰ�����һ��
	{
		queue<Node*> q;
		if (_root)
			q.push(_root);
		while (!q.empty())//���в�Ϊ��
		{
			Node* front = q.front();//ȡ��ͷ
			cout << front->_data << " ";
			q.pop();//ɾ����ͷ
			if (front->_leftchild)
				q.push(front->_leftchild);
			if (front->_rightchild)
				q.push(front->_rightchild);
		}
		cout << endl;
	}
	size_t Size()//�ڵ�ĸ���
	{
		return _Size(_root);
	}
	size_t Depth()//�������
	{
		return _Depth(_root);
	}
	size_t LeafSize()//Ҷ�ӽڵ�ĸ���
	{
		return _LeafSize(_root);
	}
	size_t GetKLevel(size_t k)//��k��ڵ�ĸ���
	{
		assert(k > 0);
		return _GetKLevel(_root, k);
	}
	Node* Find(const T& x)//�ҽڵ�x
	{
		return _Find(_root, x);
	}
protected:
	Node* _copy(Node* root)//����
	{
		if (root == NULL)
			return NULL;
		Node* newNode = new Node(root->_data);
		newNode->_leftchild = _copy(root->_leftchild);
		newNode->_rightchild =_copy(root->_rightchild);
		return newNode;
	}
	void _Destroy(Node* root)//����
	{
		if (root == NULL)
			return;
		_Destroy(root->_leftchild);
		_Destroy(root->_rightchild);
		delete root;
	}
	Node* _Find(Node* root, const T& x)//�ҽڵ�x�ĵ��ú���
	{
		if (root == NULL)
			return NULL;
		if (root->_data == x)
			return root;
		Node* tmp = _Find(root->_leftchild, x);
		if (tmp)
			return tmp;
		return _Find(root->_rightchild, x);
	}
	size_t _GetKLevel(Node* root,size_t k)//��k��ڵ�ĵ��ú���
	{
		if (root == NULL)
			return 0;
		if (k == 1)
		{
			return 1;
		}
		return _GetKLevel(root->_leftchild, k - 1) + _GetKLevel(root->_rightchild, k - 1);
	}
	size_t _LeafSize(Node* root)//Ҷ�ӽڵ�ĵ��ú���
	{
		if (root == NULL)
			return 0;
		if (root->_leftchild == NULL && root->_rightchild == NULL)
		{
			return 1;
		}
		return _LeafSize(root->_leftchild) + _LeafSize(root->_rightchild);
	}
	size_t _Depth(Node* root)//������ȵ��ú���
	{
		if (root == NULL)
			return 0;
		int left = _Depth(root->_leftchild);
		int right = _Depth(root->_rightchild);
		return left > right ? left + 1: right + 1;
	}
	size_t _Size(Node* root)//�ڵ�ĸ���
	{
		if (root == NULL)
			return 0;
		return (_Size(root->_leftchild) + _Size(root->_rightchild))+1;
	}
	void _PostOrder(Node* root)//����������ú���
	{
		if (root == NULL)
			return;
		_PostOrder(root->_leftchild);
		_PostOrder(root->_rightchild);
		cout << root->_data << " ";
	}
	void _InOrder(Node* root)//��������ĵ��ú���
	{
		if (root == NULL)
			return;
		_InOrder(root->_leftchild);
		cout << root->_data << " ";
		_InOrder(root->_rightchild);
	}
	void _PrevOrder2(Node* root)
	{
	    stack < BinaryTreeNode<T>*> s1;
	    BinaryTreeNode<T>* Point = new Node(root->_data);

	    if (root == NULL)
			return;

        Point = root;
        s1.push(Point);
        cout << Point->_data << " ";
        while(!s1.empty())
        {
            if(Point->_leftchild != NULL && Point->_leftchild->_mark == 0)
            {
               s1.push(Point->_leftchild);
               Point =  Point->_leftchild ;
               cout << Point->_data << " ";
            }
            else if(Point->_rightchild != NULL && Point->_rightchild->_mark == 0)
            {
                s1.push(Point->_rightchild);
                Point = Point->_rightchild;
                cout << Point->_data << " ";

            }
            else
            {
                Point->_mark = 1;
                s1.pop();
                if(!s1.empty())
                Point = s1.top();
            }
        }
	}

	void _PrevOrder(Node* root)//ǰ������ĵ��ú���
	{
		if (root == NULL)
			return;
		cout << root->_data << " ";
		_PrevOrder(root->_leftchild);
		_PrevOrder(root->_rightchild);
	}
	Node* _GreateTree(T* a, size_t n, const T& invalid, size_t& index)//���캯���ĵ��ú���
	{
		Node* root = NULL;
		if ((index< n) && (a[index] != invalid))
		{
			root = new Node(a[index]);
			root->_leftchild = _GreateTree(a, n, invalid, ++index);
			root->_rightchild = _GreateTree(a, n, invalid, ++index);
		}
		return root;
	}
protected:
	Node* _root;
};

void BinaryTreeTest()//����
{
	int a[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTree<int> t1(a, sizeof(a) / sizeof(a[0]), '#');
	t1.PrevOrder();
	t1.LeveIOrder();
	t1.InOrder();
	t1.PostOrder();
	cout << "num of point��" << t1.Size() << endl;
	cout << "deepth��" << t1.Depth() << endl;
	cout << "num of leaf point" << t1.LeafSize() << endl;
	cout << "the k level��" << t1.GetKLevel(2) << endl;
	BinaryTree<int> t2(t1);
	t2.PostOrder();
	BinaryTree<int> t3;
	t3 = t1;
}

int main()
{
	BinaryTreeTest();
	return 0;
}
