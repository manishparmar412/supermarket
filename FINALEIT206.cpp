//////////////    FINAL ASSIGNMENT - IT206      ////////////////////
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/////////////////////////////////   INVENTORY DATASET    /////////////////////////////////////////

long long INVENTORY_DATASET[100][4] ={{111100000001,1,100,20},{111100000002,2,110,20},{111100000003,3,120,20},{111100000004,4,130,20},
{111100000005,5,140,20},{111100000006,6,150,20},{111100000007,7,160,20},{111100000008,8,170,20},{111100000009,9,180,20},
{111100000010,10,190,20}, {111100000011,11,200,20},{111100000012,12,210,20},{111100000013,13,220,20},{111100000014,14,230,20},
{111100000015,15,240,20},{111100000016,16,250,20},{111100000017,17,260, 20},{111100000018,18,270,20},{111100000019,19,280,20},
{111100000020,20,290,20}, {111100000021,21,300,20},{111100000022,22,310,20},{111100000023,23,320,20},{111100000024,24,330,20},
{111100000025,25,340,20},{111100000026,26,350,20},{111100000027,27,360, 20},{111100000028,28,370,20},{111100000029,29,380,20},
{111100000030,30,390,20}, {111100000031,31,400,20},{111100000032,32,410,20},{111100000033,33,420,20},{111100000034,34,430,20},
{111100000035,35,440,20},{111100000036,36,450,20},{111100000037,37,460, 20},{111100000038,38,470,20},{111100000039,39,480,20},
{111100000040,40,490,20}, {111100000041,41,500,20},{111100000042,42,510,20},{111100000043,43,520,20},{111100000044,44,530,20},
{111100000045,45,540,20},{111100000046,46,550,20},{111100000047,47,560, 20},{111100000048,48,570,20},{111100000049,49,580,20},
{222200001111,50,590,20}, {222200001114,51,600,20},{222200001117,52,610,20},{222200001120,53,620,20},{222200001123,54,630,20},
{222200001126,55,640,20},{222200001129,56,650,20},{222200001132,57,660, 20},{222200001135,58,670,20},{222200001138,59,680,20},
{222200001141,60,690,20}, {222200001144,61,700,20},{222200001147,62,710,20},{222200001150,63,720,20},{222200001153,64,730,20},
{222200001156,65,740,20},{222200001159,66,750,20},{222200001162,67,760, 20},{222200001165,68,770,20},{222200001168,69,780,20},
{222200001171,70,790,20}, {222200001174,71,800,20},{222200001177,72,810,20},{222200001180,73,820,20},{222200001183,74,830,20},
{222200001186,75,840,20},{222200001189,76,850,20},{222200001192,77,860, 20},{222200001195,78,870,20},{222200001198,79,880,20},
{222200001201,80,890,20}, {222200001204,81,900,20},{222200001207,82,910,20},{222200001210,83,920,20},{222200001213,84,930,20},
{222200001216,85,940,20},{222200001219,86,950,20},{222200001222,87,960, 20},{222200001225,88,970,20},{222200001228,89,980,20},
{222200001231,90,990,20}, {222200001234,91,1000,20},{222200001237,92,1010,20},{222200001240,93,1020,20},{222200001243,94,1030,20},
{222200001246,95,1040,20},{222200001249,96,1050,20},{222200001252, 97,1060,20},{222200001255,98,1070,20},{222200001258,99,1080,20},
{222200001261,100,1090,20}}; 

//////////////////////////////////////////  CUSTOMER DATASET     /////////////////////////////////////


