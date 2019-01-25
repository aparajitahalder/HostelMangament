// HOSTEL - MANAGEMENT SYSTEM
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>

class man
{
 public : char hos_name[25], war_name[25], id[25], pass[25];
			 void Register(int);

}m[20] ;

class stu1
{
 public : char name[25], hos_name[25], type[25], con[25];
			  int rno,pass;
			  void allot(int);

}s1[30];
class stu2
{
 public : char name[25], complain[200], time[25];
			  int rno;
			 void comp(int);

}s2[30];

class stu3
{
 public : char name[25], d1[25], d2[25], place[25];
			  int eno;
			 void gate(int);

}s3[30];

int password(int a);

void main()
{
int a,i;
do
{
 clrscr();
 gotoxy(27,7); cout<<"***** LOGIN OPTIONS *****";
 gotoxy(24,10); cout<<"1. Management";
 gotoxy(24,11); cout<<"2. Warden";
 gotoxy(24,12); cout<<"3. Student";
 gotoxy(24,13); cout<<"4. Exit";
 gotoxy(21,15); cout<<"ENTER YOUR LOGIN OPTION : "; cin>>a;
 switch(a)
 {
  case 1 : int b=password(a);
			  if(b==0)
			  {
				int c;
				do
				{
				 clrscr();
				 gotoxy(27,7); cout<<"***** MENU *****";
				 gotoxy(24,10); cout<<"1. Register Hostel Warden";
				 gotoxy(24,11); cout<<"2. View Registered Wardens";
				 gotoxy(24,12); cout<<"3. Exit";
				 gotoxy(21,15); cout<<"ENTER YOUR OPTION : "; cin>>c;
				 if(c==1)
				 {
				  i=0;
				  fstream f1;
				  f1.open("management.dat",ios::binary|ios::in|ios::beg|ios::out|ios::app);
				  while(!f1.eof())
				  {
					f1.read((char*)&m[i],sizeof(m[i]));
					i++;
				  }
				  m[i].Register(i);
				  f1.close();
				 }
				 if(c==2)
				 {i=0;
					clrscr();
					gotoxy(15,2); cout<<"******* REGISTERED HOSTELS *******";
					gotoxy(3,5); cout<<"SNO";
					gotoxy(10,5); cout<<"HOSTEL NAME";
					gotoxy(30,5); cout<<"WARDEN NAME";
					gotoxy(55,5); cout<<"USER ID";
					gotoxy(70,5); cout<<"PASSWORD";
					gotoxy(1,6); cout<<"______________________________________________________________________________";
					fstream f1;
				  f1.open("management.dat",ios::in|ios::binary|ios::beg);
				  while(f1.read((char*)&m[i],sizeof(m[i])))
				  {

					gotoxy(3,7+i); cout<<i+1;
					gotoxy(12,7+i); cout<<m[i].hos_name;
					gotoxy(27,7+i); cout<<m[i].war_name;
					gotoxy(55,7+i); cout<<m[i].id;
					gotoxy(70,7+i); cout<<m[i].pass;

					i++;
				  }
				  gotoxy(5,9+i); cout<<"         PRESS ANY KEY TO EXIT";
				  getch();
				 f1.close();
				 }
				}while(c!=3);
			  }
			  break;

  case 2 :  b=password(a);
			  if(b==0)
			  {
				int c;
				do
				{
				 clrscr();
				 gotoxy(27,7); cout<<"***** MENU *****";
				 gotoxy(24,10); cout<<"1. Allot Rooms";
				 gotoxy(24,11); cout<<"2. View Alloted Rooms";
				 gotoxy(24,12); cout<<"3. View registered complains";
				 gotoxy(24,13); cout<<"4. View Gate Pass Requests";
				 gotoxy(24,14); cout<<"5. Exit";
				 gotoxy(21,16); cout<<"ENTER YOUR OPTION : "; cin>>c;
				 if(c==1)
				 {
				  i=0;
				  fstream f1;
				  f1.open("stu1.dat",ios::binary|ios::in|ios::beg|ios::out|ios::app);
				  while(!f1.eof())
				  {
					f1.read((char*)&s1[i],sizeof(s1[i]));
					i++;
				  }
				  s1[i].allot(i);
				  f1.close();
				 }
				 if(c==2)
				 {i=0;
					clrscr();
					gotoxy(15,2); cout<<"******* ALLOTED ROOMS *******";
					gotoxy(2,5); cout<<"RNO";
					gotoxy(8,5); cout<<"STUDENT NAME";
					gotoxy(25,5); cout<<"HOSTEL NAME";
					gotoxy(40,5); cout<<"ROOM TYPE";
					gotoxy(55,5); cout<<"CONTACT";
					gotoxy(70,5); cout<<"PASSWORD";
					gotoxy(1,6); cout<<"______________________________________________________________________________";
					fstream f1;
				  f1.open("stu1.dat",ios::in|ios::binary|ios::beg);
				  while(f1.read((char*)&s1[i],sizeof(s1[i])))
				  {

					gotoxy(2,7+i); cout<<s1[i].rno;
					gotoxy(8,7+i); cout<<s1[i].name;
					gotoxy(25,7+i); cout<<s1[i].hos_name;
					gotoxy(40,7+i); cout<<s1[i].type;
					gotoxy(55,7+i); cout<<s1[i].con;
					gotoxy(70,7+i); cout<<s1[i].pass;
					i++;
				  }
				  gotoxy(5,9+i); cout<<"         PRESS ANY KEY TO EXIT";
				  getch();
				 f1.close();
				 }
				 if(c==3)
				 {
				 clrscr();     int r,i=0;
					gotoxy(15,2); cout<<"******* REGISTERED COMPLAINS *******";
					gotoxy(3,5); cout<<"SNO";
					gotoxy(10,5); cout<<"ROOM NO";
					gotoxy(35,5); cout<<"NAME";
					gotoxy(1,6); cout<<"__________________________________________________________________";
					fstream f1;
				  f1.open("stu2.dat",ios::in|ios::binary|ios::beg);
				  while(f1.read((char*)&s2[i],sizeof(s2[i])))
				  {

					gotoxy(3,7+i); cout<<i+1;
					gotoxy(10,7+i); cout<<s2[i].rno;
					gotoxy(30,7+i); cout<<s2[i].name;

					i++;
				  }

				  gotoxy(3,9+i); cout<<"ENTER THE SNO YOU WANT TO VIEW DETAILS OF : ";  cin>>r;
						 f1.close();

					f1.open("stu2.dat",ios::in|ios::binary|ios::beg);
		clrscr();
					i=0;


						  while(f1.read((char*)&s2[i],sizeof(s2[i])))
				  {
					if(r==i+1)
					{
					gotoxy(13,5); cout<<"*** COMPLAIN NO. "<<i+1<<" ***";
					gotoxy(10,9); cout<<"=> RNO : ";  cout<<s2[i].rno;
					gotoxy(10,11); cout<<"=> STUDENT NAME : "; cout<<s2[i].name;
					gotoxy(10,13); cout<<"=> COMPLAIN : "; cout<<s2[i].complain;
					gotoxy(10,15); cout<<"=> TIME AND DATE AVAILABLE IN ROOM : "; cout<<s2[i].time;
					getch();
					}
					i++;
				  }

				f1.close();



				 }
				  if(c==4)
				  {
				  clrscr();     int r,i=0;
					gotoxy(15,2); cout<<"******* GATE PASS REQUESTS *******";
					gotoxy(3,5); cout<<"SNO";
					gotoxy(10,5); cout<<"ROOM NO";
					gotoxy(30,5); cout<<"NAME";
					gotoxy(1,6); cout<<"_______________________________________________________________________";
					fstream f1;
				  f1.open("stu3.dat",ios::in|ios::binary|ios::beg);
				  while(f1.read((char*)&s3[i],sizeof(s3[i])))
				  {

					gotoxy(3,7+i); cout<<i+1;
					gotoxy(12,7+i); cout<<s3[i].eno;
					gotoxy(27,7+i); cout<<s3[i].name;

					i++;
				  }

				  gotoxy(3,9+i); cout<<"ENTER THE SNO. YOU WANT TO VIEW DETAILS OF : ";  cin>>r;
				 f1.close();



		f1.open("stu3.dat",ios::in|ios::binary|ios::beg);
		clrscr();
		i=0;
					while(f1.read((char*)&s3[i],sizeof(s3[i])))
				  {
					if(r==i+1)
					{
					 gotoxy(13,5); cout<<"*** REQUEST NO. "<<i+1<<" ***";

					gotoxy(10,9); cout<<"=> STUDENT NAME : ";  cout<<s3[i].name;
					gotoxy(10,11); cout<<"=> DATE OF LEAVING : "; cout<<s3[i].d1;
					gotoxy(10,13); cout<<"=> DATE OF RETURNING : "; cout<<s3[i].d2;
					gotoxy(10,15); cout<<"=> PLACE : "; cout<<s3[i].place;
					getch();

					}
					i++;
					}
				 f1.close();

				 }
				}while(c!=5);
			  }
			  break;
case 3 : b=1;
  int id,pass;
  clrscr();
  gotoxy(20,7); cout<<"<<< Enter your Room No. and Password >>>";
  gotoxy(24,10); cout<<" ROOM NO : "; cin>>id;
  gotoxy(24,11); cout<<" PASSWORD : "; cin>>pass;
  fstream f1;
  int i=0;
  f1.open("stu1.dat",ios::binary|ios::in|ios::beg|ios::out|ios::app);
  while(!f1.eof())
  {
  f1.read((char*)&s1[i],sizeof(s1[i]));
	if(id==s1[i].rno && pass==s1[i].pass)
 {
  gotoxy(20,14); cout<<"USER ID AND PASSWORD ENTERED ARE CORRECT";
  gotoxy(20,15); cout<<"      PRESS ANY KEY TO CONTINUE";
  getch();
  b=0;
  break;
 }
  i++;
  }
  f1.close();
 if(b!=0)
 { clrscr();
	gotoxy(20,12); cout<<"            ACCESS DENIED !!!";
  gotoxy(20,14); cout<<"  USER ID AND PASSWORD ENTERED ARE INCORRECT";
  gotoxy(20,15); cout<<"SOMEONE MIGHT BE TRYING TO HACK INTO THE SYSTEM";
  getch();
 }


			 if(b==0)
			  {
				clrscr();
				int c;
				do
				{
				 clrscr();
				 gotoxy(27,7); cout<<"***** MENU *****";
				 gotoxy(24,10); cout<<"1. Open my Account";
				 gotoxy(24,11); cout<<"2. Complain Registration";
				 gotoxy(24,12); cout<<"3. Gate Pass Requets";
				 gotoxy(24,13); cout<<"4. Exit";
				 gotoxy(21,15); cout<<"ENTER YOUR OPTION : "; cin>>c;
				 if(c==1)
				 { clrscr();
					i=0;
					f1.open("stu1.dat",ios::binary|ios::in|ios::beg|ios::out|ios::app);
  while(!f1.eof())
  {
  f1.read((char*)&s1[i],sizeof(s1[i]));
	if(id==s1[i].rno && pass==s1[i].pass)
 {
			  gotoxy(10,5); cout<<"=> RNO : ";  cout<<s1[i].rno;
					gotoxy(10,7); cout<<"=> STUDENT NAME : "; cout<<s1[i].name;
					gotoxy(10,9); cout<<"=> HOSTEL NAME : "; cout<<s1[i].hos_name;
					gotoxy(10,11); cout<<"=> ROOM TYPE : "; cout<<s1[i].type;
					gotoxy(10,13); cout<<"=> CONTACT : "; cout<<s1[i].con;
					gotoxy(10,15); cout<<"=> PASSWORD : "; cout<<s1[i].pass;
					getch();
  break;
 }
  i++;
  }
  f1.close();
  }
  if(c==2)
				 {
				  i=0;
				  fstream f1;
				  f1.open("stu2.dat",ios::binary|ios::in|ios::beg|ios::out|ios::app);
				  while(!f1.eof())
				  {
					f1.read((char*)&s2[i],sizeof(s2[i]));
					i++;
				  }
				  s2[i].comp(i);
				  f1.close();
				 }

  if(c==3)
				 {
				  i=0;
				  fstream f1;
				  f1.open("stu3.dat",ios::binary|ios::in|ios::beg|ios::out|ios::app);
				  while(!f1.eof())
				  {
					f1.read((char*)&s3[i],sizeof(s3[i]));
					i++;
				  }
				  s3[i].gate(i);
				  f1.close();
				 }


				}while(c!=4);
			  }
			  break;



 }
}while(a!=4);
}

