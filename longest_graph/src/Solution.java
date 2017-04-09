import java.util.*;

public class Solution {
	static int longest(int[][] edges) {
		int longest = 0;
		//ok graph what do we do?!

		Map<Integer, List<Integer>> graph = new HashMap<>();
		Set<Integer> nodes = new HashSet<>();

		for (int[] edge : edges) {
			int a = edge[0];
			int b = edge[1];
			nodes.add(a);
			nodes.add(b);
			List<Integer> list = graph.get(a);
			if (list == null) {
				list = new ArrayList<Integer>();
				graph.put(a, list);
			}
			list.add(b);

			list = graph.get(b);
			if (list == null) {
				list = new ArrayList<Integer>();
				graph.put(b, list);
			}
			list.add(a);
		}

		//now we have a graph.
		Map<Integer, Integer> map = new HashMap<>();

		//graph. now yes we can visited.
		for (int node : nodes) {
 			int len = DFS(node, graph, map);
			System.out.println(node + "  " + len);
			longest = Math.max(longest,len);
		}

		return longest;
	}

	static int DFS(int node, Map<Integer, List<Integer>> graph, Map<Integer, Integer> map) {
		Integer depth = map.get(node);
		if (depth != null) return depth;
		depth = 1;
		
		//viisited all the neibors

		List<Integer> neibs = graph.get(node); //if no enib.
		for (Integer neib : neibs) { //for all these neibors. what you gonna do
			if (neib == node + 1) { //let's visited it
				depth = DFS(neib, graph, map) + 1;
			}
		}
		map.put(node, depth);
		return depth;
	}

	/*
	  		1
		     \
			 2 - 3
			  \ /
			    4
				  |
				    5 - 8
					  |  /
					     7
						 */

	public static void main(String[] args) {
		int[][] edges = {{1,3}, {2,3}, {2,4}, {4,3}, {4,5}, {5,8}, {5,7}, {7,8}};
		System.out.println(longest(edges));
	}
}
