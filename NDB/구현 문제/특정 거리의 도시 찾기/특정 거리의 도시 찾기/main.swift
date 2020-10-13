//
//  main.swift
//  특정 거리의 도시 찾기
//
//  Created by 원현식 on 2020/10/11.
//

import Foundation

let input = readLine()!.split(separator: " ")

let N = Int(input[0])! // 노드
let M = Int(input[1])! // 간선의 개수 - 단방향
let K = Int(input[2])!
let X = Int(input[3])! // 출발 노드

var city = Array(repeating: [Int](), count: N+1)
var distance = Array(repeating: -1, count: N+1)

for _ in 0..<M {
    let input = readLine()!.split(separator: " ")
    let start = Int(input[0])!
    let dest = Int(input[1])!
    
    city[start].append(dest)
}

func bfs(_ start: Int) {
    distance[start] = 0
    var q = [Int]()
    q.append(start)
    
    while !q.isEmpty {
        let front = q.first!
        q.removeFirst()
        for next in city[front] {
            if distance[next] == -1 {
                distance[next] = distance[front] + 1
                q.append(next)
            }
        }
    }
    
}

bfs(X)
var check = false
for i in 1..<distance.count {
    if distance[i] == K {
        print(i)
        check = true
    }
}
if check == false {
    print(-1)
}
