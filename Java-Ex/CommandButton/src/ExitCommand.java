
public class ExitCommand implements Command{
	private SystemExitClass seObj;
	
	public ExitCommand(){
		seObj = new SystemExitClass();
	}
	
	public void execute(){
		seObj.exit();
	}
}
