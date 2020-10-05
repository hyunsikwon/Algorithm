//
//  main.swift
//  문자열 재정렬
//
//  Created by 원현식 on 2020/10/05.
//

import Foundation

let S = readLine()!
var arr = [] + S;
var str = [String]()
var num = 0

for a in arr {
    if Int(String(a)) == nil {
        str.append(String(a))
    } else {
        num += Int(String(a))!
    }
}

str.sort()

var result = ""
for a in str {
    result += String(a)
}

result += String(num)

print(result)

// AJKDLSI412K4JSJ9D
// K1KA5CB7
