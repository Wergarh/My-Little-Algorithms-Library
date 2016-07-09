#include <iostream>

using namespace std;

//Some algorithms for fork with arrays

/*Инвертирует элементы массива с позиции k*/
void rev(int *arr, const int sz, const int k) {
    if(k > sz || k < 0) {
        cerr << "Error: Array index out of bounds\n";
    }
    int tmp = 0;
    
    for(int i = k, j = 0; i < (sz + k) / 2; i++, j++) {
        tmp = arr[i];
        arr[i] = arr[sz - j - 1];
        arr[sz - j - 1] = tmp;
    }
}

/*Сдвигает элементы массива вправо на один шаг*/
void oneShiftRight(int *arr, const int sz) {
    int tmp = 0;
    
    for(int i = sz - 2, j = sz - 1; i >= 0; i--, j--) {
        tmp = arr[j];
        arr[j] = arr[i];
        arr[i] = tmp;
    }
}

/*Сдвигает элементы массива влево на один шаг*/
void oneShiftLeft(int *arr, const int sz) {
    int tmp = 0;
    
    for(int i = 1, j = 0; i < sz; i++, j++) {
        tmp = arr[j];
        arr[j] = arr[i];
        arr[i] = tmp;
    }
}

/*Сдвигает элементы массива вправо на заданное число позиций - k*/
void shiftRight(int *arr, const int sz, const int k) {
    for(int i = 0; i < k; i++) {
        oneShiftRight(arr, sz);
    }
}

/*Сдвигает элементы массива влево на заданное число позиций - k*/
void shiftLeft(int *arr, const int sz, const int k) {
    for(int i = 0; i < k; i++) {
        oneShiftLeft(arr, sz);
    }
}