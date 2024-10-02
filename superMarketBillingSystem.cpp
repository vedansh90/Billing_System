#include<iostream>
#include<unistd.h>
#include<fstream>
#include<sstream>
#include<time.h>
#include<random>
using namespace std;

class manager{

public:
string itemName;
int Rate;
int Quantity;

public:
manager():itemName(""), Rate(0), Quantity(0) {}

void setItem(string item){
    itemName = item;
}

void setRate(int rate){
    Rate = rate;
}

void setQuant(int quant){
    Quantity = quant;
}

string getItem(){
    return itemName;
}

int getRate(){
    return Rate;
}

int getQuant(){
    return Quantity;
}
};


void addItem(manager m){

bool exit = false;

while(exit == false){
string item;
int rate;
int quantity;

system("cls");
cout << "\t**********************************\t" << endl;
cout << "\t" << "\tWelcome to D-Mart\t" << endl;
cout << "\t**********************************\t" << endl;

cout << "\tEnter item name: ";
cin >> item;
m.setItem(item);

cout << "\tEnter rate: ";
cin >> rate;
m.setRate(rate);

cout << "\tEnter Quantity: ";
cin >> quantity;
m.setQuant(quantity);

ofstream out("D:/itemRecords.txt", ios::app); 

if(!out){
    cout << "Enable to Open File" << endl;
}
else{
    out << m.getItem() << " : " << m.getRate() << " : " << m.getQuant() << endl;
}
out.close();

cout << "\tItem Added Successfully" << endl;
sleep(2);
cout << endl;
cout << "\t1.Add item" << endl;
cout << "\t2.Exit" << endl;
int choice2;
cout << "\tEnter Choice: ";
cin >> choice2;
if(choice2 == 2){
    exit = true;
}

}
system("cls");
cout << "\tBack to Main menu" << endl;
sleep(3);

system("cls");
cout << "\t**********************************\t" << endl;
cout << "\t" << "\tWelcome to D-Mart\t" << endl;
cout << "\t**********************************\t" << endl;

cout << "\t1.Customer" << endl;
cout << "\t2.Manager" << endl;
cout << "\t3.Close" << endl;
}


void billing(manager m){

bool close = false;

system("cls");
cout << "\t**********************************\t" << endl;
cout << "\t" << "\tWelcome to D-Mart\t" << endl;
cout << "\t**********************************\t" << endl;

cout << "\t1.Add item on Bill" << endl;
cout << "\t2.Print Bill" << endl;
int totalAmount = 0;
while(close == false){
int choice1;
cout << "\tEnter Choice: ";
cin >> choice1;

if(choice1 == 2){
    //printig bill 
    close = true;
   string cusName;
   string phoneNo;
   cout << "\tEnter your Name: ";
   cin >> cusName;
   cout << "\tEnter your Phone no.:";
   cin >> phoneNo;
         
srand(time(0));
long long randomNumber = rand() %  600000;

system("cls");
    cout << "\t**********************************\t" << endl;
    cout << "\t" << "\tWelcome to D-Mart\t" << endl;
    cout << "\t**********************************\t" << endl;
    cout << endl;
    cout << "\t__________________________________________________________" << endl;
    cout << "\t|                       Bill by D-Mart                   |" << endl;
    cout << "\t|________________________________________________________|" << endl;
    cout << "\t|                                                        |" << endl;
    cout << "\t| Customer Name: " <<cusName  << endl; 
    cout << "\t| Mobile Number: " <<phoneNo <<  endl; 
    cout << "\t|                                                        |" << endl;
    cout << "\t| Total Amount : " <<totalAmount<< "\t" << "\t"  << "\t" <<"                 |" << endl;
    cout << "\t|                                                        |" << endl;
    cout << "\t|                                                        |" << endl;
    cout << "\t|                                      Customer ID -" << randomNumber <<"|" << endl; 
    cout << "\t|                                                        |" << endl;
    cout << "\t|           Thank you, Hope to see you Again             |" << endl;
    cout << "\t**********************************************************" << endl;
    cout << endl;
    cout << "\tBack To main menu" << endl;
    sleep(5);

  
system("cls");
cout << "\t**********************************\t" << endl;
cout << "\t" << "\tWelcome to D-Mart\t" << endl;
cout << "\t**********************************\t" << endl;

cout << "\t1.Billing" << endl;
cout << "\t2.Close" << endl;
}

if(choice1 == 1){
   
    bool found = false;
   
system("cls");
cout << "\t**********************************\t" << endl;
cout << "\t" << "\tWelcome to D-Mart\t" << endl;
cout << "\t**********************************\t" << endl;


    string item;
    cout << "\tEnter Item name: ";
    cin >> item;
    int quant;
    cout << "\tEnter Quantity: ";
    cin >> quant;

    string line;
    ifstream in("D:/itemRecords.txt");
    ofstream out("D:/itemRecordsTemp.txt");
   
    
    while(getline(in, line)){
        stringstream ss;
        ss<<line;
       
       string itemName;
       int Rate;
       int Quantity;
       char delimiter;
  
   ss >> itemName >> delimiter >> Rate >> delimiter >> Quantity ;
        if(item == itemName){
           found = true;
           if(quant <= Quantity){
            int amount = Rate*quant;
             totalAmount = totalAmount + amount;

             cout << "\tItem | Rate | Quantity | Amount" << endl;
             cout << "\t" <<item << "'\t" << Rate << "\t" << quant << "\t" << amount << endl; 
             
             int newQuantity = Quantity - quant;
             Quantity = newQuantity;

             out<<"\t" << itemName <<" : " << Rate <<" : " << Quantity << endl ;
              cout << "\tItem Added Successfully" << endl;
              sleep(2);

           }
           else{
            //item ki quantity khatam ho gayi
            cout << "\tSorry  " <<item << "  Ended" << endl;
            sleep(2);
           }
        }
        else{
            // item khatam ho gaya
            out<<line;
        }
    }

    if(found == false){
        cout << "\tItem Not Available" << endl;
        sleep(2);
    }
  
  out.close();
  in.close();
  remove("D:/itemRecords");
  rename("D:/itemRecordsTemp", "D:/itemRecords");

system("cls");
cout << "\t**********************************\t" << endl;
cout << "\t" << "\tWelcome to D-Mart\t" << endl;
cout << "\t**********************************\t" << endl;

cout << "\t1.Add item on Bill" << endl;
cout << "\t2.Print Bill" << endl;
   

}
}


}

