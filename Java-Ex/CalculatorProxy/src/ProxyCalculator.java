
public class ProxyCalculator implements Calculator{
	private RealCalculator real;
	
	public void init(){
		real = new RealCalculator();
	}
	
	public double add(double x,double y){
		return real.add(x,y);
	}
	public double sub(double x,double y){
		return real.sub(x,y);
	}
	public double mul(double x,double y){
		return real.mul(x,y);
	}
	public double div(double x,double y){
		return real.div(x,y);
	}
}
