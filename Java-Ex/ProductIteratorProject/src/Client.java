
public class Client {
	public static void display(Product pd){
		ProductIterator i=pd.createIterator();
		System.out.println("商品：");
		while(!i.isLast()){
			System.out.println(i.currentProduct().toString());
			i.next();
		}
	}
	
	public static void reverseDisplay(Product pd){
		ProductIterator i=pd.createIterator();
		i.setProduct(4);
		System.out.println("逆向遍历商品：");
		while(!i.isFirst()){
			i.previous();
			System.out.println(i.currentProduct().toString());
		}
	}
	
	public static void main(String a[]){
		Product pd;
		pd=new MyProduct();
		display(pd);
		System.out.println("-------------");
		reverseDisplay(pd);
	}
}
