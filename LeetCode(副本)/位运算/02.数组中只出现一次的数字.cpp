/* 描述
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*/

#include <vector>
using namespace std;

/*我们可以让数组中的每一个数异或一下，最后会得到一个结果ret，就是两个出现一次的数字的异或结果这个结果肯定是由两个不同数字异或而来，因此我们找ret二进制中为1的位置i，因为1一定是由0,1异或而来，因此要求得两个数中，一定有一个数的二进制中的第i个位置为1， 一个为0.  
也就是两个不同的数字中，第i个位置为1的数字肯定是不同的
 */
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2) {
        if (num1 == nullptr || num2 == nullptr) {
            return;
        }

        //1.整体异或
        int result = data[0];
        for (int i = 1; i < data.size(); i++) {
            result ^= data[i];
        }

        //2.分解找到第一个比特位为1
        int flag = 1;
        int length = sizeof(int);
        for (int i = 0; i < length; i++) {
            if ((flag << i) & result) {
                flag <<= i;  //找到1的位置
                break;
            }
        }

        //3.分组异或
        *num1 = 0;
        *num2 = 0;
        for(int i = 0; i<data.size();i++){
            if(data[i] & flag){
                *num1 ^= data[i];
            }else{
                *num2 ^= data[i];
            }
        }

    }
};

//https://www.nowcoder.com/practice/e02fdb54d7524710a7d664d082bb7811?