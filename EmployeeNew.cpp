#include<string>
#include<iostream>
using namespace std; 
int i, n; 
class Employee
{
	string name; 
	int age; 
	int salary;
	string destn; 
	string Emp_Id; 
	static int employeeCount; 
	public : 
		Employee(string n, int a , int s, string des, string id)
		{
			name = n; 
			age = a; 
			salary = s; 
			destn = des; 
			Emp_Id = id; 
			employeeCount++; 			
		}
		~Employee()
		{
			employeeCount--; 
		}
		inline void Accept()
		{
			cout<<"\nEnter Employee Name, age, salary, designation, Emp_ID:";
			cin>>name>>age>>salary>>destn>>Emp_Id;		
		}
		inline void Display()
		{
			cout<<"\nEnter Details :\n Employee Name \t Age \t Salary\t Designation \t Emp_Id"; 
			cout<<"\n"<<name<<"\t"<<age<<"\t"<<salary<<"\t"<<destn<<"\t"<<Emp_Id; 
		}
		friend void search(int Emp_Id)
		{
			cout<<"\nEnter Employee Id for search :"; 
			cin>>Emp_Id; 
			for(i=0;i<n;i++)
			{
				if(strcmp(Emp_Id, E[i].Emp_Id)==0)
				{
					cout<<"\nEmployee Details Are Found :"; 
					cout<<E[i]; 
				}
				else 
				{
					cout<<"\nNot Found"; 
				}
			}
		}
}E[100]; 
int main()
{
	int ch=0; 
	cout<<"\nEnter No. Of Employees :"; 
	cin>>n; 
	do
	{
		cout<<"\n1.Accept\n2.Display\n3.Search\n4.Exit\nEnter Your choice :"; 
		cin>>ch; 
		switch(ch)
		{
			case 1 : 
				for ( int i=0;i<n;i++)
				{
					E[i].Accept(); 
				}
				break; 
			case 2 : 
				for(int i=0;i<n;i++)
				{
					E[i].Display(); 
				}
				break; 
			case 3 : 
				E[i].search(); 
				cout<<"\nEmp Count :"<<E[i].employeeCount; 
				break;
			default :
				cout<<"\nWrong Choice !!!"; 
				break; 
		}
	}while(ch!=0)
	return 0; 
}