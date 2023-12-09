#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<iomanip.h>
#include<process.h>
#include<time.h>
#include<graphics.h>
	


//structures
struct Bill
{int id;
 char Category[20],Name[100];
 long Qty;
 float total;
}K;

struct Album
{char Name[100],Category[20],Type[10],Artist[100];
 float price; int id;
 long Qty; }E,A;

struct Instrument
{char Name[50],Category[20];
 float price;
 long Qty;  int id;
 }B,C;

struct Employee
 {int i;
  char pas[9];}Q;

//global declarations
int d,f;
Bill Y[40];
int i,r;
char a;
fstream f1("Bill.dat",ios::binary|ios::app);

//subfunction to place order for an album
void Alb()
{ fstream f("Album.dat",ios::binary|ios::in|ios::out);
    cout<<"\nEnter item id: ";
  cin>>Y[i].id;int q=0;
    while(!f.eof())
   {f.read((char*)&E,sizeof(E));
    if(f.eof())break;
    if(Y[i].id==E.id){q++;break;}}
    if(!q){cout<<"Inavlid id";getch();return;}
    else {F1:
	cout<<"Enter No. of units: ";
	cin>>r; char a;
	while(E.Qty-r<0)
	{cout<<"Not Enough stock,the available no. of units is ";
	if(E.Qty==0)cout<<"Nil";
	else cout<<E.Qty;getch();
	cout<<"\nDo you want to continue billing for the same product(y) or skip to the next product(Press any key)?";
	cin>>a;
	if(a=='Y'||a=='y')goto F1;
	else return;}
	long n;
	strcpy(Y[i].Name,E.Name);
	strcpy(Y[i].Category,E.Category);
	Y[i].Qty=r;
	E.Qty-=r;
	n=sizeof(E);
	f.seekp(-n,ios::cur);
	f.write((char*)&E,sizeof(E));
	Y[i].total=r*E.price;
	f1.write((char*)&Y[i],sizeof(Y[i]));}f.close();
	i++; }

//subfunction to place an order for an instrument
void Inst()
  {fstream f("Instru.dat",ios::binary|ios::in|ios::out);
   int q=0;
   cout<<"\nEnter item id: ";
  cin>>Y[i].id;
    while(!f.eof())
   {f.read((char*)&B,sizeof(B));
    if(f.eof())break;
    if(Y[i].id==B.id){q++;break;}}
    if(!q){cout<<"Invalid id";getch();return;}
  else {F2:
	cout<<"Enter No. of units: ";
	cin>>r;
	char a;
	while(B.Qty-r<0)
	{cout<<"Not Enough stock,the available no. of units is ";
	if(B.Qty==0)cout<<"Nil";
	else cout<<B.Qty;getch();
	cout<<"\nDo you want to continue billing for the same product(y) or skip to the next product(Press any key)?";
	cin>>a;
	if(a=='Y'||a=='y')goto F2;
	else return;}
	long n;
	strcpy(Y[i].Name,B.Name);
	strcpy(Y[i].Category,B.Category);
	Y[i].Qty=r;
	Y[i].total=r*B.price;
	B.Qty-=r;
	n=sizeof(B);
	f.seekp(-n,ios::cur);
	f.write((char*)&B,sizeof(B));
	f1.write((char*)&Y[i],sizeof(Y[i]));}f.close();
	i++;}



//subfunction to assign unique id to albums on addition
void Next1()
{fstream f("Album.dat",ios::binary|ios::in);
 long n=sizeof(E);
 f.seekp(-n,ios::end);
 f.read((char*)&E,n);
 d=E.id;}

//subfunction to assign unique id to instruments on addition
void Next2()
{fstream f1("Instru.dat",ios::binary|ios::in);
 long n=sizeof(B);
 f1.seekp(-n,ios::end);
 f1.read((char*)&B,n);
 f=B.id;}

//subfunction for comparing strings
int Subcheck(char A[],char temp[])
{ int n=strlen(temp);
  int flag=0;
  strlwr(A);
  strlwr(temp);
  for(int j=0;A[j];j++)
  { if(A[j]==temp[0])
	      {char k[20];
	       int m=0;
	       for(int l=j;l<j+n;l++,m++)
	       {k[m]=A[l];}
		k[m]='\0';
		if(strcmpi(temp,k)==0){flag=1;break;}}
     }
    if(flag)return 1;
    else return 0;
 }


