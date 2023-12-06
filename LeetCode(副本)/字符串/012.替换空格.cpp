/* 描述
请实现一个函数，将一个字符串中的每个空格替换成"%20"。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 */


/* 字符串操作问题
解决思路：
虽然是替换问题，但是生成的字符串整体变长了.
因替换内容比被替换内容长，所以，一定涉及到字符串中字符的移动问题
移动方向一定是向后移动，所以现在的问题无非是移动多少的问题
因为是 ' ' -> "%20",是1换3，所以可以先统计原字符串中空格的个数(设为n)，然后可以计算出新字符串的长度
所以：new_length = old_length + 2*n
最后，定义新老索引（或者指针），各自指向新老空间的结尾，然后进行old->new的移动
如果是空格，就连续放入“%20”,其他平移即可。 
*/
class Solution {
public:
    void replaceSpace(char *str, int length) {
        int n = 0;
        char *start = str;
        //计算有多少个空格
        while (*start != '\0') {
            if (*start == ' ') {
                n++;
            }
            start++;
        }
        char *old_end = str + length;
        char *new_end = str + length + 2 * n;
        // 从后开始平移
        while (old_end >= str) {
            if (*old_end != ' ') {
                *new_end = *old_end;
                new_end--;
                old_end--;
            } else {
                //替换
                *(new_end--) = '0';
                *(new_end--) = '2';
                *(new_end--) = '%';
                old_end--;
            }
        }
    }
};

//https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?