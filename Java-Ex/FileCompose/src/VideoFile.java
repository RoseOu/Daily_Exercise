
public class VideoFile extends AbstractFile{
	private String fileName;
	
	VideoFile(String fileName){
		this.fileName=fileName;
	}
	
	public void add(AbstractFile element){
		System.out.println("Video file cannot add anything!");
	}
	public void remove(AbstractFile element){
		System.out.println("Video file cannot remove anything!");
	};
	public void display(){
		System.out.println("Scanning video file!");
		System.out.println(this.fileName);
	}
}
