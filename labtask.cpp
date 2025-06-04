5
#include <iostream>
using namespace std;

void updatearr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] += 10;
    }
}

void printarr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findMax(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int findMin(int arr[], int size) {
    int minVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

void cntEO() {
    cout << "Question 1\n";
    const int SIZE = 7;
    int arr[SIZE];
    int even = 0, odd = 0;

    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
        if (arr[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    cout << "Even numbers: " << even << "\n";
    cout << "Odd numbers: " << odd << "\n";
}

void search() {
    cout << "Question 2\n";
    const int SIZE = 5;
    int arr[SIZE];
    int value;

    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }

    cin >> value;

    bool found = false;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] == value) {
            cout << "Number found at position: " << i << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Number not found.\n";
    }
}

void revers() {
    cout << "Question 3\n";
    const int SIZE = 5;
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }

    for (int i = SIZE - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void coutOcc() {
    cout << "Question 4\n";
    const int SIZE = 8;
    int arr[SIZE];
    int value, count = 0;

    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }

    cin >> value;

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] == value) {
            count++;
        }
    }

    cout << "The number " << value << " occurs " << count << " times.\n";
}

void otherOps() {
    cout << "Question 5\n";
    const int SIZE = 5;
    int arr[SIZE] = {1, 2, 3, 4, 5};

    cout << "Original arr: ";
    printarr(arr, SIZE);

    updatearr(arr, SIZE);
    cout << "Updated arr: ";
    printarr(arr, SIZE);

    int maxVal = findMax(arr, SIZE);
    int minVal = findMin(arr, SIZE);

    cout << "Maximum value in the arr: " << maxVal << "\n";
    cout << "Minimum value in the arr: " << minVal << "\n";

    int arrSum = 0;
    for (int i = 0; i < SIZE; i++) {
        arrSum += arr[i];
    }
    cout << "Sum of arr elements: " << arrSum << "\n";
}

void addarrs() {
    cout << "Question 6\n";
    const int SIZE = 5;
    int arr1[SIZE], arr2[SIZE], arrSum[SIZE];

    cout << "Enter elements of the first arr:\n";
    for (int i = 0; i < SIZE; i++) {
        cin >> arr1[i];
    }

    cout << "Enter elements of the second arr:\n";
    for (int i = 0; i < SIZE; i++) {
        cin >> arr2[i];
    }

    for (int i = 0; i < SIZE; i++) {
        arrSum[i] = arr1[i] + arr2[i];
    }

    cout << "First arr: ";
    printarr(arr1, SIZE);
    cout << "Second arr: ";
    printarr(arr2, SIZE);
    cout << "Sum arr: ";
    printarr(arrSum, SIZE);
}

int main() {
    cout << "Ok so which question you want to solve today:\n";
    cout << "1. Count Even and Odd Numbers\n";
    cout << "2. Search for a Number in an arr\n";
    cout << "3. Reverse an arr\n";
    cout << "4. Count the Occurrences of a Number\n";
    cout << "5. Demonstrate Other arr Operations\n";
    cout << "6. Add Two arrs\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cntEO();
    } else if (choice == 2) {
        search();
    } else if (choice == 3) {
        revers();
    } else if (choice == 4) {
        coutOcc();
    } else if (choice == 5) {
        otherOps();
    } else if (choice == 6) {
        addarrs();
    } else {
        cout << "Invalid option. Exiting.\n";
    }

    return 0;
}
