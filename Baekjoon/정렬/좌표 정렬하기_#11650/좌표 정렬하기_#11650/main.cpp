//
//  main.cpp
//  좌표 정렬하기_#11650
//
//  Created by 원현식 on 2020/01/28.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int x,y;
vector<pair<int, int>> v;

//bool compare(pair<int, int> a, pair<int, int> b) {
//    if (a.first == a.first) return a.second < b.second;
//
//    return a.first < a.second;
//}

int main(int argc, const char * argv[]) {
    cin >> N;
    
    for (int i = 0; i < N ; i++) {
        cin >> x >> y;
        v.push_back(pair<int, int>(x,y));
    }
    
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }

}
