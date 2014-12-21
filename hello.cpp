#include <pthread.h>
#include <iostream>
#include <stdlib.h>
#include <assert.h>
//#include<thread>
#define NUM =5;
using namespace std;

//static const int num =5;
/*void call(int a)
{
	cout<<"helloworld"<<""<<a<<endl;
}

int main()
{
	std::thread t[num];
	for (int i=0; i<num; i++)
	{
		t[i]=std::thread(call, i);
	}
	for (int i=0; i<num; i++)
	{
		t[i].join();
	}
	//std::thread t1(call);
	//t1.join();
	return 0;
}*/


//pthread_mutex_t
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter=0;
void * fun(void * x)
{
	//int *x;
	//x=(int*)b;
	//cout<<"thread number %d"<<pthread_self();//<<endl;
	printf("Thread number %ld\n", pthread_self());

	pthread_mutex_lock (&mutex1);
	counter++;
	cout<<"program   "<<counter<<endl;
	pthread_mutex_unlock(&mutex1);
	pthread_exit(NULL);

}
/*int main()
{

	/int a,b;
	//int c=1;
	//in//t d=5;
	pthread_t t1[5];//,t2;
	int i,j;
	cout<<"Hello Thread"<<endl;

	for(i=0; i<5; i++)
	{
		pthread_create(&t1[i], NULL, fun, NULL);
	}
	//cout<<"value of a:  "<<a<<endl;
	//b=pthread_create(&t2, NULL, fun,NULL);
	//cout<<" value of b:  "<<b<<endl;
	for(j=0; j<5; j++)
	{
		pthread_join(t1[j],0);
	}
	//pthread_join (t2, 0);

	//cout<<"1223232323"<<endl;
    //fun((void*)&d);
    return 0;
}*/




