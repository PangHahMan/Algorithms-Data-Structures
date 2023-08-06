/* 描述
小易经常沉迷于网络游戏.有一次,他在玩一个打怪升级的游戏,他的角色的初始能力值为a.在接下来的一段时间内,他将会依次遇见n个怪物,每个怪物的防御力为b1,b2,b3...bn. 如果遇到的怪物防御力bi小于等于小易的当前能力值c,那么他就能轻松打败怪物,并且使得自己的能力值增加bi;如果bi大于c,那他也能打败怪物,但他的能力值只能增加bi与c的最大公约数.那么问题来了,在一系列的锻炼后,小易的最终能力值为多少?
输入描述：
对于每组数据,第一行是两个整数n(1≤n<100000)表示怪物的数量和a表示小易的初始能力值. 然后输入n行，每行整数,b1,b2...bn(1≤bi≤n)表示每个怪物的防御力
输出描述：
对于每组数据,输出一行.每行仅包含一个整数,表示小易的最终能力值

示例1
输入：
3 50
50 105 200
5 20
30 20 15 40 100

输出：
110
205 
*/

#include <iostream>
#include <vector>
using namespace std;
// 24 18
int GCD(int a, int b) {
    int c = a > b ? b : a;
    while (c >= 1) {
        if (a % c == 0 && b % c == 0) {
            return c;
        }
        c--;
    }
    return 1;// 如果没有找到公约数，返回1
}

// int GCD(int a, int b) {
//     int c;
//     while (c = a % b) {
//         a = b;
//         b = c;
//     }
//     return b;
// }

int getPowerValue(int n, int power) {
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < n; i++) {
        if (power >= num[i]) {
            power += num[i];
        } else {
            power += GCD(power, num[i]);
        }
    }
    return power;
}


int main() {
    int n, a, power;
    while (cin >> n >> a) {
        power = getPowerValue(n, a);
        cout << power << endl;
    }
    return 0;
}

//https://www.nowcoder.com/practice/fe6c73cb899c4fe1bdd773f8d3b42c3d?tpId=49&&tqId=29329&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking