#include <iostream>
using namespace std;

//���캯��

//class Person {
//public:
//
//	int m_age;
//
//
//	Person() {
//		cout << "�޲ι��캯������" << endl;
//	}
//	Person(int age) {
//      m_age = age;
//		cout << "�вι��캯���ĵ���" << endl;
//	}
//	Person(const Person& p) {
// 	    m_age = p.m_age;
//		cout << "�������캯������" << endl;
//	}
//
//	~Person() {
//		cout << "������������" << endl;
//	}
//};
//
//void test() {
//	////���ŷ����ù��캯��
//	//Person p1;
//	//Person p2(10);
//	//Person p3(p2);
//
//	////��ʾ������
//	//Person p1;
//	//Person p2 = Person(10);
//	//Person p3 = Person(p2);
//
//	//��ʽ������
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

//������������ʱ��
//1��ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
//
//2��ֵ���ݵķ�ʽ������������ֵ
// ��ʵ���ǰ����Person��һ��ʵ������һ��������������ʱ�򣬲��Ǵ���ַ���������ô���
// �����Ļ����ͻ��ȵ��ÿ������캯�����ȿ����ٴ���ȥ���亯�����޸ĵ�ֵ����ԭ����ֵ��Ӱ��
//
//3��ֵ��ʽ���ؾֲ�����
//��������һ�������ʱ���ڸú����ķ�Χ�ڣ���������ľֲ������ڵ�����֮��ᱻ����
//Ȼ����Ҫ��������ֲ�������ֵ���ͻ��ȿ���һ�ݳ��������ÿ������캯�������ٷ��س�ȥ

//���캯�����ù���
//1�������࣬���������Զ����3�����캯��
//2����д���вΣ������������д�޲Σ������Զ�д�Ͽ������캯������ʱPerson p1;�ͻᱨ��
//3����д�˹��죬��������޲��вζ�����д

//ǳ�������򵥸�ֵ���� ������ظ��ͷ�ָ�������
//������ڶ������������ڴ�ռ䣬���п������� newһ��
//����������ڶ������ٵģ�һ��Ҫ�Լ��ṩ�������캯���������ڶ�������һ���ڴ�

//��ʼ���б�
//�ڹ��캯����д
//class Person {
//
//public:
//
//	////��ͨ��ֵ
//	//Person(int a, int b, int c) {
//	//	m_a = a;
//	//	m_b = b;
//	//	m_c = c;
//	//}
//
//	//��ʼ���б�ֵ
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

//��̬��Ա
//��̬��Ա���������ж�����ͬһ�����ݣ�����׶η����ڴ棬���������������ʼ��
//��̬��Ա���������ַ��ʷ�ʽ��
//1��ͨ��������� Person p;   p.m_a
//2��ͨ���������� Person::m_a 
//��̬��Ա���������ж�����ֻ�ܷ��ʾ�̬��Ա���������ܷ��ʷǾ�̬��Ա����������ʹ��thisָ��
//
//class Person {
//public:
//	static int m_a;//����������̬��Ա����
//};
//int Person::m_a = 10;//�����ʼ����̬��Ա��������Ҫ������

//�ն���ռ���ڴ��СΪ1���ֽ�
//��Ա�����ͳ�Ա�����Ƿֿ��洢�ģ�ֻ�г�Ա�������������ڿռ�

//thisָ��:˭����������ָ��˭
//1����������ͻ��ʱ�򣬿�����thisָ�������� this->
//2�����ض���������ã�������ʽ���� *this
//
//class Person {
//public:
//	int age;
//	Person(int age) {
//		this->age = age;
//	}
//	Person &setAge() {
//		//����ķ��ر�������������
//		//��������������͵Ļ�������������һ����ʱ���󣬰�ֵ�������¶��󣬷��س����Ĳ���ԭ����
//		//������������͵Ļ����򷵻صľ���ԭ����ĵ�ַ��ֱ���޸�ԭ�����ֵ
//		age += 10;
//		return *this; //���ض����������
//	}
//};
//void test() {
//	Person p1(10);
//	p1.setAge().setAge ();
//	cout << "p1����" << p1.age << endl;
//}

//const���γ�Ա����
//����������Ա���������const  void show() const{},�������ڲ����޸ĳ�Ա������ֵ
//        ������mutable���κ����   mutable int m_a;
//������const Person p1;  ������ֻ�ܵ��ó�����

//��Ԫ friend
// 1��ȫ�ֺ�������Ԫ
//ֻҪ������������Ԫ�������ɷ��ʸ�������ԣ�����˽�е�
//class Person {
//	friend void showPerson(Person& p);
//private :
//	int m_age;
//};
//
//void showPerson(Person& p) {
//	cout << "�����ǣ�" << p.m_age << endl;
//}
//2��������Ԫ
//������������ friend class A;
//3����Ա��������Ԫ
//friend void A::show(); 

//��������� operator

//�Ӻ����������
////1����Ա��������+
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
////2��ȫ�ֺ�������+
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
