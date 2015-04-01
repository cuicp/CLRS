#include<iostream>
#include<string>
#include<memory>
#include<cstdio>
using namespace std;
typedef int key_type;
typedef string value_type;

typedef struct tree{
	key_type key;
	value_type value;
	
	shared_ptr<tree>left;
	shared_ptr<tree>right;
	shared_ptr<tree>p;

	tree(key_type _key,value_type _value,shared_ptr<tree> _left=nullptr,shared_ptr<tree> _right=nullptr,shared_ptr<tree> _p=nullptr):key(_key),value(_value),left(_left),right(_right),p(_p){}

}tree;

shared_ptr<tree> tree_search(shared_ptr<tree> T,key_type key)
{
	while(T)
	{
		if(T->key==key)return T;
		else if(T->key>key)T=T->left;
		else T=T->right;
	}
	return nullptr;
}
shared_ptr<tree> tree_max(shared_ptr<tree> x)
{
	while(x->left)
	{
		x=x->left;
	}
	return x;
}
shared_ptr<tree> tree_min(shared_ptr<tree> x)
{
	while(x->right)
	{
		x=x->right;
	}
	return x;
}
shared_ptr<tree> tree_successor(shared_ptr<tree> x)
{
	if(x->right)return tree_min(x->right);

	auto y=x->p;
	while(y&&x==y->right)
	{
		x=y;
		y=y->p;
	}

	return y;
}

bool tree_insert(shared_ptr<tree>& root,shared_ptr<tree> z)
{
	shared_ptr<tree>y;
	auto x=root;
	while(x)
	{
		y=x;
		if(x->key==z->key)return false;
		else if(x->key>z->key)x=x->left;
		else x=x->right;
	}

	z->p=y;
	if(!y)root=z;
	else if(y->key>z->key) y->left=z;
	else y->right=z;

	return true;
}
void tree_delete(shared_ptr<tree> z)
{
	shared_ptr<tree>y;
	if(!z->left||!z->right)y=z;
	else y=tree_successor(z);

	shared_ptr<tree>x;
	if(y->left)x=y->left;
	else x=y->right;

	if(x)x->p=y->p;

	if(!y->p);
	else if(y==y->p->right) y->p->right=x;
	else y->p->left=z;

	if(y!=z)
	{
		z->key=y->key;
		z->value=y->value;
	}
	
}
void tree_travel(const shared_ptr<tree> T)
{
	if(!T)return;
	tree_travel(T->left);
	cout<<T->key<<' '<<T->value<<endl;
	tree_travel(T->right);
}
int main()
{
	auto a=make_shared<int>(10);
	auto b=a;
	cout<<(b==a)<<endl;
	shared_ptr<tree>T;
	for(int i=0;i<10;++i)
	{
		int x=rand()%1000;
		tree_insert(T,make_shared<tree>(x,"",nullptr,nullptr,nullptr));
	}

	tree_travel(T);
	cout<<"tree_max="<<tree_max(T)<<endl;
	cout<<"tree_min="<<tree_min(T)<<endl;
	cout<<"please input the key you will delete"<<endl;
	int del;
	cin>>del;
	auto z1=tree_search(T,del);
	tree_delete(z1);
	tree_travel(T);
	cout<<"please input the number which successor you want get"<<endl;

	int suc;
	cin>>suc;
	auto z=tree_search(T,suc);
	if(z)cout<<tree_successor(z)->key<<endl;
	else cout<<"z==null"<<endl;



	return 0;

}

