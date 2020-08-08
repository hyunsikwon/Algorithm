//
//  main.swift
//  최솟값 만들기
//
//  Created by 원현식 on 2020/08/08.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let A = [1, 2]
let B = [3, 4]

print(solution(A, B))

func solution(_ A:[Int], _ B:[Int]) -> Int {
    var answer = 0
    var a = A.sorted()
    var b = B.sorted()
    
    while !a.isEmpty && !b.isEmpty {
        var max = a.first!
        var min = b.last!
        
        answer += (max * min)

        a.removeFirst()
        b.removeLast()


    }

    return answer
}
