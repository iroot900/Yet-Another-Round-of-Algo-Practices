import java.util.*;


public class Solution {

	public static void main(String[] args) {
		System.out.println("Out");
		dTree tree = new dTree();

 		int[][] points = {{3, 6}, {17, 15}, {13, 15}, {6, 12},
                       {9, 1}, {2, 7}, {10, 19}};
		for (int[] point : points) {
			tree.add(point[0], point[1]);
		}
 
    	int point1[] = {10, 19};
    	System.out.println(tree.search(point1[0], point1[1]));
 
		int point2[] = {12, 19};
    	System.out.println(tree.search(point2[0], point2[1]));


		int point3[] = {2, 7};
    	System.out.println(tree.search(point3[0], point3[1]));


		int point4[] = {13, 15};
    	System.out.println(tree.search(point4[0], point4[1]));


		int[] test1 = tree.closePoint(13, 14);
		print(test1);

		int[] test2 = tree.closePoint(3, 7);
		print(test2);

		int[] test3 = tree.closePoint(0, 0);
		print(test3);

		int[] test4 = tree.closePoint(100, 100);
		print(test4);
	}

	static private <T> void print(int[] arr) {
		for (int val : arr) {
			System.out.print(val);
			System.out.print(" ");
		}
		System.out.println();
	}
}

class dTree {
	static private class Node {
		//first layer up/down 0 
		//left/right & 1 = 1;
		int x;
		int y;
		Node leftUp;//up
		Node rightDown;
		Node(int x, int y) {
			this.x = x; this.y = y;
		}
	}

	private Node root;

	void add(int x, int y) { //    
		root = add(root, x, y, 0);
	}

	private Node add(Node node, int x, int y, int depth) {
		if (node == null) {
			return new Node(x, y);
		}

		boolean odd = ((depth & 1) == 1);

		if (odd) {
			if (x >= node.x) {
				node.rightDown = add(node.rightDown, x, y, depth + 1);
			} else {
				node.leftUp = add(node.leftUp, x, y, depth + 1);
			}
		} else { //evenl up and down
			if (y >= node.y) {
				node.rightDown = add(node.rightDown, x, y, depth + 1);
			} else {
				node.leftUp = add(node.leftUp, x, y, depth + 1);
			}
		}
		return node;
	}

	boolean search(int x, int y) {
		return search(root, x, y, 0);
	}

	private boolean search(Node node, int x, int y, int depth) {
		if (node == null) return false;

		if (node.x == x && node.y == y) return true;
		

		boolean odd = ((depth & 1) == 1);
		if (odd) {
			if (x >= node.x) {
				return search(node.rightDown, x, y, depth + 1);
			} else {
				return search(node.leftUp, x, y, depth + 1);
			}
		} else {
			if (y >= node.y) {
				return search(node.rightDown, x, y, depth + 1);
			} else {
				return search(node.leftUp, x, y, depth + 1);
			}
		}
	}

	int rangeSearch(int x1, int y1, int x2, int y2) {
		return -1;
	}

	int[] closePoint(int x, int y) { //the close point for (x, y)
		int[] closeP = {Integer.MAX_VALUE, Integer.MAX_VALUE};
		int[] dist = {Integer.MAX_VALUE};
		int[] point = {};
		closePoint(root, x, y, point, dist, 0, closeP);
		int[] ret = new int[3];
		ret[0] = closeP[0];
		ret[1] = closeP[1];
		ret[2] = dist[0];
		return ret;
	}

	void closePoint(Node node, int x, int y, int[] point, int dist[], int depth, int[] closeP) {
		if (node == null) return;
		if (node.x == x && node.y == y) { closeP[0] = x; closeP[1] = y; dist[0] = 0; return;}

		int curDist = (int)Math.sqrt((x - node.x) * (x - node.x)  + (y - node.y) * (y - node.y));

		if (curDist < dist[0]) {
			dist[0] = 
			closeP[0] = node.x; closeP[1] = node.y; dist[0] = curDist; 
		}

		boolean odd = ((depth & 1) == 1);
		int minDist = 0;
		
		if (odd) { //compare left and right x
			if (x < node.x) { //go to left.
				minDist = node.x - x;
				closePoint(node.leftUp, x, y, point, dist, depth + 1, closeP);
				if (minDist < dist[0]) {
					closePoint(node.rightDown, x, y, point, dist, depth + 1, closeP);
				}
			} else {
				minDist = x - node.x ;
				closePoint(node.rightDown, x, y, point, dist, depth + 1, closeP);
				if (minDist < dist[0]) {
					closePoint(node.leftUp, x, y, point, dist, depth + 1, closeP);
				}
			}
		} else {  //compare y . up and down. 

			if (y < node.y) { //go to left.
				minDist = node.y - y;
				closePoint(node.leftUp, x, y, point, dist, depth + 1, closeP);
				if (minDist < dist[0]) {
					closePoint(node.rightDown, x, y, point, dist, depth + 1, closeP);
				}
			} else {
				minDist = y - node.y;
				closePoint(node.rightDown, x, y, point, dist, depth + 1, closeP);
				if (minDist < dist[0]) {
					closePoint(node.leftUp, x, y, point, dist, depth + 1, closeP);
				}
			}
		}
	}
}
