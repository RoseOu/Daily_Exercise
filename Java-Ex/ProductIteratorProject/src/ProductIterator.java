
public interface ProductIterator {
	void setProduct(int i);
	void next();
	void previous();
	boolean isLast();
	boolean isFirst();
	Object currentProduct();
}
