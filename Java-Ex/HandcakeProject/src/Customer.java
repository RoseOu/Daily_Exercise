import java.util.*;

public interface Customer {
	public String getName();
	public void getHandcake();
	public void setCommand(AbstractCommand orderCommand);
	public void createOrder(String handcakeType, String name,int quantity,double price, double cost,double total);
}
