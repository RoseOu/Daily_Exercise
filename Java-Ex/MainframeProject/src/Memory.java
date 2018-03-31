
public class Memory {
	public void check(){
		try{
			System.out.println("内存自检成功！");
		}catch(Exception e){
			System.out.println("内存自检失败！");
			System.out.println("计算机启动失败");
		}
	}
}
