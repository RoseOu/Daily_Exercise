
public class HelpCommand implements Command{
	private DisplayHelpClass hcObj;
	
	public HelpCommand(){
		hcObj = new DisplayHelpClass();
	}
	
	public void execute(){
		hcObj.display();
	}
}
