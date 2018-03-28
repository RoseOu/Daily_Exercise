
public class EggFactory implements Factory{
	private String handcakeType;
	
	public EggFactory(String HandcakeType){
		this.handcakeType = HandcakeType;
	}
	
	public void createHandcake(){
		try{
			if(handcakeType.equals("煎鸡蛋")){
				EggHandcake friedEggHandcake = new FriedEggHandcake();
				friedEggHandcake.show();
			}else if(handcakeType.equals("煮鸡蛋")){
				EggHandcake boiledEggHandcake = new BoiledEggHandcake();
				boiledEggHandcake.show();
			}
		}catch(Exception e){
			System.out.println("制作"+handcakeType+"手抓饼失败！");
			System.out.println("没有该手抓饼！");
		}
	}
}
