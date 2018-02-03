package cn.edu.ccnu.cs._2015210925;

public class ArgumentException extends Exception{
	String message;
	public ArgumentException(){
		message="Invalid argument!";
	}
	public String toString(){
		return message;
	}
}
