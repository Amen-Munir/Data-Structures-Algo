#include<iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n;i++)
    {
        int temp=arr[i];
        int j = i - 1;
        for (; j >= 0 ;j--)
        {
            //if element is less then shift others to right 
            if(temp<arr[j])
                arr[j + 1] = arr[j]; // usko left pay rakhwa do 
            else //agar bara agya hay tu bahir ajao
                break;
        }
        arr[j + 1] = temp; // element ko right pay rakhwa do 
    }
}
int main()
{
    int arr[10]={9,8,7,6,5,4,3,2,1,0};
    insertionSort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}

// time complexity
//O(N^2) WORST CASE
// O(N) BEST CASE 