#include <iostream>
using namespace std;

//�������������<<
//class Person {
//	friend ostream& operator<<(ostream& cout, Person& p);//��Ԫ����˽������
//public :
//	Person(int a, int b) :m_a(a), m_b(b) {
//	}
//private:
//	int m_a;
//	int m_b;
//};
//ostream& operator<< (ostream& cout, Person& p) {//cout����������� ����Ϊostream
//	cout << "m_a = " << p.m_a << ", m_b = " << p.m_b;
//	return cout;
//}
//void test() {
//	Person p(11, 22);
//	cout << p << endl;//��ʽ���ã������������غ�������ֵ����Ϊostream&�����Լ���ʹ��cout
//}

//�������������++
//class MyInteger {
//	friend ostream& operator<<(ostream& cout, MyInteger m);
//public:
//	MyInteger(int a) :m_a(a) {
//	}
//	//ǰ��++����
//	MyInteger &operator++() {
//		m_a++;
//		return *this;
//	}
//	//����++����
//	MyInteger operator++(int) {//��intռλ������ǰ���ã�ֻ����int
//		//ע�⣺����++���غ������ܷ������ã���Ϊ���صĶ�������ʱ����
//		MyInteger temp = *this;//���浱ǰ����
//		m_a++;
//		return temp;//���ر������
//	}
//private:
//	int m_a;
//};
//ostream& operator<< (ostream& cout, MyInteger m) {//ע������m��ֵ����
//	//�������غ������ص���һ����ʱ���󣬲��ܽ������ô���
//	cout << m.m_a;
//	return cout;
//}
//void test() {
//	MyInteger myInteger(11);
//	cout << "++myInteger = " << ++myInteger << endl; //ǰ��++
//	cout << "myInteger++ = " << myInteger++ << endl; //����++
//	cout << "myInteger = " << myInteger << endl; //�鿴��ǰֵ
//}

//��ֵ���������=  ��ʵ�������
//�����������������()   �º���

//�̳�
//�﷨�� class ����(������) : �̳з�ʽ ����(����){} �磺class Dog : public Animal {}
//�̳з�ʽ��public�����̳� protected�����̳� private˽�м̳�
//�̳���ͬ����Ա����/�̳���ͬ����̬��Ա����ʽ
//�����г��ֺ͸�����ͬ���ĳ�Ա������Ļ����ص����������ͬ����Ա���������غ�����
//���Ҫ���ֳ������еģ�����Ҫ���������
//�磺s.m_a;(��ʾ�����ֵ)  s.Base::m_a;(��ʾ�����ֵ)
//�磺s.func();(�������ຯ��) s.Base::func();(���ø��ຯ��)
//��̳��﷨:C++����һ����̳ж������
//�﷨��class ����(������) : �̳з�ʽ ����1(����1), �̳з�ʽ ����2(����2) {}

//��̬
//��Ϊ���� ��̬��̬�����������غ���������أ� ��̬��̬����������麯��ʵ������ʱ��̬��
//��̬��̬������׶ξ�ȷ���˺����ĵ�ַ
//��̬��̬�����н׶�ȷ��������ַ
//��̬��̬������������
//1���м̳й�ϵ
//2��������д������麯������д���������� ���� ����������ͬ��
//��̬��̬ʹ�ã������ָ��������� ִ���������
//
//class Animal {
//public :
//	virtual void speak() {//�������ʱ����̳�
//		//��������̳еĻ���doSpeak�����ڱ����ʱ���ȷ���˺�����ַΪAnimal�ĵ�ַ
//		cout << "����" << endl;
//	}
//};
//
//class Cat :public Animal{//�̳�Animal
//public:
//	void speak() {
//		cout << "Сè" << endl;
//	}
//};
//
//void doSpeak(Animal &animal) {//����ʱ���ε�ʱ���������ô��λ���ָ�봫��
//	//���ε�ʱ����������ͻ��Զ�ת����Ϊ��������ͣ�����Ҫʹ��ǿ��ת��
//	animal.speak();
//}
//
//void test() {
//	Cat cat;
//	doSpeak(cat);
//}

//ģ�������

//��ͳд��   ��ʹ�ö�̬
//class Calculator {
//public:
//	//�ӷ�
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
//	int num1;//��ֵ1
//	int num2;//��ֵ2
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

//ʹ�ö�̬
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
////�ӷ���
//class AddCalculator :public Calculator {
//public:
//	int getResult() {
//		return num1 + num2;
//	}
//};
//
////������
//class SubCalculator :public Calculator {
//public:
//	int getResult() {
//		return num1 - num2;
//	}
//};
//
////�˷���
//class MulCalculator :public Calculator {
//public:
//	int getResult() {
//		return num1 * num2;
//	}
//};
//
//void test() {
//	//����ָ��ʵ�ֶ�̬
//	Calculator* p = new AddCalculator;//�ڶ���newһ���ӷ���Ķ��󣬼ǵ�����֮��Ҫ��delete�ͷ�
//	p->num1 = 11;
//	p->num2 = 12;
//	cout << p->num1 << "+" << p->num2 << "=" << p->getResult() << endl;
//	delete p;//ʹ�����֮���ͷŵ����ٵ��ڴ�
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

