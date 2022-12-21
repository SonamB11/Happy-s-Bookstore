#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class book	{
private:
	char *author,*title,*publisher;
	float *price;
	int *stock;
public:
	book()	{
	author= new char[20];
	title=new char[20];
	publisher=new char[20];
	price= new float;
	stock=new int;
	}
	void feeddata();
	void editdata();
	void showdata();
	int search(char[],char[]);

};

void book::feeddata()	{
	cin.ignore();
	cout<<"\nEnter Author Name: ";      cin.getline(author,20);
	cout<<"Enter Title Name: ";       cin.getline(title,20);
	cout<<"Enter Publisher Name: ";   cin.getline(publisher,20);
	cout<<"Enter Price: ";            cin>>*price;
	cout<<"Enter Stock Position: ";   cin>>*stock;

}

void book::editdata()	{

	cout<<"\nEnter Author Name: ";      cin.getline(author,20);
	cout<<"Enter Title Name: ";       cin.getline(title,20);
	cout<<"Enter Publisher Name: ";   cin.getline(publisher,20);
	cout<<"Enter Price: ";            cin>>*price;
	cout<<"Enter Stock Position: ";   cin>>*stock;

}

void book::showdata()	{
	cout<<"\nAuthor Name: "<<author;
	cout<<"\nTitle Name: "<<title;
	cout<<"\nPublisher Name: "<<publisher;
	cout<<"\nPrice: "<<*price;
	cout<<"\nStock Position: "<<*stock;

}

int book::search(char tbuy[20],char abuy[20] )	{
	if(strcmp(tbuy,title)==0 && strcmp(abuy,author)==0)
		return 1;
	else return 0;

}

class magazine	{
private:
	char *year,*magtitle,*edition;
	float *price;
	int *stock;
public:
	magazine()	{
	year=new char[20];
	magtitle=new char[20];
	edition=new char[20];
	price= new float;
	stock=new int;
	}
	void feeddata2();
	void editdata2();
	void showdata2();
	int search2(char[],char[]);

};

void magazine::feeddata2()	{
	cin.ignore();
	cout<<"\nEnter Year of publication: ";      cin.getline(year,20);
	cout<<"Enter Title Name: ";       cin.getline(magtitle,20);
	cout<<"Enter Edition: ";   cin.getline(edition,20);
	cout<<"Enter Price: ";            cin>>*price;
	cout<<"Enter Stock Position: ";   cin>>*stock;

}

void magazine::editdata2()	{

	cout<<"\nEnter Year of publication: ";      cin.getline(year,20);
	cout<<"Enter Title Name: ";       cin.getline(magtitle,20);
	cout<<"Enter Edition: ";   cin.getline(edition,20);
	cout<<"Enter Price: ";            cin>>*price;
	cout<<"Enter Stock Position: ";   cin>>*stock;

}

void magazine::showdata2()	{
	cout<<"\nYear: "<<year;
	cout<<"\nTitle Name: "<<magtitle;
	cout<<"\nEdition: "<<edition;
	cout<<"\nPrice: "<<*price;
	cout<<"\nStock Position: "<<*stock;

}

int magazine::search2(char mtitle[20],char yr[20] )	{
	if(strcmp(mtitle,magtitle)==0 && strcmp(yr,year)==0)
		return 1;
	else return 0;

}

class customer	{
private:
	char *cust,*custid;
	int *contact,*billpend;
public:
	customer()	{
	cust= new char[20];
	custid= new char[20];
	contact=new int;
	billpend=new int;
	}
	void custdata();
	void editcust();
	void showcust();
	int searchcust(char[],char[]);

};

void customer::custdata()	{
	cin.ignore();
	cout<<"\nEnter Customer Name: ";      cin.getline(cust,20);
	cout<<"Enter Customer ID: ";   cin.getline(custid,20);;
	cout<<"Enter Contact: ";            cin>>*contact;
	cout<<"Enter Bill pending: ";   cin>>*billpend;

}

void customer::editcust()	{

	cout<<"\nEnter Customer Name: ";      cin.getline(cust,20);
	cout<<"Enter Customer ID: ";   cin.getline(custid,20);
	cout<<"Enter Contact: ";            cin>>*contact;
	cout<<"Enter Bill pending: ";   cin>>*billpend;

}

void customer::showcust()	{
	cout<<"\nCustomer Name: "<<cust;
	cout<<"\nCustomer ID: "<<custid;
	cout<<"\nContact: "<<*contact;
	cout<<"\nBill Pending: "<<*billpend;

}

int customer::searchcust(char c[20],char id[20] )	{
	if(strcmp(c,cust)==0 && strcmp(id,custid)==0)
		return 1;
	else return 0;

}

