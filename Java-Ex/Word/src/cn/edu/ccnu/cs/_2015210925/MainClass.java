package cn.edu.ccnu.cs._2015210925;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.*;

public class MainClass {
	public static void main(String[] args) throws FileNotFoundException {
		String root = "english";
		String dataFilename = "data.txt";
		Map<String, WordCount> result = new HashMap<String, WordCount>();
		
		File dir = new File(root);
		File[] files = dir.listFiles();
		
		for(File file: files) {
			if(file.isFile()) {
				statWords(file, result);
			}
		}
		
		// sort and output
		List<WordCount> wcs = new ArrayList<WordCount>();
		wcs.addAll(result.values());
		
		Collections.sort(wcs, new Comparator<WordCount>(){
			@Override
			public int compare(WordCount o1, WordCount o2) {
				return o1.count - o2.count;
			}
		});
		
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(new FileOutputStream(dataFilename))));
		for(WordCount wc: wcs) {
			pw.println(wc);
		}
		pw.close();
		
	}
	
	public static void statWords(File file, Map<String, WordCount> result) {
		Scanner s = null;
		try {
			s = new Scanner(file);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		while(s.hasNext()) {
			String word = s.next();
			WordCount wc = null;
			if((wc = (WordCount) result.get(word)) == null) {
				wc = new WordCount();
				wc.word=word;
				result.put(word, wc);
			}
			wc.count++;
		}
	}
}

class WordCount {
	String word;
	int count;
	
	@Override
	public String toString() {
		return this.word + " " + this.count;
	}
}