//subfunction to generate login page
int Pass()
{  int c=0;
   while(1)
   {p1:
   fstream f;
   f.open("Emp.dat",ios::binary|ios::in);
   clrscr();cout<<"\t\t\tEMPLOYEE LOGIN\n";
   int z;char pass[20]; char m,o;
   cout<<"Enter employee id(4 digit no.): ";
   cin>>z;int l=0;int e=0;char ch;
   cout<<"Enter password: ";
   while(e!=9)
   {ch=getch();
   if(ch=='\r')break;
      else if(ch=='\b')cout<<"\b \b";
   else{cout<<"*";
	pass[e]=ch;
	e++;}}
	pass[e]='\0';
	     while(!f.eof())
	     {f.read((char*)&Q,sizeof(Q));
	      if(f.eof()) break;
	      if(z==Q.i){l++;
			 if(strcmpi(pass,Q.pas)==0){cout<<"\nAccess granted\nPress any key to continue";getch();return 1;}
			 else cout<<"\nInvalid password";c++;if(c==5){cout<<"\n5 attempts over";return 0;}

			 cout<<"\nReattempt(A) or Exit(Any key)";cin>>o;
			 if(o=='A'||o=='a')goto p1;
			 else return 0;}
	    }
	    if(!l){cout<<"\nInvalid ID";c++;if(c==5){cout<<"\n5 attempts over";return 0;}
		   cout<<"\nReattempt(A) or Exit(Any key)";
		       cin>>m;
		       if(m=='A'||m=='a')goto p1;
		       else return 0;} } }




//subfunction to generate welcome page
void Disp()
{int gdriver=DETECT,gmode,i=4;
 initgraph(&gdriver,&gmode,"c:\\Turboc3\\BGI");
 setcolor(RED);
 setbkcolor(LIGHTBLUE);
 settextstyle(GOTHIC_FONT,HORIZ_DIR,i);
 int midx = getmaxx() / 2;
 int midy = getmaxy() / 2;
 settextjustify(CENTER_TEXT, CENTER_TEXT);
 outtextxy(midx,midy,"WELCOME TO BISTRO MUSICALS");
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,i);
 outtextxy(300,300,"Developed by J.PREETHAA");
 getch();
 closegraph();
 }

//function to manipulate employee related details
void Emp()
{clrscr();char y;char A[9];
 do{clrscr();
    cout<<"MENU\n1.Add detail\n2.View details\n3.Remove details\n4.Edit details\n5.Exit\nEnter your choice";
    cin>>y;
    if(y=='1'){ fstream f3("Emp.dat",ios::binary|ios::in);
		p:
		int a;
		cout<<"\nEnter id(4 digits)";cin>>a;int q=0;
		while(!f3.eof())
		{f3.read((char*)&Q,sizeof(Q));
		 if(Q.i==a){q++;cout<<"ID Already exists";goto p;}}
		   if(!q){ fstream f3("Emp.dat",ios::binary|ios::app);
			   cout<<"Enter password(max. 8 characters) ";
			   gets(A);
			   strcpy(Q.pas,A);
			   Q.i=a;
			   f3.write((char*)&Q,sizeof(Q));}
			   f3.close();}
    else if(y=='2'){clrscr();
		    cout<<"\t\t\t\tEMPLOYEE DETAILS";
		    cout<<"\n\t\t\t\t"<<setw(5)<<"ID"<<setw(10)<<"Password";
		    fstream f("Emp.dat",ios::binary|ios::in);
		    while(!f.eof())
		    {f.read((char*)&Q,sizeof(Q));
		     if(f.eof())break;
		     cout<<endl<<"\t\t\t\t"<<setw(4)<<Q.i<<setw(10)<<Q.pas;}
		     getch();f.close();}
    else if(y=='3'){fstream f("Emp.dat",ios::binary|ios::in);
		    fstream f1("Temp.dat",ios::binary|ios::out);
		    cout<<"Enter the ID of the employee detail to be deleted";
		    int q; cin>>q;int i=0;
		    while(!f.eof())
		    {f.read((char*)&Q,sizeof(Q)); if(f.eof())break;
		     if(Q.i!=q)f1.write((char*)&Q,sizeof(Q));
		     else i++;}
		    if(!i){cout<<"So such record found";getch();}
		    else {cout<<"Record removed";getch();}f1.close();f.close();
		    remove("Emp.dat");
		    rename("Temp.dat","Emp.dat");}
    else if(y=='4'){fstream f("Emp.dat",ios::binary|ios::out|ios::in);
		    cout<<"Enter the Id of the detail to be edited";int q,i=0;
		    cin>>q;
		    while(!f.eof())
		    {f.read((char*)&Q,sizeof(Q));
		     if(f.eof())break;
		     if(Q.i==q){i++;char p[9];
				cout<<"Enter the new password(8 chars only): ";
				cin>>p;
				strcpy(Q.pas,p);long n=sizeof(Q);
				f.seekp(-n,ios::cur);
				f.write((char*)&Q,sizeof(Q));
				break;}
		     }if(!i)cout<<"Inavlid id";
		     f.close();
		 }
    else if(y=='5'){cout<<"Press any key to exit";getch();break;}
    else{cout<<"Invalid option";getch();}
    }while(y!='5');
 }


