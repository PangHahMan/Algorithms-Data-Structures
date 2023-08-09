// ����nums������0��n������������������ȱ��һ�������д�����ҳ��Ǹ�ȱʧ�����������а취��O(n)ʱ���������
#include <vector>
using namespace std;

//����1. ��0��n��� ��ȥnums����������
class Solution {
public:
    int missingNumber(vector<int> &nums) {
        // ��n,numsȱһ����Ȼ���0��ʼ��n����nums.size()
        int n = nums.size();
        int sum = 0;
        // 0��n���
        for (int i = 0; i <= n; i++) {
            sum += i;
        }
        // ��ӵ�ֵ��ȥ�����ÿһλֵ������ȱʧ������
        for (int i = 0; i < nums.size(); i++) {
            sum -= nums[i];
        }
        return sum;
    }
};


// ����2�����
// ˼·�����  ��ͬ����������0  0����κ����֣������κ�����.
// ��0��ʼ���n�����Դ˺������е����
class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i <= n; i++) {
            sum ^= i;
        }

        for (int i = 0; i < nums.size(); i++) {
            sum ^= nums[i];
        }
        return sum;
    }
};

// https://leetcode.cn/problems/missing-number-lcci/