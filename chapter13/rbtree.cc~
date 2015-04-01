#include<iostream>
#include<string>
#include<memory>
using namespace std;
typedef int Color;
typedef int key_type;
typedef string value_type;
const Color BLACK=1;
const Color RED=0;

typedef struct rb_tree
{
	key_type key;
	value_type value;
	Color color;
	shared_ptr<rb_tree>p;
	shared_ptr<rb_tree>left;
	shared_ptr<rb_tree>right;
	
	rb_tree(key_type key,value_type value,Color,shared_ptr<rb_tree>p=nullptr,shared_ptr<rb_tree>left=nullptr,shared_ptr<rb_tree>right=nullptr):
		key(key),value(value),color(color),p(p),left(left),right(right){}

}rb_tree;
const shared_ptr<rb_tree>NIL(0,0,BLACK);
shared_ptr<rb_tree>root;


shared_ptr<rb_tree> rb_tree_max(shared_ptr<rb_tree>x)
{
	auto y=NIL;
	while(x)
	{
		y=x;
		x=x->right;
	}
	return y;
}
shared_ptr<rb_tree> rb_tree_min(shared_ptr<rb_tree>x)
{
	auto y=NIL;
	while(x)
	{
		y=x;
		x=x->left;
	}
}
shared_ptr<rb_tree> rb_tree_successor(shared_ptr<rb_tree>x)
{
	if(x->right)return rb_tree_min(x->right);
	
	while(x->p!=NIL&&x==x->p->right)
	{
		x=x->p;
	}
	return x->p;
}
void left_rotate(shared_ptr<rb_tree>&T,shared_ptr<rb_tree>x)
{
	auto y=x->right;
	if(!y)
	{
		cerr<<"can not left rotate"<<endl;
		return ;
	}
	
	y->p=x->p;
	if(x->p==NIL)T=y;
	else if(x==x->p->right)x->p->right=y;
	else x->p->left=y;

	x->p=y;
	x->right=y->left;
	if(y->left!=NIL)y->left->p=x;
	y->left=x;
}
void right_rotate(shared_ptr<rb_tree>&T,shared_ptr<rb_tree>x)
{
	auto y=x->left;

	if(!y)
	{
		cerr<<"can not right rotate"<<endl;
		return ;
	}

	y->p=x->p;
	if(x->p==NIL)T=y;
	else if(x==x->p->left)x->p->left=y;
	else x->p->right=y;

	x->p=y;
	x->left=y->right;
	if(y->right!=NIL)y->right->p=x;
	y->right=x;
}
void rb_insert_fixup(shared_ptr<rb_tree>&T,shared_ptr<rb_tree>z)
{
	while(z->p->color==RED)
	{
		if(z->p=z->p->p->left)
		{
			auto y=z->p->p->right;
	
			if(y->color==RED)
			{
				z->p->color=BLACK;
				y->color=BLACK;
				z->p->p->color=RED;
				z=z->p->p;
			}
			else
			{
				if(z==z->p->right)
				{
					z=z->p;
					left_rotate(T,z);
				}
			
				z->p->color=BLACK;
				z->p->color=RED;
			
				right_rotate(T,z->p->p);
			}

		}
		else
		{
			auto y=z->p->p->left;

			if(y->color==RED)
			{
				z->p->color=BLACK;
				y->color=BLACK;
				z=z->p->p;
			}
			else
			{
				if(z==z->p->left)
				{
					z=z->p;
					right_rotate(T,z);
				}
				
				z->p->color=BLACK;
				z->p->p->color=RED;
				left_rotate(T,z->p->p);

			}

		}		
	}

	z->color=BLACK;
}
void rb_tree_insert(shared_ptr<rb_tree>&T,shared_ptr<rb_tree>z)
{
	auto y=NIL;
	auto x=T;
	while(x)
	{
		y=x;
		if(z->key<x->key)x=x->left;
		else x=x->right;
	}
	
	z->p=y;
	if(y==NIL)T=z;
	else if(z->key<y->key)y->left=z;
	else y->right=z;
	
	z->left=NIL;
	z->right=NIL;
	z->color=RED;
	rb_insert_fixup(T,z);
}
void rb_delete_fixup(shared_ptr<rb_tree>&T,shared_ptr<rb_tree>x)
{
	while(x!=T&&x->color==BLACK)
	{
		if(x==x->p->left)
		{
			auto w=x->p->right;
			
			//case1,color[w] is red
			if(w->color==RED)
			{
				w->color=BLACK;
				x->p->color=RED;
				left_rotate(T,x->p);
				w=x->p->right;
			}
			
			//case2,color[w] is black and color[right[w]] is black and color[left[w]] is black
			if(w->left->color==BLACK&&w->right->color==BLACK)
			{
				w->color=RED;
				x=x->p;
			}
			else
			{
				if(w->right->color==BLACK)//case 3 color[right[w]] is black and color[left[w]] is red
				{
					w->left->color=BLACK;
					w->color=RED;
					right_rotate(T,w);
					w=x->p->right;
				}
				//case 4 color[right[w]] is red 
				w->color=x->p->color;
				x->p->color=BLACK;
				w->right->color=BLACK;
				left_rotate(T,x->p);
				x=T;
			}
		}
		else
		{
			auto w=x->p->left;
			
			//case1,color[w] is red
			if(w->color==RED)
			{
				w->color=BLACK;
				x->p->color=RED;
				right_rotate(T,x->p);
				w=x->p->left;
			}
			
			//case2,color[w] is black and color[right[w]] is black and color[left[w]] is black
			if(w->right->color==BLACK&&w->left->color==BLACK)
			{
				w->color=RED;
				x=x->p;
			}
			else
			{
				if(w->left->color==BLACK)//case 3 color[right[w]] is black and color[left[w]] is red
				{
					w->right->color=BLACK;
					w->color=RED;
					left_rotate(T,w);
					w=x->p->left;
				}
				//case 4 color[right[w]] is red 
				w->color=x->p->color;
				x->p->color=BLACK;
				w->left->color=BLACK;
				right_rotate(T,x->p);
				x=T;
			}


		}
	}

}
void rb_tree_delete(shared_ptr<rb_tree>&T,shared_ptr<rb_tree>z)
{
	shared_ptr<rb_tree>y;
	if(z->right==NIL||z->left==NIL)y=z;
	else y=rb_tree_successor(z);

	shared_ptr<rb_tree>x;
	if(y->left!=NIL)x=y->left;
	else x=y->right;

	x->p=y->p;
	if(y->p==NIL)T=x;
	else if(y=y->p->left)y->p->left=x;
	else y->p->right=x;

	if(y!=z)
	{
		z->key=y->key;
		z->value=y->value;
	}

	if(y->color==BLACK)rb_delete_fixup(T,z);

}



int main()
{












	return 0;
}
