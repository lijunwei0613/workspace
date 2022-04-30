//
// Created by a3412 on 2022/4/25.
//

/*
 * 给定一个数组nums, 编写一个函数将所有0移动到数组的末尾，同时保持非零元素的相对顺序；
 */

#include <iostream>
#include <vector>

/*
 * 使用双指针，左指针指向当前已经处理好的序列的尾部，右指针指向待处理序列的头部
 *
 */

using namespace std;

class Solution {
public:
    void moveZero(vector<int> &nums) {
        int left = 0, right = 0, n = nums.size();
        while (right < n) {
            if (nums[right]) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};

int main() {
    Solution p1;
    int a[] = {0, 1, 0, 3, 12};
    std::vector<int> vect(a, a + sizeof(a) / sizeof(int));

    p1.moveZero(vect);
    for (int i = 0; i < vect.size(); ++i) {
        cout << a[i]<< endl;
    }
}