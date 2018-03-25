
public class PhoneDecorator implements Phone{
	private Phone phone;
	
	public PhoneDecorator(Phone phone){
		this.phone=phone;
	}
	
	public void ring(){
		phone.ring();
	}
}
