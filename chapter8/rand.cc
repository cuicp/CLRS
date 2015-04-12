#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
    ofstream fout("rand.txt");
    
    srand(time(NULL));

    for(int i=0;i<100000;++i)
    {
        fout<<rand()%10000<<endl;
    }




    return 0;
}
