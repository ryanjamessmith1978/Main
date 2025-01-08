// proxy.h 
// Online store that tie services together.
// Hackers use proxies on stores to take some of transaction money, routing it to their account.


#include <vector>
#include <iostream>

enum PaymentType { CREDIT, BANK, WIRE, CRYPTO };

bool Charge(const PaymentType payment_, int amount_to_charge) {
	return true;
}

// ### ITEM ###
struct ItemForSale {
	int sku;
	int cost_per;
	int num_in_stock;

	ItemForSale(int sku, int cost_per, int num_in_stock)
		: sku(sku), cost_per(cost_per), num_in_stock(num_in_stock){}
};

// ### Request Interface ###
class Request {
public:
	virtual ~Request() = default;
	virtual void AddInventory(ItemForSale itemForSale) = 0;
	virtual int RequestItem(const int item_sku, const PaymentType payment_) = 0;
protected:
	std::vector<ItemForSale> current_inventory;
};

// ### Item Request ###
class ItemRequest : Request {
public:
	virtual ~ItemRequest() {}

	virtual void AddInventory(ItemForSale itemForSale) override {
		// not allow duplicate skus, instead add to num in stock
		for (ItemForSale item : current_inventory) { // adds to number in stock
			if (item.sku == itemForSale.sku) {
				item.num_in_stock += itemForSale.num_in_stock;
				return;
			}
		}

		current_inventory.push_back(itemForSale); // if unique, add to current inventory vector.
	}

	// returns amount charged, returns 0 if item not found,returns -1 if payment error,
	virtual int RequestItem(const int item_sku, const PaymentType payment_) override {
		for (auto& item : current_inventory) {
			if (item.sku == item_sku && item.num_in_stock > 0) {
				if (Charge(payment_, item.cost_per)) {
					item.num_in_stock--;
					return item.cost_per;
				}
				return -1;
			}
		}
		return 0;
	}
};

// ### PROXY - Check Request ###
// Whole point of the proxy is to do additional stuff
// Proxy_CheckBeforeRequest puts a proxy on top of the ItemRequest
class Proxy_CheckBeforeRequest : Request {
private:

	// Proxy_CheckBeforeRequest doesn't inherit from ItemRequest (just Request)
	// but because of this member variable, it will instantiate ItemRequest's functionality
	ItemRequest* item_request;	// The constructor requires an ItemRequest be passed in.						   
							   
	void LogInventoryAdd(ItemForSale itemForSale) {
		std::cout << "attempted to add sku: " << itemForSale.sku << '\n';
	}

	bool PaymentCheck(const PaymentType payment_) {
		// pre-check payment for legality, make sure account exits/card isn't expired, etc				
		return true; // THIS CODE Would be fleshed out, just for example sake, it'll always return true.
	}

public:
	Proxy_CheckBeforeRequest(ItemRequest* item_req) : item_request(new ItemRequest(*item_req)) {};
	~Proxy_CheckBeforeRequest() { delete item_request; }
	
	// Adds LogInventory to the AddInventory function, on top of the standard ItemRequest.Add()
	virtual void AddInventory(ItemForSale itemForSale) override {
		LogInventoryAdd(itemForSale); // PROXY EXAMPLE
		item_request->AddInventory(itemForSale);
	}

	virtual int RequestItem(const int item_sku, const PaymentType payment_) override {
		// adds 'declined payment' functionality to the RequestItem
		if (!PaymentCheck(payment_)) { // PROXY EXAMPLE
			return -1;
		}
		return item_request->RequestItem(item_sku, payment_);
	}
};

// ??? QUESTIONS ???
// Why not just use child inheritance to add additional functionality instead of using a proxy?
// A: In an ideal world, we’d want to put this code directly into our object’s class, 
// but that isn’t always possible. For instance, the class may be part of a CLOSED 3rd-party library.
// 
// A: If the superclass (RealSubject) is not under your control, i.e. in the same package, 
// and specifically designed and documented for Extension, any changes to it's implementation 
// from version to version may break your implementation of the subclass (EnhancedSubject). 
// Depending directly on a concrete implementation leads to fragile code.
//
// A: it is safe to use inheritance if the RealSubject and EnhancedSubject are under your control 
// and released with the same life cycle, but 
// Depending directly on a concrete implementation leads to fragile code.