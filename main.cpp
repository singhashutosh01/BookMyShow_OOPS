#include<iostream>
#include<bits/stdc++.h>
#include<stdexcept>

using namespace std;
vector<int> v;
vector<int>::iterator itr=v.begin();
map<int,float> maps;
map<int,float>::iterator it;
class seatException{
public:
    int errNo;
    string msg;
    seatException(){}
    seatException(int x,string s)
    {
        errNo=x;
        msg=s;
    }
    void showError()
    {
        cout<<"Error Number:"<<errNo<<endl;
        cout<<"Message:"<<msg<<endl;
    }

};
class custIdException{
public:
    int errNo;
    string msg;
    custIdException(){}
    custIdException(int x,string y)
    {

        errNo=x;
        msg=y;
    }
    void showError()
    {
        cout<<"Error Number:"<<errNo<<endl;
        cout<<"Message:"<<msg<<endl;
    }
};
class mobileLengthError{
public:
    int errNo;
    string msg;
    mobileLengthError(){}
    mobileLengthError(int x,string y)
    {
        errNo=x;
        msg=y;
    }
    void showError()
    {
        cout<<"Error Number:"<<errNo<<endl;
        cout<<"Message:"<<msg<<endl;
    }
};
class debitException{
public:
   int errNo;
    string msg;
    debitException(){}
    debitException(int x,string y)
    {

        errNo=x;
        msg=y;
    }
    void showError()
    {
        cout<<"Error Number:"<<errNo<<endl;
        cout<<"Message:"<<msg<<endl;
    }
};
class noTheatreError{
public:
    int errNo;
    string msg;
    noTheatreError(){}
    noTheatreError(int x,string y)
    {
        errNo=x;
        msg=y;
    }
    void showError()
    {
        cout<<"Error Number:"<<errNo<<endl;
        cout<<"Message:"<<msg<<endl;
    }
};
class noSnackError{
public:
    int errNo;
    string msg;
    noSnackError(){}
    noSnackError(int x,string y)
    {
        errNo=x;
        msg=y;
    }
    void showError()
    {
        cout<<"Error Number:"<<errNo<<endl;
        cout<<"Message:"<<msg<<endl;
    }
};
class Seat{
public:
    string seatId;
    float price;
    bool availabilty=true;
    Seat()
    {
     seatId="";
    }
    Seat(string x,float y)
    {
     seatId=x;
     price=y;
    }
    virtual void printSeat()=0;
    bool getAvailabilty()
    {
        return availabilty;
    }
    void markAsSold()
    {
        availabilty=false;
    }
    float getPrice()
    {
        return price;
    }
};
class Gold:public Seat{
public:
    float cancelPercent;
    Gold():Seat()
    {
      seatId="";
      price=0;
      cancelPercent=0;
    }
    Gold(string x,float y,float z):Seat(x,y)
    {
      seatId=x;
      price=y;
      cancelPercent=z;
    }
    void printSeat()
    {
        cout<<seatId<<" "<<price<<" "<<cancelPercent<<endl;
    }
};
class Silver:public Seat{
public:
    float cancelPercent;
    Silver():Seat()
    {
      seatId="";
      price=0;
      cancelPercent=0;
    }
    Silver(string x,float y,float z):Seat(x,y)
    {
      seatId=x;
      price=y;
      cancelPercent=z;
    }
    void printSeat()
    {
        cout<<seatId<<" "<<price<<" "<<cancelPercent<<endl;
    }
};
class Platinum:public Seat{
public:
    float cancelPercent;
    Platinum():Seat()
    {
      seatId="";
      price=0;
      cancelPercent=0;
    }
    Platinum(string x,float y,float z):Seat(x,y)
    {
      seatId=x;
      price=y;
      cancelPercent=z;
    }
    void printSeat()
    {
        cout<<seatId<<" "<<price<<" "<<cancelPercent<<endl;
    }
};
class Auditorium{
public:
    int roomId;
    int capacity;
    Gold *seat1;
    Silver *seat2;
    Platinum *seat3;
    Seat *seats[10];
    Auditorium()
    {
        roomId=0;
        capacity=0;
    }
    Auditorium(int x,int y)
    {
        roomId=x;
        capacity=y;
    }
    void addSeat()
    {
        for(int i=0;i<3;i++)
            seats[i]=&seat1[i];
        for(int i=3;i<6;i++)
            seats[i]=&seat2[i];
        for(int i=6;i<9;i++)
            seats[i]=&seat3[i];
    }
    void printAudi()
    {
        cout<<"Room ID:"<<roomId<<" "<<"Total Seating Available:"<<capacity<<endl<<"\n";
        //Seat::printSeat();
        cout<<"Seat & Price Info"<<"\n";
                for(int i=0;i<3;i++)
            cout<<seat1[i].seatId<<" "<<seat1[i].price<<" "<<seat1[i].cancelPercent<<"\n";
        for(int i=0;i<3;i++)
            cout<<seat2[i].seatId<<" "<<seat2[i].price<<" "<<seat2[i].cancelPercent<<"\n";
        for(int i=0;i<3;i++)
            cout<<seat3[i].seatId<<" "<<seat3[i].price<<" "<<seat3[i].cancelPercent<<"\n";
            cout<<"\n";
    }

};
class Session{
public:
    string date;
    string startTime;
    Session()
    {
        date="";
        startTime="";
    }
    Session(string x,string y)
    {
        date=x;
        startTime=y;
    }
    void printSession()
    {
        cout<<"Show Date:"<<date<<" "<<"Show Time:"<<startTime<<" "<<endl;
    }
};
enum ShowType {
    ST_Movie,    ST_LiveEvents
};
//library class
class Shows{
public:
    int sid;
    string showName;
    float price;
    string releaseDate;
    //Review reviews[];
    Shows()
    {
        sid=0;
        showName="";
        price=0.0;
        releaseDate="";
    }
    Shows(int x,string y,float p,string d)
    {
        sid=x;
        showName=y;
        price=p;
        releaseDate=d;
    }
    //virtual void addReview()=0;
    virtual void printShow() = 0;
    static Shows* Create1(ShowType type);
};
class Movie:public Shows{
public:
    Session s[3];
    Movie():Shows()
    {
        sid=0;
        showName="";
        price=0;
        releaseDate="";
    }
    Movie(int x,string y,float p,string d,Session arr[]):Shows(x,y,p,d)
    {
         sid=x;
        showName=y;
        price=p;
        releaseDate=d;
        for(int i=0;i<3;i++)
        {
            s[i]=arr[i];
        }
    }
    void printShow()
    {
    cout<<"Movie ID: "<<sid<<" \n"<<"Movie Name: "<<showName<<" \n"<<"Movie Base Price: "<<price<<"\n"<<"Movie Release Date: "<<releaseDate<<"\n ";
    //Session::printSession();
    cout<<"\n";
    cout<<"Show Date:"<<s[0].date<<"\n";
    for(int i=0;i<3;i++)
    cout<<"Show Slots are:"<<s[i].startTime<<"   ";
    cout<<"\n";
    }


};
class LiveEvents:public Shows{
public:
    Session s[3];
    LiveEvents():Shows()
    {
        sid=0;
        showName="";
        price=0;
        releaseDate="";
    }
     LiveEvents(int x,string y,float p,string d,Session arr[]):Shows(x,y,p,d)
    {
        sid=x;
        showName=y;
        price=p;
        releaseDate=d;
        for(int i=0;i<3;i++)
        {
            s[i]=arr[i];
        }
    }
     void printShow()
    {
    cout<<"Live Event ID: "<<sid<<" \n"<<"Event Name: "<<showName<<" \n"<<"Event Base Price: "<<price<<"\n"<<"Event Release Date: "<<releaseDate<<"\n ";
    //Session::printSession();
    cout<<"\n";
    cout<<"Show Date:"<<s[0].date<<"\n";
    for(int i=0;i<3;i++)
    cout<<"Show Slots are:"<<s[i].startTime<<"   ";
     cout<<"\n";
    }

};
Shows* Shows::Create1(ShowType type) {
    if (type == ST_Movie)
    {
        cout<<"Enter the Movie details:\n";
        int s;
        string d,n;
        float p;
        cout<<"Enter the Movie ID: \n";
        cin>>s;
        cout<<"Enter the name of the Movie: \n";
        cin>>n;
        cout<<"Enter the Base Price of the Movie: \n";
        cin>>p;
        cout<<"Enter the Release Date of the Movie:\n";
        cin>>d;
        string date,t1,t2,t3;
        cout<<"Enter the date:";
        cin>>date;
        cout<<"Enter the three session slots for the movie:";
        cin>>t1>>t2>>t3;
        Session s1(date,t1),s2(date,t2),s3(date,t3);
        Session timeArray[]={s1,s2,s3};
        cout<<"Details Entered Successfully\n";
         return new Movie(s,n,p,d,timeArray);
    }

    else if (type == ST_LiveEvents){
        cout<<"Enter the Event details:\n";
        int s;
        string d,n;
        float p;
        cout<<"Enter the Event ID: \n";
        cin>>s;
        cout<<"Enter the name of the Event: \n";
        cin>>n;
        cout<<"Enter the Base Price of the Event: \n";
        cin>>p;
        cout<<"Enter the Release Date of the Event:\n";
        cin>>d;
        string date,t1,t2,t3;
        cout<<"Enter the date:";
        cin>>date;
        cout<<"Enter the three session slots for the movie:";
        cin>>t1>>t2>>t3;
        Session s1(date,t1),s2(date,t2),s3(date,t3);
        Session timeArray[]={s1,s2,s3};
        cout<<"Details Entered Successfully\n";
        return new LiveEvents(s,n,p,d,timeArray);
    }
    else return NULL;
}
class Client {
public:
    Client()
    {
        ShowType type=ST_Movie;
        pShow = Shows::Create1(type);
    }
    ~Client() {
        if (pShow) {
            delete[] pShow;
            pShow = NULL;
        }
    }
    Shows* getShow()  {
        return pShow;
    }

private:
    Shows *pShow;
};
class Client2 {
private:
    Shows *pShow;
public:
     Client2 ()
    {
        ShowType type=ST_LiveEvents;
        pShow = Shows::Create1(type);
    }
    ~Client2 () {
        if (pShow) {
            delete[] pShow;
            pShow = NULL;
        }
    }
    Shows* getShow()  {
        return pShow;
    }
};
class Snacks{
public:
    int productId;
    string name;
    int quantity;
    float price;
    Snacks()
    {
        name="";
        quantity=0;
        price=0;
        productId=0;
    }
    Snacks(int pp,string n,int q,float p)
    {
        name=n;
        quantity=q;
        price=p;
        productId=pp;
    }
    void printSnacks()
    {
        cout<<"Product ID:"<<productId<<":"<<"Name:"<<name<<" :"<<"Quantity:"<<quantity<<" "<<"Price:"<<price<<endl;
    }
    float getSnackPrice()
   {
       return price;
   }
};

