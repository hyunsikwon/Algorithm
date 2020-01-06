//
//  main.cpp
//  숫자의 합_#11720
//
//  Created by 원현식 on 2020/01/06.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int main(void) {
    int N;
    char a;
    
    cin >> N;

    int sum = 0;
    for (int j = 0; j < N; j++) {
        cin >> a;
        sum += a - '0';
    }
    
    cout << sum;


}
