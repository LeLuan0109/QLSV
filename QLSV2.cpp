#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>

using namespace std;

class student
{
    // khởi tọa các thuộc tính"properties" của lớp stduent với kiểu private
    // các thuộc tính  chỉ có thể truy cập từ bên trong ,
    //  muốn truy cập từ bên ngoài phải dùng nmethod set và get
    // public:
private:
    string id;
    string name;
    string clas;
    float a;
    float b;
    float c;

public:
    // khai báo hàm tạo  mặc định
    student();
    // khai báo hàm tạo tham số theo phương thưc set  ;
    student(string, string, string, float, float, float);
    // khai báo phương thức set đối với các thuộc tính :
    // khai báo phương thức get đối với các thuộc tính :
    void setId(string);
    string getId();
    void setName(string);
    string getName();
    void setClas(string);
    string getClas();

    void setA(float);
    float getA();
    void setB(float);
    float getB();
    void setC(float);
    float getC();

    // khai báo phương thức showinfor c với các thuộc tính của đối tượng;
    void showinfor();
    // khai báo phương thức showdssv c với các thuộc tính của đối tượng;
    void showdssv();
};

//  định nghĩa hàm tọa mặc định
student::student()
{
    this->id = " ";
    this->name = " ";
    this->clas = " ";
    this->a = 0;
    this->b = 0;
    this->c = 0;
}
//định nghĩa hàm tạo tham số theo phương thưc set  ;
// private nos la một gói  <- ham hoi tao (student::student(string id, string name, string clas, float a, float b, float c))

student::student(string id, string name, string clas, float a, float b, float c)
//  student sv(id, name, clas, a, b, c);
{
    setId(id);
    setName(name);
    setClas(clas);
    setA(a);
    setB(b);
    setC(c);
}
// định nghĩa phương thức set đối với các thuộc tính :
void student::setId(string id)
{
    this->id = id;
}
void student::setName(string name)
{
    this->name = name;
}
void student::setClas(string clas)
{
    this->clas = clas;
}
void student::setA(float a)
{
    this->a = a;
}
void student::setB(float b)
{
    this->b = b;
}
void student::setC(float c)
{
    this->c = c;
}
// định nghĩa phương thức get  đối với các thuộc tính :
string student::getId()
{
    return this->id;
}
string student::getName()
{
    return this->name;
}
string student::getClas()
{
    return this->clas;
}
float student::getA()
{
    return this->a;
}
float student::getB()
{
    return this->b;
}
float student::getC()
{
    return this->c;
}
// định nghĩa phương thức showinfor:

void student::showinfor()
{
    cout << "============++++++==========++++++===========" << endl;
    cout << "                   SINH VIEN            " << endl;
    cout << " Ma Sinh Vien : " << getId() << endl;
    cout << " Ten Sinh Vien : " << getName() << endl;
    cout << " Lop Hoc : " << getClas() << endl;
    cout << " Diem Toan : " << getA() << endl;
    cout << " Diem Van : " << getB() << endl;
    cout << " Diem Anh : " << getC() << endl;
    cout << "==============================================" << endl;
}
void student::showdssv(){
    cout << left << setw(15) << getId() 
    << "\t" << left << setw(20) << getName() 
    << "\t" << left << setw(10) << getClas() 
    << "\t" << left << setw(3) << getA() 
    << "\t" << left << setw(3) << getB() 
    << "\t" << left << setw(3) << getC() << endl;
}

//  hàm nhập sinh viên :
void nhap(student *dssv, int i, int n)
{
    string id, name, clas;
    float a, b, c;
    for (i; i < n; i++)
    {
        cout << " lan thu : " << i + 1 << endl;
        cout << "Nhap vao ID :";
        cin >> id;
        cin.ignore();
        cout << "Nhap vao Name :";

        getline(cin, name);
        // cin >> name;
        cout << "Nhap vao Lop :";
        cin >> clas;
        cout << "Nhap diem Toan : ";
        cin >> a;
        cout << "Nhap diem Van : ";
        cin >> b;
        cout << "Nhap diem Anh : ";
        cin >> c;
        // ham hoi tao 

        student sv(id, name, clas, a, b, c);
        dssv[i] = sv;
        getchar();
    }
}
// ham sửa :
void sua(student *dssv,string ID ,  int vitri, int n)
{
    string id, name, clas;
    float a, b, c;

    cin.ignore();
    cout << "Nhap vao NEW Name :";

    getline(cin, name);
    // cin >> name;
    cout << "Nhap vao NEW Lop :";
    cin >> clas;
    cout << "Nhap diem NEW Toan : ";
    cin >> a;
    cout << "Nhap diem NEW Van : ";
    cin >> b;
    cout << "Nhap diem NEW Anh : ";
    cin >> c;
   
            student sv(ID, name, clas, a, b, c);
            dssv[vitri] = sv;
    
    
}
// ham xóa:
void xoa(student *dssv, int vtri, int *n)
{
    for (int i = vtri ; i < *n; i++)
    {
       *(dssv + i) = *(dssv + i + 1);
    }
    *n -= 1;
}
//  ham tang
void tang(student *dssv, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            string a = dssv[i].getId();
            string b = dssv[j].getId();

            if (a.compare(b) > 0)
            {
                student s;
                s = *(dssv + i);
                *(dssv + i) = *(dssv + j);
                *(dssv + j) = s;
            }
        }
}
//  ham giam
void giam(student *dssv, int n)

