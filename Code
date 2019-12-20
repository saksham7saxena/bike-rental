#include<fstream.h>
#include<conio.h>
#include<stdio.h>
struct date
{
intdd,mm,yy;
voidgetdate()
 {
cout<<"\n\n Enter date : "<<endl;
cout<<"Date : ";
cin>>dd;
cout<<"Month : ";
cin>>mm;
cout<<"Year : ";
cin>>yy;
 }
voidshowdate()
 {
cout<<" "<<dd<<"-"<<mm<<"-"<<yy;
 }
};
class rider
{
intrno;
char name[30],address[50],phone[15];
public:
voidgetrider()
 {
cout<<"\nEnter ridership number \t: ";
cin>>rno;
cout<<"Enter rider's name \t: ";
gets(name);
cout<<"Enter rider's address \t: ";
gets(address);
cout<<"Enter contact number \t: ";
gets(phone);
 }
voidshowrider()
 {
cout<<"\nRidership No\t: "<<rno;
cout<<"\n Rider's name \t: "<<name;
cout<<"\n Address \t: "<<address;
cout<<"\nContact no. \t: "<<phone;
 }
intret_rno()
 {
returnrno;
 }
};
void line()
 {
cout<<"\n";
for(inti=1;i<=50;i++)
cout<<"_";
 }
 //Rider function declare
voidadd_rid();
intsearch_rid();
voidedit_rid();
voiddel_rid();
voiddisp_rid();
voidrider_menu()
 {
intch;
charans;
do
 {
clrscr();
cout<<"\n\n\t\tRIDER MANAGEMENT MENU";
line();
cout<<"\n\n1. Add a rider";
cout<<"\n\n2. Delete a rider";
cout<<"\n\n3. Edit a rider";
cout<<"\n\n4. Show all riders";
cout<<"\n\n5. Search a rider";
cout<<"\n\n0. Exit";
cout<<"\n\n\n Enter your choice - \t";
cin>>ch;
switch(ch)
 {
case 1 : add_rid();
break;
case 2 : del_rid();
break;
case 3 : edit_rid();
break;
case 4 : disp_rid();
break;
case 5 : search_rid();
break;
case 0 : return;
 }
cout<<endl<<"\tContinue? y/n";
cin>>ans;
}while(ans=='y'||ans=='Y');
 }
voidadd_rid()
 {
rider m;
fstream file;
cout<<"\nEnter Rider details: ";
line();
m.getrider();
file.open("rider.dat",ios::app|ios::binary);
file.write((char*)&m,sizeof(m));
file.close();
 }
