import java.util.*;

public class Solution {


	static private class Node {
		Node left = null;
		Node right = null;
		int val;
		Node (int val) {
			this.val = val;
		}
	}


	//get a regular iter then buttome iter...
	static class MyIter implements Iterator<Integer> {

		MyIter(Node root) {

			while (root != null) {
				sta.push(root); root = root.left;
			}
		}

		MyIter() {}

		public Integer next() {

			Node node = sta.pop();
			if (node.left == null && node.right == null) bottom = true;
			else bottom = false;

			int val = node.val;
			//System.out.println(val);

			//go to right if possible
			node = node.right;

			while (node != null) {
				sta.push(node); node = node.left;
			}

			return val;
		}

		public boolean hasNext() {
			return sta.size() != 0;
		}

		boolean bottom = false;
		Stack<Node> sta = new Stack<>();
	}


	static class BottomIter extends MyIter {
		BottomIter(Node root) {
			super(root);
			while (super.hasNext()) {
				int val = super.next();
				if (super.bottom) {
					this.val = val;
					break;
				}
			}
		}

		public Integer next() {
			Integer cur = val;

			val = null;
			while (super.hasNext()) {
				int val = super.next();
				if (super.bottom) {
					this.val = val;
					break;
				}
			}
			return cur;
		}

		public boolean hasNext() {
			return val != null ;
		}

		Integer val = null;
	}

	public static void main(String[] args) {

		//    4
		//  2   5
		//1  3    6
		//
		//	    3
		//   2     4
		// 1      5  6
		Node root1 = new Node(4);
		root1.left = new Node(2);
		root1.left.left = new Node(1);
		root1.left.right = new Node(3);

		root1.right = new Node(5);
		root1.right.right = new Node(6);




		Node root2 = new Node(3);
		root2.left = new Node(2);
		root2.left.left = new Node(1);
		root2.right = new Node(4);
		root2.right.left = new Node(5);
		root2.right.right = new Node(6);

		MyIter iter = new MyIter(root1);
		while (iter.hasNext()) {
			System.out.print(iter.next() + " ");
			//iter.next();
		}
		System.out.println();

		iter = new MyIter(root2);
		while (iter.hasNext()) {
			System.out.print(iter.next() + " ");
		}
		System.out.println();


		BottomIter iterB = new BottomIter(root1);
		while (iterB.hasNext()) {
			System.out.println(iterB.next() + " " );
		}
		System.out.println();


		iterB = new BottomIter(root2);
		while (iterB.hasNext()) {
			System.out.println(iterB.next() + " " );
		}
		System.out.println();


	}


}
