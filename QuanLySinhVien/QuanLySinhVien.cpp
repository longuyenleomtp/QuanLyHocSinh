#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <algorithm>

using namespace std;

class HocSinh {
public:
	string maHS, hoTen, lop, ngaySinh;
	float toan, ly, hoa, anh, van, dtb;

	void nhap();
	void hienthi();

};

void HocSinh::nhap() {
	cin.ignore(); // Thêm dòng này để xóa bộ đệm đầu vào
	cout << "Nhap ho ten: ";
	getline(cin, hoTen);
	cout << "Nhap ma hoc sinh: ";
	cin >> maHS;
	cout << "Nhap lop: ";
	cin >> lop;
	cout << "Nhap ngay sinh: ";
	cin >> ngaySinh;
	cout << "Nhap diem Toan: ";
	cin >> toan;
	cout << "Nhap diem Ly: ";
	cin >> ly;
	cout << "Nhap diem Hoa: ";
	cin >> hoa;
	cout << "Nhap diem Anh: ";
	cin >> anh;
	cout << "Nhap diem Van: ";
	cin >> van;
	if (ngaySinh[2] != '/') {
		ngaySinh = "0" + ngaySinh;
	}
	if (ngaySinh[5] != '/') {
		ngaySinh.insert(3, "0");
	}
	for (int i = 0; i < hoTen.size(); i++) {
		if (i == 0 || (i > 0 && hoTen[i - 1] == ' ')) {
			if (hoTen[i] >= 'a' && hoTen[i] <= 'z') {
				hoTen[i] -= 32;
			}
		}
	}
}


void HocSinh::hienthi() {
	dtb = (toan + ly + hoa + anh + van) / 5;
	cout << endl;
	cout << left << setw(20) << hoTen
		<< setw(10) << maHS
		<< setw(10) << lop
		<< setw(15) << ngaySinh
		<< setw(10) << toan
		<< setw(10) << ly
		<< setw(10) << hoa
		<< setw(10) << anh
		<< setw(10) << van
		<< setw(10) << fixed << setprecision(2) << dtb;
	if (dtb >= 8) {
		cout << "Gioi";
	}
	else if (dtb >= 6.5 && dtb < 8) {
		cout << "Kha";
	}
	else if (dtb >= 5 && dtb < 6.5) {
		cout << "Trung Binh";
	}
	else {
		cout << "Yeu";
	}
}

class quanlyhocsinh : public HocSinh {
public:
	HocSinh hs[1000];
	int n;

	void nhap();
	void hienthi();
	void xeploai();
	void sortDTBtd();
	void sortDTBgd();
	void hsDTBmax();
	void hsDTBmin();
	void timkiemtheomhs();
	static bool cmp(HocSinh hs1, HocSinh hs2); //sort dtb hoc sinh tang dan
	static bool cmp2(HocSinh hs1, HocSinh hs2); //sort dtb hoc sinh giam dan
};

void quanlyhocsinh::nhap() {
	cout << "Nhap so luong hoc sinh can nhap: " << endl;
	cin >> n;
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << "Nhap thong tin hoc sinh thu: " << i + 1 << "";
		cout << endl;
		hs[i].nhap();
	}
}

void quanlyhocsinh::hienthi() {
	cout << setw(20) << "\nHo ten" << setw(20) << left << "Ma Sinh Vien"
		<< setw(10) << "Lop"
		<< setw(15) << "Ngay Sinh"
		<< setw(10) << "Diem Toan"
		<< setw(10) << "Diem Ly"
		<< setw(10) << "Diem Hoa"
		<< setw(10) << "Diem Anh"
		<< setw(10) << "Diem Van"
		<< setw(10) << "Diem Trung Binh"
		<< setw(10);
	for (int i = 0; i < n; i++) {
		hs[i].hienthi();
	}
}

