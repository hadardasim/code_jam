#include <iostream> 
#include <set> 
#include <unordered_set>
#include <iterator> 
#include <functional>

using namespace std;
// Time complexity of set operations is O(Log n) while for unordered_set, it is O(1)

int set_main()
{
	// empty set container 
	set <int, greater <int> > gquiz1;
	// set <int> gquiz1;

	// insert elements in random order 
	gquiz1.insert(40);
	gquiz1.insert(30);
	gquiz1.insert(60);
	gquiz1.insert(20);
	gquiz1.insert(50);
	gquiz1.insert(50); // only one 50 will be added to the set 
	gquiz1.insert(10);

	// printing set gquiz1 
	set <int, greater <int> > ::iterator itr;
	cout << "\nThe set gquiz1 is : ";
	for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr)
	{
		cout << '\t' << *itr;
	}
	cout << endl;

	// assigning the elements from gquiz1 to gquiz2 
	set <int> gquiz2(gquiz1.begin(), gquiz1.end());

	// print all elements of the set gquiz2 
	cout << "\nThe set gquiz2 after assign from gquiz1 is : ";
	for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr)
	{
		cout << '\t' << *itr;
	}
	cout << endl;

	// remove all elements up to 30 in gquiz2 
	cout << "\ngquiz2 after removal of elements less than 30 : ";
	gquiz2.erase(gquiz2.begin(), gquiz2.find(30));
	for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr)
	{
		cout << '\t' << *itr;
	}

	// remove element with value 50 in gquiz2 
	auto num = gquiz2.erase(50);
	cout << "\ngquiz2.erase(50) : ";
	cout << num << " removed \t";
	for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr)
	{
		cout << '\t' << *itr;
	}

	cout << endl;

	//lower bound and upper bound for set gquiz1 
	cout << "gquiz1.lower_bound(40) : "
		<< *gquiz1.lower_bound(40) << endl;
	cout << "gquiz1.upper_bound(40) : "
		<< *gquiz1.upper_bound(40) << endl;

	//lower bound and upper bound for set gquiz2 
	cout << "gquiz2.lower_bound(40) : "
		<< *gquiz2.lower_bound(40) << endl;
	cout << "gquiz2.upper_bound(40) : "
		<< *gquiz2.upper_bound(40) << endl;

	return 0;

}

void printDuplicates(int arr[], int n)
{
	// declaring unordered sets for checking and storing 
	// duplicates 
	unordered_set<int> intSet;
	unordered_set<int> duplicate;

	// looping through array elements 
	for (int i = 0; i < n; i++)
	{
		// if element is not there then insert that 
		if (intSet.find(arr[i]) == intSet.end())
			intSet.insert(arr[i]);

		// if element is already there then insert into 
		// duplicate set 
		else
			duplicate.insert(arr[i]);
	}

	// printing the result 
	cout << "Duplicate item are : ";
	unordered_set<int> ::iterator itr;

	// iterator itr loops from begin() till end() 
	for (itr = duplicate.begin(); itr != duplicate.end(); itr++)
		cout << *itr << " ";
}