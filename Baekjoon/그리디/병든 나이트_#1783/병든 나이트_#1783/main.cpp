//
//  main.cpp
//  병든 나이트_#1783
//
//  Created by 원현식 on 2020/03/18.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

// 나이트가 네번 이상 움직이기 위해선 1~4번 방법을 모두 사용해야 한다.
// --> 4가지 방법을 쓰지 못하는 경우(ex. 가로 or 세로의 길이 제약) 3번까지 움직일 수 있다.

#include <iostream>
#include <algorithm>

using namespace std;

int N,M;

int main(int argc, const char * argv[]) {
    
    cin >> N >> M;
    
    if (N == 1) {
        cout << 1;
    } else if (N == 2) {
        if (M > 7) {
            cout << 4;
        } else {
            cout << (M+1)/2;
        }
    } else {
        if (M < 7) { // 4가지 방법을 모두 쓰지 못함.
            cout << min(4, M);
            
        } else { // 4가지 방법을 모두 사용 가능. // 2,3번 방법 한번씩 사용 후 1,4번 반복 사용.
            cout << M-2;
        }
    }
    
}
