#include <stdio.h>
#include <stdint.h>

int32_t search_Rotated_Array(const int32_t arr[], int32_t n, int32_t target){
    
    if(!arr || n <= 0){
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
        //left sorted
        if(arr[low] <= arr[mid]){
            
            if(arr[low] <= target && target < arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        //right sorted
        else{
            if(arr[mid] < target && target <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
    
}


int main(void){
    int32_t arr[7]= {9,10,20,1,2,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d",search_Rotated_Array(arr, n , 10));
    return 0;
}