
#include<iostream>

using namespace std;

int arr[9]={0,};
int number[8]={50000,10000,5000,1000,500,100,50,10};

int main(int argc, char** argv)
{
    int test_case;
    int T;
   
    cin>>T;
   
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin>>n;
        for(int i = 0; i<8;i++){
            arr[i] = n / number[i];
            n -= number[i] * arr[i];
        }
        
        cout<<"#"<<test_case<<"\n";
        for(int i=0;i<8;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
