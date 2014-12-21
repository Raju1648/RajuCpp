
#include<iostream>
#include <algorithm> // for swap
using namespace std;
void bubblesort(int *a,int n,bool(*comp)(int x, int y))
{
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(comp(a[i],a[j]))
			{
				swap(a[i],a[j]);
			}

		}
	}
}
bool asce(int x, int y)
{
	return x>y;
}

bool dese(int x, int y)
{
	return x<y;
}

void print(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"   "<<a[i];
	}
}
/*int main()
{
	int a[]={3,5,6,4,2,7,9,8,1};
	bubblesort(a,9,asce);
	print(a,9);
	cout<<"\n descending order"<<endl;
	bubblesort(a,9,dese);
	print(a,9);
	return 0;
}*/

























/*// Note our user-defined comparison is the third parameter
void SelectionSort(int *anArray, int nSize, bool (*pComparison)(int, int))
{
    //using namespace std;
    for (int nStartIndex= 0; nStartIndex < nSize; nStartIndex++)
    {
        int nBestIndex = nStartIndex;

        // Search through every element starting at nStartIndex+1
        for (int nCurrentIndex = nStartIndex + 1; nCurrentIndex < nSize; nCurrentIndex++)
        {
            // Note that we are using the user-defined comparison here
            if (pComparison(anArray[nCurrentIndex], anArray[nBestIndex])) // COMPARISON DONE HERE
                nBestIndex = nCurrentIndex;
        }

        // Swap our start element with our best element
        swap(anArray[nStartIndex], anArray[nBestIndex]);
    }
}

// Here is a comparison function that sorts in ascending order
// (Note: it's exactly the same as the previous Ascending() function)
bool Ascending(int nX, int nY)
{
    return nY > nX;
}

// Here is a comparison function that sorts in descending order
bool Descending(int nX, int nY)
{
    return nY < nX;
}

// This function prints out the values in the array
void PrintArray(int *pArray, int nSize)
{
    for (int iii=0; iii < nSize; iii++)
        cout << pArray[iii] << " ";
    cout << endl;
}

int main()
{
    using namespace std;

    int anArray[9] = { 3, 7, 9, 5, 6, 1, 8, 2, 4 };

    // Sort the array in descending order using the Descending() function
    SelectionSort(anArray, 9, Descending);
    PrintArray(anArray, 9);

    // Sort the array in ascending order using the Ascending() function
    SelectionSort(anArray, 9, Ascending);
    PrintArray(anArray, 9);

    return 0;
}*/
