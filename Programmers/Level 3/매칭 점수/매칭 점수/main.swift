//
//  main.swift
//  매칭 점수
//
//  Created by 원현식 on 2020/11/05.
//

import Foundation

func makeURL(_ str: String) -> String {
    var temp = ""
    var url = ""
    var flag = false
    for char in str {
        if String(char) >= "a" && String(char) <= "z" {
            if flag == true {
                url += String(char)
            }
            temp += String(char)
        } else {
            if temp == "content" {
                flag = true
                continue
            }
            if flag == true {
                if String(char) == ">" {
                    break
                }
                if String(char) == "\""{
                    continue
                }
                url += String(char)
                
            }
            temp = ""
            
        }
    }
    
    url.removeLast()
    return url
}

func makeLink(_ str: String) -> String {
    var link = ""
    var c = false
    for char in str {
        if char == "\"" {
            if link.count > 0 {
                break
            }
            c = true
            continue
        }
        
        if c == true {
            link += String(char)
        }
    }
    return link
}

func check(_ targetWord: String, _ str: String) -> Int {
    var tmpStr = ""
    var count = 0
    for char in str.lowercased() {
        if (String(char) >= "a" && String(char) <= "z") {
            tmpStr += String(char)
        } else {
            if tmpStr == targetWord {
                count += 1
            }
            tmpStr = ""
        }
    }
    if tmpStr == targetWord {
        count += 1
    }
    
    return count
}

func solution(_ word:String, _ pages:[String]) -> Int {
    var results = [(url: String, defaultValue: Int, links: [String], matching: Double)]()
    let checkWord = word.lowercased()
    
    
    for i in 0..<pages.count {
        let page = pages[i].split(separator: "\n")
        var result: (url: String, defaultValue: Int, links: [String], matching: Double) = ("",0,[], 0.0)
        var checkHead = false
        var checkBody = false
        
        // 각각의 페이지 검사
        for str in page {
            if checkHead == true {
                if str.contains("og:url") {
                    // 현재 웹페이지의 url
                    result.url = makeURL(String(str))
                    checkHead = false
                    continue
                }
                
            } else if checkBody == true {
                if str.contains("href") {
                    result.links.append(makeLink(String(str)))
                }
                result.defaultValue += check(checkWord, String(str))
            }
            
            if str == "<head>" {
                checkHead = true
                continue
            } else if str == "<body>" {
                checkBody = true
                continue
            } else if str == "</body>" {
                break
            }
        }
        
        results.append(result)
    }
    
    // 점수 계산
    for i in 0..<results.count {
        let links = results[i].links // 자신이 참조하는 웹 링크
        for j in 0..<results.count {
            guard i != j else {continue }
            
            if links.contains(results[j].url) {
                let v = Double(results[i].defaultValue)/Double(results[i].links.count)
                results[j].matching += v
            }
        }
    }
    
    for i in 0..<results.count {
        results[i].matching += Double(results[i].defaultValue)
        print(results[i])
    }
    
    
    // 결과
    var max = 0.0
    var index = 0
    for i in 0..<results.count {
        if results[i].matching > max {
            max = results[i].matching
            index = i
        }
        
    }
    return index
}


let word = "blind"
let pages = ["<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"]




print(solution(word, pages))