intsearch_rid()
 {
intnum,found=0; fstream file;
rider m;
cout<<"\n\nEnter Ridership number to search : ";
cin>>num;
file.open("rider.dat",ios::in|ios::binary);
while(!found&&file.read((char*)&m,sizeof(m)))
 {
if(num==m.ret_rno())
 {
cout<<"\n\n Rider found\n\n";
m.showrider();
found=1;
break;
 }
 }
file.close();
if(!found)
{ num=-1;
cout<<"\n\nRider not found ";
 }
return(num);
}
voidedit_rid()
{
intnum,found=0; rider m;
fstream file, temp;
file.open("rider.dat",ios::in|ios::binary);
temp.open("new.dat",ios::out|ios::binary);
cout<<"\n\nEnter Ridership no. : ";
cin>>num;
while(!found&&file.read((char*)&m,sizeof(m)))
 {
if(num==m.ret_rno())
 {
cout<<"\n\nEnter new details: ";
m.getrider();
found++;
 }
temp.write((char*)&m,sizeof(m));
 }
temp.close();
file.close();
remove("rider.dat");
rename("new.dat","data.dat");
if(!found)
cout<<"\n\nRider does not exist.";
file.close();
}
voiddisp_rid()
 {
fstream file;
rider m;
intcnt=0;
file.open("rider.dat",ios::in|ios::binary);
cout<<"\n\nDetails of riders are: ";
line();
while(file.read((char*)&m,sizeof(m)))
 {
m.showrider();
cnt++;
 }
file.close();
line();
cout<<"\n\n\tTotal number of riders - "<<cnt<<endl;
}
voiddel_rid()
{
fstream file1, file2;
intnum;
rider m;
int found=0;
file1.open("rider.dat",ios::in|ios::binary);
file2.open("temp.dat",ios::out|ios::binary);
cout<<"\n\nEnter ridership no. to be deleted: ";
cin>>num;
while(file1.read((char*)&m,sizeof(m)))
 {
if(num==m.ret_rno())
found=1;
else
file2.write((char*)&m,sizeof(m));
 }
file1.close();
file2.close();
remove("rider.dat");
rename("temp.dat","rider.dat");
if(found==1)
cout<<"\n\nRecord deleted";
else
cout<<"\n\nRecord not found";
}
class bike
{
intbikeid;
charbname[30];
chardesc[40];
public:
voidgetbike()
 {
cout<<"\nEnter Bike's Number : ";
cin>>bikeid;
cout<<"Enter Bike's Title : ";
gets(bname);
cout<<"Enter Bike's Description : ";
gets(desc);
 }
voidshowbike()
 {
cout<<"\nBike Number \t: ";
cout<<bikeid;
cout<<"\nBike's Name \t: "<<bname;
cout<<"\nBike's Description\t: "<<desc;
 }
intret_bikeid()
 {
returnbikeid;
 }
};
//Bike functions declare
voidadd_bike();
intsearch_bike();
voiddel_bike();
voiddisp_bike();
voidbike_menu()
 {
intch;
charans;
do
 {
clrscr();
cout<<"\n\n\t\tBIKE MANAGEMENT";
line();
cout<<"\n\n1. Add a bike";
cout<<"\n\n2. Delete a bike";
cout<<"\n\n3. Show all bikes";
cout<<"\n\n4. Search a bike";
cout<<"\n\n0. Exit";
cout<<"\n\n\n Enter your choice\t";
cin>>ch;
switch(ch)
 {
case 1 : add_bike();
break;
case 2 : del_bike();
break;
case 3 : disp_bike();
break;
case 4 : search_bike();
break;
case 0 : return;
 }
cout<<"Continue? y/n"<<endl;
cin>>ans;
}while(ans=='y'||ans=='Y');
 }
voidadd_bike()
 {
bike d;
fstream file;
cout<<"\nEnter bike details: ";
d.getbike();
file.open("bike.dat",ios::app|ios::binary);
file.write((char*)&d,sizeof(d));
file.close();
 }
intsearch_bike()
 {
intnu,found=0;fstream file;
bike d;
cout<<"\n\nEnter desired bike id : ";
cin>>nu;
file.open("bike.dat",ios::in|ios::binary);
while(!found&&file.read((char*)&d,sizeof(d)))
 {
if(nu==d.ret_bikeid())
 {
cout<<"\n\n Bike found\n\n";
d.showbike();
found=1;
break;
 }
 }
file.close();
if(!found)
{ nu=-1;
cout<<"\n\nBike not found";
 }
return(nu);
}
voiddel_bike()
{
fstream file,file2;
intnum;
bike d;
int found=0;
file.open("bike.dat",ios::in|ios::binary);
file2.open("temp.dat",ios::out|ios::binary);
cout<<"\n\nEnter bike no. to be deleted: ";
cin>>num;
while(file.read((char*)&d,sizeof(d)))
 {
if(num==d.ret_bikeid())
found=1;
else
file2.write((char*)&d,sizeof(d));
 }
file.close();
file2.close();
remove("bike.dat");
rename("temp.dat","bike.dat");
if(found==1)
cout<<"\n\nRecord deleted ";
}
voiddisp_bike()
 {
fstream file;
bike d;
intcnt=0;
file.open("bike.dat",ios::in|ios::binary);
cout<<"\n\nDetails of bikes are: ";
line();
while(file.read((char*)&d,sizeof(d)))
 {
d.showbike();
cnt++;
 }
file.close();
cout<<"\n\nTotal number of bike are - "<<cnt<<endl;
 }
