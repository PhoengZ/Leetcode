package main

import "fmt"

func distributeCandies(n int, limit int) int64 {
	dp := make([][]int64, 4)
	for i := 0; i <= 3; i++ {
		dp[i] = make([]int64, n+1)
	}
	dp[0][0] = 1
	for i := 1; i <= 3; i++ {
		for j := 0; j <= n; j++ {
			for k := 0; k <= min(limit, j); k++ {
				dp[i][j] += dp[i-1][j-k]
			}
		}
	}
	return dp[3][n]
}

func main() {
	n := distributeCandies(3, 3)
	fmt.Println(n)
}
