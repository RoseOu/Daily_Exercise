
public class MakeBaconHandcake implements MakeHandcake{
	private String HandcakeType;
	
	public MakeBaconHandcake(String HandcakeType){
		this.HandcakeType = HandcakeType;
	}
	
	public BaconFactory makeHandcake(){
		return new BaconFactory(HandcakeType);
	}
}
