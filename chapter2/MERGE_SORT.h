#ifndef MERGE_SORT_H
#define MERGE_SORT_H
//将两个从小到大排好序的数组A[p~q]和A[q+1~r]合并成A[p~r]且A[p~r]由小到大排好序
const int INF=0x7fffffff;
void MERGE(int A[],int p,int q,int r)
{
	int n1=q-p+1;
	int n2=r-q;
	int a[n1+1],b[n2+1];
	
	for(int i=0;i<n1;++i)
		a[i]=A[p+i];
	for(int j=0;j<n2;++j)
		b[j]=A[q+1+j];
	a[n1]=INF;
	b[n2]=INF;

	int k1=0,k2=0;
	for(int i=p;i<=r;++i)
	{
		if(a[k1]<b[k2])
		{
			A[i]=a[k1];
			k1++;
		}
		else
		{
			A[i]=b[k2];
			k2++;
		}
	}
}

//将A[p~q]合并排序
void MERGE_SORT(int A[],int p,int q)
{
	if(p==q)return ;
	
	int mid=(p+q)/2;
	MERGE_SORT(A,p,mid);
	MERGE_SORT(A,mid+1,q);

	MERGE(A,p,mid,q);
	
}












#endif
