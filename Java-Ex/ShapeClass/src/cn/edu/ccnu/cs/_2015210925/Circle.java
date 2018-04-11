package cn.edu.ccnu.cs._2015210925;

public class Circle extends Shape{
	private int x1;
	private int y1;
	private int r;
	private final static double PI=3.1415926;
	public Circle(){}
	public Circle(int x1, int y1, int r){
		this.x1 = x1;
		this.y1 = y1;
		this.r = r;
	}

	double area(){
		return PI * r * r;
	}
	String tell(){
			return "Circle";
		}

}