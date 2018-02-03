
public class MySQLFactory implements DBFactory{
	public Connection createConnection(){
		return new MySQLConnection();
	}
	
	public Statement createStatement(){
		return new MySQLStatement();
	}
}
