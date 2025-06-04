#include <iostream>
using namespace std;

void fibo(int n, int a = 0, int b = 1) {
    if (n > 0) {
        cout << a << " ";
        fibo(n - 1, b, a + b);
    }
}

void rev(int arr[], int index) {
    if (index >= 0) {
        cout << arr[index] << " ";
        rev(arr, index - 1);
    }
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectsort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    cout << "Question 1\n";
    fibo(10);
    cout << "\n\n";

    cout << "Question 2\n";
    int array[] = {1, 2, 3, 4, 5};
    int arraySize = sizeof(array) / sizeof(array[0]);
    rev(array, arraySize - 1);
    cout << "\n\n";

    cout << "Question 3\n";
    int rollNumbers[] = {34, 12, 25, 8, 22};
    int rollNumbersSize = sizeof(rollNumbers) / sizeof(rollNumbers[0]);
    bubbleSort(rollNumbers, rollNumbersSize);
    for (int i = 0; i < rollNumbersSize; i++) {
        cout << rollNumbers[i] << " ";
    }
    cout << "\n\n";

    cout << "Question 4\n";
    int rollNumbers2[] = {45, 23, 15, 9, 30};
    int rollNumbers2Size = sizeof(rollNumbers2) / sizeof(rollNumbers2[0]);
    bubbleSort(rollNumbers2, rollNumbers2Size);
    for (int i = 0; i < rollNumbers2Size; i++) {
        cout << rollNumbers2[i] << " ";
    }
    cout << "\n\n";

    cout << "Question 5\n";
    int ages[] = {16, 12, 18, 14, 10};
    int agesSize = sizeof(ages) / sizeof(ages[0]);
    selectsort(ages, agesSize);
    for (int i = 0; i < agesSize; i++) {
        cout << ages[i] << " ";
    }
    cout << "\n\n";

    cout << "Question 6\n";
    int marks[] = {78, 45, 89, 56, 67};
    int marksSize = sizeof(marks) / sizeof(marks[0]);
    selectsort(marks, marksSize);
    for (int i = 0; i < marksSize; i++) {
        cout << marks[i] << " ";
    }
    cout << "\n";

    return 0;
}
