//
//  main.swift
//  Skill Check Lv2
//
//  Created by 원현식 on 2020/05/20.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let board = [[0,1,1,1],[1,1,1,1],[1,1,1,1],[0,0,1,0]]
print(solution(board))

func solution(_ board:[[Int]]) -> Int {
    
    var answer:Int = 0
    var land = board
    let height = board.count
    let width = board[0].count
    var max = -1
    
    for i in 1..<height{
        for j in 1..<width {
            if land[i][j] == 1{
                land[i][j] = min(land[i-1][j], land[i][j-1], land[i-1][j-1]) + 1
            }
            if land[i][j] > max {
                max = land[i][j]
            }
        }
    }
    
    answer = max*max
    
    return answer
}


