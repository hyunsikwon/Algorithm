//
//  main.cpp
//  크로아티아 알파벳_#2941
//
//  Created by 원현식 on 2020/01/08.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

bool check(string temp) {
    string arr[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    for (int i = 0; i < 8; i++) {
        if(temp == arr[i]) {
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    string inputData;
    int count = 0;
    
    cin >> inputData;
    
    string temp = "";
    int i = 0;
    while(i < inputData.length()) {
        for (int j = 0; j < 3; j++) {
            temp += inputData[i+j];
            if (check(temp)) {
                count++;
                i = i + j + 1;
                break;
            } else if (!check(temp) && (j == 2)) {
                count++;
                i++;
            }
        }
        temp = "";
    }
    
    cout << count << '\n';
 
}
