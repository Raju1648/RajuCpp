#include<iostream>
#include<stdlib.h>
using namespace std;

//BST
class BST
{
private:
	struct node
	{
		int key;
		node * left;
		node * right;
	};
	node *root;
	void PrintInorderPrivate(node *ptr);
	void AddleafPrivate(int key ,node *ptr);
	node * ReturnNodePrivate(int key, node *ptr);
	node* smallestkeyPrivate(node *ptr);
	node* greatestkeyPrivate(node *ptr);
	node * findNodePrivate(int key ,node * root);
	node * SucceesorPrivate(int key, node *root);
	node * PredeceesorPrivate(int key, node *root);
	node * ChildrensPrintPrivate(node * root);
	node * AncestorPrivate(int key1,int key2, node *root);
	void  DeleteNodePrivate(int key,node * root);
	void RemoveRootMatch();
	void RemoveMatch(node *parent, node * match,bool left);
	void printpathPrivate(node * root,int path[], int length);
	void isBSTPrivate(node * root);
	int callBSTProperity(node *root,int max, int min) ;
	node * ReturnNode(int key);
	node * Createleaf(int key);
	void PrintPostorderPrivate(node *root);
	void mirrorimagePrivate(node * root);
	void PrintPreorderPrivate(node * root);
	void Destructor_PostorderPrivate(node *root);

public:

BST();
~BST();

	void Addleaf(int key);
	void PrintInorder();
	int RetrunRootkey();
	void PrintChildren(int key);
	void smallestkey();
	void greatestkey();
	void find(int key);
	void Succeesor(int key);
	void Predeceesor(int key);
	void ChildrensPrint();
	void Ancestor(int key1, int key2);
	void DeleteNode(int key);
	void printpath();
	void isBST();
	void mirrorimage();
	void PrintPreorder();
	void PrintPostorder();
};
void BST::PrintPostorder()
{
	PrintPostorderPrivate(root);
}
void BST::PrintPreorder()
{
	PrintPreorderPrivate(root);
}

void BST::PrintPreorderPrivate(node * ptr)
{
	if(ptr)
	{
		cout<<ptr->key<<" ";
		PrintPreorderPrivate( ptr->left);
		PrintPreorderPrivate( ptr->right);
	}
}
void BST::PrintPostorderPrivate(node * ptr)
{
	if(ptr)
	{

		PrintPostorderPrivate( ptr->left);
		PrintPostorderPrivate( ptr->right);
		cout<<ptr->key<<" ";
	}
}

void BST::mirrorimage()
{
	mirrorimagePrivate(root);
}

void BST::mirrorimagePrivate(node * ptr)
{

	if(ptr==NULL)
	{
		return ;
	}
	else
	{
		node * temp;
			mirrorimagePrivate(ptr->left);

			mirrorimagePrivate(ptr->right);
			temp=ptr->left;
			ptr->left=ptr->right;
			ptr->right=temp;
	}


}
BST::~BST()
{
	cout<<"destructor calling"<<endl;
	Destructor_PostorderPrivate(root);
}
void BST::Destructor_PostorderPrivate(node *ptr)
{
	if(ptr)
	{
		if(ptr->left!=NULL)
		{
			Destructor_PostorderPrivate(ptr->left);
		}
		if(ptr->right!=NULL)
		{
			Destructor_PostorderPrivate(ptr->right);
		}
		cout<<ptr->key<<" ";
		delete ptr;
	}

}
void BST::isBST()
{
	isBSTPrivate(root);
}

void BST::isBSTPrivate(node * root)
{

		int max=9999;
		int min=-1;
		int x=callBSTProperity(root,max, min);
		if(x==1)
		{
			cout<<"Tree is Binary Search Tree"<<endl;
		}
		else
		{
			cout<<"Tree is not Binary Search Tree"<<endl;
		}


}
int BST::callBSTProperity(node *root,int max, int min)
{
	if(root== NULL)
	{
		return 1;
	}
	if(root->key> max || root->key< min)
	{
		return 0;
	}
	return callBSTProperity(root->left,root->key,min) &&
			callBSTProperity(root->right,max,root->key);

}
void printArray(int path[],int length);
void BST::printpath()
{ int path[100];
	printpathPrivate(root, path,0);
}
void BST::printpathPrivate(node * root,int path[], int length)
{
	if(root==NULL)
		return;
	path[length]=root->key;
	length++;

	if(root->left==NULL && root->right==NULL)
	{
		printArray(path ,length);
	}
	else
	{
		printpathPrivate(root->left,path,length);
		printpathPrivate(root->right,path,length);
	}


}
void printArray(int path[],int length)
{
 for(int i=0;i<length;i++)
 {
	 cout<<" "<<path[i];
 }
 cout<<endl;
}

