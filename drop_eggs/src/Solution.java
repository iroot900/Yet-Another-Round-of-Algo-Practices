import java.util.*;

public class Solution {

	//n floors and k eggs. (k = 
	static int minDrops(int n, int E) {

		//f[n][k] = ?

		//use one egg broken or not

		//try floor   1 2 3 4 5 6  with one egg.



		//floor i. ok if we broken something, didn't broken    only go up. or it broke, then
		// f[n][e]  = min( max(f[n - i][e], f[i][e-1]) for i)
		//
		// 

		int[][] f = new int[n + 1][E + 1];
		//1 floor. ew need1

		for (int i = 1; i <= n; ++i) {
			f[i][1] = i;
		}


		for (int i = 1; i <= E; ++i) {
			f[1][i] = 1;
		}

		for (int h = 2; h <= n; ++h) {
			for (int e = 2; e <= E; ++e) {

				f[h][e] = h;
				for (int i = 1; i <= h; ++i) { //try each floor
					f[h][e] = Math.min(f[h][e], Math.max(f[h - i][e], f[i - 1][e - 1]) + 1);

					// h ith floor.   not broken  h - i// check all the remaining
					//
					// h ith flor.. borken.   check i - 1  then check i -1 broken or not?!
				}
			}
		}

		return f[n][E];
	}

	public static void main(String[] args) {
		System.out.println("Out");
		System.out.println(minDrops(5,1));
		System.out.println(minDrops(5,2));
		System.out.println(minDrops(5,3));
		System.out.println(minDrops(5,4));
		System.out.println(minDrops(5,5));
	}
}
