#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class item{
    private:

    public:
    string name;
    int qty;
    float price;
    
    item(){};
    item(string n,int q,float p){
        name=n;
        qty=q;
        price=p;
    };
    friend ostream & operator<<(ostream &o,item &i);
    friend ofstream & operator<<(ofstream &ofs,item &i);
    friend ifstream & operator>>(ifstream &ifs,item &i);

};
     ostream & operator<<(ostream &o,item &i){
        o<<i.name<<endl;
        o<<"\t\t\t\t\t"<<i.price<<endl;
        o<<"\t\t\t\t\t"<<i.qty<<endl;
        return o;
    }
     ofstream & operator<<(ofstream &ofs,item &i){
        ofs<<i.name<<endl;
        ofs<<i.price<<endl;
        ofs<<i.qty<<endl;
        return ofs;
    }
     ifstream & operator>>(ifstream &ifs,item &i){
        ifs>>i.name>>i.price>>i.qty;
        return ifs;
    }
int main(){
    int n;
    string str;
    int qt;
    float pr;
    cout<<"Enter the no of items :"<<endl;
    cin>>n;
    cin.ignore();
    item arr[n];
        ofstream of;
        of.open("New_file.txt",ios::trunc);

    for(int i=0;i<n;i++){
        cout<<"Enter the name of item "<<i+1<<" :"<<endl;
        getline(cin,str);
        cout<<"Enter the qty of the item "<<i+1<<" :"<<endl;
        cin>>qt;
        cout<<"Enter the price of the item "<<i+1<<" :"<<endl;
        cin>>pr;
        item it(str,qt,pr);

        arr[i]=it;
        of<<arr[i];
        cin.ignore();
        if(i==n-1){
            of.close();
        }
    }
   ifstream ifs("New_file.txt");
    for(int i=0;i<n;i++){
//    ostream out;
/*use of cout operator is possible under the overloading of insertion operator inside a class*/
   ifs>>arr[i];
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<endl;
    cout<<"\t\t\t\t\t"<<arr[i];
    
    cout<<endl;

    if(i==n-1){
        ifs.close();
    }
    }


    return 0;
}