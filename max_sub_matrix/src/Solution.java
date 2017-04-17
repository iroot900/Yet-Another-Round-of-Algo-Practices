import java.util.*;

public class Solution {
	static private int[] submatrix(int[][] matrix) {
		int[] ret = new int[4];
		int maxSum = Integer.MIN_VALUE;

		int m = matrix.length; if (m == 0) return ret; 
		int n = matrix[0].length;

		for (int left = 0; left < n; ++left) {
			int[] sum = new int[m];
			for (int right = left; right < n; ++right) {
				int total = 0;
				int start = 0;
				for (int i = 0; i < m; ++i) {
					sum[i] += matrix[i][right]; //all the sum (left, right) -- max.
					if (total < 0) { start = i; }
					total = Math.max(total + sum[i], sum[i]);
					int maxSumTmp = Math.max(total, maxSum);
					if (maxSum < maxSumTmp) {
						maxSum = maxSumTmp;
						ret[0] = left;
						ret[1] = right;
						ret[2] = start;
						ret[3] = i;
					}
				}
			}
		}
		System.out.println(maxSum);

		return ret;
	}

	static public void main(String[] args) {
		int[][] matrix = {{1, 2, -1, -4, -20},
                       	  {-8, -3, 4, 2, 1},
                          {3, 8, 10, 1, 3},
                          {-4, -1, 1, 7, -6}};		
		
		int[] ret = submatrix(matrix);
		for (int i = 0; i < ret.length; ++i) {
			System.out.println(ret[i]);
		}
	}
}
