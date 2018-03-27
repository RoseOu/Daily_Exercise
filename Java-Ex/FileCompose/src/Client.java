
public class Client {
	public static void main(String a[]){
		AbstractFile studyFolder,imageFolder,teachFolder;
		AbstractFile video,image1,image2,text1,text2;
		
		studyFolder = new Folder("学习资料");
		imageFolder = new Folder("图片文件夹");
		teachFolder = new Folder("教材文件夹");
		video = new VideoFile("录像");
		studyFolder.add(imageFolder);
		studyFolder.add(teachFolder);
		studyFolder.add(video);
		image1 = new ImageFile("图片1");
		image2 = new ImageFile("图片2");
		imageFolder.add(image1);
		imageFolder.add(image2);
		text1 = new TextFile("文本1");
		text2 = new TextFile("文本2");
		teachFolder.add(text1);
		teachFolder.add(text2);
		studyFolder.display();
	}
}
