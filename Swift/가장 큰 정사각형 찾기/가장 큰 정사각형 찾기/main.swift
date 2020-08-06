//
//  main.swift
//  가장 큰 정사각형 찾기
//
//  Created by 원현식 on 2020/08/06.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let board = [[0,1,1,1],[1,1,1,1],[1,1,1,1],[0,0,1,0]]

print(solution(board))

func solution(_ board:[[Int]]) -> Int {
    var answer:Int = 0
    
    var tempBoard = board
    var height = board.count
    var width = board[0].count
    
    let limit = height < width ? height : width
    
    if height <= 1 || width <= 1 { // 한 변의 길이가 2이상이 될 수 없을 때
        for i in 0..<height {
            for j in 0..<width {
                if board[i][j] == 1 {
                    answer = 1
                }
            }
        }
        
    } else {
        
        for i in 1..<height {
            for j in 1..<width {
                if tempBoard[i][j] != 0 {
                    tempBoard[i][j] = min(min(tempBoard[i-1][j-1], tempBoard[i-1][j]),tempBoard[i][j-1]) + 1
                    answer = tempBoard[i][j] > answer ? tempBoard[i][j] : answer
                }
            }
        }
        
    }
    
    
    return answer*answer
}

