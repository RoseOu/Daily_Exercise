package cn.edu.ccnu.cs._2015210925;

import java.io.*;

public class MainClass {
	public static void main(String[] args){
		BufferedReader br=null;
		PrintWriter pw=null;
		try{
			FileInputStream in = new FileInputStream("/Users/rose/study/java/file/a.txt");
			InputStreamReader input = new InputStreamReader(in,"GBK");
			br = new BufferedReader(input);

			FileOutputStream on = new FileOutputStream("/Users/rose/study/java/file/b.txt");
			OutputStreamWriter output = new OutputStreamWriter(on,"UTF-8");
			BufferedWriter bw = new BufferedWriter(output);
			pw = new PrintWriter(bw);

			String line = null;
			while((line=br.readLine()) !=null){
				pw.println(line);
			}
			while((line=br.readLine()) !=null){
				pw.write(line);
			}
		} catch (Exception e){
			e.printStackTrace();
		}
		finally{
			try{
				br.close();
			}catch(Exception e){
				e.printStackTrace();
			}
			try{
				pw.close();
			}catch(Exception e){
				e.printStackTrace();
			}
		}
	}
}


