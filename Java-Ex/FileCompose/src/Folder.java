import java.util.ArrayList;

public class Folder extends AbstractFile{
	private ArrayList<AbstractFile> fileList = new ArrayList<AbstractFile>();
	private String fileName;
	
	Folder(String fileName){
		this.fileName=fileName;
	}
	
	public void add(AbstractFile element){
		fileList.add(element);
	}
	public void remove(AbstractFile element){
		fileList.remove(element);
	};
	public void display(){
		System.out.println("Scanning folder!");
		System.out.println(this.fileName);
		for(AbstractFile f:fileList){
			((AbstractFile)f).display();
		}
		System.out.println();
	}
}
