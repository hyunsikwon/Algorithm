//
//  main.cpp
//  파도반 수열_#9461
//
//  Created by 원현식 on 2020/01/11.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

long long a[102] = {0,};

long long padovan(int N) {
    if (a[N] != 0) return a[N];
    if (N == 1 || N == 2 || N == 3) a[N] = 1;
    else if (N == 4 || N == 5) a[N] = 2;
    else a[N] = padovan(N-1) + padovan(N-5);
    
    return a[N];
}

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        cout << padovan(N) << '\n';
    }
}
