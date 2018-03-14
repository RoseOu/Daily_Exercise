package cn.edu.ccnu.cs._2015210925;

import java.util.Scanner;

public class MainClass {
	public static void main(String[] args){
		long justnow=0;
		long now=0;
		int n;
		
		try{
			justnow=System.currentTimeMillis();
			Scanner reader = new Scanner(System.in);
			System.out.println("Input N:");
			n=reader.nextInt();
			
			Thread[] threads = new Thread[n];
			for(int i = 0; i < n;i++){
				FullPermutation fp = new FullPermutation(i,n);
				threads[i] = new Thread(fp);
				threads[i].start();
			}	
			for(Thread t:threads){
				t.join();
			}
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
	

}
