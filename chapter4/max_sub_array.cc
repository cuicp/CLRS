#include<iostream>
#include<vector>
using namespace std;
const int INF=100000000;
vector<int> find_max_crossing_subarray(int A[],int low,int mid,int high)
{
    int left_sum=-INF;
    int sum=0,max_left;
    
    for(int i=mid;i>=low;--i)
    {
        sum+=A[i];
        if(sum>left_sum)
        {
            left_sum=sum;
            max_left=i;
        }
    }
    
    int right_sum=-INF;
    int max_right;

    sum=0;
    for(int i=mid+1;i<=high;++i)
    {
        sum+=A[i];
        if(sum>right_sum)
        {
            right_sum=sum;
            max_right=i;
        }
    }
    
    vector<int>sol={max_left,max_right,left_sum+right_sum};
    return sol;
}

vector<int> find_max_subarray(int A[],int low,int high)
{
    if(low==high)
    {
        vector<int>sol={low,high,A[low]};
        return sol;
    }
    
    int mid=(low+high)/2;
    auto lhs=find_max_subarray(A,low,mid);
    auto rhs=find_max_subarray(A,mid+1,high);
    auto ms=find_max_crossing_subarray(A,low,mid,high);

    if(lhs[2]>rhs[2]&&lhs[2]>ms[2])return lhs;
    else if(rhs[2]>lhs[2]&&rhs[2]>ms[2])return rhs;
    else return ms;
}


int main()
{
    int a[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    auto solution=find_max_subarray(a,0,15);

    cout<<"left= "<<solution[0]<<endl;
    cout<<"right= "<<solution[1]<<endl;;
    cout<<"max_ssum= "<<solution[2]<<endl;

    return 0;
}
