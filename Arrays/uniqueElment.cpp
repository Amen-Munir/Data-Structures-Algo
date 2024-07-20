#include<iostream>
using namespace std;
int uniqueElement(int arr[], int size) //xor method 
{
    int x = 0;
    for (int i = 0; i < size;i++)
    {
        x = x ^ arr[i];

    }
    return x;
}
int main()
{   
    bool twice = false;
    int m = 4;
    int size = 2 * m + 1;
    int inputArray[9] = {1, 2, 3,4, 1, 2, 3,4,7};
    cout << uniqueElement(inputArray, size) <<endl;
 //-----------------------this code has a time complexity of O(n^2) to reduce complexity to constatnt we can use xor method //
//     for (int i = 0; i < size; i++)
//     {    bool twice = false;
//         int current = inputArray[i];
//         for (int j = 0; j < size; j++)
//         {
//             if ((current == inputArray[j]) && (i != j))
//             {
//                 twice = true;
//                 break;
//             }
//         }
//         if (twice == false)
//         {
//             cout << "unique element is " << inputArray[i];
//         }
//   }
}

// we have an array in of size 2m+1 when m is the number of elements and each element is repeated twice and one element is unique 
// eg m=3
// size= 2x3+1=7
//array= [1,2,3,1,2,3,4] 4 is unique 
// find 4 