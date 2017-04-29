import java.util.*;

public class Solution {

	static int[] removeNodes(int[][] nodes, int[] nodesToRemove) {
		Map<Integer, Integer> map = new HashMap<>(); //map  key ,val.   nodes. 
		Map<Integer, Set<Integer>> graph = new HashMap<>();

		for (int [] node : nodes) {
			int child = node[0]; int parent = node[1];
			map.put(child, parent);
			Set<Integer> children = graph.get(parent);
			if (children == null) {
				children = new HashSet<Integer> ();
				graph.put(parent, children);
			}
			children.add(child);
		}

		for (int node : nodesToRemove) {
			remove(graph, map, node);
		}

		int[] ret = new int[map.keySet().size()];
		int i = 0;
		for (Integer value : map.keySet()) {
			ret[i++] = value;
		}
		return ret;
	}

	static void remove(Map<Integer, Set<Integer>> graph, Map<Integer, Integer> map, int node) {
		map.remove(node);

		Set<Integer> children = graph.get(node);

		if (children != null) {
			for (Integer child :  children) {
				remove(graph, map, child);
			}
		}
	}
	

	//
	//			4
	//     3  8   1   6
	//   0
	//2   7        9     
	//
	//    10   
	//  11   12
	//
	//  13  14
	
	public static void main(String[] args) {
		int[][] nodes = {{4,-1}, {3, 4}, {8, 4}, {1,4}, {6,4}, {0,3}, {2,0}, {7,0}, {9,1}, {10, -1}, {11, 10}, {12, 10}, {13, -1}, {14, 13}};
		int[] nodesToRemove = {3, 12, 13,6};
		int[] ret = removeNodes(nodes, nodesToRemove);
		System.out.println(Arrays.toString(ret));
	}
}
