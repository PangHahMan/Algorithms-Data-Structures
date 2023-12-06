#include <unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr) {
            return nullptr;
        }
        Node *cur = head;
        unordered_map<Node *, Node *> map;
        // 3. 复制各节点，并建立 “原节点 -> 新节点” 的 Map 映射
        while (cur != nullptr) {
            map[cur] = new Node(cur->val);//通过cur建立键值对
            cur = cur->next;
        }
        cur = head;
        // 4. 构建新链表的 next 和 random 指向
        while (cur != nullptr) {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }
        // 5. 返回新链表的头节点
        return map[head];
    }
};

//https://leetcode.cn/problems/copy-list-with-random-pointer/description/