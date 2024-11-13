/* Create a c++ class named Television that has data member to hold the Model No. and the Screen size in Inches and the price. 
	Member function include overloaded insertion and extraction operator. If more than 4 digits are entered for the Model, If the Screen
	size is smaller than 12 or greater than 70 inches, prize is in -ve or over 5000 Dollers then throw an integer. Write 
	a main function that instanciate a Television object, allow user to enter data and display the data member values.
	If an exception is caught replace all data member value with 0 value. */
	
#include<iostream>
using namespace std; 
class Television 
{
	int ModelNo, ScreenSize, Prize; 
	public : 						/*class name istream and reference Object & */
		friend istream & operator >> ( istream &, Television &); 
		friend ostream & operator << ( ostream &, Television &); 
		
}; 
istream & operator >> (istream &din, Television &t)
{
	int e; 
	cout<<"Enter Model No. Of TV : "; 
	din>>t.ModelNo;
	cout<<"\nEnter Screen Size Of TV :"; 
	din>>t.ScreenSize; 
	cout<<"\nEnter Prize Of TV :"; 
	din>>t.Prize;
	
	try
	{
		if( t.ModelNo > 9999 || t.ScreenSize < 12 || t.ScreenSize >70 || t.Prize < 0 || t.Prize > 5000)
		{
			throw e; 
		}
	}
	catch( int e )
	{
		cout<<"\nException Caught!!!"; 
		t.ModelNo = 0; 
		t.ScreenSize = 0; 
		t.Prize = 0; 
	}
	return din; 
}
ostream &  operator << (ostream &dout, Television &t)
{
	dout<<t.ModelNo; 
	dout<<t.ScreenSize; 
	dout<<t.Prize; 
	return dout; 
}
int main()
{
	Television tv; 
	int ch; 
	do
	{
		cout<<"\n------------------Menu-------------------"; 
		cout<<"\n1.Accept \n2.Display \n3.Exit"; 
		cout<<"\nEnter Your Choice :"; 
		cin>>ch; 
		switch(ch)
		{
			case 1 : 
				cin>>tv; 
				break; 
			case 2 :
				cout<<tv; 
				break; 
			case 3 : 
				return 0; 
				break; 
			default : 
				cout<<"\n !!!!! Wrong Choice !!!!!"; 
				break; 
		}
	}while(ch!=3); 
	return 0; 
}