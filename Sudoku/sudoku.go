package main

import "fmt"

func getSubgrid(row, col int) int {
	return (row/3)*3 + col/3
}

func solve(board [][]byte, row, col int, rboard, cboard, subgrid []map[int]bool, found *bool) {
	if row == 9 {
		*found = true
		return
	}
	if board[row][col] != '.' {
		if col == 8 {
			solve(board, row+1, 0, rboard, cboard, subgrid, found)
			return
		}
		solve(board, row, col+1, rboard, cboard, subgrid, found)
		return

	}
	for i := 1; i <= 9; i++ {
		grid := getSubgrid(row, col)
		if rboard[row][i] || cboard[col][i] || subgrid[grid][i] {
			continue
		}
		rboard[row][i] = true
		cboard[col][i] = true
		subgrid[grid][i] = true
		board[row][col] = byte(i) + '0'
		if col == 8 {
			solve(board, row+1, 0, rboard, cboard, subgrid, found)
		} else {
			solve(board, row, col+1, rboard, cboard, subgrid, found)
		}
		if *found {
			return
		}
		delete(rboard[row], i)
		delete(cboard[col], i)
		delete(subgrid[grid], i)
		board[row][col] = '.'
	}
}

func solveSudoku(board [][]byte) {
	rboard := make([]map[int]bool, 9)
	cboard := make([]map[int]bool, 9)
	subgrid := make([]map[int]bool, 9)
	for i := 0; i < 9; i++ {
		rboard[i] = make(map[int]bool)
		cboard[i] = make(map[int]bool)
		subgrid[i] = make(map[int]bool)
	}
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			if board[i][j] != '.' {
				num := int(board[i][j] - '0')
				rboard[i][num] = true
				cboard[j][num] = true
				subgrid[getSubgrid(i, j)][num] = true
			}
		}
	}
	found := false
	solve(board, 0, 0, rboard, cboard, subgrid, &found)
}

func main() {
	board := [][]byte{
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'},
	}

	solveSudoku(board)
	fmt.Println("Solved Sudoku:")
	for _, row := range board {
		for _, val := range row {
			fmt.Printf("%c ", val)
		}
		fmt.Println()
	}
}