{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            string a = dssv[i].getId();
          
            string b = dssv[j].getId();
           
            if (a.compare(b) < 0)
            {
                  student s;
                s = *(dssv + i);
                *(dssv + i) = *(dssv + j);
                *(dssv + j) = s;
            }
        }
}

// show ra danh sách sinh viên trên 24:
void showResult(student *s, int n)
{
    cout << "+++++++++++============++++++==========++++++===========+++++++++++" << endl;
    cout << left << setw(15) << "MASV"
         << "\t" << left << setw(20) << "Name" 
         << "\t" << left << setw(10) << "class" 
         << "\t" << left << setw(3) << "toan" 
         << "\t" << left << setw(3) << "van" 
         << "\t" << left << setw(3) << "anh" 
         << endl;
    {
        for (int i = 0; i < n; i++)
        {
            float sum = 0;
            sum = s[i].getA() + s[i].getB() + s[i].getC();
            if (sum >= 24)
            {
                s[i].showdssv();
            }
        }
    }
    cout << "===================================================================" << endl << endl;
}
// ham in ra danh sach :
void indanhsach(student *dssv, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (dssv[i].getId() != " ")
            dssv[i].showinfor();
    }
}

int main()
{
    student *dssv;
    // khỏi tạo danh sách sinh viên 
    dssv = new student[1000];
    // khai báo số lương danh sách
    int dem = 0;
    int luachon;
    while (1)
    {
        cout << endl;
        cout << " +++===========++++============++" << endl;
        cout << " ++===========MENU============++" << endl;
        cout << " CHUONG TRINH QUAN LI SINH VIEN :" << endl
             << endl;
        cout << " 1.Them sinh vien." << endl
             << endl;
        cout << " 2.In ra danh sach  sinh vien." << endl
             << endl;
        cout << " 3.Xoa phan tu sinh vien." << endl
             << endl;
        cout << " 4.Sua phan tu sinh vien." << endl
             << endl;
        cout << " 5.Sap sep danh sach tang dan." << endl
             << endl;
        cout << " 6.Sap xep danh sach giam dan." << endl
             << endl;
        cout << " 7.Show ra sinh vien co diem trong tren 24D." << endl
             << endl;
        cout << " 0.Thoat." << endl
             << endl;
        cout << "++Nhap vao lua chon cua bn++: ";
        cin >> luachon;
        cout << endl;

        if (luachon != 0)
        {
            switch (luachon)
            {
                // thêm danh sách
            case 1:
            {
                int n;
                cout << "So luong sinh vien can them: " << endl
                     << endl;
                cin >> n;

                nhap(dssv, dem, dem + n);
                // cập nhập số lượng danh sách
                dem += n;

                break;
            }
            // in ra danh sách
            case 2:
            {
                if (dem == 0)
                {
                    cout << "Danh sach trong!!!!" << endl
                         << endl;
                    break;
                }

                indanhsach(dssv, dem);
                break;
            }
            // xóa thành viên
            case 3:
            {
                string ID;
                int vitri = -1;
                cout << " nhap vao ID can Xoa : ";
                cin >> ID;
                
                // tim ra gia tri can xoa:
                for (int i = 0; i < dem; i++)
                {
                    string var = dssv[i].getId();
                    if (var.compare(ID) == 0)
                    {
                        vitri = i;
                        break;
                        
                    }
                }
                if(vitri == -1){
                    cout << " ma sinh can xoa k hop le !" << endl << endl;
                }else{
                    xoa(dssv, vitri, &dem);
                    cout << " gia tri cuan " << dem << endl;
                }
               
                break;
            }
            // sửa thành viên
            case 4:
            {
                string ID;
                int vitri = -1;
                cout << " nhap vao ID can Sua: ";
                cin >> ID;

                // tim ra gia tri can xoa:
                for (int i = 0; i < dem; i++)
                {
                    string var = dssv[i].getId();
                    if (var.compare(ID) == 0)
                    {
                        vitri = i;
                        break;
                    }
                }
                if (vitri == -1)
                {
                    cout << " ma sv can Sua k hop le !" << endl
                         << endl;
                }else{
                    sua(dssv,ID,  vitri, dem);
                }
               
               
                break;
            }
            // sắp xếp tăng
            case 5:
            {
                 cout << "sap xep tang :" << endl;
                tang(dssv, dem);
                indanhsach(dssv, dem);
                break;
            }
            // sắp xếp giảm
            case 6:
            {
                cout << "sap xep giam :" << endl;
                giam(dssv, dem);
                indanhsach(dssv, dem);
                break;
            }

            //  hiện thị danh sách sinh viên trên 24 điểm
            case 7:
            {
                showResult(dssv, dem);
                break;
            }
            }
        }

        // kết thúc chương trình quản lí .
        if (luachon == 0)
        {
            cout << " cam on bn!!!!";
            break;
        }
    }

    return 0;
}
