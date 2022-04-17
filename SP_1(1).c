#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Facturi
{
    int factura; //numar factura
    char nume_client[30];
    char data[9];
    int suma; //suma de plata
    char produse[100];
} f[100];


void antet();
void meniu (int);
void cautare(), afisare(), plata();
void caut(int), afis(int), plat(int);
int n;
int main()
{
    FILE *fpoint;
    fpoint = fopen("facturi.txt", "r");
    char linie[200], *p;
    int i=1;
    while(!feof(fpoint))
    {
        fgets(linie,200,fpoint);
        p=strtok(linie," ");
        f[i].factura = atoi(p);
        fgets(linie,200,fpoint);
        //printf("%s\n", linie);
        p=strtok(linie,"\n");
        strcpy(f[i].nume_client,p);
        //printf("%s\n", f[i].nume_client);
        fgets(linie,200,fpoint);
        p=strtok(linie,"\n");
        strcpy(f[i].data,p);
        fgets(linie,200,fpoint);
        p=strtok(linie," ");
        f[i].suma = atoi(p);
        fgets(linie,200,fpoint);
        p=strtok(linie,"\n");
        strcpy(f[i].produse,p);
        i++;

    }

    fclose(fpoint);
    n=i-1;
    //for (i=1;i<=n;i++) printf("%d %s %s %d %s\n", f[i].factura, f[i].nume_client, f[i].data, f[i].suma, f[i].produse);
    //printf("%s\n", f[3].nume_client);

    int optiune;
    do
    {
        antet();
        printf("       Optiunea dorita este: ");
        scanf("%d",&optiune);
        printf("\n");
        meniu(optiune);
    }
    while(optiune>=1 && optiune<=5);

    return 0;
}


int i, nr_adaugat;

void antet()
{
    printf("                                   --------------------------------------------------------\n");
    printf("                                                         MENIU PRINCIPAL      \n"               );
    printf("                                   --------------------------------------------------------\n");
    printf("                                           Bine ati venit! Acesta este meniul principal! \n\n");
    printf("       Alegeti optiunea dorita astfel: \n");
    printf("               Pentru cautare factura - Apasati tasta 1\n");
    printf("               Pentru afisare factura - Apasati tasta 2\n");
    printf("               Pentru plata factura - Apasati tasta 3\n");
    printf("               Pentru adaugare factura - Apasati tasta 4\n");
    printf("               Pentru iesire din program - Apasati tasta 5\n");
}

