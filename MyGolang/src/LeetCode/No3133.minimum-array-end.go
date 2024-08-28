/**
No3133. 数组最后一个元素的最小值
给你两个整数 n 和 x 。你需要构造一个长度为 n 的 正整数 数组 nums ，对于所有 0 <= i < n - 1 ，满足 nums[i + 1] 大于 nums[i] ，并且数组 nums 中所有元素的按位 AND 运算结果为 x 。
返回 nums[n - 1] 可能的 最小 值。
 
示例 1：
输入：n = 3, x = 4
输出：6
解释：
数组 nums 可以是 [4,5,6] ，最后一个元素为 6 。
示例 2：
输入：n = 2, x = 7
输出：15
解释：
数组 nums 可以是 [7,15] ，最后一个元素为 15 。
 
提示：
1 <= n, x <= 108
 */

package LeetCode

func minEnd(n int, x int) int64 {
    var res int = 0
    var i, j, k int = 1, 1, 1

    if n == 1 {
        return int64(x)
    }
    n = n - 1

    for ; i <= x; i = i<<1 {
        if int(x & i) == i {
            res |= k
        } else if j <= n {
            if int(n & j) == j {
                res |= k
            }
            j = j << 1
        }
        k = k << 1
    }

    for ; j <= n; j = j <<1 {
        if int(n & j) == j {
            res |= k
        }
        k = k << 1
    }

    return int64(res)
}