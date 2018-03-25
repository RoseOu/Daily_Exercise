
public class Client {
	public static void main(String args[]){
		Phone sp,jp,cp;
		
		System.out.println("SimplePhone：");
		sp = new SimplePhone();
		sp.ring();
		System.out.println();
		
		System.out.println("JarPhone：");
		jp = new JarPhone(sp);
		jp.ring();
		System.out.println();
		
		System.out.println("ComplexPhone：");
		cp = new ComplexPhone(jp);
		cp.ring();
	}
}
