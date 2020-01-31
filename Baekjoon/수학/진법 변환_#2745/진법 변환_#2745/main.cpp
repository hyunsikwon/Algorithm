//
//  main.cpp
//  진법 변환_#2745
//
//  Created by 원현식 on 2020/01/31.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int B;
string N; // B진법 수 N.
int answer = 0;

int main(int argc, const char * argv[]) {
    
    cin >> N >> B;
    
    for (int i = 0; i < N.length(); i++) {
        if (N[i] >= '0' && N[i] <= '9') {
//            cout << "if" << N[i] - '0' << '\n';
            answer = answer * B + (N[i] - '0');
        } else {
//            cout << "else" << N[i] - 'A' + 10 << '\n';
            answer = answer * B + (N[i] - 'A' + 10);
        }
    }
    
    cout << answer << '\n';
    
}
