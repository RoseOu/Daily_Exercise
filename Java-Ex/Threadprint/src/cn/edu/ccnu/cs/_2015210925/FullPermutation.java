package cn.edu.ccnu.cs._2015210925;

import java.util.*;

public class FullPermutation implements Runnable{
	private int f;
	private int n;
		
	public FullPermutation(int f,int n){
			this.f = f;
			this.n = n;
	}
	
	public void run() {
		ArrayList<Integer> num = new ArrayList<Integer>();
		for(int i=1;i<this.n;i++){
			num.add(i);
		}
		getfullPermutation(num,0,this.n-2);
	}
	
	public void getfullPermutation(ArrayList<Integer> num,int start,int end){
		try{
			if(start == end){
				num.add(this.f, this.n);
				System.out.println(num.toString());
				num.remove(this.f);
			}
			for(int i = start;i <= end;i++){
				Collections.swap(num,i,start);
				getfullPermutation(num,start+1,end);
				Collections.swap(num,i,start);
			}
		}catch(Exception e){
			e.printStackTrace();
		}
	}
}
