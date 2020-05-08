//
//  main.cpp
//  예산
//
//  Created by 원현식 on 2020/05/08.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool binarySearch(int num, int M, vector<int> budgets) {
    int sum = 0;
    for (int i = 0; i < budgets.size(); i++) {
        if (budgets[i] > num) {
            sum += num;
        } else {
            sum += budgets[i];
        }
    }
    
    if (sum > M) {
        return false;
    } else {
        return true;
    }
}

int solution(vector<int> budgets, int M) {
    int first = 1;
    int last = *max_element(budgets.begin(), budgets.end());
    
    while (first <= last) {
        int mid = (first+last)/2;
        cout << "first: " << first << ' ';
        cout << "last: "<< last << '\n';
        if (binarySearch(mid, M, budgets)) {
            first = mid + 1;
        } else {
            last = mid - 1;
        }
    }
    return last;
}

int main(int argc, const char * argv[]) {
    vector<int> budgets = {120, 110, 140, 150};
    int M = 485;
    
    cout << solution(budgets, M);
}
