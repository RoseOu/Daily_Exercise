
public class BaconFactory implements Factory{
	private String handcakeType;
	
	public BaconFactory(String HandcakeType){
		this.handcakeType = HandcakeType;
	}
	
	public void createHandcake(){
		try{
			if(handcakeType.equals("黑椒培根")){
				BaconHandcake pepperBaconHandcake = new PepperBaconHandcake();
				pepperBaconHandcake.show();
			}else if(handcakeType.equals("沙拉培根")){
				BaconHandcake saladBaconHandcake = new SaladBaconHandcake();
				saladBaconHandcake.show();
			}
		}catch(Exception e){
			System.out.println("制作"+handcakeType+"手抓饼失败！");
			System.out.println("没有该手抓饼！");
		}
	}
}
