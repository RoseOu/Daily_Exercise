package cn.edu.ccnu.cs._2015210925;
public class Rect extends Shape{
	private int x1;
	private int x2;
	private int y1;
	private int y2;
	public Rect(){}   // default
	public Rect(int x1, int y1, int x2, int y2){
			this.x1 = x1;
			this.y1 = y1;
			this.x2 = x2;
			this.y2 = y2;
	}

	public double area(){
			return Math.abs((x1 - x2)*(y1 - y2));
	}
	public String tell(){
			return "Rect";
		};
}
