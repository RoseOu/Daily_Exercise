import java.util.*;

public class HandcakeShop implements Shop{
	ArrayList<Customer> personList;
	ArrayList<Order> orderList;
	private static HandcakeShop hs=null;
	
	private HandcakeShop(){
		hs = this;
		personList = new ArrayList<Customer>();
		orderList = new ArrayList<Order>();
	}

	public static HandcakeShop getHandcakeShop(){
		if(hs==null){
			hs = new HandcakeShop();
		}
		return hs;
	}
	
	public void addCustomer(Customer o){
		if(!(personList.contains(o))){
			personList.add(o);
		}
	}
	
	public void deleteCustomer(Customer o){
		if(!(personList.contains(o))){
			personList.remove(o);
		}		
	}
	
	public void notifyCustomer(){
		for(int i=0;i<personList.size();i++){  //通知顾客生产完毕
			Customer person = personList.get(i);
			String personName = person.getName();
			person.getHandcake();
		}
		personList.clear();  //清空顾客
		orderList.clear();    //清空订单
	}
	
	public void showOrder(){
		for(int i=0;i<orderList.size();i++){
			System.out.println(orderList.get(i).getName()+"      "+orderList.get(i).getHandcakeType()
					          +"     "+orderList.get(i).getQuantity()+"    "+orderList.get(i).getPrice()
					          +"    "+orderList.get(i).getCost()+"     "+orderList.get(i).getTotal());
		}
	}
	
	public void getOrder(String handcakeType, String name,int quantity,double price, double cost,double total){
		Order order = new Order(handcakeType,name,quantity, price, cost,total);
		orderList.add(order);
	}
}
