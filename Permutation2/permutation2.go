package main

import "fmt"

func sliceToString(sol []int) string {
	ans := ""
	for _, val := range sol {
		ans += fmt.Sprintf("%d", val)
	}
	return ans
}

func permuteUnique(nums []int) [][]int {
	check := make([]int, len(nums))
	var sol []int
	var ans [][]int
	checksol := make(map[string]bool)

	permutation(nums, check, sol, len(nums), &ans, checksol)
	return ans
}
func permutation(nums, check, sol []int, count int, ans *[][]int, checksol map[string]bool) {
	if count == 0 {
		c := sliceToString(sol)
		if checksol[c] {
			return
		}
		checksol[c] = true
		copied := make([]int, len(nums))
		copy(copied, sol)
		*ans = append(*ans, copied)
		return
	}
	for i := 0; i < len(nums); i++ {
		if (check)[i] == 1 {
			continue
		}
		check[i] = 1
		sol = append(sol, nums[i])
		permutation(nums, check, sol, count-1, ans, checksol)
		(check)[i] = 0
		sol = sol[:len(sol)-1]
	}
}
