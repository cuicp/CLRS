#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
const int MAX_NUM=10005;
const int MAX_LEN=100000;

int A[MAX_LEN],B[MAX_LEN];

void counting_sort(int A[],int B[],int K=MAX_NUM)
{
    int C[K];
    memset(C,0,sizeof(C));
    for(int i=0;i<MAX_LEN;++i)
    {
        C[A[i]]++;
    }

    for(int i=1;i<K;++i)
        C[i]+=C[i-1];

    for(int i=MAX_LEN-1;i>=0;--i)
    {
        B[C[A[i]]-1]=A[i];
        C[A[i]]--;
    }

}


int main()
{
    ifstream fin("rand.txt");
    for(int i=0;i<MAX_LEN;++i)
    {
        fin>>A[i];
    }
    counting_sort(A,B);
    
    for(int i=0;i<MAX_LEN;++i)
        cout<<B[i]<<endl;

    return 0;
}
