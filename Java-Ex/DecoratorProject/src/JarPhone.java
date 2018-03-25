
public class JarPhone extends PhoneDecorator{
	public JarPhone(Phone phone){
		super(phone);
	}
	
	public void ring(){
		super.ring();
		jar();
	}
	
	public void jar(){
		System.out.println("产生振动！！");
	}
}
