import java.util.*;

public class Solution {

	/*
	 *input是两个string： string1 和string2， 要求是把string1 convert成string2。 
	 *有两个method， 一个是 void pre(char ch), 意思是把String1里的的ch replace成  字母序列里前一位的character. 比如 pre(‘b’), 就是把所有string1 里的 'b' convert 成 ‘a’. 另一个method 是 void next(char ch),  意思是把String1里的的ch replace成  字母序列里后一位的character. 比如 pre(‘b’), 就是把所有string1 里的 'b' convert 成 ‘c’.   另外 ‘a’ 的pre还是 ‘a’, 'z' 的  next 还是‘z’.  
	 *需要的output是想要完成 string1 到string2 的conversion所需要call 这两个method 的次数之和。  如果不能conversion， 返回 -1.

	 */

	private static int minMoves(String str1, String str2) {
		int m = str1.length(); int n = str2.length();
		if (m != n) return -1;
		int left = 257;
		int right = 0;
		List<Integer> leftB = new ArrayList<>();
		List<Integer> rightB = new ArrayList<>();

		for (int i = 0; i < m; ++i) {
			char c = str2.charAt(i);
			if (c < left) leftB.clear();
			if (c <= left) leftB.add(i);

			if (c > right) rightB.clear();
			if (c >= right) rightB.add(i);
			left = Math.min(c, left);
			right = Math.max(c, right);
		} //then what do we do?!

		if (leftB.get(0) == rightB.get(0)) {//a stright line.

			//System.out.println(str1);
			//push to left wall or right wall. then push to mid 
			return 0;//yes we can get it same.
		}


		//get larget of the 3. then  check if there is any smaller or equals. 

		//get left wall ready
		//leftB.  (1, 3, 8) these 3 should be the shortest 3.
		int maxL = 0;
		Set<Integer> leftBS = new HashSet<>();
		leftBS.addAll(leftB);
		for (int index : leftB) {
			char c = str1.charAt(index);
			maxL = Math.max(maxL, c);
		}

		for (int i = 0; i < str1.length(); ++i) {
			char c = str1.charAt(i);
			if (c <= maxL && !leftBS.contains(i)) {
				return -1;
			}
		}


		int minR = 300;
		Set<Integer> rightBS = new HashSet<>();
		rightBS.addAll(rightB);
		for (int index : rightB) {
			char c = str1.charAt(index);
			minR = Math.min(minR, c);
		}

		for (int i = 0; i < str1.length(); ++i) {
			char c = str1.charAt(i);
			//System.out.println("	" + c + ", " + (char)minR);
			if (c >= minR && !rightBS.contains(i)) {
				return -1;
			}
		}


		//check all the staff other than boundary
		//
		int diff = 300; 
			//System.out.println();
		for (int i = 0; i < str1.length(); ++i) {
			if (leftBS.contains(i) || rightBS.contains(i)) continue;
			int curDiff = str1.charAt(i) - str2.charAt(i);
			if (diff == 300) {
				diff = curDiff;
			} else {
				if (diff != curDiff) return -1;
			}
		}

		//get right wall ready

		//left boundary and right boundary.
		
		//get bound.
		//check left bound

		return 0;
	}

	static private void test(String str1, String str2) {
		System.out.println(str1 + "  " + str2 + " : " + minMoves(str1, str2));
	}

	public static void main(String[] args) {
		String str1 = "abcdefff";
		String str2 = "aaaaaaaa";
		test(str1, str2);


		str1 = "aaaabbbb";
		str2 = "aaaacccc";
		test(str1, str2);


		str1 = "mnxxzy";
		str2 = "aabbcc";
		test(str1, str2);


		str1 = "abcd";
		str2 = "defg";
		test(str1, str2);

		str1 = "abcdfg";
		str2 = "defgtt";
		test(str1, str2);


		str1 = "abcddfg";
		str2 = "defgttt";
		test(str1, str2);

		str1 = "abcd";
		str2 = "dekg";
		test(str1, str2);
	}
}
