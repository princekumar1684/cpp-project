#include <iostream>
#include <iomanip>
using namespace std;

class FoodItem
{
    int id;
    string name;
    float price;

public:
    FoodItem()
    {
        id = 0;
        name = "";
        price = 0;
    }

    FoodItem(int id, string name, float price)
    {
        this->id = id;
        this->name = name;
        this->price = price;
    }

    void display() const
    {
        cout << id << "\t" << name << "\tRs :" << price << endl;
    }

    string getName()
    {
        return name;
    }

    float getPrice()
    {
        return price;
    }
};

class Order
{
    static int totalOrders;

public:
    float calculateBill(float amount)
    {
        return amount;
    }

    float calculateBill(float amount, int discount)
    {
        return amount - (amount * discount / 100);
    }

    void placeOrder(float total)
    {
        totalOrders++;

        cout << "\n====================FINAL INVOICE====================";
        cout << "\nTotal Amount Rs/- " << total << endl;

        float finalAmount;

        if (total >= 500)
        {
            finalAmount = calculateBill(total, 10);
            cout << "10% Discount Applied.." << endl;
        }
        else
        {
            finalAmount = calculateBill(total);
            cout << "No Discount Applied.." << endl;
        }

        cout << "Order Placed Successfully ! Enjoy your meal.." << endl;
        cout << "Final Bill Amount is Rs/- " << finalAmount << endl;
    }
};

int Order::totalOrders = 0;

int main()
{

    FoodItem menu[5] = {
        FoodItem(1, "Burger", 60),
        FoodItem(2, "Pizza", 99),
        FoodItem(3, "Pasta", 100),
        FoodItem(4, "Momos", 60),
        FoodItem(5, "Sandwich", 50),
    };

    Order order;

    int choice, quantity;
    float total = 0;

    cout << "\n=============================================";
    cout << "\n               Highway King";
    cout << "\n=============================================";

    cout << "\n----------------------MENU----------------------" << endl;

    for (int i = 0; i < 5; i++)
    {
        menu[i].display();
    }

    cout << "Enter 0 to Exit" << endl;

    while (true)
    {
        cout << "Enter Food Id : ";
        cin >> choice;

        if (choice == 0)
        {
            break;
        }

        if (choice < 1 || choice > 5)
        {
            cout << "Invalid Choice : Please Enter Valid ID";
            continue;
        }

        cout << "Enter Item Quantity : ";
        cin >> quantity;

        if (quantity < 1)
        {
            cout << "Please Select Atleast 1 item " << endl;
            continue;
        }

        float amount = menu[choice - 1].getPrice() * quantity;

        total += amount;

        cout << menu[choice - 1].getName() << " Added ! Price /- " << total << endl;
    }

    if (total > 0)
    {
        order.placeOrder(total);
    }
    else
    {
        cout << "No Items Added to Order " << endl;
    }

    return 0;
}
