//
//  main.cpp
//  스킬트리_cpp
//
//  Created by 원현식 on 2020/09/23.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for(string skillTree: skill_trees) {
        string temp = "";
        
        for(char s: skillTree) {
            for(char c: skill) {
                if (c == s) {
                    temp += s;
                }
            }
        }
        
        
        for(char s: skill) {
            bool contains = false;
            for(char c: temp) {
                if(c == s) {
                    contains = true;
                    break;
                }
            }
            
            if (contains == false) {
                temp += s;
                
            }
        }
        
        
        if (temp == skill) { answer++; }
        
    }
    
    
    return answer;
}

int main(void) {
    string skill = "CBD";
    vector<string> skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};
    
    // result: 2
    cout << solution(skill, skill_trees);
}
