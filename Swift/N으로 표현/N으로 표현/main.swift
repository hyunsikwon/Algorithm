//
//  main.swift
//  N으로 표현
//
//  Created by 원현식 on 2020/05/21.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

// Input:
let N = 5
let number = 12
// Output: 4
print(solution(N,number))

var answer = 9

func dfs(_ N: Int, _ number: Int, _ count: Int, _ currentNum: Int) {
    if count > 8 {
        return
    }
    
    if currentNum == number {
        answer = min(count, answer)
        return
    }
    
    var temp = 0
    for i in 0..<(8-count) {
        temp = temp*10 + N
        dfs(N, number, count + i + 1, currentNum+temp)
        dfs(N, number, count + i + 1, currentNum-temp)
        dfs(N, number, count + i + 1, currentNum*temp)
        dfs(N, number, count + i + 1, currentNum/temp)
    }
}

func solution(_ N:Int, _ number:Int) -> Int {
    if N == number { return 1 }
    dfs(N, number, 0, 0)
    
    if answer == 9 { return -1 }
    return answer
}

