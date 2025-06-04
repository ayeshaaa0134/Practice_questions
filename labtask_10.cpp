
#include <iostream>
using namespace std;

void inc(int &num) {
    num++;
}

void dec(int &num) {
    num--;
}

void findMM(int a, int b, int c, int &min, int &max) {
    if (a < b && a < c) min = a;
    else if (b < a && b < c) min = b;
    else min = c;
    
    if (a > b && a > c) max = a;
    else if (b > a && b > c) max = b;
    else max = c;
}

void swapV(int car1, int car2) {
    int temp = car1;
    car1 = car2;
    car2 = temp;
    cout << "Inside swapV: " << car1 << " " << car2 << endl;
}

void swapR(int &car1, int &car2) {
    int temp = car1;
    car1 = car2;
    car2 = temp;
    cout << "Inside swapR: " << car1 << " " << car2 << endl;
}

void display(int scores[], int size) {
    for (int i = 0; i < size; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;
}

float avg(int scores[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) sum += scores[i];
    return static_cast<float>(sum) / size;
}

void update(int scores[], int index, int newScore) {
    scores[index] = newScore;
}

int main() {
    
    cout << "Question: 1" << endl;
    int num = 10;
    cout << "Initial: " << num << endl;
    inc(num);
    cout << "Incremented: " << num << endl;
    dec(num);
    cout << "Decremented: " << num << endl;

   
    cout << "Question: 2" << endl;
    int x = 5, y = 8, z = 3;
    int min, max;
    findMM(x, y, z, min, max);
    cout << "Min: " << min << ", Max: " << max << endl;

   
    cout << "Question: 3" << endl;
    int car1 = 1, car2 = 2;
    cout << "Initial: " << car1 << " " << car2 << endl;
    swapV(car1, car2);
    cout << "After swapV: " << car1 << " " << car2 << endl;
    swapR(car1, car2);
    cout << "After swapR: " << car1 << " " << car2 << endl;

    
    cout << "Question: 4" << endl;
    int scores[5] = {75, 88, 92, 65, 80};
    display(scores, 5);
    cout << "Average: " << avg(scores, 5) << endl;
    update(scores, 2, 95);
    display(scores, 5);

    return 0;
}
