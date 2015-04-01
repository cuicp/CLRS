#include<iostream>
#include<fstream>
using namespace std;
void merge(int A[],int p,int q,int r)
{
	int n1=q-p+1;
	int n2=r-q;

	int a[n1],b[n2];
	for(int i=0;i<n1;++i)
		a[i]=A[p+i];
	for(int i=0;i<n2;++i)
		b[i]=A[q+1+i];
	
	int k1=0,k2=0;
	for(int i=p;i<=r;++i)
	{
		if(k1==n1)
		{
			break;
		}else if(k2==n2){
			for(;k1<n1;++k1)
			{
				A[i++]=a[k1];
			}
			break;
		}else{
			if(a[k1]<b[k2])
			{
				A[i]=a[k1];
				k1++;
			}else{
				A[i]=b[k2];
				k2++;
			}
		}
	}
}


void merge_sort(int A[],int p,int q)
{
	if(p==q)return ;
	int mid=(p+q)/2;
	merge_sort(A,p,mid);
	merge_sort(A,mid+1,q);
	merge(A,p,mid,q);
}
int main()
{
	ifstream fin("randnum");

	int num=0;
	int A[1000000];

	while(fin>>A[num])
		num++;
	
	merge_sort(A,0,num-1);

	for(int i=0;i<num;++i)
		cout<<A[i]<<endl;


	return 0;
}
