#include<iostream>
using namespace std;
void BubbleSort(int array[], int n)
{
    for (int i = 1; i < n ;i++)
    {
        bool checkSwap = false;
        for (int j = 0; j <n-i; j++)
        {
            if(array[j]>array[j+1])
            {
                checkSwap = true;
                swap(array[j], array[j + 1]);
            }
            if(checkSwap==false)
            {
                break;
            }
        }
    }
}
int main()
{
    int arr[10]={9,8,7,6,5,4,3,2,1, 0};
    BubbleSort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}
//time complexity for average case if O(N^2) N IS THE SIZE OF ARRAY 
// BEST CASE: O(n) already sorted 
//worst case : reverse order O(n^2)