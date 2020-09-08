#include <iostream>

using namespace std;
int calculate(int arr[7],int l,int r){
        int mid = (l+r)/2;
        int leftarea = 0;
        int rightarea = 0;
        int middlearea = 0;
        int leftheight = arr[mid];
        int rightheight = arr[mid+1];
        int li = mid;
        int ri = mid+1;
        while(li>=0){
            if(leftheight>arr[li]) break;
            else{
                leftarea = leftarea+leftheight;
                li--;
            }
        }
        while(ri<8){
            if(rightheight>arr[ri]) break;
            else{
                rightarea = rightarea+rightheight;
                ri++;
            }
        }
        int a = min(leftheight,rightheight);
        li = mid;
        ri = mid+1;
        while(li>=0){
            if(a>arr[li]) break;
            else{
                middlearea = middlearea + a;
                li--;
            }
        }
        while(ri<8){
            if(a>arr[ri]) break;
            else{
                middlearea = middlearea+a;
                ri++;
            }
        }
        int maximum = max(leftarea,rightarea);
        return max(maximum,middlearea);
}
int fence(int arr[7],int l,int r){
    if(l<r){
        int mid = (l+r)/2;
        cout<<"l:"<<l<<" mid:"<<mid<<" r:"<<r<<endl;
        int leftarea = fence(arr,l,mid);
        int rightarea = fence(arr,mid+1,r);
        return max(calculate(arr,l,mid),calculate(arr,mid+1,r));
    }
}
int main()
{
    int arr[7] = {1,1,8,1,1,1,1};
    cout<<fence(arr,0,7);

    return 0;
}
