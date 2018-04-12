import java.util.*;

public class MainClass {
	public static void main(String args[]){
		try{
			Shape shape;
			System.out.println("输入要绘制的形状：");
			Scanner reader = new Scanner(System.in);
			String shapeName = reader.nextLine();
			shape = ShapeFactory.produceShape(shapeName);
			shape.draw();
			shape.erase();
		}catch(UnsupportShapeException e){
			System.out.println(e.toString());
		}
	}
}
