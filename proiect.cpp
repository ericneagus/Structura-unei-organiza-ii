/*
    Tema: Structura unei organizatii
    Problema: Gestionarea unor angajati, salariile acestora si relatiile ierarhice dintre ei

    Date de intrare: nume, varsta, functie, id
    - salariu de baza, bonusuri
    - relatii intre angajati

    Clase: Angajati, Salarii, Relatii_Ierarhice

    Operatii:
    - gestionarea angajatilor
    - gestionarea relatiilor ierarhice
    - operatii asupra salariilor

*/

#include <iostream>
#include <cstring>
using namespace std;

class Salariu{
    float salariu;
    float bonusuri;

    public:
        Salariu() {
            salariu = 0;
            bonusuri = 0;
        }

        Salariu(const Salariu& c2){
            salariu = c2.salariu;
            bonusuri = c2.bonusuri;
        }

        Salariu& operator=(const Salariu& c2){
            if(this != &c2){
                salariu = c2.salariu;
                bonusuri = c2.bonusuri;
            }
            return *this;
        }
       
        ~Salariu() {}

        Salariu(float suma, float sumabon) {
            salariu = suma;
            bonusuri = sumabon;
        }

        void AtribuireDate(float suma, float sumabon) {
            salariu = suma;
            bonusuri = sumabon;
        }

        void MarireSalariu(float procent) {
            salariu = salariu + salariu * procent /100;
        }

        void MarireBonusuri(float procent) {
            bonusuri = bonusuri + bonusuri * procent /100;
        }

        void EliminaBonusuri() {
            bonusuri = 0;
        }

        float retSalariu() const {return salariu;}
        
        float retBonusuri() const {return bonusuri;}

        float Total() const{
            return salariu + bonusuri;
        }

        void AfisareSalariu() const {
            cout<<"Salariu baza: "<<salariu<<'\n';
            cout<<"Bonus: "<<bonusuri<<'\n';
            cout<<"Total: "<<Total()<<'\n';
        }

        friend ostream& operator<<(ostream& out, const Salariu& s){
            out<<"Salariu baza: "<<s.salariu<<'\n';
            out<<"Bonus: "<<s.bonusuri<<'\n';
            out<<"Total: "<<s.Total()<<'\n';
            return out;
        }
};

class Angajat{
    
    char id[10];
    int varsta;
    char nume[50];
    char functie[70];
    Salariu S;

    public:
        Angajat(){
            strcpy(id,"?");
            varsta = 0;
            strcpy(nume, "Anonim");
            strcpy(functie, "Nedefinita");
        };
        Angajat(const char i[],const char n[], int v,const char f[],Salariu& s1){
            strcpy(id,i);
            strcpy(nume,n);
            varsta = v;
            strcpy(functie,f);
            S = s1;
        };
        Angajat(const Angajat& a2) {
            strcpy(id,a2.id);
            strcpy(nume,a2.nume);
            varsta = a2.varsta;
            strcpy(functie,a2.functie);
            S = a2.S;
        }
        Angajat& operator=(const Angajat& a2){
            if (this!= &a2){
                strcpy(id,a2.id);
                strcpy(nume,a2.nume);
                varsta = a2.varsta;
                strcpy(functie,a2.functie);
                S = a2.S;
            }
            return *this;
        }
        ~Angajat() {}
        void AtribuireDatePersonale(char i[],char n[], int v, char f[],Salariu& s1){
            strcpy(id,i);
            strcpy(nume,n);
            varsta = v;
            strcpy(functie,f);
            S = s1;
        };
        void AtribuireSalariu(const Salariu& slr){
            S = slr;
        }

        void MarireSalariu(float procent) {
            S.MarireSalariu(procent);
        }

        void MarireBonusuri(float procent) {
            S.MarireBonusuri(procent);
        }

        void EsteMajor() const{
            if(varsta>=18) cout<<"Angajatul "<<nume<<" este major!"<<'\n';
            else cout<<"Angajatul "<<nume<<" este minor!"<<'\n';
        }

        void SchimbaFunctie(const char f[]) {
            strcpy(functie,f);
        }

