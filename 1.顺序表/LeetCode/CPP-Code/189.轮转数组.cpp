// LeetCode 189.��ת����
// ����һ�����飬�������е�Ԫ��������ת k ��λ�ã����� k �ǷǸ�����
/*
ʾ�� 1:
����: nums = [1,2,3,4,5,6,7], k = 3
���: [5,6,7,1,2,3,4]
����:
������ת 1 ��: [7,1,2,3,4,5,6]
������ת 2 ��: [6,7,1,2,3,4,5]
������ת 3 ��: [5,6,7,1,2,3,4]
*/
#include <vector>
using namespace std;

/* ����һ��ʹ�ö��������
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        // ����������
        int n = nums.size();
        vector<int> newArr(n);
        // ��nums��ֵ��newArr��kλ��
        for (int i = 0; i < n; i++)
        {
            newArr[(i + k) % n] = nums[i];
        }
        // �ڽ�newArr���鿽����ȥ
        nums.assign(newArr.begin(), newArr.end());
    }
};
*/

// ����2 ��������
class Solution
{
public:
    void reverse(vector<int> &nums, int begin, int end)
    {
        while (begin < end)
        {
            swap(nums[begin], nums[end]);
            begin++;
            end--;
        }
    }

    void rotate(vector<int> &nums, int k)
    {
        // ��Ҫʹk���ã��γɻ��ε�����
        k %= nums.size();
        // 1.��������
        reverse(nums, 0, nums.size() - 1);
        // 2.����k���
        reverse(nums, 0, k - 1);
        // 3.����k�ұ�
        reverse(nums, k, nums.size() - 1);
    }
};
// https://leetcode.cn/problems/rotate-array/