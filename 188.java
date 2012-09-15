/*
 * Author: nzh@UESTC
 */
import java.util.*;
public class Solution {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		final int pr=1000;
		int n=in.nextInt();
		int t=in.nextInt();
		int speed[]=new int[n+7];
		int pos[]=new int[n+7];
		for(int i=0;i<n;i++) pos[i]=in.nextInt();
		for(int i=0;i<n;i++) speed[i]=in.nextInt();
		int res[]=new int[n+7];
		for(int i=0;i<n;i++){
			res[i]=0;
			for(int j=0;j<n;j++){
				if(j!=i){
					if(speed[i]>=0 && speed[j]<=0){
						int d=(pos[j]+pr-pos[i])%pr;
						int tt=(speed[i]-speed[j])*t-d;
						if(tt>=0) res[i]+=tt/pr+1;
					}else if(speed[i]<=0 && speed[j]>=0){
						int d=(pos[i]+pr-pos[j])%pr;
						int tt=(speed[j]-speed[i])*t-d;
						if(tt>=0) res[i]+=tt/pr+1;
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			System.out.print(res[i]);
			if(i==n-1) System.out.println("");
			else System.out.print(" ");
		}
	}
}
