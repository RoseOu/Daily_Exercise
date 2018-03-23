
public class Client {
	public static void main(String args[]){
		try{
			DBFactory factory;
			Connection connection;
			Statement statement;
			factory = (DBFactory) XMLUtilDatabase.getBean();
			connection = factory.createConnection();
			connection.connect();
			statement = factory.createStatement();
			statement.provideStatement();
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
	}
}