void quanlyhocsinh::xeploai() {
	cout << "\n\n";
	cout << "-----Danh Sach Hoc Sinh Gioi---------------" << endl;
	for (int i = 0; i < n; i++) {
		if (hs[i].dtb >= 8) {
			hs[i].hienthi();
		}
	}
	cout << endl;
	cout << "-----Danh Sach Hoc Sinh Kha---------------" << endl;
	for (int i = 0; i < n; i++) {
		if (hs[i].dtb >= 6.5 && hs[i].dtb < 8) {
			hs[i].hienthi();
		}
	}
	cout << endl;
	cout << "-----Danh Sach Hoc Sinh Trung Binh---------------" << endl;
	for (int i = 0; i < n; i++) {
		if (hs[i].dtb >= 5 && hs[i].dtb < 6.5) {
			hs[i].hienthi();
		}
	}
	cout << endl;
	cout << "-----Danh Sach Hoc Sinh Yeu---------------" << endl;
	for (int i = 0; i < n; i++) {
		if (hs[i].dtb < 5) {
			hs[i].hienthi();
		}
	}
	cout << endl;
}

bool quanlyhocsinh::cmp(HocSinh hs1, HocSinh hs2) {
	return hs1.dtb < hs2.dtb;
}

bool quanlyhocsinh::cmp2(HocSinh hs1, HocSinh hs2) {
	return hs1.dtb > hs2.dtb;
}

void quanlyhocsinh::sortDTBtd() {
	cout << endl;
	cout << "-----Danh Sach Hoc Sinh Co Diem Trung Binh Tang Dan---------------" << endl;
	sort(hs, hs + n, cmp);
	for (int i = 0; i < n; i++) {
		hs[i].hienthi();
	}
}

void quanlyhocsinh::sortDTBgd() {
	cout << endl;
	cout << "-----Danh Sach Hoc Sinh Co Diem Trung Binh Giam Dan---------------" << endl;
	sort(hs, hs + n, cmp2);
	for (int i = 0; i < n; i++) {
		hs[i].hienthi();
	}
}

void quanlyhocsinh::hsDTBmax() {
	cout << endl;
	cout << "-----Hoc Sinh Co Diem Trung Binh Cao Nhat---------------" << endl;
	float max = -1;
	int pos = 0;
	for (int i = 0; i < n; i++) {
		if (hs[i].dtb > max) {
			max = hs[i].dtb;
			pos = i;
		}
	}
	hs[pos].hienthi();
}

void quanlyhocsinh::hsDTBmin() {
	cout << endl;
	cout << "-----Hoc Sinh Co Diem Trung Binh Thap Nhat---------------" << endl;
	float min = 11;
	int pos = 0;
	for (int i = 0; i < n; i++) {
		if (hs[i].dtb < min) {
			min = hs[i].dtb;
			pos = i;
		}
	}
	hs[pos].hienthi();
}

void quanlyhocsinh::timkiemtheomhs() {
	string mhs;
	int cnt = 0;
	cout << "Nhap ma hoc sinh can tim" << endl;
	getline(cin, mhs);
	for (int i = 0; i < n; i++) {
		if (hs[i].maHS == mhs) {
			hs[i].hienthi();
			cnt++;
		}
	}
	if (cnt == 0) {
		cout << "Khong tim thay sinh vien nao!" << endl;
	}
}


int main() {

	quanlyhocsinh QLHS;
	while (1) {
		cout << "\n==========================MENU===================================\n";
		cout << "1. Nhap hoc sinh\n";
		cout << "2. In danh sach hoc sinh\n";
		cout << "3. Xep loai hoc sinh\n";
		cout << "4. Sap xep hoc sinh theo diem trung binh tang dan\n";
		cout << "5. Sap xep hoc sinh theo diem trung binh giam dan\n";
		cout << "6. Hoc Sinh co diem trung binh cao nhat\n";
		cout << "7. Hoc Sinh co diem trung binh thap nhat\n";
		cout << "8. Tim kiem hoc sinh theo ma hoc sinh\n";
		cout << "0. Ket thuc chuong trinh\n";
		cout << "==========================MENU===================================\n";
		cout << endl;
		cout << "Nhap lua chon: ";
		int n; cin >> n;
		cin.ignore();

		if (n == 1) {
			QLHS.nhap();
		}
		else if (n == 2) {
			QLHS.hienthi();
		}
		else if (n == 3) {
			QLHS.xeploai();
		}
		else if (n == 4) {
			QLHS.sortDTBtd();
		}
		else if (n == 5) {
			QLHS.sortDTBgd();
		}
		else if (n == 6) {
			QLHS.hsDTBmax();
		}
		else if (n == 7) {
			QLHS.hsDTBmin();
		}
		else if (n == 8) {
			QLHS.timkiemtheomhs();
		}
		else if (n == 0) {
			break;
		}
	}

	return 0;
}