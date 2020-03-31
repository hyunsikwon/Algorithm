//
//  main.cpp
//  숫자 카드2_#10816
//
//  Created by 원현식 on 2020/03/31.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
int A[500001];
int B[500001];
int tmp[500001];
int cnt[20000001];


bool check(int start, int end, int a) {
    if (end < start) return false;
    
    int middle = (start + end) / 2;
    
    if (a < B[middle]) {
        return check(start, middle-1, a);
    } else if(a > B[middle]) {
        return check(middle+1, end, a);
    } else if (a == B[middle]) {
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
    
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> B[i];
        tmp[i] = B[i];
    }
    sort(B, B+M);
    
    for (int i = 0; i < N; i++) {
        if (check(0, M-1, A[i])) {
            cnt[A[i]+10000000]++;
        }
    }
    
    for (int i = 0; i < M; i++) {
        cout << cnt[tmp[i]+10000000] << ' ';
    }
    
    
    
}
