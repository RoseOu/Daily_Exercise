
public class Order {
	private String HandcakeType;
	private String name;
	private int quantity;
	private double cost;
	private double price;
	private double total;
	
	public Order(String HandcakeType, String name, int quantity,double price, double cost,double total){
		this.HandcakeType = HandcakeType;
		this.name = name;
		this.quantity = quantity;
		this.price = price;
		this.cost = cost;
		this.total = total;
	}
	
	public double getPrice(){
		return this.price;
	}
	
	public double getCost(){
		return this.cost;
	}
	
	public double getTotal(){
		return this.total;
	}
	
	public String getHandcakeType(){
		return this.HandcakeType;
	}
	
	public String getName(){
		return this.name;
	}
	
	public int getQuantity(){
		return this.quantity;
	}
}