class worker{
    
    public:
    char *workername;
    int *workerid,*workhrs;
    worker(){
          workername=new char[20];
          workerid=new int;
          workhrs=new int;
    }
    void addworker(){
        cout<<"\nEnter Worker Name: ";   cin.getline(workername,20);;
	  cout<<"Enter Worker ID: ";       cin>>*workerid;
	  cout<<"Enter Working Hours: ";   cin>>*workhrs;


    }
    void workerdetail(){
        cout<<"\nWorker Name:"<<workername;
        cout<<"\nWorker ID"<<*workerid;
        cout<<"\nWorking Hours"<<*workhrs;
    }
};
class storemanager: public worker{
  
};
class cashier: public worker{

};

int main()	{
	book *B[20];
	magazine *M[20];
	customer *CUST[20];
	int i=0,r,t,choice;
	char titlebuy[20],authorbuy[20],magtitle[20],magyear[20],c[20],cid[20];
	while(1)	{
		cout<<"\n\n======Book Shop Management System======"
		<<"\n1. Entry of New Book"
		<<"\n2. Search For Book"
		<<"\n3. Edit Details Of Book"
		<<"\n4. Entry of New Magazine"
		<<"\n5. Search For Magazine"
		<<"\n6. Edit Details Of Magazine"
		<<"\n7. Entry of New Customer"
		<<"\n8. Search For Customer"
		<<"\n9. Edit Details Of Customer"
		<<"\n10. Exit"
		<<"\n\nEnter your Choice: ";
		cin>>choice;

		switch(choice)	{
			case 1:	B[i] = new book;
				B[i]->feeddata();
				i++;	break;

			case 2: cin.ignore();
				cout<<"\nEnter Title Of Book: "; cin.getline(titlebuy,20);
				cout<<"Enter Author Of Book: ";  cin.getline(authorbuy,20);

				for(t=0;t<i;t++)	{
					if(B[t]->search(titlebuy,authorbuy))	{
						cout<<"\nBook Found Successfully";
						B[t]->showdata();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis Book is Not in Stock";
				break;

			case 3: cin.ignore();
				cout<<"\nEnter Title Of Book: "; cin.getline(titlebuy,20);
				cout<<"Enter Author Of Book: ";  cin.getline(authorbuy,20);

				for(t=0;t<i;t++)	{
					if(B[t]->search(titlebuy,authorbuy))	{
						cout<<"\nBook Found Successfully";
						B[t]->editdata();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis Book is Not in Stock";
				break;
            case 4:	M[i] = new magazine;
				M[i]->feeddata2();
				i++;	break;

			case 5: cin.ignore();
				cout<<"\nEnter Title Of Magazine: "; cin.getline(magtitle,20);
				cout<<"Enter Year of Magazine: ";  cin.getline(magyear,20);

				for(t=0;t<i;t++)	{
					if(M[t]->search2(magtitle,magyear))	{
						cout<<"\nMagazine Found Successfully";
						M[t]->showdata2();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis Magazine is Not in Stock";
				break;

			case 6: cin.ignore();
				cout<<"\nEnter Title Of Magazine: "; cin.getline(magtitle,20);
				cout<<"Enter Year of Magazine: ";  cin.getline(magyear,20);

				for(t=0;t<i;t++)	{
					if(M[t]->search2(magtitle,magyear))	{
						cout<<"\nMagazine Found Successfully";
						M[t]->editdata2();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis Magazine is Not in Stock";
				break;
			case 7:	CUST[i] = new customer;
				CUST[i]->custdata();
				i++;	break;
			case 8:cin.ignore();
				cout<<"\nEnter Customer ID : "; cin.getline(cid,20);
				cout<<"Enter Customer: ";  cin.getline(c,20);

				for(t=0;t<i;t++)	{
					if(CUST[t]->searchcust(c,cid))	{
						cout<<"\nCustomer Found Successfully";
						CUST[t]->showcust();
						break;
					}
				}
				if(t==i)
				cout<<"\nCustomer Not Found";
				break;
			case 9:cin.ignore();
			cout<<"\nEnter Customer ID : "; cin.getline(cid,20);
				cout<<"Enter Customer: ";  cin.getline(c,20);

				for(t=0;t<i;t++)	{
					if(CUST[t]->searchcust(c,cid))	{
						cout<<"\nMagazine Found Successfully";
						CUST[t]->editcust();
						break;
					}
				}
				if(t==i)
				cout<<"\nInvalid Customer";
				break;
			case 10: exit(0);
			default: cout<<"\nInvalid Choice Entered";

		}
	}




	return 0;
}