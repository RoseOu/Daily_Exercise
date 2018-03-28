
public class DiscountStyleThree implements DiscountStyle{
	public double discount(double price,double m){
		price = price * m/10;
		return price;
	}
}
