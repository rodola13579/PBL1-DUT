#include<iostream>
#include "termcolor.hpp"
#include<string>
#include<fstream>
#include<iomanip>
#include<vector>
#include <sstream>
using namespace std;
void print(int n){
	cout<<"+";
	for(int i=0;i<n;i++){
		cout<<char(196);
	}
}
string thuong(string s){
	for(int i = 0; i < s.size(); i++){
		s[i] = tolower(s[i]);
	}
	return s;
}
class Lichtrinh{
	public:
		int i;
		vector<string>ngay;
		string time[15];
		string vitri[15];
};
class Tauthuyen{
	private:
		string ten;
		string loaitau;
		string chu_tau;
		int taitrong;
		string trangthai;
		Lichtrinh lt;
		string nation;
	public:
		//lay ten
		string getten(){
			return ten;
		}
		void setten(string ten){
			this->ten=ten;
		}
		//lay type tau
		string getloaitau(){
			return loaitau;
		}
		void setloaitau(string loai){
			this->loaitau=loai;
		}
		//chu tau
		string getchutau(){
			return chu_tau;
		} 
		void setchutau(string chutau){
			this->chu_tau=chutau;
		}
		//tai trong
		int gettaitrong(){
			return taitrong;
		}
		void settaitrong(int TL){
			this->taitrong=TL;
		}
		// trang thai
		string gettrangthai(){
		return this->trangthai;
		}
		void settrangthai(string TT){
			this->trangthai=TT;
		}
		// quoc gia
		string getnation(){
			return this->nation;
		}
		void setnation(string nt){
			this->nation=nt;
		}
		// lich trinh
		Lichtrinh getlichtrinh(){
			return lt;
		}
		void setlichtrinh(int i){
			string day;
			cout<<"nhap ngay/thang/nam    : ";
			getline(cin,day);
			lt.ngay.push_back(day);
			cout<<"nhap vi tri tau den(word)     :";
			getline(cin,lt.vitri[i]);
			cout<<"nhap thoi gian (gio)h(phut)-(gio)h(phut):" ;
			getline(cin,lt.time[i]);
		}
		void nhaplichtrinhvaofile(ofstream &ofs){
			for(int j=0;j<lt.i;j++){
				ofs<<lt.ngay[j]<<">"<<lt.time[j]<<">"<<lt.vitri[j];
				if(j==lt.i-1){
					ofs<<"#, ";
					break;
				}
				ofs<<"#>";
			}
		}
		bool tradiadiem(string diadiem){
			for(int j=0;j<lt.i;j++){
				if(thuong(this->lt.vitri[j]).find(thuong(diadiem))!=string::npos){
					return 1;
				}
			}
			return 0;	
		}
		//nhapthong tin 
		void nhapthongtin(string themtype){
			this->loaitau=themtype;
			cout<<"Quoc gia cua tau(word)    :";
			getline(cin,this->nation);
			cout<<"Nhap name(word)           :";
			getline(cin,this->ten);
			cout<<"Chu tau(word)             :";
			getline(cin,this->chu_tau);
			cout<<"Trong luong tau(number)   :";
			cin>>this->taitrong;
			cin.ignore();
			cout<<"Trang thai hoat dong(word):";
			getline(cin,this->trangthai);
			cout<<"So dia diem tau den(number):";
			cin>>this->lt.i;
			cin.ignore();
			for(int j=0;j<lt.i;j++){
				setlichtrinh(j);
			}
		}
		//doc file
		void doc_file(ifstream&);	
		void xuat_thongtin(){
			cout<<char(179)<<setw(8)<<left<<this->loaitau<<char(179)<<setw(15)<<left<<this->nation<<char(179)<<setw(15)<<left<<this->ten<<char(179)
			<<setw(28)<<left<<this->chu_tau<<char(179)<<setw(10)<<left<<this->taitrong<<char(179)<<setw(15)<<left<<this->trangthai<<char(179);
		}
		void xuat_thongtinlichtrinh(){
			for(int j=0;j<lt.i;j++){
				string str="("+lt.ngay[j]+")";
			cout<<setw(37)<<str<<char(179)<<endl;str=" #"+lt.time[j]+"->"+lt.vitri[j];
			cout<<char(179)<<setw(3)<<" "<<char(179)<<setw(8)<<" "<<char(179)<<setw(15)<<" "<<char(179)<<setw(15)<<" "<<char(179)<<setw(28)<<" "<<char(179)<<setw(10)<<" "<<char(179)
		    <<setw(15)<<" "<<char(179)<<setw(11)<<" "<<char(179)<<setw(13)<<" "<<char(179)<<setw(37)<<str<<char(179)<<endl;
			if(j+1!=lt.i){
		    cout<<char(179)<<setw(3)<<" "<<char(179)<<setw(8)<<" "<<char(179)<<setw(15)<<" "<<char(179)<<setw(15)<<" "<<char(179)<<setw(28)<<" "<<char(179)<<setw(10)<<" "<<char(179)
		    <<setw(15)<<" "<<char(179)<<setw(11)<<" "<<char(179)<<setw(13)<<" "<<char(179);
			}
			}
			print(3);print(8);print(15);print(15);print(28);print(10);print(15);print(11);print(13);print(37);cout<<"+"<<endl;
		}	
		
};


void Tauthuyen::doc_file(ifstream& fs){
			getline(fs,nation,',');
			fs.ignore(1);
			getline(fs,ten,',');
			fs.ignore(1);
			getline(fs,chu_tau,',');
			fs.ignore(1);
			fs>>taitrong;
			fs.ignore(2);
			getline(fs,trangthai,',');
			fs.ignore(1);
			int j=0; 
			while(true){
				char a;
				string str;
				getline(fs,str,'>');
				lt.ngay.push_back(str);
				getline(fs,lt.time[j],'>');
				getline(fs,lt.vitri[j],'#');
				j++;
				fs>>a;
				if(a==','){
					break;
				}
				
			}
			lt.i=j;
				
		}
class Dulich : public Tauthuyen{
	private:
		int SLkhach;//So luong khach
		int succhua;//suc chua
	public:
		Dulich(){
			//dung xoa
		}
//		So luong khach
		int getSLkhach(){
			return this->SLkhach;
		}
		void setSLkhach(int SL){
			this->SLkhach=SL;
		}
		//suc chua
		int getsucchua(){
			return this->succhua;
		}
		
