
public class TextFile extends AbstractFile{
	private String fileName;
	
	TextFile(String fileName){
		this.fileName=fileName;
	}
	
	public void add(AbstractFile element){
		System.out.println("Text file cannot add anything!");
	}
	public void remove(AbstractFile element){
		System.out.println("Text file cannot remove anything!");
	};
	public void display(){
		System.out.println("Scanning text file!");
		System.out.println(this.fileName);
	}
}
