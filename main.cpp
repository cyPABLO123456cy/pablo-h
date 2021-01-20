#include <iostream>
using namespace std;

#define MAX 1000
#include <string>
//创建一个联系人结构体
struct Person{
//    姓名
        string  m_names;
//    性别
        int  m_sex;
//      年龄
        int m_age;
//      联系电话
        string m_phone;
//      家庭住址
        string m_Address;
};

//创建一个通讯录结构体

struct Address_book {
    //创建一个通讯录数组；
    struct Person personArray[MAX];
    //一个记录通讯录人数的常量；
    int m_size;
};
void add(struct Address_book *addressBook){

    if (addressBook->m_size > 1000){
        cout << "爆满了，我的小心脏" << endl ;
        return;
    } else{
        //添加具体联系人

        //添加姓名
        string  name;
        cout << "请输入您新朋友的姓名："<< endl;

        cin >> name;
        addressBook->personArray[addressBook->m_size].m_names = name;
        //性别

        int sex = 0;

        cout << "性别是啥？"<< endl;
        cout << " 1---男"<< endl;
        cout << " 2---女" << endl;
        cin >> sex ;
        while (true){
            if (sex == 1 || sex == 2){
                addressBook->personArray[addressBook->m_size].m_sex = sex;
                break;
            }
            cout << "您输入错啦，请重新输入哟！" << endl;
        }

        //年龄

        cout << "请输入年龄" << endl;
        int age = 0;
        cin >> age;
        addressBook->personArray[addressBook->m_size].m_age = age;

        //电话

        cout << "请输入朋友的电话号码" << endl;
        string nub1;
        cin >> nub1;
        addressBook->personArray[addressBook->m_size].m_phone = nub1;



        //家庭住址
        cout << "请输入家庭住址信息" << endl;
        string address;
        cin >> address;
        addressBook->personArray[addressBook->m_size].m_Address = address;

        //size值+1；
        addressBook->m_size++;
//        cout << addressBook->m_size << endl;
        cout << "恭喜收获一名新好友！"<< endl;

    }

};


//显示所有的联系人

void Show_Person(struct Address_book *addressBook){

    if (addressBook->m_size == 0){

        cout << "联系人为空"<< endl;

    } else{
        for (int i = 0; i < addressBook->m_size; i++) {

            cout << "姓名："<< addressBook->personArray[i].m_names << "\t";
            cout << "性别："<< (addressBook->personArray[i].m_sex == 1 ? "男" : "女") << "\t";
            cout << "年龄："<< addressBook->personArray[i].m_age << "\t";
            cout << "电话："<< addressBook->personArray[i].m_phone << "\t";
            cout << "家庭住址："<< addressBook->personArray[i].m_Address << endl;

        }
    }
};
//判断该联系人是否存在
int Isexit(struct Address_book *addressBook, string name){

    for (int i = 0; i < addressBook->m_size; i++) {

        if (addressBook->personArray[i].m_names == name){
            //返回该名字在数组中的地址
            return i;
        }
        return -1;
    }

}

//删除联系人
void DeletePerson(struct Address_book * addressBook){
    cout << "请输入您要放弃的好友名字"<< endl;
    string name;
    cin >> name;

    int ret = Isexit(addressBook,name);

//    cout << ret <<endl;
    if (ret != -1){

        for (int i = ret; i < addressBook->m_size; i++) {
            //数据前移
            addressBook->personArray[i] = addressBook->personArray[i + 1];
            //数组-1
            addressBook->m_size--;

            cout << "删除联系人成功！"<< endl;
        }

    } else{

        cout << "找哭辽，还是没有呢！没有该好友！" <<endl;

    }

}

//查找联系人