long long CUSTOMER_DATASET[100][3] ={{9400000001,1,0},{9400000002,2,0},{9400000003,3,0},{9400000004,4,0},{9400000005,5,0},
{9400000006,6,0},{9400000007,7,0},{9400000008,8,0},{9400000009,9,0},{9400000010,10,0},{9400000011,11,0},{9400000012,12,0},
{9400000013,13,0},{9400000014,14,0},{9400000015,15,0},{9400000016,16,0},{9400000017,17,0},{9400000018,18,0},{9400000019,19,0},
{9400000020,20,0}, {9400000021,21,0},{9400000022,22,0},{9400000023,23,0},{9400000024,24,0},{9400000025,25, 0},{9400000026,26,0},
{9400000027,27,0},{9400000028,28,0},{9400000029,29,0},{9400000030, 30,0}, {9400000031,31,0},{9400000032,32,0},{9400000033,33,0},
{9400000034,34,0},{9400000035,35, 0},{9400000036,36,0},{9400000037,37,0},{9400000038,38,0},{9400000039,39,0},{9400000040, 40,0},
{9400000041,41,0},{9400000042,42,0},{9400000043,43,0},{9400000044,44,0},{9400000045,45, 0},{9400000046,46,0},{9400000047,47,0},
{9400000048,48,0},{9400000049,49,0},{9400000050, 50,0}, {9400000051,51,0},{9400000052,52,0},{9400000053,53,0},{9400000054,54,0},
{9400000055,55, 0},{9400000056,56,0},{9400000057,57,0},{9400000058,58,0},{9400000059,59,0},{9400000060, 60,0}, {9400000061,61,0},
{9400000062,62,0},{9400000063,63,0},{9400000064,64,0},{9400000065,65, 0},{9400000066,66,0},{9400000067,67,0},{9400000068,68,0},
{9400000069,69,0},{9400000070, 70,0}, {9400000071,71,0},{9400000072,72,0},{9400000073,73,0},{9400000074,74,0},{9400000075,75, 0},
{9400000076,76,0},{9400000077,77,0},{9400000078,78,0},{9400000079,79,0},{9400000080, 80,0}, {9400000081,81,0},{9400000082,82,0},
{9400000083,83,0},{9400000084,84,0},{9400000085,85, 0},{9400000086,86,0},{9400000087,87,0},{9400000088,88,0},{9400000089,89,0},
{9400000090, 90,0}, {9400000091,91,0},{9400000092,92,0},{9400000093,93,0},{9400000094,94,0},{9400000095,95, 0},{9400000096,96,0},
{9400000097,97,0},{9400000098,98,0},{9400000099,99,0},{9400000100,100,0},}; 


class Item   ///// FOR INVENTORY DATASET
{
  public:
  long long item_id;
  string name;
  int quantity;
  float rate;
  int TEMP;
  Item* next;
  Item()
  {
    item_id=0;
    name="";
    quantity=0;
    rate=0.0;
    next=NULL;
  }
  Item(long long id,long long s,long long q,long long r)
  {
    item_id=id;
    TEMP=(int)s;
    name=to_string(TEMP);
    quantity=(int)q;
    rate=(float)r;
    next=NULL;
  }
};

/////
class Item1   ///// FOR CUSTOMER DATASET
{
  public:
  long long item_id;
  string name;
  int quantity,TEMP;
  float rate;
  int amount;
  Item1* next;
  Item1()
  {
    item_id=0;
    name="";
    quantity=0;
    rate=0.0;
    amount=0;
    next=NULL;
  }
  Item1(long long id,string s,int q,int r,int a)
  {
    item_id=id;
    name=s;
    quantity=(int)q;
    rate=(float)r;
    amount=a;
    next=NULL;
  }
};

class item_list
{
public:
    Item* head;
    item_list()
    {
        head=NULL;
    }

};
class item1_list
{
public:
    Item1* head;
    item1_list()
    {
        head=NULL;
    }
};

/////////////////////

