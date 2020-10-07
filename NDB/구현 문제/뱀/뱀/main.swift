//
//  main.swift
//  뱀
//
//  Created by 원현식 on 2020/10/06.
//

import Foundation

let N = Int(readLine()!)! // 보드의 크기 N X N
let K = Int(readLine()!)! // 사과의 개수

var board = Array(repeating: Array(repeating: 0, count: N+1), count: N+1)

// 사과의 위치
for _ in 0..<K {
    let input = readLine()!.split(separator: " ")
    let row = Int(input[0])!
    let col = Int(input[1])!
    board[row][col] = -1
}

let L = Int(readLine()!)! // 뱀의 방향 전환 횟수
var moveData: [(Int, String)] = []
for _ in 0..<L {
    let input = readLine()!.split(separator: " ")
    moveData.append((Int(input[0])!, String(input[1])))
}

board[1][1] = 1
var time = 0
var size = 1

enum Direction: Int {
    case up = 1
    case down = 2
    case left = 3
    case right = 4
}

var direction = Direction.right

func move(row: Int, col: Int) {
    if row <= 0 || col <= 0 || row > N || col > N || board[row][col] > 0 {
        print(time+1)
        return
    }
    time += 1
    
    if board[row][col] == -1 { // 사과가 있으면
        size += 1
        board[row][col] = size
    } else {
        for i in 1...N { // 사이즈 조정
            for j in 1...N {
                guard board[i][j] > 0 else { continue }
                board[i][j] -= 1
            }
        }
        board[row][col] = size
    }
    
    if !moveData.isEmpty, moveData.first!.0 == time { // 방향 전환
        let c = moveData.first!.1
        moveData.removeFirst()
        
        if c == "L" {
            switch direction {
            case .up:
                direction = .left
            case .down:
                direction = .right
            case .left:
                direction = .down
            case .right:
                direction = .up
            }
        } else {
            switch direction {
            case .up:
                direction = .right
            case .down:
                direction = .left
            case .left:
                direction = .up
            case .right:
                direction = .down
            }
        }
    }
    
    switch direction {
    case .up:
        move(row: row-1, col: col)
    case .down:
        move(row: row+1, col: col)
    case .left:
        move(row: row, col: col-1)
    case .right:
        move(row: row, col: col+1)
    }
    
    
}

move(row: 1, col: 2)


//for i in 1...N {
//    for j in 1...N {
//        print(board[i][j], terminator: " ")
//    }
//    print()
//}
//
//print(moveData)

/*
6
3
3 4
2 5
5 3
3
3 D
15 L
17 D
*/