class rent
 {
intrent_id;
intbike_id, rid_id;
datedoi,dor;
float rent;
public:
voidgetrent(intrno, intbikeid)
 {
rid_id=rno; bike_id=bikeid;
cout<<"\n\nBike ID :\t"<<bike_id;
cout<<"\nRider ID :\t"<<rid_id;
cout<<"\n\nEnter rent id no.: ";
cin>>rent_id;
cout<<"\n\nDate of issue :\t";
doi.getdate();
cout<<"\n\nDate of return:\t";
dor.getdate();
cout<<"\n\nEnter rent :\t";
cin>>rent;
 }
voidshowrent()
 {
cout<<"\n\nRent ID no: \t";
cout<<rent_id;
cout<<"\nBike ID no: \t";
cout<<bike_id;
cout<<"\nRider ID no:\t";
cout<<rid_id;
cout<<"\nDate of issue:\t";
doi.showdate();
cout<<"\nDate of return:\t";
dor.showdate();
cout<<"\nRent: \t";
cout<<rent;
 }
intret_rid()
 {
returnrent_id;
 }
};
voidissue_bike()
 {
rent r; fstream file;
intrid_id,bike_id;
bike_id=search_bike();
if(bike_id!=-1)
 {
rid_id=search_rid();
if(rid_id!=-1)
 {
r.getrent(rid_id, bike_id);
file.open("rent.dat",ios::app|ios::binary);
file.write((char*)&r,sizeof(r));
file.close();
cout<<"Bike has been rented.\nRent details are:\n";
r.showrent();
 }
 }
 }
void find()
 {
intn,found=0;fstream file;
rent r;
cout<<"\n\nEnter rent id: ";
cin>>n;
file.open("rent.dat",ios::in|ios::binary);
while(!found&&file.read((char*)&r,sizeof(r)))
 {
if(n==r.ret_rid())
 {
cout<<"\n\n Details found\n\n";
r.showrent();
found=1;
break;
 }
 }
file.close();
if(!found)
cout<<"\n\nBike not found";
}
voiddisp_rent()
 {
fstream file;
rent r;
intcnt=0;
file.open("rent.dat",ios::in|ios::binary);
cout<<"\n\nDetails of bike are: ";
line();
while(file.read((char*)&r,sizeof(r)))
 {
r.showrent();
cnt++;
 }
file.close();
cout<<"\n\nTotal number of rented bikes - "<<cnt<<endl;
}
voidret_bike()
{
fstream file,file2;
int n;
rent r;
int found=0;
file.open("rent.dat",ios::in|ios::binary);
file2.open("temp.dat",ios::out|ios::binary);
cout<<"\n\nEnter bike no. to be returned: ";
cin>>n;
while(file.read((char*)&r,sizeof(r)))
 {
if(n==r.ret_rid())
found=1;
else
file2.write((char*)&r,sizeof(r));
 }
file.close();
file2.close();
remove("rent.dat");
rename("temp.dat","rent.dat");
if(found)
cout<<"\n\nBike returned! ";
else
cout<<"\n\nRecord not found ";
}
void main()
{
intch;
charans;
clrscr();
do
 {
cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\t BIKE RENTAL
SERVICE\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ";
cout<<"\n\t\tMain Menu"<<endl;
cout<<"\n\n1.Bike Management";
cout<<"\n\n2.Rider Management";
cout<<"\n\n3.Rent a bike";
cout<<"\n\n4.Search a rented bike";
cout<<"\n\n5.Return a bike";
cout<<"\n\n6.Show all rented bikes";
cout<<"\n\n0.Exit ";
cout<<"\n\n\n Your choice is : ";
cin>>ch;
if(ch==0)
break;
switch(ch)
 {
case 1: bike_menu();
break;
case 2 :rider_menu();
break;
case 3 :issue_bike();
break;
case 4 :find();
break;
case 5 :ret_bike();
break;
case 6 :disp_rent();
break;
 }
cout<<"\nContinue in the main menu? y/n";
cin>>ans;
clrscr();
}while(ans=='y'||ans=='Y');
clrscr();
cout<<"\n\n\n\n\n\n\t_________Thank You!!!_________";
cout<<"\n\n\n\tCOMPUTER PROJECT ";
cout<<"\n\n\t\t BY :-"; cout<<"\n\t\tSakshamSaxena"<<"\t XII - C\n\t\tDelhi Public School, Vasant
Kunj";
cout<<" \n\n\n\t\t Press any key to exit ";
getch();
}
