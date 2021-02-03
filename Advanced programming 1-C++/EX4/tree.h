/* Created By Lizzy Asis */

#ifndef TREE_HEADER
#define TREE_HEADER
#include "Node.h"

template <class T> class Tree
{
	template <class T> friend ostream &operator<<(ostream &Output, const Tree<T> &ToPrint);
private:
	Node<T> *Root;
	int Size;
public:
	Tree();
	virtual ~Tree() { this->Root->RemoveLeaf(this->GetRoot());}
	void AddNode(Node<T> *, const T &);
	void InOrder(const Node<T> *) const;
	Node<T> *GetRoot() const;
	int GetSize() const;
	bool isExist(const Node<T> *, const T &) const;
};
#endif

template <class T> Tree<T>::Tree() {Root = NULL; Size = 0;}
template <class T> void Tree<T>::AddNode(Node<T> *Leaf, const T &newValue)
{
	if (Root == NULL) {Root = new Node<T>(newValue); Size++;}
	else if (newValue < Leaf->GetData())
	{
		if (Leaf->GetLeftNode() == NULL) {Leaf->SetLeftNode(newValue); Size++;}
		else {AddNode(Leaf->GetLeftNode(), newValue);}
	}
	else
	{
		if (Leaf->GetRightNode() == NULL) {Leaf->SetRightNode(newValue); Size++;}
		else {AddNode(Leaf->GetRightNode(), newValue);}
	}
}
template <class T> void Tree<T>::InOrder(const Node<T> *Leaf) const
{
	if (Leaf != NULL)
	{
		InOrder(Leaf->GetLeftNode());
		cout << "[" << Leaf->GetData() << "] ";
		InOrder(Leaf->GetRightNode());
	}
}
template <class T> Node<T> *Tree<T>::GetRoot() const {return Root;}
template <class T> ostream &operator<<(ostream &Output, const Tree<T> &ToPrint) {ToPrint.InOrder(ToPrint.GetRoot());return Output;}
template <class T> int Tree<T>::GetSize() const {return Size;}
template <class T> bool Tree<T>::isExist(const Node<T> *Leaf, const T &SearchValue) const
{
	if (Leaf != NULL)
	{
		if (Leaf->GetData() == SearchValue)
			return true;
		else if (Leaf->GetData() < SearchValue) {return isExist(Leaf->GetLeftNode(), SearchValue);}
		else if (Leaf->GetData() >= SearchValue) {return isExist(Leaf->GetRightNode(), SearchValue);}
		else {return false;}
	}
}
