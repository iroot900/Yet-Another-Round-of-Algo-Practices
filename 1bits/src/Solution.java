import java.util.*;

public class Solution {

	static private long oneBits(int number) {
		//1 at each position
		

		//at first position 
		//
		//00  (every two there is one with 1)
		//01
		//10  (again half of them is 1)
		//11


		//000 (every 4 numeber,      1 zero, 1 one.   2 zero 2 one. 4 zero. 4 ones)
		//001
		//010
		//011

		//100
		//101
		//110
		//111
		
		//000
		
		long count = 0;
		long base = 2;
		for (int i = 0; i < 32; ++i) {
			// num / paris  -->  n * paris / 2
			// the rest.   pair * 2 - rest. 
			//
			//
			int times = (int)((number + 1) / base); 
			
			count += times * (base / 2);
		
			int remaing = (int) ((number + 1) % base);
			count += Math.max(0, remaing - (int)(base / 2));

			base *= 2;
		}
		return count;
	}

	static private long brute(int number ) {
		long count = 0;
		for (int n = 1; n <= number; ++n) {
			for (int i = 0 ; i< 32; ++i) {
				count += ((n >> i) & 1);
			}
		}
		return count;
	}

	public static void main(String[] args) {
		int test1 = 100;
		System.out.println(oneBits(test1));
		System.out.println(brute(test1));
		test1 = 1232112;
		System.out.println(oneBits(test1));
		System.out.println(brute(test1));
	}
}
