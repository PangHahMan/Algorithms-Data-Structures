/* 描述
输入一个链表的头节点，按链表从尾到头的顺序返回每个节点的值（用数组返回）。 

示例1
输入：{1,2,3}
返回值：[3,2,1]

示例2
输入：{67,0,24,58}
返回值：[58,24,0,67]
*/

/* 链表问题
解题思路：
这道题整体解决思路很多，可以使用stack，可以递归，也可以将数据保存数组，逆序数组
我们可以三种方法都实现一下，具体可以酌情编写 
*/


#include <algorithm>
#include <stack>
#include <vector>
using namespace std;


//方法一，stack方式，这种方式会有内存占用过多的问题
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode *head) {
        stack<int> s;
        vector<int> v;
        while (head) {
            s.push(head->val);
        }
        while (!s.empty()) {
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }
};

//方法二，逆置数组
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode *head) {
        vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        reverse(v.begin(), v.end());
        return v;
    }
};

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

//方法3，递归
class Solution {
public:
    void Print(ListNode *head, vector<int> &v) {
        if (head == nullptr) {
            return;
        }

        Print(head->next, v);
        v.push_back(head->val);
    }
    vector<int> printListFromTailToHead(ListNode *head) {
        vector<int> v;
        Print(head, v);

        return v;
    }
};


//https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?