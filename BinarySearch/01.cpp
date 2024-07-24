#include <iostream>
#include <vector>
using namespace std;

vector<int> FindFirstAndLastIndex(vector<int> array, int key) {
    int startIndex = -1, endIndex = -1;
    int s = 0;
    int e = array.size() - 1;

  
    while (s <= e) {
        int mid = s + ((e - s) / 2);
        if (array[mid] == key) {
            startIndex = mid;
            e = mid - 1;
        } else if (key > array[mid]) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    s = 0;
    e = array.size() - 1;

    while (s <= e) {
        int mid = s + ((e - s) / 2);
        if (array[mid] == key) {
            endIndex = mid;
            s = mid + 1;
        } else if (key > array[mid]) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    vector<int> res;
    res.push_back(startIndex);
    res.push_back(endIndex);
    return res;
}

int main() {
    vector<int> test = {1, 2, 2, 3, 4};
    vector<int> res = FindFirstAndLastIndex(test, 2);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}
//time complexity O(lgn)
//space complexity O(1)