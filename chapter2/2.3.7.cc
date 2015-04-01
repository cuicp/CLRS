#include<iostream>
#include<fstream>
#include "MERGE_SORT.h"
using namespace std;
int binary_search(int A[],int p,int q,int x)
{
	int low=p;
	int high=q;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(A[mid]==x)
		{
			return mid;
		}else if(A[mid]>x){
			high=mid-1;
		}else{
			low=mid+1;
		}
	}
	return -1;
}


int main()
{
	ifstream fin("randnum");
	int A[100005],num=0;

	while(fin>>A[num])
	{
		num++;
	}

	MERGE_SORT(A,0,num-1);
	
	int x=10000;
	for(int i=0;i<num;++i)
	{
		int index=binary_search(A,0,num-1,x-i);
		if(index!=-1){
			cout<<i<<' '<<A[index]<<endl;
			break;
		}
	}
	
	return 0;
}
