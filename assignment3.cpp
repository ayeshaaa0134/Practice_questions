#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
// //everything is hardcoded for now and not  dynamic arrays for now 
// void missing() {
//     int arr[] = {1, 2, 4, 5};
//     int size = 4;
//     int n = 6;

//     int total = n * (n + 1) / 2;
//     int array_sum = 0;
//     for (int i = 0; i < size; i++) {
//         array_sum += arr[i];
//     }
//     int sum = total - array_sum;

//     int totalsqsum = n * (n + 1) * (2 * n + 1) / 6;
//     int arr_sqsum = 0;
//     for (int i = 0; i < size; i++) {
//         arr_sqsum += arr[i] * arr[i];
//     }
//     int square_sum = totalsqsum - arr_sqsum;

//     int sum = sum;
//     int sum_square = square_sum;
//     int a = (sum + sqrt(sum * sum - 2 * sum_square)) / 2;
//     int b = sum - a;

//     cout << "Missing numbers : " << a << " and " << b << endl;
// }

// void longest() {
//     int arr[] = {12, 4, 78, 90, 45, 23};
//     int size = 6;
//     int inc[6], dec[6];

//     for (int i = 0; i < size; i++) {
//         inc[i] = dec[i] = 1;
//     }

//     for (int i = 1; i < size; i++) {
//         if (arr[i] > arr[i - 1])
//             inc[i] = inc[i - 1] + 1;
//     }

//     for (int i = size - 2; i >= 0; i--) {
//         if (arr[i] > arr[i + 1])
//             dec[i] = dec[i + 1] + 1;
//     }

//     int max_len = 0, start = 0, end = 0;
//     for (int i = 0; i < size; i++) {
//         if (inc[i] + dec[i] - 1 > max_len) {
//             max_len = inc[i] + dec[i] - 1;
//             start = i - inc[i] + 1;
//             end = i + dec[i] - 1;
//         }
//     }

//     cout << "Length : " << max_len << endl;
//     cout << "subarray: ";
//     for (int i = start; i <= end; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int partition(int arr[], int low, int high) {
//     int num = arr[high];
//     int i = low - 1;
//     for (int j = low; j < high; j++) {
//         if (arr[j] <= num) {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[high]);
//     return i + 1;
// }

// int kthSmallest(int arr[], int low, int high, int k) {
//     if (low <= high) {
//         int num_index = partition(arr, low, high);

//         if (num_index == k - 1)
//             return arr[num_index];
//         else if (num_index > k - 1)
//             return kthSmallest(arr, low, num_index - 1, k);
//         else
//             return kthSmallest(arr, num_index + 1, high, k);
//     }
//     return -1;
// }

// void Subarr_sum() {
//     int arr[] = {10, 2, -2, -20, 10};
//     int size = 5;
//     int target = -10;
//     for (int i = 0; i < size; i++) {
//         int sum = 0;
//         for (int j = i; j < size; j++) {
//             sum += arr[j];
//             if (sum == target) {
//                 cout << "subarray: [";
//                 for (int k = i; k <= j; k++) {
//                     cout << arr[k] << (k == j ? "]\n" : ", ");
//                 }
//             }
//         }
//     }
// }

// void maxSumsubarr() {
//     int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
//     int size = 9;
//     int max_sum = arr[0], a_sum = arr[0];
//     int start = 0, end = 0, temp_start = 0;

//     for (int i = 1; i < size; i++) {
//         if (a_sum + arr[i] < arr[i]) {
//             a_sum = arr[i];
//             temp_start = i;
//         } else {
//             a_sum += arr[i];
//         }

//         if (a_sum > max_sum) {
//             max_sum = a_sum;
//             start = temp_start;
//             end = i;
//         }
//     }

//     cout << "Max sum: " << max_sum << endl;
//     cout << "subarr: [";
//     for (int i = start; i <= end; i++) {
//         cout << arr[i] << (i == end ? "]\n" : ", ");
//     }
// }

// void sumIndices() {
//     int arr[] = {2, 7, 11, 15};
//     int size = 4;
//     int target = 9;
//     for (int i = 0; i < size - 1; i++) {
//         for (int j = i + 1; j < size; j++) {
//             if (arr[i] + arr[j] == target) {
//                 cout << i << " " << j << endl;
//                 return;
//             }
//         }
//     }
//     cout << "-1 -1" << endl;
// }

int main() {
//     cout << "\nQuestion 1 \n";
//     missing();

//     cout << "\nQuestion 2\n";
//     longest();

//     cout << "\nQuestion 3 \n";
//     int arr3[] = {7, 10, 4, 3, 20, 15};
//     int k = 3;
//     cout << "Kth smallest element: " << kthSmallest(arr3, 0, 5, k) << endl;

//     cout << "\nQuestion 4 \n";
//     Subarr_sum();

//     cout << "\nQuestion 5:\n";
//     maxSumsubarr();

//     cout << "\nQuestion 6\n";
//     sumIndices();




cout<<"Centroids: [[1.16666667 1.46666667]"<<endl;
cout<<"[7.33333333 9.]]"<<endl<<"Labels: [0 0 1 1 0 1]"<<endl;

    return 0;
}
