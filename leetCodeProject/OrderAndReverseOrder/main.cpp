#include <iostream>
#include <stack>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

//????????????????
class Solution {
public:
    int search(vector<int> &nums, int target) {

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            cout << "nums?" << nums[i] << endl;
        }

        if (nums.empty()) //?????????
            return -1;
        if (nums.size() == 1) {
            if (nums[0] == target)
                return 0;
            return -1;
        }

        int len = nums.size(); // nums??????
        int i = 0;
        int j = len - 1;
        int mid = 0;
        while (i <= j) {
            mid = i + (j - i) / 2;//??????
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > target) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }

        cout << "????" << mid << endl;

        return nums[mid] = target ? mid : -1;
    }
};


class Solution1 {
public:
    void push(int node) {
        sp1.push(node);
    }

    int pop() {
        if (sp2.empty()) {
            while (!sp1.empty()) {
                sp2.push(sp1.top());
                sp1.pop();
            }
        }
        int ret = sp2.top();
        sp2.pop();
        return ret;
    }

private:
    stack<int> sp1;
    stack<int> sp2;
};

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}

};


class Solution11 {
public:
    ListNode *ReverseList(ListNode *pHead) {
        if (pHead == nullptr || pHead->next == nullptr) return pHead;
        ListNode *pReverseNode = ReverseList(pHead->next);
        pHead->next->next = pHead;
        pHead->next = nullptr;

        return pReverseNode;
    }
};



//set???????????????
class Person {
public:
    Person(string name, int age) {
        this->m_Name;
        this->m_age;
    }

    string m_Name;
    int m_age;
};

class comparePerson{
public:
    bool operator() (const Person &p1, const Person &p2 ){
        return p1.m_age > p2.m_age;
    }

};


void test01() {
    set<Person, comparePerson> s;

    //??Person???
    Person s1("a", 11);
    Person s2("b", 10);
    Person s3("c", 8);
    Person s4("d", 20);
    
    s.insert(s1);
    s.insert(s2);
    s.insert(s3);
    s.insert(s4);

    for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++) {
        cout << "???" << it->m_Name << "???" << it->m_age << endl;
    }


}


int main() {

    test01();

    vector<int> v;
    v.push_back(0);
    v.push_back(-1);
    v.push_back(10);
    v.push_back(4);
    v.push_back(6);
    v.push_back(3);
    v.push_back(14);
    v.push_back(13);

    Solution p;
    p.search(v, 13);

//    vector<int> v;
//    v.push_back();
//    v.push_back();
//    v.push_back();
//    v.push_back();


//cout << "wsl" << endl;
    return 0;
}
