package main

import (
	"fmt"
	"sort"
)

func checker(element int, arr []int) bool {
	i := len(arr) - 1
	for j := element - 1; j >= 0; j-- {
		if !(arr[i] > arr[j] && arr[i-1] > arr[j]) {
			return false
		}
		i--
	}
	return true
}

func main() {
	var n int
	fmt.Scan(&n)
	arr := make([]int, n)
	for i := range n {
		fmt.Scan(&arr[i])
	}
	sort.Ints(arr)
	var mid int
	ans := 0
	low := 1
	high := (n+1)/2 - 1
	for low <= high {
		mid = (low + high) / 2
		if checker(mid, arr) {
			ans = mid
			low = mid + 1
		} else {
			high = mid - 1
		}
	}
	fmt.Println(ans)
	i := n - 1
	j := ans - 1
	final_ans := make([]int, n)
	for k := range n {
		if k%2 == 0 || j == -1 {
			final_ans[k] = arr[i]
			i--
		} else {
			final_ans[k] = arr[j]
			j--
		}
	}
	for i := range n {
		fmt.Print(final_ans[i], " ")
	}
	fmt.Print("\n")
}
