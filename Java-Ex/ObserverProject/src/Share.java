
public class Share extends Subject{
	private float oldprice;
	private float newprice;
	
	public Share(float price){
		this.oldprice=price;
		this.newprice=price;
	}
	
	public void change(float price){
		this.oldprice=this.newprice;
		this.newprice=price;
	}
	
	public void attach(Observer observer){
		observers.add(observer);
	}
	
	public void detach(Observer observer){
		observers.remove(observer);
	}
	
	public void notice(){
		float c;
		if(this.newprice>this.oldprice){
			c=this.newprice-this.oldprice;
		}else{
			c=this.oldprice-this.newprice;
		}
		if(c>=(this.oldprice*0.05)){
			System.out.println("股票价格变化幅度达到5%！！");
			for(Object obs:observers){
				((Observer) obs).response();
			}
		}
	}
}
