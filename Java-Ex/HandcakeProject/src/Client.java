import java.util.*;

public class Client {
	public static void main(String args[]){
		System.out.println("------------ ‘啦啦手抓饼’营业啦 ------------");
		HandcakeShop lalaShop = HandcakeShop.getHandcakeShop();
		AbstractCommand orderCommand = new OrderCommand(lalaShop);
		List<String> alltype=new ArrayList<>();
		alltype.add("香蕉水果");
		alltype.add("榴莲水果");
		alltype.add("煎鸡蛋");
		alltype.add("煮鸡蛋");
		alltype.add("黑椒培根");
		alltype.add("沙拉培根");
		System.out.println("本店手抓饼菜单：香蕉水果、榴莲水果、煎鸡蛋、煮鸡蛋、黑椒培根、沙拉培根");
		System.out.println();
		
		int choice=0;
		while(choice==0){
			Scanner input = new Scanner(System.in);
			System.out.println("--------------- 选择操作 ---------------");
			System.out.println("1.客户下订单 2.店员查看订单 3.店员通知顾客：");
			choice = input.nextInt();
			System.out.println();
			if(choice==1){
				System.out.println("------------ 客户填写订单 ------------");
				System.out.println("输入客户姓名：");
				String name = input.next();
				System.out.println("输入你要的手抓饼类型（香蕉水果、榴莲水果、煎鸡蛋、煮鸡蛋、黑椒培根、沙拉培根）：");
				String type="";
				while(!alltype.contains(type)){
					type = input.next();
				}
				System.out.println("输入你要的数量：");
				int num = input.nextInt();
				Customer cus = new ConcreteCustomer(lalaShop,type,name);
				cus.setCommand(orderCommand);
				System.out.println("------------ 店员填写订单 ------------");
				System.out.println("输入手抓饼的原价：");
				int price = input.nextInt();
				
				OrderHandcake dis = new OrderHandcake();
				int distyle=0;
				double m,cost=0,total=0;
				while(distyle!=1&&distyle!=2&&distyle!=3){
					System.out.println("输入你选择的优惠方式（1.直接标价  2.减价 3.打折）：");
					distyle = input.nextInt();
					if(distyle!=1&&distyle!=2&&distyle!=3){
						System.out.println("输入错误！");
					}
				}
				if(distyle==1){
					dis.setStyle(new DiscountStyleOne());
					System.out.println("输入优惠后的价钱：");
					m = input.nextDouble();
					dis.setM(m);
					dis.setPrice(price);
					cost = dis.getCost(dis.getPrice(),dis.getM());
					total = cost*num;
					cus.createOrder(type,name,num,price,cost,total);
				}else if(distyle==2){
					dis.setStyle(new DiscountStyleTwo());
					System.out.println("输入要减的价钱：");
					m = input.nextDouble();
					dis.setM(m);
					dis.setPrice(price);
					cost = dis.getCost(dis.getPrice(),dis.getM());
					total = cost*num;
					cus.createOrder(type,name,num,price,cost,total);
				}else if(distyle==3){
					dis.setStyle(new DiscountStyleThree());
					System.out.println("输入折扣：");
					m = input.nextDouble();
					dis.setM(m);
					dis.setPrice(price);
					cost = dis.getCost(dis.getPrice(),dis.getM());
					total = cost*num;
					cus.createOrder(type,name,num,price,cost,total);
				}
				System.out.println();
				choice = 0;
			}else if(choice == 2){
				System.out.println("---------------- 订单列表 ----------------");
				System.out.println("用户姓名"+"   "+"手抓饼类型"+"   "+"数量"+"   "+"原价"+"    "+"优惠价"+"    "+"总价");
				lalaShop.showOrder();
				System.out.println();
				choice = 0;
			}else if(choice == 3){
				System.out.println("---------------- 店员通知 ----------------");
				lalaShop.notifyCustomer();
				System.out.println();
				choice = 0;
			}else{
				System.out.println("输入无效");
				choice = 0;
			}
		}
	}
}
