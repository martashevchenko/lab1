#include <iostream>
const int size =20;

struct DATABASE
        {
    char user[size];
    char pass[size];
    bool isAdmin;
}part;

struct  HOSPITAL
{
    int id;
    char name[size];
    bool isDeleted = false;
}department;

struct PATIENT
{
    int id;
    int idDepartment;
    char name[size];
    char diagnos[size];
    char operations[size];
    char procedures [size];
    char pills[size];
    bool isDeleted = false;
} patient;

void ResaveDB() {
    FILE *fp;
    fopen_s(&fp, "patient.dat", "rb");
    if (!fp) {
        return;
    }
    FILE *fp2;
    fopen_s(&fp2, "patient_copy.dat", "wb");
    fseek(fp, 0, SEEK_SET);

    PATIENT part;
    fread(&part, sizeof(part), 1, fp);
    while (!feof(fp)) {
        if (!part.isDeleted) {
            fwrite(&part, sizeof(part), 1, fp2);
        }
        fread(&part, sizeof(part), 1, fp);
    }

    fclose(fp);
    fclose(fp2);
    remove("patient.dat");
    rename("patient_copy.dat", "patient.dat");
}

bool isEqual(char s1[], char s2[])
        {
    int i = 0;
    while(s1[i]!='\0'||s2[i]!='\0')
    {
        if (s1[i]!=s2[i])
        {
            return false;
        }
        i++;
    }
    if ((s1[i]=='\0')&&(s2[i]=='\0'))
    {
        return true;
    }
    else
    {
        return false;
    }

        };

DATABASE *findLogin(char a[])
{
    FILE *f;
    fopen_s(&f, "user.dat", "r+b");
    if (!f)
    {
        return NULL;
    }
    fseek(f, 0, SEEK_END);
    long pos = ftell(f);
    fseek(f, 0, SEEK_SET);
    int count = pos / sizeof(DATABASE);
    DATABASE* part = new DATABASE[count];
    fread(part, sizeof(DATABASE), count, f);
    for (int i = 0; i <= count; i++)
    {
        if (isEqual(part[i].user, a))
        {
            fclose(f);
            return &part[i];
        }

    }
    delete[] part;
    fclose(f);
    return NULL;
}

DATABASE *logIn( )
{
    char login[size];
    char password[size];
    std::cout<<"Enter a login ";
    std::cin>>login;
    while(!findLogin(login))
    {
        std::cout<<"Wrong login! Please enter again!";
        std::cin>>login;
    }
    DATABASE *thisUser=findLogin(login);
    if (!thisUser)
    {
        std::cout<<"There is no user with this login!"<<std::endl;
    }
    else
    {
        std::cout<<"There is user with this login"<<std::endl;
        std::cout<<"Enter a password";
        std::cin>>password;
        if (isEqual(thisUser->pass,password))
        {
            std::cout<<"You've entered"<<std::endl;
            return thisUser;

        }
        else
        {
            std::cout<<"You've entered a wrong password";
        }

    }
}

void signUp( DATABASE part)
{
    FILE *f;
    f = fopen("user.dat", "ab");
    for (int i = 0; i < 1; i++)
    {
        int ch;
        std::cout << "Enter a login ";
        std::cin >> part.user;
        while (!findLogin(part.user))
        {
            std::cout<<"This login is already exists! Please enter new!";
            std::cin>>part.user;
        }
        std::cout << "Enter a password ";
        std::cin >> part.pass;
        std::cout << "Do you want this user to be admin?" << std::endl;
        std::cout << "If yes, enter 1/ If no, enter 2";
        std::cin >> ch;
        if (ch==1)
        {
            part.isAdmin=0;
        }
        if (ch==2)
        {
            part.isAdmin=1;
        }
        fwrite(&part, sizeof(part), 1, f);
    }
}

void menuAuthorization()
{
    std::cout<<"Log in - 1"<<std::endl;
    std::cout<<"Sign up - 2";
}

void menuDepartment()
{
    std::cout<<std::endl<<"0 - Add new department"<<std::endl;
    std::cout<<"1 - Show all departments"<<std::endl;
    std::cout<<"2 - Chose a department"<<std::endl;
    std::cout<<"3 - Delete a department"<<std::endl;
    std::cout<<"4 - Exit"<<std::endl;
}

