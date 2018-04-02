import java.util.*;

public abstract class Subject {
	private float oldprice;
	private float newprice;
	
	protected ArrayList observers = new ArrayList();
	
	public abstract void attach(Observer observer);
	
	public abstract void detach(Observer observer);
	
	public abstract void change(float price);
	
	public abstract void notice();
	
}
