#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
const int NUM=1E5;
const int MAX=1000000;
int main()
{
	ofstream fout("randnum");
	srand((unsigned)time(NULL));

	for(int i=0;i<NUM;++i)	
	{
		fout<<rand()%MAX<<endl;		
	}
	return 0;
}
