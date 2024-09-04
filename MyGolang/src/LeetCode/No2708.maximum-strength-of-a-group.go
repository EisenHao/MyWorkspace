/*
No2708.maximum-strength-of-a-group
2708. 一个小组的最大实力值

给你一个下标从 0 开始的整数数组 nums ，它表示一个班级中所有学生在一次考试中的成绩。老师想选出一部分同学组成一个 非空 小组，且这个小组的 实力值 最大，如果这个小组里的学生下标为 i0, i1, i2, ... , ik ，那么这个小组的实力值定义为 nums[i0] * nums[i1] * nums[i2] * ... * nums[ik​] 。

请你返回老师创建的小组能得到的最大实力值为多少。

示例 1：
输入：nums = [3,-1,-5,2,5,-9]
输出：1350
解释：一种构成最大实力值小组的方案是选择下标为 [0,2,3,4,5] 的学生。实力值为 3 * (-5) * 2 * 5 * (-9) = 1350 ，这是可以得到的最大实力值。

示例 2：
输入：nums = [-4,-5,-4]
输出：20
解释：选择下标为 [0, 1] 的学生。得到的实力值为 20 。我们没法得到更大的实力值。

提示：
1 <= nums.length <= 13
-9 <= nums[i] <= 9
*/


func maxStrength(nums []int) int64 {
	n := len(nums)

	// 当数组仅有 1 个元素且为负数时，最大积为负数
	if n == 1 && nums[0] < 0 {
		return int64(nums[0])
	}

	var res int64 = 1

	// 统计负数个数
	negCnt := 0
	posCnt := 0
	maxNeg := -9

	for i := 0; i < n; i++ {
		if nums[i] < 0 {
			negCnt++
			if nums[i] > maxNeg {
				maxNeg = nums[i]
			}
		} else if nums[i] > 0 {
			posCnt++
		} else {
			continue
		}
		res = res * int64(nums[i])
	}

	// 当数组不包含正数，且负数元素小于等于 1 个时，最大积为 0
	if posCnt == 0 && negCnt <= 1 {
		return 0
	}

	if res > 0 {
		return res
	}
	return res / int64(maxNeg)
}