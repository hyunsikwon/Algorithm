//
//  main.swift
//  카펫
//
//  Created by 원현식 on 2020/07/13.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let brown = 24
let yellow = 24

// OUTPUT: [4, 3]
print(solution(brown, yellow))

func solution(_ brown:Int, _ yellow:Int) -> [Int] {
    var answer = [Int]()
    var horizontal = 1 // 가로
    var vertical = 1 // 세로
    
    var sum = (brown+4)/2
    
    for i in 3..<sum {
        for j in 3..<sum {
            if i+j == sum {
                if i >= j && i*j - yellow == brown {
                    answer.append(i)
                    answer.append(j)
                    break
                }
            }
        }
    }
    
    
    return answer
}
