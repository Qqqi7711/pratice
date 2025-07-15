#include <iostream>
using namespace std;

//构造函数

//class Person {
//public:
//
//	int m_age;
//
//
//	Person() {
//		cout << "无参构造函数调用" << endl;
//	}
//	Person(int age) {
//      m_age = age;
//		cout << "有参构造函数的调用" << endl;
//	}
//	Person(const Person& p) {
// 	    m_age = p.m_age;
//		cout << "拷贝构造函数调用" << endl;
//	}
//
//	~Person() {
//		cout << "析构函数调用" << endl;
//	}
//};
//
//void test() {
//	////括号法调用构造函数
//	//Person p1;
//	//Person p2(10);
//	//Person p3(p2);
//
//	////显示法调用
//	//Person p1;
//	//Person p2 = Person(10);
//	//Person p3 = Person(p2);
//
//	//隐式法调用
//	Person p1;
//	Person p2 = 10;
//	Person p3 = p2;
//}
//
//int main()
//{
//
//	test();
//
//	system("pause");
//	return 0;
//}

//拷贝函数调用时机
//1、使用一个已经创建完毕的对象来初始化一个新对象
//
//2、值传递的方式给函数参数传值
// 其实就是把这个Person的一个实例传给一个函数做参数的时候，不是传地址，不是引用传参
// 这样的话，就会先调用拷贝构造函数，先拷贝再传过去，其函数中修改的值不对原本的值有影响
//
//3、值方式返回局部对象
//函数返回一个对象的时候，在该函数的范围内，函数里面的局部变量在调用完之后会被销毁
//然后想要返回这个局部变量的值，就会先拷贝一份出来（调用拷贝构造函数），再返回出去

//构造函数调用规则
//1、创建类，编译器会自动添加3个构造函数
//2、若写了有参，则编译器不会写无参，但会自动写上拷贝构造函数，此时Person p1;就会报错
//3、若写了构造，则编译器无参有参都不会写

//浅拷贝：简单赋值拷贝 会带来重复释放指针的问题
//深拷贝：在堆区重新申请内存空间，进行拷贝操作 new一个
//如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，重新在堆区申请一块内存

//初始化列表
//在构造函数中写
//class Person {
//
//public:
//
//	////普通赋值
//	//Person(int a, int b, int c) {
//	//	m_a = a;
//	//	m_b = b;
//	//	m_c = c;
//	//}
//
//	//初始化列表赋值
//	Person(int a, int b, int c) :m_a(a), m_b(b), m_c(c) {
//
//	}
//
//	int m_a;
//	int m_b;
//	int m_c;
//};
//
//void test() {
//	Person p(1, 2, 3);
//	cout << "m_a = " << p.m_a << endl;
//	cout << "m_b = " << p.m_b << endl;
//	cout << "m_c = " << p.m_c << endl;
//}
//
//int main() {
//
//	test();
//	
//	system("pause");
//	return 0;
//}

//静态成员
//静态成员变量：所有对象共享同一份数据，编译阶段分配内存，类内声明，类外初始化
//静态成员变量有两种访问方式：
//1、通过对象访问 Person p;   p.m_a
//2、通过类名访问 Person::m_a 
//静态成员函数：所有对象共享，只能访问静态成员变量，不能访问非静态成员变量，不能使用this指针
//
//class Person {
//public:
//	static int m_a;//类内声明静态成员变量
//};
//int Person::m_a = 10;//类外初始化静态成员变量（必要操作）

//空对象占用内存大小为1个字节
//成员变量和成员函数是分开存储的，只有成员变量才算入类内空间

//this指针:谁调用它，它指向谁
//1、变量名冲突的时候，可以用this指针来区分 this->
//2、返回对象本身的引用，方便链式操作 *this
//
//class Person {
//public:
//	int age;
//	Person(int age) {
//		this->age = age;
//	}
//	Person &setAge() {
//		//这里的返回必须是引用类型
//		//如果不是引用类型的话，则重新生成一个临时对象，把值拷贝给新对象，返回出来的不是原对象
//		//如果是引用类型的话，则返回的就是原对象的地址，直接修改原对象的值
//		age += 10;
//		return *this; //返回对象本身的引用
//	}
//};
//void test() {
//	Person p1(10);
//	p1.setAge().setAge ();
//	cout << "p1年龄" << p1.age << endl;
//}

//const修饰成员函数
//常函数：成员函数后面加const  void show() const{},常函数内不可修改成员变量的值
//        变量用mutable修饰后可以   mutable int m_a;
//常对象：const Person p1;  常对象只能调用常函数

//友元 friend
// 1、全局函数做友元
//只要在类内声明友元函数即可访问该类的属性，包括私有的
//class Person {
//	friend void showPerson(Person& p);
//private :
//	int m_age;
//};
//
//void showPerson(Person& p) {
//	cout << "年龄是：" << p.m_age << endl;
//}
//2、类做友元
//在类内做声明 friend class A;
//3、成员函数做友元
//friend void A::show(); 

//运算符重载 operator

//加号运算符重载
////1、成员函数重载+
//class Person {
//public:
//	/*Person operator+(Person& p) {
//		Person temp;
//		temp.m_a = this->m_a + p.m_a;
//		temp.m_b = this->m_b + p.m_b;
//		return temp;
//	}*/
//	Person() {
//		m_a = 10;
//		m_b = 10;
//	}
//	int m_a;
//	int m_b;
//};
//
////2、全局函数重载+
//Person operator+(Person& p1, Person& p2) {
//	Person temp;
//	temp.m_a = p1.m_a + p2.m_a;
//	temp.m_b = p1.m_b + p2.m_b;
//	return temp;
//}
//
//void test() {
//	Person p1,p2,p3;
//	p3 = p1 + p2;
//	cout << "p3.m_a = " << p3.m_a << endl;
//	cout << "p3.m_b = " << p3.m_b << endl;
//}


int main() {
	//test();
	system("pause");
	return 0;
}
