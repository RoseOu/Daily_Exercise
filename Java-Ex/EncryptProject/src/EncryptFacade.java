
public class EncryptFacade {
	FileReader reader;
	CipherMachine cipher;
	FileWriter writer;
	
	public EncryptFacade(){
		reader = new FileReader();
		cipher = new CipherMachine();
		writer = new FileWriter();	
	}
	
	public void fileEncrypt(String fileNameSrc,String fileNameDes){
		String plainStr = reader.read(fileNameSrc);
		String encryptStr = cipher.encrypt(plainStr);
		writer.write(encryptStr, fileNameDes);
	}
}