void BST::RemoveMatch(node *parent, node * match,bool left)
{
	if(root!=NULL)
	{
		node * delptr;
		int matchkey=match->key;
		//int smallestInRightSubtree;

		//case 1-No children
		if(match->left==NULL &&match->right==NULL)
		{
			delptr=match;
			left==true?parent->left=NULL:parent->right=NULL;
			delete delptr;
			cout<<"the node containing a key"<<matchkey<<"was removed"<<endl;
		}
		//case 2 1- child
		else if(match->left==NULL && match->right!=NULL)
		{
			left==true?parent->left=match->right:parent->right=match->right;
			match->right=NULL;
			delptr=match;
			delete delptr;
			cout<<"the node containing a key"<<matchkey<<"was removed"<<endl;
		}
		else if(match->left!=NULL && match->right==NULL)
				{
					left==true?parent->left=match->left:parent->right=match->left;
					match->left=NULL;
					delptr=match;
					delete delptr;
					cout<<"the node containing a key"<<matchkey<<"was removed"<<endl;
				}

		//case 3 2 child
		else
		{
			node *ptr = SucceesorPrivate(matchkey,match);
			DeleteNodePrivate(ptr->key,match);
			match->key=ptr->key;

		}
	}
	else
	{
		cout<<"tree is empty..."<<endl;
	}
}

void BST::DeleteNode(int key)
{
	DeleteNodePrivate(key,root);
}
void BST::DeleteNodePrivate(int key,node * parent)
{
	if(root!=NULL)
	{
		if(root->key == key)
		{
			RemoveRootMatch();
		}
		else
		{
			if(key< parent->key && parent->left!=NULL)
			{
				parent->left->key==key ?
						RemoveMatch(parent,parent->left,true):
						DeleteNodePrivate(key,parent->left);
			}
			else if(key> parent->key && parent->right!=NULL)
			{
				parent->right->key==key ?
						RemoveMatch(parent,parent->right,false):
						DeleteNodePrivate(key,parent->right);
			}
			else
			{
				cout<<"the key "<<"was not found in the tree"<<endl;
			}

		}
	}
	else
	{
		cout<<"The tree is empty"<<endl;
	}
}

void BST::RemoveRootMatch()
{
	if(root!=NULL)
	{
		node * delptr=root;
		int rootkey=root->key;
		//int smallestInRightsubtree;

		//case1- No children
		if (root->left== NULL && root->right==NULL)
		{
			root=NULL;
			delete delptr;
		}
		else if(root->left==NULL && root->right!=NULL)
		{
			root=root->right;
			delptr->right=NULL;
			delete delptr;
			cout<<"The root node with key"<<rootkey<<"was deleted. and the new root "
					"contain "<<root->key<<endl;

		}
		else if(root->left!=NULL && root->right==NULL)
			{
				root=root->left;
				delptr->left=NULL;
				delete delptr;
				cout<<"The root node with key"<<rootkey<<"was deleted. and the new root "
						"contain "<<root->key<<endl;

			}
		//case 2- 2 children
		else
		{

			node *ptr=SucceesorPrivate(root->key,root);
			DeleteNodePrivate(ptr->key,root);
			root->key =ptr->key;
			cout<<"The root node with key"<<rootkey<<"was Over written by"
									"contain "<<root->key<<endl;
		}


	}
	else
	{
		cout<<"can not remove root.The tree is empty"<<endl;
	}
}

