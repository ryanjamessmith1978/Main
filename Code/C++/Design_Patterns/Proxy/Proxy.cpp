// Proxy.cpp | https://www.youtube.com/watch?v=9yY6Bc2cgYU
// Proxy Design Pattern - Structural
// Proxy puts a class in front of your real process that adds on a little additional functionality.
// Proxies act as a substitute or placeholder for another object. 
// A proxy controls access to the original object.

#include <iostream>
#include "proxy.h"

int main() {

	// real store
	ItemRequest our_store_front;
	// this DOESN'T have Log inventory functionality
	our_store_front.AddInventory(ItemForSale(123, 10, 1));
	our_store_front.AddInventory(ItemForSale(456, 2, 2));
	our_store_front.AddInventory(ItemForSale(543, 15, 1));
	our_store_front.AddInventory(ItemForSale(233, 6, 1));
	our_store_front.AddInventory(ItemForSale(434, 9, 1));
	our_store_front.AddInventory(ItemForSale(665, 1, 1)); 

	// proxy it
	Proxy_CheckBeforeRequest proxy_store(&our_store_front);
	// this DOES add to Log Inventory
	proxy_store.AddInventory(ItemForSale(277, 2, 2)); 

	// client
	PaymentType our_payment = PaymentType::CREDIT;
	
	// ultimately passes Request item to ItemRequest class
	// since 234 doesn't exist in inventory, returns '0' because 234 isn't in inventory.
	auto return_code = proxy_store.RequestItem(234, our_payment);
	std::cout << "return code for purchase 234: " << return_code << '\n';

	auto return_code2 = proxy_store.RequestItem(233, our_payment);
	std::cout << "return code for purchase 233: " << return_code2 << '\n';

	system("pause");
}