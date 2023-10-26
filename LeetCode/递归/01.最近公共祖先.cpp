/* 描述
将一棵无穷大满二叉树的结点按根结点一层一层地从左往右编号，根结点编号为1。现给定a，b为两个结点。设计一个算法，返回a、b最近的公共祖先的编号。注意其祖先也可能是结点本身。

测试样例：
2，3
返回：1
 */

class LCA {
public:
    int getLCA(int a, int b) {
        if (a == b) {
            return a;
        }

        //9和3测试应该为1
        return a > b ? getLCA(a / 2, b) : getLCA(a, b / 2);
    }
};

//https://www.nowcoder.com/practice/70e00e490b454006976c1fdf47f155d9?tpId=8&&tqId=1101