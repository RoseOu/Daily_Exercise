package cn.edu.ccnu.cs._2015210925;

import java.util.Scanner;

public class MainClass {
	public static void main(String[] args){
		long justnow=0;
		long now=0;
		int n;
		int[] num;
		
		try{
			justnow=System.currentTimeMillis();
			Scanner reader = new Scanner(System.in);
			System.out.println("Input N:");
			n=reader.nextInt();
			System.out.println("1~N:");
			num=new int[n];
			for(int i=0;i<n;i++){
				num[i]=i+1;
				System.out.print(num[i]+" ");
			}
			System.out.println();
			System.out.println("Full Permutation:");
			fullPermutation(num,n,0);
			
			now=System.currentTimeMillis();
			System.out.println("");
			System.out.println("Time:");
			System.out.println("Start:"+justnow);
			System.out.println("End:"+now);
			System.out.println("Sub:"+(now-justnow));
			System.out.println();
			reader.close();
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	
	public static void swap(int[] num,int i,int j)
	{
	    int temp=num[i];
	    num[i]=num[j];
	    num[j]=temp;
	}
	
	public static void fullPermutation(int[] num,int n,int i){
		try{
			if(i==n-1){
				for(int k=0;k<n;k++){
					System.out.print(num[k]+" ");
				}
				System.out.println();
			}
			for(int j=i;j<n;j++){
				swap(num,i,j);
				fullPermutation(num,n,i+1);
				swap(num,i,j);
			}
		}catch(Exception e){
			e.printStackTrace();
		}
	}
}
