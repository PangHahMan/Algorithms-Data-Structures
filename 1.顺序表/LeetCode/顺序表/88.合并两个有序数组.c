/*
�����������ǵݼ�˳�����е���������nums1��nums2��������������m��n ���ֱ��ʾnums1��nums2�е�Ԫ����Ŀ��
����ϲ�nums2��nums1 �У�ʹ�ϲ��������ͬ�����ǵݼ�˳�����С�
 */

/*
���룺nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
�����[1,2,2,3,5,6]
*/

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    int i1 = m - 1;     // nums1����������±�
    int i2 = n - 1;     // nums2����������±�
    int i3 = m + n - 1; // nums1���������±�
    while (i1 >= 0 && i2 >= 0)
    {
        if (nums1[i1] > nums2[i2]) // ����ķŵ�i3�±���,�ڷֱ�--
        {
            nums1[i3--] = nums1[i1--];
        }
        else
        {
            nums1[i3--] = nums2[i2--];
        }
    }

    //���i1�����ˣ������ѭ��������i2��û�����꣬���Ի�Ҫѭ��һ��i2
    //Ϊʲôû��i1����Ϊһ��i2�����ˣ���i1����ԭ���飬ԭ�ⲻ�����ɡ�
    while (i2 >= 0)
    {
        nums1[i3--] = nums2[i2--];
    }
}
// https://leetcode.cn/problems/merge-sorted-array