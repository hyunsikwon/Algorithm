//
//  main.cpp
//  30_#10610
//
//  Created by 원현식 on 2020/03/18.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

string check(string n) {
    int sum = 0;
    bool zero = false;
    for (int i = 0; i < n.size(); i++) {
        sum += (n[i] - '0');
        if (n[i] == '0') {
            zero = true;
        }
    }
    
    sort(n.begin(), n.end(), greater<int>());
    
    if (sum % 3 == 0 && zero == true) {
        return n;
    } else {
        return "-1";
    }

}

int main(void) {
    string N;
    cin >> N;
    
    cout << check(N);
    
}
