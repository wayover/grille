//Kamil Wiœniewski


#include <iostream>
#include <string>
#include <vector>

class grille
{
private:
	int dlugosc;
	std::vector<std::vector<char> > tablica;
	std::vector<std::vector<char> > tablica2;
	std::vector<std::vector<char> > tymcz;
	std::vector<char> tab;



public:

	void setdlugosc(int dl);
	void dodaj(std::string tekst,int a);
	void dodaj2(std::string tekst,int a);
	void wyswietl();
	void obrot();

};


void grille::setdlugosc(int dl)
{
	dlugosc = dl;

	for (int j = 0; j < dl; j++)
	{
		tab.push_back('-');
	}

	for (int i = 0; i < dl; i++)
	{
		tymcz.push_back(tab);
	}
}


void grille::dodaj(std::string tekst,int a)
{
	tablica.push_back(tab);

	for (int i = 0; i < dlugosc; i++)
	{
	tablica[a][i] = tekst[i];
	}
}




void grille::dodaj2(std::string tekst,int a)
{
	tablica2.push_back(tab);

	for (int i = 0; i < dlugosc; i++)
	{
		tablica2[a][i] = tekst[i];
	}
}



void grille::wyswietl()
{
	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < dlugosc; i++)
		{
			for (int j = 0; j < dlugosc; j++)
			{
				if (tablica[i][j] == 'O')
				{
					std::cout << tablica2[i][j];
				}
			}

		}
		
		obrot();
	}
	std::cout << std::endl;
}


void grille::obrot() 
{
	tymcz = tablica;
	for (int i = 0; i < dlugosc; i++)
	{
	
		for (int j = 0; j < dlugosc; j++)
		{
			tablica[i][j] = tymcz[dlugosc-1-j][i];
		}
		
	}

}



int main()
{
		std::string tekst;
		int dlugosc = 0;
		grille gr;
		for (long i = 0; i < INFINITY; i++)
		{
			std::cin >> dlugosc;
			if (dlugosc == 0)
			{
				return 0;
			}

			gr.setdlugosc(dlugosc);

			for (int z = 0; z < dlugosc; z++)
			{
				std::cin >> tekst;
				gr.dodaj(tekst,z);
			}

			for (int x = 0; x < dlugosc; x++)
			{
				std::cin >> tekst;
				gr.dodaj2(tekst,x);
			}


			gr.wyswietl();
	}

		return 0;
}