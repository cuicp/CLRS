#include"rbtree"
int main()
{
    shared_ptr<rb_tree>T=NIL;
    for(int i=0;i<10;++i)
    {
        rb_tree_insert(T,make_shared<rb_tree>(rand()%1000,0));
    }

    output(T);
    
    cout<<"input the element you will delete"<<endl;
    int del;
    cin>>del;
    auto delnode=rb_tree_search(T,del);
    if(delnode!=NIL)
    {
         rb_tree_delete(T,delnode);
        output(T);
    }
    else
    {
        cout<<"the element you want delete is not in the tree"<<endl;
    }

    cout<<"input the elemeny whose seccessor you want"<<endl;
    int suc;
    cin>>suc;
    if(delnode!=NIL)
    {
        auto sucnode=rb_tree_search(T,suc);
        cout<<rb_tree_successor(sucnode)->key<<endl;
    }
    else
    {
        cout<<"the element you inputed has not successor"<<endl;
    }
	return 0;
}
