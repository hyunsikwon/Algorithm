//
//  main.cpp
//  상수_#2908
//
//  Created by 원현식 on 2020/01/08.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;



int main(int argc, const char * argv[]) {
    string num1,num2;
    
    cin >> num1 >> num2;
    
    string a = "";
    string b = "";
    
    for (int i = 2; i >= 0; i--) {
        a += num1[i];
        b += num2[i];
    }
    
    if (a > b) cout << a << '\n';
    else cout << b << '\n';
    
}
