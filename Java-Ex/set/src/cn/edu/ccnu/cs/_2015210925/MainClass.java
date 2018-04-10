package cn.edu.ccnu.cs._2015210925;

import java.util.*;

public class MainClass {
	public static void main(String[] args){
		int count =100000;
		int delcount=100000;
		long justnow=0;
		long now=0;
		Set<Integer> alist = null;
		
		//HashSet
		justnow=System.currentTimeMillis();
		alist = new HashSet<Integer>();
		for(int i=0;i<count;i++){
			int index = (int)(Math.random()*alist.size());
			alist.add(index);
		}
		
		for(int i=0;i<delcount;i++){
			int index = (int)(Math.random()*alist.size());
			alist.remove(index);
		}
		now=System.currentTimeMillis();
		System.out.println("//HashSet");
		System.out.println("Time:");
		System.out.println("Start:"+justnow);
		System.out.println("End:"+now);
		System.out.println("Sub:"+(now-justnow));
		System.out.println();
		
		//TreeSet
		justnow=System.currentTimeMillis();
		alist = new TreeSet<Integer>();
		for(int i=0;i<count;i++){
			int index = (int)(Math.random()*alist.size());
			alist.add(index);
		}
		
		for(int i=0;i<delcount;i++){
			int index = (int)(Math.random()*alist.size());
			alist.remove(index);
		}
		now=System.currentTimeMillis();
		System.out.println("//TreeSet");
		System.out.println("Time:");
		System.out.println("Start:"+justnow);
		System.out.println("End:"+now);
		System.out.println("Sub:"+(now-justnow));
		System.out.println();

	}
}
