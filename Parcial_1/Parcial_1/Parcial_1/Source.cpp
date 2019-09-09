#include<string>
#include"Buffer_8b.h"
#include"Buffer_32b.h"


int main() {
	CBuffer *buf1 = NULL, *buf2 = NULL;
	int x, y, formato=FORMAT_RGBAF32;
	double data;
	std::string opcion = "";
	/*buf.init(5, 5);
	buf.printBuffer();
	std::cout << std::endl<<buf.get(2,1);
	std::cout << std::endl;

	buf.set(0, 0, 90);
	std::cout << std::endl<<buf.get(2,1);
	std::cout << std::endl;

	buf.printBuffer();
	std::cout << std::endl;
	system("pause");*/


	std::cout << "Introdusca las dimenciones de la matriz\nX:";
	while (opcion[0]=='\0')
	{
	std::getline(std::cin, opcion, '\n');
	}
	x = std::stoi(opcion);
	opcion = "\0";
	std::cout << "\nY:";
	while (opcion[0] == '\0')
	{
		std::getline(std::cin, opcion, '\n');
	}
	y = std::stoi(opcion);

	buf1 =new Buffer_8b();
	buf2 = new Buffer_32b();
	buf1->init(x, y, FORMAT_R8G8B8A8UN);
	buf2->init(8, 8, FORMAT_RGBAF32);

	while (opcion[0] != 'X') {
		system("cls");
		std::cout << "\nPara imprimir la matriz, introdusca 1.\nPara definir un valor en una cordenada intodusca 2.";
		std::cout << "\nPara obtener el valor de una cordenada en especifico introdusca  3.\nPara salir presione 4.\n";
		std::getline(std::cin, opcion, '\n');
		switch (opcion[0])
		{
		case '1':
			buf1->printBuffer();
			std::cout << std::endl;
			system("pause");
			break;
		case '2':
			std::cout << "Introdusca las cordenadas\nX:";
			std::getline(std::cin, opcion, '\n');
			x = std::stoi(opcion);
			std::cout << "\nY:";
			std::getline(std::cin, opcion, '\n');
			y = std::stoi(opcion);

			std::cout << "\nIntrodusca el valor:";
			std::getline(std::cin, opcion, '\n');
			data = std::stod(opcion);

			buf1->setData(x - 1, y - 1, data,1);
			std::cout << std::endl;
			system("pause");
			break;
		case '3':
			std::cout << "Introdusca las cordenadas\nX:";
			std::getline(std::cin, opcion, '\n');
			x = std::stoi(opcion);
			std::cout << "\nY:";
			std::getline(std::cin, opcion, '\n');
			y = std::stoi(opcion);
			std::cout << buf1->getD(x - 1, y - 1, 0);
			std::cout << std::endl;
			system("pause");
			break;
		case '4':
			opcion[0] = 'X';
			break;
		case'5':
			buf2->copy(buf1);
			buf2->printBuffer();
			system("pause");
		default:
			break;
		}
	}
	delete buf1;
	delete buf2;
	return 0;
}