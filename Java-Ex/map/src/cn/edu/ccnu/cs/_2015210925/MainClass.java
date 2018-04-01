package cn.edu.ccnu.cs._2015210925;

import java.util.*;

public class MainClass {
	public static void main(String[] args){
		int count =100000;
		int delcount=100000;
		long justnow=0;
		long now=0;
		Map<Integer,Integer> alist = null;
		
		//HashMap
		justnow=System.currentTimeMillis();
		alist = new HashMap<Integer,Integer>();
		for(int i=0;i<count;i++){
			int index = (int)(Math.random()*alist.size());
			alist.put(index,i);
		}
		
		for(int i=0;i<delcount;i++){
			int index = (int)(Math.random()*alist.size());
			alist.remove(index);
		}
		now=System.currentTimeMillis();
		System.out.println("//HashMap");
		System.out.println("Time:");
		System.out.println("Start:"+justnow);
		System.out.println("End:"+now);
		System.out.println("Sub:"+(now-justnow));
		System.out.println();
		
		//TreeMap
		justnow=System.currentTimeMillis();
		alist = new TreeMap<Integer,Integer>();
		for(int i=0;i<count;i++){
			int index = (int)(Math.random()*alist.size());
			alist.put(index,i);
		}
		
		for(int i=0;i<delcount;i++){
			int index = (int)(Math.random()*alist.size());
			alist.remove(index);
		}
		now=System.currentTimeMillis();
		System.out.println("//TreeMap");
		System.out.println("Time:");
		System.out.println("Start:"+justnow);
		System.out.println("End:"+now);
		System.out.println("Sub:"+(now-justnow));
		System.out.println();

	}
}
