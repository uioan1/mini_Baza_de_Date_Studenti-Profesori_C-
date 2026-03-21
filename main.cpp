#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Persoana // clasa parinte(Nume si Prenume)
{
    public:
        string Nume;
        string Prenume;
};
//

class Student : public Persoana //clasa student(ID si Medie)
{
    public:
        int ID;
        float Medie;
        string getText() // returnam un singur string
        {
            return Nume + "\t" + Prenume + "\t" + to_string(ID) + "\t" + to_string(Medie);
        }
};
//

class Profesor : public Persoana // clasa profesor(Domeniu)
{
    public:
        string Domeniu;
        string getText()
        {
            return Nume + "\t" + Prenume + "\t" + Domeniu;
        }
};

// declaram vectorii globali
Student Vstud[100];
int NrStud=0;

Profesor Vprof[100];
int NrProf=0;

// declaram functiile
void incarcareDate();
void salveazaDate();
bool checkID(int id);
void intStud();
void intProf();
void ListareS();
void ListareP();
void CautareS();
void CautareP();
void menu1();
void menu2();
void menu3();
void menuP();
//

int main() 
{
    incarcareDate();
    menuP();
    salveazaDate();
    return 0;
}
//

void incarcareDate() // citire din fisier
{
    ifstream fs("Studenti.txt"); // deschidem fisierul pentru a citi
    if(fs.is_open())
    {
        while(fs>>Vstud[NrStud].Nume>>Vstud[NrStud].Prenume>>Vstud[NrStud].ID>>Vstud[NrStud].Medie)
        {
            NrStud++; // creste daca a citit cu succes
        }
        fs.close(); // confirmam citirea studentilor
    }
    
    ifstream fp("Profesori.txt");
    if(fp.is_open())
    {
        while(fp>>Vprof[NrProf].Nume>>Vprof[NrProf].Prenume>>Vprof[NrProf].Domeniu)
        {
            NrProf++; // creste daca a citit cu succes
        }
        fp.close();
    }
}
//

void salveazaDate() // scriere in fisier
{
    ofstream fs("Studenti.txt");
    for(int i=0 ; i<NrStud ; i++) // pt fiecare student scrie o linie in fisier
    {
        fs<<Vstud[i].Nume<<" "<<Vstud[i].Prenume<<" "<<Vstud[i].ID<<" "<<Vstud[i].Medie<<"\n";
    }
    fs.close(); // confirmam scrierea studentilor
    
    ofstream fp("Profesori.txt");
    for(int i=0 ; i<NrProf ; i++) // pt fiecare profesor scrie o linie in fisier
    {
        fp<<Vprof[i].Nume<<" "<<Vprof[i].Prenume<<" "<<Vprof[i].Domeniu<<"\n";
    }
    fp.close(); // confirmam scrierea profesorilor
}
//

bool checkID(int id) // verificare ID
{
    for(int i=0 ; i<NrStud ; i++)
    {
        if(Vstud[i].ID==id) // comparam fiecare id cu ID-ul cautat
            return true; // Adevarat daca coincid
    }
    return false; // Fals daca nu am gasit
}
//

void intStud() // citire studenti
{
    if(NrStud >= 100)
    {
        cout<<"\n   Memorie plina!\n";
        return;
    }
    
    int optiune;
    
    do
    {
        Student temp; // variabila temporara pentru citire date
        
        cout<<"\n   Introdu Numele de Familie: ";
        cin>>temp.Nume;
        
        cout<<"\n   Introdu Prenumele: ";
        cin>>temp.Prenume;
        
        do
        {
            cout<<"\n   Introdu ID Student: ";
            cin>>temp.ID;
            
            if(checkID(temp.ID))
                cout<<"\n   ID-ul este deja alocat!\n   Introdu alt ID\n";
                
        }while(checkID(temp.ID));
        
        cout<<"\n   Introdu Media: ";
        cin>>temp.Medie;
        
        Vstud[NrStud]=temp; // valoarea temporara o salvam in vector
        NrStud++; // incrementam indexul/numarul de studenti
        
        cout<<"\n   Mai adaugati un student?(1=yes/0=no): ";
        cin>>optiune;
        
    }while(optiune==1 && NrStud<100);
}
//

void intProf() // citire profesori
{
    if(NrProf >= 100)
    {
        cout<<"\n   Memorie plina!\n";
        return;
    }
    
    int optiune;
    
    do
    {
        Profesor temp; // variabila temporara pentru citire date
        
        cout<<"\n   Introdu Numele de Familie: ";
        cin>>temp.Nume;
        
        cout<<"\n   Introdu Prenumele: ";
        cin>>temp.Prenume;
        
        cout<<"\n   Introdu Materia Predata: ";
        cin>>temp.Domeniu;
        
        Vprof[NrProf]=temp; // valoarea temporara o salvam in vector
        NrProf++; // incrementam indexul/numarul de profesori
        
        cout<<"\n   Mai adaugati un profesor?(1=yes/0=no): ";
        cin>>optiune;
        
    }while(optiune==1 && NrProf<100);
}
//

void ListareS() // listare studenti
{
    if(NrStud == 0)
    {
        cout<<"\n   Fisierul este gol!\n";
        return;
    }
    
    cout<<"\nNume\t\tPrenume\t\tID\tMedie\n";
    cout<<"---------------------------------------------------\n";
    
    for(int i=0 ; i<NrStud ; i++)
    {
        cout<<Vstud[i].getText()<<"\n";
    }
}
//

