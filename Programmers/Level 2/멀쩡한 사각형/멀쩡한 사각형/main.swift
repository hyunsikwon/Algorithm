//
//  main.swift
//  멀쩡한 사각형
//
//  Created by 원현식 on 2020/05/11.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let W = 8
let H = 12
print(solution(W, H))

func solution(_ w:Int, _ h:Int) -> Int64{
    var answer: Int64 = 0
    
    let max = w < h ? w : h
    var i = 1
    var gcd = 0
    
    while i <= max  {
        if w % i == 0 && h % i == 0 {
            gcd = i
        }
        
        i+=1
    }

    answer = Int64((w*h) - ((h/gcd)+(w/gcd)-1)*gcd)
    
    return answer
}

/*
 반복되는 사각형의 크기는 가로, 세로 길이의 최대공약수로 각각을 나눈 값이다
 위의 예에서 최대공약수는 4이므로 가로는 2 세로는 3 크기의 직사각형이 최대 공약수만큼 반복된다.
 ㅋ
 */

