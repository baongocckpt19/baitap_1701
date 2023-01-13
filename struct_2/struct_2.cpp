#include<iostream>
using namespace std;

int n, m;

int main()
{
    
    cout << "Nhap so sinh vien: ";
    cin >> n;
    cout << "Nhap so mon hoc: ";
    cin >> m;
    
    
	struct baongoccute{
		string HT;
		float *diem = new float[m];
		float DTB;
		int HL, HB;
	} sv[n];
	
    int i, j;
    for(i = 1; i <= n; i++)
    {
        cin.ignore();
        cout << "Ho va ten:";
        getline(cin, sv[i].HT);
        
        cout << "Diem so cac mon lan luot la: ";
        for (j = 1; j <= m; j++) {
            cin >> sv[i].diem[j];
        }
    }
     

  
	for (i = 1; i <= n; i++)
    {
    	sv[i].HL = 0;
        for (j = 1; j <= m; j++)
        {
            if(sv[i].diem[j] < 4)
            {
                sv[i].HL++;
            }
        }
    }
        
    for (i = 1; i <= n; i++)
    { 
        sv[i].DTB = 0;
        for (j = 1; j <= m; j++)
        {
            sv[i].DTB = sv[i].DTB + sv[i].diem[j];
        }
        sv[i].DTB = sv[i].DTB / m;
    }


    for (i = 1; i <= n; i++)
    {
    	sv[i].HB = 0;
        if (sv[i].HL == 0)
        {
            if (sv[i].DTB > 9)
            {
                sv[i].HB = 1;
            } else if (sv[i].DTB > 8)
            {
                sv[i].HB = 2;
            } else if (sv[i].DTB > 7)
            {
                sv[i].HB = 3;
            } else sv[i].HB = 0;
        }
    }

		
    for (i = 1; i <= n; i++)
    {
        if (sv[i].HB > 0)
        {
            cout << "Sinh vien " << sv[i].HT;
            cout << " dat hoc bong loai " << sv[i].HB << endl;
        }
    }
    
    for (auto &x : sv)
        delete []x.diem;
    return 0;
}
