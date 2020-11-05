//
//  main.swift
//  주사위 굴리기_#14499
//
//  Created by 원현식 on 2020/11/05.
//

import Foundation

var input = readLine()!.split(separator: " ")
let n = Int(input[0])!
let m = Int(input[1])!
var x = Int(input[2])!
var y = Int(input[3])!
let k = Int(input[4])!

var map = Array(repeating: Array(repeating: 0, count: m), count: n)
var direction = [Int]()
        //  t  위  >  < 아래 b
var dice = [0, 0, 0, 0, 0, 0]

for i in 0..<n {
    input = readLine()!.split(separator: " ")
    for j in 0..<m {
        map[i][j] = Int(input[j])!
    }
}

input = readLine()!.split(separator: " ")

for a in input {
    direction.append(Int(a)!)
}

func moveDice(_ direction: Int){
    let temp = dice
    if direction == 1 { // 오른으로 굴림
        dice[0] = temp[3]
        dice[2] = temp[0]
        dice[3] = temp[5]
        dice[5] = temp[2]
    } else if direction == 2{ // 왼쪽으로 굴림
        dice[0] = temp[2]
        dice[2] = temp[5]
        dice[3] = temp[0]
        dice[5] = temp[3]
    } else if direction == 3 { // 위로 굴림

        dice[0] = temp[4]
        dice[1] = temp[0]
        dice[4] = temp[5]
        dice[5] = temp[1]
    } else if direction == 4 { // 아래로 굴림
        dice[0] = temp[1]
        dice[1] = temp[5]
        dice[4] = temp[0]
        dice[5] = temp[4]
    }
}

for d in direction {
    if d == 1 { // 동
        if y + 1 == m {
            continue
        }
        
        y += 1
        moveDice(d)
        if map[x][y] == 0{
            // 현재 지도의 칸에 주사위 바닥면 값을 복사
            map[x][y] = dice[5]
        } else {
            // 현재 지도의 칸에 적혀있는 값을 주사위 바닥면으로 복사
            dice[5] = map[x][y]
            map[x][y] = 0
        }
        
    } else if d == 2 { // 서
        if y - 1 < 0{
            continue
        }
        y -= 1
        moveDice(d)
        if map[x][y] == 0{
            map[x][y] = dice[5]
        } else {
            dice[5] = map[x][y]
            map[x][y] = 0
        }
        
    } else if d == 3 {// 북
        if x - 1 < 0 {
            continue
        }
        moveDice(d)
        x -= 1
        if map[x][y] == 0{
            map[x][y] = dice[5]
        } else {
            dice[5] = map[x][y]
            map[x][y] = 0
        }
    } else if d == 4 {// 남
        if x + 1 == n {
            continue
        }
        moveDice(d)
        x += 1
        if map[x][y] == 0{
            map[x][y] = dice[5]
        } else {
            dice[5] = map[x][y]
            map[x][y] = 0
        }
    }
    print(dice[0])
}

