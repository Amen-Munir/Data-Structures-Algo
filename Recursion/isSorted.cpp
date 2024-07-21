#include<iostream>
using namespace std;
bool IsSorted(int arr[],int size)
{
   if(size==1)
       return true;
 else if (arr[0]>arr[1])
      return false;
 else
 return IsSorted(arr+1,size-1);
        
        }
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int size = 10;
    cout<<IsSorted(arr,size);
}