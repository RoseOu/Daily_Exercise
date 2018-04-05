
public class Client {
	public static void main(String a[]){		
		PrintSpoolerSingleton ps1,ps2,ps3;
		try{
			ps1 = PrintSpoolerSingleton.getInstance();
			ps1.manageJobs();
		}catch(PrintSpoolerException e){
			System.out.println(e.getMessage());
		}
		System.out.println("---------------");
		
		try{
			ps2 = PrintSpoolerSingleton.getInstance();
			ps2.manageJobs();
		}catch(PrintSpoolerException e){
			System.out.println(e.getMessage());
		}
		System.out.println("---------------");
		
		try{
			ps3 = PrintSpoolerSingleton.getInstance();
			ps3.manageJobs();
		}catch(PrintSpoolerException e){
			System.out.println(e.getMessage());
		}
		System.out.println("---------------");
		

	}
}
