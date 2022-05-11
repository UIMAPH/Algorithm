#include<iterator>
#include<map>
#include<string>
#include<iostream>
using namespace std;
using namespace std;


struct member{
    string name;
    int gender;
    bool married;
    bool haveFather;
    bool haveMother;
    member* wife;
    member* father;
    member* mother;
};


map<string,int> idx;
member m[201];
int dist[201][201];
int key=0;




void init(char initialMemberName[], int initialMemberSex){
    for(int i=0;i<201;i++){
        m[i] = {"",-1,false,false,false};
        idx.clear();
        for(int j=0;j< 201;j++){
            dist[i][j]=0;
        }
    }
    key=0;
    idx[initialMemberName] = key;
    m[key] = member{initialMemberName,initialMemberSex,0,0,0};
    key++;
}

bool canAdd(char newMemberName[], int newMemberSex, int relationship, char existingMemberName[]){
    member thism = m[idx[existingMemberName]];
    switch (relationship) {
        case 0:
            return !thism.married and thism.gender != newMemberSex;
        case 1:
            if(!thism.haveFather and !thism.haveMother){
                return true;
            }
            if (thism.haveFather){
                if(newMemberSex and !thism.father->married){
                    return true;
                }
            }
            if(thism.haveMother){
                if(!newMemberSex and !thism.mother->married){
                    return true;
                }
            }
            return false;
        case 2:
            return true;
    }
    return false;
}

bool addMember(char newMemberName[], int newMemberSex, int relationship, char existingMemberName[]){
    if(canAdd(newMemberName, newMemberSex, relationship, existingMemberName)){
        //cout<<key<<"\n";
        int exidx = idx[existingMemberName];
        idx[newMemberName] = key;
        member& exist = m[exidx];
        //배우자일때
        if(relationship==0){
            member newm = {newMemberName,newMemberSex,1,0,0};
            m[key] = newm;
            exist.married = true;
            exist.wife = &m[key];
            m[key].married = 1;
            m[key].wife = &exist;
            dist[exidx][key]=0;
            for(int i=0;i<200;i++){
                dist[key][i] =  dist[exidx][i];
                dist[i][key] = dist[key][i];
            }
        }else if(relationship == 1){ //부모
            dist[exidx][key]=0;
            for(int i=0;i<200;i++){
                dist[key][i] = dist[exidx][i] + 1;
                dist[i][key] = dist[key][i];
            }
            dist[key][key] = 0;
            m[key] = {newMemberName,newMemberSex,0,0,0};
            if(exist.haveFather){
                m[key].married = true;
                exist.haveMother = true;
                exist.mother = &m[key];
                m[key].wife = exist.father;
                exist.father->wife = &m[key];
                exist.father->married = true;
                int fathern = idx[exist.father->name];
                dist[fathern][key]=0;
                for(int i=0;i<200;i++){
                    dist[key][i] = dist[fathern][i];
                    dist[i][key] = dist[key][i];
                }
                dist[key][key] = 0;
            } else if(exist.haveMother){
                m[key].married = true;
                exist.haveFather = true;
                exist.father = &m[key];
                m[key].wife = exist.mother;
                exist.mother->wife = &m[key];
                exist.mother->married = true;
                int mothern = idx[exist.mother->name];
                dist[mothern][key]=0;
                for(int i=0;i<200;i++){
                    dist[key][i] = dist[mothern][i];
                    dist[i][key] = dist[key][i];
                }
                dist[key][key] = 0;
            } else{
                if(newMemberSex){
                    exist.haveMother = true;
                    exist.mother = &m[key];
                }else{
                    exist.haveFather = true;
                    exist.father = &m[key];
                }
            }
        } else{//자식
            m[key]={newMemberName,newMemberSex,0,0,0};
            if(exist.married){
                m[key].haveMother = true;
                m[key].haveFather = true;
                if(exist.gender){
                    m[key].mother = &exist;
                    m[key].father = exist.wife;
                }
                else{
                    m[key].father = &exist;
                    m[key].mother = exist.wife;
                }
            } else if (exist.gender){
                m[key].haveMother = true;
                m[key].mother = &exist;
            } else{
                m[key].haveFather = true;
                m[key].father = &exist;
            }
            dist[exidx][key] = 0;
            for(int i=0;i<200;i++){
                dist[key][i] = dist[exidx][i] + 1;
                dist[i][key] =dist[key][i];
            }
            dist[key][key] = 0;
        }
        key++;
        return true;
    }
    return false;
}

int getDistance(char nameA[], char nameB[]){
    int a = idx[nameA];
    int b = idx[nameB];
    return dist[a][b];
}

int countMember(char name[], int dis){
    int a = idx[name];
    int answer=0;
    for(int i=0;i<200;i++){
        if(dist[a][i]==dis and a!=i and m[i].name!=""){
            answer++;
        }
    }
    
    return answer;
}
