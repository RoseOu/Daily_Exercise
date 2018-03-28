
public class MakeEggHandcake implements MakeHandcake{
	private String HandcakeType;
	
	public MakeEggHandcake(String HandcakeType){
		this.HandcakeType = HandcakeType;
	}
	
	public EggFactory makeHandcake(){
		return new EggFactory(HandcakeType);
	}
}
