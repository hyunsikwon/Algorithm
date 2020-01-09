//
//  main.cpp
//  그룹 단어 체커_#1316
//
//  Created by 원현식 on 2020/01/09.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    int count = 0;
    
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        bool check = true;
        char temp;
        
        for (int k = 0; k < word.length(); k++) {
            temp = word[k];
            for (int j = k + 1; j < word.length() ; j++) { // 현재 알파벳과 같은 알파벳이 바로 옆에있다면 그냥 break.
                if (temp == word[j] && j == k + 1){
                    break;
                } else if (temp == word[j] && j > k+1) { // 현재 알파벳과 같은 알파벳이 바로옆이 아닌 곳에 있다면 속성 만족하지 않음.
                    check = false;
                }
            }
        }
        
        if (check) count++;
    }
    
    cout << count << '\n';
    
    
}
