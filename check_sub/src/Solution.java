import java.util.*;

public class Solution {

	static private boolean isSub(String str, String sub) {
		int m = str.length();
		int n = sub.length();


		//sub.  find char, find   char, which index should be larger than current index. on str.
		//n * log(m);

		Map<Character, TreeSet<Integer>> map = new HashMap<>();

		for (int i = 0; i < str.length(); ++i) {
			char c = str.charAt(i);
			TreeSet<Integer> set = map.get(c);
			if (set == null) {
				set = new TreeSet<>();
				map.put(c, set);
			}
			set.add(i);
		}

		int p = -1;
		for (int i = 0; i < sub.length(); ++i) {
			char c = sub.charAt(i);
			TreeSet<Integer> set = map.get(c);
			if (set == null) return false;
			Integer nextP = set.ceiling(p + 1);
			if (nextP != null) {
				p = nextP;
			} else {
				return false;
			}
		}

		return true;
	}

	public static void main(String[] args) {
		System.out.println(isSub("1234", "1234"));
		System.out.println(isSub("010203040", "1234"));
		System.out.println(isSub("12300004", "1234"));
		System.out.println(isSub("1243", "1234"));
	}
}
