package main

import "fmt"

func rotate(matrix [][]int) {
	l := len(matrix)
	for i := 0; i < l; i++ {
		for j := i; j < l; j++ {
			matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
		}
	}
	for i := 0; i < l; i++ {
		for j := 0; j < l/2; j++ {
			matrix[i][j], matrix[i][l-1-j] = matrix[i][l-1-j], matrix[i][j]
		}
	}
}

func main() {
	matrix := [][]int{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}}
	rotate(matrix)
	for i := 0; i < 4; i++ {
		for j := 0; j < 4; j++ {
			fmt.Print(matrix[i][j], " ")
		}
		fmt.Println()
	}
}
