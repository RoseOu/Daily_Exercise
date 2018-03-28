
public class DiscountStyleTwo implements DiscountStyle{
	public double discount(double price,double m){
		price = price - m;
		return price;
	}
}
