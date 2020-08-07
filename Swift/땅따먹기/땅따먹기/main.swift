//
//  main.swift
//  땅따먹기
//
//  Created by 원현식 on 2020/08/07.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let land = [[1,2,3,5],[5,6,7,8],[4,3,2,1]]

print(solution(land))

func solution(_ land:[[Int]]) -> Int {
    var answer = 0
    var n = land.count
    var temp = land
    
    for i in 1..<n {
        for j in 0..<4 {
            var max = 0
            for k in 0..<4 {
                if j != k {
                    if temp[i-1][k] > max  {
                        max = temp[i-1][k]
                    }
                }
            }
        
            temp[i][j] += max
            
        }
    }

    answer = temp[n-1].max() ?? 0

    return answer
}

