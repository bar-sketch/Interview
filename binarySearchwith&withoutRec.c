//Binary Search with and without recursion

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL -1
#define SUCCESS 1
#define INT_BITS 16
 
int8_t BinarySearchRec(uint8_t arr[], uint8_t l,uint8_t r,uint8_t x);
int8_t BinarySearch(uint8_t arr[], uint8_t low,uint8_t high,uint8_t x);
/* Driver program to test above functions*/
int main()
{
    uint8_t arr[]={2,4,7,9,14,18,26,28,36};
    uint8_t size=sizeof(arr)/sizeof(arr[0]);
    printf("Index:%d\n",BinarySearchRec(arr,0,size-1,7));
    printf("Index:%d\n",BinarySearch(arr,size,18));
    return 0;
}

int8_t BinarySearchRec(uint8_t arr[], uint8_t l,uint8_t r,uint8_t x)
{
    uint8_t mid=0;
    if(r>=l){
        mid=l + (r-l)/2;
        //printf("Mid:%d\n",mid);
        if(arr[mid]==x)
            return mid;
        else if(x<arr[mid])
            return BinarySearch(arr,l,mid-1,x);
        else
            return BinarySearch(arr,mid+1,r,x);
    }
    return FAIL;
}


int32_t binarySearch(const int32_t *arr, size_t n, int32_t target){
    
    if(!arr || n==0){
        return -1;
    }
    
    int32_t low = 0;
    int32_t high = n-1;
    int32_t mid;
    
    while(low <= high){
        
        mid = low + ((high - low)>>1);
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
        
    }
    return -1;
}
