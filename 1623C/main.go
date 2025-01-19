package main

import "fmt"

func ok(h int, nums []int) bool {
	c := make([]int, len(nums))
	copy(c, nums)

	for i := len(nums) - 1; i >= 0; i-- {
		if nums[i] < h {
			return false
		}
		d := min((nums[i]-h)/3, c[i]/3)
		if i > 1 {
			nums[i-1] += d
			nums[i-2] += 2 * d
		}
		nums[i] -= 3 * d
	}

	return true
}

func solve() {
	var n int
	fmt.Scan(&n)
	nums := make([]int, n)
	for i := range n {
		fmt.Scan(&nums[i])
	}
	low := 1
	high := int(1e9)
	var mid, ans int
	for low <= high {
		mid = (low + high) / 2
		if ok(mid, append([]int(nil), nums...)) {
			ans = mid
			low = mid + 1
		} else {
			high = mid - 1
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
