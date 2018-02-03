package cn.edu.ccnu.cs._2015210925;

import java.util.Scanner;

public class MainClass {
	public static void main(String[] args){
		double a;
		double b;
		double c;
		double x1;
		double x2;
		Resolve resolve = new Resolve();
		Scanner reader = new Scanner(System.in);
		
		System.out.println("Input a:");
		a=reader.nextDouble();
		System.out.println("Input b:");
		b=reader.nextDouble();
		System.out.println("Input c:");
		c=reader.nextDouble();
		
		try{
			resolve.resolve(a, b, c);
			x1=resolve.getx1();
			x2=resolve.getx2();
			System.out.println();
			System.out.println("x1="+x1);
			System.out.println("x2="+x2);
		}catch(ArgumentException e){
			System.out.println(e.toString());
		}
	}
}
