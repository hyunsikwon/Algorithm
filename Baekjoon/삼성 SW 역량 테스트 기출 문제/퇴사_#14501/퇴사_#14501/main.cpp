//
//  main.cpp
//  퇴사_#14501
//
//  Created by 원현식 on 2020/11/23.
//

#include <iostream>

using namespace std;

int n, t[17], p[17], d[17], result;

int main() {
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> t[i] >> p[i];
    }

    for(int i=1; i<=n; i++){
        if (i+t[i] <= n+1) {
            d[i+t[i]] = max(d[i+t[i]], d[i] + p[i]);
            result = max(result, d[i+t[i]]);
        }

        d[i+1] = max(d[i+1], d[i]);
        result = max(result, d[i+1]);
    }

    cout << result;
}
