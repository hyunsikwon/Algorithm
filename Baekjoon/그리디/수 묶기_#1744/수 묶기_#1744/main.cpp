//
//  main.cpp
//  수 묶기_#1744
//
//  Created by 원현식 on 2020/03/16.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> positive;
vector<int> negative;
int result = 0;

bool compare(int a, int b) {
    return a > b;
}

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    int value[20001];
    for (int i = 0; i < N; i++) {
        cin >> value[i];
    }
    
    for (int i = 0; i < N; i++) {
        if (value[i] > 0) {
            positive.push_back(value[i]);
        } else if (value[i] <= 0){
            negative.push_back(value[i]);
        }
    }
    
    
    sort(positive.begin(), positive.end(), compare);
    sort(negative.begin(), negative.end());
    
    for (int i = 0; i < positive.size(); i += 2) {
        if (i+1 < positive.size() && positive[i+1] > 1) {
            result += positive[i] * positive[i+1];
        } else if (i + 1 >= positive.size()){
            result += positive[i];
        } else {
            result += positive[i] + positive[i+1];
        }
    }
    
    
    for (int i = 0; i < negative.size(); i += 2) {
        if (i+1 < negative.size() && negative[i+1] <= 0) {
            result += negative[i] * negative[i+1];
        } else if (i + 1 >= negative.size()){
            result += negative[i];
        } else {
            result += negative[i] + negative[i+1];
        }
    }
    
    cout << result;
    
}
