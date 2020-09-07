//
//  main.swift
//  하노이의 탑
//
//  Created by 원현식 on 2020/09/07.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation


func solution(_ n:Int) -> [[Int]] {
    var answer = [[Int]]()
    
    
    func hanoi(_ n: Int, _ from: Int, _ tmp: Int, _ to: Int) {
        if n == 1 {
            answer.append([from, to]) // move
        } else {
            hanoi(n-1, from, to, tmp)
            answer.append([from, to]) // move
            hanoi(n-1, tmp, from, to)
            
        }
        
    }
    
    hanoi(n, 1, 2, 3)
    return answer
}



let n = 5

print(solution(n)) // RESULT: [ [1,2], [1,3], [2,3] ]
