package cn.edu.ccnu.cs._2015210925;

public class MainClass {
    public static void main(String args[]){
        Rational r1=new Rational(2,3);
        Rational r2=new Rational(3,4);

        Rational result=r1.add(r2);
        r1.show();
        System.out.print("+");
        r2.show();
        System.out.print("=");
        result.show();
        System.out.println();

        result=r1.sub(r2);
        r1.show();
        System.out.print("-");
        r2.show();
        System.out.print("=");
        result.show();
        System.out.println();

        result=r1.muti(r2);
        r1.show();
        System.out.print("x");
        r2.show();
        System.out.print("=");
        result.show();
        System.out.println();

        result=r1.div(r2);
        r1.show();
        System.out.print("÷");
        r2.show();
        System.out.print("=");
        result.show();
        System.out.println();
    }
}
