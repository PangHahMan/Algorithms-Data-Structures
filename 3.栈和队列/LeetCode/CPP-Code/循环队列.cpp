//https://leetcode.cn/problems/design-circular-queue/solutions/1713181/she-ji-xun-huan-dui-lie-by-leetcode-solu-1w0a/
/* 思路：
在环形队列中，队列为空时，队头队尾指向同一个位置。当队列不为空时，队头指向插入的第一个数据，队尾指向最后一个数据的下一个位置。当tail+1等于front时，说明环形队列已满。
注意：环形队列的队尾不能像常规队列中队尾一样指向最后一个数据，如果这样的话，我们将不能区别环形队列的状态是空还是满，因为此时队头和队尾都指向同一个位置。这就意味着，我们必须留出一个空间，这个空间不能存放数据，这样我们才能很好的区别环形队列的状态是空还是满。 
*/

#include <vector>
using namespace std;
class MyCircularQueue {
private:
    int front;
    int rear;
    int capacity;
    vector<int> elements;

public:
    MyCircularQueue(int k) {
        this->capacity = k + 1;
        this->elements = vector<int>(capacity);
        rear = front = 0;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        elements[rear] = value;
        rear = (rear + 1) % capacity;  //更新rear,防止越界
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;   //更新front，防止越界
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return elements[front];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return elements[(rear - 1 + capacity) % capacity];   //取队尾
    }

    bool isEmpty() {
        return rear == front;
    }

    bool isFull() {
        return ((rear + 1) % capacity) == front;   //队列满
    }
};