void addDepartment()
{
    FILE *filename;
    fopen_s(&filename, "department.dat", "ab");
    fseek(filename, 0, SEEK_END);
    for (int i=0; i<1; i++)
    {
        std::cout<<"New department"<<std::endl;
        std::cout<<"ID - "<<std::endl;
        std::cin>>department.id;
        std::cout<<"Name - ";
        std::cin>>department.name;
        fwrite(&department, sizeof(department), 1, filename);

    }
    fclose(filename);
}

void showDepartment()
{
    FILE *filename;
    fopen_s(&filename, "department.dat", "r+b");
    fseek(filename, 0, SEEK_END);
    long pos = ftell(filename);
    fseek(filename, 0, SEEK_SET);
    int count = pos / sizeof(HOSPITAL);
    HOSPITAL* department = new HOSPITAL[count];
    fread(department, sizeof(HOSPITAL), count, filename);
}

void menuPatient()
{
    std::cout<<"Add new patient - 0"<<std::endl;
    std::cout<<"Show the patient list - 1"<<std::endl;
    std::cout<<"Delete a patient - 2"<<std::endl;
    std::cout<<"Find a patient - 3"<<std::endl;
    std::cout<<"Update a patient - 4"<<std::endl;
}

void addPatient()
{
    FILE *fp1;
    fopen_s(&fp1, "patient.dat", "ab");
    fseek(fp1, 0, SEEK_END);
    for (int i=0; i<1; i++)
    {
        std::cout<<"New patient"<<std::endl;
        std::cout<<"ID - "<<std::endl;
        std::cin>>patient.id;
        std::cout<<"Department ID - ";
        std::cin>>patient.idDepartment;
        std::cout<<"Name - ";
        std::cin>>patient.name;
        std::cout<<"Diagnos - ";
        std::cin>>patient.diagnos;
        std::cout<<"Operations - ";
        std::cin>>patient.operations;
        std::cout<<"Procedures - ";
        std::cin>>patient.procedures;
        std::cout<<"Pills -";
        std::cin>>patient.pills;

        fwrite(&patient, sizeof(patient), 1, fp1);

    }
    fclose(fp1);
}

void deletePatient()
{
    FILE *fp8;
    fopen_s(&fp8, "patient.dat", "r+b");
    fseek(fp8, 0, SEEK_END);
    long pos = ftell(fp8);
    fseek(fp8, 0, SEEK_SET);
    int count = pos / sizeof(PATIENT);
    PATIENT* patient = new PATIENT[count];
    fread(patient, sizeof(PATIENT), count, fp8);
    std::cout<<"Enter ID of the patient, you want to delete";
    int p;
    std::cin>>p;
    for (int i = 0; i <= count; i++) {
        if (patient[i].id == p) {
            patient[i].isDeleted = true;
            fseek(fp8, sizeof(patient)*(i), SEEK_SET);
            fwrite(&patient[i], sizeof(patient[i]), 1, fp8);
            delete[] patient;
            fclose(fp8);
            return;
        }
    }
    fclose(fp8);
}

void showPatientList(int a)
{
    FILE *fp1;
    fopen_s(&fp1, "patient.dat", "r+b");
    fseek(fp1, 0, SEEK_END);
    long pos = ftell(fp1);
    fseek(fp1, 0, SEEK_SET);
    int count = pos / sizeof(PATIENT);
    PATIENT* patient = new PATIENT[count];
    fread(patient, sizeof(PATIENT), count, fp1);
    for (int i = 0; i < count; i++)
    {
        if (a==patient[i].idDepartment)
        {
            std::cout<<"ID -  "<<patient[i].id<<".";
            std::cout<<"Name -  "<<patient[i].name<<std::endl;
            std::cout<<"ID Department - "<<patient[i].idDepartment<<std::endl;
            std::cout<<"Diagnos - "<<patient[i].diagnos<<std::endl;
            std::cout<<"Operations - "<<patient[i].operations<<std::endl;
            std::cout<<"Procedures - "<<patient[i].procedures<<std::endl;
            std::cout<<"Pills - "<<patient[i].pills<<std::endl;
        }

    }
    fclose(fp1);
}

