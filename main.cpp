#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Persoana // clasa parinte(Nume si Prenume)
{
    public:
        string nume;
        string prenume;
};
//

class Student : public Persoana //clasa student(ID si Medie)
{
    public:
        int id;
        float medie;
        string getText() // returnam un singur string
        {
            return nume + "\t" + prenume + "\t" + to_string(id) + "\t" + to_string(medie);
        }
};
//

class Profesor : public Persoana // clasa profesor(Domeniu)
{
    public:
        string domeniu;
        string getText()
        {
            return nume + "\t" + prenume + "\t" + domeniu;
        }
};

// declaram vectorii globali
Student vStud[100];
int nrStud = 0;

Profesor vProf[100];
int nrProf = 0;

// declaram functiile
void incarcareDate();
void salveazaDate();
bool checkId(int id);
void intStud();
void intProf();
void listareS();
void listareP();
void cautareS();
void cautareP();
void menu1();
void menu2();
void menu3();
void menuPrincipal();
//

int main() 
{
    incarcareDate();
    menuPrincipal();
    salveazaDate();
    return 0;
}
//

void incarcareDate() // citire din fisier
{
    ifstream fs("Studenti.txt"); // deschidem fisierul pentru a citi
    if(fs.is_open())
    {
        while(fs >> vStud[nrStud].nume >> vStud[nrStud].prenume >> vStud[nrStud].id >> vStud[nrStud].medie)
        {
            nrStud++; // creste daca a citit cu succes
        }
        fs.close(); // confirmam citirea studentilor
    }
    
    ifstream fp("Profesori.txt");
    if(fp.is_open())
    {
        while(fp >> vProf[nrProf].nume >> vProf[nrProf].prenume >> vProf[nrProf].domeniu)
        {
            nrProf++; // creste daca a citit cu succes
        }
        fp.close();
    }
}
//

void salveazaDate() // scriere in fisier
{
    ofstream fs("Studenti.txt");
    for(int i = 0 ; i < nrStud ; i++) // pt fiecare student scrie o linie in fisier
    {
        fs << vStud[i].nume << " " << vStud[i].prenume << " " << vStud[i].id << " " << vStud[i].medie << "\n";
    }
    fs.close(); // confirmam scrierea studentilor
    
    ofstream fp("Profesori.txt");
    for(int i = 0 ; i < nrProf ; i++) // pt fiecare profesor scrie o linie in fisier
    {
        fp << vProf[i].nume << " " << vProf[i].prenume << " " << vProf[i].domeniu << "\n";
    }
    fp.close(); // confirmam scrierea profesorilor
}
//

bool checkId(int id) // verificare ID
{
    for(int i = 0 ; i < nrStud ; i++)
    {
        if(vStud[i].id == id) // comparam fiecare id cu ID-ul cautat
            return true; // Adevarat daca coincid
    }
    return false; // Fals daca nu am gasit
}
//

void intStud() // citire studenti
{
    if(nrStud >= 100)
    {
        cout << "\n   Memorie plina!\n";
        return;
    }
    
    int optiune;
    
    do
    {
        Student temp; // variabila temporara pentru citire date
        
        cout << "\n   Introdu Numele de Familie: ";
        cin >> temp.nume;
        
        cout << "\n   Introdu Prenumele: ";
        cin >> temp.prenume;
        
        do
        {
            cout << "\n   Introdu ID Student: ";
            cin >> temp.id;
            
            if(checkId(temp.id))
                cout << "\n   ID-ul este deja alocat!\n   Introdu alt ID\n";
                
        }while(checkId(temp.id));
        
        cout << "\n   Introdu Media: ";
        cin >> temp.medie;
        
        vStud[nrStud] = temp; // valoarea temporara o salvam in vector
        nrStud++; // incrementam indexul/numarul de studenti
        
        cout << "\n   Mai adaugati un student?(1=yes/0=no): ";
        cin >> optiune;
        
    }while(optiune == 1 && nrStud < 100);
}
//

void intProf() // citire profesori
{
    if(nrProf >= 100)
    {
        cout << "\n   Memorie plina!\n";
        return;
    }
    
    int optiune;
    
    do
    {
        Profesor temp; // variabila temporara pentru citire date
        
        cout << "\n   Introdu Numele de Familie: ";
        cin >> temp.nume;
        
        cout << "\n   Introdu Prenumele: ";
        cin >> temp.prenume;
        
        cout << "\n   Introdu Materia Predata: ";
        cin >> temp.domeniu;
        
        vProf[nrProf] = temp; // valoarea temporara o salvam in vector
        nrProf++; // incrementam indexul/numarul de profesori
        
        cout << "\n   Mai adaugati un profesor?(1=yes/0=no): ";
        cin >> optiune;
        
    }while(optiune == 1 && nrProf < 100);
}
//

