#include<iostream>
using namespace std;
//void display();
class A
{
public:
	int *ptr;
	int size;
public:
	A(int size=0):size(size)
	//A()
	{
		ptr= new int[size];
		for(int i=0;i<size;i++)
		{
			ptr[i]=0;
		}
		cout<<"constructor"<<endl;
		/**(this->a)=x;
		b=y;
		cout<<*(this->a)<<"  "<<b<<endl;*/
	}
	~A()
	{
		delete []ptr;
		size=0;
	}

	int getval(int _id)
	{//cout<<"in fgdgdg"<<endl;
		return ptr[_id];
	}
	A(const A &obj)
	{
		cout<<"copy const"<<endl;
		size=obj.size;
		ptr= new int[size];
		for(int i=0;i<size;i++)
		{
			ptr[i]=getval(i);
			cout<<"value"<<ptr[i]<<endl;
		}
	}
	/*A(const A &obj3)
	{cout<<" copy constructor"<<endl;
		a=obj3.a;
		b=obj3.b;
		cout<<a<<"  "<<b<<endl;
	//~A();
	}*/

};



/*int main()
{
	A *obj= new A(5);
	A *obj1= new A(*obj);

	obj->getval(1);
	delete obj;
	obj1->getval(1);
	cout<<"changing an object"<<endl;
		//A *obj1= new A(*obj);

	//A obj1=obj;
	//obj1.a=34;
	//obj1.b='i';
	//obj.a=2;
	//obj.b='m';
	//delete(obj);
	//cout<<obj1.a<<"  "<<obj1.b<<endl;
//	obj.a=65;
	//		obj.b='u';
	//		cout<<obj1.a<<"  "<<obj1.b<<endl;
	//cout<<obj.a<<"  "<<obj.b<<endl;
	//obj.display();

	return 0;
}*/
