#include<iostream>
#include<fstream>
using namespace std;
void insert_sort(int A[],int p,int q)
{
	if(p==q)return ;
	
	insert_sort(A,p,q-1);
	
	int key=A[q],i=q-1;
	while(i>=0&&A[i]>key)
	{
		A[i+1]=A[i];
		i--;
	}
	A[i+1]=key;
}
int main()
{
	ifstream fin("randnum");
	int num=0,A[100005];
	
	while(fin>>A[num])
		num++;

	insert_sort(A,0,num-1);
	for(int i=0;i<num;++i)
		cout<<A[i]<<endl;

	return 0;
}
