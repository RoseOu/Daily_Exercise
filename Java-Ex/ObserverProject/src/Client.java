
public class Client {
	public static void main(String a[]){
		Subject sub = new Share(100);
		Observer obs = new Buyer();
		
		sub.attach(obs);
		
		//从100变到101
		sub.change(101);
		sub.notice();
		System.out.println("-----");
		
		//从101变到200
		sub.change(200);
		sub.notice();
		System.out.println("-----");
	}
}
