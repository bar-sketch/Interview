
int32_t findPeakElement(const int32_t arr[], int32_t n){
    
    if(!arr || n <= 0){
        return -1;
    }
    
    int32_t low = 0;
    int32_t high = n - 1;
    int32_t mid;
    
    while( low < high){
    
        mid = low + ((high - low)>>1);
        
        if(arr[mid] < arr[mid + 1]){
            low = mid + 1;
        }    
        else{
            high = mid;
        }
    }
    return low;
}

int main(void){
    int32_t arr[7]= {1,2,4,4,2,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d",findPeakElement(arr, n));
    return 0;
}