//���麯��
//�﷨�� virtual ����ֵ���� ������(�����б�) = 0;

//�����ࣺ�൱�а����˴��麯���������������
//�����಻��ʵ��������(���۶�������ջ��)��ֻ�������̳�
//���������д����Ĵ��麯������������Ҳ�ǳ�����

//��Ʒ����

//class AbstractDrink {
//public:
//	virtual void boil() = 0;//��ˮ
//	virtual void brew() = 0;//����
//	virtual void pourInCup() = 0;//���뱭��
//	virtual void putSTH() = 0;//���븨��
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
//		cout << "��������Ȫˮ" << endl;
//	}
//	void brew() {
//		cout << "���ݿ��ȷ�" << endl;
//	}
//	void pourInCup() {
//		cout << "���벣������" << endl;
//	}
//	void putSTH() {
//		cout << "�����Ǻ�ţ��" << endl;
//	}
//};
//
//class Tea :public AbstractDrink {
//public:
//	void boil() {
//		cout << "��ũ��ɽȪ��Ȫˮ" << endl;
//	}
//	void brew() {
//		cout << "���ݲ�Ҷ" << endl;
//	}
//	void pourInCup() {
//		cout << "����豭��" << endl;
//	}
//	void putSTH() {
//		cout << "��������" << endl;
//	}
//};
//
//void doWork(AbstractDrink * abs) {
//	abs->make();
//	delete abs; //ʹ�����֮���ͷŵ����ٵ��ڴ�
//}
//
//void test() {
//	//��������
//	doWork(new Coffee());
//	cout << "------------------" << endl;
//	//������
//	doWork(new Tea());
//}

//��̬ʹ�õ�����--����������ж������ٵ����ݣ�����ָ�����ͷŵ�ʱ��ֻ����ø����Լ�����������
//�޷���������������������Ӷ�����û�а취����ɾ����������
//������ ��������
//���ԣ����Խ������ָ���ͷŶ���  ��Ҫ�о���ĺ���ʵ��
//�������ʱ����������������������ڳ����࣬����ʵ��������

//�ļ�����--ͨ���ļ������ݳ־û�
//ʹ���ļ�����Ҫ����ͷ�ļ� <fstream> �ļ���
// �ļ����ͷ�Ϊ�ı��ļ�(ASCII����ʽ�洢)�Ͷ������ļ�(��������ʽ�洢)
//�ļ���һ�����������   1��oftream д����  2��ifstream ������  3��fstream ��д����
// �ļ��򿪷�ʽ��
// 1��ios::in ���ļ�
// 2��ios::out д�ļ�
// 3��ios::ate ��ʼλ��Ϊ�ļ�ĩβ
// 4��ios::app ׷�ӵķ�ʽд��
// 5��ios::trunc ����ļ������������ɾ���ٴ���
// 6��ios::binary �����Ƶķ�ʽ���ļ�
// �ļ��򿪲�����ʽ�������ʹ�� ���ò����� |   
// �����ö����Ƶ���ʽд�ļ�  ios::out | ios::binary
//�ı��ļ�д�ļ���
//1������ͷ�ļ� #include <fstream>
// 2�������ļ������� ofstream ofs;
// 3�����ļ� ofs.open("�ļ�·��",�򿪷�ʽ);
// 4��д���� ofs<<"д�������";
// 5���ر��ļ� ofs.close();
//�ı��ļ����ļ���
//1������ͷ�ļ� #include <fstream>
// 2�������ļ������� ifstream ifs;   
// 3�����ļ� ifs.open("�ļ�·��",�򿪷�ʽ);   //ͨ�����ж��ļ��Ƿ�ɹ��� ifs.is_open();(��������bool)
// if(!ifs.is_open()){cout<<"�ļ���ʧ��"<<endl; return;}
// 4�������� 
// ��һ�֣� 
// char buf[1024] = { 0 };  //����һ���ַ�����
// while( ifs >> buf ){ cout << buf <<endl; }
// �ڶ��֣�
// char buf[1024] = { 0 };
// while(ifs.getline(buf,sizeof(buf))){ cout << buf <<endl; }
// �����֣�
// string buf;
// while(getline(ifs,buf)) { cout << buf << endl; }
// �����֣�//���Ƽ�
// char c;
// while((c = ifs.get()) != EOF ) { cout << c; }
// 5���ر��ļ� ofs.close();
// �������ļ�д���ļ���
// �����ݵ�ʱ����ò�Ҫ��string ���ַ����� ��string����������������
//#include <fstream>
//class Person {
//public:
//	char m_name[64];
//	int m_age;
//};
//void test() {
//	//Person p = { "����",18 };
//	//ofstream ofp;
//	//ofp.open("person.txt", ios::out | ios::binary);
//	//ofp.write((const char*) & p, sizeof(Person));//д������
//	//ofp.close();
//
//	ifstream ifp;
//	ifp.open("person.txt",ios::in | ios::binary );
//	if (!ifp.is_open()) {
//		cout << "�ļ���ʧ��" << endl;
//		return;
//	}
//	Person p;
//	ifp.read((char*) & p, sizeof(Person));
//	cout << "������" << p.m_name << " ���䣺" << p.m_age << endl;
//	ifp.close();
//}



int main() {
	//test();
	system("pause");
	return 0;
}
