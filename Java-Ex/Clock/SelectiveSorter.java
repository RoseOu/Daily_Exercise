package cn.edu.ccnu.cs._2015210925;

class SelectiveSorter implements Sorter{
	@Override
	public void sort(Clock[] cs,Comparor comp){
		int i;
		int j;
		int lastExchangeIndex;
		Clock W;
		
		i=cs.length;
		while(i>1){
			lastExchangeIndex=1;
			for(j=0;j<i-1;j++){
				if(comp.compare(cs[j+1],cs[j])==1){
					W=cs[j];
					cs[j]=cs[j+1];
					cs[j+1]=W;
					lastExchangeIndex=j+1;
				}
			}
			i=lastExchangeIndex;
		}
	}
}