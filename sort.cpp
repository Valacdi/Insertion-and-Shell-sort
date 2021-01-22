#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

void ShellSort(vector<int>& A, long long& pakeitimai, long long& lyginimai);
void InsertionSort(vector<int>& A, long long& pakeitimai, long long& lyginimai);
void generuoti(int size, vector<int>& skaiciai);
void insertion_sort_laikas(long long& pakeitimai, vector<int>& A, long long& lyginimai);
void shell_sort_laikas(long long& pakeitimai, vector<int>& A, long long& lyginimai);
void Kopijuoti(vector<int>& A, vector<int>& B);
void RezIFaila(vector<int>& A);

int main()
{
    vector<int> skaiciai, skaiciai2;
    long long pakeitimai1 = 0, pakeitimai2 = 0, lyginimai1 = 0, lyginimai2 = 0;
    int dydis = 0, pasirinkimas = 0, pasirinkimas3 = 0, klausimas = 0;

    cout << "Shell sort ir Insertion sort tyrimas\n";
    do{
        cout << "\n================================================\n";
        cout << "Pasirinkite atveji: \n";
        cout << "1. Sugeneruoti skaicius\n";
        cout << "2. Blogiausias atvejis\n";
        cout << "3. Vidutinis atvejis\n";
        cout << "4. Geriausias atvejis\n";
        cout << "5. Baigti programa.\n";
        cout << "================================================\n";
        cout << "Pasirinkite: ";
        cin >> pasirinkimas;

        switch (pasirinkimas)
        {
        case 1: ///generuoti skaicius
            cout << "Iveskite masyvo dydi: ";
            cin >> dydis;
            generuoti(dydis, skaiciai);
            Kopijuoti(skaiciai, skaiciai2);
            cout << "Sugeneruota!\n";
            break;

        case 2:///kai surusiuota atvirksciai
            if (skaiciai.empty() && skaiciai2.empty())
            {
                cout << "Tuscias masyvas!!!!\n";
                break;
            }
            else
            {
                sort(skaiciai.begin(), skaiciai.end(), greater<int>()); ///rusiuojama atvirksciai
                sort(skaiciai2.begin(), skaiciai2.end(), greater<int>());
                shell_sort_laikas(pakeitimai1, skaiciai, lyginimai1);
                cout << "Lyginimai: " << lyginimai1 << endl;
                cout << "Keitimai: " << pakeitimai1 << endl << endl;
                RezIFaila(skaiciai);
                insertion_sort_laikas(pakeitimai2, skaiciai2, lyginimai2);
                cout << "Lyginimai: " << lyginimai2 << endl;
                cout << "Keitimai: " << pakeitimai2 << endl << endl;
                cout << "Ar norite matyti rezultata konsoleje? 1. NE 2. TAIP\n";
                cout << "Pasirinkite: ";
                cin >> klausimas;
                cout << endl;
                if (klausimas == 1)
                    pasirinkimas = 5;
                else ///matyti konsoleje rezultata
                {
                    cout << "Rezultatas shell masyvo: ";
                    for (int i = 0;i<skaiciai.size();i++)
                        cout << skaiciai[i] << " ";
                    cout << endl << endl;
                    cout << "Rezultatas insertion masyvo: ";
                    for (int i = 0;i<skaiciai2.size();i++)
                        cout << skaiciai2[i] << " ";
                    cout << endl << endl;
                    pasirinkimas = 5;
                }
            }
            break;
        case 3:///atsitiktiniai duomenys
            if (skaiciai.empty() && skaiciai2.empty())
            {
                cout << "Tuscias masyvas!!!!\n";
                break;
            }
            shell_sort_laikas(pakeitimai1, skaiciai, lyginimai1);
            cout << "Lyginimai: " << lyginimai1 << endl;
            cout << "Keitimai: " << pakeitimai1 << endl << endl;
            RezIFaila(skaiciai);
            insertion_sort_laikas(pakeitimai2, skaiciai2, lyginimai2);
            cout << "Lyginimai: " << lyginimai2 << endl;
            cout << "Keitimai: " << pakeitimai2 << endl << endl;
            cout << "Ar norite matyti rezultata konsoleje? 1. NE 2. TAIP\n";
            cout << "Pasirinkite: ";
            cin >> klausimas;
            cout << endl;
            if (klausimas == 1)
                pasirinkimas = 5;
            else ///matyti konsoleje rezultata
            {
                cout << "Rezultatas shell masyvo: ";
                for (int i = 0;i<skaiciai.size();i++)
                    cout << skaiciai[i] << " ";
                cout << endl << endl;
                cout << "Rezultatas insertion masyvo: ";
                for (int i = 0;i<skaiciai2.size();i++)
                    cout << skaiciai2[i] << " ";
                cout << endl << endl;
                pasirinkimas = 5;
            }
            break;

        case 4: ///kai vienas nesurusiuotas
            if (skaiciai.empty() && skaiciai2.empty())
            {
                cout << "Tuscias masyvas!!!!\n";
                break;
            }
            else
            {
                sort(skaiciai.begin(), skaiciai.end());
                skaiciai2.clear(); ///pravalome tam kad galetumeme kopijuoti aibe su swap
                swap(skaiciai[skaiciai.size()-1], skaiciai[skaiciai.size()-2]); ///apkeiciamas priespaskutinis skaicius su paskutiniu
                Kopijuoti(skaiciai, skaiciai2);
                shell_sort_laikas(pakeitimai1, skaiciai, lyginimai1);
                cout << "Lyginimai: " << lyginimai1 << endl;
                cout << "Keitimai: " << pakeitimai1 << endl << endl;
                RezIFaila(skaiciai);
                insertion_sort_laikas(pakeitimai2, skaiciai2, lyginimai2);
                cout << "Lyginimai: " << lyginimai2 << endl;
                cout << "Keitimai: " << pakeitimai2 << endl << endl;
                cout << "Ar norite matyti rezultata konsoleje? 1. NE 2. TAIP\n";
                cout << "Pasirinkite: ";
                cin >> klausimas;
                cout << endl;
                if (klausimas == 1)
                    pasirinkimas = 5;
                else ///matyti konsoleje rezultata
                {
                    cout << "Rezultatas shell masyvo: ";
                    for (int i = 0;i<skaiciai.size();i++)
                        cout << skaiciai[i] << " ";
                    cout << endl << endl;
                    cout << "Rezultatas insertion masyvo: ";
                    for (int i = 0;i<skaiciai2.size();i++)
                        cout << skaiciai2[i] << " ";
                    cout << endl << endl;
                    pasirinkimas = 5;
                }
            }
            break;
        case 5:
            break;
        default:
            cout << "Blogas pasirinkimas!!!\n";
        }
    } while (pasirinkimas != 5);

    skaiciai.clear();
    return 0;
}

