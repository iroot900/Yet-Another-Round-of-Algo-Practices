import java.util.*;

public class Solution {
	private static class Node {
		Node left;
		Node right;
		int val; 
		public Node(int val) {
			this.val = val;
		}
	}

	static void print(Node node) {
		if (node == null) return;
		print(node.left);
		System.out.print(node.val + ",");
		print(node.right);
	}

	static String toString(Node node) {
		if (node == null) return "";
		return node.val + "(" +  toString(node.left) + ")(" + toString(node.right) + ")";  //it's done. . 
	}


	// 
	//       5
	//   3      7
	// 1   4   6  8
	
	
	// 7 tree
	static int[] prefix(String str) {
		int n = str.length();
		int[] pre = new int[n];
		if (n == 0) return pre;
		pre[0] = 0;
		
		for (int i = 1; i < n; ++i) {
			char c = str.charAt(i);
			int last = pre[i - 1];
			while (last != 0 && c != str.charAt(last)) {
				last = pre[last - 1];
			}

			if (c == str.charAt(last)) {
				pre[i] = last + 1;
			}
		}
		return pre;
	}

	//111212123456
	//12123
	static boolean KMP(String str, String sub) {
		int[] pre = prefix(sub);

		int m = sub.length();
		int n = str.length();
		for (int i = 0; i < str.length();) {
			//if the same. then just go, till mismatch. then we find another i. 

			char c = str.charAt(i);
			char cc = sub.charAt(0);
			if (c == cc) {
				//go to match whole sub. 	
				int l = i;
				int r = 0;
				while (true) {
					while (l < n && r < m && str.charAt(l) ==  sub.charAt(r)) {
						++l; ++r;
					}
					if (r == m) return true;
					if (l == n) return false;
					

					//1212123
					//1212
					//r == 0.
					int pref = pre[r - 1];
					if (pref == 0) { //i = l;
						i = l;
						break;
					} else {
						//l
						//go back 
						l = l - pref;
						r = 0;
					}
				}
				//didn't find. then what do we do?
			} else {
				++i; //just go to next. 
			}
		}

		return false;
	}

	public static void main(String[] args) {
		Node node = new Node(5);
		node.left = new Node(3);
		node.right = new Node(7);
		node.left.left = new Node(1);
		node.left.right = new Node(4);
		node.right.left = new Node(6);
		node.right.right = new Node(8);
		//print(node);
		System.out.println(" ");

		System.out.println(toString(node));

		//O(n)  O(m)

		Node node2 = new Node(7);
		node2.left = new Node(6);
		node2.right = new Node(8);
		//print(node2);
		System.out.println(toString(node2));
		//node2.left = new Node(

		System.out.println(Arrays.toString(prefix("1231201234")));

		String str = toString(node);
		String sub = toString(node2);
		System.out.println(KMP(str, sub));
		System.out.println(KMP("111212123456", "12123"));
		System.out.println(KMP("111212123456", "12126"));
	}
}
