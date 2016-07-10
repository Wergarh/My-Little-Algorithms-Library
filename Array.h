#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

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

/*Создает матрицу размера rows x cols*/
int **createMatrix(const unsigned rows, const unsigned cols) {
    int **arr = new int *[rows];
    for (size_t i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    
    return arr;
}

/*Заполняет матрицу случайными числами, требуется cstdlib и ctime*/
void setMatrix(int **m, const unsigned rows, const unsigned cols) {
    srand(time(NULL)); //передаем функция time() с параметром NULL
    for (size_t i = 0; i < rows; i++) {
        for(size_t j = 0; j < cols; j++) {
            m[i][j] = (rand() / 1000);
        }
    }
}

/*Печать матрицы размера rows x cols*/
void printArr(const int * const * m, unsigned rows, unsigned cols) {
    for (size_t i = 0; i < rows; i++) {
        for(size_t j = 0; j < cols; j++) {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }
}

/*Транспонирует матрицу размера rows × cols в матрицу размера cols x rows*/
int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int **a = createMatrix(cols, rows);
    
    for (size_t i = 0; i < cols; i++) {
        for(size_t j = 0; j < rows; j++) {
            a[i][j] = m[j][i];
        }
    }
    
    return a;
}

/*Находит минимальный элемент матрицы и меняет строку с этим элементом с первой*/
void swap_min(int *m[], int rows, int cols)
{
    int min = m[0][0], cMin = 0;
    int *p1 = *m, *p2 = *(m+1);

    
    for (int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(m[i][j] < min) {
                min = m[i][j];
                p2 = *(m+i);
                cMin = i;
            }
        }
    }
    *(m+cMin) = p1;
    *m = p2;
}

#endif //ARRAY_H