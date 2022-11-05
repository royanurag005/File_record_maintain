#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
class Item{
    private:
    string str;
    int qty;
    float price;
    public:
    Item(){

    };
    Item (string s,int qt,float pr){
        str=s;
        qty=qt;
        price=pr;
    }
    friend ifstream & operator>>(ifstream & ifs,Item &i);
    friend ofstream & operator<<(ofstream & ofs,Item &i);
    friend ostream & operator<<(ostream & o,Item &i);
};
    ofstream & operator<<(ofstream & ofs,Item &i){
        ofs<<i.str<<endl;
        ofs<<i.qty<<endl;
        ofs<<i.price<<endl;
        return ofs; 
    }
    ifstream & operator>>(ifstream & ifs,Item &i){
        ifs>>i.str>>i.qty>>i.price;
        return ifs;
    }
    ostream & operator<<(ostream &o,Item &i){
        o<<i.str<<endl;
        o<<i.qty<<endl;
        o<<i.price<<endl;
        return o;
    }
int main(){
    int n;
    cout<<"Enter the no of items you want to insert :"<<endl;
    cin>>n;
    cin.ignore();
    vector<Item>v;
    string str;
    int qty;
    float price;
    ofstream ofs;
    ofs.open("Newnewnew.txt",ios::app);
    for(int i=0;i<n;i++){
        cout<<"Enter the name of the item-"<<i+1<<":"<<endl;
        getline(cin,str);
        cout<<"Enter the quantity of item-"<<i+1<<":"<<endl;
        cin>>qty;
        cout<<"Enter the price of item-"<<i+1<<":"<<endl;
        cin>>price;
        cin.ignore();
        Item vv(str,qty,price);
        v.push_back(vv);
        vector<Item>::iterator it;
        it=v.begin();
        for(;it!=v.end();it++){
            ofs<<(*it)<<endl;
        }
        if(i==n-1){
            ofs.close();
        }
    }
    ifstream ifs;
    ifs.open("Newnewnew.txt");
    if(!(ifs.is_open())){
        cout<<"File is not found"<<endl;
    }
    for(int i=0;i<n;i++){
        for(auto x:v){
            Item i=x;
            cout<<x<<endl;

        }
        if(i==n-1){
            ifs.close();
        }
    }



    return 0;
}