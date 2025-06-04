#include <iostream>
#include <cmath>
using namespace std;


int sum_k_1_to_5() {
    int sum = 0;
    for (int k = 1; k <= 5; k++) {
        sum += k;
    }
    return sum;
}


int sum_k_1_to_7() {
    int sum = 0;
    for (int k = 1; k <= 7; k++) {
        sum += k;
    }
    return sum;
}


int sum_k_1_to_5_times_3() {
    return sum_k_1_to_5() * 3;
}


int fact(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int sum_fact_k_1_to_5() {
    int sum = 0;
    for (int k = 1; k <= 5; k++) {
        sum += fact(k);
    }
    return sum;
}


int sum_fact_k_1_to_7() {
    int sum = 0;
    for (int k = 1; k <= 7; k++) {
        sum += fact(k);
    }
    return sum;
}


int sum_fact_k_1_to_5_times_3_sum_k_1_to_n(int n) {
    int inner_sum = 0;
    for (int k = 1; k <= n; k++) {
        inner_sum += k;
    }
    return sum_fact_k_1_to_5() * 3 * inner_sum;
}


int sum_fact_k_1_to_n(int n) {
    int sum = 0;
    for (int k = 1; k <= n; k++) {
        sum += fact(k);
    }
    return sum;
}


int nested_sum_j_1_to_5_k_1_to_3() {
    int sum = 0;
    for (int j = 1; j <= 5; j++) {
        for (int k = 1; k <= 3; k++) {
            sum += j;
        }
    }
    return sum;
}


double nested_sum_j_1_to_2_k_1_to_3_divided_by_j() {
    double sum = 0.0;
    for (int j = 1; j <= 2; j++) {
        for (int k = 1; k <= 3; k++) {
            sum += (1.0 / j);
        }
    }
    return sum;
}


int nested_fact_sum_j_1_to_2_k_1_to_2() {
    int sum = 0;
    for (int j = 1; j <= 2; j++) {
        for (int k = 1; k <= 2; k++) {
            sum += fact(j);
        }
    }
    return sum;
}

int main() {
    cout<<"Q:1"<<endl;
    cout << "sum k 5 k=1: " << sum_k_1_to_5() << endl;
    cout << "sum k 7 k=1: " << sum_k_1_to_7() << endl;
    cout << "(sum k 5 k=1) * 3: " << sum_k_1_to_5_times_3() << endl;
    cout << "sum k! 5 k=1: " << sum_fact_k_1_to_5() << endl;
    cout << "sum k! 7 k=1: " << sum_fact_k_1_to_7() << endl;
    cout << "(sum k! 5 k=1) * 3 sum k 3 n k=1: " << sum_fact_k_1_to_5_times_3_sum_k_1_to_n(3) << endl;
    cout << "sum k! 3 n k=1: " << sum_fact_k_1_to_n(3) << endl;
    cout << "sum  5 j=1 sum k 3 3 k=1 j: " << nested_sum_j_1_to_5_k_1_to_3() << endl;
    cout << "sum  2 j=1 sum k 3 3 k=1 /j: " << nested_sum_j_1_to_2_k_1_to_3_divided_by_j() << endl;
    cout << "sum  2 j=1 sum k 3 2 k=1 j!: " << nested_fact_sum_j_1_to_2_k_1_to_2() << endl;

    return 0;
}
