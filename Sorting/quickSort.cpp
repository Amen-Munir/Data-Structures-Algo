#include<iostream>
using namespace std; 
int partion(int arr[], int s, int e)
{
    int piviot = arr[s];
    int count = 0;
    for (int i = s+1; i <=e;i++)
    {
        if(arr[i]<=piviot)
            count++;

    }
    int piviotIndex = s+ count;
    swap(arr[piviot], arr[s]);

    //left pay saray chotay ajain, right pay saray baray ajain
    int i = s, j = e;
    while(i<piviotIndex && j>piviotIndex)
    {
        while(arr[j]>arr[piviotIndex])
        {
            j--;
        }

        while(arr[i]<arr[piviotIndex])
        {
            i++;
        }
        if(i<piviotIndex && j>piviotIndex)
            {
                swap(arr[i++], arr[j--]);
            }
    }
    return piviotIndex;
}
void quickSort(int arr[], int statrtingIndex, int endingIndex)
{
    if(statrtingIndex>=endingIndex)
    {
        return;
    }
    
    int p = partion(arr, statrtingIndex, endingIndex);
    // call func for left side
    quickSort(arr, statrtingIndex, p - 1);
    // call for right side
    quickSort(arr, p + 1, endingIndex);
}
int main()
{
    int arr[10]={9,8,7,6,5,4,3,2,1, 0};
    int size = 10;
    quickSort(arr, 0, size-1);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}
// time complexity
// worst case O(n^2)
// best and average case O(nlog(n))