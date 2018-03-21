
public class Client {
	public static void main(String args[]){
		Command exitCommand,helpCommand;
		
		//系统退出键
		exitCommand = new ExitCommand();		
		FunctionButton exitButton = new FunctionButton();
		exitButton.setCommand(exitCommand);
		exitButton.click();
		
		//打开帮助界面键
		helpCommand = new HelpCommand();
		FunctionButton helpButton = new FunctionButton();
		helpButton.setCommand(helpCommand);
		helpButton.click();
		
	}
}