class Inventory
{
  //friend class Manager;
public:
  item_list l1[100];
  int p,i;
  Item* temp;
  Item* tmp;
  void add_items()
  {
    for(i=0;i<100;i++)
    {
        p=INVENTORY_DATASET[i][0] % 100;
        temp=new Item(INVENTORY_DATASET[i][0],INVENTORY_DATASET[i][1],INVENTORY_DATASET[i][3],INVENTORY_DATASET[i][2]);
        tmp=l1[p].head;
        if(tmp==NULL)
        {
            l1[p].head=temp;
        }
        else
        {
           while(tmp->next!=NULL)
           {
            tmp=tmp->next;
           }
           tmp->next=temp;
        }
    }
    temp=NULL;
  }
  void Delete_item(Item* temp,int q)
  {
   (temp->quantity) = (temp->quantity)- q;
  }
  void add_item(Item* temp,int m)
  {
   (temp->quantity) = (temp->quantity) + m;
  }
  void update_item(int new_rate,int new_quantity,long long item_id)
  {
      Item* temp=new Item();
      p= item_id % 100;
      temp=l1[p].head;
      if(temp==NULL)
      cout<<"NOT FOUND"<<endl;
      else
      {
      while(temp!=NULL && temp->item_id!=item_id)
      {
        temp=temp->next;
      }
      if(temp==NULL)
      cout<<"NOT FOUND"<<endl;  
      else if(temp->item_id==item_id)
      {
        temp->rate=new_rate;
        temp->quantity=new_quantity;
      }
      }
  }
  
public:
  void update_stock(Item* tem,int q,int m)
  {
      Delete_item(tem,q);
      add_item(tem,m);
  }
  void get_product_info(long long A[],int n)
  {
    int i,p;
    Item* temp=new Item();
    cout<<" Item Information of updated Items : "<<endl;
    cout<<" Item ID     "<<" Item_Name  "<<" Item_Quantity "<<endl; 
    for(i=0;i<n;i++)
    {
      p= A[i] % 100;
      temp=l1[p].head;
      if(temp==NULL)
      cout<<"NOT FOUND"<<endl;
      else
      {
      while(temp!=NULL && temp->item_id!=A[i])
      {
        temp=temp->next;
      }
      if(temp==NULL)
      cout<<"NOT FOUND"<<endl;  
      else if(temp->item_id==A[i])
      cout<<" "<<temp->item_id<<"    "<<temp->name<<"          "<<temp->quantity<<"    "<<endl;
      }

    }
  }
  void printList()
  {
          for(i=0;i<100;i=i+2)
          {
          Item *temp=l1[i].head;
          while(temp!=NULL)
          {
            cout<<"("<<temp->item_id<<","<<temp->name<<", "<<temp->quantity<<")  "<<endl;
            temp=temp->next;
          }
        }
  }

};

////////////////

class Node 
{
public:
    long long customer_id;
    string name;
    int temp,points;

    Node* next;
    Node()
    {
        customer_id=0;
        name="";
        points=0;
        next=NULL;
    }
    Node(long long ID,long long s,long long point)
    {
        customer_id=ID;
        temp=(int)s;
        name=to_string(temp);
        points=(int)point;
        next=NULL;
    }
};


////////////////////////////////

class Singlylinkedlist
{
public:
    Node* head;
    Singlylinkedlist()
    {
        head=NULL;
    }

    Singlylinkedlist(Node *n)
    {
        head=n;
    }

};

/////////////////////////////////

class Customer
{
   
   public:
    long long customer_id;
    string Name;
    int p,i;
    Node* temp;
    Node* tmp;
    Singlylinkedlist c1[100];
    int points;
    Customer()
    {
      points=0;
    }
    void add_customers()
    {
     for(i=0;i<100;i++)
     {
        p=CUSTOMER_DATASET[i][0] % 100;
        temp=new Node(CUSTOMER_DATASET[i][0],CUSTOMER_DATASET[i][1],CUSTOMER_DATASET[i][2]);
        tmp=c1[p].head;
        if(tmp==NULL)
        {
            c1[p].head=temp;
        }
        else
        {
           while(tmp->next!=NULL)
           {
            tmp=tmp->next;
           }
           tmp->next=temp;
        }
     }
    }

