//
//  main.cpp
//  진법 변환2_#11005
//
//  Created by 원현식 on 2020/01/31.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int B;
int N;
string answer;

int main(int argc, const char * argv[]) {
    cin >> N >> B;

    while (N != 0) {

        int a = N % B;

        if (a >= 0 && a <= 9) {
            answer += a + '0';
        } else {
            answer += a + 'A' - 10;
        }

        N = N / B;
    }

    reverse(answer.begin(), answer.end());

    cout << answer;

}
