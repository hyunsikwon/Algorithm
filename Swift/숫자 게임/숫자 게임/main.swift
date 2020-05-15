//
//  main.swift
//  숫자 게임
//
//  Created by 원현식 on 2020/05/15.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let A = [5,1,3,7]
let B = [2,2,6,8]

print(solution(A,B))

func solution(_ a:[Int], _ b:[Int]) -> Int {
    var answer = 0
    let sortedA = a.sorted {$0 > $1}
    let sortedB = b.sorted {$0 > $1}
    
    var k = -1
    for i in 0..<b.count {
        for j in k+1..<a.count {
            if sortedB[i] > sortedA[j] {
                k = j
                answer+=1
                break;
            }
        }
    }
    
    return answer
}
