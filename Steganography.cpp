#include "Steganography.h"
#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <codecvt>

int Steganography::extraction(string container) {
    
    file_container = container;
    setlocale(LC_ALL, "ru");
    string str;
    string s = "";
    string file;
    
    ifstream fin(file_container);
    
       if (!fin.good())
        {
            cout << "Ошибка открытия файла" << endl;
            exit(1);
            }

    while (!fin.eof())
        {
            str = "";
            getline(fin, str);
            s.append(str + "\n");
            }
    
    fin.close();
    
    locale loc("ru_RU.UTF-8");
    wstring_convert < codecvt_utf8<wchar_t>, wchar_t> codec;
    wstring ws = codec.from_bytes(s);
    
    int t = 0;
    int i = 0;
    
    ws.c_str();
    
    
    while(ws[i] != 0)
    {
        if (ws[i] == 32)
        {
            if (ws[i+1] == 32)
            {
                t++;
                i=i+2;
                }
            else
            {
                t++;
                i=i+1;
                }
            }
        
        else
        {
            i++;
            }
        }
    
    int32_t *m = new int32_t [t+1];
    
    i = 0;
    
    int n = 0;
    
    while(ws[i] != 0)
    {
        if (ws[i] == 32)
        {
            if (ws[i+1] == 32)
            {
                m[n] = 1;
                n++;
                i=i+2;
                }
            else
            {
                m[n] = 0;
                n++;
                i=i+1;
                }
            }
        
        else
        {
            i++;
            }
        }

    
    int w;
    i = 0;
    int counter;
    int k = 0;
    int l = 0;
    
    while (k <= t)
    {
        counter = 0;
        w = 0;
        
        while (w < 16)
        {
            if (m[i] == 0)
            {
                counter++;
                }
            w++;
            i++;
            }
        l++;
        
        if (counter == 16)
        {
            break;
            }
            
        k += 16; 
        }

        if (counter != 16)
        {
            cout << "Не возможно извлечь сообщение!" << endl;
            return 1;
            }
        
        wchar_t p[l] = {0};
        k = 0;
        int32_t c;
        i = 15;
        
    i = 0;
    int b = 15;
    int a;
    
    while(i < l)
    {
        w = 0;
        p[i] = 0;
        c = 1;
        while (w < 16)
        {
            p[i] = p[i] + m[b]*c;
            c = c*2;
            b = b - 1;
            w++;
            }
        b = b + 32;
        i++;
        }
        
        delete[] m;
        
        wstring wstg = wstring(p);
        string stg = codec.to_bytes(wstg);
        
        file_new = file_container; 
        file_new.erase(file_new.rfind('/') + 1, file_new.length());
        file_new.append("NewFile.txt");
        
        ofstream fout;
        fout.open(file_new);
        fout << stg ;
        fout.close();
        
        cout << "Путь к новому файлу: "<< file_new << endl;
    return 0;
    }
int Steganography::concealment(string container, string message) {
    
    file_container= container;
    file_message = message;
    
    string st;
    string sp = "";
    string strm;
    string sm = "";
    
    ifstream fin;
    fin.open(file_container);
    
       if (!fin.good())
        {
            cout << "Ошибка открытия файла" << endl;
            exit(1);
            }

    while (!fin.eof())
        {
            st = "";
            getline(fin, st);
            sp.append(st + "\n");
            }
            
    fin.close();
    
    fin.open(file_message);
    
    if (!fin.good())
    {
        cout << "Ошибка открытия файла" << endl;
        exit(1);
        }

    while (!fin.eof())
    {
        strm = "";
        getline(fin, strm);
        sm.append(strm + "\n");
        }
    
    fin.close();
    
    locale loc("ru_RU.UTF-8");
    wstring_convert < codecvt_utf8<wchar_t>, wchar_t> codec;
    wstring wsp = codec.from_bytes(sp);
    wstring wsm = codec.from_bytes(sm);
    
    wsm.erase(wsm.length()-2,wsm.length()-1);
    wsp.erase(wsp.length()-2,wsp.length()-1);
    
    wsm.c_str();
    
    int t = 0, i = 0;
    
    while(wsm[i] != 0)
    {
        t++;
        i++;
        }
        
    int32_t p[t+1];
    
    i = 0;
    
    while(i < t+1)
    {
        p[i] = wsm[i];
        i++;
        }
      
    int l = (t+1)*16;
    int32_t *m = new int32_t [l];
    
    i = 0;
    int b = 15;
    int a;
    
    while(b < l)
    {
        a = 0;
        while(a < 16)
        {
            m[b] = p[i] % 2;
            p[i] = p[i] / 2;
            b = b -1;
            a++;
            }
        b = b + 32;
        i++;
        }
    
    i = 0;
    int counter = 0;
    
    while (i < l)
    {
        if (m[i] == 1)
        {
            counter++;
            }
        i++;

        }
    
    wsp.c_str();
    
    i = 0;
    int u = 0;
    while(wsp[i] != 0)
    {
        if (wsp[i] == 32)
        {
            u++;
            }
        if((wsp[i] == 32) && (wsp[i+1] == 32))
        {
            cout << "Не возможно скрыть сообщение!" << endl;
            return 2;
            }
        i++;
        }
    if (l > u)
    {
        cout << "Не возможно скрыть сообщение!"<< endl;
        return 1;
        }
        
    i = 0;
    t = 0;
    int h = 0;
    
    int len = l + wsp.length();
    
    wchar_t wcht[len];
    
    while(i < len)
    {
        wcht[i] = wsp[h];
        
        if (wsp[h] == 32)
        {
            if (m[t] == 1)
            {
                wcht[i+1] = wsp[h];
                i++;
                }
            t++;
            }
        h++;
        i++;
        }
        
    delete[] m;   
    wstring wstg = wstring(wcht);
    string stg = codec.to_bytes(wstg);
    
    file_new = file_container; 
    file_new.erase(file_new.rfind('/') + 1, file_new.length());
    file_new.append("NewFile.txt");
        
    ofstream fout;
    fout.open(file_new);
    fout << stg ;
    fout.close();
        
    cout << "Путь к новому файлу: "<< file_new << endl;
        
    return 0;
    
    }


