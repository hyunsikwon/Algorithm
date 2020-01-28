//
//  main.cpp
//  소트인사이드_#1427
//
//  Created by 원현식 on 2020/01/28.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// N은 1,000,000,000보다 작거나 같은 자연수이다.
string N;
int a[11];

int main(int argc, const char * argv[]) {
    cin >> N;

    for (int i = 0; i < N.length(); i++) {
        a[i] =  N[i] - '0';
    }
    
    sort(a, a+N.length());
    
    for (int i = N.length()-1; i >= 0; i--) {
        cout << a[i];
    }
}
