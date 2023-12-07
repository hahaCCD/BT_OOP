#include<iostream>
using namespace std;

class Media{
    protected:
        string maPT;
        int namSB;
        float giaBan;
    public:
        Media(string ma_PT = "", int year = 0, float price = 0.0){
            maPT = ma_PT;
            namSB = year;
            giaBan = price;
        } 
        string getmaPT(){
            return maPT;
        }
        void setmaPT(string ma_PT){
            maPT = ma_PT;
        }
        int getnamSB(){
            return namSB;
        }
        void setmaPT(int year){
            namSB = year;
        }
        float getgiaBan(){
            return giaBan;
        }
        void setmaPT(float price){
            giaBan = price;
        }
        void nhap(){
            cout<<"Nhap ma PT: ";cin>>maPT;
            // cin.ignore();
            // getline(cin, maPT);
            cout<<"Nhap nam xuat ban: "; cin>>namSB;
            cout<<"Nhap gia ban: "; cin>>giaBan;
        }
        void hienThi(){
            cout<<"Ma phuong tien: "<<maPT<<", ";
            cout<<"nam xuat ban: "<<namSB<<", ";
            cout<<"gia ban: "<<giaBan;
        }
};
class Book: public Media{
    string tenSach, tacGia;
    int soTrang;
    public:
        Book(string ma_PT = "", int year = 0, float price = 0.0, string nameBook = "", string author = "", int bookPageNumber = 0):Media::Media(ma_PT, year, price)
        {
            tenSach = nameBook;
            tacGia = author;
            soTrang = bookPageNumber;
        }
        string get_tenSach(){
            return tenSach;
        }
        string get_tacGia(){
            return tacGia;
        }
        int getso_Trang(){
            return soTrang;
        }
        void set_tenSach(string nameBook){
            tenSach = nameBook;
        }
        void set_tacGia(string author){
            tacGia = author;
        }
        void set_soTrang(int bookPageNumber){
            soTrang = bookPageNumber;
        }
        void Nhap_Book(){
            nhap();
            cout<<"nhap ten sach: ";cin.ignore();
            getline(cin, tenSach);
            cout<<"nhap ten tac gia: ";
            getline(cin, tacGia);
            cout<<"nhap so trang: "; cin>>soTrang;
        }
        void hienThi_Book(){
            hienThi();
            cout<<", "<<"ten sach: "<<tenSach<<", ";
            cout<<"tac gia: "<<tacGia<<", ";
            cout<<"so trang: "<<soTrang<<"."<<endl;
        }
        bool operator >(Book sach){
            return this->soTrang > sach.soTrang;
        }
        bool operator >=(Book sach){
            return this->soTrang >= sach.soTrang;
        }
        bool operator <(Book sach){
            return this->soTrang < sach.soTrang;
        }
        bool operator <=(Book sach){
            return this->soTrang <= sach.soTrang;
        }
        bool operator ==(Book sach){
            return this->soTrang == sach.soTrang;
        }
        bool operator !=(Book sach){
            return this->soTrang != sach.soTrang;
        }
};
int main(){
    // Book a("T01", 2020, 13000, "Tin 12", "Bo giao duc va dao tao", 48);
    // Book b("T01", 2020, 13000, "Tin 12", "Bo giao duc va dao tao", 42);
    // cout<<(a>b);
    // a.hienThi_Book();
    int n = 0;
    while(1){
        cout<<"Nhap so luong sach can nhap(<=50): ";cin>>n;
        if(n<51) break;
        else{
            cout<<"Nhap sai moi nhap lai!\n";
        }
    }
    Book listBook[n];
    for (int i = 0; i < n; i++){
        cout<<"--------------------------------------------\n";
        cout<<"Nhap thong tin sach thu("<<i+1<<")\n";
        listBook[i].Nhap_Book(); 
    }
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++)
	        if(listBook[i] > listBook[j])  
		        swap(listBook[i], listBook[j]);
    }
// ==================================================================
    int tong_SoTrang = 0;
    float  tong_GiaTri = 0;
    cout<<"Thong tin sach da sap xep theo so trang: \n";
    for (int i = 0; i < n; i++){
        tong_SoTrang += listBook[i].getso_Trang();
        tong_GiaTri += listBook[i].getgiaBan();
        cout<<"--------------------------------------------\n";
        cout<<"Thong tin sach thu("<<i+1<<")\n";
        listBook[i].hienThi_Book();   
    }
// ==================================================================
    float gia_CaoNhat=listBook[n-1].getgiaBan();
    cout<<"Nhung cuon sach co gia cao nhat la: \n";
    for (int i = 0; i < n; i++){
        if(listBook[i].getgiaBan() == gia_CaoNhat){
        cout<<"--------------------------------------------\n";
            cout<<"Cuon sach thu("<<i+1<<")\n";
            listBook[i].hienThi_Book(); 
        }
    }cout<<"--------------------------------------------\n";
    cout<<"Tong so trang cua tat ca sach: "<<tong_SoTrang<<" va tong gia tri: "<<tong_GiaTri<<endl;
// ==================================================================
    string tac_Gia = "";
    int new_index = 0;
    Book newListBook[n-1];
    cout<<"--------------------------------------------\n";
    cout<<"Nhap ten tac gia muon xoa: ";cin.ignore();
    getline(cin, tac_Gia);
    // cout<<"Ten tac gia la: "<<listBook[1].get_tacGia();
    for(int i = 0; i < n; i++){
        if(tac_Gia != listBook[i].get_tacGia()){
            newListBook[new_index] = listBook[i]; 
            new_index ++;
        }
    }
    cout<<"Danh sach moi la: \n";
    for(int i = 0; i < n-1; i++){
        cout<<"--------------------------------------------\n";
        cout<<"Thong tin sach thu("<<i+1<<")\n";
        newListBook[i].hienThi_Book();   
    }
}