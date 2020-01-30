//
//  main.cpp
//  단어 정렬_#1181
//
//  Created by 원현식 on 2020/01/30.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<string> arr;
string str;

bool compare(string a, string b) {
    if (a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

int main(int argc, const char * argv[]) {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> str;
        arr.push_back(str);
    }
    
    sort(arr.begin(), arr.end(), compare);

    for (int i = 0; i < arr.size(); i++) {
        if (i > 0 && arr[i] == arr[i-1]) continue;
        else cout << arr[i] << '\n';
    }
   
}
