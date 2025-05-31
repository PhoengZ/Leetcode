package main

func spiralOrder(matrix [][]int) []int {
	m, n := len(matrix), len(matrix[0])
	check := make([][]bool, m)
	for i := 0; i < m; i++ {
		check[i] = make([]bool, n)
	}
	row := 0
	col := 0
	var ans []int
	for {
		c1 := row-1 < 0 || check[row-1][col]
		c2 := col-1 < 0 || check[row][col-1]
		c3 := row+1 >= m || check[row+1][col]
		c4 := col+1 >= n || check[row][col+1]
		if c1 && c2 && c3 && c4 && check[row][col] {
			break
		}
		for col < n && !check[row][col] {
			check[row][col] = true
			ans = append(ans, matrix[row][col])
			if col+1 >= n || check[row][col+1] {
				break
			}
			col++
		}
		if row+1 < m {
			row++
		}
		for row < m && !check[row][col] {
			check[row][col] = true
			ans = append(ans, matrix[row][col])
			if row+1 >= m || check[row+1][col] {
				break
			}
			row++
		}
		if col-1 >= 0 {
			col--
		}
		for col >= 0 && !check[row][col] {
			check[row][col] = true
			ans = append(ans, matrix[row][col])
			if col-1 < 0 || check[row][col-1] {
				break
			}
			col--
		}
		if row-1 >= 0 {
			row--
		}
		for row >= 0 && !check[row][col] {
			check[row][col] = true
			ans = append(ans, matrix[row][col])
			if row-1 < 0 || check[row-1][col] {
				break
			}
			row--
		}
		if col+1 < n {
			col++
		}
	}
	return ans
}
