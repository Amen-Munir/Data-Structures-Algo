#include<iostream>
using namespace std;
void TowerOfHanoi(int starting, int end, char src, char middle,char dest)
{
    if(end<starting)
    {
        return;
    }
    else
     TowerOfHanoi(starting,end-1,src,dest,middle);
    cout<<"move disk "<<end<<" from "<<src<<" to "<<dest<<endl;
     TowerOfHanoi(starting,end-1,middle,src,dest);
}
int main()
{
        TowerOfHanoi(1,3,'A','B','C');
}