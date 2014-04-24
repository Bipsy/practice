package main

import (
	"fmt"
	"math"
)

func isPrime(num int) bool {
	bound := math.Sqrt(float64(num))
	for i := 2; i < bound; i++ {
		if num % i == 0 {
			return false
		}
	}
	return true
}

func main() {
	upper_bound := 1000
	count := 0
	for i := 2; i < upper_bound; i++ {
		if isPrime(i) == true {
			count++
		}
	}
	fmt.Println("The number of primes less than", upper_bound, "is", count)
}