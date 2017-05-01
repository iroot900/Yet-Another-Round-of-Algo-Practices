import java.util.*;

public class Solution {

	static private int minRectangle(int[][] points) {
		//a b then find the poinst. xx. 
		Set<String> set = new HashSet<>();

		int minArea = -1;
		for (int[] point : points) {
			String code = point[0] + ":" + point[1];
			set.add(code);
		}
		//
		//     b
		//   
		//a
		//
		//----------
		//
		//    a
		//b  
		//    a

		for (int i = 0; i < points.length; ++i) {
			for (int j = i; j < points.length; ++j) {
				if (i == j) continue;
				int a1 = points[i][0];
				int a2 = points[i][1];

				int b1 = points[j][0];
				int b2 = points[j][1];

				int c1 = b1; 
				int c2 = a2;

				int d1 = a1;
				int d2 = b2;

				String code1 = c1 + ":" + c2;
				String code2 = d1 + ":" + d2;

				if (set.contains(code1) && set.contains(code2)) {
					//System.out.println("found");
					int area = Math.abs(a1 - b1) * Math.abs(a2 - b2);
					//System.out.println(area);
					if (area != 0) {
						if (minArea == -1) minArea = area;
						else minArea = Math.min(minArea, area);
					}
				}
			}
		}

		return minArea;
	}

	public static void main(String[] args) {
		int[][] points = {{0,0}, {1,0}, {0,1}, {1,1}, {2,0}, {2,1}};
		System.out.println(minRectangle(points));
	}
}
