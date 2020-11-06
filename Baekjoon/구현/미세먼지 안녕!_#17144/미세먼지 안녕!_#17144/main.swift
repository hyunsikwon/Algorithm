//
//  main.swift
//  미세먼지 안녕!_#17144
//
//  Created by 원현식 on 2020/11/06.
//

import Foundation

// MARK: - INPUT
var input = readLine()!.split(separator: " ")
let R = Int(input[0])!
let C = Int(input[1])!
let T = Int(input[2])!

var board = Array(repeating: Array(repeating: 0, count: C), count: R)
var airCleaner: [(i: Int, j: Int)] = []

for i in 0..<R {
    input = readLine()!.split(separator: " ")
    for j in 0..<input.count {
        board[i][j] = Int(input[j])!
        if Int(input[j])! == -1 {
            airCleaner.append((i, j))
        }
    }
}


// MARK: - LOGIC

func spread(_ r: Int, _ c: Int) -> Bool {
    if r < 0 || r >= R || c < 0 || c >= C {
        return false
    }
    
    if board[r][c] < 0 {
        return false
    }
    return true
}

func activateAirCleaner(_ r: Int, c: Int, value: Int) {
    if r < 0 || r >= R || c < 0 || c >= C {
        return
    }
    
    
}

for _ in 0..<T {
    // 1.미세먼지 확산 전
    var temp: [(i: Int, j: Int, v: Int)] = []
    for i in 0..<R {
        for j in 0..<C {
            if board[i][j] > 0 {
                var count = 0
                let value = board[i][j]/5
                if spread(i+1, j) {
                    temp.append((i+1,j,value))
                    count += 1
                }
                
                if spread(i-1, j) {
                    temp.append((i-1,j,value))
                    count += 1
                }
                
                if spread(i, j+1) {
                    temp.append((i,j+1,value))
                    count += 1
                }
                
                if spread(i, j-1) {
                    temp.append((i,j-1,value))
                    count += 1
                }
                
                board[i][j] -= (count*value)
            }
        }
    }
    
    // 1-2.미세먼지 확산 후
    for tup in temp {
        board[tup.i][tup.j] += tup.v
    }
    
//    for a in board {
//        print(a)
//    }
    
    // 2.공기청정기 작동 - 언제나 1번 열에 위치
    for i in 0..<airCleaner.count {
        let row = airCleaner[i].i
        if i == 0 { // 위쪽 바람 - 반시계
            var previous = 0
            // →
            for c in 1..<C {
                let temp = previous
                previous = board[row][c]
                board[row][c] = temp
            }
            // ↑
            for r in stride(from: row-1, to: -1, by: -1) {
                let temp = previous
                previous = board[r][C-1]
                board[r][C-1] = temp
            }
            // ←
            for c in stride(from: C-2, to: -1, by: -1) {
                let temp = previous
                previous = board[0][c]
                board[0][c] = temp
            }
            // ↓
            for r in 1..<row {
                let temp = previous
                previous = board[r][0]
                board[r][0] = temp
            }
            
        } else { // 아래쪽 바람 - 시계
            var previous = 0
            // →
            for c in 1..<C {
                let temp = previous
                previous = board[row][c]
                board[row][c] = temp
            }
            // ↓
            for r in row+1..<R {
                let temp = previous
                previous = board[r][C-1]
                board[r][C-1] = temp
            }
            // ←
            for c in stride(from: C-2, to: -1, by: -1) {
                let temp = previous
                previous = board[R-1][c]
                board[R-1][c] = temp
            }
            // ↑
            for r in stride(from: R-2, to: row, by: -1) {
                let temp = previous
                previous = board[r][0]
                board[r][0] = temp
            }
        }
    }
    
//    for a in board {
//        print(a)
//    }
//
}

var answer = 0
for r in 0..<R {
    for c in 0..<C {
        if board[r][c] > 0 {
            answer += board[r][c]
        }
    }
}

// MARK: OUTPUT
print(answer)
