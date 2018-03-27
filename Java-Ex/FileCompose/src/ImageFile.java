
public class ImageFile extends AbstractFile{
	private String fileName;
	
	ImageFile(String fileName){
		this.fileName=fileName;
	}
	
	public void add(AbstractFile element){
		System.out.println("Image file cannot add anything!");
	}
	public void remove(AbstractFile element){
		System.out.println("Image file cannot remove anything!");
	};
	public void display(){
		System.out.println("Scanning image file!");
		System.out.println(this.fileName);
	}
}
