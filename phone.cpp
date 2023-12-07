#include<iostream>
using namespace std;
class Phone{	
	protected: 
		string tenDT, hangSX;
		int namSH;
		float giaGoc;
	public:
		Phone(string namePhone = "", string phoneCompany = "", int year = 0, float price = 0){
			tenDT = namePhone;
			hangSX = phoneCompany;
			namSH = year;
			giaGoc =  price;
		}
		string gettenDT(){
			return tenDT;
		}
		void settenDT(string namePhone){
			tenDT = namePhone;
		}
		string gethangSX(){
			return hangSX;
		}
		void sethangSX(string phoneCompany){
			hangSX = phoneCompany;
		}
		float getgiaGoc(){
			return giaGoc;
		}
		void setgiaGoc(float price){
			giaGoc = price;
		}
		int getnamSH(){
			return namSH;
		}
		void setnamSH(int year){
			namSH = year;
		}
		void nhap(){
			cout<<"Nhap ten dien thoai: ";cin.ignore();
			getline(cin, tenDT);
			
			cout<<"Nhap hang DT: ";cin.ignore();
			getline(cin, hangSX);
			
			cout<<"Nhap nam: "; cin>>namSH;
			cout<<"Nhap gia goc: "; cin>>giaGoc;
		}
		void hienThi(){
			cout<<"Tenm dien thoai la: "<<tenDT<<endl;
			cout<<"Dien thoai co hang: "<<hangSX<<endl;
			cout<<"Nam DT ra mat la: "<<namSH<<endl;
			cout<<"Gia goc: "<<giaGoc<<endl;
		}
		bool operator<(const Phone& other) {
        	return tenDT < other.tenDT;
    	}
		bool operator>(const Phone& other) {
        	return tenDT > other.tenDT;
		}	 
		
		bool operator==(const Phone& other) {
        	return tenDT == other.tenDT;
    	}
};
// ================================================
class smatPhone : public Phone{
	float tocDoChip, kichThuocManHinh, giaTriConLai;
	int socamera;
	public:
		smatPhone(float tDChip =  0, float kTManhinh = 0, int soCMR = 0, string namePhone = "", string phoneCompany = "", int year = 0, float price = 0):Phone::Phone(namePhone, phoneCompany, year, price){
			tocDoChip = tDChip;
			kichThuocManHinh = kTManhinh;
			socamera = soCMR;
		}
		float gettocDoChip(){
			return tocDoChip;
		}
		void settocDoChip(float tDChip){
			tocDoChip = tDChip;
		}
		float getgiaTriConLai(){
			return giaTriConLai;
		}
		void setgiaTriConLai(float gTCL){
			giaTriConLai = gTCL;
		}
		float getkichThuocManHinh(){
			return kichThuocManHinh;
		}
		void setkichThuocManHinh(float kTManhinh){
			kichThuocManHinh = kTManhinh;
		}
		int getsocamera(){
			return socamera;
		}
		void settocDoChip(int soCMR){
			socamera = soCMR;
		}
		void Nhap(){
			nhap();
			cout<<"Nhap toc do chip: ";cin>> tocDoChip;
			cout<<"Nhap kich thuoc man hinh: ";cin>> kichThuocManHinh;
			cout<<"Nhap so camera: "; cin>> socamera;
			cout<<"=================================================\n";
		}
		void hienThiSMP(){
			float soNamSH;
			soNamSH = 2023 - float(namSH);
			giaTriConLai = giaGoc - (soNamSH*(2/100)*giaGoc);
			hienThi();
			cout<<"Toc do chip: "<<tocDoChip<<endl;
			cout<<"Kich thuoc man hinh: "<<kichThuocManHinh<<endl;
			cout<<" So camera: "<<socamera<<endl;
			cout<<"So nam xuat hien: "<<soNamSH<<endl;
			if(giaTriConLai < 0){
				cout<<"Gia tri con lai bang 0. "<<endl;	
			}else
				cout<<"Gia tri con lai: "<<giaTriConLai<<endl;
		}
};
int main(){
	// Phone a("omegaa2");
	// // a.nhap();
	// // a.hienThi();
	// Phone b("omega");
	// cout<< (a > b);
	// smatPhone c(1,1,1,"a","c",2016,3);
	// c.Nhap();
	
	// for (int i= 0; i < n; i++){
	// 	cout<<"nhap thong tin samtphone thu ("<<i+1<<")\n";
	// 	ListSMP[i].Nhap();
	// }
	int n = 3;
	smatPhone ListSMP[n];
	ListSMP[0]=smatPhone(6,7,8,"a25","samsum",2017,4);
	ListSMP[1]=smatPhone(4,6,6,"a23","samsum",2016,3);
	ListSMP[2]=smatPhone(7,8,9,"a24","samsum",2018,5);
	string trgian="";
	float tg = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
			float soNamSH, giaTriConLai;
			soNamSH = 2023 - float(ListSMP[i].getnamSH());
			ListSMP[i].setgiaTriConLai(ListSMP[i].getgiaGoc() - (soNamSH*(2/100)*ListSMP[i].getgiaGoc()));
			ListSMP[j].setgiaTriConLai(ListSMP[j].getgiaGoc() - (soNamSH*(2/100)*ListSMP[j].getgiaGoc()));
            if(ListSMP[i].gettenDT() > ListSMP[j].gettenDT() ){
                // Hoan vi 2 so ListSMP[i] va ListSMP[j]
                trgian = ListSMP[i].gettenDT() ;
                ListSMP[i].settenDT(ListSMP[j].gettenDT()) ;
                ListSMP[j].settenDT(trgian) ;        
            }
			if(ListSMP[i].getgiaTriConLai() > ListSMP[j].getgiaTriConLai() ){
                // Hoan vi 2 so ListSMP[i] va ListSMP[j]
                tg = ListSMP[i].getgiaTriConLai() ;
                ListSMP[i].setgiaTriConLai(ListSMP[j].getgiaTriConLai()) ;
                ListSMP[j].setgiaTriConLai(tg) ;        
            }
        }
    }
	for (int i = 0; i < n; i++){
		cout<<ListSMP[i].gettenDT()<<" ";
	}
    cout<<"Gia tri con lai lon nhat la cua "<<ListSMP[n-1].gettenDT()<<": "<<ListSMP[n-1].getgiaTriConLai();
}
