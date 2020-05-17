//
//  main.swift
//  기지국 설치
//
//  Created by 원현식 on 2020/05/17.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let N = 16
let stations = [9]
let W = 2

print(solution(N,stations,W))

func solution(_ n:Int, _ stations:[Int], _ w:Int) -> Int {
    var answer = 0
    var idx = 0
    var location = 1

    while location <= n {
        if idx < stations.count && location >= stations[idx] - w {
            location = stations[idx] + w + 1
            idx += 1
        } else {
            location += 2*w+1
            answer += 1
        }
    }
    return answer
}
