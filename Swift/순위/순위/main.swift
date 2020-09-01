//
//  main.swift
//  순위
//
//  Created by 원현식 on 2020/09/01.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation



func solution(_ n:Int, _ results:[[Int]]) -> Int {
    let INF = Int.max/2
    var matrix = Array(repeating: Array(repeating: INF, count: n), count: n)
    var temp = Array(repeating: 0, count: n)
    var answer = 0
    for result in results {
        let winner = result.first! - 1
        let loser = result.last! - 1
        
        matrix[winner][loser] = 1
    }
    
    for k in 0..<n {
        for i in 0..<n {
            for j in 0..<n {
                if i == j {
                    matrix[i][j] = 0
                    continue
                }
                
                if matrix[i][k] + matrix[k][j] < matrix[i][j] {
                    matrix[i][j] = matrix[i][k] + matrix[k][j]
                }
                
            }
        }
    }
    
    for i in 0..<matrix.count {
        for j in  0..<matrix[i].count {
            if matrix[i][j] != INF, matrix[i][j] != 0 {
                temp[i] += 1 // 승
                temp[j] += 1 // 패
            }
        }
    }
 
    temp.forEach { if $0 == (n-1) {answer += 1} }
    
    return answer
}


let n = 5
let results = [[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]


//let n = 3
//let results = [[1, 2], [3, 2]]

// RETURN: 2
print(solution(n, results))

// 실패 코드
//func dfs(_ current: Int, _ board: inout [[Int]], _ visited: inout [Bool]) {
//    if !board[current].contains(1)  {
//        return
//    }
//
//    for i in 0..<board[current].count {
//        guard board[current][i] == 1 else { continue }
//        visited[i] = true
//        dfs(i, &board, &visited)
//    }
//
//}
//
//func solution(_ n:Int, _ results:[[Int]]) -> Int {
//    var board = Array(repeating: Array(repeating: 0, count: n), count: n)
//    var visited = Array(repeating: false, count: n)
//    var answer = Array(repeating: 0, count: n)
//    var count = 0
//
//    for result in results {
//        let winner = result[0] - 1
//        let loser = result[1] - 1
//
//        board[winner][loser] = 1
//    }
//
//    for i in 0..<n {
//
//        dfs(i, &board, &visited)
//
//        print(visited)
//
//        for j in 0..<visited.count {
//            if visited[j] == true {
//                answer[j] += 1 // 패
//                answer[i] += 1 // 승
//            }
//        }
//
//        visited = Array(repeating: false, count: n)
//
//
//    }
//
//    print(answer)
//    for value in answer {
//        if value == n-1 {
//            count += 1
//        }
//    }
//
//    return count
//}