void searchPatient()
{
    FILE *fp1;
    fopen_s(&fp1, "patient.dat", "r+b");
    fseek(fp1, 0, SEEK_END);
    long pos = ftell(fp1);
    fseek(fp1, 0, SEEK_SET);
    int count = pos / sizeof(PATIENT);
    PATIENT* patient = new PATIENT[count];
    fread(patient, sizeof(PATIENT), count, fp1);
    int p;
    std::cin>>p;
    for (int i = 0; i < count; i++)
    {
        if (p==patient[i].id)
        {
            std::cout<<"ID -  "<<patient[i].id<<".";
            std::cout<<"Name -  "<<patient[i].name<<std::endl;
            std::cout<<"ID Department - "<<patient[i].idDepartment<<std::endl;
            std::cout<<"Diagnos - "<<patient[i].diagnos<<std::endl;
            std::cout<<"Operations - "<<patient[i].operations<<std::endl;
            std::cout<<"Procedures - "<<patient[i].procedures<<std::endl;
            std::cout<<"Pills - "<<patient[i].pills<<std::endl;
        }

    }
    fclose(fp1);
}

void updateIdDepartment(int p)
{
    std::cout<<"I'm in"<<std::endl;
    FILE *fp3;
    fopen_s(&fp3, "patient.dat", "r+b");
    fseek(fp3, 0, SEEK_END);
    long pos = ftell(fp3);
    fseek(fp3, 0, SEEK_SET);
    int count = pos / sizeof(PATIENT);
    PATIENT *patient1 = new PATIENT[count];
    fread(patient1, sizeof(PATIENT), count, fp3);
    for (int i = 0; i <=count; i++)
    {
        std::cout<<"count"<<count;
        std::cout<<"patient id - "<<patient1[i].id<<std::endl;
        std::cout<<"p ="<<p<<std::endl;
        if (patient1[i].id == p)
        {
            std::cout<<"I'm in 2"<<std::endl;
            std::cout<<"Enter a new ID department - ";
            std::cin>>patient1[i].idDepartment;
            fseek(fp3, sizeof(patient1)*(i), SEEK_SET);
            fwrite(&patient1[i], sizeof(patient1[i]), 1, fp3);
            break;
        }
    }
    std::cout<<"count"<<count;
    fclose(fp3);
}

void updateDiagnos(int p)
{
    FILE *fp4;
    fopen_s(&fp4, "patient.dat", "r+b");
    fseek(fp4, 0, SEEK_END);
    long pos = ftell(fp4);
    fseek(fp4, 0, SEEK_SET);
    int count = pos / sizeof(PATIENT);
    PATIENT *patient2 = new PATIENT[count];
    fread(patient2, sizeof(PATIENT), count, fp4);
    for (int i = 0; i <=count; i++)
    {
        if (patient2[i].id == p)
        {
            std::cout<<"Enter a new diagnos - ";
            std::cin>>patient2[i].diagnos;
            fseek(fp4, sizeof(patient2)*(i), SEEK_SET);
            fwrite(&patient2[i], sizeof(patient2[i]), 1, fp4);
            break;
        }
    }
    fclose(fp4);

}

void updateOperations(int p)
{
    FILE *fp5;
    fopen_s(&fp5, "patient.dat", "r+b");
    fseek(fp5, 0, SEEK_END);
    long pos = ftell(fp5);
    fseek(fp5, 0, SEEK_SET);
    int count = pos / sizeof(PATIENT);
    PATIENT *patient3 = new PATIENT[count];
    fread(patient3, sizeof(PATIENT), count, fp5);
    for (int i = 0; i <=count; i++)
    {
        if (patient3[i].id == p)
        {
            std::cout<<"Enter a new operation - ";
            std::cin>>patient3[i].operations;
            fseek(fp5, sizeof(patient3)*(i), SEEK_SET);
            fwrite(&patient3[i], sizeof(patient3[i]), 1, fp5);
            break;
        }
    }
    fclose(fp5);
}

void updateProcedures(int p)
{
    FILE *fp6;
    fopen_s(&fp6, "patient.dat", "r+b");
    fseek(fp6, 0, SEEK_END);
    long pos = ftell(fp6);
    fseek(fp6, 0, SEEK_SET);
    int count = pos / sizeof(PATIENT);
    PATIENT *patient4 = new PATIENT[count];
    fread(patient4, sizeof(PATIENT), count, fp6);
    for (int i = 0; i <=count; i++)
    {
        if (patient4[i].id == p)
        {
            std::cout<<"Enter a new procedure - ";
            std::cin>>patient4[i].procedures;
            fseek(fp6, sizeof(patient4)*(i), SEEK_SET);
            fwrite(&patient4[i], sizeof(patient4[i]), 1, fp6);
            break;
        }
    }
    fclose(fp6);
}

