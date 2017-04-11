import java.util.*;

public class Solution {


	//full drug
	
	//each time you'll take half. 
	
	static double[] fullDrug(int n) {
		if (n == 0) return null;
		double[][] f = new double[2 * n][n];


		// after k 5 remaings. 
		// after k 3 ful reaming. 
		//
		// change that f[i][remaing]
		//  f[i][remaing] = f[i - 1][remaing] * (get a half) + f[i][remaing+1])1 * (get a full).
		//
		//
		//  f[i][remaing]  * k 
	
		//  f[i][remaing ] = f[i-1][remaing](get a half) + f[i - 1][]
		//  change of 5 full.   chances to get half. 
		//
		//  change to get half. and chance to get full .    
		//  chance of how many is full
		//  //chnage of 
		
		//f[0][]
		//after i, change of k full remaing. 
		f[0][n - 1] = 1;

		//f[2*n - 1][0] = 1;

		double[] ret = new double[2*n];
		ret[0] = 1;
		for (int i = 1; i < 2 * n; ++i) {
			//number of remaing. 
			for (int j = 0; j < n; ++j) { //reming is 0, 1 2 3 n.  remaing is 0
				//how to get it to make it [k reminag.]
				// last k remaing. this time get half.    last time k -1 remaing, this time get half. 

				//what are the chnage to get full number of full and we kown number of half.

				// ok. what is this?!  ---- numbe - j.. // all the fulls  get half. how many half we have? 
				// should be  half.?    2 *n - i
				// n - j  
				// n - (j + 1)
				int remainHalfs = 2 * n - i; //ok what is this?  -- remainHalfs.
				
				//how many full we have. how many half we have. 

				double halfs1 = (remainHalfs - 2 * j);
				double halfs2 = (remainHalfs - 2 * (j + 1));

				f[i][j] = f[i-1][j] * ((halfs1 >= 0 && (halfs1 + j > 0)) ? halfs1 / (halfs1 + j) : 0) +  
						  (j == n - 1 ? 0 : f[i-1][j+1]) * ((halfs2 >= 0 && (halfs2 + j + 1> 0)) ? (j + 1) / (j + 1 + halfs2): 0); //last time is f[][]  and we get 


				//after each move k remaing. 
				//chnage of getting half. 
				//at this time. 
				//all cases, then each case. change of get a full
				//f[i-1][j]


				//f[i-1][0 - k] --- geot a full 0 to n -1. 
				//

				double half = (remainHalfs -  2 * j); 
				ret[i] += f[i-1][j] * ((half >= 0 && half + j > 0)? j / (half + j) : 0);
			}
		}

		return ret;	
	}

	public static void main(String[] args) {
		double[] ret = fullDrug(10); 
		for (int i = 0; i < ret.length; ++i) {
			System.out.println(ret[i]);
		}
	}
}