int main(){

manager m;

bool close = false;
while(close == false){
system("cls");
cout << "\t**********************************\t" << endl;
cout << "\t" << "\tWelcome to D-Mart\t" << endl;
cout << "\t**********************************\t" << endl;
cout << endl;
cout << "\t1. Customer "<< endl;     
cout << "\t2. Manager " << endl;


//choice is for customer and manager
int choice;
cout << "\tEnter choice: ";
cin >> choice;


// for manager section
if(choice == 2){
  
system("cls");
cout << "\t**********************************\t" << endl;
cout << "\t" << "\tWelcome to D-Mart\t" << endl;
cout << "\t**********************************\t" << endl;


string managerID = "123@vedansh", manager;
int passCode = 23851, pass;


cout << "\tEnter Manager Id: ";
cin >> manager;

//edit from here
if(manager == managerID){

cout << "\tEnter Password: ";
cin >> pass;
   if(pass == passCode){
     
   
system("cls");
cout << "\t**********************************\t" << endl;
cout << "\t" << "\tWelcome to D-Mart\t" << endl;
cout << "\t**********************************\t" << endl;
cout << "\t1.Add item" << endl;
cout << "\t2.Shut Down" << endl;
cout << "\t3.Exit" << endl;
int choice1;
cout << "\tEnter Choice:";
cin>>choice1;

//for Shut down section
if(choice1 == 3){
   system("cls");
cout << "\t**********************************\t" << endl;
cout << "\t" << "\tWelcome to D-Mart\t" << endl;
cout << "\t**********************************\t" << endl;
cout << endl;
cout << "\t1. Customer "<< endl;     
cout << "\t2. Manager " << endl;

}
//for add items in the mart
if(choice1 == 1){
 addItem(m);
}
if(choice1 == 2){
    //shut down the system
close = true;
system("cls");
cout << "\t********************************************" << endl;
cout << "\t\t* Shuting Down the System *" << endl;
cout << "\t********************************************" << endl;
sleep(3);
system("cls");
}

   

   }
   else{
    cout << "\tInvalid Password" << endl;
    sleep(2);
    system("cls");
cout << "\t**********************************\t" << endl;
cout << "\t" << "\tWelcome to D-Mart\t" << endl;
cout << "\t**********************************\t" << endl;
cout << endl;
cout << "\t1. Customer "<< endl;     
cout << "\t2. Manager " << endl;

   }

}
else{
    cout << "\tInvalid ID" << endl;
    sleep(3);
    system("cls");
cout << "\t**********************************\t" << endl;
cout << "\t" << "\tWelcome to D-Mart\t" << endl;
cout << "\t**********************************\t" << endl;
cout << endl;
cout << "\t1. Customer "<< endl;     
cout << "\t2. Manager " << endl;
}






}

//for customer section
if(choice == 1){
system("cls");
cout << "\t**********************************\t" << endl;
cout << "\t" << "\tWelcome to D-Mart\t" << endl;
cout << "\t**********************************\t" << endl;

cout << "\t1.Billing" << endl;
cout << "\t2.Close" << endl;

bool Close = false;
while(Close == false){

int choice3;
cout << "\tEnter choice: ";
cin >> choice3;

if(choice3 == 1){

   billing(m);
}

if(choice3 == 2){
    cout << "\tBack to Main Menu" << endl;
    sleep(2);
   Close = true;

}
}
}

}

    return 0;
}