/*
No3254.find-the-power-of-k-size-subarrays-i
*/
func resultsArray(nums []int, k int) []int {
	n := len(nums)
	cnt := 0
	ans := make([]int, n-k+1)
	// for i:0, i<len(ans); i++ {
	//     ans[i] = -1
	// }

	// iteator, check connecting add
	for i := 0; i < n; i++ {
		if i == 0 || nums[i]-nums[i-1] != 1 {
			cnt = 1
		} else {
			cnt++
		}

		if cnt >= k {
			ans[i-k+1] = nums[i]
		} else if i-k+1 >= 0 {
			ans[i-k+1] = -1
		}
	}

	return ans
}