void ListareP() // listare profesori
{
    if(NrProf == 0)
    {
        cout<<"\n   Fisierul este gol!\n";
        return;
    }
    
    cout<<"\nNume\t\tPrenume\t\tDomeniu\n";
    cout<<"---------------------------------------------------\n";
    
    for(int i=0 ; i<NrProf ; i++)
    {
        cout<<Vprof[i].getText()<<"\n";
    }
}
//

void CautareS() // cautare student
{
    int IDc;
    bool gasit;
    
    do
    {
        gasit=false;
        
        cout<<"\n   Introdu ID Student(0 pentru iesire): ";
        cin>>IDc;
        
        if(IDc == 0) // iesire fortata din bucla
            return;
        
        for(int i=0 ; i<NrStud ; i++)
        {
            if(Vstud[i].ID == IDc)
            {
                cout<<"\nNume\t\tPrenume\t\tID\tMedie\n";
                cout<<"---------------------------------------------------\n";
                cout<<Vstud[i].getText()<<"\n";
                gasit=true;
                break; // intrerupem iteratia daca am gasit ID-ul
            }
        }
        
        if(!gasit) // gasit=False va printa mesajul (!False=True)
                   // gasit=True nu va executa instructiunea (!True=False)
            cout<<"\n   Nu am gasit ID-ul!\n";
            
    }while(!gasit); // daca !gasit=False(gasit=True) se opreste bucla
}
//

void CautareP()
{
    string sirCautat;
    bool gasit;
    
    do
    {
        gasit=false;
        cout<<"\n   Introdu Numele(scrie 'exit' pentru iesire): ";
        cin>>sirCautat;
        
        if(sirCautat == "exit") // daca utilizatorul scrie 'exit' iesim
            return;
        
        cout<<"\nNume\t\tPrenume\t\tDomeniu\n";
        cout<<"---------------------------------------------------\n";
        
        for(int i=0 ; i<NrProf ; i++)
        {
            int pozNume=Vprof[i].Nume.find(sirCautat);
            int pozPrenume=Vprof[i].Prenume.find(sirCautat);
            
            if(pozNume!=-1 || pozPrenume!=-1) // FIND returneaza -1 daca subsirul nu se afla in sirul cautat
            {
                cout<<Vprof[i].getText()<<"\n";
                gasit=true;
            }
        }
        
        if(!gasit) // gasit=False va printa mesajul (!False=True)
                   // gasit=True nu va executa instructiunea (!True=False)
            cout<<"\n   Nu am gasit numele!\n";
            
    }while(!gasit); // daca !gasit=False(gasit=True) se opreste bucla
}
//

void menu1()
{
    int optiune;
    do
    {
        cout<<"\n   INTRODUCERE DATE\n\n";
        cout<<"   1) Despre studenti\n";
        cout<<"   2) Despre profesori\n";
        cout<<"   3) Revenire la meniul principal\n\n";
        cout<<"   Alege o optiune: ";
        cin>>optiune;
        
        switch(optiune)
        {
        case 1:
            intStud();
            break;
        case 2:
            intProf();
            break;
        case 3:
            return;
        default:
            cout<<"\n   Optiune incorecta!\n";
        }
    }while(optiune != 3);
}
//

void menu2()
{
    int optiune;
    do
    {
        cout<<"\n   CAUTARE DATE\n\n";
        cout<<"   1) Despre studenti\n";
        cout<<"   2) Despre profesori\n";
        cout<<"   3) Revenire la meniul principal\n\n";
        cout<<"   Alege o optiune: ";
        cin>>optiune;
        
        switch(optiune)
        {
        case 1:
            CautareS();
            break;
        case 2:
            CautareP();
            break;
        case 3:
            return;
        default:
            cout<<"\n   Optiune incorecta!\n";
        }
    }while(optiune != 3);
}
//

void menu3()
{
    int optiune;
    do
    {
        cout<<"\n   LISTARE DATE\n\n";
        cout<<"   1) Despre studenti\n";
        cout<<"   2) Despre profesori\n";
        cout<<"   3) Revenire la meniul principal\n\n";
        cout<<"   Alege o optiune: ";
        cin>>optiune;
        
        switch(optiune)
        {
        case 1:
            ListareS();
            break;
        case 2:
            ListareP();
            break;
        case 3:
            return;
        default:
            cout<<"\n   Optiune incorecta!\n";
        }
    }while(optiune != 3);
}
//

void menuP()
{
    int optiune;
    do
    {
        cout<<"\n   MENIU PRINCIPAL\n\n";
        cout<<"   1) Introducere date\n";
        cout<<"   2) Cautare date\n";
        cout<<"   3) Listare date\n";
        cout<<"   0) Iesire Applicatie\n\n";
        cout<<"   Alege o optiune: ";
        cin>>optiune;
        
        switch(optiune)
        {
        case 1:
            menu1();
            break;
        case 2:
            menu2();
            break;
        case 3:
            menu3();
            break;
        case 0:
            return;
        default:
            cout<<"\n   Optiune incorecta!\n";
        }
    }while(optiune != 0);
}
