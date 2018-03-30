
public class FileLogFactory implements LogFactory{
	public Log createLog(){
		System.out.println("Create file log now...");
		return new FileLog();
	}
}
