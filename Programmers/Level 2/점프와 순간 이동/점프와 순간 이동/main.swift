//
//  main.swift
//  점프와 순간 이동
//
//  Created by 원현식 on 2020/05/12.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let N = 6

print(solution(N))

func solution(_ n:Int) -> Int {
    var ans:Int = 0
    var current: Int = 0
    
    var a = n

    while a != 1  {
        if a % 2 == 0 {
            a/=2
        } else {
            ans+=1
            a -= 1
            a/=2
        }
    }
    
    return ans + 1
}

