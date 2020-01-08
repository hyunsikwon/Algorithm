//
//  main.cpp
//  다이얼_#5622
//
//  Created by 원현식 on 2020/01/08.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    string str;
    int time = 0;
    
    cin >> str;
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] - 0 <= 'C' - 0) {
            time += 3;
        } else if (str[i] - 0 <= 'F' - 0) {
            time += 4;
        } else if (str[i] - 0 <= 'I' - 0){
            time += 5;
        } else if (str[i] - 0 <= 'L' - 0){
            time += 6;
        } else if (str[i] - 0 <= 'O' - 0){
            time += 7;
        } else if (str[i] - 0 <= 'S' - 0){
            time += 8;
        } else if (str[i] - 0 <= 'V' - 0){
            time += 9;
        } else {
            time += 10;
        }
    }
    
    cout << time << '\n';
}
