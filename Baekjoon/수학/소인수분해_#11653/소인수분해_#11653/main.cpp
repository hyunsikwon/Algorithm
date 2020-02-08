//
//  main.cpp
//  소인수분해_#11653
//
//  Created by 원현식 on 2020/02/08.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> primeFactors;
int pf = 2;

int main(int argc, const char * argv[]) {
    cin >> N;
    
    while (N != 1) {
        if (N % pf == 0) {
            primeFactors.push_back(pf);
            N /= pf;
            pf = 2;
        } else pf++;
        
    }
    
    for (int i : primeFactors) {
        cout << i << '\n';
    }
    
}