void meniu(int optiune)
{
    if (optiune==1)
    {
        int id_cautare;
        do
        {
            cautare();
            scanf("%d", &id_cautare);
            //printf("%d", id_cautare);
            caut(id_cautare);
        }
        while (id_cautare < 1 || id_cautare > 2);
        return 0;
    }

    else if (optiune==2)
    {
        int id_afisare;
        do
        {
            afisare();
            scanf("%d", &id_afisare);
            afis(id_afisare);
        }
        while (id_afisare < 1 || id_afisare > 2);
        return 0;
    }

    else if (optiune==3)
    {
        int id_plata;
        do
        {
            plata();
            scanf("%d", &id_plata);
            plat(id_plata);
        }
        while (id_plata < 1 || id_plata > 2);
        return 0;
    }
    else if (optiune==4)
    {
        adaugare();
    }

    else if(optiune==5)
    {
        printf("Programul se va inchide la apasarea oricarei taste.\n");
        exit(0);
    }
    else {
        antet();
        printf("Alegeti o optiune corecta!\n"); }
}
void cautare()
{
    printf("Ati optat pentru cautarea unei facturi! \n\n");
    printf("               Alegeti una dintre optiuni, astfel: \n");
    printf("               Cautare factura dupa nume - Apasati tasta 1\n");
    printf("               Cautare factura dupa numar factura - Apasati tasta 2\n");
}
void afisare()
{
    printf("Ati optat pentru afisarea unor facturi! \n\n");
    printf("               Alegeti una dintre optiuni, astfel: \n");
    printf("               Afisare a tuturor facturilor existente - Apasati tasta 1\n");
    printf("               Afisare a facturilor neplatite integral - Apasati tasta 2\n");
}
void plata()
{
    printf("Ati optat pentru plata unei facturi! \n\n");
    printf("               Alegeti una dintre optiuni, astfel: \n");
    printf("               Pentru plata integrala - Apasati tasta 1\n");
    printf("               Pentru afisare chitante facturi platite - Apasati tasta 2\n");
}
void adaugare()
{

    printf("Introduceti numarul de facturi pe care doriti sa il adaugati: ");
    scanf("%d",&nr_adaugat);

    for(i=n+1; i<nr_adaugat+n+1; i++)
    {
        FILE * fpoint;
        fpoint = fopen("./facturi.txt", "a");

        printf("Introduceti numarul facturii: ");
        scanf("%d",&f[i].factura);
        printf("Introduceti numele clientului: ");
        getchar();
        scanf("%[^\n]",&f[i].nume_client);
        printf("Introduceti data emiterii: ");
        getchar();
        scanf("%[^\n]",&f[i].data);
        printf("Introduceti suma de plata: ");
        scanf("%d",&f[i].suma);
        printf("Introduceti produsele achizitionate: ");
        getchar();
        scanf("%[^\n]",&f[i].produse);

        if(fpoint==NULL) printf("Nu merge bos");
        else {
        fprintf(fpoint, "%d\n%s\n%s\n%d\n%s\n", f[i].factura, f[i].nume_client, f[i].data, f[i].suma, f[i].produse);
        fclose(fpoint);}

        printf("\nAti introdus factura: nr. %d, emisa clientului %s, in data de %s, in valoare de %d lei, \ncu urmatoarele achizitii: %s \n\n",
               f[i].factura,f[i].nume_client,f[i].data,f[i].suma,f[i].produse);
    }
    n=n+nr_adaugat;
}
void caut(id_cautare)
{
    if (id_cautare == 1)
    {
        char nume[30];
        int ok=0;
        printf("Completati cu numele facturii cautate: ");
        scanf("%s", nume);
        for (int i=1; i<=n; i++)
        {
           if (strcmp(f[i].nume_client,nume)==0)
            {
                printf("Factura cautata este urmatoarea: \n");
                printf("Factura cu numarul: %d\n",f[i].factura);
                printf("Emisa in data de: %s \n",f[i].data);
                printf("In valoare de %d lei\n",f[i].suma);
                printf("Cu urmatoarele achizitii: %s\n",f[i].produse);
                ok=1;
            }
        }

        if (ok==0) printf("Factura dorita nu a fost gasita.\n");}
        /*int ok=0,i;
        for (i=0; i<nr_adaugat; i++)
        {
            if (strcmp(f[i].nume_client,n)==0)
            {
                printf("Factura cautata este urmatoarea: \n");
                printf("Factura cu numarul: %d\n",f[i].factura);
                printf("Emisa in data de: %s \n",f[i].data);
                printf("In valoare de %d lei\n",f[i].suma);
                printf("Cu urmatoarele achizitii: %s\n",f[i].produse);
                ok=1;
            }
        }
        if (ok==0)
        {/
            printf("Nu exista facturi inregistrate pe acest nume.\n");
        }*/


    else if (id_cautare == 2)
    {
        int nr;
        printf("Completati cu numarul facturii cautate: ");
        scanf("%d",&nr);
        printf("\n");
        int i;

            if (nr<=n)
            {
                printf("Factura cautata este urmatoarea: \n");
                printf("Factura cu numarul: %d\n",f[nr].factura);
                printf("Clientului: %s\n", f[nr].nume_client);
                printf("Emisa in data de: %s \n",f[nr].data);
                printf("In valoare de %d lei\n",f[nr].suma);
                printf("Cu urmatoarele achizitii: %s\n",f[nr].produse);
            }

            else printf("Factura cautata nu este inregsitrata in sistem.\n");
    }
}
void afis(id_afisare)
{
    if (id_afisare == 1)
    {
        int i;
        FILE *fpoint;
        fpoint=fopen("facturi.txt", "r");
        char c = fgetc(fpoint);
        while (c != EOF)
        {
            printf ("%c", c);
            c = fgetc(fpoint);
        }

        fclose(fpoint);


        /*for(i=0; i<nr_adaugat; i++)
        {
           fscanf(fpoint,"%d",f[i].factura);
           fscanf(fpoint,"%s",f[i].nume_client);
           fscanf(fpoint,"%d",f[i].data);
           fscanf(fpoint,"%d",f[i].suma);
           fscanf(fpoint,"%s",f[i].produse);
           f[i].factura = i+1;


            printf("Inregistrate sunt urmatoarele facturi: ",i);
            fprintf("%d\n",f[i].factura);
            fgets(f[i].nume_client, 30, stdin);
            printf("%s\n",f[i].nume_client);
            printf("%d\n",f[i].data);
            printf("%d\n",f[i].suma);
            printf("%s\n",f[i].produse);
            printf("-------------------------------------\n");*/
        }


    else if (id_afisare == 2)
    {
        int i,ok=0;
        for (i=1;i<=n;i++)
        {
            if (f[i].suma!=0)
            {
                printf("%d %s %s %d %s\n", f[i].factura, f[i].nume_client, f[i].data, f[i].suma, f[i].produse);
                ok=1;
            }
        }
        if (ok==0) printf("Toate facturile au fost achitate.");
    }
}
void plat(id_plata)
{
    if (id_plata == 1)
    {
        int fact_plata;
        printf("Ati ales plata integrala a unei facturi.\n Introduceti numarul facturii pe care intentionati sa o platiti: ");
        scanf("%d", &fact_plata);
            f[fact_plata].suma = 0;
            FILE *fpoint;
            fpoint = fopen("facturi.txt", "w");
            for (int i=1;i<=n;i++)
                {
                    if (i==1)
                    fprintf(fpoint,"%d\n%s\n%s\n%d\n%s", f[i].factura, f[i].nume_client, f[i].data,f[i].suma,f[i].produse);
                    else
                    fprintf(fpoint,"\n%d\n%s\n%s\n%d\n%s", f[i].factura, f[i].nume_client, f[i].data,f[i].suma,f[i].produse);
                }
            fclose(fpoint);
            printf("Factura a fost achitata cu succes.\n");

            FILE *filep;
            filep = fopen("chitante.txt", "w");
            fprintf(filep, "CHITANTE FACTURI PLATITE\n");
            fprintf(filep,"Chitanta aceasta atesta plata facturii cu urmatoarele date:\n Nr:%d Client:%s Data:%s Produse:%s\n\n",
                    f[fact_plata].factura, f[fact_plata].nume_client, f[fact_plata].data,f[fact_plata].produse);

            fclose(filep);

            /*if (fact_plata = f[i].factura) {
                printf("%d\n", f[i].suma);
                f[i].suma = 0;
                printf("%d\n", f[i].suma);
                printf("Factura a fost platita.");
                ok=1;
            }
            if (ok=0) printf("Factura nu a fost gasita.");*/
        }


    else if (id_plata == 2)
    {
        //printf("Plata facturilor in rate este disponibila momentan doar clientilor premium, \nva fi curand disponibila tuturor utilizatorilor.\n Multumim pentru intelegere!\n");
        printf("In sistem sunt inregistrate urmatoarele chitante: \n");
        int i;
        FILE *pointer;
        pointer=fopen("chitante.txt", "r");
        char c = fgetc(pointer);
        while (c != EOF)
        {
            printf ("%c", c);
            c = fgetc(pointer);
        }

        fclose(pointer);


    }
}
