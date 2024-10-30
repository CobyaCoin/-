# Все сортировки для группы ЕГ на c++
только не переписывайте 1 в 1




компилировать можно прямо в гдб, просто нажми создать файл ==> input.txt


# Пузырек
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
# Вставки
```cpp
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
```
