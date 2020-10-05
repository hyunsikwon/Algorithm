//
//  main.swift
//  럭키 스트레이트
//
//  Created by 원현식 on 2020/10/05.
//

import Foundation


var N = readLine()!
var arr = [] + N
var half = N.count/2

var left = 0
var right = 0

for i in 1...arr.count {
    let str = String(arr[i-1])
    if i <= half {
        left += Int(str)!
    } else {
        right += Int(str)!
    }
}

if left == right {
    print("LUCKY")
} else {
    print("READY")
}