		//ham doc file cua du lich
		void doc_filedulich(ifstream& fs){
			Tauthuyen::doc_file(fs);
			fs.ignore(1);
			fs>>this->succhua;
			fs.ignore(2);
			fs>>this->SLkhach;
			fs.ignore();
		}
		//ham xuat file
		void xuat_thongtindulich(){
			Tauthuyen::xuat_thongtin();
			cout<<left<<setw(11)<<this->succhua<<char(179)<<left<<setw(13)<<this->SLkhach<<char(179);
			Tauthuyen::xuat_thongtinlichtrinh();
		}
		//nhap thong tin tau du lich
		void nhapthongtindulich(string themtype){
			cout<<setw(103)<<internal<<"   ==CAC DIA DIEM TAU DU LICH CO THE DEN==   "<<endl;
		    cout<<setw(103)<<internal<<"============================================="<<endl;
			cout<<setw(103)<<internal<<"||1.ben du thuyen Song Han                 ||"<<endl;
           	cout<<setw(103)<<internal<<"||2.cau Thuan Phuoc                        ||"<<endl;
	        cout<<setw(103)<<internal<<"||3.cau Tran Thi Ly                        ||"<<endl;
	        cout<<setw(103)<<internal<<"||4.cau Rong                               ||"<<endl;
	        cout<<setw(103)<<internal<<"||5.cau Tien Sa                            ||"<<endl;
	        cout<<setw(103)<<internal<<"============================================="<<"\n\n"<<endl;
			Tauthuyen::nhapthongtin(themtype);
			cout<<"nhap suc chua cua tau:";
			cin>>this->succhua;
			cout<<"nhap so luong khach tren tau:";
			cin>>this->SLkhach;
			cin.ignore();
		}
		
		
};
class Chohang : public Tauthuyen{
	private:
		int TL_hang;//trong luong hang
		vector<string>loaihang;// type hang
	public:
		int sl_loaihang;
		Chohang(){
		}
		//trong luong hang
		int getTL_hang(){
			return this->TL_hang;
		}
		void setTL_hang(int TL){
			this->TL_hang=TL;
		}
		//type hang
		vector<string> getloaihang(){
			return this->loaihang;
		}
		void setloaihang(vector<string> loai){
			this->loaihang=loai;
		}
		//nhap hang vao file
		void nhaploaihangvaofile(ofstream &ofs){
			for(int i=0;i<sl_loaihang;i++){
				ofs<<loaihang[i]<<"#";
				if(i==sl_loaihang-1){
					ofs<<", ";
					break;
				}
				ofs<<"-";
			}
		}
		// doc file cua cho hang
		void doc_filechohang(ifstream& fs){
			Tauthuyen::doc_file(fs);
			fs.ignore(1);
			while(true){
			    string loai;
				char a;
				getline(fs,loai,'#');
				fs>>a;
				loaihang.push_back(loai);
				if(a==','){
					break;
				}
			}
			sl_loaihang=loaihang.size();
			fs.ignore(1);
			fs>>this->TL_hang;
			fs.ignore();	
		}
		// xuat file cua cho hang
		void xuat_thongtinchohang(){
			Lichtrinh lt=getlichtrinh();
			Tauthuyen::xuat_thongtin();
			cout<<setw(14)<<left<<loaihang[0]<<char(179)<<setw(13)<<left<<this->TL_hang<<char(179);string str="("+lt.ngay[0]+")";
			cout<<setw(34)<<str<<char(179)<<endl;str=" #"+lt.time[0]+"->"+lt.vitri[0];
			if(loaihang.size()>1){
				cout<<char(179)<<setw(3)<<" "<<char(179)<<setw(8)<<" "<<char(179)<<setw(15)<<" "<<char(179)<<setw(15)<<" "<<char(179)<<setw(28)<<" "<<char(179)<<setw(10)<<" "<<char(179)
		    <<setw(15)<<" "<<char(179)<<setw(14)<<loaihang[1]<<char(179)<<setw(13)<<" "<<char(179)<<setw(34)<<str<<char(179)<<endl;
			}
			else{cout<<char(179)<<setw(3)<<" "<<char(179)<<setw(8)<<" "<<char(179)<<setw(15)<<" "<<char(179)<<setw(15)<<" "<<char(179)<<setw(28)<<" "<<char(179)<<setw(10)<<" "<<char(179)
		    <<setw(15)<<" "<<char(179)<<setw(14)<<" "<<char(179)<<setw(13)<<" "<<char(179)<<setw(34)<<str<<char(179)<<endl;
			}
			int a=2;
			int b=1;
			while(a<loaihang.size()||b<lt.i){
				cout<<char(179)<<setw(3)<<" "<<char(179)<<setw(8)<<" "<<char(179)<<setw(15)<<" "<<char(179)<<setw(15)<<" "<<char(179)<<setw(28)<<" "<<char(179)<<setw(10)<<" "<<char(179)
		    <<setw(15)<<" "<<char(179);
				if(a<loaihang.size()){
					cout<<setw(14)<<left<<loaihang[a]<<char(179)<<setw(13)<<left<<" "<<char(179);
					a++;
				}
				else{cout<<setw(14)<<left<<" "<<char(179)<<setw(13)<<left<<" "<<char(179);
				}
				if(b<lt.i){
					string str;
					str="("+lt.ngay[b]+")";
					cout<<setw(34)<<str<<char(179)<<endl;
					cout<<char(179)<<setw(3)<<" "<<char(179)<<setw(8)<<" "<<char(179)<<setw(15)<<" "<<char(179)<<setw(15)<<" "<<char(179)<<setw(28)<<" "<<char(179)<<setw(10)<<" "<<char(179)
		                <<setw(15)<<" "<<char(179);
					if(a<loaihang.size()){
						cout<<setw(14)<<left<<loaihang[a]<<char(179)<<setw(13)<<left<<" "<<char(179);
					a++;;
					}
					else{cout<<setw(14)<<left<<" "<<char(179)<<setw(13)<<left<<" "<<char(179);
				   }
				   str=" #"+lt.time[b]+"->"+lt.vitri[b];
				   cout<<setw(34)<<str<<char(179)<<endl;
				   b++;
				}
				else{cout<<setw(34)<<" "<<char(179)<<endl;
				}
			}
			print(3);print(8);print(15);print(15);print(28);print(10);print(15);print(14);print(13);print(34);cout<<"+"<<endl;
		}
		//nhap thong tin tau cho hang
		void nhapthongtinchohang(string themtype){
			cout<<setw(103)<<internal<<"  ==CAC DIA DIEM TAU CHO HANG CO THE DEN==  "<<endl;
		    cout<<setw(103)<<internal<<"============================================"<<endl;
			cout<<setw(103)<<internal<<"||1.ben thuyen Song Han                    ||"<<endl;
            cout<<setw(103)<<internal<<"||2.cau Thuan Phuoc                        ||"<<endl;
	        cout<<setw(103)<<internal<<"||3.cau Tran Thi Ly                        ||"<<endl;
	        cout<<setw(103)<<internal<<"||4.cau Rong                               ||"<<endl;
	        cout<<setw(103)<<internal<<"||5.cau Tien Sa                            ||"<<endl;
	        cout<<setw(103)<<internal<<"||6.ben hang Song Han                      ||"<<endl;
	        cout<<setw(103)<<internal<<"============================================="<<"\n\n"<<endl;
			Tauthuyen::nhapthongtin(themtype);
			cout<<"SO LOAI HANG BAN MUON NHAP :";
			cin>>sl_loaihang;cin.ignore();
			for(int i=0;i<sl_loaihang;i++){
				string str;
			    cout<<"loai hang :";
			    getline(cin,str);
			    loaihang.push_back(str);
		}
			cout<<"khoi luong hang :";
			cin>>this->TL_hang;
			cin.ignore();
		}
};
class Fish : public Tauthuyen{
	private:
		int dai;
		string size;
//		string xep_loai_size_tau;
	public:
		Fish(){
			//de delete
		}
		//dai
		int getdai(){
			return this->dai;
		}
		void setdai( int dai){
			this->dai=dai;
		}
		//doc file tau danh ca
		void doc_filedanhca(ifstream& fs){
			Tauthuyen::doc_file(fs);
			fs.ignore(1);
			fs>>this->dai;
			if(this->dai<6){
				size="tau nho";
			}
			else if(6<=this->dai<12){
				size="tau TB";
			}
			else if(this->dai>=12){
				size="tau lon";
			}
			fs.ignore();
		}
		//xuat thong tin tau danh ca
		void xuat_thongtindanhca(){
			Tauthuyen::xuat_thongtin();
			cout<<setw(11)<<left<<this->dai<<char(179)<<setw(13)<<left<<this->size<<char(179);
			Tauthuyen::xuat_thongtinlichtrinh();
		}
		//nhap thong tin danh ca
		void nhapthongtintaudanhca(string themtype){
			cout<<setw(101)<<internal<<termcolor::cyan<<"  ==CAC DIA DIEM TAU DANH CA CO THE NEO DAU==  "<<termcolor::reset<<endl;
			    cout<<setw(101)<<internal<<termcolor::cyan<<"================================================"<<termcolor::reset<<endl;
				cout<<setw(101)<<internal<<termcolor::cyan<<"||1.cua bien Dang Nang                        ||"<<termcolor::reset<<endl;
            	cout<<setw(101)<<internal<<termcolor::cyan<<"||2.cau Thuan Phuoc                           ||"<<termcolor::reset<<endl;
	            cout<<setw(101)<<internal<<termcolor::cyan<<"||3.cau Tran Thi Ly                           ||"<<termcolor::reset<<endl;
	            cout<<setw(101)<<internal<<termcolor::cyan<<"||4.cau Rong                                  ||"<<termcolor::reset<<endl;
	            cout<<setw(101)<<internal<<termcolor::cyan<<"||5.cau Tien Sa                               ||"<<termcolor::reset<<endl;
	            cout<<setw(101)<<internal<<termcolor::cyan<<"||6.ben hang hoa Song Han                     ||"<<termcolor::reset<<endl;
	            cout<<setw(101)<<internal<<termcolor::cyan<<"================================================"<<termcolor::reset<<"\n\n"<<endl;
			Tauthuyen::nhapthongtin(themtype);
			cout<<"nhap chieu dai tau :";
			cin>>this->dai;
			if(this->dai<6){
				this->size="tau nho";
			}
			else if(6<=this->dai<12){
				this->size="tau TB";
			}
			else if(this->dai>=12){
				this->size="tau lon";
			}
			
		} 
};
void inthongtindautrangdulich(){
	cout<<setw(98)<<internal<<"---THONG TIN TAU THUYEN DU LICH---"<<endl;
	        print(3);print(8);print(15);print(15);print(28);print(10);print(15);print(11);print(13);print(37);cout<<"+"<<endl;
		//in thong tin tau du lich
			cout<<char(179)<<"STT"<<char(179)<<setw(8)<<left<<"LOAI"<<char(179)<<setw(15)<<left<<"QUOC GIA"<<char(179)<<setw(15)<<left<<"TEN THUYEN"<<char(179)<<setw(28)<<left<<"CHU SO HUU"<<"|"<<setw(10)<<left<<"TAI TRONG"<<char(179)
			<<setw(15)<<left<<"TRANG TRANG"<<char(179)<<setw(11)<<left<<"SUC CHUA"<<char(179)<<setw(13)<<left<<"SL KHACH"<<char(179)<<setw(37)<<left<<"LICH TRINH CUA TAU"<<char(179)<<endl;
			print(3);print(8);print(15);print(15);print(28);print(10);print(15);print(11);print(13);print(37);cout<<"+"<<endl;
		//IN DAU TRANG
}
void inthongtindautrangchohang(){
	//IN THONG TIN CHO HANG
			cout<<setw(98)<<internal<<"---THONG TIN TAU THUYEN CHO HANG---"<<endl;
			print(3);print(8);print(15);print(15);print(28);print(10);print(15);print(14);print(13);print(34);cout<<"+"<<endl;
			cout<<char(179)<<"STT"<<char(179)<<setw(8)<<left<<"LOAI"<<char(179)<<setw(15)<<left<<"QUOC GIA"<<char(179)<<setw(15)<<left<<"TEN THUYEN"<<char(179)<<setw(28)<<left<<"CHU SO HUU"<<char(179)<<setw(10)<<left<<"TAI TRONG"<<char(179)
			<<setw(15)<<left<<"TRANG THAI"<<char(179)<<setw(14)<<left<<"LOAI HANG"<<char(179)<<setw(13)<<left<<"TL HANG(TAN)"<<char(179)<<setw(34)<<left<<"LICH TRINH CUA TAU"<<char(179)<<endl;
			print(3);print(8);print(15);print(15);print(28);print(10);print(15);print(14);print(13);print(34);cout<<"+"<<endl;
		//IN DAU TRANG
}
void inthongtindautrangdanhca(){
	//IN THONG TIN TAU DANH CA
			cout<<setw(98)<<internal<<"---THONG TIN TAU THUYEN DANH CA---"<<endl;
			print(3);print(8);print(15);print(15);print(28);print(10);print(15);print(11);print(13);print(37);cout<<"+"<<endl;
			cout<<char(179)<<"STT"<<char(179)<<setw(8)<<left<<"LOAI"<<char(179)<<setw(15)<<left<<"QUOC GIA"<<char(179)<<setw(15)<<left<<"TEN THUYEN"<<char(179)<<setw(28)<<left<<"CHU SO HUU"<<char(179)<<setw(10)<<left<<"TAI TRONG"<<char(179)
			<<setw(15)<<left<<"TRANG THAI"<<char(179)<<setw(11)<<left<<"CHIEU DAI"<<char(179)<<setw(13)<<left<<"SIZE TAU"<<char(179)<<setw(37)<<left<<"LICH TRINH CUA TAU"<<char(179)<<endl;
			print(3);print(8);print(15);print(15);print(28);print(10);print(15);print(11);print(13);print(37);cout<<"+"<<endl;
	//IN DAU TRANG
}
float chuyenchuoi(string chuoi){//chuyen chuoi thanh so
    stringstream ss(chuoi);
	string hour,minute;
    getline(ss,hour,'h');
	getline(ss,minute,'h');
	float a,b,c;
	a= stof(hour);
	b= stof(minute);
	return c=a+b/60;
}
string chuyenngay(string ngay){
	int i,j,k;
	stringstream ss(ngay);
	string b,c,d;
	getline(ss,b,'/');
	getline(ss,c,'/');
	getline(ss,d,'/');
	i= stof(b);
	j= stof(c);
	k= stof(d);
	return to_string (i)+"/"+to_string (j)+"/"+to_string (k);
} 
bool sosanh(string ngay1,string gio1,string ngay2,string gio2){//so sanh 2 lich trinh
	int x,y;
	stringstream aa(gio1);
	stringstream bb(gio2);
	string c[4];
	getline(aa,c[0],'-');
	getline(aa,c[1],'-');
	getline(bb,c[2],'-');
	getline(bb,c[3],'-');
	if(chuyenngay(ngay1)==chuyenngay(ngay2)){
	    if(chuyenchuoi(c[0])<chuyenchuoi(c[3])&&chuyenchuoi(c[3])<chuyenchuoi(c[1])){
	    	return 1;
	    }
	    else if(chuyenchuoi(c[2])<chuyenchuoi(c[1])&&chuyenchuoi(c[1])<chuyenchuoi(c[3])){
	    	return 1;
    	}
    	else{return 0;}
     }
	else{  
		return 0;
	}
}
bool tra_lichtrinh(Chohang *ch[],Dulich *dl[],Fish *ca[],int x,int y,int z,string diadiem, string tg, string ngay){//tra ve gia tri dung neu lich trinh da kin
	Lichtrinh lt;
	int dem=0;
	for(int i=0;i<x;i++){
		lt=dl[i]->getlichtrinh();
		for(int j=0;j<lt.i;j++){
			if(thuong(diadiem)==thuong(lt.vitri[j])){
				if(sosanh(ngay,tg,lt.ngay[j],lt.time[j])){
					dem++;
				}
			}
		}
	}
	for(int i=0;i<y;i++){
		lt=ch[i]->getlichtrinh();
		for(int j=0;j<lt.i;j++){
			if(thuong(diadiem)==thuong(lt.vitri[j])){
				if(sosanh(ngay,tg,lt.ngay[j],lt.time[j])){
					dem++;
				}
			}
		}
	}
	for(int i=0;i<z;i++){
		lt=ch[i]->getlichtrinh();
		for(int j=0;j<lt.i;j++){
			if(thuong(diadiem)==thuong(lt.vitri[j])){
				if(sosanh(ngay,tg,lt.ngay[j],lt.time[j])){
					dem++;
				}
			}
		}
	}
	return dem>=5;
}
int tra_loaihang(string loaihang){
	int n;
	ifstream ifs;
	ifs.open("ds_hangcam.txt");
	if(ifs.is_open()){
	ifs>>n;
	ifs.ignore();
	string *hangcam=new string[n];
	for(int i=0;i<n;i++){
		getline(ifs,hangcam[i]);
		if(loaihang==hangcam[i]){
			return 1;
		}
		}
	ifs.close();
}
	
else{
	cout<<"ko mo";
}
	return 0;
	 
}
void capnhat_file(Chohang *ch[],Dulich *dl[],Fish *ca[],int x,int y,int z){
	ofstream ofs;
			ofs.open("ds_boats.txt",ios_base::out);
			ofs.seekp(0,ios_base::beg);
			ofs<<x+y+z;
			//nhap du lich
			for(int i=0;i<x;i++){
				ofs<<endl<<dl[i]->getloaitau()<<", "<<dl[i]->getnation()<<", "<<dl[i]->getten()<<", "<<dl[i]->getchutau()<<", "<<dl[i]->gettaitrong()<<", "<<dl[i]->gettrangthai()<<", ";
				dl[i]->nhaplichtrinhvaofile(ofs);
				ofs<<dl[i]->getsucchua()<<", "<<dl[i]->getSLkhach();
			}
			//nhap cho hang
			for(int w=0;w<y;w++){
				ofs<<endl<<ch[w]->getloaitau()<<", "<<ch[w]->getnation()<<", "<<ch[w]->getten()<<", "<<ch[w]->getchutau()<<", "<<ch[w]->gettaitrong()<<", "<<ch[w]->gettrangthai()<<", ";
				ch[w]->nhaplichtrinhvaofile(ofs);
				ch[w]->nhaploaihangvaofile(ofs);
				ofs<<ch[w]->getTL_hang();
			}
			//nhap danh ca
			for(int e=0;e<z;e++){
				ofs<<endl<<ca[e]->getloaitau()<<", "<<ca[e]->getnation()<<", "<<ca[e]->getten()<<", "<<ca[e]->getchutau()<<", "<<ca[e]->gettaitrong()<<", "<<ca[e]->gettrangthai()<<", ";
				ca[e]->nhaplichtrinhvaofile(ofs);
				ofs<<ca[e]->getdai();
			}
			ofs.close();
}
void xoadata_file(Chohang *ch[],Dulich *dl[],Fish *ca[],int &x,int &y,int &z,string dlete){
	//tim dulich
	for(int q=0;q<x;q++){
	 if(thuong(dl[q]->getten())==thuong(dlete)){
		inthongtindautrangdulich();
		cout<<char(179)<<setw(3)<<internal<<q;
		dl[q]->xuat_thongtindulich();
		for(int j=q;j<x;j++){
		   dl[j]=dl[j+1];
		   }
		x--;
		dl[x]=new Dulich();//reset lai du lieu trong doi tuong
		delete dl[x];//giai phong xoa doi tuong
		break;
		}	  
	}
	//tim cho hang
	for(int w=0;w<y;w++){
	   if(thuong(ch[w]->getten())==thuong(dlete)){
	      for(int t=w;t<y;t++){//dua phan tu mang can xoa xuong cuoi mang
		     ch[t]=ch[t+1];
			}
		y--;
		ch[y]=new Chohang();//reset lai du lieu trong doi tuong
		delete ch[y];//giai phong doi tuong
		break;	    
		}
	}
	//tim danh ca
	for(int e=0;e<z;e++){
	   if(thuong(ca[e]->getten())==thuong(dlete)){
	      for(int f=e;f<z;f++){//dua phan tu mang can xoa xuong cuoi mang
		    ca[f]=ca[f+1];
			}
		z--;
		ca[z]=new Fish();//reset
		delete ca[z];//giai phong
		break;      
		}
	}
	capnhat_file(ch,dl,ca,x,y,z);
}
void themtau(Chohang *ch[],Dulich *dl[],Fish *ca[],int &x,int &y,int &z,string themtype){
	Lichtrinh lt;
				if(themtype=="du lich"){
				    dl[x]=new Dulich(); 
					dl[x]->nhapthongtindulich(themtype);
					lt=dl[x]->getlichtrinh();
					for(int i=0;i<lt.i;i++){
					if(tra_lichtrinh(ch,dl,ca,x-1,y,z,lt.vitri[i],lt.time[i],lt.ngay[i])){
						cout<<"\n\nLICH TRINH "<<lt.time[i]<<"->"<<lt.vitri[i]<<"\n(!)vi ly do da kin thuyen\n *Hay thay doi lich trinh(!)"<<endl;
						dl[x]->setlichtrinh(i);i--;
						lt=dl[x]->getlichtrinh();
					}
				}
				x++;
				if(dl[x-1]->gettaitrong()>2000){
					cout<<"\n\n(!) TAI TRONG BAN DA VUOT QUA QUY DINH VI LY DO AN TOAN GIAO THONG TAU KHONG DUOC VAO(!)\n";
					xoadata_file(ch,dl,ca,x,y,z,dl[x-1]->getten());
					cout<< termcolor::underline<<termcolor::green<<"(#)THUYEN DA XOA KHOI DANH SACH"<<termcolor::reset<<endl;
				}
				}
				else if(themtype=="cho hang"){
					ch[y]=new Chohang();
					ch[y]->nhapthongtinchohang(themtype);
					lt=ch[y]->getlichtrinh();
					for(int i=0;i<lt.i;i++){
					if(tra_lichtrinh(ch,dl,ca,x,y-1,z,lt.vitri[i],lt.time[i],lt.ngay[i])){
						cout<<"\n\nLICH TRINH "<<lt.time[i]<<"->"<<lt.vitri[i]<<"\n(!)vi ly do da kin thuyen\n *Hay thay doi lich trinh(!)"<<endl;
						ch[y]->setlichtrinh(i);i--;
						lt=ch[y]->getlichtrinh();
					 }
			    	}
			    	y++;
			    	for(int i=0;i<ch[y-1]->sl_loaihang;i++){
			    	vector<string> str=ch[y-1]->getloaihang();
			    	if(tra_loaihang(str[i])){
			    		cout<<termcolor::red<<"\n(!)LOAI HANG TRONG TAU THUOC LOAI HANG CAM KHONG DUOC VAO SONG(!)\n"<<termcolor::reset;
			    		xoadata_file(ch,dl,ca,x,y,z,ch[y-1]->getten());
			    		cout<< termcolor::underline<<termcolor::green<<"(#)THUYEN DA XOA KHOI DANH SACH"<<termcolor::reset<<endl;
			    		break;
					}
					if(ch[y-1]->gettaitrong()>2000){
					cout<<termcolor::red<<"\n\n(!) TAI TRONG BAN DA VUOT QUA QUY DINH VI LY DO AN TOAN GIAO THONG TAU KHONG DUOC VAO(!)\n"<<termcolor::reset;
					xoadata_file(ch,dl,ca,x,y,z,ch[y-1]->getten());
					cout<< termcolor::underline<<termcolor::green<<"(#)THUYEN DA XOA KHOI DANH SACH"<<termcolor::reset<<endl;
				}
				}
				}
				else if(themtype=="danh ca"){
					ca[z]=new Fish();
					ca[z]->nhapthongtintaudanhca(themtype);
					lt=ca[z]->getlichtrinh();
					for(int i=0;i<lt.i;i++){
					if(tra_lichtrinh(ch,dl,ca,x,y,z-1,lt.vitri[i],lt.time[i],lt.ngay[i])){
						cout<<"\n\nLICH TRINH "<<lt.time[i]<<"->"<<lt.vitri[i]<<"\n(!)vi ly do da kin thuyen\n *Hay thay doi lich trinh(!)"<<endl;
						ca[z]->setlichtrinh(i);i--;
						lt=ca[z]->getlichtrinh();
				    }
				   }
				    z++;
				    if(ca[z-1]->gettaitrong()>2000){
					cout<<termcolor::red<<"\n\n(!) TAI TRONG BAN DA VUOT QUA QUY DINH VI LY DO AN TOAN GIAO THONG TAU KHONG DUOC VAO(!)\n"<<termcolor::reset;
					xoadata_file(ch,dl,ca,x,y,z,ca[z-1]->getten());
					cout<< termcolor::underline<<termcolor::green<<"(#)THUYEN DA XOA KHOI DANH SACH"<<termcolor::reset<<endl;
				}
				}
}
//============================================MENU===============================================
void Menu(Chohang *ch[],Dulich *dl[],Fish *ca[],int n){
    int x=0;
	int y=0;
	int z=0;// dem cac loai tau lan luot: du lich,cho hang, tau ca 
	ifstream fs;
	fs.open("ds_boats.txt");
	fs>>n;
	fs.ignore();
	if(fs.is_open()){
	for(int i=0;i<n;i++){
	string loai_boat;
	getline(fs,loai_boat,',');
	fs.ignore(1);
	if(loai_boat=="du lich"){
		dl[x]= new Dulich();
		dl[x]->setloaitau(loai_boat);
		dl[x]->doc_filedulich(fs);
		x++;
	}
	else if(loai_boat=="cho hang"){
		ch[y]= new Chohang();
		ch[y]->setloaitau(loai_boat);
		ch[y]->doc_filechohang(fs);
		y++;
	}
	else if(loai_boat=="danh ca"){
		ca[z]= new Fish();
		ca[z]->setloaitau(loai_boat);
		ca[z]->doc_filedanhca(fs);
		z++;
	}
    }
}
    else{
    	cout<<"loi mo file";
	}
	fs.close();
	int them=0;
	while(true){system("cls");
	cout<<setw(106)<<internal<<"=====       =====  ========  =====     ==  ===     ==="<<endl;
	cout<<setw(106)<<internal<<"======     ======  ========  ======    ==  ===     ==="<<endl;
	cout<<setw(106)<<internal<<"=== ===   === ===  ===       === ===   ==  ===     ==="<<endl;
	cout<<setw(106)<<internal<<"===  === ===  ===  ========  ===  ===  ==  ===     ==="<<endl;
	cout<<setw(106)<<internal<<"===   =====   ===  ========  ===   === ==  ===     ==="<<endl;
	cout<<setw(106)<<internal<<"===    ===    ===  ===       ===    =====  ===     ==="<<endl;
	cout<<setw(106)<<internal<<"===     =     ===  ========  ===     ====  ====   ===="<<endl;
	cout<<setw(106)<<internal<<"===           ===  ========  ===      ===   ========= "<<endl;
	cout<<setw(101)<<internal<<"============================================"<<endl;
	cout<<setw(101)<<internal<<"||1.Danh sach tau thuyen tren song        ||"<<endl;
	cout<<setw(101)<<internal<<"||________________________________________||"<<endl;
	cout<<setw(101)<<internal<<"||2.Them Tau thuyen vao cang              ||"<<endl;
	cout<<setw(101)<<internal<<"||________________________________________||"<<endl;
	cout<<setw(101)<<internal<<"||3.Xoa Tau thuyen ra cang                ||"<<endl;
	cout<<setw(101)<<internal<<"||________________________________________||"<<endl;
	cout<<setw(101)<<internal<<"||4.Tra cuu thong tin tau thuyen tren song||"<<endl;
	cout<<setw(101)<<internal<<"||________________________________________||"<<endl;
	cout<<setw(101)<<internal<<"||5.Chinh sua trang thai cua thuyen       ||"<<endl;
	cout<<setw(101)<<internal<<"||________________________________________||"<<endl;
	cout<<setw(101)<<internal<<"||6.Cap nhat lai file                     ||"<<endl;
	cout<<setw(101)<<internal<<"||________________________________________||"<<endl;
	cout<<setw(101)<<internal<<"||7.Thoat                                 ||"<<endl;
	cout<<setw(101)<<internal<<"============================================"<<"\n\n"<<endl;
	cout <<termcolor::yellow<< char(26) <<"LUA CHON CHE DO SO:"<<termcolor::reset;
	string luachon;
	cin>>luachon;
	if(luachon=="1"){
		int i=1;
			cout<<"\n\n"<<setw(104)<<internal<<"*******DANH SACH TAU THUYEN TREN SONG********\n"<<endl;
			cout<<"TONG SO LUONG TAU TREN CANG "<<x+y+z<<endl;
			inthongtindautrangdulich();
			for(int d=0;d<x;d++){
			cout<<char(179)<<setw(3)<<internal<<i++;
				dl[d]->xuat_thongtindulich();
			}
			inthongtindautrangchohang();
			for(int e=0;e<y;e++){
				cout<<char(179)<<setw(3)<<internal<<i++;
				ch[e]->xuat_thongtinchohang();
			}
			inthongtindautrangdanhca();
			for(int f=0;f<z;f++){
				cout<<char(179)<<setw(3)<<internal<<i++;
				ca[f]->xuat_thongtindanhca();
			}
		}
	else if(luachon=="2"){
		cout<<"\n\n"<<setw(92)<<internal<<"****CHE DO THEM THUYEN****"<<"\n\n";
			cout<<termcolor::magenta<<"(?)them bao nhieu thuyen vao cang :"<<termcolor::reset;
			cin>>them;
			cin.ignore();
			for(int i=0;i<them;i++){
				cout<<termcolor::cyan<<"Cac loai tau thuyen:\n"<<"du lich    "<<"cho hang    "<<"danh ca\n";
				cout<<"nhap loai tau(word) "<<i+1<<" : "<<termcolor::reset;
				string themtype;
			    getline(cin,themtype);
				if(themtype!="du lich"&&themtype!="cho hang"&&themtype!="danh ca"){
					cout<<termcolor::yellow<<"loai thuyen khong hop le(!)\n(*)MOI BAN NHAP LAI\n";
					i--;
					continue;
			    }
			    themtau(ch,dl,ca,x,y,z,themtype);cout<<endl;
			}//vong for	
			if(n!=x+y+z){
			          cout<<termcolor::yellow<<"BAN CO MUON SAVE IN FILE ?"<<endl;
			          cout<<termcolor::yellow<<"1.YES    or     2.NO"<<endl;
			          cout<<termcolor::magenta<<"lua chon cua ban->";
			          int chon;
			          cin>>chon;
			          if(chon==1){n=x+y+z;
			          	capnhat_file(ch,dl,ca,x,y,z);
			          	cout<<termcolor::green<<"(#)File da duoc cap nhat"<<termcolor::reset<<endl;
					  }
					  else{
					  	continue;
					  }
				}
			}
	//xoa tau thuyen
     else if(luachon=="3"){
				cout<<"\n\n"<<setw(98)<<"**********CHE DO XOA FILE**********\n\n"<<endl;
				int sl_xoa;
				cout<<termcolor::magenta<<"SO LUONG THUYEN CAN XOA : "<<termcolor::reset;
				cin>>sl_xoa;
				cin.ignore();
				string dlete;
				for (int i=0;i<sl_xoa;i++){if(i>=1){cout<<termcolor::cyan<<"MOI NHAP THONG TIN TAU TIEP THEO(...)\n"<<termcolor::reset;}	
				cout<<"ten thuyen can xoa->";
				getline(cin,dlete);
				xoadata_file(ch,dl,ca,x,y,z,dlete);
				if(n==x+y+z){cout<< termcolor::underline<<termcolor::yellow<<"\n(!)KHONG THAY TEN BAN CAN XOA(!)\n\n"<<termcolor::reset;
				i--;
					   }
				}
				cout<< termcolor::underline<<termcolor::green<<"(#)THUYEN "<<dlete<<" DA XOA KHOI DANH SACH"<<termcolor::reset<<endl;
				cout<<termcolor::underline<<termcolor::green<<"Da xoa khoi file"<<termcolor::reset<<endl;
			}//else
         else if(luachon=="4"){
				cout<<"\n\n"<<setw(97)<<internal<<termcolor::yellow<<"**** MUC TRA CUU THONG TIN ****\n\n";
				cout<<setw(102)<<internal<<"==============================================="<<endl;
				cout<<setw(102)<<internal<<"||1.tra cuu trang thai tau thuyen            ||"<<endl;
            	cout<<setw(102)<<internal<<"||2.tra cuu thong tin ra vao cua mot DIA DIEM||"<<endl;
	            cout<<setw(102)<<internal<<"||3.tra cuu quoc gia tau thuyen              ||"<<endl;
	            cout<<setw(102)<<internal<<"||4.tim kiem tau theo ten                    ||"<<endl;
	            cout<<setw(102)<<internal<<"||5.tim kiem tau theo loai tau               ||"<<endl;
	            cout<<setw(102)<<internal<<"==============================================="<<"\n\n"<<termcolor::reset<<endl;
	            int chon;
	            cout<<"BAN MUON TRA CUU THONG TIN SO MAY (?)"<<endl;
	            cout<<termcolor::magenta<<"So lua chon cua ban la"<<"-"<<(char)16<<termcolor::reset;cin>>chon;
	            if(chon==1){
	            cout<<"\n\n"<<setw(100)<<internal<<"**** CHE DO TRA CUU TRANG THAI ****\n\n";
	            	int number=1;
	            	cin.ignore();
	            	string tt;
	            	cout<<termcolor::cyan<<"NHAP TRANG THAI CAN TRA CUU :"<<termcolor::reset;
	            	getline(cin,tt);
	            cout<<setw(95)<<internal<<"====THONG TIN TAU THUYEN CO TRANG THAI "<<tt<<"===="<<endl;	
	            	for(int i=0;i<x;i++){
	            		if(thuong(dl[i]->gettrangthai())==thuong(tt)){
	            			inthongtindautrangdulich();
	            			cout<<char(179)<<setw(3)<<internal<<number++;
	            			dl[i]->xuat_thongtindulich();
						}
					}
					for(int i=0;i<y;i++){
						if(thuong(ch[i]->gettrangthai())==thuong(tt)){
							inthongtindautrangchohang();
							cout<<char(179)<<setw(3)<<internal<<number++;
							ch[i]->xuat_thongtinchohang();
						}
					}
					for(int i=0;i<z;i++){
						if(thuong(ca[i]->gettrangthai())==thuong(tt)){
							inthongtindautrangdanhca();
							cout<<char(179)<<setw(3)<<internal<<number++;
							ca[i]->xuat_thongtindanhca();
						}
					}
					cout<<termcolor::cyan<<"=>(*)HIEN CO "<<number-1<<" TAU THUYEN "<<tt<<termcolor::reset<<endl;
					if(number==1){
						system("cls");
						cout<<termcolor::underline<<termcolor::red<<"TRANG THAI KHONG HOP LE!\n\n"<<termcolor::reset;
					}
					}
				
				else if(chon==2){
					cout<<"\n\n"<<setw(98)<<internal<<"**** CHE DO TRA CUU DIA DIEM ****\n\n";
					cin.ignore();
					int number=0;
					string diadiem;
					cout<<termcolor::cyan<<"(?)DIA DIEM CAN TRUY CAP :"<<termcolor::reset;
					getline(cin,diadiem);
				cout<<setw(102)<<internal<<"====THONG TIN TAU THUYEN DEN DIA DIEM TRA CUU===="<<endl;
				    inthongtindautrangdulich();	
					for(int i=0;i<x;i++){
						if(dl[i]->tradiadiem(diadiem)){
							number++;
							cout<<char(179)<<setw(3)<<internal<<number;
							dl[i]->xuat_thongtindulich();
						}
					}
					inthongtindautrangchohang();
					for(int i=0;i<y;i++){
						if(ch[i]->tradiadiem(diadiem)){
							number++;
							cout<<char(179)<<setw(3)<<internal<<number;
							ch[i]->xuat_thongtinchohang();
						}
					}
					inthongtindautrangdanhca();
					for(int i=0;i<z;i++){
						if(ca[i]->tradiadiem(diadiem)){
							number++;
							cout<<char(179)<<setw(3)<<internal<<number;
							ca[i]->xuat_thongtindanhca();
						}
					
					}
					if(number=0){
					cout<<termcolor::yellow<<"(!)KHONG CO TAU THUYEN NAO DEN "<<diadiem<<" OR DIA DIEM BAN NHAP KHONG HOP LE"<<termcolor::reset<<endl;		
					}
				}
				else if(chon==3){
					cout<<"\n\n"<<setw(107)<<internal<<"**** CHE DO TRA CUU QUOC GIA TAU THUYEN ****\n\n";
				    cin.ignore();
				    int number=0;
					string name;
					cout<<termcolor::cyan<<"<=>MOI NHAP QUOC GIA CUA TAU : "<<termcolor::reset;
					getline(cin,name);
					for(int i=0;i<x;i++){
						if(thuong(dl[i]->getnation()).find(thuong(name))!=string::npos){
							inthongtindautrangdulich();
							number++;
							cout<<char(179)<<setw(3)<<internal<<number;
							dl[i]->xuat_thongtindulich();
							break;
						}
					}
					for(int i=0;i<y;i++){
						if(thuong(ch[i]->getnation()).find(thuong(name))!=string::npos){
							inthongtindautrangchohang();
							number++;
							cout<<char(179)<<setw(3)<<internal<<number;
							ch[i]->xuat_thongtinchohang();
							break;
						}
						}
					for(int i=0;i<z;i++){
						if(thuong(ca[i]->getnation()).find(thuong(name))!=string::npos){
							inthongtindautrangdanhca();
							number++;
							cout<<char(179)<<setw(3)<<internal<<number;
							ca[i]->xuat_thongtindanhca();
							break;
						}
						}
						if(number==0){
							cout<<termcolor::yellow<<"(!) KHONG TIM THAY KET QUA "<<termcolor::reset<<endl;
						}
				}
				else if(chon==4){//chi can nhap ki tu trong ten can tim will hien ket qua
				    cout<<"\n\n"<<setw(102)<<internal<<"**** CHE DO TRA CUU TEN TAU THUYEN ****\n\n";
				    cin.ignore();
				    cout<<"(*)CO THE NHAP KI TU TRONG TEN BAN CAN TIM\n\n";
				    int number=0;
					string name;
					cout<<termcolor::cyan<<"<=>MOI NHAP TEN CAN TIM : "<<termcolor::reset;
					getline(cin,name);
					inthongtindautrangdulich();
					for(int i=0;i<x;i++){
						if(thuong(dl[i]->getten()).find(thuong(name))!=string::npos){
							number++;
							cout<<char(179)<<setw(3)<<internal<<number;
							dl[i]->xuat_thongtindulich();
							break;
						}
					}
					inthongtindautrangchohang();
					for(int i=0;i<y;i++){
						if(thuong(ch[i]->getten()).find(thuong(name))!=string::npos){
							number++;
							cout<<char(179)<<setw(3)<<internal<<number;
							ch[i]->xuat_thongtinchohang();
							break;
						}
						}
					inthongtindautrangdanhca();
					for(int i=0;i<z;i++){
						if(thuong(ca[i]->getten()).find(thuong(name))!=string::npos){
							number++;
							cout<<char(179)<<setw(3)<<internal<<number;
							ca[i]->xuat_thongtindanhca();
							break;
						}
						}
						if(number==0){
							cout<<termcolor::yellow<<"(!) KHONG TIM THAY KET QUA "<<termcolor::reset<<endl;
						}
			     }
				else if(chon==5){
					cout<<"\n\n"<<setw(98)<<internal<<"**** CHE DO TRA CUU LOAI TAU ****\n\n";
					int number=0;
					cin.ignore();
					while(true){
				 	cout<<termcolor::green<<"(?) LOAI TAU BAN CAN TRA CUU \n\n"<<"1.du lich        2.cho hang         3.danh ca\n\n"<<termcolor::reset;
				 	string loai;
				 	cout<<termcolor::cyan<<"=> NHAP LOAI TAU BAN CAN TRA CUU(NHAP CHU) :"<<termcolor::reset;
				 	getline(cin,loai);
				 	cout<<setw(101)<<internal<<"===DANH SACH TRA CUU THEO LOAI===\n\n\n ";
				 	if(loai=="du lich"){
				 		inthongtindautrangdulich();
				 		for(int i=0;i<x;i++){
				 			number++;
				 			cout<<char(179)<<setw(3)<<internal<<number;
				 			dl[i]->xuat_thongtindulich();
						 }
					 }
					else if(loai=="cho hang"){
						inthongtindautrangchohang();
						for(int i=0;i<y;i++){
							number++;
							cout<<char(179)<<setw(3)<<internal<<number;
							ch[i]->xuat_thongtinchohang();
						}
					}
					else if(loai=="danh ca"){
						inthongtindautrangdanhca();
						for(int i=0;i<z;i++){
							number++;
							cout<<char(179)<<setw(3)<<internal<<number;
							ca[i]->xuat_thongtindanhca();
						}
					}
					if(number!=0){
						break;
					}
					else{
						cout<<termcolor::yellow<<"=>(!)LOAI TAU KHONG HOP LE\n";
						cout<<"   (!)MOI BAN NHAP LAI\n"<<termcolor::reset;
					}
				 }
				}
				 
         }//lua chon 4
         else if(luachon=="5"){
         	cin.ignore();
         	cout<<"\n\n"<<setw(92)<<internal<<"=====CHE DO CHINH SUA TRANG THAI====="<<"\n\n";
         	string chinh;
         	string tt;
         	while(true){
         	cout<<"(?) TEN TAU CAN CHINH :";
         	getline(cin,chinh);
         	int a=0;
			for(int i=0;i<x;i++){
			if(thuong(dl[i]->getten())==thuong(chinh)){
				cout<<"(!)Nhap trang thai moi cua "<<dl[i]->getten()<<" :";
				getline(cin,tt);
				dl[i]->settrangthai(tt);
				capnhat_file(ch,dl,ca,x,y,z);
				a++;
				cout<<termcolor::green<<"(!)TRANG THAI DA DUOC CAP NHAT\n\n"<<termcolor::reset;
	    	break;
			}				  
			}
			//tim cho hang
			for(int i=0;i<y;i++){
			if(thuong(ch[i]->getten())==thuong(chinh)){
				cout<<"(!)Nhap trang thai moi cua "<<ch[i]->getten()<<" :";
				getline(cin,tt);
				ch[i]->settrangthai(tt);
				capnhat_file(ch,dl,ca,x,y,z);
				a++;
				cout<<termcolor::green<<"(!)TRANG THAI DA DUOC CAP NHAT\n\n"<<termcolor::reset;
			break;	    
				}
			}
			//tim danh ca
			for(int i=0;i<z;i++){
			if(thuong(ca[i]->getten())==thuong(chinh)){
				cout<<"(!)Nhap trang thai moi cua "<<ca[i]->getten()<<" :";
				getline(cin,tt);
				ca[i]->settrangthai(tt);
				capnhat_file(ch,dl,ca,x,y,z);
				cout<<termcolor::green<<"(!)TRANG THAI DA DUOC CAP NHAT\n\n"<<termcolor::reset;
				a++;
				break;      
			 }
			}
			if(a==0){
				cout<<termcolor::red<<"\n(!)Ten thuyen khong tim thay moi ban nhap lai:\n\n "<<termcolor::reset;
			}else {break; 
			} 
			}
		 }// lua chon 5
		 else if(luachon=="6"){
		 	capnhat_file(ch,dl,ca,x,y,z);
		 	cout<<termcolor::green<<"TRANG THAI DA DUOC CAP NHAT\n\n"<<termcolor::reset;
		 }//lua chon 6
		 else if(luachon=="7"){
		 	break;
		 }//lua chon 7
		 else{cout<<termcolor::yellow<<"\n\n\t(!)lua chon cua ban khong co trong menu\n\n"<<termcolor::reset;
		 }
		 
	cout<<termcolor::cyan<<"(#)BAN CO MUON DANG XUAT KHONG\n"<<"1.YES   or    2.NO\n"<<termcolor::reset;
	int cchon;
	cin>>cchon;
	if(cchon==1 ){
		break;
	}
	else{
		continue;
	}				   	          
//	}//switch
}//while
}
//void
void capnhataccount(string *id,string *pass,int a,string security, string ac, string pa){
	ofstream ofs;
	ofs.open("account.txt");
	ofs<<security;
	ofs<<endl<<a;
	for(int i=0;i<a-1;i++){
		ofs<<endl<<id[i]<<endl<<pass[i];
	}
	ofs<<endl<<ac<<endl<<pa;
	ofs.close();
}
int main(){
	int n=0;
	string security,se,ac,pa;
	int a;
	Chohang *ch[100];
	Dulich *dl[100];
	Fish *ca[100];
	while(true){
	ifstream ifs;
	ifs.open("account.txt");
	ifs>>security;ifs.ignore();
	ifs>>a;
	string *id=new string[a];
	string *pass=new string[a];
	ifs.ignore();
	for(int i=0;i<a;i++){
		getline(ifs,id[i]);getline(ifs,pass[i]);
	}
	ifs.close();
	cout<<"1.LOG IN\n"<<"2.CREAT ACCOUNT\n"<<"SO LUA CHON CUA BAN=>>";
	int lua;cin>>lua;cin.ignore();
	if(lua==2){system("cls");
		for(int i=0;i<3;i++){
		cout<<"\n\n\n"<<setw(66)<<internal<<"";print(46);cout<<"+\n";
		cout<<setw(67)<<char(179)<<setw(26)<<internal<<"LOG UP"<<setw(22)<<internal<<"|\n";	
		cout<<setw(66)<<internal<<"";print(46);cout<<"+\n";
		cout<<setw(78)<<internal<<"MA BAO VE :";getline(cin,se);	
		if(se==security){
	     cout<<setw(76)<<internal<<"account :";getline(cin,ac);cout<<setw(73)<<internal<<"pass :";getline(cin,pa);
			a++;
			capnhataccount(id,pass,a,security,ac,pa);system("cls");
			cout<<"ACCOUNT SUCCESSFULLY CREATED\n";
			break;
		}
		else{system("cls");cout<<"*MA KHONG HOP LE!";cout<<"=> AGAIN <=\n";
		}
	}
	}
	else if(lua==1){system("cls");	
	for(int i=0;i<3;i++){
		 cout<<"\n\n\n"<<setw(66)<<internal<<"";print(46);cout<<"+\n";
		 cout<<setw(67)<<char(179)<<setw(26)<<internal<<"LOG IN"<<setw(22)<<internal<<"|\n";
		 cout<<setw(66)<<internal<<"";print(46);cout<<"+\n";
	     cout<<setw(76)<<internal<<"account :";getline(cin,ac);cout<<setw(73)<<internal<<"pass :";getline(cin,pa);
	    for(int j=0;j<a;j++){
	    	if(pass[j]==pa && id[j]==ac){
	    		system("cls");
	        Menu(ch,dl,ca,n);
	        i=3;
	    }
     }
     if(i<3){
     	system("cls");
	    	cout<<"(!)NHAP SAI(!)\n"<<"=> AGAIN <=\n";
		}
} 
    break;
}
else{
	break;
}
}
	return 0;
}
