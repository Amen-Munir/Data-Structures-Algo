#include<iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;
void printArray(int arr[], int size)
{
  for (int i = 0; i < size ;i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    const int size = 11;
    int *inputArray=new int[size];
      srand(time(0));
    for (int i = 0; i < size ;i++)
    { 
       inputArray[i]=rand() % 100;
    }

    printArray(inputArray, size);

    for (int i = 0; i < size; i += 2)
    {
        if(i+1<size)
        {
            swap(inputArray[i],inputArray[i+1]);
        }

    }

    cout << endl;
    printArray(inputArray, size);
   
}
