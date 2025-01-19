package main

import (
	"fmt"
	"math"
)

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func solve() {
	var n int
	fmt.Scan(&n)
	v := make([]int, n)
	for i := range n {
		fmt.Scan(&v[i])
	}
	var ans int
	for i := range n {
		ans = gcd(ans, int(math.Abs(float64(v[i]-v[n-i-1])))
	}
	fmt.Print(ans)
}

func main() {
	var t int
	fmt.Scan(&t)
	for range t {
		solve()
	}
}