//function to display the available albums and instruments
void Show()
{clrscr();char a;
 fstream f;
 do{clrscr();
    cout<<"\nMENU\n1.Album\n2.Instrument\n3.Exit\nEnter your choice";
    cin>>a;
 if(a=='1')
	   {f.open("Album.dat",ios::binary|ios::in);
	    cout<<setw(2)<<"\nID"<<setw(15)<<"Album"<<setw(15)<<"Category"<<setw(10)<<"Type"<<setw(15)<<"Artist"<<setw(7)<<"Qty"<<setw(12)<<"Unit Price";
		       while(!f.eof())
		       {f.read((char*)&E,sizeof(E));
		       if(f.eof())break;
		       cout<<endl<<setw(2)<<E.id<<setw(15)<<E.Name<<setw(15)<<E.Category<<setw(10)<<E.Type<<setw(15)<<E.Artist<<setw(6)<<E.Qty<<setw(7)<<E.price;
		       } getch();f.close();}
 else if(a=='2')
	    {f.open("Instru.dat",ios::binary|ios::in);
	     cout<<endl<<setw(2)<<"ID"<<setw(12)<<"Instrument"<<setw(14)<<"Category"<<setw(7)<<"Qty"<<setw(12)<<"Unit Price";
			 while(!f.eof())
			 {f.read((char*)&B,sizeof(B));
			 if(f.eof())break;
			  cout<<endl<<setw(2)<<B.id<<setw(10)<<B.Name<<setw(16)<<B.Category<<setw(6)<<B.Qty<<setw(10)<<B.price;
			 } getch();f.close();  }
  else if(a=='3')
	     {cout<<"Press any key";getch();return;}
    else
	{cout<<"Invalid choice";getch();}
  }while(a!='3');

 }

//function to place an order
void OrderBill()
{clrscr();
 char n;char x;

 cout<<"Press 1 to view album list/instrument list\nPress 2 to continue billing\nAny other key retuens to MENU: ";
 cin>>n;
 if(n=='1'){cout<<"Note the ID of the item required"<<endl;getch();
	   Show();
	   cout<<"\nPress any key to proceed to billing";getch();
	   goto FN2;}
 else if(n=='2'){ goto FN2;}
 else return;

 FN2:
 clrscr();
  char k='C';
 FN5:
 while(k=='C'||k=='c'||k=='k'||k=='K')
		{if(k=='K'||k=='k'){Show();clrscr();}
		 cout<<"Album(A)/Instrument(I): ";cin>>a;
		 if(a=='A'||a=='a')Alb();
		 else if(a=='I'||a=='i')Inst();
		 else{cout<<"Invalid option";goto FN5;}

     cout<<"\nPress \'c\'to continue,\npress\'k\' to view the item list,\nany other key stops the billing process,Enter choice: ";cin>>k;}
    clrscr();
    cout<<"\t\t\t   BISTRO MUSICALS"<<endl;
    time_t t;
    time(&t);
    printf("Date and time: %s\n", ctime(&t));
    if(i==0){cout<<"No items purchased";getch();}
   else{ cout<<"\t\t\t\tBILL\n";float m=0;
     cout<<endl<<setw(4)<<"Sno."<<setw(25)<<"Name of the product"<<setw(15)<<"No of units"<<setw(10)<<"Total"<<endl;
  for(int b=0;b<i;b++)
  {cout<<setw(2)<<b+1<<setw(25)<<Y[b].Name<<setw(10)<<Y[b].Qty<<setw(17)<<Y[b].total<<endl;
   m+=Y[b].total;}
  cout<<"Net amount to be paid: Rs."<<m;getch();

  cout<<endl<<"Happy shopping! Come back for great offers!";getch();f1.close();}
  return;
  }