void BST::Ancestor(int key1, int key2)
{
	AncestorPrivate(key1,key2,root);
}
BST::node *BST::AncestorPrivate(int key1,int key2, node *ptr)
{
	if(ptr==NULL)
	{
		return NULL;
	}
	if(ptr->key>key1 && ptr->key >key2)
	{
		AncestorPrivate(key1,key2,ptr->left);
	}
	if(ptr->key<key1 && ptr->key <key2)
	{
		AncestorPrivate(key1,key2,ptr->right);
	}
	cout<<" "<<ptr->key;
	return ptr;
}
void BST::ChildrensPrint()
{
	ChildrensPrintPrivate(root);
}

BST::node * BST::ChildrensPrintPrivate(node * ptr)
{
	if (ptr==NULL)
	{
		return ptr;
	}

	if(ptr->left== NULL && ptr->right==NULL)
	{
		cout<<ptr->key<<" ";

	}
	else
	{
		ChildrensPrintPrivate(ptr->left);
		ChildrensPrintPrivate(ptr->right);
	}
	return NULL;
}
void BST::Predeceesor(int key)
{	cout<<key<<" is :";
	node * ptr=findNodePrivate(key, root);
	PredeceesorPrivate(key,ptr);
}

BST::node * BST::PredeceesorPrivate(int key, node *ptr)
{
	if(ptr->left == NULL)
	{
		return ptr;
	}
	else
	{
		return greatestkeyPrivate(ptr->left->right);
	}
}
void BST::Succeesor(int key)
{	cout<<key<<" is :";
	node * ptr=findNodePrivate(key, root);
	SucceesorPrivate(key,ptr);
}

BST::node * BST::SucceesorPrivate(int key, node *ptr)
{
	if(ptr->right == NULL)
	{
		return ptr;
	}
	else
	{
		return smallestkeyPrivate(ptr->right->left);
	}
}

void BST::find(int key)
{
	//cout<<key;
	//cout<<"i am in find function"<<endl;
	findNodePrivate(key, root);
}
BST::node * BST::findNodePrivate(int key ,node * ptr)
{
	//cout<<"i am in findNOde111 function"<<endl;
	if(ptr!=NULL)
	{
		if(ptr->key == key)
		{
		//cout<<"key is found and node:  "<<ptr->key<<endl;
			return ptr;
		}
		else if(ptr->key < key)
		{
			return findNodePrivate(key, ptr->right);
		}
		else if(ptr->key > key)
		{
			return	findNodePrivate(key, ptr->left);
		}
	}
	else
	{
		cout<<key<< " is not found in the tree"<<endl;

	}

	return ptr;
}

void BST::greatestkey()
{
	greatestkeyPrivate(root);
}

BST::node * BST::greatestkeyPrivate(node *ptr)
{
	if(ptr==NULL)
	{
		return ptr;
	}
	else if(ptr->right!=NULL)
	{
		return greatestkeyPrivate(ptr->right);
	}
	//cout<<"greatest key is:  "<<ptr->key<<endl;
	cout<<ptr->key;
	return ptr;
}
void BST::smallestkey()
{
	smallestkeyPrivate(root);
}

BST::node * BST::smallestkeyPrivate(node *ptr)
{
	if(ptr==NULL)
	{
		return ptr;
	}
	else if(ptr->left!=NULL)
	{
		return smallestkeyPrivate(ptr->left);
	}
	//cout<<"smallest key is:  "<<ptr->key<<endl;
	cout<<ptr->key;
	return ptr;
}
void BST::PrintChildren(int key)
{
	node *ptr =ReturnNode(key);
	if(ptr)
	{
		cout<<"parent node"<<ptr->key<<endl;
		ptr->left==NULL?
				cout<<"Left Child= NULL\n":
				cout<<"Left Child= "<<ptr->left->key<<endl;
		ptr->right==NULL?
				cout<<"right Child= NULL\n":
				cout<<"right Child= "<<ptr->right->key<<endl;
	}
	else
	{
		cout<<"key"<<key<<"is not in the tree"<<endl;
	}
}
int BST::RetrunRootkey()
{
	if(root!=NULL)
	{
		return root->key;
	}
	else
	{
		return -1000;
	}
}
BST::node * BST::ReturnNode(int key)
{
	return ReturnNodePrivate(key,root);
}

