#include <iostream>   // cout
#include <algorithm>  // copy, fill

#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;

// Задание 1
void swap_args(int *lhs, int *rhs) {

    if (!lhs | !rhs) {
        return;
    }
    int ph = *rhs;
    *rhs = *lhs;
    *lhs = ph;
}

// Задание 2
int **allocate_2d_array(int num_rows, int num_cols, int init_value) {
    if (num_rows <= 0 | num_cols <= 0) {
        return nullptr;
    }
    int **array_2d = new int *[num_rows];

    for (int row_index = 0; row_index < num_rows; row_index++) {
        array_2d[row_index] = new int[num_cols];
    }

    for (int row_index = 0; row_index < num_rows; row_index++) {
        for (int column_index = 0; column_index < num_cols; column_index++) {

            array_2d[row_index][column_index] = init_value;
        }
    }
    return array_2d;
}


// Задание 3
bool copy_2d_array(int **arr_2d_source, int **arr_2d_target, int num_rows, int num_cols) {
    if (!arr_2d_source || !arr_2d_target || num_rows <= 0 | num_cols <= 0) {
        return false;
    }

    for (int row_index = 0; row_index < num_rows; row_index++) {
        for (int column_index = 0; column_index < num_cols; column_index++) {
            arr_2d_target[row_index][column_index] = arr_2d_source[row_index][column_index];
        }
    }
    return true;
}

// Задание 4
void reverse_1d_array(vector<int> &arr) {
    for (int i = 0; i < arr.size() / 2; ++i) {
        int ph = arr[i];
        arr[i] = arr[arr.size() - i - 1];
        arr[arr.size() - i - 1] = ph;

    }
}

// Задание 5
void reverse_1d_array(int *arr_begin, int *arr_end) {
    if (arr_begin && arr_end) {
        while (arr_end > arr_begin) {
            swap_args(arr_begin, arr_end);
            arr_begin++;
            arr_end--;
        }
    }
}


// Задание 6
int *find_max_element(int *arr, int size) {
    if (!arr | (size <= 0)) {
        return nullptr;
    }
    int *max = arr;
    for (int i = 0; i < size; i++) {
        if (*arr > *max) {
            max = arr;
        }
        arr += 1;
    }
    return max;
}


// Задание 7
vector<int> find_odd_numbers(vector<int> &arr) {

    vector<int> vector = {};
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] % 2 != 0) {
            vector.emplace_back(arr[i]);
        }
    }
    return vector;
}

// Задание 8
vector<int> find_common_elements(vector<int> &arr_a, vector<int> &arr_b) {
    vector<int> vector = {};
    for (int i = 0; i < arr_a.size(); ++i) {
        for (int j = 0; j < arr_b.size(); ++j) {
            if (arr_a[i] == arr_b[j]) {
                vector.emplace_back(arr_a[i]);
            }
        }
    }
    return vector;
}
