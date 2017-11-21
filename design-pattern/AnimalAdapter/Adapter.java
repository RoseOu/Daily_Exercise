
public class Adapter implements Cat,Dog{
	private ConcreteDog dog=null;
	private ConcreteCat cat=null;
	
	public void dogLooks(){
		System.out.println("I am a dog,not a cat.");
	}
	
	public void catLooks(){
		System.out.println("I am a cat,not a dog.");
	}
	
	public void wang(){
		cat.catchMouse();
	}
	
	public void catchMouse(){
		dog.wang();
	}
	
	public Adapter(ConcreteDog dog){
		this.dog=dog;
	}
	
	public Adapter(ConcreteCat cat){
		this.cat=cat;
	}
}
