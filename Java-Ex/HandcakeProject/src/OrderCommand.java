
public class OrderCommand implements AbstractCommand{
	private Shop shop;
	
	public OrderCommand(Shop shop){
		this.shop = shop;
	}
	
	public void execute(String handcakeType, String name,int quantity, double price, double cost,double total){
		shop.getOrder(handcakeType, name, quantity, price, cost, total);
	}
}
