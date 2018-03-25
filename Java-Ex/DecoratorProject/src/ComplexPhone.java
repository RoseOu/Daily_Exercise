
public class ComplexPhone extends PhoneDecorator{
	public ComplexPhone(Phone phone){
		super(phone);
	}
	
	public void ring(){
		super.ring();
		light();
	}
	
	public void light(){
		System.out.println("灯光闪烁！！");
	}
}
