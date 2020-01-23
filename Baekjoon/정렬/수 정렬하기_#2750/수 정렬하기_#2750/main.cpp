//
//  main.cpp
//  수 정렬하기_#2750
//
//  Created by 원현식 on 2020/01/23.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int a[1001];

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selectionSort(int a[],int size) {
    int minIndex;
    for (int i = 0; i < size; i++) {
        int min = a[i];
        for (int j = i; j < size; j++) {
            if (a[j] <= min) {
                minIndex = j;
                min = a[j];
            }
        }
        swap(a, i, minIndex);
    }
    
}

void bubbleSort(int a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool sorted = true;
        for (int j = 0; j < size - i - 1; j++) {
            if (a[j] > a[j+1]) {
                swap(a, j, j+1);
                sorted = false;
            }
        }
        if (sorted) break;
    }
}

void insertionSort(int a[], int size) {
    for (int i = 1; i < size; i++) {
        for (int j = i; j > 0; j--) {
            if (a[j] < a[j-1]) {
                swap(a,j,j-1);
            } else continue;
        }
    }
}

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    //선택 정렬
    selectionSort(a,N);
    
    // 삽입 정렬
    //    insertionSort(a,N);
    //    //버블 정렬
    //    bubbleSort(a,N);
    
    for (int i = 0; i < N; i++) {
        cout << a[i] << '\n';
    }
    
}
