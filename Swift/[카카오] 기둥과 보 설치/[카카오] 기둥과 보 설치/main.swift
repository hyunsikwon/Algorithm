//
//  main.swift
//  [카카오] 기둥과 보 설치
//
//  Created by 원현식 on 2020/09/02.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

// 0은 기둥, 1은 보
// 0은 삭제, 1은 설치

// x,y,a,b
// (x,y)에, a(기둥, 보)를 b(설치, 삭제) 해라
func solution(_ n:Int, _ build_frame:[[Int]]) -> [[Int]] {
    var frame = Array(repeating: Array(repeating: 4, count: n+1), count: n+1)
    let range = 0...n
    var result = [[Int]]()
    
    for info in build_frame {
        let x = n - info[1]
        let y = info[0]
        let a = info[2]
        let b = info[3]
        
        if b == 1 { // 설치
            
            if a == 0 { // 기둥 설치
                // 바닥
                guard x != 0 else { continue }
                if x == n {
                    frame[x][y] = a
                } else if y > 0 && frame[x][y-1] == 1 || y > 0 && frame[x][y-1] == 2 { // 보의 오른쪽 끝 위
                    if frame[x][y] == 1 {
                        frame[x][y] = 2
                    } else if frame[x][y] == 4 {
                        frame[x][y] = a
                    }
                    
                } else if x < n && frame[x+1][y] == 0 || x < n && frame[x+1][y] == 2 { // 기둥 위
                    if frame[x][y] == 1 {
                        frame[x][y] = 2
                    } else if frame[x][y] == 4 {
                        frame[x][y] = a
                    }
                }
                
            } else if a == 1 { // 보 설치
                
                guard y != n else { continue }
                
                if  (frame[x+1][y] == 0 && x < n) || (frame[x+1][y+1] == 0 && x < n && y < n)
                    || (frame[x+1][y] == 2 && x < n) || (frame[x+1][y+1] == 2 && x < n && y < n) { // 기둥 위에 있는 경우
                    if frame[x][y] == 0 {
                        frame[x][y] = 2
                    } else if frame[x][y] == 4 {
                        frame[x][y] = a
                    }
                    
                    
                } else if y > 0 && y < n && frame[x][y-1] == 1 && frame[x][y+1] == 1
                    || y > 0 && y < n && frame[x][y-1] == 2 && frame[x][y+1] == 2 { //양 옆에 보가 있는 경우
                    if frame[x][y] == 0 {
                        frame[x][y] = 2
                    } else if frame[x][y] == 4 {
                        frame[x][y] = a
                    }
                }
                
            }
            
        } else { // 삭제
            let temp = frame[x][y]
            frame[x][y] = 4
            if isPossible(frame, n) == true {
                continue
            } else {
                frame[x][y] = temp
            }
        }
    }
    
    for i in range {
        for j in range {
            guard frame[i][j] != 4 else { continue }
            
            let x = j
            let y = n - i
            let a = frame[i][j]
            
            if a == 2 {
                result.append([x,y,0])
                result.append([x,y,1])
            } else {
                result.append([x,y,a])
            }
            
            
        }
        
    }
    
    for i in range {
        for j in range {
            print(frame[i][j], terminator: " ")
        }
        print()
    }
    
    result.sort { (a, b) -> Bool in
        if a[0] != b[0] {
            return a[0] < b[0]
        } else if a[0] == b[0]{
            return a[1] < b[1]
        } else {
            return a[2] < b[2]
        }
    }
    
    return result
}


func isPossible(_ frame: [[Int]], _ size: Int) -> Bool {
    for i in 0...size {
        for j in 0...size {
            guard frame[i][j] != 4 else { continue }
            
            if frame[i][j] == 0 { // 기둥
                if (j > 0 && frame[i][j-1] == 1) || (j > 0 && frame[i][j-1] == 2) { // 기둥이 보 위에 있으면 ok
                    continue
                }
                
                if i == size { // 기둥이 바닥에 있으면 ok
                    continue
                }
                
                if (i < size && frame[i+1][j] == 0) || (i < size && frame[i+1][j] == 2) { // 기둥이 기둥위에 있으면 ok
                    continue
                }
                
                return false
                
            } else { // 보
                if (i < size && frame[i+1][j] == 0) || (i < size && frame[i+1][j] == 2) { // 왼쪽 모서리가 기둥 위에 있을 때
                    continue
                }
                
                if (i < size && j < size && frame[i+1][j+1] == 0) || (i < size && j < size && frame[i+1][j+1] == 2 ){ // 오른쪽 모서리가 기둥 위에 있을 때
                    continue
                }
                
                if (j > 0 && j < size && frame[i][j-1] == 1 && frame[i][j+1] == 1) || (j > 0 && j < size && frame[i][j-1] == 2 && frame[i][j+1] == 2) { // 양 옆에 보가 있을 때
                    continue
                }
                
                return false
                
            }
            
        }
    }
    
    return true
}


let n = 5 // 벽면의 크기
let build_frame = [[0,0,0,1],[2,0,0,1],[4,0,0,1],[0,1,1,1],[1,1,1,1],[2,1,1,1],[3,1,1,1],[2,0,0,0],[1,1,1,0],[2,2,0,1]]


// result: [[0,0,0],[0,1,1],[1,1,1],[2,1,1],[3,1,1],[4,0,0]]
print(solution(n, build_frame))
