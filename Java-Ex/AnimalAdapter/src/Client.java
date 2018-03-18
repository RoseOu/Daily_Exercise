public class Client {
	public static void main(String[] args) {
		// 把一条狗适配成一只猫           
		Cat fakeCat = new Adapter(new ConcreteDog());          
		fakeCat.catLooks();           
		fakeCat.catchMouse();
		
		// 把一只猫适配成一条狗           
		Dog fakeDog = new Adapter(new ConcreteCat());          
		fakeDog.dogLooks();           
		fakeDog.wang();
	}
}
