
public class FruitFactory implements Factory{
	private String handcakeType;
	
	public FruitFactory(String HandcakeType){
		this.handcakeType = HandcakeType;
	}
	
	public void createHandcake(){
		try{
			if(handcakeType.equals("香蕉水果")){
				FruitHandcake bananaHandcake = new BananaHandcake();
				bananaHandcake.show();
			}else if(handcakeType.equals("榴莲水果")){
				FruitHandcake durianHandcake = new DurianHandcake();
				durianHandcake.show();
			}
		}catch(Exception e){
			System.out.println("制作"+handcakeType+"手抓饼失败！");
			System.out.println("没有该手抓饼！");
		}
	}
}
