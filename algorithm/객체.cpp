#include<iostream>

using namespace std;

//집 짓는 나만의 가이드라인
class House{
public:

    explicit House(string paint, string sigong, int value)
    :wallColor{paint}, iron{sigong}{
        if(value < 10){
            price = -1;
        }
        else{
            price = value;
        }
    }

    House(){}

    string getWallColor() const{
        return wallColor;
    }

    void setWallColor(string color){
        cout<<color + "으로 부탁해요\n";
        wallColor = color;
    }

    string getIron() const{
        return iron;
    }

    void setIron(string sigong){
        cout<<sigong + "로 부탁해요\n";
        iron = sigong;
    }

    int getPrice() const{
        return price;
    }

    void setPrice(int value){
        if(price < 10){
            cout<<"이런말도 안되는 가격을 제시하다니 저리 썩 꺼져!!!!\n";
        }
        else {
            cout<<price+value;
            cout<<"가 딱좋네만.\n";
            price = value;
        }
    }

    void printHouseInfo(){
        cout<<"벽색깔 : "<<wallColor<<"\n";
        cout<<"철근종류 : "<<iron<<"\n";
        cout<<"가격 : "<<price<<"\n";
    }

    void addPrice(int value){
        if(price < 10){
            cout<<"이렇게 낮추는건 안돼!!!!\n";
        }
        else {
            cout<<value;
            if (value > 0){
                cout<<"만큼 올렸네 너무 올렸나? 흠흠\n";
            }
            else {
                cout<<"만큼 내렸네 너무 착한가? ㅠㅠ\n";
            }
            price = price + value;
        }
    }

private:
    string wallColor;
    string iron;
    int price;
};

int main(){

    House seoulHouse;
    House incheonHouse("빨강색", "구리", 25);
    seoulHouse.printHouseInfo();
    
    
    
    cout<<"똑똒똒 건물주님 서울집 벽을 무슨색깔로 할까요?\n";
    seoulHouse.setWallColor("파랑색");
    cout<<"그럼 철근은 어떤걸로 할까요\n?";
    seoulHouse.setIron("다이아몬드");
    cout<<"그럼 가격은?\n";
    seoulHouse.setPrice(25);
    
    seoulHouse.printHouseInfo();
    
}
