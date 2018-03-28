public class ConcreteCustomer implements Customer{
	Shop shop;
	private String handcakeType;
	private String name;
	private AbstractCommand orderCommand;
	
	public ConcreteCustomer(Shop shop, String handcakeType, String name){
		this.shop = shop;
		this.handcakeType = handcakeType;
		this.name = name;
		shop.addCustomer(this);
	}
	
	public String getName(){
		return this.name;
	}
	
	public void setCommand(AbstractCommand orderCommand){
		this.orderCommand = orderCommand;
	}
	
	public void createOrder(String handcakeType, String name,int quantity, double price, double cost, double total){
		orderCommand.execute(handcakeType, name, quantity, price, cost,total);
	}
	
	public void getHandcake(){		
		if(handcakeType.equals("香蕉水果") || handcakeType.equals("榴莲水果")){
			MakeFruitHandcake mf = new MakeFruitHandcake(handcakeType);
			FruitFactory fruitHandcake = mf.makeHandcake();
			fruitHandcake.createHandcake();
		}else if(handcakeType.equals("黑椒培根") || handcakeType.equals("沙拉培根")){
			MakeBaconHandcake mb = new MakeBaconHandcake(handcakeType);
			BaconFactory baconHandcake = mb.makeHandcake();
			baconHandcake.createHandcake();
		}else if(handcakeType.equals("煎鸡蛋") || handcakeType.equals("煮鸡蛋")){
			MakeEggHandcake me = new MakeEggHandcake(handcakeType);
			EggFactory eggHandcake = me.makeHandcake();
			eggHandcake.createHandcake();
		}
	}
}
