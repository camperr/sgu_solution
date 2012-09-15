/*
 * Author: nzh@UESTC
 */
import java.util.*;
import java.io.*;
import java.math.*;
public class solve {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		BigInteger bN=new BigInteger(in.next());
		BigInteger one=BigInteger.valueOf(1);
		BigInteger two=BigInteger.valueOf(2);
		BigInteger four=BigInteger.valueOf(4);
		int rem[]={0,-1,0,-2};
		BigInteger bK=BigInteger.valueOf(rem[bN.add(one).mod(four).intValue()]);
		BigInteger res=bN.divide(two).add(bK);
		System.out.println(res.toString());
	}
}