int password(int a)
{
 if(a==1)
 {
  char id[25],pass[25];
  clrscr();
  gotoxy(20,7); cout<<"<<< Enter your User-Id and Password >>>";
  gotoxy(24,10); cout<<" USER ID : "; gets(id);
  gotoxy(24,11); cout<<" PASSWORD : "; gets(pass);
 if(strcmp(id,"management.cet")==0 && strcmp(pass,"management")==0)
 {
  gotoxy(20,14); cout<<"USER ID AND PASSWORD ENTERED ARE CORRECT";
  gotoxy(20,15); cout<<"      PRESS ANY KEY TO CONTINUE";
  getch();
  return(0);
 }
 else
 {
  clrscr();
  gotoxy(20,12); cout<<"            ACCESS DENIED !!!";
  gotoxy(20,14); cout<<"  USER ID AND PASSWORD ENTERED ARE INCORRECT";
  gotoxy(20,15); cout<<"SOMEONE MIGHT BE TRYING TO HACK INTO THE SYSTEM";
  sound(500);
  delay(1500);
  nosound();
  return(1);
 }
 }
 if(a==2)
 {
  char id[25],pass[25];
  clrscr();
  gotoxy(20,7); cout<<"<<< Enter your User-Id and Password >>>";
  gotoxy(24,10); cout<<" USER ID : "; gets(id);
  gotoxy(24,11); cout<<" PASSWORD : "; gets(pass);
  fstream f1;
  int o=1,i=0;
  f1.open("management.dat",ios::binary|ios::in|ios::beg|ios::out|ios::app);
  while(!f1.eof())
  {
  f1.read((char*)&m[i],sizeof(m[i]));
	if(strcmp(id,m[i].id)==0 && strcmp(pass,m[i].pass)==0)
 {
  gotoxy(20,14); cout<<"USER ID AND PASSWORD ENTERED ARE CORRECT";
  gotoxy(20,15); cout<<"      PRESS ANY KEY TO CONTINUE";
  getch();
  o=0;
  break;
 }
  i++;
  }
  f1.close();
 if(o!=0)
 {
	clrscr();
	gotoxy(20,12); cout<<"            ACCESS DENIED !!!";
  gotoxy(20,14); cout<<"  USER ID AND PASSWORD ENTERED ARE INCORRECT";
  gotoxy(20,15); cout<<"SOMEONE MIGHT BE TRYING TO HACK INTO THE SYSTEM";
  getch();
  return(1);
 }
 else
 return(0);
}
return(9);
}

