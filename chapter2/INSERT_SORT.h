#ifndef INSERT_SORTH
#define INSERT_SORTH
//将数组A按照从小到大的顺序排序
void INSERT_SORT(int A[],int p,int q)
{
	for(int i=p+1;i<=q;++i)
	{
		int j=i-1;
		int key=A[i];
		while(A[j]>key&&j>=p)
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=key;
	}
}

#endif