Shows *arr1[10];
Shows *arr2[10];
Shows *arr3[10];
Shows *arr4[10];
Shows *arr5[10];
Shows *arr6[10];
Shows *arr7[10];
Shows *arr8[10];
Shows *arr9[10];
Shows *arr10[10];
Shows *arr11[10];//stackoverflow.com/questions/33123371/how-to-create-array-of-an-abstract-class-in-c/33123456
class Theatre{
public:
    int tid;
    string tName;
    string address;
    Movie *movie;
    LiveEvents *liveEvents;
    Auditorium audi[4];
    Snacks snacks[3];
   static int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11;
   Theatre()
   {
       tid=0;
       tName="";
       address="";
   }
   Theatre(int x,string y,string z,Auditorium arr[],Snacks sarr[])
   {
       tid=x;
       tName=y;
       address=z;
      for(int i=0;i<4;i++)
        audi[i]=arr[i];
      for(int i=0;i<3;i++)
        snacks[i]=sarr[i];
   }
   void addShow(int x1)
   {
     int x;
    cout<<"What type of Show you want to add in the theatre:\n";
    cout<<"Enter the choice:\n";
    cout<<"1.Movie\n";
    cout<<"2.Live Event\n";
    cin>>x;
    Shows *pShow;
    if(x==1){
        Client *pClient = new Client();
        pShow = pClient->getShow();
        pShow->printShow();
    }
    if(x==2){
        Client2 *pClient= new Client2();
        pShow = pClient->getShow();
        pShow->printShow();
    }
    if(x1==1)
    {
         arr1[i1]=pShow;
       i1++;
    }
    if(x1==2)
    {
         arr2[i2]=pShow;
       i2++;
    }
    if(x1==3)
    {
         arr3[i3]=pShow;
       i3++;
    }
    if(x1==4)
    {
         arr4[i4]=pShow;
       i4++;
    }
    if(x1==5)
    {
         arr5[i5]=pShow;
       i5++;
    }
    if(x1==6)
    {
         arr6[i6]=pShow;
       i6++;
    }
    if(x1==7)
    {
         arr7[i7]=pShow;
       i7++;
    }
    if(x1==8)
    {
         arr8[i8]=pShow;
       i8++;
    }
    if(x1==9)
    {
         arr9[i9]=pShow;
       i9++;
    }
    if(x1==10)
    {
         arr10[i10]=pShow;
       i10++;
    }
    if(x1==11)
    {
         arr11[i11]=pShow;
       i11++;
    }
   }

