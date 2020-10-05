//
//  main.cpp
//  럭키 스트레이트_cpp
//
//  Created by 원현식 on 2020/10/05.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    string N;
    cin >> N;

    int left = 0;
    int right = 0;
    
    for (int i = 0; i < N.length(); i++) {
        if (i < N.length()/2) {
            left += N[i] - '0';
        } else {
            right += N[i] - '0';
        }
    }
    
    if (left == right) {
        cout << "LUCKY";
    } else {
        cout << "READY";
    }
    
}
