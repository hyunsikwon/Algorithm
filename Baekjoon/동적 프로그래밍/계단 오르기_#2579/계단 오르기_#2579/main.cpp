//
//  main.cpp
//  계단 오르기_#2579
//
//  Created by 원현식 on 2020/01/13.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    int stairs[302];
    int accumulated[302];
    
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        int score;
        cin >> score;
        stairs[i] = score;
    }
    
    accumulated[1] = stairs[1];
    accumulated[2] = stairs[1] + stairs[2];
    accumulated[3] = max(stairs[1] + stairs[3],stairs[2] + stairs[3]);
    
    for (int i = 4; i <= n; i++) {
        accumulated[i] = max(accumulated[i-3] + stairs[i-1] + stairs[i], accumulated[i-2] + stairs[i]);
        
    }
    
    cout << accumulated[n] << '\n';
    

}
