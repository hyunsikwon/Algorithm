//
//  main.cpp
//  단어 공부_#1157
//
//  Created by 원현식 on 2020/01/06.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <limits.h>

using namespace std;

int main(int argc, const char * argv[]) {
    string word;
    int count[27] = {0,}; // 모두 0으로 초기화
    char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    cin >> word;
    for (int i = 0; i < word.length(); i++) {
        int ascii = word[i] - 0;
        if (ascii >= 97) {
            count[ascii - 97]++;
        } else {
            count[ascii - 65]++;
        }
    }
    
    int max = INT_MIN;
    int maxIndex;
    bool sameValue = false;
    
    for (int i = 0; i < 26; i++) {
        if (count[i] > max) {
            max = count[i];
            maxIndex = i;
            sameValue = false;
        } else if(max == count[i]) {
            sameValue = true;
        }
    }
    
    if (sameValue) {
        cout << "?\n";
    } else {
        cout << alphabet[maxIndex] << '\n';
    }
    
    
}
