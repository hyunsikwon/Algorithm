//
//  main.cpp
//  나머지_10430
//
//  Created by 원현식 on 2019/12/26.
//  Copyright © 2019 Hyunsik Won. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int a,b,c;
    
    std::cin >> a >> b >> c;
    
    cout << (a + b) % c << endl;
    cout << (a % c + b % c) % c << endl;
    cout << (a * b) % c << endl;
    cout << (a % c * b % c) % c << endl;
    

}

//첫째 줄에 (A+B)%C, 둘째 줄에 (A%C + B%C)%C, 셋째 줄에 (A×B)%C, 넷째 줄에 (A%C × B%C)%C를 출력한다.