void listareS() // listare studenti
{
    if(nrStud == 0)
    {
        cout << "\n   Fisierul este gol!\n";
        return;
    }
    
    cout << "\nNume\t\tPrenume\t\tID\tMedie\n";
    cout << "---------------------------------------------------\n";
    
    for(int i = 0 ; i < nrStud ; i++)
    {
        cout << vStud[i].getText() << "\n";
    }
}
//

void listareP() // listare profesori
{
    if(nrProf == 0)
    {
        cout << "\n   Fisierul este gol!\n";
        return;
    }
    
    cout << "\nNume\t\tPrenume\t\tDomeniu\n";
    cout << "---------------------------------------------------\n";
    
    for(int i = 0 ; i < nrProf ; i++)
    {
        cout << vProf[i].getText() << "\n";
    }
}
//

void cautareS() // cautare student
{
    int idCautat;
    bool gasit;
    
    do
    {
        gasit = false;
        
        cout << "\n   Introdu ID Student(0 pentru iesire): ";
        cin >> idCautat;
        
        if(idCautat == 0) // iesire fortata din bucla
            return;
        
        for(int i = 0 ; i < nrStud ; i++)
        {
            if(vStud[i].id == idCautat)
            {
                cout << "\nNume\t\tPrenume\t\tID\tMedie\n";
                cout << "---------------------------------------------------\n";
                cout << vStud[i].getText() << "\n";
                gasit = true;
                break; // intrerupem iteratia daca am gasit ID-ul
            }
        }
        
        if(!gasit) // gasit=False va printa mesajul (!False=True)
                   // gasit=True nu va executa instructiunea (!True=False)
            cout << "\n   Nu am gasit ID-ul!\n";
            
    }while(!gasit); // daca !gasit=False(gasit=True) se opreste bucla
}
//

void cautareP()
{
    string sirCautat;
    bool gasit;
    
    do
    {
        gasit = false;
        cout << "\n   Introdu Numele(scrie 'exit' pentru iesire): ";
        cin >> sirCautat;
        
        if(sirCautat == "exit") // daca utilizatorul scrie 'exit' iesim
            return;
        
        cout << "\nNume\t\tPrenume\t\tDomeniu\n";
        cout << "---------------------------------------------------\n";
        
        for(int i = 0 ; i < nrProf ; i++)
        {
            int pozNume    = vProf[i].nume.find(sirCautat);
            int pozPrenume = vProf[i].prenume.find(sirCautat);
            
            if(pozNume != -1 || pozPrenume != -1) // FIND returneaza -1 daca subsirul nu se afla in sirul cautat
            {
                cout << vProf[i].getText() << "\n";
                gasit = true;
            }
        }
        
        if(!gasit) // gasit=False va printa mesajul (!False=True)
                   // gasit=True nu va executa instructiunea (!True=False)
            cout << "\n   Nu am gasit numele!\n";
            
    }while(!gasit); // daca !gasit=False(gasit=True) se opreste bucla
}
//

void menu1()
{
    int optiune;
    do
    {
        cout << "\n   INTRODUCERE DATE\n\n";
        cout << "   1) Despre studenti\n";
        cout << "   2) Despre profesori\n";
        cout << "   3) Revenire la meniul principal\n\n";
        cout << "   Alege o optiune: ";
        cin >> optiune;
        
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
            cout << "\n   Optiune incorecta!\n";
        }
    }while(optiune != 3);
}
//

void menu2()
{
    int optiune;
    do
    {
        cout << "\n   CAUTARE DATE\n\n";
        cout << "   1) Despre studenti\n";
        cout << "   2) Despre profesori\n";
        cout << "   3) Revenire la meniul principal\n\n";
        cout << "   Alege o optiune: ";
        cin >> optiune;
        
        switch(optiune)
        {
        case 1:
            cautareS();
            break;
        case 2:
            cautareP();
            break;
        case 3:
            return;
        default:
            cout << "\n   Optiune incorecta!\n";
        }
    }while(optiune != 3);
}
//

void menu3()
{
    int optiune;
    do
    {
        cout << "\n   LISTARE DATE\n\n";
        cout << "   1) Despre studenti\n";
        cout << "   2) Despre profesori\n";
        cout << "   3) Revenire la meniul principal\n\n";
        cout << "   Alege o optiune: ";
        cin >> optiune;
        
        switch(optiune)
        {
        case 1:
            listareS();
            break;
        case 2:
            listareP();
            break;
        case 3:
            return;
        default:
            cout << "\n   Optiune incorecta!\n";
        }
    }while(optiune != 3);
}
//

void menuPrincipal()
{
    int optiune;
    do
    {
        cout << "\n   MENIU PRINCIPAL\n\n";
        cout << "   1) Introducere date\n";
        cout << "   2) Cautare date\n";
        cout << "   3) Listare date\n";
        cout << "   0) Iesire Applicatie\n\n";
        cout << "   Alege o optiune: ";
        cin >> optiune;
        
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
            cout << "\n   Optiune incorecta!\n";
        }
    }while(optiune != 0);
}
