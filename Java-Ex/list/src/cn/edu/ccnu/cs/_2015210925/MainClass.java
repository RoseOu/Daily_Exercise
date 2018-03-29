package cn.edu.ccnu.cs._2015210925;

import java.util.*;

public class MainClass {
	public static void main(String[] args){
		int count =100000;
		int delcount=100000;
		long justnow=0;
		long now=0;
		List<Integer> alist = null;
		
		//ArrayList
		justnow=System.currentTimeMillis();
		alist = new ArrayList<Integer>();
		for(int i=0;i<count;i++){
			int index = (int)(Math.random()*alist.size());
			alist.add(index,i);
		}
		
		for(int i=0;i<delcount;i++){
			int index = (int)(Math.random()*alist.size());
			alist.remove(index);
		}
		now=System.currentTimeMillis();
		System.out.println("//ArrayList");
		System.out.println("Time:");
		System.out.println("Start:"+justnow);
		System.out.println("End:"+now);
		System.out.println("Sub:"+(now-justnow));
		System.out.println();
		
		//LinkedList
		justnow=System.currentTimeMillis();
		alist = new LinkedList<Integer>();
		for(int i=0;i<count;i++){
			int index = (int)(Math.random()*alist.size());
			alist.add(index,i);
		}
		
		for(int i=0;i<delcount;i++){
			int index = (int)(Math.random()*alist.size());
			alist.remove(index);
		}
		now=System.currentTimeMillis();
		System.out.println("//LinkedList");
		System.out.println("Time:");
		System.out.println("Start:"+justnow);
		System.out.println("End:"+now);
		System.out.println("Sub:"+(now-justnow));
		System.out.println();
		
		//Vector
		justnow=System.currentTimeMillis();
		alist = new Vector<Integer>();
		for(int i=0;i<count;i++){
			int index = (int)(Math.random()*alist.size());
			alist.add(index,i);
		}
		
		for(int i=0;i<delcount;i++){
			int index = (int)(Math.random()*alist.size());
			alist.remove(index);
		}
		now=System.currentTimeMillis();
		System.out.println("//Vector");
		System.out.println("Time:");
		System.out.println("Start:"+justnow);
		System.out.println("End:"+now);
		System.out.println("Sub:"+(now-justnow));
		System.out.println();
		
		//Stack
		justnow=System.currentTimeMillis();
		alist = new Stack<Integer>();
		for(int i=0;i<count;i++){
			int index = (int)(Math.random()*alist.size());
			alist.add(index,i);
		}
		
		for(int i=0;i<delcount;i++){
			int index = (int)(Math.random()*alist.size());
			alist.remove(index);
		}
		now=System.currentTimeMillis();
		System.out.println("//Stack");
		System.out.println("Time:");
		System.out.println("Start:"+justnow);
		System.out.println("End:"+now);
		System.out.println("Sub:"+(now-justnow));
		System.out.println();
	}
}
