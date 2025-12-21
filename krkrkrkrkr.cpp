#include <iostream>
#include <cmath>

using namespace std;

int sumEvenIndices(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i += 2) {
        sum += arr[i];
    }
    return sum;
}

void replaceNegativesWithZero(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            arr[i] = 0;
        }
    }
}

int findMin(const int arr[], int size);

int linearSearch(const int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(const int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void bubbleSortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i -1; j++) {
            if (arr[j] < arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size -1; i++) {
        int min_idx = i;
        for (int j = i+1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i -1;
        while (j >=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int sumMainDiagonal(int arr[5][5]) {
    int sum = 0;
    for (int i=0; i<5; i++) {
        sum += arr[i][i];
    }
    return sum;
}

void maxInRows(int arr[4][4]) {
    for (int i=0; i<4; i++) {
        int maxVal = arr[i][0];
        for (int j=1; j<4; j++) {
            if (arr[i][j] > maxVal) maxVal = arr[i][j];
        }
        cout << "Max in row " << i << ": " << maxVal << endl;
    }
}

void staticCounter() {
    static int count = 0;
    count++;
    cout << "Counter: " << count << endl;
}

int globalVar = 100;

void scopeTest() {
    int globalVar = 50;
    cout << "Local globalVar: " << globalVar << endl;
    cout << "Global globalVar: " << ::globalVar << endl;
}

auto average(const int arr[], int size) -> double {
    int sum = 0;
    for (int i=0; i<size; i++) {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}

void printChar(char c='*', int count=10) {
    for (int i=0; i<count; i++) {
        cout << c;
    }
    cout << endl;
}

inline int maxOfTwo(int a, int b) {
    return (a > b) ? a : b;
}

void print(int a) {
    cout << "int: " << a << endl;
}
void print(double a) {
    cout << "double: " << a << endl;
}
void print(const int arr[], int size) {
    cout << "Array: ";
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void transpose(int arr[3][3]) {
    for (int i=0; i<3; i++) {
        for (int j=i+1; j<3; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

double sum(double a=0, double b=0) {
    return a + b;
}

double sum(const int arr[], int size) {
    double total=0;
    for (int i=0; i<size; i++) {
        total += arr[i];
    }
    return total;
}

int main() {
    const int size1 = 10;
    int arr1[size1];
    cout << "Enter 10 integers:" << endl;
    for (int i=0; i<size1; i++) {
        cin >> arr1[i];
    }
    cout << "Array: ";
    int sumPositive = 0;
    for (int i=0; i<size1; i++) {
        cout << arr1[i] << " ";
        if (arr1[i] > 0) sumPositive += arr1[i];
    }
    cout << "\nSum of positive elements: " << sumPositive << endl;

    cout << "Sum of elements at even indices: " << sumEvenIndices(arr1, size1) << endl;

    replaceNegativesWithZero(arr1, size1);
    cout << "Array after replacing negatives with zeros: ";
    for (int i=0; i<size1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "Minimum element in array: " << findMin(arr1, size1) << endl;

    int key;
    cout << "Enter number to search linearly: ";
    cin >> key;
    int index = linearSearch(arr1, size1, key);
    cout << "Found at index: " << index << endl;

    selectionSort(arr1, size1);
    cout << "Sorted array for binary search: ";
    for (int i=0; i<size1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    cout << "Enter number for binary search: ";
    cin >> key;
    int binIndex = binarySearch(arr1, size1, key);
    cout << "Binary search result: " << binIndex << endl;

    int arrBubble[10] = {5, 2, 9, 1, 5, 6, 3, 2, 8, 7};
    bubbleSortDescending(arrBubble, 10);
    cout << "Array after bubble sort descending: ";
    for (int i=0; i<10; i++) {
        cout << arrBubble[i] << " ";
    }
    cout << endl;

    int arrSel[10] = {64, 25, 12, 22, 11};
    selectionSort(arrSel, 5);
    cout << "Array after selection sort: ";
    for (int i=0; i<5; i++) {
        cout << arrSel[i] << " ";
    }
    cout << endl;

    int arrInsert[6] = {12, 11, 13, 5, 6};
    insertionSort(arrInsert, 5);
    cout << "Array after insertion sort: ";
    for (int i=0; i<5; i++) {
        cout << arrInsert[i] << " ";
    }
    cout << endl;

    int matrix[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    cout << "Sum of main diagonal of 5x5: " << sumMainDiagonal(matrix) << endl;

    int arr4x4[4][4] = {
        {3, 5, 1, 9},
        {2, 8, 7, 4},
        {6, 0, 3, 2},
        {1, 4, 9, 5}
    };
    maxInRows(arr4x4);

    staticCounter();
    staticCounter();
    staticCounter();

    scopeTest();

    int arrAve[5] = {1, 2, 3, 4, 5};
    cout << "Average: " << average(arrAve, 5) << endl;

    printChar();
    printChar('#', 5);

    cout << "Max of 10 and 20: " << maxOfTwo(10, 20) << endl;

    print(42);
    print(3.1415);
    print(arrAve, 5);

    int matrix3x3[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    transpose(matrix3x3);
    cout << "Transposed 3x3 matrix:" << endl;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cout << matrix3x3[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Sum of 3.5 and 4.5: " << sum(3.5, 4.5) << endl;
    int arrSum[4] = {1, 2, 3, 4};
    cout << "Sum of array elements: " << sum(arrSum, 4) << endl;
    cout << "Sum with default arguments: " << sum() << endl;

    int bigArr[15] = {23, 5, 67, 89, 12, 45, 78, 34, 56, 90, 11, 3, 99, 100, 1};
    selectionSort(bigArr, 15);
    int target;
    cout << "Enter number to search: ";
    cin >> target;
    int res = binarySearch(bigArr, 15, target);
    if (res != -1)
        cout << "Element found at position: " << res << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}

int findMin(const int arr[], int size) {
    int minVal = arr[0];
    for (int i=1; i<size; i++) {
        if (arr[i] < minVal)
            minVal = arr[i];
    }
    return minVal;
}
