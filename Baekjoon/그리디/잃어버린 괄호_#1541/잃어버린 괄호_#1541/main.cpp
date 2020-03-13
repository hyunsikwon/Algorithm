//
//  main.cpp
//  잃어버린 괄호_#1541
//
//  Created by 원현식 on 2020/03/13.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

string expression;

int main(int argc, const char * argv[]) {
    cin >> expression;
    
    string temp = "";
    bool isMinus = false;
    int result = 0;
    for (int i = 0; i <= expression.size(); i++) {
        
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == NULL) {
            if (isMinus) {
                result -= atoi(temp.c_str());
            } else {
                result += atoi(temp.c_str());
            }
            temp = "";
            if (expression[i] == '-') {
                isMinus = true;
            }
            
        } else {
            temp += expression[i];

        }
    }
    
    cout << result;
    
 
  
}
