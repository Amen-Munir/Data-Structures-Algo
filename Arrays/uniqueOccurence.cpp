#include <iostream>
using namespace std;

int uniqueElement(int arr[], int size)
{
    int x = 0;
    for (int i = 0; i < size; i++) {
        x = x ^ arr[i];
    }
    return x;
}

bool uniqueOccurrences(int arr[], int size) {
    int occurrence[1000] = {0}; 
    for (int i = 0; i < size; i++) {
        occurrence[arr[i]]++;
    }

   
    for (int i = 0; i < 1000; i++) {
        if (occurrence[i] != 0) {
            cout << "Element " << i << " occurs " << occurrence[i] << " times." << endl;
        }
    }

   
    int occurrenceCounts[1000] = {0}; 
    for (int i = 0; i < 1000; i++) {
        if (occurrence[i] != 0) {
            occurrenceCounts[occurrence[i]]++;
        }
    }


    if (uniqueElement(occurrenceCounts, 1000) == 0) {
        return false;
    } else {
        return true ;
    }
}

int main()
{
    int array[3] = {1, 2, 2};

    if (uniqueOccurrences(array, 3)) {
        cout << "unique" << endl;
    } else {
        cout << "not unique" << endl;
    }

    return 0;
}
