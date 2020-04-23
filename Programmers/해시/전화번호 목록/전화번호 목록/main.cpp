//
//  main.cpp
//  전화번호 목록
//
//  Created by 원현식 on 2020/04/23.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i].length() < phone_book[i+1].length()) {
            bool isSame = true;
            for (int j = 0; j < phone_book[i].length(); j++) {
                if (phone_book[i][j] != phone_book[i+1][j]) {
                    isSame = false;
                    continue;
                }
            }
            if (isSame) return false;
            
        }
    }
    
    return answer;
}
