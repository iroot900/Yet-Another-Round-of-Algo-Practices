import java.util.*;

public class Solution {

	static private class Heap {
		List<Integer> data = new ArrayList<>();
		

		//  
		//  	1
		//   3     4  
		//2    0  5
		//
		//    0    
		//  1   2
		// 3 4 5 6 
		//
		//
		// p  * 2 + (1, 2)
		//
		//
		// (p - 1) /2 
		
		public void print() {
			for (int i = 0; i < data.size(); ++i) {
				System.out.print(data.get(i) +  " ");
			}
			System.out.println();
		}

		public int size() {
			return data.size();
		}

		public int top() {
			return data.get(0);
		}

		public int pop() {
			int top = top();
			//how to pop this?
			//after this what do we do need to find the smallest number. 
			int end = data.get(data.size() - 1); //this is the laset data.	
			data.set(0, end);
			data.remove(data.size() - 1);
			int i = 0;
			while (i < data.size() - 1) {
				int left = i * 2 + 1;
				if (left >= data.size()) break;
				int lval = data.get(left);

				int right = i * 2 + 2;
				int rval = Integer.MAX_VALUE;
				if (right < data.size()) {
					rval = data.get(right);
				}
				if (lval <= rval) { //l min
					if (data.get(i) > lval) {
						int tmp = data.get(i);
						data.set(i, lval);
						data.set(left, tmp);
						i = left;
					} else {
						break;
					}
				} else {
					if (data.get(i) > rval) {
						int tmp = data.get(i);
						data.set(i, rval);
						data.set(right, tmp);
						i = right;
					} else {
						break;
					}
				}
			}
			return top;
		}

		public void push(int val) {
			data.add(val); //if smaller then get it to htere. 

			int i = data.size()  - 1;
			int p = -1;
			while (i != 0) {
				p = (i - 1) / 2;
				int pval = data.get(p);
				if (pval > data.get(i)) {
					data.set(p, data.get(i));
					data.set(i, pval);
					i = p;
				} else {
					break;
				}
			}
		}

		public boolean isEmpty() {
			return data.size() == 0;
		}
	}

	public static void main(String[] args) {
		System.out.println("out");
		Heap heap = new Heap();
		heap.push(4);
		heap.push(3);
		heap.push(2);
		heap.push(7);
		heap.push(6);
		heap.push(0);

		heap.print();

		while (heap.size() >3) {
			System.out.println(heap.pop());
		}
		System.out.println("---");

		heap.push(9);
		heap.push(-1);
		while (heap.size() > 0) {
			System.out.println(heap.pop());
		}
	}
}