    void update_customer(string new_name,long long customer_id)
    {
      Node* temp=new Node();
      p= customer_id % 100;
      temp=c1[p].head;
      if(temp==NULL)
      cout<<"NOT FOUND"<<endl;
      else
      {
      while(temp!=NULL && temp->customer_id!=customer_id)
      {
        temp=temp->next;
      }
      if(temp==NULL)
      cout<<"NOT FOUND"<<endl;  
      else if(temp->customer_id==customer_id)
      {
        temp->name=new_name;
      }
      }
    }
    
    void update_points(Item* T,int q,int m)
    {
        points=points+(T->rate)*q-((T->rate)*m);
    }
};
Customer c1;
Inventory I1;
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

class Billing : public Customer,public Inventory
{
public:
  long transaction_id;
  int total_amount;
  long long Customer_id;
   int p;
  item1_list l2[10];
  Billing()
  {
      transaction_id=2120201528;
      total_amount=0;
  }
  Item* buy_item(long long ID,int q)
  {
      p =ID % 100;
      //cout<<p<<endl;
       Item* tem=new Item();
      tem=I1.l1[p].head;
      //cout<<tem->rate<<endl;
     if(tem==NULL)
     cout<<"ITEM NOT FOUND"<<endl;
     else
     {
      while(tem!=NULL && tem->item_id!=ID)
      {
        tem=tem->next;
      }
      if(tem==NULL)
      cout<<"ITEM NOT FOUND"<<endl;
      else if((tem->quantity)<q)
      {
      cout<<"THERE IS NO ENOUGH ITEMS"<<endl;
      return NULL;
      }
      else if(tem->item_id==ID)
      {
	      int old_quantity=tem->quantity;
	      update_stock(tem,q,0);
	      p=ID % 10;
	      Item1* Temp=new Item1();
	      Item1* New=new Item1(tem->item_id,tem->name,old_quantity-tem->quantity,tem->rate,(old_quantity-tem->quantity)*(tem->rate));
	      total_amount=total_amount + (old_quantity-tem->quantity)*(tem->rate);
	      Temp=l2[p].head;
	      if(Temp==NULL)
	      {
	          l2[p].head=New;
	      }
	      else
	      {
	        while(Temp->next!=NULL)
	        {
	          Temp=Temp->next;
	        }
	          Temp->next=New;
	      }
      
      }
    }
    return tem;
  }