   void searchShow()
   {
    if(tid==1)
    for(int i=0;i<i1;i++)
     {
         arr1[i]->printShow();
     }
     if(tid==2)
    for(int i=0;i<i2;i++)
     {
         arr2[i]->printShow();
     }
     if(tid==3)
    for(int i=0;i<i3;i++)
     {
         arr3[i]->printShow();
     }
    if(tid==4)
    for(int i=0;i<i4;i++)
     {
         arr4[i]->printShow();
     }
    if(tid==5)
    for(int i=0;i<i5;i++)
     {
         arr5[i]->printShow();
     }
     if(tid==6)
    for(int i=0;i<i6;i++)
     {
         arr6[i]->printShow();
     }

    if(tid==7)
    for(int i=0;i<i7;i++)
     {
        arr7[i]->printShow();
     }
     if(tid==8)
    for(int i=0;i<i8;i++)
     {
         arr8[i]->printShow();
     }
     if(tid==9)
    for(int i=0;i<i9;i++)
     {
         arr9[i]->printShow();
     }
     if(tid==10)
    for(int i=0;i<i10;i++)
     {
         arr10[i]->printShow();
     }
     if(tid==11)
    for(int i=0;i<i11;i++)
     {
         arr11[i]->printShow();
     }

   }


   void printTheatre()
   {
       cout<<"Theatre Name:"<<tName<<" "<<"Theatre ID:"<<tid<<" "<<"Theatre Address:"<<address<<"\n";
       //Shows::printShow();
       cout<<"\n";
   }
   void seatMap()
   {
      audi[0].printAudi();
      cout<<"\n";
   }
   void printSnackss()
   {
       for(int i=0;i<3;i++)
       snacks[i].printSnacks();


   }
};

