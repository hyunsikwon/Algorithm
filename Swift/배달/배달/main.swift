//
//  main.swift
//  배달
//
//  Created by 원현식 on 2020/05/14.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let N = 1
var road = [[1,1,0]]
let k = 3
print(solution(N,road,k))


func choose(_ distance: [Int], _ n: Int, _ visited: [Bool]) -> Int {

    var min = 999999
    var minPos = -1
    for i in 1...n {
        if visited[i] == false && distance[i] < min {
            min = distance[i]
            minPos = i
        }
    }
    return minPos
}

func solution(_ N:Int, _ roads:[[Int]], _ k:Int) -> Int {
    var answer = 0
    var weigth = [[Int]](repeating: Array(repeating: 0, count: N+1), count: N+1) // 노드들간 거리들
    var distance = [Int](repeating: 0, count: N+1) // 1번 노드부터 각 노드까지의 거리
    var visited = [Bool](repeating: false, count: N+1)
    
    if N == 1 {
        return 1
    }
    
    for i in 0..<roads.count {
        let road = roads[i]
        if  weigth[road[0]][road[1]] != 0 &&  weigth[road[0]][road[1]] < road[2]  {
            continue
        }
        weigth[road[0]][road[1]] = road[2]
        weigth[road[1]][road[0]] = road[2]
    }

    for i in 1...N {
        for j in 1...N {
            if j != i && weigth[i][j] == 0{
                weigth[i][j] = 999999
            }
        }
    }
    
    var currentNode = 1
    visited[currentNode] = true
    for i in 1...N {
        distance[i] = weigth[currentNode][i]
    }
    
    for _ in 2...N {
        currentNode = choose(distance, N, visited)
        visited[currentNode] = true
        for i in 1...N {
            if visited[i] == false {
                if distance[currentNode] + weigth[currentNode][i] < distance[i] {
                    distance[i] = distance[currentNode] + weigth[currentNode][i]
                }
            }
        }
    }
    
    for i in 2...N {
        if  distance[i] != 0 && distance[i] <= k {
            answer+=1
        }
    }
    return answer+1
}
