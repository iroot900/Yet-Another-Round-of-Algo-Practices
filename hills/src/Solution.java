import java.util.*;

public class Solution {

	private static int longestHill(int[] nums) {
		int last = 0;
		int length = 0;
		int start = 0;

		int i = 1;
		for (; i < nums.length; ++i) {
			if (nums[i] - nums[i - 1] > 0) {
				last = 1;
				++i;
				start = i - 1;
				break;
			}
		}

		if (i == nums.length) return 0;

		for (; i < nums.length; ++i) {
			int dir  = nums[i] - nums[i - 1];
			if (dir > 0) {
				if (last > 0) {
					//still going up don't care
				} else if (last < 0) {
					//going down. then what do we do?!from down we're going up now. 
					int len = i - start;
					length = Math.max(length, len);
					last = 1;	
					start = i - 1;
				}
			} else if (dir < 0) { //go down
				if (last > 0) { //from up to down.
					last = -1;
				} else if (last < 0) {
					//keep go down
				}
			}
		}

		if (last == -1) {
			length = Math.max(length, i - start);
		}
		return length;
	}

	public static void main(String[] args) {
		int[] test1 = {2, 6, 1, 8, 9, 2, 7, 3, 10};
		System.out.println(longestHill(test1));


		int[] test2 = {2, 6, 1, 8, 2, 7, 3, 10};
		System.out.println(longestHill(test2));

		int[] test3 = {2, 6, 7, 8, 9};
		System.out.println(longestHill(test3));

		int[] test4 = {2, 6, 7, 8, 9, 2};
		System.out.println(longestHill(test4));
	}
}
