/* 描述
A,B,C三个人是好朋友,每个人手里都有一些糖果,我们不知道他们每个人手上具体有多少个糖果,但是我们知道以下的信息：
A - B, B - C, A + B, B + C. 这四个数值.每个字母代表每个人所拥有的糖果数.
现在需要通过这四个数值计算出每个人手里有多少个糖果,即A,B,C。这里保证最多只有一组整数A,B,C满足所有题设条件。 

输入描述：输入为一行，一共4个整数，分别为A - B，B - C，A + B，B + C，用空格隔开。 范围均在-30到30之间(闭区间)。
输出描述：输出为一行，如果存在满足的整数A，B，C则按顺序输出A，B，C，用空格隔开，行末无空格。 如果不存在这样的整数A，B，C，则输出No

示例1
输入：1 -2 3 4
输出：2 1 3

*/

/* 
1、A - B = a 
2、B - C = b 
3、A + B = c 
4、B + C = d 
这道题目的实质是：判断三元一次方程组是否有解及求解，这里是小学生都会的问题了^^ 
1+3可以得到A=(a+c)/2；4-2可以得到C=(d-b)/2;
2+4可以得到B2=(b+d)/2，3-1可以得到B1=(c-a)/2；
如果B1不等B2则表达式无解 */


#include <iostream>
using namespace std;
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int A = (a + c) / 2;
    int B1 = (c - a) / 2;
    int B2 = (b + d) / 2;
    int C = (d - b) / 2;
    if (B1 != B2) {
        cout << "No" << endl;
    } else {
        cout << A << " " << B1 << " " << C << endl;
    }
    return 0;
}

//https://www.nowcoder.com/practice/02d8d42b197646a5bbd0a98785bb3a34?tpId=85&&tqId=29857&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking