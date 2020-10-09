//
//  main.swift
//  치킨 배달
//
//  Created by 원현식 on 2020/10/09.
//

import Foundation


let input1 = readLine()!.split(separator: " ")
let N = Int(input1[0])!
let M = Int(input1[1])!

var houses = [(row: Int, col: Int)]()
var chickens = [(row: Int, col: Int)]()

// 1은 집 2는 치킨집
for i in 1...N {
    let input2 = readLine()!.split(separator: " ")
    for j in 1...input2.count {
        if Int(input2[j-1])! == 1 {
            houses.append((i,j))
        } else if Int(input2[j-1])! == 2 {
            chickens.append((i,j))
        }
    }
}

var result = 99999

var temp = [Int]()

func comb(_ current: Int) {
    if temp.count == M { // 전체 치킨 집에서 M개를 뽑았을 때
        var answer = 0 // 해당 조합 도시의 치킨 거리
        for house in houses {
            var min = 1000
            for i in temp {
                let chicken = chickens[i]
                let distance = abs(house.row - chicken.row) + abs(house.col - chicken.col)
                
                if distance < min {
                    min = distance
                }
            }
            answer += min
        }
        
        if answer < result {
            result = answer
        }
        
        return
    }
    
    for i in current..<chickens.count {
        guard !temp.contains(i) else { continue }
        temp.append(i)
        comb(i)
        temp.removeLast()
    }
}

comb(0)

print(result)

