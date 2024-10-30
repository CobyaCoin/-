#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }
        
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        
        while (j <= right) {
            temp[k++] = arr[j++];
        }

        for (i = left, k = 0; i <= right; i++, k++) {
            arr[i] = temp[k];
        }
    }
}

int main() {
    ifstream inputFile("input.txt");
    vector<int> arr;
    int number;

    while (inputFile >> number) {
        arr.push_back(number);
    }

    inputFile.close();

    mergeSort(arr, 0, arr.size() - 1);

    for (const int& num : arr) {
        cout << num << " ";
    }
    
    return 0;
}