BST::node * BST::ReturnNodePrivate(int key, node *ptr)
{
	if(ptr!=NULL)
	{
		if(key == ptr->key)
		{
			//cout<<" key is found";
			return ptr;

		}
		else
		{
			if(key > ptr->key)
			{
				return ReturnNodePrivate(key, ptr->right);
			}
			else
			{
				return ReturnNodePrivate(key, ptr->left);
			}
		}
	}
	else
	{
		return NULL;
	}
}



void BST::PrintInorder()
{
	PrintInorderPrivate(root);
}

void BST::PrintInorderPrivate(node *ptr)
{
	if(root)
	{
		if(ptr->left)
		PrintInorderPrivate(ptr->left);
		cout<<ptr->key<< " ";
		if(ptr->right)
		PrintInorderPrivate(ptr->right);
	}
	else
	{
		cout<<"Tree is empty"<<endl;
	}
}
void BST::Addleaf(int key)
{
	AddleafPrivate(key,root);
}
void BST::AddleafPrivate(int key ,node *ptr)
{
	if(root==NULL)
	{
		root=Createleaf(key);
	}
	else if(ptr->key>key)
	{
		if(ptr->left!=NULL)
		{
			AddleafPrivate(key,ptr->left);
		}
		else
		{
			ptr->left=Createleaf(key);
		}
	}
	else if(ptr->key<key)
		{
			if(ptr->right!=NULL)
			{
				AddleafPrivate(key,ptr->right);
			}
			else
			{
				ptr->right=Createleaf(key);
			}
		}
	else
	{
		cout<<"key is "<<key<<" already present"<<endl;
	}

}
BST::BST()
{
	cout<<"constructor called"<<endl;
	root= NULL;
}
BST::node * BST::Createleaf(int key)
{

	node *n=new node;
	n->key=key;
	n->left=NULL;
	n->right=NULL;
	return n;
}



int main()
{

int treeA[]={50,76,21,4,32,64,15,52,14,52,14,100,83,23,70,87,80};
cout<<"program start here"<<endl;
BST ref;
cout<<"Before adding an elements in tree"<<endl;
ref.PrintInorder();
cout<<"Now Adding an elements in tree"<<endl;
for (int i=0;i<sizeof(treeA)/sizeof(int);i++)
{
	ref.Addleaf(treeA[i]);
}

cout<<"inorder travels"<<endl;
ref.PrintInorder();
cout<<"\n preorder of tree"<<endl;
ref.PrintPreorder();
cout<<"\n postorder of tree"<<endl;
ref.PrintPostorder();
//cout<<"key found call"<<endl;
//ref.ReturnNode(33);
//cout<<"key is found"<<p<<endl;
//ref.PrintChildren(100);
//cout<<"smallest key"<<endl;
cout<<"\n smallest key in the tree: ";
ref.smallestkey();
//cout<<endl;
cout<<"\n greatest key in the tree: ";

ref.greatestkey();
cout<<endl;
//cout<<"\n find the key  83 is : ";
//ref.find(83);
//ref.find(14);
ref.find(82);

cout<<"\n Successor of ";
ref.Succeesor(76);
cout<<"\n Predecessor of ";
ref.Predeceesor(76);
cout<<"\n children's of the tree : ";
ref.ChildrensPrint();
cout<<"\n Ancestor of two keys : ";
ref.Ancestor(80,52);

cout<<"\n printpath:"<<endl;
ref.printpath();

cout<<"\n is BST calling"<<endl;
ref.isBST();

cout<<"\n mirror image of tree"<<endl;
ref.mirrorimage();
cout<<"\n preorder of tree"<<endl;
ref.PrintPreorder();
cout<<endl;
//cout<<"\n delete node in the tree  : ";
//ref.DeleteNode(4);
//cout<<"\n inorder travels"<<endl;
//ref.PrintInorder();
//for (int i=0;i<sizeof(treeA)/sizeof(int);i++)
//{
	//ref.PrintChildren(treeA[i]);
	//refAddleaf(treeA[i]);
//}

	return 0;
}