void man::Register(int i)
{
 clrscr();
 fstream f1;
 f1.open("management.dat",ios::binary|ios::out|ios::app);
 gotoxy(10,7); cout<<">>> Enter the following details to register a new hostel <<<";
 gotoxy(20,10); cout<<"HOSTEL NAME : "; gets(hos_name);
 gotoxy(20,12); cout<<"WARDEN NAME : "; gets(war_name);
 gotoxy(20,14); cout<<"User-Id of Warden : "; gets(id);
 gotoxy(20,16); cout<<"Password of Warden : "; gets(pass);
 gotoxy(20,19); cout<<"***** NEW HOSTEL REGISTERED SUCCESSFULLY *****";
 gotoxy(20,20); cout<<"             PRESS ANY KEY TO EXIT" ;
 f1.write((char*)&m[i],sizeof(m[i]));
 f1.close();
 getch();
}

void stu1::allot(int i)
{
 clrscr();
 fstream f1;
 f1.open("stu1.dat",ios::binary|ios::out|ios::app);
 gotoxy(10,7); cout<<">>> Enter the following details to allot a new room <<<";
 gotoxy(20,10); cout<<"HOSTEL NAME : "; gets(hos_name);
 gotoxy(20,12); cout<<"STUDENT NAME : "; gets(name);
 gotoxy(20,14); cout<<"HOSTEL TYPE : "; gets(type);
 gotoxy(20,16); cout<<"CONTACT : "; gets(con);
 gotoxy(20,18); cout<<"ROOM NO. ALLOTED : "; cin>>rno;
 pass=rno+random(25);
 gotoxy(10,21); cout<<"***** NEW ROOM ALLOTTED SUCCESSFULLY *****";
 gotoxy(10,22); cout<<"           PRESS ANY KEY TO EXIT" ;
 f1.write((char*)&s1[i],sizeof(s1[i]));
 f1.close();
 getch();
}

