#include <iostream>
#include <vector>

using namespace std;

void MergeSort(vector<int>& a) {
    int size = a.size();
    //base case
    if (size == 1)
        return;

    //normal case        
    int mid = (size - 1) / 2;
    int n1 = (size + 1) / 2;
    int n2 = size - n1;
    //create two half arrays
    vector<int> a1(n1);
    vector<int> a2(n2);
    //copy values into the two arrays
    int i = 0;
    for (i = 0; i <= mid; i++)
    {
        a1[i] = a[i];
    }
    for (i = mid + 1; i < size; i++)
    {
        a2[i - mid - 1] = a[i];
    }
    //call merge sort on half arrays
    MergeSort(a1);
    MergeSort(a2);
    //Merge the sorted halves
    int j, k;
    i = 0;
    j = 0;
    k = 0;
    while (k < size)
    {
        if (j >= n2)
        {
            a[k] = a1[i];
            i++;
        }
        else if (i >= n1)
        {
            a[k] = a2[j];
            j++;
        }
        else if (a1[i] < a2[j])
        {
            a[k] = a1[i];
            i++;
        }
        else
        {
            a[k] = a2[j];
            j++;
        }
        k++;
    }
    return;
}

void main()
{
    vector<int> nums(5);
    nums[0] = 5;
    nums[1] = 3;
    nums[2] = 4;
    nums[3] = 1;
    nums[4] = 2;

    for (int i = 0; i < 5; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    MergeSort(nums);

    for (int i = 0; i < 5; i++)
    {
        cout << nums[i] << " ";
    }
}
