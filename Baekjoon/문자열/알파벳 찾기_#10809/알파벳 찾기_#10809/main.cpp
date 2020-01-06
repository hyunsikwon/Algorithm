//
//  main.cpp
//  알파벳 찾기_#10809
//
//  Created by 원현식 on 2020/01/06.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    string S;
    int a[27];
    
    for (int i = 0; i < 26; i++) {
        a[i] = -1;
    }

    cin >> S;
    
    for (int j = 0; j < S.length(); j++) {
        int asciiCode = S[j] - 0;
        
        if (a[asciiCode - 97] == -1) {
            a[asciiCode - 97] = j
        }
    }

    for (int k = 0; k < 26; k++) {
        cout << a[k] << ' ';
    }


}
