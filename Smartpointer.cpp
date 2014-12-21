#include<iostream>
#include<memory>
//#include<vector>
using namespace std;
//void display();
class A
{
public:
	int a;
	int b;
	A(int x=3, int y=2):a(x),b(y)
	{
		a=x;
		b=y;
	}
	~A()
	{
		//delete []obj;
		//if(A)
		{
		//	A= NULL;
		}
	}
	void display()
	{
		cout<<a<<"   "<<b<<endl;
	}
};

/*int main()
{
	//A *obj = new A();//(10,20);
	std::shared_ptr<A> obj(new A());
	//unique_ptr<A> obj(new A());
	obj->display();
	//shared_ptr<A> obj1 = obj;//(new A());

	weak_ptr<A> obj2 = obj;//(new A());
	//obj2->display();
	shared_ptr<A> obj1 = obj;//(new A());

	return 0;


}*/
