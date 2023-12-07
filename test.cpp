#include<iostream>
using namespace std;

class Media{
    protected:
        string maPT;
        int namSB;
        float giaBan;
    public:
        Media(string ma_PT = "", int Nam = 0, float gia = 0.0){
            maPT = ma_PT;
            namSB = Nam;
            giaBan = gia;
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
        void setmaPT(int Nam){
            namSB = Nam;
        }
        float get_giaBan(){
            return giaBan;
        }
        void setmaPT(float gia){
            giaBan = gia;
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
    string TenSach, TacGia;
    int so_Trang;
    public:
        Book(string ma_PT = "", int Nam = 0, float gia = 0.0, string name = "", string TG = "", int S_TrangSach = 0):Media::Media(ma_PT, Nam, gia)
        {
            TenSach = name;
            TacGia = TG;
            so_Trang = S_TrangSach;
        }
        string get_TenSach(){
            return TenSach;
        }
        string get_TacGia(){
            return TacGia;
        }
        
        int getso_Trang(){
            return so_Trang;
        }
        void set_TenSach(string name){
            TenSach = name;
        }
        void set_TacGia(string TG){
            TacGia = TG;
        }
        void set_so_Trang(int S_TrangSach){
            so_Trang = S_TrangSach;
        }
        void Nhap_Book(){
            nhap();
            cout<<"nhap ten sach: ";cin.ignore();
            getline(cin, TenSach);
            cout<<"nhap ten tac gia: ";
            getline(cin, TacGia);
            cout<<"nhap so trang: "; cin>>so_Trang;
        }
        void hienThi_Book(){
            hienThi();
            cout<<", "<<"ten sach: "<<TenSach<<", ";
            cout<<"tac gia: "<<TacGia<<", ";
            cout<<"so trang: "<<so_Trang<<"."<<endl;
        }
        bool operator >(Book sach){
            return this->so_Trang > sach.so_Trang;
        }
        bool operator >=(Book sach){
            return this->so_Trang >= sach.so_Trang;
        }
        bool operator <(Book sach){
            return this->so_Trang < sach.so_Trang;
        }
        bool operator <=(Book sach){
            return this->so_Trang <= sach.so_Trang;
        }
        bool operator ==(Book sach){
            return this->so_Trang == sach.so_Trang;
        }
        bool operator !=(Book sach){
            return this->so_Trang != sach.so_Trang;
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
        if(n<51 && n >0) break;
        else{
            cout<<"Nhap sai moi nhap lai!\n";
        }
    }
    Book dsBOOK[n];
    for (int i = 0; i < n; i++){
        cout<<"--------------------------------------------\n";
        cout<<"Nhap cuon sach thu :"<<i+1;
        dsBOOK[i].Nhap_Book(); 
    }
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++)
	        if(dsBOOK[i] > dsBOOK[j])  
		        swap(dsBOOK[i], dsBOOK[j]);
    }

    int Tso_trang = 0;
    float  TGiatri = 0;
    cout<<"Thong tin sach da sap xep theo so trang: \n";
    for (int i = 0; i < n; i++){
        Tso_trang = Tso_trang + dsBOOK[i].getso_Trang();
        TGiatri = TGiatri + dsBOOK[i].get_giaBan();
        cout<<"--------------------------------------------\n";
        cout<<"cuon sach thu :"<<i+1;
        dsBOOK[i].hienThi_Book();   
    }

    float gia_CaoNhat=dsBOOK[n-1].get_giaBan();
    cout<<"Nhung cuon sach co gia cao nhat la: \n";
    for (int i = 0; i < n; i++){
        if(dsBOOK[i].get_giaBan() == gia_CaoNhat){
        cout<<"--------------------------------------------\n";
            cout<<"Cuon sach thu:"<<i+1;
            dsBOOK[i].hienThi_Book(); 
        }
    }cout<<"--------------------------------------------\n";
    cout<<"Tong so trang cua tat ca sach: "<<Tso_trang;
    cout<<"Tong gia tri: "<<TGiatri<<endl;
    string tac_Gia = "";
    cout<<"Nhap ten tac gia muon xoa: "; cin.ignore();
    getline(cin, tac_Gia);
    int j = 0;
    Book dsmoi[n-1];
    for(int i = 0; i < n; i++){
        cout<<dsBOOK[i].get_TacGia();
        if(tac_Gia != dsBOOK[i].get_TacGia()){
            dsmoi[j] = dsBOOK[i]; 
            j++;
        }
    }
 
    cout<<"Danh sach moi la: \n";
    for(int i = 0; i < n-1; i++){
        cout<<"--------------------------------------------\n";
        cout<<"cuon sach thu :"<<i+1;
        dsmoi[i].hienThi_Book();   
    }
}
