
public class MakeFruitHandcake implements MakeHandcake{
	private String HandcakeType;
	public MakeFruitHandcake(String HandcakeType){
		this.HandcakeType = HandcakeType;
	}
	
	public FruitFactory makeHandcake(){
		return new FruitFactory(HandcakeType);
	}
}
