//
//  main.cpp
//  2진수 8진수_#1373
//
//  Created by 원현식 on 2020/02/01.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//
// 2진수 -> 8진수 변환 법 https://blog.naver.com/javrin4/220956809081 참고

#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

string binaryNum;
vector<int> v;

int main(int argc, const char * argv[]) {
    cin >> binaryNum;
    
    if ((binaryNum.length() % 3) == 1) {
        binaryNum = "00" + binaryNum;
        
    } else if ((binaryNum.length() % 3) == 2) {
        binaryNum = "0" + binaryNum;
    }
    
    int i = 3;
   
    while (i <= binaryNum.length()) {
        int num = 0;
        for (int j = 2; j >= 0; j--) {
            int a = binaryNum[i - j - 1] - '0';
            num = num + (a * pow(2, j));
        }
        v.push_back(num);
        i += 3;
    }
    
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
    
}

