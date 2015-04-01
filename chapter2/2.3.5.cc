#include<iostream>
#include<fstream>
#include "MERGE_SORT.h"
using namespace std;
int binary_search(int A[],int p,int q,int x)
{
	int low =p;
	int high=q;

	while(low<=high)
	{
		int mid=(low+high)/2;
		if(A[mid]==x){
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
	int num=0,A[100005];
	
	while(fin>>A[num])
	{
		num++;
	}
	
	MERGE_SORT(A,0,num-1);
	int a=binary_search(A,0,num-1,999998);
	if(a!=-1)cout<<A[a]<<endl;

	return 0;
}