class Ticket{
public:
    int ticketId;
    string thName;
    string seatArray[10];
    int roomNum;
    int custID;
    float totalCost;
    int seats;
    string name;
    string showName;
    Ticket()
    {

    }
    Ticket(int xx,string x,int r,int c,float co,string a[],int s,string ss,string sn)
    {
        ticketId=xx;
        thName=x;
        roomNum=r;
        custID=c;
        totalCost=co;
        seats=s;
        name=ss;
        showName=sn;
        for(int i=0;i<s;i++)
            seatArray[i]=a[i];
    }
    void printTicket()
    {
        cout<<"******************************************************************************************"<<endl;
        cout<<"Ticket ID:"<<ticketId<<endl;
        cout<<"Venue:"<<thName<<endl;
        cout<<"Audi Number:"<<roomNum<<endl;
        cout<<"Customer ID:"<<custID<<endl;
        cout<<"Customer Name:"<<name<<endl;
        cout<<"Show Name:"<<showName<<endl;
        cout<<"Total Payment:"<<totalCost<<endl;
        cout<<"Selected seats are:"<<endl;
        for(int i=0;i<seats;i++)
            cout<<seatArray[i]<<" ";
        cout<<endl;


    }
};
map<int,Ticket> mp;
map<int,Ticket>::iterator its;
class ServiceProvider{
public:
    string name;
    Theatre *theatres;
    Ticket *tickets[100];
    static int ticketCounter;
    ServiceProvider()
    {
    name="";
    }
    ServiceProvider(string s)
    {
       name=s;
    }
    void printServiceProvider()
    {
        cout<<"                                                    "<<name<<"                                    \n";
        cout<<"--------------------------------------------------------------------------------------------------------\n";
        cout<<"List of all the theatres associated\n\n";
        for(int i=0;i<11;i++)
        {
            theatres[i].printTheatre();
        }
    }
    void showTheatres(string x,int *p)
    {
        int flag=0;
        cout<<"***************************************************************************************\n";
        cout<<"Theatres Available In Your City Are:\n\n";
        for(int i=0;i<11;i++)
        {
            if(theatres[i].address==x)
            {
                theatres[i].printTheatre();
                flag=1;
                break;

            }

        }
        if(flag==0){
                *p=-1;
            throw noTheatreError(9999,"No Theatre in your location\nPlease Enter new location:");

        }
    }
    void searchThetare(int x)
    {
        int index;
        for(int i=0;i<11;i++)
        {
            if(theatres[i].tid==x)
            {
                index=i;
                break;
            }
        }
        theatres[index].searchShow();
    }
    void showSeats(int x)
    {
        int index;
        for(int i=0;i<11;i++)
        {
            if(theatres[i].tid==x)
            {
                index=i;
                break;
            }
        }
        theatres[index].seatMap();
    }
    int checkSeat(int x,int y,string z)
    {
        int index=-1;
        for(int i=0;i<9;i++){

       if(theatres[x].audi[y].seats[i]->seatId==z)
       {
            index=i;
            break;
       }
        }
        return theatres[x].audi[y].seats[index]->getAvailabilty();
    }
    void fillSeat(int x,int y,string z)
    {
        int index=-1;
        for(int i=0;i<9;i++){

       if(theatres[x].audi[y].seats[i]->seatId==z)
       {
            index=i;
            break;
       }
        }
        theatres[x].audi[y].seats[index]->markAsSold();

    }
    void showTheatreMenu(int id)
    {

        (theatres[id]).printSnackss();
    }
    void addNewTicket(string x, int r,int c,float p,string a[],int s,int b[],int sc,string ss,string sname)
    {
        tickets[ticketCounter]=new Ticket(ticketCounter+1,x,r,c,p,a,s,ss,sname);
        ticketCounter++;
    }
    void showTicket()
    {
        for(int i=0;i<ticketCounter;i++)
        {
            tickets[i]->printTicket();
        }
    }
    void payment(int id)
    {
        it=maps.find(id);
        if(it==maps.end())
            cout<<"Customer Doesnot Exists"<<endl;
        else
            cout<<"Customer ID:"<<it->first<<" "<<"Total Payment:"<<it->second<<endl;

    }

};
int ServiceProvider::ticketCounter=0;
class Customer{
public:
    int cid;
    string cName;
    long long int contactNo;
    long long int debitCardNo;
    string password;
    ServiceProvider booking;
    Customer()
    {
        cid=0;
        cName="";
        contactNo=0;
        debitCardNo=0;
        password="";
    }
    Customer(int x, string c,long long int y,long long int z,string z1)
    {
        cid=x;
        cName=c;
        contactNo=y;
        debitCardNo=z;
        password=z1;
    }
    void bookTicket(ServiceProvider ss,Customer cc)
    {
      string city;
      cout<<"Enter your city:";
      cin>>city;
      int j=0;
      for(int i=0;i<1;i++)
      {
        try{

      ss.showTheatres(city,&j);
      i=j;
        }
        catch(noTheatreError nte)
        {
            nte.showError();
        }
      }
      cout<<"Enter the theatre id:";
      int id;
      cin>>id;
      cout<<"The list of shows in the preferred theatre are:\n";
      ss.searchThetare(id);
      int show;
      cout<<"Enter the show ID to be booked:";
      cin>>show;
      cout<<"The Available seats are:\n";
      ss.showSeats(id);
      int num;
      cout<<"Enter the number of people:";
      cin>>num;
      cout<<"Enter the seat id to be selected:";
      string arr[20],s;
      for(int i=0;i<num;i++)
      {
          cin>>s;
          int status=ss.checkSeat(id-1,1,s);
          try{
          if(status==1)
          {
              cout<<"Seat Available"<<endl;
              arr[i]=s;
              ss.fillSeat(id-1,1,s);
          }
          else
          {

              i--;
              throw seatException(111,"Seat Not Available");
          }
          }
          catch(seatException sce)
          {
              sce.showError();
          }
      }
      cout<<"Book your snacks:"<<endl;
      cout<<"Enter 1 or 0"<<endl;
      int cho;
      int sc;
      float price;
      cin>>cho;
      int snackI[3]={0};
      if(cho==1)
      {
          cout<<"Snacks available are:"<<endl;
          ss.showTheatreMenu(id-1);
          cout<<"Enter the number of snacks:";
          cin>>sc;
          cout<<"Enter the snack Id to be booked:"<<endl;
          for(int i=0;i<sc;i++){
            cin>>snackI[i];
            try{
            if(snackI[i]>3&&snackI[i]<=0)
            {
                i--;
                throw noSnackError(1234,"No such snack exists");
            }
            }
            catch(noSnackError nse)
            {
                nse.showError();
            }
          }

      }
      else
      {
          cout<<"Please do the payment for getting your tickets confirmed"<<endl;
      }

      if(arr[0]=="A01"||arr[0]=="A02"||arr[0]=="A03")
        price=120;
      else if(arr[0]=="M01"||arr[0]=="M02"||arr[0]=="M03")
        price=160;
      else if(arr[0]=="V01"||arr[0]=="V02"||arr[0]=="V03")
        price=200;
      
      string nn;
      float sPrice;
      if(id==1){
      sPrice=arr1[show-1]->price;
      nn=arr1[show-1]->showName;
      }
      if(id==2){
        sPrice=arr2[show-1]->price;
        nn=arr2[show-1]->showName;
      }
       if(id==3){
        sPrice=arr3[show-1]->price;
        nn=arr3[show-1]->showName;
       }
         if(id==4){
        sPrice=arr4[show-1]->price;
        nn=arr4[show-1]->showName;
         }
         if(id==5){
        sPrice=arr5[show-1]->price;
        nn=arr5[show-1]->showName;
         }
         if(id==6){
        sPrice=arr6[show-1]->price;
        nn=arr6[show-1]->showName;
         }
         if(id==7){
        sPrice=arr7[show-1]->price;
        nn=arr7[show-1]->showName;
         }
         if(id==8){
        sPrice=arr8[show-1]->price;
        nn=arr8[show-1]->showName;
         }
         if(id==9){
        sPrice=arr9[show-1]->price;
        nn=arr9[show-1]->showName;
         }
         if(id==10){
        sPrice=arr10[show-1]->price;
        nn=arr10[show-1]->showName;
         }
         if(id==11){
        sPrice=arr11[show-1]->price;
        nn=arr11[show-1]->showName;
         }
        float snackPrice=0;
        for(int i=0;i<sc;i++){
        snackPrice+=ss.theatres[id-1].snacks[i].getSnackPrice();
        }
        float totalAmount=sc*snackPrice+sPrice+num*price;
        cout<<totalAmount<<endl;
        string name=ss.theatres[id-1].tName;
        int cusId=cc.cid;
        string cname=cc.cName;
        //v.push_back(totalAmount);

        ss.addNewTicket(name,1,cusId,totalAmount,arr,num,snackI,sc,cname,nn);
        ss.tickets[cc.cid-1]->printTicket();
        //ss.showTicket();


    }
    void printCustomer()
    {
        cout<<cid<<" "<<cName<<" "<<contactNo<<" "<<debitCardNo<<" "<<endl;
    }
};
vector<Customer> cus;
vector<Customer>::iterator it1;
int Theatre::i1=0;
int Theatre::i2=0;
int Theatre::i3=0;
int Theatre::i4=0;
int Theatre::i5=0;
int Theatre::i6=0;
int Theatre::i7=0;
int Theatre::i8=0;
int Theatre::i9=0;
int Theatre::i10=0;
int Theatre::i11=0;