void RezIFaila(vector<int>& A) ///rodo TIK SHELLO rezultata
{
    ofstream fr ("rezshell.txt");
    for (int i = 0;i<A.size();i++)
    {
        fr << A[i] << " ";
    }
    fr.close();
}

void Kopijuoti(vector<int>& A, vector<int>& B) ///perkeliame reiksmes is vektoriaus A i B
{
    for (int i = 0;i<A.size();i++)
    {
        B.push_back(A[i]);
    }
}

void shell_sort_laikas(long long& pakeitimai, vector<int>& A, long long& lyginimai)
{
	auto start = high_resolution_clock::now();
	ShellSort(A, pakeitimai, lyginimai);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Shell funkcijai praejo laiko: " << duration.count() / 1000000. << " sekundes " << endl;
}

void insertion_sort_laikas(long long& pakeitimai, vector<int>& A, long long& lyginimai)
{
	auto start = high_resolution_clock::now();
	InsertionSort(A, pakeitimai, lyginimai);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Insertion funkcijai praejo laiko: " << duration.count() / 1000000. << " sekundes " << endl;
}

void generuoti(int size, vector<int>& numbers)
 {
	ofstream fr("duom.txt");
	unsigned int seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine engine(seed); //varikliukas
    std::uniform_int_distribution<int> distr(1000, 9999); //reikšmių rėžis
	for (int i = 0; i < size; i++)
	{
	    int a = distr(engine);
		fr << a << " "; ///parodo faile ka sugeneravo
		numbers.push_back(a);
	}
}

void ShellSort(vector<int>& A, long long& pakeitimai, long long& lyginimai)
{
	for (int gap = A.size()/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < A.size(); i += 1)
        {
            int temp = A[i];
            int j = i;
            while(j >= gap)
            {
                lyginimai++;
                if(A[j - gap] > temp)
                {
                    pakeitimai++;
                    A[j] = A[j - gap];
                    j -= gap;
                }
                else
                {
                    break;
                }
            }
            A[j] = temp;
        }
    }
}
void InsertionSort(vector<int>& A, long long& pakeitimai, long long& lyginimai)
{
    int key, temp;
    for (int i = 0; i < A.size(); i++)
    {
        key = A[i];
        temp = i;
        while (temp > 0)
        {
            lyginimai++;
            if (A[temp - 1] > key)
            {
                pakeitimai++;
                A[temp] = A[temp - 1];
                temp--;
            }
            else
            {
                break;
            }
        }
        A[temp] = key;
    }
}
