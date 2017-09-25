package cn.edu.ccnu.cs._2015210925;

import java.util.Random;

public class MainClass {
	public static void main(String args[]){
		Random rand = new Random();
		
		Clock[] cs = new Clock[10];
		for(int i=0;i<cs.length;i++){
			cs[i]=new Clock(rand.nextInt(24), rand.nextInt(60), rand.nextInt(60));
		}
		Sorter s = new SelectiveSorter();
		Comparor comp = new ClockComparor();
		
		s.sort(cs, comp);
		
		for(Clock c:cs){
			System.out.print(c.h+":"+c.m+":"+c.s);
			System.out.println();
		}
	}
}
