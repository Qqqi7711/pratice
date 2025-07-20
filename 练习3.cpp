#include <iostream>
using namespace std;

//左移运算符重载<<
//class Person {
//	friend ostream& operator<<(ostream& cout, Person& p);//友元访问私有属性
//public :
//	Person(int a, int b) :m_a(a), m_b(b) {
//	}
//private:
//	int m_a;
//	int m_b;
//};
//ostream& operator<< (ostream& cout, Person& p) {//cout是输出流对象 类型为ostream
//	cout << "m_a = " << p.m_a << ", m_b = " << p.m_b;
//	return cout;
//}
//void test() {
//	Person p(11, 22);
//	cout << p << endl;//链式调用，所以上面重载函数返回值类型为ostream&，可以继续使用cout
//}

//递增运算符重载++
//class MyInteger {
//	friend ostream& operator<<(ostream& cout, MyInteger m);
//public:
//	MyInteger(int a) :m_a(a) {
//	}
//	//前置++重载
//	MyInteger &operator++() {
//		m_a++;
//		return *this;
//	}
//	//后置++重载
//	MyInteger operator++(int) {//用int占位符区分前后置，只能用int
//		//注意：后置++重载函数不能返回引用，因为返回的对象是临时对象
//		MyInteger temp = *this;//保存当前对象
//		m_a++;
//		return temp;//返回保存对象
//	}
//private:
//	int m_a;
//};
//ostream& operator<< (ostream& cout, MyInteger m) {//注意这里m是值传递
//	//后置重载函数返回的是一个临时对象，不能进行引用传递
//	cout << m.m_a;
//	return cout;
//}
//void test() {
//	MyInteger myInteger(11);
//	cout << "++myInteger = " << ++myInteger << endl; //前置++
//	cout << "myInteger++ = " << myInteger++ << endl; //后置++
//	cout << "myInteger = " << myInteger << endl; //查看当前值
//}

//赋值运算符重载=  其实就是深拷贝
//函数调用运算符重载()   仿函数

//继承
//语法： class 子类(派生类) : 继承方式 父类(基类){} 如：class Dog : public Animal {}
//继承方式：public公共继承 protected保护继承 private私有继承
//继承中同名成员处理/继承中同名静态成员处理方式
//子类中出现和父类中同名的成员，子类的会隐藏掉父类的所有同名成员（包括重载函数）
//如果要显现出父类中的，则需要添加作用域
//如：s.m_a;(显示子类的值)  s.Base::m_a;(显示父类的值)
//如：s.func();(调用子类函数) s.Base::func();(调用父类函数)
//多继承语法:C++允许一个类继承多个父类
//语法：class 子类(派生类) : 继承方式 父类1(基类1), 继承方式 父类2(基类2) {}

//多态
//分为两类 静态多态（即函数重载和运算符重载） 动态多态（派生类和虚函数实现运行时多态）
//静态多态：编译阶段就确定了函数的地址
//动态多态：运行阶段确定函数地址
//动态多态的满足条件：
//1、有继承关系
//2、子类重写父类的虚函数（重写即返回类型 参数 函数名都相同）
//动态多态使用：父类的指针或者引用 执行子类对象
//
//class Animal {
//public :
//	virtual void speak() {//父类必须时虚拟继承
//		//不是虚拟继承的话，doSpeak函数在编译的时候就确定了函数地址为Animal的地址
//		cout << "动物" << endl;
//	}
//};
//
//class Cat :public Animal{//继承Animal
//public:
//	void speak() {
//		cout << "小猫" << endl;
//	}
//};
//
//void doSpeak(Animal &animal) {//必须时传参的时候父类用引用传参或者指针传参
//	//传参的时候子类的类型会自动转换成为父类的类型，不需要使用强制转换
//	animal.speak();
//}
//
//void test() {
//	Cat cat;
//	doSpeak(cat);
//}

//模拟计算器

//传统写法   不使用多态
//class Calculator {
//public:
//	//加法
//	int getResult(string op) {
//		if (op == "+") {
//			return num1 + num2;
//		}
//		else if(op== "-") {
//			return num1 - num2;
//		}
//		else if (op == "*") {
//			return num1 * num2;
//		}
//	}
//
//	int num1;//数值1
//	int num2;//数值2
//};
//
//void test() {
//	Calculator c;
//	c.num1 = 11;
//	c.num2 = 22;
//	cout<<c.num1<<"+"<<c.num2<<"="<<c.getResult("+")<<endl;
//	cout << c.num1 << "-" << c.num2 << "=" << c.getResult("-") << endl;
//	cout << c.num1 << "*" << c.num2 << "=" << c.getResult("*") << endl;
//}

//使用多态
//class Calculator {
//public:
//	virtual int getResult() {
//		return 0;
//	}
//
//	int num1;
//	int num2;
//};
//
////加法类
//class AddCalculator :public Calculator {
//public:
//	int getResult() {
//		return num1 + num2;
//	}
//};
//
////减法类
//class SubCalculator :public Calculator {
//public:
//	int getResult() {
//		return num1 - num2;
//	}
//};
//
////乘法类
//class MulCalculator :public Calculator {
//public:
//	int getResult() {
//		return num1 * num2;
//	}
//};
//
//void test() {
//	//利用指针实现多态
//	Calculator* p = new AddCalculator;//在堆区new一个加法类的对象，记得用完之后要用delete释放
//	p->num1 = 11;
//	p->num2 = 12;
//	cout << p->num1 << "+" << p->num2 << "=" << p->getResult() << endl;
//	delete p;//使用完成之后释放掉开辟的内存
//
//	p = new SubCalculator;
//	p->num1 = 11;
//	p->num2 = 12;
//	cout << p->num1 << "-" << p->num2 << "=" << p->getResult() << endl;
//	delete p;
//
//	p = new MulCalculator;
//	p->num1 = 11;
//	p->num2 = 12;
//	cout << p->num1 << "*" << p->num2 << "=" << p->getResult() << endl;
//	delete p;
//}

