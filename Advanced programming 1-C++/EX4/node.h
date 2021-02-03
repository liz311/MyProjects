/* Created By Lizzy Asis */

#ifndef NODE_HEADER
#define NODE_HEADER
#include <iostream>
using namespace std;

template <class T> class Node
{
private:
	T Data;
	Node *Right, *Left;
public:
	Node();
	Node(const T &);
	virtual ~Node () {}
	void RemoveLeaf(Node<T> *Leaf) {
		if(Leaf != NULL)
		{
			RemoveLeaf(Leaf->GetLeftNode());
			RemoveLeaf(Leaf->GetRightNode());
			delete Leaf;
		}
	}
	void SetData(const T &);
	const T GetData() const;
	void SetRightNode(const T &);
	void SetLeftNode(const T &);
	Node<T> *GetRightNode() const;
	Node<T> *GetLeftNode() const;
};
#endif

template <class T> Node<T>::Node() {Right = NULL; Left = NULL;}
template <class T> Node<T>::Node(const T &Data) {Right = NULL; Left = NULL; SetData(Data);}
template <class T> void Node<T>::SetData(const T &Data) {this->Data = Data;}
template <class T> const T Node<T>::GetData() const {return Data;}
template <class T> void Node<T>::SetRightNode(const T &ValueToRight) {this->Right = new Node<T>(ValueToRight);}
template <class T> void Node<T>::SetLeftNode(const T &ValueToLeft) {this->Left = new Node<T>(ValueToLeft);}
template <class T> Node<T> *Node<T>::GetRightNode() const {return this->Right;}
template <class T> Node<T> *Node<T>::GetLeftNode() const {return this->Left;}
