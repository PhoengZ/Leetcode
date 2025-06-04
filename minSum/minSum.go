package main

func minSum(nums1 []int, nums2 []int) int64 {
	var total_1, total_2, cz_1, cz_2 int64
	total_1, total_2, cz_1, cz_2 = 0, 0, 0, 0
	for i := 0; i < len(nums1); i++ {
		if nums1[i] == 0 {
			cz_1++
		}
		total_1 += int64(nums1[i])
	}
	for i := 0; i < len(nums2); i++ {
		if nums2[i] == 0 {
			cz_2++
		}
		total_2 += int64(nums2[i])
	}
	if total_1+cz_1 > total_2 && cz_2 == 0 {
		return -1
	}
	if total_2+cz_2 > total_1 && cz_1 == 0 {
		return -1
	}
	return max(total_2+cz_2, total_1+cz_1)
}
