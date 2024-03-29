/* 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。 
*/
#include <vector>
using namespace std;

/* 解题思路：
这道题原题是不需要保证奇偶位置不变的。
现在新增了需求，解决方法也比较多，我们用较优方式解决一下，借鉴一下插入排序的思想 
*/
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int k = 0;// 用来放奇数的下标
        for (int i = 0; i < array.size(); i++) {
            if (array[i] % 2 == 1) {
                //遇到奇数，挪动位置，挪动k+1~i之间的位置
                int tmp = array[i];//现将当前奇数保存起来
                for (int j = i; j > k; j--) {
                    //将该奇数之前的内容(偶数序列)，整体后移一个位置
                    array[j] = array[j - 1];
                }
                //将奇数保存在它将来改在的位置，因为我们是从左往右放的，没有跨越奇数，所以一定是相对位置不变的
                array[k++] = tmp;
            }
        }
    }
};

//https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?