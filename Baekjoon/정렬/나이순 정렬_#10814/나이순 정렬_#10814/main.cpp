//
//  main.cpp
//  나이순 정렬_#10814
//
//  Created by 원현식 on 2020/01/30.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<pair<int, string>> members;
int age;
string name;

bool compare(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}

int main(int argc, const char * argv[]) {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> age >> name;
        members.push_back(pair<int, string>(age,name));
    }

    stable_sort(members.begin(), members.end(), compare);
    
    for (int i = 0; i < N; i++) {
        cout << members[i].first << ' ' << members[i].second << '\n';
    }

}