        int DiferentaVarsta(const Angajat& a2) const{
            if (varsta > a2.varsta){
                return varsta - a2.varsta;
            }
            else return a2.varsta - varsta;
        }

        const char* Nume() const {return nume;};
        const char* Id() const {return id;};
        int Varsta() const {return varsta;};
        const char* Functie() const {return functie;};
        void AfisareDate() const {
             /*cout<<"ID: "<<id<<'\n';
             cout<<"NUME: "<<nume<<'\n';
             cout<<"VARSTA: "<<varsta<<'\n';
             cout<<"FUNCTIE: "<<functie<<'\n';*/
             cout<<id<<" - "<<nume<<" - "<<varsta<<" - "<<functie<<'\n';
             S.AfisareSalariu();
    }
        friend ostream& operator<<(ostream& out, const Angajat& a){
             out<<a.id<<" - "<<a.nume<<" - "<<a.varsta<<" - "<<a.functie<<'\n';
             out<<a.S<<'\n';
            return out;
        }

};

class Relatii_Ierarhice{
    Angajat sub,sef;
    public:
        Relatii_Ierarhice() {}
        Relatii_Ierarhice(const Angajat& a1, const Angajat& a2) {
            sub = a1;
            sef = a2;
        }
        Relatii_Ierarhice(const Relatii_Ierarhice& r){
            sub = r.sub;
            sef = r.sef;
        }
        Relatii_Ierarhice& operator=(const Relatii_Ierarhice& r){
            if(this != &r){
                sub = r.sub;
                sef = r.sef;
            }
            return *this;
        }
        ~Relatii_Ierarhice() {}
        void AdaugaRelatie(const Angajat& a1, const Angajat& a2) {
            sub = a1;
            sef = a2;
        }

        bool EsteSeful(const char numeSef[]) const{
            return strcmp(sef.Nume(),numeSef) == 0;
        }

        bool EsteSubordonatul(const char numeSub[]) const{
            return strcmp(sub.Nume(),numeSub) == 0;
        }

        void Afisare() const{
            cout<<sef.Nume()<<" este seful lui "<<sub.Nume()<<'\n';
        }

        friend ostream& operator<<(ostream& out, const Relatii_Ierarhice& r){
            out<<r.sef.Nume()<<" este seful lui "<<r.sub.Nume()<<'\n';
            return out;
        }
};

int NrCifre(int nr){
    int i=0;
    while(nr){
        i++;
        nr=nr/10;
    }
    return i;
}

void ConversieID(char *id,int nr,int nr_cifre){
    while(nr_cifre>0){
        id[1+nr_cifre]=(nr%10) + '0';
        nr=nr/10;
        nr_cifre--;
    }
}



