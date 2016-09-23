using namespace std;
int Count(int* A, int n)
{
    int k = 0, flag = 0;
    for(int i = n - 1; i >= 0; i--){
        flag = 0;
        for(int j = 0; j < i; j++){
            if(A[i] == A[j]){
                flag = 1;
                break;
            }
        }
        if(flag){
            k++;
        }
    }
    return k;





    int i,j=0,k;


    if(n==1)
        return 1;

    else{

        for(i=0;i<n-1;i++){
            if(A[i]==A[n-1])
             j++;
        }
        //   1 - n     O(n)


        //


        if(j==0)
            k = Count(A,n-1)+1;    //  O(n)    O(n^2)
        else
            k=Count(A,n-1);
        return k;
    }
}



int main()
{
    int A[10],n=10,i;
    cout<<"Please input ten integers:"<<endl;
    for(i=0;i<10;i++)
        cin>>A[i];
    cout<<Count(A,n);
    return 0;
}
