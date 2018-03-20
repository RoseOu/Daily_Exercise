import java.util.*;

public class Client {
	public static void main(String args[]){
		ProxyCalculator calculator = new ProxyCalculator();
		calculator.init();
		double x,y;
		Scanner input = new Scanner(System.in);
		System.out.println("输入x：");
		x= input.nextDouble();
		System.out.println("输入y：");
		y= input.nextDouble();
		System.out.println("x+y："+calculator.add(x,y));
		System.out.println("x-y："+calculator.sub(x,y));
		System.out.println("x*y："+calculator.mul(x,y));
		System.out.println("x/y："+calculator.div(x,y));
	}
}
