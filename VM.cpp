#include <iostream>
#include <string>

using namespace std;

class VendingMachine {
public:
    VendingMachine(string Name, int items, float Price) {
        name = Name;
        quantity = items;
        price = Price;
    }
    
	//Setter functions
    void set_name(string Name) {
        name = Name;
    }
    void set_inventory(int items) {
        quantity = items;
    }
    void set_price(float Price) {
        price = Price;
    }
	
	//Getter functions
    float get_price() {
        return price;
    }
    int get_inventory() {
        return quantity;
    }
    string get_name() {
        return name;
    }
	
    void buy_items(int number) {
        quantity = quantity - number;
    }
    
    virtual void stat() = 0;
    
private:
    int quantity;
    float price;
protected:
    string name;
};

class CandyMachine: public VendingMachine {
public:
	int total_pieces;
	CandyMachine(string Name, int items, float Price, int Total_pieces) 
		: VendingMachine(Name, items, Price)
	{
		total_pieces = Total_pieces;
	}
	void stat() {
        cout << "Candy VM contains " << get_inventory() << " " << name << " of $" << get_price() << " which has " << total_pieces << " pieces." << endl;
    }
};

class DrinksMachine: public VendingMachine {
public:
	float size;
	DrinksMachine(string Name, int items, float Price, float Size) 
		: VendingMachine(Name, items, Price)
	{
		size = Size;
	}
	void stat() {
        cout << "Drinks VM contains " << get_inventory() << " " << name << " of $" << get_price() << " and of size " << size << "ml." << endl;
    }
};

int main()
{
	CandyMachine C1 = CandyMachine("M&M", 10, 2, 10);
	DrinksMachine D1 = DrinksMachine("Coke", 10, 3, 500);
	
	VendingMachine* V1 = &C1;
	VendingMachine* V2 = &D1;
	
	V1->stat();
	V2->stat();
}