//function to remove albums and instruments
void RI()
{clrscr();
 char a;int r;
 do{clrscr();
    cout<<"MENU\n1.Album\n2.Instrument\n3.Exit\nEnter your choice";
 cin>>a;
 fstream f1("Temp.dat",ios::binary|ios::out);
 if(a=='1')
   {fstream f("Album.dat",ios::binary|ios::in);int i=0;
    cout<<"Enter id of the item to be removed: ";
    cin>>r;
    while(!f.eof())
    {f.read((char*)&E,sizeof(E));
     if(f.eof())break;
     if(E.id==r)i++;
     else f1.write((char*)&E,sizeof(E));}
     if(!i){cout<<"No such record found";     getch();}
     else{ cout<<"Record removed";getch();}
     f.close();f1.close();
     remove("Album.dat");
     rename("Temp.dat","Album.dat");
    }
   else if(a=='2')
      {fstream f("Instru.dat",ios::binary|ios::in);int i=0;
       cout<<"Enter id of the item to be removed: ";
       cin>>r;
       while(!f.eof())
       {f.read((char*)&B,sizeof(B));
       if(f.eof())break;
       if(E.id==r)i++;
       else f1.write((char*)&B,sizeof(B));}
       if(!i){cout<<"No such record found";getch();}
       else{ cout<<"Record removed";getch();}
       remove("Album.dat");
       rename("Temp.dat","Album.dat");f.close();f.close();
    }
    else if(a=='3'){cout<<"Press any key to return to main menu";getch();return;}
    else {cout<<"Inavlid option";getch();}}
    while(a!='3');
    return;
  }

//function to edit details of the available items
void EI()
{clrscr();
 char a;int r;char A[8];
 do{cout<<"MENU\n1.Album\n2.Instrument\n3.Exit\nEnter your choice: ";cin>>a;
 if(a=='1'){  cout<<"Enter id: ";cin>>r;int i=0;
		      fstream f("Album.dat",ios::binary|ios::in|ios::out);
		      while(!f.eof())
		      {f.read((char*)&E,sizeof(E));
		      if(f.eof())break;
		    if(E.id==r){i++;cout<<"1.Name\n2.Category\n3.Tpye\n4.Artist\n5.Units\n6.Price\n7.Exit\nEnter the fields to be changed:" ;gets(A);
				 for(int k=0;A[k];k++)
				 switch(A[k])
				{case '1': cout<<"\nEnter Album Name: ";gets(E.Name);break;
				case '2': cout<<"\nEnter Category: ";gets(E.Category);break;
				case '3': cout<<"\nEnter Type: ";gets(E.Type);break;
				case '4': cout<<"\nEnter Artist: ";gets(E.Artist);break;
				case '5': cout<<"\nUnits: ";cin>>E.Qty;break;
				case '6':cout<<"\nPrice of one unit: ";cin>>E.price;break;
				case '7':break;}
				long n=sizeof(E);
				f.seekp(-n,ios::cur);
				f.write((char*)&E,sizeof(E));}}
		       if(!i)cout<<"Invalid ID";f.close();}
   else if(a=='2'){cout<<"Enter id: ";cin>>r;int i=0;
		      fstream f("Instru.dat",ios::binary|ios::in|ios::out);
		      while(!f.eof())
		      {f.read((char*)&B,sizeof(B));
		      if(f.eof())break;
		    if(B.id==r){i++;cout<<"1.Name\n2.Category\n3.Units\n4.Price\n5.Exit\nEnter the fields to be changed:" ;gets(A);
				 for(int k=0;A[k];k++)
				 switch(A[k])
				{case '1': cout<<"\nEnter Instrument Name: ";gets(B.Name);break;
				case '2': cout<<"\nEnter Category: ";gets(B.Category);break;
				case '3':  cout<<"\nUnits: ";cin>>B.Qty;break;
				case '4':cout<<"\nPrice of one unit: ";cin>>B.price;break;
				case'5':break;}
				long n=sizeof(B);
				f.seekp(-n,ios::cur);
				f.write((char*)&B,sizeof(B));}}
		       if(!i)cout<<"Invalid ID"; f.close();}

     else if(a=='3'){cout<<"Press any key to return to main menu";getch();}
     else {cout<<"Invalid option";getch();}}
     while(a!='3');
     return;
   }


