//
//  main.cpp
//  위장_cpp
//
//  Created by 원현식 on 2020/10/21.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> dic;
    vector<string> k;
    
    for (int i = 0; i < clothes.size(); i++) {
        string kind = clothes[i].back();
        if (dic[kind] == 0) {
            k.push_back(kind);
        }
        dic[kind]++;
    }
    
    for (int i = 0; i < k.size(); i++) {
        answer *= (dic[k[i]]+1);
        
    }
    
    return answer-1;
}

int main(int argc, const char * argv[]) {
    vector<vector<string>> clothes = {
        {"yellow_hat", "headgear"},
        {"blue_sunglasses", "eyewear"},
        {"green_turban", "headgear"}};
    
    cout << solution(clothes);
}
