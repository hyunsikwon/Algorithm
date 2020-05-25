//
//  main.swift
//  쇠막대기
//
//  Created by 원현식 on 2020/05/25.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

//Input:
let arrangement = "()(((()())(())()))(())"
// "R(((R R) (R) R))(R)"
//Output: 17
print(solution(arrangement))

func solution(_ arrangement:String) -> Int {
    var answer = 0
    var former = ""
    var count = 0
    for v in arrangement {
        let str = String(v)
        if str == "(" {
            count += 1
        } else {
            count -= 1
            if former == "(" {
                answer += count
            } else {
                answer += 1
            }
        }
        former = str
    }

    return answer
}