//纯虚函数
//语法： virtual 返回值类型 函数名(参数列表) = 0;

//抽象类：类当中包含了纯虚函数的类叫做抽象类
//抽象类不能实例化对象(无论堆区还是栈区)，只能用来继承
//子类必须重写父类的纯虚函数，否则子类也是抽象类

//饮品制作

//class AbstractDrink {
//public:
//	virtual void boil() = 0;//煮水
//	virtual void brew() = 0;//冲泡
//	virtual void pourInCup() = 0;//倒入杯中
//	virtual void putSTH() = 0;//放入辅料
//	void make() {
//		boil();
//		brew();
//		pourInCup();
//		putSTH();
//	}
//};
//
//class Coffee :public AbstractDrink {
//public:
//	void boil() {
//		cout << "煮怡宝矿泉水" << endl;
//	}
//	void brew() {
//		cout << "冲泡咖啡粉" << endl;
//	}
//	void pourInCup() {
//		cout << "倒入玻璃杯中" << endl;
//	}
//	void putSTH() {
//		cout << "加入糖和牛奶" << endl;
//	}
//};
//
//class Tea :public AbstractDrink {
//public:
//	void boil() {
//		cout << "煮农夫山泉矿泉水" << endl;
//	}
//	void brew() {
//		cout << "冲泡茶叶" << endl;
//	}
//	void pourInCup() {
//		cout << "倒入茶杯中" << endl;
//	}
//	void putSTH() {
//		cout << "加入柠檬" << endl;
//	}
//};
//
//void doWork(AbstractDrink * abs) {
//	abs->make();
//	delete abs; //使用完成之后释放掉开辟的内存
//}
//
//void test() {
//	//制作咖啡
//	doWork(new Coffee());
//	cout << "------------------" << endl;
//	//制作茶
//	doWork(new Tea());
//}

//多态使用的问题--如果子类中有堆区开辟的数据，则父类指针在释放的时候只会调用父类自己的析构函数
//无法调用子类的析构函数，从而导致没有办法清除干净子类的数据
//虚析构 纯虚析构
//共性：可以解决父类指针释放对象  需要有具体的函数实现
//区别：如果时纯虚析构函数，则该类属于抽象类，不能实例化对象

//文件操作--通过文件将数据持久化
//使用文件操作要包含头文件 <fstream> 文件流
// 文件类型分为文本文件(ASCII码形式存储)和二进制文件(二进制形式存储)
//文件流一般包括三个类   1、oftream 写操作  2、ifstream 读操作  3、fstream 读写操作
// 文件打开方式：
// 1、ios::in 读文件
// 2、ios::out 写文件
// 3、ios::ate 初始位置为文件末尾
// 4、ios::app 追加的方式写入
// 5、ios::trunc 如果文件存在则先清空删除再创建
// 6、ios::binary 二进制的方式打开文件
// 文件打开操作方式可以配合使用 利用操作符 |   
// 比如用二进制的形式写文件  ios::out | ios::binary
//文本文件写文件：
//1、包含头文件 #include <fstream>
// 2、创建文件流对象 ofstream ofs;
// 3、打开文件 ofs.open("文件路径",打开方式);
// 4、写数据 ofs<<"写入的数据";
// 5、关闭文件 ofs.close();
//文本文件读文件：
//1、包含头文件 #include <fstream>
// 2、创建文件流对象 ifstream ifs;   
// 3、打开文件 ifs.open("文件路径",打开方式);   //通常会判断文件是否成功打开 ifs.is_open();(返回类型bool)
// if(!ifs.is_open()){cout<<"文件打开失败"<<endl; return;}
// 4、读数据 
// 第一种： 
// char buf[1024] = { 0 };  //定义一个字符数组
// while( ifs >> buf ){ cout << buf <<endl; }
// 第二种：
// char buf[1024] = { 0 };
// while(ifs.getline(buf,sizeof(buf))){ cout << buf <<endl; }
// 第三种：
// string buf;
// while(getline(ifs,buf)) { cout << buf << endl; }
// 第四种：//不推荐
// char c;
// while((c = ifs.get()) != EOF ) { cout << c; }
// 5、关闭文件 ofs.close();
// 二进制文件写读文件：
// 读数据的时候最好不要用string 用字符数组 用string容易引发乱码问题
//#include <fstream>
//class Person {
//public:
//	char m_name[64];
//	int m_age;
//};
//void test() {
//	//Person p = { "张三",18 };
//	//ofstream ofp;
//	//ofp.open("person.txt", ios::out | ios::binary);
//	//ofp.write((const char*) & p, sizeof(Person));//写入数据
//	//ofp.close();
//
//	ifstream ifp;
//	ifp.open("person.txt",ios::in | ios::binary );
//	if (!ifp.is_open()) {
//		cout << "文件打开失败" << endl;
//		return;
//	}
//	Person p;
//	ifp.read((char*) & p, sizeof(Person));
//	cout << "姓名：" << p.m_name << " 年龄：" << p.m_age << endl;
//	ifp.close();
//}



int main() {
	//test();
	system("pause");
	return 0;
}
