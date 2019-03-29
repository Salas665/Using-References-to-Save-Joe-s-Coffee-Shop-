#include <iostream>

using namespace std;

//Declaring my functions
void printHackedTrans(int x, int y); //Not using references
void printNormalTrans(int& x, int& y); //Using references

int main()
{
	//Declaring local variables
	int normalTrans = 5;
	int hackedTrans = 50000;

	// Displaying Original Values
	cout << "Orginal Values\n";
	cout << "Joe's Coffee Shop Balance: " << normalTrans << "\n";
	cout << "Hackers Balance: " << hackedTrans << "\n";

	//Displaying Hacked Transaction 
	//Since the function's parameters aren't references, they are passing values,
	//the arguements are left unswapped, this is why 
	//it displays the values delcared in main
	cout << "\nCalling printHackedTrans():\n"; 
	printHackedTrans(normalTrans, hackedTrans);
	cout << "Joe's Coffee Shop Balance: " << normalTrans << "\n";
	cout << "Hackers Balance: " << hackedTrans << "\n";

	//Displaying Normal Transaction
	//Since the funcion's parameters are references, it is passing the parameters by reference,
	//meaning that anyhthing that you do to the references, will occur to that which 
	//you are referencing, in this case, the variables delcared in main()
	cout << "\nCalling printNormalTrans():\n";
	printNormalTrans(normalTrans, hackedTrans);
	cout << "Joe's Coffee Shop Balance: " << normalTrans << "\n";
	cout << "Hackers Balance: " << hackedTrans << "\n";

	cout << "\nThe hackers are officially bankrupt!\n";

	system("pause");
	return 0;
}
//The parameters of this function are passed by value
//meaning that they will go out of scope once main() regains control
void printHackedTrans(int x, int y)
{
	//Swapping the parameters, this does NOT affect main()
	int temp = x;
	x = y;
	y = temp;
}
//The parameters of this function are passed by reference
//meaning that anything done to these parameters, the same will occur
//for the arguements in main. This is why the transactions in main flipped
void printNormalTrans(int& x, int& y)
{
	//Swapping the parameters, this does affect main()
	int temp = x;
	x = y;
	y = temp;
}