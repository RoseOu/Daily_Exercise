
public class OrderHandcake {
	double cost,price;
	DiscountStyle style;
	double m;
	
	public void setPrice(double price){
		this.price = price;
	}
	
	public double getPrice(){
		return this.price;
	}
	
	public void setStyle(DiscountStyle style){
		this.style = style;
	}
	
	public DiscountStyle getStyle(){
		return this.style;
	}
	
	public void setM(double m){
		this.m = m;
	}
	
	public double getM(){
		return this.m;
	}
	
	public double getCost(double price,double m){
		return style.discount(price,m);
	}
}
