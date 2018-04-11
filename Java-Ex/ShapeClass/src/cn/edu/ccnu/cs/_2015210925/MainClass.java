package cn.edu.ccnu.cs._2015210925;
import java.util.Random;
public class MainClass {
	public static void main(String[] args){
		Rect rect[];
		Circle circle[];
		int i;
		rect=new Rect[5];
		circle=new Circle[5];
		
		Random rand = new Random();

		for (i = 0; i < 5; i ++)
		{
			rect[i] = new Rect(rand.nextInt(20), rand.nextInt(20), rand.nextInt(20), rand.nextInt(20));
		}
		
		for (i = 0; i < 5; i ++)
		{
			circle[i] = new Circle(rand.nextInt(20), rand.nextInt(20), rand.nextInt(10));
		}

		for (i = 0; i < 5; i ++)
		{
			System.out.print(rect[i].tell()+":"+rect[i].area());
			System.out.println();
		}
		
		for (i = 0; i < 5; i ++)
		{
			System.out.print(circle[i].tell()+":"+circle[i].area());
			System.out.println();
		}
	}
}