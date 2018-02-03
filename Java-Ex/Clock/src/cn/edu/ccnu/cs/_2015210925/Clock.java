package cn.edu.ccnu.cs._2015210925;

public class Clock {
	int h;
	int m;
	int s;
	
	Clock(int h,int m,int s){
		this.h=h;
		this.m=m;
		this.s=s;
	}
}

class ClockComparor implements Comparor{
	@Override
	public int compare(Object o1,Object o2){
		Clock c1 = (Clock)o1;
		Clock c2 = (Clock)o2;
		
		return (c1.h*3600+c1.m*60+c1.s) < (c2.h*3600+c2.m*60+c2.s) ? 1 : 0;
	}
}

