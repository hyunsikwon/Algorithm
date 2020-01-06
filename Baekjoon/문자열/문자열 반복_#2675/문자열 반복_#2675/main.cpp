//
//  main.cpp
//  문자열 반복_#2675
//
//  Created by 원현식 on 2020/01/06.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    string S;
    int T;
    
    cin >> T;

    for (int i = 0; i < T; i++) {
        int R;
        string P = "";
        string S;

        cin >> R >> S;

        for (int j = 0; j < S.length(); j++) {
            for (int k = 0; k < R; k++) {
                P += S[j];
            }
        }

        cout << P << '\n';
    }
    
}
