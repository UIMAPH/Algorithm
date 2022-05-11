#include<iostream>

using namespace std;

int main(int argc, char** argv){
    int test_case;
    int T;
    int n;
    int ans = 0;
    
    cin>>T;
    
    
    for(test_case = 1; test_case <= T; ++test_case){
        cin>>n;
        int num = 1;
        ans = 0;
        //0 에서부터 9까지 숫자가 모드 있을때 멈춘다
        //1<<10 -1 은 1023을 표시
        while(ans != ((1<<10)-1)){
            
            int temp = num*n;
            while(temp>0){
                //숫자를 받으면 뒤에서 부터 한글자씩 해당 자리와 비교
                ans = ans | (1<<((temp%10)));
                temp /= 10;
            }
            num++;
        }
        cout<<"#"<<test_case<<" "<<(num-1)*n<<"\n";
    }
    return 0;//정상종료시
}