  Item* cancel_item(long long ID,int q)
  {
      p =ID % 100;
      //cout<<p<<endl;
      Item* tem=new Item();
      tem=I1.l1[p].head;
      //cout<<tem->rate<<endl;
    if(tem==NULL)
    cout<<"ITEM NOT FOUND"<<endl;
    else
    {
      while(tem!=NULL && tem->item_id!=ID)
      {
        tem=tem->next;
      }
      if(tem==NULL)
      cout<<"ITEM NOT FOUND"<<endl;
      else if((tem->quantity)<q)
      {
      cout<<"THERE IS NO ENOUGH ITEMS"<<endl;
      return NULL;
      }
      else if(tem->item_id==ID)
      {
      int old_quantity=tem->quantity;
      update_stock(tem,0,q);
      p=ID % 10;
      Item1* Temp=new Item1();
      //Item1* New=new Item1(tem->item_id,tem->name,tem->quantity-old_quantity,tem->rate,);
      total_amount=total_amount - (tem->quantity-old_quantity)*(tem->rate);
      Temp=l2[p].head;
      if(Temp==NULL)
      {
          cout<<" Item Not Found "<<endl;
      }
      else
      {
        while(Temp->next!=NULL && Temp->item_id!=ID)
        {
          Temp=Temp->next;
        }
        if(Temp==NULL)
        cout<<"ITEM NOT FOUND"<<endl;
        else if(Temp->item_id==ID)
        {
            Temp->quantity=Temp->quantity-q;
            Temp->amount=Temp->amount-(tem->quantity-old_quantity)*(tem->rate);
        }
      }
      
      
      }
    }
    return tem;
  }
  
  
  long long assign_customer_id(string name)
  {
    Node* New_Customer=new Node();
    Node* temp=c1[0].head;
    New_Customer->name=name;
    New_Customer->points=0;
    if(temp==NULL)
    {
      c1[0].head=New_Customer;
      New_Customer->customer_id=111122223333;
    }
    else
    {
      while(temp->next!=NULL)
      {
        temp=temp->next;
      }
      New_Customer->customer_id = temp->customer_id + 100;
      temp=New_Customer;
    }
    return New_Customer->customer_id;
  }
  void make_payment(long long ID)
  {
   Customer_id=ID;
   cout<<endl;
   cout<<endl;
   cout<<"                       ROYAL  SUPER-STORE      "<<endl;
   cout<<endl<<"                       BILL "<<endl;
   cout<<endl;
   cout<<" Customer ID :  "<<Customer_id<<endl;
   cout<<" Transaction ID : "<<transaction_id<<endl;
   cout<<endl;
   cout<<"   Product_ID      Product Name      Rate     Quantity     Amount    "<<endl;
   cout<<endl;
   for(int i=0;i<10;i++)
   {
       Item1* temp=l2[i].head;
          while(temp!=NULL)
          {
            cout<<"  "<<temp->item_id<<"           "<<temp->name<<"          "<<temp->rate<<" Rs.         "<<temp->quantity<<"       "<<temp->amount<<" Rs."<<endl;
            temp=temp->next;
          }
   }
   cout<<"                                                   Total Amount = "<<total_amount<<" Rs."<<endl;
   
  }


};
Billing b1;

class Manager:public Inventory
{

public:
  
  long long ID;
  string name;

};

////////////////////////////////
////////////////////////////////
int main()
{
    long long customer_id,item_ID;
    long long item_ids1[100];
    int n,i,q,choice,N;
    Manager m1;
    Item* temp;
    string Name;
    m1.ID=201901167;
    m1.name="Manish";
    I1.add_items();
    c1.add_customers();
    cout<<"If customer is new customer then press 1 else press 0."<<endl;
    cin>>choice;
    if(choice==1)
    {
    cout<<"Enter customer's Name"<<endl;
    cin>>Name;  
    customer_id=b1.assign_customer_id(Name);
    }
    else
    {
    cout<<"Enter Customer ID"<<endl;
    cin>>customer_id;
    //customer_id=9400000013;
    }
    cout<<"How many Items customer wanna buy"<<endl;
    cin>>n;
    m1.printList();
    for(i=0;i<n;i++)
    {
      cout<<"Enter the Item Id of the item customer wanna buy"<<endl;
      cin>>item_ID;
      cout<<"Enter the quantity"<<endl;
      cin>>q;
     temp=b1.buy_item(item_ID,q);
     if(temp!=NULL)
     {
     c1.update_points(temp,q,0);
     cout<<" Total Amount till now : "<<c1.points<<endl;
     item_ids1[i]=item_ID;
     }

    }

    cout<<"How many Items customer wanna cancel?"<<endl;
    cin>>N;
    for(i=0;i<N;i++)
    {
      cout<<"Enter the Item Id of the item customer wanna cancel"<<endl;
      cin>>item_ID;
      cout<<"Enter the quantity"<<endl;
      cin>>q;
     temp=b1.cancel_item(item_ID,q);
     if(temp!=NULL)
     {
     c1.update_points(temp,0,q);
     cout<<" Total Amount till now : "<<c1.points<<endl;
     
     }
    }
    I1.get_product_info(item_ids1,n);
    b1.make_payment(customer_id);
    
    return 0;
}