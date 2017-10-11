package cn.edu.ccnu.cs._2015210925;

public class Resolve {
	double delta;
	double x1;
	double x2;
	public void resolve(double a, double b, double c) throws ArgumentException{
		this.delta = b*b - 4*a*c;
		if(this.delta<0){
			throw new ArgumentException();
		}else{
			this.x1 = ((-b)+Math.sqrt(this.delta))/(2*a);
			this.x2 = ((-b)-Math.sqrt(this.delta))/(2*a);
		}
	}
	public double getx1(){
		return x1;
	}
	public double getx2(){
		return x2;
	}
}
