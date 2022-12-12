package mergesort

import (
	"math"
)

func merge(numbers []int, l, mid, r int) {
	n1 := mid - l + 1
	n2 := r - mid
	left := []int{}
	right := []int{}
	for i := 0; i < n1; i++ {
		left = append(left, numbers[l+i])
	}
	for i := 0; i < n2; i++ {
		right = append(right, numbers[mid+i+1])
	}
	left = append(left, math.MaxInt)
	right = append(right, math.MaxInt)

	for k := l; k <= r; k++ {
		if left[0] <= right[0] {
			numbers[k] = left[0]
			left = left[1:]
		} else {
			numbers[k] = right[0]
			right = right[1:]
		}
	}
}

func mergeSort(numbers []int, l, r int) {
	if l < r {
		mid := l + (r-l)/2
		mergeSort(numbers, l, mid)
		mergeSort(numbers, mid+1, r)
		merge(numbers, l, mid, r)
	}
}
