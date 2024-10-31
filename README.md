# Все сортировки для группы ЕГ на c++
только не переписывайте 1 в 1




компилировать можно прямо в гдб, просто нажми создать файл ==> input.txt


# Пузырек
```cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> 
#include <time.h>

using namespace std;

double bubbleSort(vector<int>& arr) {
    time_t start, end;
    time(&start);
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    
    time(&end);
    double seconds = difftime(end, start);
    return seconds;
}

int main() {
    ifstream inputFile("input.txt");


    vector<int> arr;
    int number;
    double timecount;

    while (inputFile >> number) {
        arr.push_back(number);
    }

    inputFile.close();

    timecount = bubbleSort(arr);

    for (const int& num : arr) {
        cout << num << " ";
    }
    cout << endl;
    cout << timecount;

    return 0;
}
```
# Вставки
```cpp
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

double insertionSort(vector<int>& arr) {
    time_t start, end;
    time(&start);
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
    time(&end);
    double seconds = difftime(end, start);
    return seconds;
}

int main() {
    ifstream inputFile("input.txt");
    vector<int> arr;
    int num;
    double alltime;

    while (inputFile >> num) {
        arr.push_back(num);
    }
    inputFile.close();

    alltime = insertionSort(arr);

    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    cout << alltime;

    return 0;
}
```

#  Слияния

```cpp
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

double mergeSort(vector<int>& arr, int left, int right) {
    time_t start, end;
    time(&start);
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
    time(&end);
    double seconds = difftime(end, start);
    return seconds;
}

int main() {
    ifstream inputFile("input.txt");
    vector<int> arr;
    int number;
    double alltime;

    while (inputFile >> number) {
        arr.push_back(number);
    }

    inputFile.close();

    alltime = mergeSort(arr, 0, arr.size() - 1);

    for (const int& num : arr) {
        cout << num << " ";
    }
    cout << endl << alltime;
    
    return 0;
}
```

# Выбором
```cpp
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
```
