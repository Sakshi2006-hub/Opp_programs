#include<iostream>
using namespace std; 
int n; 
class Student 
{
	int rollNo; 
	string prnNo, name; 
	public : 
		void Accept(); 
		void Display(); 
};
class Test : public Student
{
	int s1, s2, s3; 
	public : 
		void AcceptT(); 
		void DisplayT(); 
}; 
void Student :: Accept()
{
	cout<<"---------Enter Student Details-----------"<<endl;
	cout<<"Enter Student Roll No, 	PRN No,  Name :"<<endl; 
	cin>>rollNo>>prnNo>>name; 
}
void Student :: Display()
{
	cout<<"\nRoll No.\tPRN No.\tName"; 
	cout<<"\n"<<"\t"<<rollNo<<"\t"<<prnNo<<"\t"<<name<<endl; 
}
void Test :: AcceptT()
{
	cout<<"-----------Enter Student Marks-----------"<<endl; 
	cout<<"Enter 3 Subject1 Marks, Subject2 Marks, Subject3 Marks:"<<endl; 
	cin>>s1>>s2>>s3; 
}
void Test :: DisplayT()
{
	int Avg,Total;
	Total = s1+s2+s3; 
	Avg= Total/3; 
	cout<<"\nSubject1\tSubject2\tSubject3";
	cout<<"\n"<<"\t"<<s1<<"\t"<<s2<<"\t"<<s3; 
	cout<<"\nAverage Of Marks :"<<Avg; 

}
int main()
{
	Test t; 
	int choice;
	do
	{
		cout<<"\n-----------Menu--------------"; 
		cout<<"\n1.Accept\n2.Display\n3.Accept Marks\n4.Display Average \n5.Exit"; 
		cout<<"\nEnter Your Choice:"; 
		cin>>choice; 
		switch(choice)
		{
			case 1 :cout<<"Enter No. Of Student :"<<endl; 
					cin>>n; 
					for( int i=0;i<n;i++)
					{
						t.Accept();
					}
					break; 
			case 2 : for( int i=0;i<n;i++)
					{
						t.Display();
					}
					break; 
			case 3 : for( int i=0;i<n;i++)
					{
						t.AcceptT();
					}
					break; 
			case 4 : for( int i=0;i<n;i++)
					{
						t.DisplayT();
					} 
					break; 
			case 5 : 
					return 0; 
			default : 
					cout<<"Wrong Choice!!!!!"; 
		}
		
	}while(choice!=5);
	
}