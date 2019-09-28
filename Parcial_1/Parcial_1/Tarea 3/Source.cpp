#include<string>
#include"Buffer_8b.h"
#include"Buffer_32b.h"


void formatBuffer(CBuffer*&renacido) {
	int x, y, formato;
	std::string opcion;
	std::cout << "Si las dimenciones son menores a 1 en cualquiera de los casos se creara una matriz 4x4, si no se le da un formato valido sera R8G8B8AUN";
	std::cout << "\nIntrodusca las dimenciones de la matriz\nX:";
	while (opcion[0] == '\0')
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

	std::cout << "Introdusca el tipo de formato introduce ";
	std::cout << "\nFORMAT_R8G8B8A8UN = 0";
	std::cout << "\nFORMAT_R8G8B8 = 1";
	std::cout << "\nnFORMAT_R8G8 = 2";
	std::cout << "\nFORMAT_R8 = 3";
	std::cout << "\nFORMAT_RGBAF32 = 4";
	std::cout << "\nFORMAT_RGBF32 = 5";
	std::cout << "\nFORMAT_RGF32 = 6";
	std::cout << "\nFORMAT_RF32 = 7 \nFormato: ";

	opcion = "\0";
	while (opcion[0] == '\0')
	{
		std::getline(std::cin, opcion, '\n');
	}

	switch (opcion[0])
	{
	case '0':
		renacido = new Buffer_8b();
		if (renacido->init(x, y, FORMAT_R8G8B8A8UN)) {}
		else {
			renacido->init(4, 4, FORMAT_R8G8B8A8UN);
		}
		break;
	case '1':
		renacido = new Buffer_8b();
		if(renacido->init(x, y, FORMAT_R8G8B8)){}
		else {
			renacido->init(4, 4, FORMAT_R8G8B8);
		}
		break;
	case '2':
		renacido = new Buffer_8b();
		if (renacido->init(x, y, FORMAT_R8G8)) {}
		else {
			renacido->init(4, 4, FORMAT_R8G8);
		}
		break;
	case '3':
		renacido = new Buffer_8b();
		if(renacido->init(x, y, FORMAT_R8)){}
		else {
			renacido->init(4, 4, FORMAT_R8);
		}
		break;
	case'4':
		renacido = new Buffer_32b();
		if (renacido->init(x, y, FORMAT_RGBAF32)) {}
		else {
			renacido->init(4, 4, FORMAT_RGBAF32);
		}
		break;
	case'5':
		renacido = new Buffer_32b();
		if (renacido->init(x, y, FORMAT_RGBF32)) {}
		else {
			renacido->init(4, 4, FORMAT_RGBF32);
		}
		break;
	case'6':
		renacido = new Buffer_32b();
		if (renacido->init(x, y, FORMAT_RGF32)) {}
		else {
			renacido->init(4, 4, FORMAT_RGF32);
		}
		break;
	case'7':
		renacido = new Buffer_32b();
		if (!renacido->init(x, y, FORMAT_RF32)) {
			renacido->init(4, 4, FORMAT_RF32);
		}
		break;
	default:
		renacido = new Buffer_8b();
		renacido->init(4, 4, 0);
		break;
	}
}
void  deleteBuffer(CBuffer *&victima) {
	delete victima;
	formatBuffer(victima);
}

int main() {
	CBuffer *buf1 = NULL, *buf2 = NULL;
	int x, y, x2, y2;
	double data;
	bool currentBuf = true;
	std::string opcion = "";

	std::cout << "De formato al Buffer 1\n";	
	formatBuffer(buf1);
	system("cls");
	std::cout << "De formato al Buffer 2\n";	
	formatBuffer(buf2);

	while (opcion[0] != 'X') {
		system("cls");
		if (currentBuf) { std::cout << " [BUFFER 1 ACTIVO]"; }
		else {
			std::cout <<" [BUFFER 2 ACTIVO]";
		}
		std::cout << "\nPara imprimir la matriz, introdusca 1.\nPara definir un valor en una cordenada intodusca 2.";
		std::cout << "\nPara obtener el valor de una cordenada en especifico introdusca  3.\nPara salir presione 4.";
		std::cout << "\nPara hace una copia de buffer activo a buffer pasivo introdusca 5.\nPara dibujar una linea de un punto a otro introdusca 6.";
		std::cout << "\nPara cambiar el buffer activo a pasivo y viseversa presione 7";
		std::cout << "\nPara reformatear el buffer presione 8";
		std::cout << "\nPara dibujar un circulo en el buffer presione 9";
		std::cout << "\nOpcion: ";

		std::getline(std::cin, opcion, '\n');
		switch (opcion[0])
		{
		case '1':
			if (currentBuf) {
				buf1->printBuffer();
			}
			else {
				buf2->printBuffer();
			}
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
			if (currentBuf) {
				buf1->setData(x - 1, y - 1, data, 1);
			}
			else {
				buf2->setData(x - 1, y - 1, data, 1);
			}
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
			if (currentBuf) {
				std::cout << buf1->getD(x - 1, y - 1, 0);
			}
			else {
				std::cout << buf1->getD(x - 1, y - 1, 0);
			}
			std::cout << std::endl;
			system("pause");
			break;
		case '4':
			opcion[0] = 'X';
			delete buf1;
			delete buf2;
			break;
		case'5':
			if (currentBuf) {
				buf2->copy(buf1);
				buf2->printBuffer();
			}
			else
			{
				buf2->copy(buf1);
				buf2->printBuffer();
			}
			system("pause");
			break;
		case '6':
			std::cout << "Introdusca las cordenadas\nX1:";
			std::getline(std::cin, opcion, '\n');
			x = std::stoi(opcion);
			std::cout << "\nY1:";
			std::getline(std::cin, opcion, '\n');
			y = std::stoi(opcion);
			std::cout << "Introdusca las cordenadas\nX2:";
			std::getline(std::cin, opcion, '\n');
			x2 = std::stoi(opcion);
			std::cout << "\nY2:";
			std::getline(std::cin, opcion, '\n');
			y2 = std::stoi(opcion);
			if (currentBuf) {
				buf1->clearBuffer();
				buf1->line(--x, --y, x2, y2);
				buf2->linea(x, y, x2, y2);
				buf1->printBuffer();
				buf2->printBuffer();
			}
			else {
				buf2->clearBuffer();
				buf2->line(--x, --y, x2, y2);
				buf1->linea(x, y, x2, y2);
				buf2->printBuffer();
				buf1->printBuffer();
			}
			system("pause");
			break;
		case'7':
			if (currentBuf) { currentBuf = false; }
			else { currentBuf = true; }
			break;
		case'8':
			if (currentBuf) { deleteBuffer(buf1); }
			else { deleteBuffer(buf2); }
		case'9':
			std::cout << "Introdusca las cordenadas\nX:";
			std::getline(std::cin, opcion, '\n');
			x = std::stoi(opcion);
			std::cout << "\nY:";
			std::getline(std::cin, opcion, '\n');
			y = std::stoi(opcion);

			std::cout << "\nIntrodusca el radio:";
			std::getline(std::cin, opcion, '\n');
			x2 = std::stoi(opcion);

			if (currentBuf) {
				buf1->circle(x, y,x2); 
				buf1->printBuffer();
			}
			else {
				buf2->circle(x, y, x2);
				buf2->printBuffer();
			}
			system("pause");
		default:
			break;
		}
	}
	return 0;
}