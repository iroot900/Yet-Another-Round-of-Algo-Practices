import java.util.*;

public class Solution {
	private static Random rd = new Random();

	static int[][] case1 = {{1,1,0}, {0,0,1}};


	private static int[][] candyBorad(int m, int n, int k) {

		if (k < 3) return null;
		int[][] board = new int[m][n];  //check up if two then choose another color.

		//if only two color. then not fun. 
		////more than 2 color.

		for (int i = 0; i < case1.length; ++i) {
			for (int j = 0; j < case1[0].length; ++j) {
				board[i][j] = case1[i][j];
			}
		}

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i < case1.length && j < case1[1].length) continue;
				int color = rd.nextInt(k); 
				while ( ((i > 1) && (board[i-1][j] == board[i - 2][j] &&  board[i-1][j] == color) ) || 
						((j > 1) && (board[i][j-1] == board[i][j-2] &&  board[i][j-1] == color)) ) {
					color = rd.nextInt(k); 
				}
				board[i][j] = color;
			}
		}

		return board;
	}

	public static void main(String[] args) {
		String hi = "bullshit";
		int[][] board = candyBorad(7,7, 4);

		int m = board.length; int n = board[0].length;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				System.out.print(board[i][j] + " "); 
			}
			System.out.println();
		}
		
	}
}


//all the patterns
//  x
//xx
//  x
//
//
// x
//x x
//
//
//
// x
//x x
//
//
//x  x
// x
//
//   x
// xx 
//
// xx 
//   x
//
