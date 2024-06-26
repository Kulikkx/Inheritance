#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<ctime>

using std::cin;
using std::cout;
using std::endl;
//#define WRITE_TO_FILE
#define READ_FROM_FILE
void main()
{
	setlocale(LC_ALL, "");
	
#ifdef WRITE_TO_FILE
	std::ofstream fout;			//создаем поток
	fout.open("File.txt", std::ios_base::app);		//Открываем поток
	//std::ios_base::app - append (дописать в конец файла)
//fout << "Helloworld" << endl; //Пишем в поток
fout << "Сам привет!" << endl;
	time_t now = time(NULL);
	fout << ctime(&now) << endl;

	fout.close();					//Закрываем поток
	//Потоки как холодос,если открыты, их нужно закрыть!

	system("notepad File.txt");
#endif // WRITE_TO_FILE

#ifdef READ_FROM_FILE
	std::ifstream fin("File.txt");
	if (fin.is_open())
	{
		//здесь будет читать файл
		const int SIZE = 256; //размер буфера
		char buffer[SIZE]{}; //буфер

		while (!fin.eof()) //NOT EndOffile
		{
			//fin >> buffer;
			fin.getline(buffer, SIZE); //читает строку с пробелами
			cout << buffer << endl;
		}
		fin.close();

	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
#endif // READ_FROM_FILE

}