void stu2::comp(int i)
{
 clrscr();
 fstream f1;
 f1.open("stu2.dat",ios::binary|ios::out|ios::app);
 gotoxy(10,7); cout<<">>> Enter the following details to register a complain <<<";
 gotoxy(15,10); cout<<"YOUR NAME : "; gets(name);
 gotoxy(15,12); cout<<"ROOM NO. : "; cin>>rno;
 gotoxy(15,14); cout<<"COMPLAIN (200 words) : "; gets(complain);
 gotoxy(15,16); cout<<"TIME YOU WILL BE AVAILABLE IN ROOM (Tomorrow): "; gets(time);
 gotoxy(10,19); cout<<"***** YOUR COMPLAIN HAS BEEN REGISTERED SUCCESSFULLY *****";
 gotoxy(10,20); cout<<"               PRESS ANY KEY TO EXIT" ;
 f1.write((char*)&s2[i],sizeof(s2[i]));
 f1.close();
 getch();
}
void stu3::gate(int i)
{
 clrscr();
 fstream f1;
 f1.open("stu3.dat",ios::binary|ios::out|ios::app);
 gotoxy(10,7); cout<<">>> Enter the following details to apply for gate - pass <<<";
 gotoxy(15,10); cout<<"YOUR NAME : "; gets(name);
 gotoxy(15,12); cout<<"ROLL NO. : "; cin>>eno;
 gotoxy(15,14); cout<<"DATE OF LEAVING : "; gets(d1);
 gotoxy(15,16); cout<<"DATE OF RETURNING : "; gets(d2);
 gotoxy(15,18); cout<<"PLACE : "; gets(place);
 gotoxy(10,21); cout<<"***** GATE - PASS REQUEST SUCCESSFUL *****";
 gotoxy(10,22); cout<<"           PRESS ANY KEY TO EXIT" ;
 f1.write((char*)&s3[i],sizeof(s3[i]));
 f1.close();
 getch();
}



