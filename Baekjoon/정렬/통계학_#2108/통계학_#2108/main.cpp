//
//  main.cpp
//  통계학_#2108
//
//  Created by 원현식 on 2020/01/27.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

//산술평균 : N개의 수들의 합을 N으로 나눈 값
//중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
//최빈값 : N개의 수들 중 가장 많이 나타나는 값
//범위 : N개의 수들 중 최댓값과 최솟값의 차이

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int arithmeticMean;
int median;
int mode;
int range;

int a[500001];
int counting[8002];

int main(int argc, const char * argv[]) {

    cin >> N;

    double sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        sum += a[i];
        
        counting[a[i] + 4000]++;
    }
    
    sort(a, a+N);
    
    int max = -1;
    int index = 0;
    bool check = false;
    int count = 0;
    for (int i = 0; i <= 8000; i++) {
        if (counting[i] > max) {
            index = i;
            max = counting[i];
            check = false;
        } else if(counting[i] == max && check == false) {
            check = true;
            index = i;
        }
        count++;
    }
    
    arithmeticMean = round(sum/N);
    median = a[(0+N)/2];
    mode = index - 4000;
    range = a[N-1] - a[0];

    cout << arithmeticMean << '\n';
    cout << median << '\n';
    cout << mode << '\n';
    cout << range << '\n';

}
