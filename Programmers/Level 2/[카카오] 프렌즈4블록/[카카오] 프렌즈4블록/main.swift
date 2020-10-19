
//
//  main.swift
//  [카카오] 프렌즈4블록
//
//  Created by 원현식 on 2020/08/13.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let m = 4, n = 5
let board = ["CCBDE",
             "AAADE",
             "AAABF",
             "CCBBF"]

// OUTPUT: 14
print(solution(m, n, board))

func check(_ i: Int, _ j: Int, _ newBoard: inout [[String]], _ visited: inout [[Bool]]) -> Int {
    let char = newBoard[i][j]
    if newBoard[i+1].count <= j + 1 || char == "-" {
        return 0
    }
    
    if newBoard[i][j+1] == char && newBoard[i+1][j] == char && newBoard[i+1][j+1] == char {
        var sum = 0
        
        if !visited[i][j] {
            sum += 1
            visited[i][j] = true
        }
        if !visited[i][j+1] {
            sum += 1
            visited[i][j+1] = true

        }
        if !visited[i+1][j] {
            sum += 1
            visited[i+1][j] = true

        }
        if !visited[i+1][j+1]{
            sum += 1
            visited[i+1][j+1] = true
        }
        
        return sum
    }
    
    return 0
}

func solution(_ m:Int, _ n:Int, _ board:[String]) -> Int {
    var answer = 0
    var newBoard = Array(repeatElement([String](), count: n))  // 열 단위로 저장
    var visited = Array(repeatElement(Array(repeatElement(false, count: m)), count: n))
    
    for i in (0...m-1).reversed() {
        var j = 0
        for char in board[i] {
            newBoard[j].append(String(char))
            j += 1
        }
    }

    
    var popSum = 0
    repeat {
        popSum = 0
        for i in 0...(newBoard.count-2) {
            for j in 0...(newBoard[i].count - 2) {
                popSum += check(i, j, &newBoard, &visited)
            }
        }
        answer += popSum

        // board 조정
        for i in 0..<visited.count {
            for j in (0...visited[i].count-1).reversed() {
                if visited[i][j] {
                    visited[i][j] = false
                    newBoard[i].remove(at: j)
                }
            }
            
            while newBoard[i].count < m {
                newBoard[i].append("-")
            }
        }

    } while popSum != 0

    return answer
}






