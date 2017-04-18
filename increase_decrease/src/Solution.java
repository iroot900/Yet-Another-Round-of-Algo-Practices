import java.util.*;

public class Solution {
	private static int maxNum(int[] nums) {
		int n = nums.length;  if (n == 0) return -1;
		int left = 0;
		int right =  n - 1;

		while (left < right) {
			int mid = (left + right) >> 1; //ab   left  
			if (mid == left) {
				return Math.max(nums[left], nums[right]);
			}
			if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return nums[mid];
			if (nums[mid] > nums[mid - 1]) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}

		return nums[left];
	}
	
	public static void main(String[] args) {
		int[] test1 = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
		System.out.println(maxNum(test1));

		int[] test2 = {1, 3, 50, 10, 9, 7, 6};
		System.out.println(maxNum(test2));

		int[] test3 = {10, 20, 30, 40, 50};
		System.out.println(maxNum(test3));

		int[] test4 = {120, 100, 80, 20, 0};
		System.out.println(maxNum(test4));
	}
}


/*
 *
 *
	Input: arr[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1}
	Output: 500

	Input: arr[] = {1, 3, 50, 10, 9, 7, 6}
	Output: 50

	Corner case (No decreasing part)
	Input: arr[] = {10, 20, 30, 40, 50}
	Output: 50

	Corner case (No increasing part)
	Input: arr[] = {120, 100, 80, 20, 0}
	Output: 120
*
*/