int main(){
    
    Salariu s1(5000.25,3000.25);
    Salariu s2(400, 50.667);
    Salariu s3(15600,2555);

    Salariu s4 =s2,s5;
    s5 = s1;

    cout<<s4<<s5;

    Angajat a1("id1", "Andrei Popescu", 45, "Manager", s1);
    Angajat a2("id2", "Ion Ionescu", 12, "Programator", s2);
    Angajat a3("id3", "Ana Georgescu", 16, "Contabil", s3);

    cout<<a1<<a2<<a3;

    a1.EsteMajor();
    a2.EsteMajor();

    a3.SchimbaFunctie("Sofer");
    a2.MarireBonusuri(15);
    a1.MarireSalariu(50);
    cout<<a1<<a2<<a3;

    Relatii_Ierarhice r1(a1, a2);
    Relatii_Ierarhice r2(a3, a1);

    cout<<r1<<r2;
    if(r1.EsteSeful("Ion Ionescu")) cout<<"Ion Ionescu este sef."<<'\n';

    /*
    Angajat A[101];
    Relatii_Ierarhice R[101];
    
    int x = -1,nr_angajati = 0;
    
    while(x!=0) {
        cout<<"1. Adauga angajat!"<<'\n';
        cout<<"2. Sterge angajat!"<<'\n';
        cout<<"3. Afiseaza angajati!"<<'\n';
        cout<<"4. Adauga relatii ierarhice!"<<'\n';
        cout<<"5. Afiseaza relatiile ierarhice!"<<'\n';
        cout<<"0. Iesire!"<<'\n';
        cin >> x;cin.get();
        if(x==1) {
            nr_angajati++;
            char nume[50],functie[70],id[10]="id";
            int varsta;
            float salariu,bonus;
            cout<<"Nume:";cin.get(nume,50);
            cin.get();
            cout<<"Varsta:";cin>>varsta;
            cin.get();
            cout<<"Functie:";cin.get(functie,70);
            cin.get();
            cout<<"Salariu:";cin>>salariu;
            cin.get();
            cout<<"Bonus:";cin>>bonus;
            cin.get();
            Salariu S;
            S.AtribuireDate(salariu,bonus);
            ConversieID(id,nr_angajati,NrCifre(nr_angajati));
            A[nr_angajati].AtribuireDatePersonale(id,nume,varsta,functie);  
            A[nr_angajati].AtribuireSalariu(S);
        }
        else if(x==2) {
            char id[10]="";
            bool gasit = 0;
            cout<<"ID-ul angajatului pe care vrei sa il stergi:";cin.get(id,10);
            cin.get();
            for(int i=1;i<=nr_angajati;i++)
                if(strcmp(id,A[i].Id())==0) {
                    cout<<"Angajatul "<<A[i].Nume()<<" a fost sters cu succes!"<<'\n';
                    for(int j=i;j<nr_angajati;j++)
                        A[j]=A[j+1];
                    nr_angajati--;
                    gasit = 1;
                    break;
                }
            if(gasit==0) cout<<"Angajatul nu a fost gasit!"<<'\n';

        }
        else if(x==3) {
            if(nr_angajati==0) cout<<"Niciun angajat gasit!"<<'\n';
            for(int i=1;i<=nr_angajati;i++)
                A[i].AfisareDate();
        }
        else if(x==4) {

        }
    }
    */
    /*
    A.AtribuireDatePersonale("c31","Marina Bai",30,"Primar");
    B.AtribuireDatePersonale("c32","Cristian Maciuca",40,"Programator");
    S1.AtribuireDate(500,200.50);
    A.AtribuireSalariu(S1);
    B.AtribuireSalariu(S1);
    A.AfisareDate();
    B.AfisareDate();
    R1.AdaugaRelatie(A,B);
    R1.Afisare();*/

}        Salariu& operator=(const Salariu& c2){
            if(this != &c2){
                salariu = c2.salariu;
                bonusuri = c2.bonusuri;
            }
            return *this;
        }
       
        ~Salariu() {}

        Salariu(float suma, float sumabon) {
            salariu = suma;
            bonusuri = sumabon;
        }

        void AtribuireDate(float suma, float sumabon) {
            salariu = suma;
            bonusuri = sumabon;
        }

        void MarireSalariu(float procent) {
            salariu = salariu + salariu * procent /100;
        }

        void MarireBonusuri(float procent) {
            bonusuri = bonusuri + bonusuri * procent /100;
        }

        void EliminaBonusuri() {
            bonusuri = 0;
        }

        float retSalariu() const {return salariu;}
        
        float retBonusuri() const {return bonusuri;}

        float Total() const{
            return salariu + bonusuri;
        }

        void AfisareSalariu() const {
            cout<<"Salariu baza: "<<salariu<<'\n';
            cout<<"Bonus: "<<bonusuri<<'\n';
            cout<<"Total: "<<Total()<<'\n';
        }

        friend ostream& operator<<(ostream& out, const Salariu& s){
            out<<"Salariu baza: "<<s.salariu<<'\n';
            out<<"Bonus: "<<s.bonusuri<<'\n';
            out<<"Total: "<<s.Total()<<'\n';
            return out;
        }
};

class Angajat{
    
    char id[10];
    int varsta;
    char nume[50];
    char functie[70];
    Salariu S;