//function to add a new detail
void AddNi()
{clrscr();
 Next1();Next2();
 char a;
 do{  clrscr();
      cout<<"MENU\n1.Album\n2.Instrument\n3.Exit\nEnter your choice: ";cin>>a;
      if(a=='1') {clrscr();
		     E.id=++d;
		     cout<<"Enter Album Name: ";gets(E.Name);
		     cout<<"Enter Category: ";gets(E.Category);
		     cout<<"Enter Type: ";gets(E.Type);
		     cout<<"Enter Artist: ";gets(E.Artist);
		     cout<<"Units: ";cin>>E.Qty;
		     cout<<"Price of one unit: ";cin>>E.price;
		     fstream f("Album.dat",ios::binary|ios::app);
		     f.write((char*)&E,sizeof(E));
		     f.close();
		    }
  else if(a=='2')        {clrscr();
			  B.id=++f;
			  cout<<"Enter Instrument: ";gets(B.Name);
			  cout<<"Enter Category: ";gets(B.Category);
			  cout<<"Units: ";cin>>B.Qty;
			  cout<<"Price of one unit: ";cin>>B.price;
			  fstream f("Instru.dat",ios::binary|ios::app);
			  f.write((char*)&B,sizeof(B));
			  f.close();
		    }
  else if(a=='3'){cout<<"Press any key to go to menu";getch();return;}
  else {cout<<"Invalid entry";getch(); }}
  while(a!=3);  return;
}


//function to display album in stock
void AinSto()
{clrscr();
 cout<<"Albums in Stock: "<<endl;
 fstream f("Album.dat",ios::binary|ios::in);
 cout<<setw(2)<<"\nID"<<setw(15)<<"Album"<<setw(15)<<"Category"<<setw(10)<<"Type"<<setw(15)<<"Artist"<<setw(7)<<"Qty"<<setw(12)<<"Unit Price";
  while(!f.eof())
  {f.read((char*)&E,sizeof(E));
   if(f.eof())break;
   if(E.Qty>0)cout<<endl<<setw(2)<<E.id<<setw(15)<<E.Name<<setw(15)<<E.Category<<setw(10)<<E.Type<<setw(15)<<E.Artist<<setw(6)<<E.Qty<<setw(7)<<E.price;
	      }getch();f.close();return;}

//function to display Instruments in stock
void IinSto()
 {clrscr();
  cout<<"Instruments in Stock: "<<endl;
 fstream f2("Instru.dat",ios::binary|ios::in);
  cout<<endl<<setw(2)<<"ID"<<setw(12)<<"Instrument"<<setw(14)<<"Category"<<setw(7)<<"Qty"<<setw(12)<<"Unit Price";
  while(!f2.eof())
  {f2.read((char*)&B,sizeof(B));
   if(f2.eof())break;
   if(B.Qty>0)cout<<endl<<setw(2)<<B.id<<setw(10)<<B.Name<<setw(16)<<B.Category<<setw(6)<<B.Qty<<setw(10)<<B.price;
    }getch();f2.close();return;
}


//function to display all the sold items up to date
void SoldItems()
{clrscr();cout<<"\t\t\t     SOLD ITEMS";
 fstream f("Bill.dat",ios::binary|ios::in);
 float m=0;
     while(!f.eof())
 {f.read((char*)&K,sizeof(K));
  if(f.eof())break;
  cout<<endl<<"\nId: "<<K.id<<"\nName: "<<K.Name<<"\nCategory: "<<K.Category<<"\nNo. of units sold: "<<K.Qty;getch();
  m+=K.total;
  }cout<<"\nTotal amount collected so far:"<<m;getch();
  f.close();return;
}


