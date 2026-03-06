#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 打印一个排列
void printPermutation(const vector<int> &perm)
{
    for (int num : perm)
    {
        cout << num << " ";
    }
    cout << endl;
}

// 生成全排列的递归函数
void generatePermutations(vector<int> &nums, int start)
{
    // 如果起始位置达到数组的末尾，打印当前排列
    if (start == nums.size())
    {
        printPermutation(nums);
        return;
    }

    // 从当前起始位置到数组的末尾交换元素
    for (int i = start; i < nums.size(); ++i)
    {
        // 交换元素
        swap(nums[start], nums[i]);

        // 递归调用，生成下一个排列
        generatePermutations(nums, start + 1);

        // 回溯，恢复交换前的状态
        swap(nums[start], nums[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n); // 你可以改变这里的输入来生成其他数字的全排列
    for(int &i:nums)
        cin >> i;
    generatePermutations(nums, 0);                      // 从第一个元素开始生成全排列
    return 0;
}