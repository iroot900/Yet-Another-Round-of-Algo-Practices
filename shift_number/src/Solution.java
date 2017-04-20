import java.util.*;

public class Solution {

	static private void shift(int[] nums, int val) {
		int n = nums.length;
		int p = -1; //is the first p
		for (int i = 0; i < n; ++i) {
			if (nums[i] == val) {
				//go on
				if (p == -1) {
					p = i;
				}
			} else {
				if (p == -1) continue;
				int tmp = nums[p];
				nums[p] = nums[i];
				nums[i] = tmp;
				++p;
			}
		}
	}

	public static void main(String[] args) {
		int[] test = {2, 3, 1, 2, 4, 2, 5, 2};
		shift(test, 2);
		for (int i = 0; i < test.length; ++i) {
			System.out.println(test[i]);
		}
	}
}
