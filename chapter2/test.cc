#include<iostream>
#include<fstream>
#include "INSERT_SORT.h"
#include "MERGE_SORT.h"
using namespace std;
const int MAX_NUM=1E5;
int main()
{
	ifstream fin("randnum");
	int A[MAX_NUM],num=0;
	while(fin>>A[num])
	{
		num++;
	}

	MERGE_SORT(A,0,num-1);
	for(int i=0;i<num;++i)
	{
		cout<<A[i]<<endl;
	}

	return 0;
}
