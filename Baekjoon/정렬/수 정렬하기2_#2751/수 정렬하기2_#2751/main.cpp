//
//  main.cpp
//  수 정렬하기2_#2751
//
//  Created by 원현식 on 2020/01/23.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int a[1000001];
int tempArr[1000001];

// MARK: - Swap
void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// MARK: - Quick Sort
int partition(int a[], int start, int end){
    int j = start;
    int i = start - 1;
    int pivot = end;

    for (j = start; j < end; j++) {
        if (a[j] < a[pivot]) {
            i++;
            swap(a,i,j);
        }
    }

    swap(a, i+1, pivot);
    return i + 1; // 기준 인덱스. 이 인덱스를 기준으로 왼쪽에는 더 작은값, 오른쪽에는 더 큰 값.
}


void quickSort(int a[], int start, int end) {
    if (start < end) {
        int middle = partition(a, start, end);
        quickSort(a, start, middle-1);
        quickSort(a, middle + 1, end);
    }
}

// MARK: - Merge Sort
void merge(int a[], int start, int middle, int end) {
    int i = start; // 4
    int tmpIndex = i; // 4
    int j = middle + 1; // 6
    
    while (i <= middle && j <= end) {
        if (a[i] <= a[j]) {
            tempArr[tmpIndex] = a[i];
            i++;
        } else {
            tempArr[tmpIndex] = a[j];
            j++;
        }
        tmpIndex++;
    }
    
    if (i > middle) {
        for (int k = j; k <= end; k++) {
            tempArr[tmpIndex] = a[k];
            tmpIndex++;
        }
    } else {
        for (int k = i; k <= middle; k++) {
            tempArr[tmpIndex] = a[k];
            tmpIndex++;
        }
    }
    
    for (int k = start; k <= end; k++) {
        a[k] = tempArr[k];
    }
}


void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;
        mergeSort(a, start, middle);
        mergeSort(a, middle + 1, end);
        merge(a, start, middle, end);
    }
}

//MARK: - Heap Sort



//MARK: - Main
int main(int argc, const char * argv[]) {
    
    int N;
    //입력
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    //Quick Sort - 최악의 경우 n^2
    //    quickSort(a, 0, N - 1);
    
    //Merge Sort
    mergeSort(a, 0, N - 1);
    
    
    //출력
    for (int i = 0; i < N; i++) {
        cout << a[i] << '\n';
    }
    
}
