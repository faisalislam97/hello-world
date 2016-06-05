#include <iostream>
#include <string>

using namespace std;

inline int Input()
{
	int key = 0;
	cout << "Enter key: ";
	cin >> key;
	return key;
}
inline int Mid(int low, int high)
{
	return ((low + high) / 2);
}

int main()
{
	const int ArrSize = 100;
	int specimen[ArrSize] = {};						//making array of 100 elements, out of multiples of 3
	for (int a = 0; a < ArrSize; a++)
		specimen[a] = 3 * a;





	int i = 0, j = 0;								// indexes for keeping searching iterations to a limit
													// j is the maximum number of search iterations to perform
	
	
	int low = 0, high = ArrSize;					// calculating mid for the first time
	int mid = Mid(low, high);


	{																		//calculating limit of iteration
		int rem = high;													
		while (rem >= 1)
		{
			j++;	rem /=2;						//divide rem repeatedly and increment j, as long as rem is not less than 1										
		}
	}
	
	int key = Input();								//taking input
	bool keyFound = false;

	while (keyFound == false && i != j)										/*Search loop. It works as long as key is not found,
																			or limit of searching is not reached*/
	{

		if (key < specimen[mid])											//If key is less than mid
		{
			high = mid;
			mid = Mid(low,high);
		}
		else if (key > specimen[mid])										//If key is greater than mid
		{
			low = mid;
			mid = Mid(low, high);;
		}
		else
																			
		{
			keyFound = true;
			cout << "Key found in specimen[" << mid << "]" << endl;			// Success : From Munadi
		}
		
		i++;
	}
	
	if (keyFound == false)													//If key not found
		cout << "Key not found";
	
	
	return 0;
}