#include<iostream>
using namespace std;
void mergeArrays(int arr[], int s, int e)
{ // xalculate lengths of two arrays
    int mid = (s + e) / 2;
    int lengthOfFirst = mid - s + 1;
    int lenghthOfSecond = e - mid;
           // create new arrays
    int *first = new int[lengthOfFirst];
    int *second = new int[lenghthOfSecond];

// copy value from main array to this array
    int mainIndex = s;
    for (int i = 0; i <lengthOfFirst ;i++)
    {
        first[i]=arr[mainIndex++];

    }
 mainIndex = mid+1;
     for (int i = 0; i <lenghthOfSecond ;i++)
    {
        second[i]=arr[mainIndex++];
        
    }
    // merge copied arrays in sorted order
    int index1 = 0;
    int index2 = 0;
    mainIndex=s;
    
    while (index1<lengthOfFirst && index2< lenghthOfSecond)
    {
        if(first[index1]<second[index2])
    {
        arr[mainIndex++] = first[index1++];
    }
    else
    {
        arr[mainIndex++] = second[index2++];
    }
    }

    // maube lengths are different 
    while(index1<lengthOfFirst)
    {
         arr[mainIndex++] = first[index1++];
    }

     while(index2<lenghthOfSecond)
    {
     arr[mainIndex++] = second[index2++];
    }
    
}
void mergeSort(int arr[], int start, int end)
{
   // base case 
   if(start>=end)
   {
       return;
   }

   // mid
   int mid = (start + end) / 2;
   // recursive call for first half
   mergeSort(arr, start, mid );
    // recursive call for second half
   mergeSort(arr, mid + 1, end);

   // sorted arrays ko merge kardo
   mergeArrays(arr, start, end);
}
int main()
{
    int arr[11]={9,8,7,6,5,4,3,2,1, 0,10};
    int size = 11;
    mergeSort(arr, 0, size-1);
    for (int i = 0; i < 11; i++)
    {
        cout << arr[i] << " ";
    }
}