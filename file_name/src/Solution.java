import java.util.*;

public class Solution {


	//ab{{a,b},{c,d}}tf
	//stack of {
	//ab{a,b,c
	//put a {
	//
	//ok. what {} should return.  a list of something. 
	//
	//
	//
	//{	}  we want a list. 
	static List<String> getTokens(String str) {
		//get rid of head of {}
		//
		String trimed = str.substring(1, str.length() - 1);

		List<String> tokens = new ArrayList<>(); 

		int count = 0;
		int start = 0;
		for (int i = 0; i < trimed.length(); ++i) {
			char c = trimed.charAt(i);
			if (c == '{') {
				++count;
			} else if (c == '}') {
				--count;
			} else if (c == ',') {
				if (count == 0) {
					String token = trimed.substring(start, i);
					tokens.add(token);
					start = i + 1;
				} 
			}
		}

		String token = trimed.substring(start);
		tokens.add(token);
			
		//{a, b , c}
		//
		//{a,{},c}

		//each item is a list. just add {a,b,{},c}
		List<String> ret = new ArrayList<>();

		for (int i = 0; i < tokens.size(); ++i) {
			ret.addAll(fileNames(tokens.get(i)));
		}

		if (ret.size() == 0) {
			ret.add("");
		}
		return ret;
	}

	static private List<String> fileNames(String str) {
		List<String> ret = new ArrayList<>();
		ret.add("");

		int start = 0;
		for (int i = 0; i < str.length(); ) {
			char c = str.charAt(i);
			if (c == '{') {
				String mid = str.substring(start, i);
				//all temp shall add this thing.
				for (int k = 0; k < ret.size(); ++k) {
					ret.set(k, ret.get(k) + mid);
				}

				//start end. add 
				int count = 1;
				int j = i + 1;
				for (; j < str.length(); ++j) {
					char cc = str.charAt(j);
					if (cc == '{') {
						++count;
					} else if (cc == '}') {
						--count;
						if (count == 0) break;
					}
				}
				List<String> tokens = getTokens(str.substring(i , j + 1));
				i = j + 1;
				List<String> tmp = new ArrayList<>();
				for (String cur : ret) {
					for (String token :  tokens) {
						tmp.add(cur + token);
					}
				}
				ret = tmp;
				start = i;
			} else {
				++i;
			}
		}

		
		String mid = str.substring(start, str.length());
		//all temp shall add this thing.
		for (int k = 0; k < ret.size(); ++k) {
			ret.set(k, ret.get(k) + mid);
		}


		return ret;
	}

	//  if {}
	public static void main(String[] args) {

		List<String> ret = fileNames("abc{{1,2},{x,y}}ef{o}-{}+");

		for (String file : ret) {
			System.out.println(file);
		}


		ret = fileNames("abc{{1},xy{{m,n},{}}d}-");

		for (String file : ret) {
			System.out.println(file);
		}

		ret = fileNames("abc{{1a,1b}{2a,}}xyz");

		for (String file : ret) {
			System.out.println(file);
		}


	}
}
