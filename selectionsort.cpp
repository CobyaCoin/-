#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
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

    selectionSort(arr);

    for (const int& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}