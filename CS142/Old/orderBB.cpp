// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment
//
// mbeltz
#include <iostream>
#include <string>

int main()
{
	double Hamp(1.5),Cheesep(2),Frenchp(1),Drinkp(1),Cakep(1.25);
	// The price of each item
	double cost(0),paid(-1);
	// The amount of money that is owed and is paid
	int order = -1;
	// used for input to determine what is being ordered
	int Hamc(0),Cheesec(0),Frenchc(0),Drinkc(0),Cakec(0);
	// used to count how many of each item was ordered
	double format(.01), excess(0);
	// used to get correct change and price format
	
	std:: cout << "Hello. Welcome to My Menue Order System";
	while (order != 6)
	{
		std::cout << "What would you like to order?" << "\n" << "\n";
		std::cout << "1." << "\t" << "Hamburger         $1.50" << "\n";
		std::cout << "2." << "\t" << "Cheesebutger      $2.00" << "\n";
		std::cout << "3." << "\t" << "French Fries      $1.00" << "\n";
		std::cout << "4." << "\t" << "Soft Drink        $1.00" << "\n";
		std::cout << "5." << "\t" << "Piece of Cake     $1.25" << "\n";
		std::cout << "6." << "\t" << "Complete Order" << "\n" << "\n";
		std::cout << "Please enter your selection: ";
		std::cin >> order;
		// The menue and ordering that will appear betwen every order
		
		if (order == 1) //if they order a Hambergur 
		{
			std::cout << "You have selected a Hamburger" << "\n" << "\n";
			cost = cost + Hamp;
			Hamc++;
		}
		else if (order == 2) //if they order a cheeseburger
		{
			std::cout << "You have selected a Cheeseburger" << "\n" << "\n";
			cost = cost + Cheesep;
			Cheesec++;
		}
		else if (order == 3) //if they order French Fries
		{
			std::cout << "You have selected French Fries" << "\n" << "\n";
			cost = cost + Frenchp;
			Frenchc++;
		}
		else if (order == 4) //if they order a Soft Drink
		{
			std::cout << "You have selected a Soft Drink" << "\n" << "\n";
			cost = cost + Drinkp;
			Drinkc++;
		}
		else if (order == 5) //if they order a Piece of Cake
		{
			std::cout << "You have selected a Piece of Cake" << "\n" << "\n";
			cost = cost + Cakep;
			Cakec++;
		}
		else if (order == 6) //if their order is finished
		{
			std::cout << "Thank you" << "\n" << "\n";
		}
		else //if they have an invalid selection
		{
			std::cout << "Invalid selection" << "\n" << "\n";
		}
	}
	
	std::cout << "Thank you your order is:" << "\n";
	if ( Hamc > 0) //if they ordered any hamburgers
	{
		std::cout << Hamc << " Hamburger(s)" << "\n";
	}
	else
	{
		//do nothing
	}
	
	if ( Cheesec > 0) //if they ordered any cheeseburgers
	{
		std::cout << Cheesec << " cheseburger(s)" << "\n";
	}
	else
	{
		//do nothing
	}
	
	if ( Frenchc > 0) //if they ordered any french fries
	{
		std::cout << Frenchc << " French Fries" << "\n";
	}
	else
	{
		//do nothing
	}
	
	if ( Drinkc > 0) //if they ordered any Soft Drinks
	{
		std::cout << Drinkc << " Soft Drink(s)" << "\n";
	}
	else
	{
		//do nothing
	}
	
	if ( Cakec > 0) //if they ordered any pieces of cake
	{
		std::cout << Cakec << " Piece(s) of cake" << "\n";
	}
	else
	{
		//do nothing
	}
	
	cost = cost * 1.07;
	excess = cost / format;
	cost = cost - excess; // used to get rid of the excess decimals
	std::cout << "Your total is: " << cost << "\n" << "\n";
	
	while ( paid < cost)
	{
		std::cout << "Enter the amount tendered: $";
		std::cin >> paid;
		if ( paid < cost)//they did not pay enough
		{
			std::cout << "You have not provided enough money to purchase your items!" << "\n" << "Please enter an amount greater than or equal to: $" << cost << "\n" << "\n";
		}
		else
		{
			//do nothing
		}
	}
	if ( paid >= cost) //they paid enough
	{
		std::cout << "Your change is: $" << paid - cost << "\n" << "\n";
	}
	else
	{
		std::cout << "Max we have an error";
	}
	std::cout << "Thank you! Enjoy your meal!" << "\n";
	
	
	return 0;
}