#include<string>
#include"Buffer.h"


int main() {
	Buffer<int> buf;
	int x, y;
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
	std::getline(std::cin, opcion, '\n');
	x = std::stoi(opcion);
	std::cout << "\nY:";
	std::getline(std::cin, opcion, '\n');
	y = std::stoi(opcion);

	buf.init(x, y);
	while (opcion[0] != 'X') {
		system("cls");
		std::cout << "\nPara imprimir la matriz, introdusca 1.\nPara definir un valor en una cordenada intodusca 2.";
		std::cout << "\nPara obtener el valor de una cordenada en especifico introdusca  3.\nPara salir presione 4.\n";
		std::getline(std::cin, opcion, '\n');
		switch (opcion[0])
		{
		case '1':
			buf.printBuffer();
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

			buf.set(x - 1, y - 1, std::stoi(opcion));
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

			std::cout << buf.get(x - 1, y - 1);
			std::cout << std::endl;
			system("pause");
			break;
		case '4':
			opcion[0] = 'X';
			break;
		default:
			break;
		}
	}
	return 0;
}