//function to search for an instrument
void Instru()
{clrscr();
 char A[20];int i=0;char w;
do {clrscr();
    cout<<"\nMENU\n1.Search\n2.Exit\nEnter your choice: ";
    cin>>w;
 if(w=='1'){cout<<"Enter category";
 gets(A);
 fstream f("Instru.dat",ios::binary|ios::in);
 while(!f.eof())
 {f.read((char*)&B,sizeof(B));
  if(f.eof())break;
  if(Subcheck(B.Category,A)!=0){if(i==0){cout<<endl<<setw(2)<<"ID"<<setw(12)<<"Instrument"<<setw(14)<<"Category"<<setw(7)<<"Qty"<<setw(12)<<"Unit Price";}
			       cout<<endl<<setw(2)<<B.id<<setw(10)<<B.Name<<setw(16)<<B.Category<<setw(6)<<B.Qty<<setw(10)<<B.price;
			       i++;
			       }
  }getch();if(!i)cout<<"Unsuccessful search";getch();f.close();}
  else if(w=='2'){cout<<"Press any key to return to main menu";
		  getch(); }
  else{ cout<<"Invalid option";getch();}
  }while(w!='2');

  return;
 }


//function to search for an album
void FindMusic()
{clrscr();
 int n;char A[100];
 do{clrscr();
 cout<<"Enter on what basis should the album be searched for"<<endl;
 cout<<endl<<"1.Album name\n2.Category\n3.Type\n4.Artist\n5.Exit"<<endl<<"Enter your choice";
 cin>>n;
 switch (n)
  {case 1:{cout<<"Enter name: ";gets(A);
	  int i=0;
	  fstream f("Album.dat",ios::binary|ios::in);
	  while(!f.eof())
	  {f.read((char*)&E,sizeof(E));
	   if(f.eof())break;
	   if(Subcheck(E.Name,A)!=0){if(i==0){cout<<setw(2)<<"\nID"<<setw(15)<<"Album"<<setw(15)<<"Category"<<setw(10)<<"Type"<<setw(15)<<"Artist"<<setw(7)<<"Qty"<<setw(12)<<"Unit Price";}
				    cout<<endl<<setw(2)<<E.id<<setw(15)<<E.Name<<setw(15)<<E.Category<<setw(10)<<E.Type<<setw(15)<<E.Artist<<setw(6)<<E.Qty<<setw(7)<<E.price;i++;}
	   }getch();if(!i)cout<<"Unsuccessful search";getch();f.close();break;}

    case 2:{cout<<"Enter category: ";
	       gets(A);int i=0;
	       fstream f("Album.dat",ios::binary|ios::in);
	  while(!f.eof())
	  {f.read((char*)&E,sizeof(E));
	   if(f.eof())break;
	   if(Subcheck(E.Category,A)!=0){if(i==0){cout<<setw(2)<<"\nID"<<setw(15)<<"Album"<<setw(15)<<"Category"<<setw(10)<<"Type"<<setw(15)<<"Artist"<<setw(7)<<"Qty"<<setw(12)<<"Unit Price";}
				    cout<<endl<<setw(2)<<E.id<<setw(15)<<E.Name<<setw(15)<<E.Category<<setw(10)<<E.Type<<setw(15)<<E.Artist<<setw(6)<<E.Qty<<setw(7)<<E.price;i++;}
	   }getch();if(!i)cout<<"Unsuccessful search";getch();f.close();break;}
     case 3:{cout<<"Enter type: ";
	       gets(A);int i=0;
	       fstream f("Album.dat",ios::binary|ios::in);
	       while(!f.eof())
	       {f.read((char*)&E,sizeof(E));
		if(f.eof())break;
		if(Subcheck(E.Type,A)!=0){if(i==0){cout<<setw(2)<<"\nID"<<setw(15)<<"Album"<<setw(15)<<"Category"<<setw(10)<<"Type"<<setw(15)<<"Artist"<<setw(7)<<"Qty"<<setw(12)<<"Unit Price";}
					 cout<<endl<<setw(2)<<E.id<<setw(15)<<E.Name<<setw(15)<<E.Category<<setw(10)<<E.Type<<setw(15)<<E.Artist<<setw(6)<<E.Qty<<setw(7)<<E.price;
					 i++;}
		 }if(!i)cout<<"Unsuccessful search";getch();f.close();break;}
     case 4:{cout<<"Enter Artist: ";
		gets(A);int i=0;
	  fstream f("Album.dat",ios::binary|ios::in);
	  while(!f.eof())
	  {f.read((char*)&E,sizeof(E));
	   if(f.eof())break;
	   if(Subcheck(E.Artist,A)!=0){if(i==0){cout<<setw(2)<<"\nID"<<setw(15)<<"Album"<<setw(15)<<"Category"<<setw(10)<<"Type"<<setw(15)<<"Artist"<<setw(7)<<"Qty"<<setw(12)<<"Unit Price";}
				    cout<<endl<<setw(2)<<E.id<<setw(15)<<E.Name<<setw(15)<<E.Category<<setw(10)<<E.Type<<setw(15)<<E.Artist<<setw(6)<<E.Qty<<setw(7)<<E.price;i++;}
	   }getch();if(!i)cout<<"Unsuccessful search";getch();f.close();break;}
     case 5:{cout<<"Press any key to return to main menu";getch();return;}
    default: cout<<"Invalid choice";getch(); } }
    while(n!=5);
  return;

 }

