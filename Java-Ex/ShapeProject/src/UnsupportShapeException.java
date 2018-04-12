
public class UnsupportShapeException extends Exception{
	String message;
	public UnsupportShapeException(String shapeName){
		message = shapeName + " can not be drew!";
	}
	public String toString(){
		return message;
	}
}
