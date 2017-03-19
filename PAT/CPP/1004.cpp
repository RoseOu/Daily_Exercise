/*
读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。

输入格式：每个测试输入包含1个测试用例，格式为

  第1行：正整数n
  第2行：第1个学生的姓名 学号 成绩
  第3行：第2个学生的姓名 学号 成绩
  ... ... ...
  第n+1行：第n个学生的姓名 学号 成绩
其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。
输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。

输入样例：
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
输出样例：
Mike CS991301
Joe Math990112
*/
#include <iostream>
#include <string>
using namespace std;

class Student{
	private:
		string name;
		string no;
		int score;
	public:
		Student(){}
		~Student(){}
		Student(string name,string no,int score){
			this->name=name;
			this->no=no;
			this->score=score;
		}

		string Getname(){
			return name;
		}

		string Getno(){
			return no;
		}

		int Getscore(){
			return score;
		}

		static Student findmax(Student *students,int n){
			Student maxstu=students[0];
			for(int i=0;i<n;i++){
				if(students[i].Getscore()>maxstu.Getscore()){
					maxstu=students[i];
				}
			}
			return maxstu;
		}

		static Student findmin(Student *students,int n){
			Student minstu=students[0];
			for(int i=0;i<n;i++){
				if(students[i].Getscore()<minstu.Getscore()){
					minstu=students[i];
				}
			}
			return minstu;
		}
};

int main(){
	int n;
	Student *students,maxstu,minstu;
	cin>>n;
	students=new Student[n];
	for(int i=0;i<n;i++){
		string name,no;
		int score;
		Student stu;
		cin>>name>>no>>score;
		stu=Student(name,no,score);
		students[i]=stu;
	}
	maxstu=Student::findmax(students,n);
	minstu=Student::findmin(students,n);
	cout<<maxstu.Getname()<<" "<<maxstu.Getno()<<endl;
	cout<<minstu.Getname()<<" "<<minstu.Getno();
	return 0;
}