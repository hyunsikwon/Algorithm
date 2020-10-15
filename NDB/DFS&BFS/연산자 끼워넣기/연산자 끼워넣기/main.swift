//
//  main.swift
//  연산자 끼워넣기
//
//  Created by 원현식 on 2020/10/15.
//

import Foundation

// MARK: - Input
let N = Int(readLine()!)!

var arr = Array(repeating: 0, count: N)
var op = Array(repeating: 0, count: 4)
var input = readLine()!.split(separator: " ")

for i in 0..<N {
    arr[i] = Int(input[i])!
}

input = readLine()!.split(separator: " ")

for i in 0..<4{
    op[i] = Int(input[i])!
}

// MARK: - main
var results = [Int]() // 연산의 모든 결과
var temp = [Int]() // 경우의 수 중 하나
var count = 0
func dfs(_ depth: Int) {
    if depth == N-1 {
        calculate(temp)
        count += 1
        return
    }
    
    for i in 0..<4 {
        guard op[i] > 0 else { continue }
        temp.append(i)
        op[i] -= 1
        
        dfs(depth+1)
        
        temp.removeLast()
        op[i] += 1
    }
}

dfs(0)
print(count)
func calculate(_ temp: [Int]) {
    var answer = 0
    for j in 0..<arr.count {
        if j == 0 { answer = arr[j] }
        else {
            switch temp[j-1] {
            case 0:
                answer += arr[j]
            case 1:
                answer -= arr[j]
            case 2:
                answer *= arr[j]
            case 3:
                answer /= arr[j]
            default:
                break
            }
            
        }
    }
    results.append(answer)
    
}


//print(results)
// MARK: - Output
print(results.max() ?? 0)
print(results.min() ?? 0)
