//
//  main.swift
//  연구소
//
//  Created by 원현식 on 2020/10/13.
//

import Foundation

var input = readLine()!.split(separator: " ")

let N = Int(input[0])!
let M = Int(input[1])!

var board = Array(repeating: Array(repeating: 0, count: M), count: N)

for i in 0..<N {
    input = readLine()!.split(separator: " ")
    for j in 0..<input.count {
        board[i][j] = Int(input[j])!
    }
}

// 0은 빈칸 1은 벽 2는 바이러스


var result = 0 // 최종 결과

// 벽을 설치하는 모든 경우의 수
var temp = [Int]()
func comb(_ current: Int) {
    if temp.count == 3 {
        buildWall(location: temp)
        return
    }
    for i in current..<N*M {
        guard current != i, !temp.contains(i) else {continue}
        temp.append(i)
        comb(i)
        temp.removeLast()
    }
}

// 벽 설치
func buildWall(location: [Int]) {
    let first: (row: Int, col: Int) = (location[0]/M, location[0] % M)
    let second: (row: Int, col: Int) = (location[1]/M, location[1] % M)
    let third: (row: Int, col: Int) = (location[2]/M, location[2] % M)
    
    // 벽을 세워야할 위치에 바이러스 혹은 이미 벽이 있는 경우는 제외
    guard board[first.row][first.col] == 0,
          board[second.row][second.col] == 0,
          board[third.row][third.col] == 0  else { return }
    
    // 벽 세우기
    var tempBoard = board
    tempBoard[first.row][first.col] = 1
    tempBoard[second.row][second.col] = 1
    tempBoard[third.row][third.col] = 1

    // 바이러스 전파 후 결과
    for i in 0..<N {
        for j in 0..<M {
            if tempBoard[i][j] == 2 {
                virus(i+1, j, &tempBoard)
                virus(i-1, j, &tempBoard)
                virus(i, j+1, &tempBoard)
                virus(i, j-1, &tempBoard)
            }
        }
    }
  
//    for a in tempBoard{
//        print(a)
//    }
    
    var cnt = 0
    // 안전 영역 count
    for i in 0..<N {
        for j in 0..<M {
            if tempBoard[i][j] == 0 {
                cnt += 1
            }
        }
    }
    
    if cnt > result {
        result = cnt
    }
}

// 바이러스 전파
func virus(_ i: Int, _ j: Int, _ tmpBoard: inout [[Int]]) {
    guard i >= 0, i < N, j >= 0, j < M else { return }
    guard tmpBoard[i][j] == 0 else { return }
    
    tmpBoard[i][j] = 2
    
    virus(i+1, j, &tmpBoard)
    virus(i-1, j, &tmpBoard)
    virus(i, j+1, &tmpBoard)
    virus(i, j-1, &tmpBoard)
}

comb(-1)
print(result)
