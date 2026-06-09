#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void menuList();
void addMenulist();
void Firstchoose();
void Custemer_class();
void Admin_class();
void passVerification();
void CustomerFood();
// Updated to accept the full accumulated items string and the overall subtotal
void receiptBill (string accumulatedItems, float overallSubtotal);
void cash_method(string name, string accumulatedItems, float overallSubtotal, int method);
void payment_changer(int method);

int main()
{
    /*front page of the restaurant */
    cout<<"\t\t==================================================\n";
    cout<<"\t\t       ETHIOPIAN RESTAURANT MANAGEMENT SYSTEM     \n";
    cout<<"\t\t==================================================\n";

    cout<<"\t\tWelcome to Ethiopian Restaurant Management system \n";
    Firstchoose();

    return 0;
}

void Firstchoose()
{
    cout<<"-------------------------------------------------";
    cout<<"\n\t [1] Customer Order \n";
    cout<<"\n\t [2] Admin Panel \n\n";
    cout<<"-------------------------------------------------\n";
    int l_choose;
    cout<<"Enter your choose please:-   ";
    cin>>l_choose;

    switch(l_choose)
    {
    case 1:
        Custemer_class();
        break;
    case 2:
        Admin_class();
        break;
    default :
        cout<<"Wrong choose\n";
    }
}

void Custemer_class()
{
    cout<<"\n\n=====================================================\n";
    cout<<"\t\t\tGURSHA RESTAURANT MENU \n";
    cout<<"=====================================================\n";
    CustomerFood();
}

void Admin_class()
{
    cout<<"\n\n=============ADMIN PANEL===============\n";
    string password;

    cout << "Enter Password: ";
    cin >> password;

    if(password == "admin123")
    {
        cout << "Access Granted\n";
        passVerification();
    }
    else
    {
        cout << "Wrong Password";
    }
}

void passVerification()
{
    int choice;
    cout<<"[1] Add New Item\n";
    cout<<"[2] View Menu\n";
    cout<<"[3] Exit Admin panel\n";
    cout<<"Enter your choice:\t";
    cin>>choice;
    while(1){
        if(choice==3)
            break;

        switch(choice)
        {
        case 1:
            addMenulist();
            break;
        case 2:
            menuList();
            break;
        }
        cout<<"\n\n==============ADMIN PANEL===============\n\n";
        cout<<"[1] Add New Item\n";
        cout<<"[2] View Menu\n";
        cout<<"[3] Exit Admin panel\n";
        cout<<"Enter your choice:\t";
        cin>>choice;
    }
}

void CustomerFood()
{
    cout<<"\n\t--------------------Food----------------------\n";
    cout<<"Id.Food Name..............................price\n";
    cout<<"[1] Beyaynetu (Veggie Platter)            250 ETB\n";
    cout<<"[2] Doro Wat (Chicken Stew)               450 ETB\n";
    cout<<"[3] Kitfo (Minced Beef)                   400 ETB\n";
    cout<<"[4] Tibs (Sauteed Meat)                   350 ETB\n";
    cout<<"[5] Shiro Wat (Chickpea Stew)             180 ETB\n";

    cout<<"\n\t--------------------DRINK----------------------\n";
    cout<<"Id.Drink Name..............................price\n";
    cout<<"[6] Tej (Honey Wine)                      120 ETB\n";
    cout<<"[7] Tella (Traditional Beer)               80 ETB\n";
    cout<<"[8] Ethiopian Macchiato                   60 ETB\n";
    cout<<"[9] Ambo Water                             40 ETB\n";
    cout<<"[10] Spris (Mixed Juice)                  90 ETB\n\n\n";

    string itemName;
    float price = 0;
    char agin;
    int Quantity;

    // Track overall order info dynamically
    float overallSubtotal = 0;
    string receiptItems = "";

    do{
        int takeOrder;
        cout<<"Enter Item ID (0 to finish):";
        cin>>takeOrder;
        if(takeOrder == 0)
        {
            break;
        }

        bool validItem = true;
        switch(takeOrder)
        {
        case 1:
            itemName = "Beyaynetu";
            price = 250.00;
            break;
        case 2:
            itemName = "Doro Wat";
            price = 450.00;
            break;
        case 3:
            itemName = "Kitfo";
            price = 400.00;
            break;
        case 4:
            itemName = "Tibs";
            price = 350.00;
            break;
        case 5:
            itemName = "Shiro Wat";
            price = 180.00;
            break;
        case 6:
            itemName = "Tej";
            price = 120.00;
            break;
        case 7:
            itemName = "Tella";
            price = 80.00;
            break;
        case 8:
            itemName = "Ethiopian Macchiato";
            price = 60.00;
            break;
        case 9:
            itemName = "Ambo Water";
            price = 40.00;
            break;
        case 10:
            itemName = "Spris";
            price = 90.00;
            break;
        default:
            cout << "Invalid ID selection!\n";
            validItem = false;
            break;
        }

        if(validItem) {
            cout<<"Enter Quantity:-";
            cin>>Quantity;

            // Calculate for this specific item and add it to the overall total
            overallSubtotal += (price * Quantity);

            // Build a string block for this item to show in the final receipt
            receiptItems += itemName + "\t\t\t" + to_string(Quantity) + "X\t\t\t" + to_string((int)price) + " ETB\n";

            cout<<"Added Successfully!\n";
        }

        cout<<"\nDo you want to add more items? choose(y/n):";
        cin>>agin;
    } while(agin=='y' || agin=='Y');

    if (overallSubtotal > 0) {
        receiptBill(receiptItems, overallSubtotal);
    } else {
        cout << "No items were ordered.\n";
    }
}

