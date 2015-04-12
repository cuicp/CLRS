//此程序是错误的，将sort换成一个稳定排序算法就对了





#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
const int MAX_NUM_LEN=4;
const int MAX_LEN=100;

void radix_sort(int A[],int len=MAX_LEN)
{
    for(int i=0;i<MAX_NUM_LEN;++i)
    {
        sort(A,A+len,
             [i](int a,int b)
             {
                auto sa=to_string(a);
                auto sb=to_string(b);
                if(sa.size()<i+1)return false;
                else if(sb.size()<i+1)return true;
                else return sa[i]>sb[i];
             }
            );
    }
}
int main()
{
    ifstream fin("rand.txt");
    int A[MAX_LEN];
    for(int i=0;i<MAX_LEN;++i)
        fin>>A[i];
    radix_sort(A);
    for(int i=0;i<MAX_LEN;++i)
        cout<<A[i]<<endl;

    return 0;
}
