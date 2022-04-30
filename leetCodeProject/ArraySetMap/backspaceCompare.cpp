//
// Created by a3412 on 2022/4/26.
//
#include <iostream>
#include <vector>

using namespace std;
//给定s和t两个字符串，当他们分别被输入到空白的文本编辑器中，如果两者相等则返回true;
//匹配使用栈

//时间复杂度O(n+m) 空间复杂度O(n+m) n为S的长度， m为T的长度；
class Slution {
public:
    string getString(const string &S) {
        string s;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] != '#') s += S[i];
            else if (!s.empty()) {
                s.pop_back();
            }
        }
        return s;
    }

public:
    bool backspaceCompare(string S, string T) {  //将重复的逻辑抽象成函数
        return getString(S) == getString(T);
    }
};

//优化后的空间复杂度O(1)的空间复杂度
//同时从后向前遍历S和T（i和j是S和T的末尾）， 记录#数量，模拟消除的操作，如果#用完就开始比较S[i]和S[j];
//如果S[i]和T[j]不相同返回false, 如果有一个指针（i或者j）先走到字符串头部位置，返回false;
class Slution01 {
public:
    bool backspaceCompare(string S, string T) {
        int sSkipNum = 0;  //记录S的#数量
        int tSkipNum = 0;  //记录T的#数量
        int i = S.size() - 1;
        int j = T.size() - 1;

        while (1) {
            while (i >= 0) { //从后向前消除S的#;
                if (S[i] == '#') sSkipNum++;
                else {
                    if (sSkipNum > 0) sSkipNum--;
                    else break;
                }
                i--;
            }
            while (j >= 0) {   //从后向前消除T的#;
                if (T[j] == '#') tSkipNum++;
                else {
                    if (tSkipNum > 0) tSkipNum--;
                    else break;
                }
                j--;
            }
            if (i < 0 || j < 0) break;  //S或者T遍历到头；
            if (S[i] != T[j]) return false;
            i--;
            j--;
        }
        // 说明S和T同时遍历完毕
        if (i == -1 && j == -1) return true;
        return false;
    }
};
