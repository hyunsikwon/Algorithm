//
//  main.swift
//  종이접기
//
//  Created by 원현식 on 2020/05/13.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let n = 3
print(solution(n))

func recursive(_ n: Int) -> [Int] {
    if n == 1 {
        return [0]
    }
    var leftSide = recursive(n-1)
    var rigthSide = [Int]()
    for a in leftSide {
        if a == 0 {
            rigthSide.append(1)
        } else {
            rigthSide.append(0)
        }
    }
    return leftSide + [0] + rigthSide.reversed()
}

func solution(_ n:Int) -> [Int] {
    // 가운데 0
    // 가운데를 기준으로 왼쪽은 n-1번 째 값들
    // 오른쪽은 왼쪽 수들의 역수들
    return recursive(n)
}
