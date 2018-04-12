
public class ShapeFactory {
	public static Shape produceShape(String shapeName) throws UnsupportShapeException{
		if(shapeName.equalsIgnoreCase("Circle")){
			System.out.println("Drawing circle...");
			return new Circle();
		}else if(shapeName.equalsIgnoreCase("Triangle")){
			System.out.println("Drawing Triangle...");
			return new Triangle();
		}else if(shapeName.equalsIgnoreCase("Rectangle")){
			System.out.println("Drawing Rectangle...");
			return new Rectangle();
		}else{
			throw new UnsupportShapeException(shapeName);
		}
	}
}
