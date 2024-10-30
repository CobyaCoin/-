#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;  
    }
}

int main() {
    ifstream inputFile("input.txt");
    vector<int> arr;
    int num;

    while (inputFile >> num) {
        arr.push_back(num);
    }
    inputFile.close();

    insertionSort(arr);

    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}