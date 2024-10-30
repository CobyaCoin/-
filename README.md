# Все сортировки для группы ЕГ на c++
только не переписывайте 1 в 1




компилировать можно прямо в гдб, просто нажми создать файл ==> input.txt


#Пузырек
```cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> 

using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
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

    bubbleSort(arr);

    for (const int& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```
