package mergesort

import (
	"reflect"
	"testing"
)

func TestMerge(t *testing.T) {
	t.Run("Both halfs of array are sorted", func(t *testing.T) {
		want := []int{1, 2, 2, 3, 4, 5, 6, 7}
		nums := []int{2, 4, 5, 7, 1, 2, 3, 6}
		merge(nums, 0, 3, len(nums)-1)
		if !reflect.DeepEqual(want, nums) {
			t.Errorf("Expected %v, got %v instead.", want, nums)
		}
	})
	t.Run("Array in reversed order", func(t *testing.T) {
		want := []int{3, 2, 2, 1, 7, 6, 5, 4}
		nums := []int{7, 6, 5, 4, 3, 2, 2, 1}
		merge(nums, 0, 3, len(nums)-1)
		if !reflect.DeepEqual(want, nums) {
			t.Errorf("Expected %v, got %v instead.", want, nums)
		}
	})

}

func TestMergeSort(t *testing.T) {
	t.Run("Sort array in random order", func(t *testing.T) {
		want := []int{1, 2, 2, 3, 4, 5, 6, 7}
		nums := []int{5, 2, 4, 7, 1, 3, 2, 6}
		mergeSort(nums, 0, len(nums)-1)
		if !reflect.DeepEqual(want, nums) {
			t.Errorf("Expected %v, got %v instead.", want, nums)
		}
	})

	t.Run("Sort array in reverse order", func(t *testing.T) {
		want := []int{1, 2, 3, 4, 5, 6, 7, 8}
		nums := []int{8, 7, 6, 5, 4, 3, 2, 1}
		mergeSort(nums, 0, len(nums)-1)
		if !reflect.DeepEqual(want, nums) {
			t.Errorf("Expected %v, got %v instead.", want, nums)
		}
	})
}
