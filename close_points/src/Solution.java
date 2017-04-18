import java.util.*;


public class Solution {

	// find the two close points.
	// 			.
	//   .	  .
	//    .  . 		.	
	// .    . .  .
	//     .
	//
	//
	
	//divide into two parts.  points. sorted by x.
	//
	//left dist and right dist
	//min dist
	//
	//points.   mid - mid mid + min.  for all these
	//
	//then sorted by y.     y within min. then check distance. then again. 
	//
	//  if y distance is beyond min. then  it's greater then min.
	//
	//
	//  can we just do it again x.
	//
	//  all points on left side is  distan greater than min. ok. 

	//Divide and conquer
	static double closePoints(int[][] points) {
		int[] ret = {5};
		int n = points.length;	

		Arrays.sort(points, new Comparator<int[]> () {
			@Override
			public int compare(int[] left, int[] right) {
				return left[0] - right[1];
			}
		});

		return closePoints(points, ret, 0, n - 1);
	}


	//can we get a basic one?!
	//
	//yes. then well  DFS DP Divide and conquer
	//
	////you don't have to carry out the whole thing. 
	//
	//OK. the point it assume you have solution to n how about n -1
	//
	// n/2 , how about n
	//
	//
	//	The essence of problem solving. 
	// // base case. that's why trivail concerte example are so important
	//
	//    n coudl be n-1 (dp dfs)
	//
	//    n could be n /2  (divide and conquer)
	private static double closePoints(int[][] points, int[] closeOnes, int left, int right) {
		if (left >= right) return Integer.MAX_VALUE;
		if (left + 1 == right) {
			int dx = Math.abs(points[left][0] - points[right][0]);
			int dy = Math.abs(points[left][1] - points[right][1]);
			return  Math.sqrt(dx*dx + dy*dy);
		} //base case.   bottom up

		int mid = (left + right) >> 1;
		double distLeft = closePoints(points, closeOnes, left , mid - 1); //
		double distRight = closePoints(points, closeOnes, mid + 1, right);

		double minDist = Math.min(distLeft, distRight);

		int l = mid - 1; int r = mid + 1;
		List<int[]> boundary = new ArrayList<>();
		boundary.add(points[mid]);
		while (l >= left && (points[mid][0] - points[l][0] < minDist)) { boundary.add(points[l]); --l; } //sort those points by n log n
		while (r <= right  && (points[r][0] - points[mid][0] < minDist)) { boundary.add(points[r]); ++r; }


		Collections.sort(boundary, new Comparator<int[]> () {
			@Override
			public int compare(int[] left, int[] right) {
				return left[1] - right[1];
			}
		});
		//find min within the boundary
		//
		// n *log(n) * log(n);

		double curMin = minDist;
		for (int i = 0; i < boundary.size(); ++i) {
			for (int j = i - 1; j >= 0; --j) {
				if (boundary.get(i)[1] - boundary.get(j)[1] < minDist) {
					int dx = Math.abs(boundary.get(i)[0] - boundary.get(j)[0]);	
					int dy = Math.abs(boundary.get(i)[1] - boundary.get(j)[1]);	
					curMin = Math.min(curMin, Math.sqrt(dx* dx + dy * dy));
				}
			}
		}

		return curMin;
	}

	public static void main(String[] args) {
		int[][] points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
		System.out.println(closePoints(points));
	}
}
