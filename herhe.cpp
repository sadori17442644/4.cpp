#include <iostream>
#include <algorithm>

auto square(int x) -> int {
    return x * x;
}

auto min(int a, int b) -> int {
    return (a < b) ? a : b;
}

int globalVar = 100;

void showVariables() {
    int localVar = 50;
    std::cout << "Global: " << globalVar << ", Local: " << localVar << std::endl;
}

void counterFunction() {
    static int counter = 0;
    counter++;
    std::cout << "Counter: " << counter << std::endl;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int sum(int a, int b);

void print2DArray(int arr[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void modifyArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] += 5;
    }
}

extern int externalVar;

void showExternal() {
    std::cout << "External var: " << externalVar << std::endl;
}

auto arraySum(int arr[], int size) -> int {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

int countEven(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int diagonalSum(int arr[4][4]) {
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        sum += arr[i][i];
    }
    return sum;
}

double average(int arr[], int size);

double average(int arr[], int size) {
    if (size == 0) return 0.0;
    return static_cast<double>(arraySum(arr, size)) / size;
}

int counter = 0;

void incrementCounter() {
    counter++;
}

void printCounter() {
    std::cout << "Counter value: " << counter << std::endl;
}

void fillArray(int (&arr)[6]) {
    for (int i = 0; i < 6; ++i) {
        arr[i] = i * 10;
    }
}
void zeroBelowDiagonal(int arr[3][3]) {
    for (int i = 1; i < 3; ++i) {
        for (int j = 0; j < i; ++j) {
            arr[i][j] = 0;
        }
    }
}

auto maxIndex(int arr[], int size) -> int {
    if (size == 0) return -1;
    int maxIdx = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[maxIdx]) {
            maxIdx = i;
        }
    }
    return maxIdx;
}

int sameNameVar = 1000;

void demonstrateScope() {
    int sameNameVar = 2000;
    std::cout << "Local sameNameVar: " << sameNameVar << std::endl;
    std::cout << "Global sameNameVar: " << ::sameNameVar << std::endl;
}

void transposeMatrix(int arr[3][3]) {
    int temp[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            temp[j][i] = arr[i][j];
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            arr[i][j] = temp[i][j];
        }
    }
}

auto countAboveAverage(int arr[], int size) -> int;

auto countAboveAverage(int arr[], int size) -> int {
    double avg = average(arr, size);
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > avg) {
            count++;
        }
    }
    return count;
}

int main() {
    std::cout << "Square of 5: " << square(5) << std::endl;
    std::cout << "Min of 10 and 7: " << min(10, 7) << std::endl;
    showVariables();
    counterFunction();
    counterFunction();
    counterFunction();

    int arr[] = {1, 2, 3, 4, 5};
    printArray(arr, 5);
    modifyArray(arr, 5);
    printArray(arr, 5);

    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    print2DArray(matrix);

    externalVar = 42;
    showExternal();

    std::cout << "Array sum: " << arraySum(arr, 5) << std::endl;
    std::cout << "Even count: " << countEven(arr, 5) << std::endl;

    int matrix4x4[4][4] = {{1,0,0,0}, {0,2,0,0}, {0,0,3,0}, {0,0,0,4}};
    std::cout << "Diagonal sum: " << diagonalSum(matrix4x4) << std::endl;

    std::cout << "Average: " << average(arr, 5) << std::endl;

    incrementCounter();
    incrementCounter();
    printCounter();

    int fillArr[6];
    fillArray(fillArr);
    printArray(fillArr, 6);

  
    zeroBelowDiagonal(matrix);
    print2DArray(matrix);

    std::cout << "Max index: " << maxIndex(arr, 5) << std::endl;

    demonstrateScope();

    transposeMatrix(matrix);
    print2DArray(matrix);

    std::cout << "Above average count: " << countAboveAverage
