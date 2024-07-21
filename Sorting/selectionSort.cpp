#include<iostream>
using namespace std;
void selectionSort( int array[], int size )
{
    for (int i = 0; i < size - 1;i++)
      {  int min = i;
          for (int j = i + 1; j < size;j++)
          if(array[j]<array[min]){
              min = j;

          }
          swap(array[min], array[i]);
      }
}
int main()
{
    int arr[10]={9,8,7,6,5,4,3,2,1,0};
    selectionSort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}

//space complexity ------is O(1)  because the only space being tsken is the variables hat we have created which is a constant space 
//time complexity ------- O(n^2) 
// outer loop is run from 0-----------n-1 
// inner loop is run from 0----------n
//n(n-1)/2=n^2-n  so time complexity is O(n^2)