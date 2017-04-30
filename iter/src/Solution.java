import java.util.*;

public class Solution {


	//3, 8, 0, 12, 2, 9
	


	static private class MyIter implements Iterator<Integer> {

		MyIter(int[] nums) {
			this.nums = nums;
		}

		public boolean hasNext() {
			/*
			if (count > 0 || p < nums.length) {
				System.out.println("   " + count);
				return true;
			}
			*/

			while (count == 0) { //must go to next 
				if (p >= nums.length) return false;
				count = nums[p]; ++p; 
				num = nums[p]; ++p;
			}

			return true;
		}

		public Integer next() {
			--count;
			return num;
		}

		private int count = 0;
		private int num = 0;
		int p = 0;
		int[] nums;
	}

	public static void main(String[] args) {
		int[] nums = {3, 8, 0, 12, 2, 9};
		MyIter iter = new MyIter(nums);
		while (iter.hasNext()) {
			System.out.println(iter.next());
		}
	}
}
