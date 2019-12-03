#include <iostream>
#include <algorithm>
using namespace std;

void max_heapsort(int arr[],int start,int end)
{
    int dad = start;
    int son = dad *2 + 1;
    while (son <= end)
    {
        if(son +1 <=end && arr[son] < arr[son + 1])
        son++;
        if(arr[dad] > arr[son])
        return;
        else
        {
            swap(arr[dad],arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }       
    }
}
void heapsort(int arr[],int len)
{
    for(int i=len / 2 -1;i>=0;i--)
    max_heapsort(arr,i,len -1);
    for(int i=len-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        max_heapsort(arr,0,i-1);
    }
}
int main()
{    
    int n=10;
    int arr[10];
    cout << "请输入" << n << "个数字" << endl;
    for(int i=0;i<10;i++)
    cin >> arr[i];
   // int arr[]={1,5,8,0,3,4,8};
    int len = (int)sizeof(arr) / sizeof(*arr);
    heapsort(arr,len);
    cout << "排序后" << endl;
    for(int i=0;i<len;i++)
    cout  << arr[i] << ' ';
    cout << endl;
    return 0;
}
