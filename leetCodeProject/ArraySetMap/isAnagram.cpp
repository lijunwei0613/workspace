//
// Created by a3412 on 2022/4/30.
//
#include <string>
#include <iostream>

using namespace std;

/*
 *数组-简答哈希表 定义一个数组记录字符串s里字符出现的次数
 * 定义的数组record，大小为26，初始化为0， 字符a到字符z的ascll是26个连续的数值；
 * record用来记录字符串s里字符出现的次数；
 * 把字符映射到数组（字符串元素对应到1-26个字母上）也就是哈希表的索引下标上（0-25）
 * 01234567.。。。。。。。。。。。。。
 * 000000000000000000000000000000
 * 10001/2
 * 在遍历s字符串数组首个元素时如a 则对应个数是1，再向后移动一位还是a就是2，若是e则对应第5位变成1；依次类推；
 * 遍历字符串s时，需要将s[1] -'a'所在元素做+1操作，即在遍历过程中
 */
//字母异位词 :出现的字符和次数完全一致称为字母异位词；
class Solution {
public:
    bool isAnagram(string s, string t) {  //字符串的长度得是相等的；
        int record[26] = {0};  //定义一个数组，记录字符串s里字符出现的次数；
        //定义数组的大小为26，并初始化为0，因为字符a到字符z的ASCLL是26个连续的数值；
        //再遍历字符串s时，只需要将s[i]-'a'所在的元素+1
        for (int i = 0; i < s.size(); i++) {
            record[s[i] - 'a']++;  //返回   s[i] - ‘a’ 所在的元素做+1 操作
        }
        //在遍历字符串t时，只需要将t[i]-'a'所在的元素-1
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                cout << "false" << endl;
                return false;
            }
        }

        cout << "true" << endl;
        return true;
    }
};

int main() {
    string S = "anagram";
    string T = "nagaram";
    Solution p1;
    p1.isAnagram(S, T);

}