#include<iostream>
#include <vector>
using namespace std;

// 1 to some number and only one duplicate 
vector<int> Duplicates(int arr[], int size) 
{

vector<int> temp;
    for (int i = 0; i < size;i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if(arr[i]==arr[j])
            {
                temp.push_back(arr[i]);
            }
        }
    }
    return temp;
}
int main()
{
    int array[5]={1,3,3,4,4};
    vector<int> res; 
 res= Duplicates(array, 5);
for (auto i = res.begin(); i != res.end(); ++i)
        cout << *i << " ";
}