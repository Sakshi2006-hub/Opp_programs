/* . A hospital management system needs to streamline its operations by organizing various types of personnel and services. The system should
manage different roles such as doctors, nurses, and administrative staff. Create the Different classes like Person, Doctor ,Nurse, Administrate
Staff. Use the concept of Inheritance. */

#include<iostream>
using namespace std; 
class Person
{
	public : 
	int Id, salary; 
	string name, design; 
	 
		virtual void Accept()=0; 
		virtual void Display()=0; 
}; 
class Doctor : public Person
{
	public : 
		void Accept()
		{
			cout<<"\nEnter ID Of Doctor :"; 
			cin>>Id; 
			cout<<"\nEnter Name Of Doctor :"; 
			cin>>name; 
			cout<<"\nEnter Designation Of Doctor :"; 
			cin>>design; 
		}
		void Display()
		{
			cout<<"\n------------Doctor Infromation-------------"; 
			cout<<"\n ID \t Name \t Designation"; 
			cout<<"\n"<<Id<<"\t"<<name<<"\t"<<design;  	
		}
}; 
class Nurse : public Person
{
	public : 
		void Accept()
		{
			cout<<"\nEnter ID Of Nurse :"; 
			cin>>Id;
			cout<<"\nEnter Name Of Nurse :"; 
			cin>>name;
			cout<<"\nEnter Salary Of Nurse ;"; 
			cin>>salary; 
		}
		void Display()
		{
			cout<<"\n---------------Nurse Infromation-------------";
			cout<<"\n ID \t Name \t Salary"; 
			cout<<"\n"<<Id<<"\t"<<name<<"\t"<<salary; 
		}
};
class AdStaff : public Person
{
	public :
		void Accept()
		{
			cout<<"\nEnter ID Of Administrator :"; 
			cin>>Id; 
			cout<<"\nEnter Name :"; 
			cin>>name; 
			cout<<"\nEnter Salary Of Administrative Staff :"; 
			cin>>salary; 
			cout<<"\nEnter Designation Of Administrative Staff :";
			cin>>design; 
		}
		void Display()
		{
			cout<<"\n----------------------Admin Info-----------------"; 
			cout<<"\n ID \t Name \t Salary \t Designation"; 
			cout<<"\n"<<Id<<"\t"<<name<<"\t"<<salary<<"\t"<<design; 
		}
};
int main()
{
	Doctor d; 
	Nurse n[10]; 
	AdStaff s[10]; 
	int v,ch; 
	cout<<"\nEnter How Many Details You Want To Enter :"; 
	cin>>v; 
	do
	{
		cout<<"\n------------------------Menu--------------------------"; 
		cout<<"\n1.Accept Doctor Details \n2.Display Doctor Details ";
		cout<<"\n3.Accept Nurse Details \n4.Display Nurse Details ";
		cout<<"\n5.Accept Admin Details \n6.Display Admin Details \n7.Exit";
		cout<<"\nEnter Your Choice :"; 
		cin>>ch; 
		switch(ch)
		{
			case 1 :
					d.Accept(); 
					break; 
			case 2 :
				d.Display(); 
					break;  
			case 3 : 
				for (int i=0;i<v;i++)
				{
					n[i].Accept(); 
				}
				break;
			case 4 : 
				for (int i=0;i<v;i++)
				{
					n[i].Display(); 
				}
				break;
			case 5 : 
				for (int i=0;i<v;i++)
				{
					s[i].Accept(); 
				}
				break;
			case 6 : 
				for (int i=0;i<v;i++)
				{
					s[i].Display(); 
				}
				break;
			case 7 :
				cout<<"\n----------------Thanks-----------------"; 
				return 0; 
			default :
				cout<<"\n!!!!!!!!Wrong Choice!!!!!!!!"; 
		}

	}while(ch!=7); 
	return 0; 
}