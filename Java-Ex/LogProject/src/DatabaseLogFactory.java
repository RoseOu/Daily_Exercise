
public class DatabaseLogFactory implements LogFactory{
	public Log createLog(){
		System.out.println("Create database log now...");
		return new DatabaseLog();
	}
}