void updatePills(int p)
{
    FILE *fp7;
    fopen_s(&fp7, "patient.dat", "r+b");
    fseek(fp7, 0, SEEK_END);
    long pos = ftell(fp7);
    fseek(fp7, 0, SEEK_SET);
    int count = pos / sizeof(PATIENT);
    PATIENT *patient4 = new PATIENT[count];
    fread(patient4, sizeof(PATIENT), count, fp7);
    for (int i = 0; i <=count; i++)
    {
        if (patient4[i].id == p)
        {
            std::cout<<"Enter a new operation - ";
            std::cin>>patient4[i].operations;
            fseek(fp7, sizeof(patient4)*(i), SEEK_SET);
            fwrite(&patient4[i], sizeof(patient4[i]), 1, fp7);
            break;
        }
    }
    fclose(fp7);

}

void updatePatient()
{
    FILE *fp2;
    fopen_s(&fp2, "patient.dat", "ab");
    fseek(fp2, 0, SEEK_END);
    long pos = ftell(fp2);
    fseek(fp2, 0, SEEK_SET);
    int count = pos / sizeof(PATIENT);
    PATIENT* patient = new PATIENT[count];
    fread(patient, sizeof(PATIENT), count, fp2);
    std::cout<<"Enter ID of the patient, you want to edit";
    int p;
    std::cin>>p;
    for (int i = 0; i < count; i++)
    {
        if (p==patient[i].id)
        {
            std::cout<<patient[i].id<<".";
            std::cout<<patient[i].name<<std::endl;
            std::cout<<patient[i].idDepartment<<std::endl;
            std::cout<<patient[i].diagnos<<std::endl;
            std::cout<<patient[i].operations<<std::endl;
            std::cout<<patient[i].procedures<<std::endl;
            std::cout<<patient[i].pills<<std::endl;
        }
    }
    fclose(fp2);
    std::cout<<"Enter what exactly you want to change"<<std::endl;
    std::cout<<"Department ID - 0"<<std::endl;
    std::cout<<"Diagnos - 1"<<std::endl;
    std::cout<<"Operations - 2"<<std::endl;
    std::cout<<"Procedures - 3"<<std::endl;
    std::cout<<"Pills - 4"<<std::endl;
    int g;
    std::cin>>g;
    switch(g)
    {
        case 0: updateIdDepartment(p);
        case 1: updateDiagnos(p);
        case 2: updateOperations(p);
        case 4: updateProcedures(p);
        case 5: updatePills(p);
    }
}

void choseDepartment()
{
    FILE *filename;
    fopen_s(&filename, "department.dat", "r+b");
    fseek(filename, 0, SEEK_END);
    long pos = ftell(filename);
    fseek(filename, 0, SEEK_SET);
    int count = pos / sizeof(HOSPITAL);
    HOSPITAL* department = new HOSPITAL[count];
    fread(department, sizeof(DATABASE), count, filename);
    for (int i = 0; i < count; i++)
    {
        std::cout<<department[i].id<<".";
        std::cout<<department[i].name<<std::endl;
    }
    fclose(filename);
    std::cout<<"Enter a department, which you want to chose";
    int a;
    std::cin>>a;
    menuPatient();
    int f;
    std::cin>>f;
    switch(f)
    {
        case 0: addPatient(); break;
        case 1: showPatientList(a); break;
        case 2: deletePatient(); ResaveDB(); break;
        case 3: searchPatient(); break;
        case 4: updatePatient();
    }
}

void menuAuthentication(DATABASE *part)
{
    if (part->isAdmin == 0)
    {
        int n;
        while (true)
        {
            menuDepartment();
            std::cin >> n;
            switch (n) {
                case 0:
                    addDepartment();
                    break;
                case 1:
                    showDepartment();
                    break;
                case 2:
                    choseDepartment();
                    break;
                case 4:
                    exit(0);
                    break;
                case 5:
                    updatePatient();


            }
        }
    }
    else if (part->isAdmin == 1)
    {
        std::cout << "Enter an ID of the patient you want to find";
        searchPatient();
        int k;
        std::cout<<"Enter 0, if you want to exit"<<std::endl;
        std::cin>>k;
        if (k==0)
        {
            exit(0);
        }
    }

}

int main()
{
    FILE *f;
    f = fopen("user.dat", "ab");
    fseek(f, 0, SEEK_END);
    int m;
    /*DATABASE part;*/
    DATABASE *Login;
    menuAuthorization();
    std::cin>>m;
    if (m==2)
    {
        signUp(part);
    }
    fclose(f);
    if (m==1)
    {
        Login=logIn();
        menuAuthentication(Login);
    }
    return 0;
}









