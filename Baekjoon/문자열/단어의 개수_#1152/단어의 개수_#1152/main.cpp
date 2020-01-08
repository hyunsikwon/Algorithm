//
//  main.cpp
//  단어의 개수_#1152
//
//  Created by 원현식 on 2020/01/08.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    string str;
    int count = 0;
    
    getline(cin,str);
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            if (i == 0 || i == str.length() - 1) continue;
            else count++;
            
        }
    }
    
    if (str == " " || str == "") cout << 0 << '\n';
    else cout << count+1 << '\n';
    
}
