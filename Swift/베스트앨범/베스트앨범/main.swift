//
//  main.swift
//  베스트앨범
//
//  Created by 원현식 on 2020/09/02.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

func solution(_ genres:[String], _ plays:[Int]) -> [Int] {
    var bestAlbum = [Int]()
    var count = [String: [(Int,Int)]]()
    var total = [String: Int]()
    
    // 장르별 총 플레이 횟수 구하기
    for i in 0..<genres.count {
        let genre = genres[i]
        let play = plays[i]
        
        if total[genre] == nil {
            total[genre] = play
        } else if total[genre] != nil {
            total[genre]! += play
        }
    }
    
    // 장르 : (고유번호, 플레이 타임)
    for i in 0..<genres.count {
        let genre = genres[i]
        let play = plays[i]
        let temp = (i, play)
        
        if count[genre] == nil {
            count[genre] = [temp]
            
        } else if count[genre] != nil{
            
            count[genre]!.append(temp)
            count[genre]!.sort { (a, b) -> Bool in // 정렬
                if a.1 != b.1 {
                    return a.1 > b.1
                } else {
                    return a.0 < b.0
                }
            }
            
            
        }
    }
    
    // 플레이 횟수가 큰 순서대로 장르를 정렬
    let sortedT = total.sorted { $0.value > $1.value }
    for a in sortedT {
        let key = a.key
        
        while count[key]!.count > 2 {
            count[key]!.removeLast()
        }
        
        for (n, _) in count[key]! {
            bestAlbum.append(n)
        }
        
    }
    
    return bestAlbum
}

let genres = ["classic", "pop", "classic", "classic", "pop"]
let plays = [500, 600, 500, 800, 2500]

// RETURN [4, 1, 3, 0]
print(solution(genres, plays))
