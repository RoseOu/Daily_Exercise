import java.util.ArrayList;

public interface Shop {
	ArrayList<Customer> personList=new ArrayList();
	ArrayList<Order> orderList=new ArrayList();
	public void addCustomer(Customer o);
	public void deleteCustomer(Customer o);
	public void notifyCustomer();
	public void getOrder(String handcakeType, String name,int quantity,double price, double cost,double total);
}
