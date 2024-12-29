package main

import (
	"fmt"
	"sort"
)

func checker(operations int, a []int, maxSum int, sum int) bool {
	if sum-operations <= maxSum {
		return true
	}

	n := len(a)
	for i := n - 1; i >= max(1, n-operations); i-- {
		sum -= a[i]
		operationsLeft := operations - (n - i)
		tempSum := sum - a[0] + (n-i+1)*(a[0]-operationsLeft)
		if tempSum <= maxSum {
			return true
		}
	}

	return false
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func solve() {
	var n, k int
	fmt.Scan(&n, &k)
	nums := make([]int, n)
	sum := 0
	for i := range n {
		fmt.Scan(&nums[i])
		sum += nums[i]
	}
	sort.Ints(nums)
	low := 0
	high := int(1e14)
	var mid, ans int
	for low <= high {
		mid = (low + high) / 2
		if checker(mid, nums, k, sum) {
			ans = mid
			high = mid - 1
		} else {
			low = mid + 1
		}
	}
	fmt.Println(ans)
}

func main() {
	var t int
	fmt.Scan(&t)
	for range t {
		solve()
	}
}
