//
//  main.cpp
//  [카카오] 보석 쇼핑_cpp
//
//  Created by 원현식 on 2020/10/23.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    set<string> g;
    
    for(string gem: gems) {
        g.insert(gem);
    }
    
    int k = g.size(); // 보석의 종류
    vector<int> answer;
    answer.push_back(0); answer.push_back(0);
    
    set<string> temp;
    int i = 0, j = 0;
    int range = 100001;
    
    temp.insert(gems[i]);
    while (1) {
        
        if (temp.size() == k) {
            if (abs(i-j) < range) {
                range = abs(i-j);
                answer[0] = i+1;
                answer[1] = j+1;
            }
            
            temp.erase(gems[i]);
            i++;
        } else if (temp.size() < k){
            j++;
            temp.insert(gems[j]);
        }
        
        if (j >= gems.size()) break;
        
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<string> gems = {"ZZZ", "YYY", "NNNN", "YYY", "BBB"};
    
    vector<int> answer = solution(gems);

    
    // 3 7
    for(auto a: answer) {
        cout << a << ' ';
    }

}