    public:
        Angajat(){
            strcpy(id,"?");
            varsta = 0;
            strcpy(nume, "Anonim");
            strcpy(functie, "Nedefinita");
        };
        Angajat(const char i[],const char n[], int v,const char f[],Salariu s1){
            strcpy(id,i);
            strcpy(nume,n);
            varsta = v;
            strcpy(functie,f);
            S = s1;
        };
        Angajat(const Angajat& a2) {
            strcpy(id,a2.id);
            strcpy(nume,a2.nume);
            varsta = a2.varsta;
            strcpy(functie,a2.functie);
            S = a2.S;
        }
        Angajat& operator=(const Angajat& a2){
            if (this!= &a2){
                strcpy(id,a2.id);
                strcpy(nume,a2.nume);
                varsta = a2.varsta;
                strcpy(functie,a2.functie);
                S = a2.S;
            }
            return *this;
        }
        ~Angajat() {}
        void AtribuireDatePersonale(char i[],char n[], int v, char f[]){
            strcpy(id,i);
            strcpy(nume,n);
            varsta = v;
            strcpy(functie,f);
        };
        void AtribuireSalariu(const Salariu& slr){
            S = slr;
        }

        void MarireSalariu(float procent) {
            S.MarireSalariu(procent);
        }

        void MarireBonusuri(float procent) {
            S.MarireBonusuri(procent);
        }

        void EsteMajor() const{
            if(varsta>=18) cout<<"Angajatul "<<nume<<" este major!"<<'\n';
            else cout<<"Angajatul "<<nume<<" este minor!"<<'\n';
        }

        void SchimbaFunctie(const char f[]) {
            strcpy(functie,f);
        }

        int DiferentaVarsta(const Angajat& a2) const{
            if (varsta > a2.varsta){
                return varsta - a2.varsta;
            }
            else return a2.varsta - varsta;
        }

        const char* Nume() const {return nume;};
        const char* Id() const {return id;};
        int Varsta() const {return varsta;};
        const char* Functie() const {return functie;};
        void AfisareDate() const {
             /*cout<<"ID: "<<id<<'\n';
             cout<<"NUME: "<<nume<<'\n';
             cout<<"VARSTA: "<<varsta<<'\n';
             cout<<"FUNCTIE: "<<functie<<'\n';*/
             cout<<id<<" - "<<nume<<" - "<<varsta<<" - "<<functie<<'\n';
             S.AfisareSalariu();
    }
        friend ostream& operator<<(ostream& out, const Angajat& a){
             cout<<a.id<<" - "<<a.nume<<" - "<<a.varsta<<" - "<<a.functie<<'\n';
             cout<<a.S<<'\n';
            return out;
        }

};

class Relatii_Ierarhice{
    Angajat sub,sef;
    public:
        Relatii_Ierarhice() {}
        Relatii_Ierarhice(const Angajat& a1, const Angajat& a2) {
            sub = a1;
            sef = a2;
        }
        Relatii_Ierarhice(const Relatii_Ierarhice& r){
            sub = r.sub;
            sef = r.sef;
        }
        Relatii_Ierarhice& operator=(const Relatii_Ierarhice& r){
            if(this != &r){
                sub = r.sub;
                sef = r.sef;
            }
            return *this;
        }
        ~Relatii_Ierarhice() {}
        void AdaugaRelatie(const Angajat& a1, const Angajat& a2) {
            sub = a1;
            sef = a2;
        }

        bool EsteSeful(const char numeSef[]) const{
            return strcmp(sef.Nume(),numeSef) == 0;
        }

        bool EsteSubordonatul(const char numeSub[]) const{
            return strcmp(sub.Nume(),numeSub) == 0;
        }

        void Afisare() const{
            cout<<sef.Nume()<<" este seful lui "<<sub.Nume()<<'\n';
        }

        friend ostream& operator<<(ostream& out, const Relatii_Ierarhice& r){
            cout<<r.sef.Nume()<<" este seful lui "<<r.sub.Nume()<<'\n';
            return out;
        }
};

int NrCifre(int nr){
    int i=0;
    while(nr){
        i++;
        nr=nr/10;
    }
    return i;
}

