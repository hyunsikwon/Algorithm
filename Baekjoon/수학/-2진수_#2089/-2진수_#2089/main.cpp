//
//  main.cpp
//  -2진수_#2089
//
//  Created by 원현식 on 2020/02/03.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

int decimal;
stack<int> s;

int main(void) {
    
    cin >> decimal;

    while (decimal != 0) {
        if (decimal > 0) {
            s.push(decimal % -2);

        } else if (decimal < 0) {
            decimal = -decimal;
            s.push((decimal) % -2);
            decimal = -decimal - 1;
        }

        decimal /= -2;
    }

    if (s.empty()) {
        cout << 0;
        
    } else {
        
        while (!s.empty()) {
            cout << s.top();
            s.pop();
        }
    }
    
        
}

//void cal(int a) {
//
//    if (a == 0) return;
//
//    if (a < 0) {
//        cal(-((a - 1) / 2));
//        cout << -a % 2;
//
//    } else if (a>0) {
//        cal(-(a / 2));
//        cout << a % 2;
//
//    }
//
//}
//
//int main() {
//
//    int n;
//    cin >> n;
//
//    if (n == 0) {
//        cout << 0;
//        return 0;
//    }
//
//    cal(n);
//    return 0;
//}