void receiptBill(string accumulatedItems, float overallSubtotal)
{
    string name;
    cout<<"Enter Customer First Name:";
    cin>>name;
    int method;
    cout<<"Select Your Payment Method \n";
    cout<<"[1] Cash\n";
    cout<<"[2] Card\n";
    cout<<"[3] Mobile Banking\n";
    cin>>method;

    cash_method(name, accumulatedItems, overallSubtotal, method);
}

void cash_method(string name, string accumulatedItems, float overallSubtotal, int method)
{
    float vat = overallSubtotal * 0.15;
    float service = overallSubtotal * 0.10;
    float total = overallSubtotal + vat + service;
    time_t now = time(0);
    char* dt = ctime(&now);

    cout<<"\t\t==================================================\n";
    cout<<"\t\t                   FINAL RECEIPT                  \n";
    cout<<"\t\t==================================================\n";
    cout<<"Customer Name :"<<name<<endl;
    cout<<"Date & Time   : "<<dt;
    payment_changer(method);
    cout<<"------------------------------------------------------\n";
    cout<<"Item                    Quantity               Price\n";
    cout<<"------------------------------------------------------\n";
    // Prints out ALL accumulated items instead of just one
    cout<<accumulatedItems;
    cout<<"------------------------------------------------------\n";
    cout<<"subtotal:\t\t\t\t\t"<<overallSubtotal<<" ETB\n";
    cout<<"VAT(15%)\t\t\t\t\t"<<vat<<" ETB\n";
    cout<<"Service Charge:\t\t\t\t\t"<<service<<" ETB\n";
    cout<<"\n-----------------------------------------------------\n";
    cout<<"TOTAL:\t\t\t\t\t\t"<<total<<" ETB\n";
    cout<<"\n=====================================================\n";
    cout<<"               Melkam Megeb! Thank You!                  \n";
    cout<<"\n===================================================\n\n";
    cout<<"Receipt saved to receipt.txt successfully!\n";
}

void payment_changer(int method)
{
    if(method==1)
        cout<<"Payment Method: Cash\n\n";
    else if (method==2)
        cout<<"Payment Method: Card\n\n";
    else if (method==3)
        cout<<"Payment Method: Mobile Banking\n\n";
    else
        cout<<"Payment Method: Unknown\n\n";
}

void menuList()
{
    cout<<"\n\n=====================================================\n";
    cout<<"\t\t\tGURSHA RESTAURANT MENU \n";
    cout<<"=====================================================\n";
    cout<<"\n\t--------------------Food----------------------\n";
    cout<<"Id.Food Name..............................price\n";
    cout<<"[1] Beyaynetu (Veggie Platter)            250 ETB\n";
    cout<<"[2] Doro Wat (Chicken Stew)               450 ETB\n";
    cout<<"[3] Kitfo (Minced Beef)                   400 ETB\n";
    cout<<"[4] Tibs (Sauteed Meat)                   350 ETB\n";
    cout<<"[5] Shiro Wat (Chickpea Stew)             180 ETB\n";

    cout<<"\n\t--------------------DRINK----------------------\n";
    cout<<"Id.Drink Name..............................price\n";
    cout<<"[6] Tej (Honey Wine)                      120 ETB\n";
    cout<<"[7] Tella (Traditional Beer)               80 ETB\n";
    cout<<"[8] Ethiopian Macchiato                   60 ETB\n";
    cout<<"[9] Ambo Water                             40 ETB\n";
    cout<<"[10] Spris (Mixed Juice)                  90 ETB\n\n\n";
}

void addMenulist()
{
    string Id,name,category;
    int amount;
    cout<<"Enter New Item ID:";
    cin>>Id;
    cout<<"Enter Item Name:";
    cin>>name;
    cout<<"Enter Price:";
    cin>>amount;
    cout<<"Enter Category(Food/Drink):";
    cin>>category;
    cout<<"Item Added Successfully!";
}



