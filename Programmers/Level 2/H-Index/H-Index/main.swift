//
//  main.swift
//  H-Index
//
//  Created by 원현식 on 2020/07/09.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

func solution(_ citations:[Int]) -> Int {
    var sortedArr = citations.sorted{ $0 > $1 }
    for (i, nOfCitation) in sortedArr.enumerated() {
        print(i, nOfCitation)
        if i >= nOfCitation {
            return i
        }
    }
    return citations.count
}

let c = [3, 0, 6, 1, 5]
//let c = [47, 42, 32, 28, 24, 22, 17, 15, 10, 10, 8]

print(solution(c))