void ConversieID(char *id,int nr,int nr_cifre){
    while(nr_cifre>0){
        id[1+nr_cifre]=(nr%10) + '0';
        nr=nr/10;
        nr_cifre--;
    }
}



int main(){
    
    Salariu s1(5000.25,3000.25);
    Salariu s2(400, 50.667);
    Salariu s3(15600,2555);

    Salariu s4 =s2,s5;
    s5 = s1;

    cout<<s4<<s5;

    Angajat a1("id1", "Andrei Popescu", 45, "Manager", s1);
    Angajat a2("id2", "Ion Ionescu", 12, "Programator", s2);
    Angajat a3("id3", "Ana Georgescu", 16, "Contabil", s3);

    cout<<a1<<a2<<a3;

    a1.EsteMajor();
    a2.EsteMajor();

    a3.SchimbaFunctie("Sofer");
    a2.MarireBonusuri(15);
    a1.MarireSalariu(50);
    cout<<a1<<a2<<a3;

    Relatii_Ierarhice r1(a1, a2);
    Relatii_Ierarhice r2(a3, a1);

    cout<<r1<<r2;
    if(r1.EsteSeful("Ion Popescu")==0) cout<<"Ion Popescu este sef."<<'\n';

    /*
    Angajat A[101];
    Relatii_Ierarhice R[101];
    
    int x = -1,nr_angajati = 0;
    
    while(x!=0) {
        cout<<"1. Adauga angajat!"<<'\n';
        cout<<"2. Sterge angajat!"<<'\n';
        cout<<"3. Afiseaza angajati!"<<'\n';
        cout<<"4. Adauga relatii ierarhice!"<<'\n';
        cout<<"5. Afiseaza relatiile ierarhice!"<<'\n';
        cout<<"0. Iesire!"<<'\n';
        cin >> x;cin.get();
        if(x==1) {
            nr_angajati++;
            char nume[50],functie[70],id[10]="id";
            int varsta;
            float salariu,bonus;
            cout<<"Nume:";cin.get(nume,50);
            cin.get();
            cout<<"Varsta:";cin>>varsta;
            cin.get();
            cout<<"Functie:";cin.get(functie,70);
            cin.get();
            cout<<"Salariu:";cin>>salariu;
            cin.get();
            cout<<"Bonus:";cin>>bonus;
            cin.get();
            Salariu S;
            S.AtribuireDate(salariu,bonus);
            ConversieID(id,nr_angajati,NrCifre(nr_angajati));
            A[nr_angajati].AtribuireDatePersonale(id,nume,varsta,functie);  
            A[nr_angajati].AtribuireSalariu(S);
        }
        else if(x==2) {
            char id[10]="";
            bool gasit = 0;
            cout<<"ID-ul angajatului pe care vrei sa il stergi:";cin.get(id,10);
            cin.get();
            for(int i=1;i<=nr_angajati;i++)
                if(strcmp(id,A[i].Id())==0) {
                    cout<<"Angajatul "<<A[i].Nume()<<" a fost sters cu succes!"<<'\n';
                    for(int j=i;j<nr_angajati;j++)
                        A[j]=A[j+1];
                    nr_angajati--;
                    gasit = 1;
                    break;
                }
            if(gasit==0) cout<<"Angajatul nu a fost gasit!"<<'\n';

        }
        else if(x==3) {
            if(nr_angajati==0) cout<<"Niciun angajat gasit!"<<'\n';
            for(int i=1;i<=nr_angajati;i++)
                A[i].AfisareDate();
        }
        else if(x==4) {

        }
    }
    */
    /*
    A.AtribuireDatePersonale("c31","Marina Bai",30,"Primar");
    B.AtribuireDatePersonale("c32","Cristian Maciuca",40,"Programator");
    S1.AtribuireDate(500,200.50);
    A.AtribuireSalariu(S1);
    B.AtribuireSalariu(S1);
    A.AfisareDate();
    B.AfisareDate();
    R1.AdaugaRelatie(A,B);
    R1.Afisare();*/

}
