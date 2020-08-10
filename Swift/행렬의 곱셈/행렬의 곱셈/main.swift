//
//  main.swift
//  행렬의 곱셈
//
//  Created by 원현식 on 2020/08/10.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let arr1 = [
    [2, 3, 2],
    [4, 2, 4],
    [3, 1, 4]
    ]

let arr2 = [
    [5, 4, 3],
    [2, 4, 1],
    [3, 1, 1]
    ]


/* OUTPUT: [
    [15, 15],
    [15, 15],
    [15, 15]
]
 */
print(solution(arr1, arr2))

func solution(_ arr1:[[Int]], _ arr2:[[Int]]) -> [[Int]] {
    var answer = [[Int]]()
    
    for i in 0..<arr1.count {
        var temp = [Int]()
        for j in 0..<arr2[0].count {
            var sum = 0
            for k in 0..<arr2.count {
                sum += (arr1[i][k]*arr2[k][j])
            }
            
            temp.append(sum)
        }
        answer.append(temp)
    }
    
    return answer
}

