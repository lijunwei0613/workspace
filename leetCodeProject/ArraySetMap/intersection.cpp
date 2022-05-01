//
// Created by a3412 on 2022/4/30.
//

//#include <string>
#include <iostream>
//#include <algorithm>
#include <vector>
//#include <functional>
//#include <numeric>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        //存放交集的集合，并且采用哈希表进行自动去重
        unordered_set<int> result_set;
        //将nums1中的元素拷贝存入num_set容器当中；
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num: nums2) {   //等价于： for(int num = 0; num < nums2.size(); num++
            //查找nums2中指定元素，如相同元素2，返回指定元素的迭代器，直至返回结束迭代器之后终止遍历；
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
                cout << "yes, it is intersection!" << endl;
                cout << *(nums_set.find(num)) << endl;
            } else{
                cout << "no intersection" << endl;
            }
        }

        return vector<int>(result_set.begin(), result_set.end());
    }
};

int main() {
    vector<int> num1 = {1, 2, 2, 1};
    vector<int> num2 = {2, 2};

    Solution p1;
    p1.intersection(num1, num2);
}