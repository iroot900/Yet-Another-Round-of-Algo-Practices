import java.util.*;

public class Solution {

	static private boolean block(List<int[]> circles, int left, int right, int up, int down) {
		//circle touches left and up
		//circle touched right and down
		//
		//for each circles who's your neibor?!

		Set<String> leftUps = new HashSet<>();
		Set<String> rightDowns = new HashSet<>();


		//who's whose neibors 

		Map<String, Set<String>> graph = new HashMap<>();
		for (int[] circle : circles) {
			int x = circle[0];
			int y = circle[1];
			int r = circle[2];
			if (x < left || x > right || y < down || y > up) continue; 

			String code = x + "," + y + ":" + r;
			
			if (x -r <= 0 || y + r >= up) leftUps.add(code); 
			if (x + r >= right || y - r <= down) rightDowns.add(code);
			
			for (int[] circle2 : circles) {
				int xx = circle2[0];
				int yy = circle2[1];
				int rr = circle2[2];
				if (xx == x && yy == y && rr == r) continue;
				if (xx < left || xx > right || yy < down || yy > up) continue; 
				String code2 = xx + "," + yy + ":" + rr;

				double dist = Math.sqrt( (xx-x) * (xx - x)  + (yy - y) * (yy - y));
				int R = r + rr;
				if (dist <= R) {
					Set<String> tos = graph.get(code);
					if( tos == null) {
						tos = new HashSet<String>();
						graph.put(code, tos);
					}
					tos.add(code2);

					Set<String> from = graph.get(code2);
					if (from == null) {
						from = new HashSet<String>();
							graph.put(code2, from);
					}
					from.add(code);
				}
			}
		}

		for (String key : graph.keySet()) {
			Set<String> neibs = graph.get(key);
			System.out.print(key +  " -> "); 

			for (String neib : neibs) {
				System.out.print(neib + "  ");
			}
			System.out.println();
		}

		System.out.println("up_left");
		for (String code : leftUps) {
			System.out.println(code);
		}

		System.out.println("right_down");
		for (String code : rightDowns) {
			System.out.println(code);
		}

		System.out.println("------");
		for (String node : leftUps) {
			Set<String> visited = new HashSet<>();
			visited.add(node);
			if(DFS(node, graph, visited, rightDowns)) return true;
		}

		return false;
	}


	static boolean DFS(String node, Map<String, Set<String>> graph, Set<String> visited, Set<String> rightDowns) {
		if (rightDowns.contains(node)) { 
			System.out.println("found");	
			return true;
		}
		System.out.println(node);

		Set<String> neibs = graph.get(node);
		if (neibs == null) return false;
		
		for (String neib : neibs) {
			if (visited.contains(neib)) continue;
			visited.add(neib);
			if (DFS(neib, graph, visited, rightDowns)) return true;
			visited.remove(neib);
		}

		return false;
	}

	//
	//					10,10
	//
	//
	// 
	//
	public static void main(String[] args) {
		List<int[]> circles = new ArrayList<>();
		circles.add(new int[] {0,5,1});
		circles.add(new int[] {2,5,1});
		circles.add(new int[] {4,5,1});
		circles.add(new int[] {6,5,1});
		circles.add(new int[] {8,5,1});
		//circles.add(new int[] {9,5,1});
		circles.add(new int[] {10,1,1});


		//

		circles.add(new int[] {8,3,1});
		circles.add(new int[] {8,1,1});
		boolean ret = block(circles, 0, 10, 10, 0);
		System.out.println("result " + ret);
	}
}
