/* Created By Lizzy Asis */

#include "Tree.h"
void InsertValuesToIntegerTree(Tree<int> &);
void InsertValuesToDoubleTree(Tree<double> &);
void FunctionForExists(Tree<int> &, Tree<double> &);

void main()
{
	Tree<int> IntegerTree;
	Tree<double> DoubleTree;
	InsertValuesToIntegerTree(IntegerTree);
	InsertValuesToDoubleTree(DoubleTree);
	int Size = IntegerTree.GetSize();
	cout << "Integer tree: " << IntegerTree << ",Size: " << Size << endl << endl;
	Size = DoubleTree.GetSize();
	cout << "Double tree: " << DoubleTree << ",Size: " << Size << endl << endl;
	FunctionForExists(IntegerTree, DoubleTree);
}

void InsertValuesToIntegerTree(Tree<int> &myTree)
{
	myTree.AddNode(myTree.GetRoot(), 3);
	myTree.AddNode(myTree.GetRoot(), 1);
	myTree.AddNode(myTree.GetRoot(), 5);
	myTree.AddNode(myTree.GetRoot(), 2);
	myTree.AddNode(myTree.GetRoot(), 4);
}

void InsertValuesToDoubleTree(Tree<double> &myTree)
{
	myTree.AddNode(myTree.GetRoot(), 5.2);
	myTree.AddNode(myTree.GetRoot(), -2.3);
	myTree.AddNode(myTree.GetRoot(), 12.4);
	myTree.AddNode(myTree.GetRoot(), 34.8);
	myTree.AddNode(myTree.GetRoot(), 0.0);
	myTree.AddNode(myTree.GetRoot(), 1.8);
}
void FunctionForExists(Tree<int> &IntegerTree, Tree<double> &DoubleTree)
{
	if (IntegerTree.isExist(IntegerTree.GetRoot(),3) == true)
		cout << "We checked number 3 and it's inside the integer tree." << endl;
	else
		cout << "We checked number 3 and it's NOT inside the integer tree." << endl;

	if (DoubleTree.isExist(DoubleTree.GetRoot(), 15.8) == true)
		cout << "We checked number 15.8 and it's inside the double tree." << endl;
	else
		cout << "We checked number 15.8 and it's NOT inside the double tree." << endl;
}