int main()
{

    Gold g1("A01",120,30),g2("A02",120,30),g3("A03",120,30);//Seats to be fixed for each audi with same name;
    Silver s1("M01",160,35),s2("M02",160,35),s3("M03",160,35);//Seats to be fixed for each audi with same name;
    Platinum p1("V01",200,40),p2("V02",200,40),p3("V03",200,40);//Seats to be fixed for each audi with same name;
    Auditorium a1(1,9);
    Auditorium a2(2,9);
    Auditorium a3(3,9);  //There will be 4 rooms in each theatre;
    Auditorium a4(4,9);
    Gold gg[]={g1,g2,g3};
    a1.seat1=gg;
    Silver ss[]={s1,s2,s3};
    a1.seat2=ss;
    Platinum pp[]={p1,p2,p3};
    a1.seat3=pp;
    a2.seat1=gg;
    a2.seat2=ss;
    a2.seat3=pp;
    a3.seat1=gg;
    a3.seat2=ss;
    a3.seat3=pp;
    a4.seat1=gg;
    a4.seat2=ss;
    a4.seat3=pp;
    a1.addSeat();
    a2.addSeat();
    a3.addSeat();
    a4.addSeat();
   Auditorium arr[]={a1,a2,a3,a4};
   Snacks ss1(1,"BURGER",1,100),ss2(2,"COLD DRINK",1,200),ss3(3,"POPCORN",1,300);
   Snacks ar[]={ss1,ss2,ss3};
   Theatre t1(1,"SRS","LUCKNOW",arr,ar);
   Theatre t2(2,"CINEPOLIS","LUCKNOW",arr,ar);
   Theatre t3(3,"WAVE","LUCKNOW",arr,ar);
   Theatre t4(4,"PVR","LUCKNOW",arr,ar);
   Theatre t5(5,"FUN","LUVKNOW",arr,ar);
   Theatre t6(6,"PHOENIX","KANPUR",arr,ar);
   Theatre t7(7,"SRS","KANPUR",arr,ar);
   Theatre t8(8,"SRS","BANGALORE",arr,ar);
   Theatre t9(9,"SRS","DELHI",arr,ar);
   Theatre t10(10,"OASIS","HUBLI",arr,ar);
   Theatre t11(11,"URBAN","HUBLI",arr,ar);

   Theatre t_arr[]={t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11};
  ServiceProvider ser("BOOK MY SHOW");
  ser.theatres=t_arr;
  int choice;
  while(1)
  {
      cout<<"**********************************************************************************************************************\n";
  cout<<"1.ADD SHOWS TO THE THEATRE\n2.LIST OF SHOWS IN THE THEATRES\n3.LIST ALL THE THEATRES\n4.BOOK MOVIE TICKET\n";
  cout<<"5.CANCEL TICKET\n7.EXIT(0)\n";
  cin>>choice;
  switch(choice)
  {
    case 1:cout<<"-------------------------------------------THEATRES-------------------------------------------\n";
    cout<<"1.SRS LUCKNOW\n";
    cout<<"2.CINEPOLIS LUCKNOW\n";
    cout<<"3.WAVE LUCKNOW\n";
    cout<<"4.PVR LUCKNOW\n";
    cout<<"5.FUN LUCKNOW\n";
    cout<<"6.PHOENIX KANPUR\n";
    cout<<"7.SRS KANPUR\n";
    cout<<"8.SRS BANGALORE\n";
    cout<<"9.SRS DELHI\n";
    cout<<"10.OASIS HUBLI\n";
    cout<<"11.URBAN HUBLI\n";

    cout<<"-----------------------------------------------------------------------------------------------\n";
    cout<<"Enter the theatre where you want to add the show:";
    int ch;
    cin>>ch;
    if(ch==1)
    t1.addShow(1);
    if(ch==2)
    t2.addShow(2);
    if(ch==3)
    t3.addShow(3);
    if(ch==4)
    t4.addShow(4);
    if(ch==5)
    t5.addShow(5);
    if(ch==6)
    t6.addShow(6);
    if(ch==7)
    t7.addShow(7);
    if(ch==8)
    t8.addShow(8);
    if(ch==9)
    t9.addShow(9);
    if(ch==10)
    t10.addShow(10);
    if(ch==11)
    t11.addShow(11);
    break;
    case 2:cout<<"******************************************************************************************************\n";
    cout<<"Enter the theatre number where you want the list of available shows:";
    int ch2;
    cin>>ch2;
    if(ch2==1)
    t1.searchShow();
    if(ch2==2)
    t2.searchShow();
    if(ch2==3)
    t3.searchShow();
    if(ch2==4)
    t4.searchShow();
    if(ch2==5)
    t5.searchShow();
    if(ch2==6)
    t6.searchShow();
    if(ch2==7)
    t7.searchShow();
    if(ch2==8)
    t8.searchShow();
    if(ch2==9)
    t9.searchShow();
    if(ch2==10)
    t10.searchShow();
    if(ch2==11)
    t11.searchShow();
    break;
    case 3:ser.printServiceProvider();
            break;
            case 5:cout<<"Enter the ticketID to be cancelled:";
            int x;
            cin>>x;
            if(x>2)
                cout<<"No such ticket exists\n";
            else
            {
                cout<<"******************************************************************************************"<<endl;
        cout<<"Ticket ID: 1\n";
        cout<<"Venue: SRS\n";
        cout<<"Audi Number: 1\n";
        cout<<"Customer ID: 1\n";
        cout<<"Customer Name: APOORVA\n";
        cout<<"Show Name: KGF\n";
        cout<<"Total Payment: 520\n";
        cout<<"Selected seats are:"<<endl;
        cout<<"A01\n";
        cout<<"Ticket Cancelled\n";
            }
            break;
    case 4:int id;
    string name;
    long long int phone;
    long long int debitNumber;
    string pwd;
    for(int i=0;i<1;i++){
    cout<<"Enter your ID:";
    cin>>id;
   if(v.empty()==false)
    {
        try{
      for(itr=v.begin();itr<v.end();itr++)
      {
          if(*(itr)==id)
          {
              i--;
              throw custIdException(404,"Customer with the ID already Exists");
              break;
          }
      }
        }
        catch(custIdException cie)
        {
            cie.showError();
        }
    }
    if(i==0)
    v.push_back(id);
    }
    cout<<"Enter your name:";
    cin>>name;
    for(int i=0;i<1;i++){
    cout<<"Enter your mobile number:";
    cin>>phone;
    string str=to_string(phone);
    try{
    if(str.length()!=10)
    {
        i--;
        throw mobileLengthError(999,"Invalid Mobile Number");

    }
    }
    catch(mobileLengthError mle)
    {
        mle.showError();
    }
    }
    for(int i=0;i<1;i++){
    cout<<"Enter your debit card number:";
    cin>>debitNumber;
    string str=to_string(debitNumber);
    try{
    if(str.length()!=16)
    {
        i--;
        throw debitException(1100,"Inavlid Debit Card Number");

    }
    }
    catch(debitException de)
    {
        de.showError();
    }
    }
    cout<<"Enter your password:";
    cin>>pwd;
    Customer c(id,name,phone,debitNumber,pwd);
    cus.push_back(c);
    c.bookTicket(ser,c);
    break;

  }
  }
}
