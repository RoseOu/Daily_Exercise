
public class MyProduct implements Product{
	private Object[] obj={"衣服","家具","电子产品","食物"};
	
	public ProductIterator createIterator(){
		return new MyIterator();
	}
	
	private class MyIterator implements ProductIterator{
		private int currentIndex=0;
		
		public void next(){
			if(currentIndex<obj.length){
				currentIndex++;
			}
		}
		
		public void previous(){
			if(currentIndex>0){
				currentIndex--;
			}
		}
		
		public void setProduct(int i){
			currentIndex=i;
		}
		
		public Object currentProduct(){
			return obj[currentIndex];
		}
		
		public boolean isLast(){
			return currentIndex==obj.length;
		}
		
		public boolean isFirst(){
			return currentIndex==0;
		}
	}
}
