//
//  main.cpp
//  수 찾기_#1920
//
//  Created by 원현식 on 2020/03/31.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int A[100001];
int B[100001];
int N, M;

bool check(int start, int end, int a) {
    if (end < start) return false;
    
    int middle = (start + end)/2;
    if (a < A[middle]) {
        return check(start, middle-1, a);
    } else if (a > A[middle]) {
        return check(middle+1, end, a);
    } else if (a == A[middle]){
        return true;
    } else {
        return false;
    }
    
}

int main(int argc, const char * argv[]) {
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    sort(A, A+N);
    
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    
    for (int i = 0; i < M; i++) {
        if (check(0,N-1,B[i])) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    
}
