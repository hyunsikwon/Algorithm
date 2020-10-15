//
//  main.swift
//  경쟁적 전염
//
//  Created by 원현식 on 2020/10/14.
//

import Foundation

// MARK: - input

var input = readLine()!.split(separator: " ")

let N = Int(input[0])!
let K = Int(input[1])!

var board = Array(repeating: Array(repeating: 0, count: N+1), count: N+1)
var visited = Array(repeating: Array(repeating: false, count: N+1), count: N+1)

for i in 1...N {
    input = readLine()!.split(separator: " ")
    for j in 1...input.count {
        board[i][j] = Int(input[j-1])!
        if board[i][j] > 0 {
            visited[i][j] = true
        }
    }
}

input = readLine()!.split(separator: " ")

let S = Int(input[0])!
let X = Int(input[1])!
let Y = Int(input[2])!


// MARK: - logic

func virus(_ i: Int, _ j: Int, _ formerValue: Int) {
    guard i > 0, i <= N, j > 0, j <= N else { return }
    guard visited[i][j] == false else { return }
    
    if board[i][j] == 0 {
        board[i][j] = formerValue
    } else if formerValue < board[i][j]  {
        board[i][j] = formerValue
    }
    
}

for _ in 0..<S {
    
    for i in 1...N {
        for j in 1...N {
            guard visited[i][j] == true else {continue}
            virus(i+1, j, board[i][j])
            virus(i-1, j, board[i][j])
            virus(i, j+1, board[i][j])
            virus(i, j-1, board[i][j])
        }
    }
    
    for i in 1...N {
        for j in 1...N {
            guard board[i][j] != 0 else {continue}
            visited[i][j] = true
        }
    }
    
}

// MARK: - output
//for a in board {
//    print(a)
//}
print(board[X][Y])
