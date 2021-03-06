//****Binary Search***//


int binarySearch(int low,int high,int key)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]<key)
        {
            low=mid+1;
        }
        else if(a[mid]>key)
        {
            high=mid-1;
        }
        else
        {
            return mid;
        }
    }
    return -1;                //key not found
}

lower_bound (v.begin(), v.end(), 20);
upper_bound (v.begin(), v.end(), 20);
binary_search(v.begin(), v.end(), 20);
