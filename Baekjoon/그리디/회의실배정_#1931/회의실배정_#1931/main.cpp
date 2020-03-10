//
//  main.cpp
//  회의실배정_#1931
//
//  Created by 원현식 on 2020/03/10.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> a;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        a.push_back(make_pair(start, end));
    }
    
    sort(a.begin(), a.end(), compare);
    
    int end = a[0].second;
    int count = 1;
    for (int i = 1; i < N; i++) {
        if (a[i].first >= end) {
            count++;
            end = a[i].second;
        }
    }
    
    cout << count;

}


