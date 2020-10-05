//
//  main.cpp
//  문자열 재정렬_cpp
//
//  Created by 원현식 on 2020/10/05.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
    return a < b;
}

int main(int argc, const char * argv[]) {
    string S;
    cin >> S;
    vector<string> arr;

    int sum = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] - '0' < 10) {
            sum += S[i] - '0';
        } else {;
            arr.push_back(string(1,S[i]));
        }
        
    }
    
    sort(arr.begin(), arr.end(), compare);
    
    string result = "";
    for (int i = 0; i < arr.size(); i++) {
        result += arr[i];
    }
    result += to_string(sum);
    
    cout << result;
}
