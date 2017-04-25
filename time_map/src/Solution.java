import java.util.*;

public class Solution {

	static private class TimeMap {

		public void set(int key, int val, int expir) {
			Entry entry  = keyMap.get(key);
			if (entry == null) {
				keyMap.put(key, new Entry(val, expir));
				Set<Integer> set = timeTree.get(expir);  //new entry. new key, val expir time.
					if (set == null) {
						set = new HashSet<Integer>();
						timeTree.put(expir, set);
					}
					set.add(key);
			} else { //key already exist.
				int oldExpir = entry.expir;
				entry.expir = expir;
				Set<Integer> set = timeTree.get(oldExpir);  //new entry. new key, val expir time.
				set.remove(key);
				timeTree.get(expir);  //new entry. new key, val expir time.
					if (set == null) {
						set = new HashSet<Integer>();
						timeTree.put(expir, set);
					}
				set.add(key);
	    	}
		}

		public Integer get(int key) {
			Entry entry = keyMap.get(key);
			if (entry == null) return null;
			int val = entry.val; 
			int expir = entry.expir;

			if (clock >= expir) {
				//remove this entry.
				Set<Integer> set = timeTree.remove(expir);
				for (Integer expirKey  : set) {
					keyMap.remove(expirKey);
				}
				return null;
			} else {
				return val;
			}
		}


		public void clean() {
			while (timeTree.size() != 0) {
				int firstKey = timeTree.firstKey();
				if (firstKey >= clock) {
					timeTree.remove(firstKey);
				}
			}
		}

		public void addTime(int val) {
			clock += val;
		}

		//time. val
		///remove update .

		
		static private class Entry {
			public Entry(int val, int expir) {
				this.val = val;
				this.expir = expir;
			}
			int val = 0;
			int expir = 0;
		};

		Map<Integer, Entry> keyMap = new HashMap<>();
		TreeMap<Integer, Set<Integer>> timeTree = new TreeMap<>();


		int clock =  0;
	}

	public static void main(String[] args) {
		System.out.println("out");
		TimeMap map = new TimeMap();
		map.set(1, 1, 3);
		map.set(2, 2, 2);
		map.addTime(2);
		System.out.println(map.get(1));
		System.out.println(map.get(2));

		map.set(3,3,5);
		System.out.println(map.get(1));
		System.out.println(map.get(2));
		System.out.println(map.get(3));

		map.set(1, 1, 4);
		map.addTime(1);
		
		System.out.println(map.get(1));
		System.out.println(map.get(2));
		System.out.println(map.get(3));
	}
}
