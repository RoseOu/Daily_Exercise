
public class OracleFactory implements DBFactory{
	public Connection createConnection(){
		return new OracleConnection();
	}
	
	public Statement createStatement(){
		return new OracleStatement();
	}
}
