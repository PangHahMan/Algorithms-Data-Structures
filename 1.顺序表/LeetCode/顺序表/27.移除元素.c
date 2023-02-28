/*
����һ������ nums?��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ����?val?��Ԫ�أ��������Ƴ���������³��ȡ�
��Ҫʹ�ö��������ռ䣬������ʹ�� O(1) ����ռ䲢 ԭ�� �޸��������顣
Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
 */

/*
���룺nums = [3,2,2,3], val = 3
�����2, nums = [2,2]
*/

int removeElement(int *nums, int numsSize, int val)
{
    // ˫ָ�� - �ж��Ƿ���ͬ����ͬ�Ļ�src++������ͬ���src��dst
    int dst = 0, src = 0;
    for(int i =0 ;i<numsSize;i++)
    {
        if(nums[src]==val)
        {
            src++;
        }
        else
        {
            nums[dst++]=nums[src++];
        }
    }
    return dst;  //dst����++���������³���
}
// https://leetcode.cn/problems/remove-element