void FindPerson(struct Address_book *addressBook){
    cout << "请输入需要查找的联系人："<< endl;
    string name;
    cin >> name;
    int ret = Isexit(addressBook,name);
    if (ret != -1){
        cout << "姓名："<<addressBook->personArray[ret].m_names << "\t ";
        cout << "性别："<<addressBook->personArray[ret].m_sex << "\t ";
        cout << "年龄："<<addressBook->personArray[ret].m_age << "\t ";
        cout << "电话号码："<<addressBook->personArray[ret].m_phone << "\t ";
        cout << "家庭地址："<<addressBook->personArray[ret].m_Address << endl;
    } else{
        cout << "找哭辽没有" << endl;
    }
}

//修改联系人
void ModifyPerson(struct Address_book *addressBook){

    cout << "请输入需要修改的联系人："<< endl;
    string name;
    cin >> name;
    int ret = Isexit(addressBook,name);

    if (ret != -1){

        cout << "需要修改联系人的姓名请输1" << endl;
        cout << "需要修改联系人的性别请输2" << endl;
        cout << "需要修改联系人的年龄请输3" << endl;
        cout << "需要修改联系人的电话请输4" << endl;
        cout << "需要修改联系人的地址请输5" << endl;
        int select = 0;
        cin >> select;

        switch (select) {
            case 1://删除姓名
            {
                cout << "请输入正确的名字" << endl;
                string name;
                cin >> name;
                addressBook->personArray[ret].m_names = name;
                cout << "修改成功！" << endl;
            }
                break;
            case 2://删除性别
            {
                cout << "请输入正确的性别" << endl;
                int sex;
                cin >> sex;
                //对输入的判断是否合法，若合法那么就可以输入并修改；
                while (true){
                    if (sex == 1 || sex == 2){
                        addressBook->personArray[ret].m_sex = sex;
                        break;
                    }
                }
                cout << "修改成功！" << endl;
            }
                break;
            case 3://删除年龄
            {
                cout << "请输入正确的年龄" << endl;
                int age;
                cin >> age;
                addressBook->personArray[ret].m_age = age;

                cout << "修改成功！" << endl;
            }
                break;
            case 4://删除电话
            {
                cout << "请输入正确的电话号码" << endl;
                string num1;
                cin >> num1;
                addressBook->personArray[ret].m_phone = num1;
                cout << "修改成功！" << endl;
            }
                break;
            case 5://删除地址
            {
                cout << "请输入正确的邮件地址" << endl;
                string address;
                cin >> address;
                addressBook->personArray[ret].m_Address = address;
                cout << "修改成功！" << endl;
            }
                break;

        }
    } else{
        cout << "找哭辽没有呀！" << endl;
    }
}


void Showmenu(){
    cout << " ************************* " << endl;
    cout << " ****   1，添加联系人 ****** " << endl;
    cout << " ****   2，显示联系人 ****** " << endl;
    cout << " ****   3，删除联系人 ****** " << endl;
    cout << " ****   4，查找联系人 ****** " << endl;
    cout << " ****   5，修改联系人 ****** " << endl;
    cout << " ****   6，清空联系人 ****** " << endl;
    cout << " ****   0，退出通讯录 ****** " << endl;
    cout << " ************************* " << endl;
}
//清空通讯录！

void  CleanPerson(Address_book * addressBook){
    addressBook->m_size = 0;
    cout << "通讯录已清空！" << endl;
}

int main() {

    int select;
    //创建一个通讯录的实例；
    struct Address_book addressBook;
    //给通讯录的大小赋一个初值；
    addressBook.m_size = 0;

    while (true){
        //显示通讯录；
        Showmenu();

        cout << "请输入你要选择的操作："<< endl;
        cin >> select;

        switch (select) {
            case 1:     //添加联系人
                add(&addressBook);
                break;
            case 2:     //显示联系人
                Show_Person(&addressBook);
                break;
            case 3:     //删除联系人
                DeletePerson(&addressBook);
                break;
            case 4:     //查找联系人
                FindPerson(&addressBook);
                break;
            case 5:     //修改联系人
                ModifyPerson(&addressBook);
                break;
            case 6:     //清空联系人
                break;
            case 0:     //退出通讯录
                CleanPerson(&addressBook);
                cout << "欢迎下次使用"<< endl;
                return 0;
                break;
        }

    }


    return 0;
}