//function to quit the software
void Exit()
{clrscr();
 char a;
 while(1)
 {cout<<"Are you sure that you want to exit(Y/N)";
 cin>>a;
 if(a=='Y'||a=='y'){cout<<"Press any key to exit";
		    getch();
		    exit(0);}
 if(a=='N'||a=='n')return;
 else cout<<"\nEnter valid option\n";}
 }



//driver function to invoke all necessary functions
void main()
{clrscr();
   int q;
 do{clrscr();Disp();
    cout<<"\t\t\t\tBISTRO MUSICALS";cout<<endl;
    cout<<"\t    MAIN MENU\n   1.Customer\n   2.Employee\n   3.Exit\n   Enter your choice: ";
    cin>>q; int m,n=8;
    switch(q)
    { case 1:{
	      do{clrscr();
		 cout<<"\t\t\t\tBISTRO MUSICALS\nIt's our pleasure to have you here!\nWhat is that you want to know? ";cout<<endl;
		 cout<<"1.Place Order"<<endl;
		 cout<<"2.Find Music"<<endl;
		 cout<<"3.Find Instrument"<<endl;
		 cout<<"4.Show all items"<<endl;
		 cout<<"5.Exit"<<endl;
		 cout<<"Enter your choice: ";
		 cin>>m;
			  switch(m)
			  {case 1:OrderBill();break;
			   case 2:FindMusic();break;
			   case 3:Instru();break;
			   case 4:Show();break;
			   case 5:{cout<<"Press any key to exit";
				   getch();
				   break;}
			   default:{cout<<"Invaild choice";getch();}}
			   }while(m!=5);break; }
    case 2:{int k=Pass();
	    if(!k)goto A2;
	    else{
	    do
	    {clrscr();
	    cout<<"What would you like to do?"<<endl;
	    cout<<"1.View albums in Stock\n";
	    cout<<"2.View instruments in Stock"<<endl;
	    cout<<"3.View sold items\n";
	    cout<<"4.Add new item"<<endl;
	    cout<<"5.Edit item\n";
	    cout<<"6.Remove item"<<endl ;
	    cout<<"7.Employee Usage\n";
	    cout<<"8.Exit"<<endl<<"Enter your choice: ";
	    cin>>n;
			       switch(n)
			       {case 3:SoldItems();break;
				case 1:AinSto();break;
				case 2:IinSto();break;
				case 4:AddNi();break;
				case 5:EI();break;
				case 6:RI();break;
				case 7:Emp();break;
				case 8:{A2: cout<<"Press any key to exit";getch();break;}
				default:cout<<"Invalid choice, ENTER again";getch();
				}}while(n!=8);break;}}
   case 3:{Exit();break;}
   default:cout<<"Invalid choice, ENTER again";getch();}}while(q);
  getch();
}
