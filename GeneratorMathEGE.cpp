#include <iostream>                                             // Для операторов cin и cout
#include <ctime>                                                // Для функции srand() которая помогает делать реальный рандомайзер
#include <cmath>                                                // Для математических операторов
#include <string>
#include <iomanip>                                              // Чтобы небыло лишних нулей вконце ***
#include <sstream>                                              // Чтобы небыло лишних нулей вконце ***
using namespace std;

int main_menu()                                                 // Функция которая выводит главное меню
{
    int choice_mm;
    cout << "\033[2J\033[1;1H";
    cout << "\"Генератор заданий ЕГЭ: математика\"\n" << endl;
    cout << "Выберите действие:" << endl;
    cout << "1. Сгенерировать задания по темам" << endl;
    cout << "2. Сгенерировать целую первую часть" << endl;
    cout << "3. Сгенерировать вариант" << endl << endl;
    cout << "0. Выход" << endl << endl;
    cout << "Ваш выбор: ";
    cin >> choice_mm;
    return choice_mm;
}

string FormatDouble(double val, int maxPrecision = 10) // Чтобы небыло лишних нулей вконце ***
{      
    ostringstream out;
    out << fixed << setprecision(maxPrecision) << val;
    string s = out.str();
    s.erase(s.find_last_not_of('0') + 1);
    if (s.back() == '.') s.pop_back();
    return s;
}

const double PI = 3.14159265;

int NOD(int number1, int number2)                               // Ищет и возвращает НОД двух чисел
{
    int nod = 1;
    int count_del1, count_del2;
    count_del1 = count_del2 = 0;
    for (int i = 2; i <= number1; i++)                                // Считает количество делителей первого числа
    {
        if (number1 % i == 0)
            count_del1++;
    }

    for (int i = 2; i <= number2; i++)                                // Считает количество делителей второго числа
    {
        if (number2 % i == 0)
            count_del2++;
    }

    int count = 0;
    int del1[50], del2[50];                                           // Создаются массивы для делителей
    for (int i = 0; i < 50; i++)
        del1[i] = 1;
    for (int i = 0; i < 50; i++)
        del2[i] = 1;

    for (int i = 2; i <= number1; i++)                               // Заполняется массив делителей первого числа
    {
        if (number1 % i == 0)
        {
            del1[count] = i;
            count++;
        }
    }
    count = 0;
    for (int i = 2; i <= number2; i++)                               // Заполняется массив делителей второго числа
    {
        if (number2 % i == 0)
        {
            del2[count] = i;
            count++;
        }
    }

    for (int i = 0; i < count_del1; i++)                               // Ищет наибольший общий делитель
    {
        for (int n = 0; n < count_del2; n++)
        {
            if ((del1[i] == del2[n]) && (del1[i] > nod))
                nod = del1[i];
        }
    }
    return nod;
}

string SIGNUr(double number, int pos)                                   // Возвращает знак операции + или - для Latex (pos - позиция знака в выражении)
{
    string sgn;
    if ((number > 0) && (pos == 1))
        sgn = "";
    if ((number > 0) && (pos == 2))
        sgn = "+";
    if (number < 0)
        sgn = "-";
    return sgn;

}

string NumberCelUr(double number, int pos)
{
    string final;
    if ((fabs(number) == 1) && (pos == 1))
        final = "";
    if ((fabs(number) == 1) && (pos == 2))
        final = "1";
    if (fabs(number) != 1)
        final = to_string(static_cast<int>(fabs(number)));
    return final;
}

int ZnakKub(double number)
{
    int znak;
    if (number > 0)
        znak = 1;
    else
        znak = -1;

    return znak;
}

struct point
{
    double x;
    double y;
};

struct TrigFunction
{
    string name;
    double angel;
};

TrigFunction a[3];

double ZnakTrigonFunction(string name, double angle)
{
    double out;
    if (name == "sin")
    {
        if ((angle > 0) && (angle < 180))
            out = 1;
        if ((angle > 360) && (angle < 540))
            out = 1;
        if ((angle > 720) && (angle < 900))
            out = 1;
        if ((angle > 180) && (angle < 360))
            out = -1;
        if ((angle > 540) && (angle < 720))
            out = -1;
        if ((angle > 900) && (angle < 1080))
            out = -1;
    }
    if (name == "cos")
    {
        if ((angle > 0) && (angle < 90))
            out = 1;
        if ((angle > 270) && (angle < 450))
            out = 1;
        if ((angle > 630) && (angle < 810))
            out = 1;
        if ((angle > 90) && (angle < 270))
            out = -1;
        if ((angle > 450) && (angle < 630))
            out = -1;
        if ((angle > 810) && (angle < 1170))
            out = -1;
    }
    return out;
}

string StepKoren(int AllType)
{
    double osn[3], pok[6];
			string Answer;
			int check = 0;
			double answer;
			int type;
            if(AllType == 0)
                type = rand() % 10 + 1;
            else
                type = AllType;
			int type_1, del;
			switch (type)
			{
			case 1:
				do {
					for (int i = 0; i < 2; i++)
						osn[i] = rand() % 18 + 2;
					for (int i = 0; i < 3; i++)
						pok[i] = pow(-1, rand()) * (rand() % 98 + 1) / 10;
					answer = pow((osn[0] * osn[1]), pok[0]) * pow(osn[0], pok[1]) / pow(osn[1], pok[2]);
					check = 1;
					if (answer - static_cast<int>(answer) != 0)
						check = 0;
					if (answer > 1700)
						check = 0;
				} while (check != 1);
				if (pow(-1, rand()) > 0)
					cout << "\\item		Найдите значение выражения: $$\\frac{" << (osn[0] * osn[1]) << "^{" << pok[0] << "}\\cdot " << osn[0] << "^{" << pok[1] << "}}{" << osn[1] << "^{" << pok[2] << "}}$$" << endl;
				else
					cout << "\\item		Найдите значение выражения: $$\\frac{" << osn[0] << "^{" << pok[1] << "}\\cdot " << (osn[0] * osn[1]) << "^{" << pok[0] << "}}{" << osn[1] << "^{" << pok[2] << "}}$$" << endl;
				//cout << "\\\\" << answer << endl;
				Answer = "  \\item " + FormatDouble(answer) + " \n";
				break;

			case 2:
				do {
					osn[0] = rand() % 8 + 2;
					for (int i = 0; i < 6; i++)
					{
						pok[i] = rand() % 8 + 2;
					}
					answer = pow(pow(pow(osn[0], pok[0]), pok[1]), pok[2]) / pow(pow(pow(osn[0], pok[3]), pok[4]), pok[5]);
					check = 1;
					if (answer - static_cast<int>(answer) != 0)
						check = 0;
					if (answer > 1700)
						check = 0;
					if (pow(osn[0], pok[0]) > 100)
						check = 0;
					if (pow(osn[0], pok[3]) > 100)
						check = 0;
					if (answer == 1)
						check = 0;
				} while (check != 1);
				cout << "\\item		Найдите значение выражения: $\\left(" << pow(osn[0], pok[0]) << "^{" << pok[1] << "}\\right)^{" << pok[2] << "}:\\left(" << pow(osn[0], pok[3]) << "^{" << pok[4] << "}\\right)^{" << pok[5] << "}$." << endl;
				//cout << "\\\\" << answer << endl;
				Answer = "  \\item " + FormatDouble(answer) + " \n";
				break;

			case 3:
				do {
					osn[0] = rand() % 8 + 2;
					pok[0] = rand() % 2 + 2;
					pok[1] = rand() % 99 + 1;
					pok[1] = pok[1] / 100;
					pok[2] = rand() % 99 + 1;
					pok[2] = pok[2] / 100;
					answer = pow(osn[0], pok[1]) * pow(pow(osn[0], pok[0]), pok[2]);
					check = 1;
					if (answer - static_cast<int>(answer) != 0)
						check = 0;
					if (answer == 1)
						check = 0;
				} while (check != 1);
				if (pow(-1, rand()) > 0)
					cout << "\\item		Найдите значение выражения: $" << osn[0] << "^{" << pok[1] << "}\\cdot " << pow(osn[0], pok[0]) << "^{" << pok[2] << "}$." << endl;
				else
					cout << "\\item		Найдите значение выражения: $" << pow(osn[0], pok[0]) << "^{" << pok[2] << "}\\cdot " << osn[0] << "^{" << pok[1] << "}$." << endl;
				//cout << "\\\\" << answer << endl;
				Answer = "  \\item " + FormatDouble(answer) + " \n";
				break;

			case 4:
				type_1 = rand() % 2 + 1;
				do {
					osn[0] = rand() % 9 + 1;
					pok[0] = rand() % 2 + 2;
					pok[1] = rand() % 99 + 1;
					pok[1] = pok[1] / 10;
					pok[2] = rand() % 99 + 1;
					pok[2] = pok[2] / 10;
					if (type_1 == 1)
						answer = pow(pow(osn[0],pok[0]), pok[1]) / pow(osn[0], pok[2]);
					if (type_1 == 2)
						answer = pow(osn[0], pok[2]) / pow(pow(osn[0],pok[0]), pok[1]);
					check = 1;
					if (answer - static_cast<int>(answer) != 0)
						check = 0;
					if (answer == 1)
						check = 0;
					if (answer > 1000)
						check = 0;
					if ((pok[1] - static_cast<int>(pok[1]) == 0) || (pok[2] - static_cast<int>(pok[2]) == 0))
						check = 0;
				} while (check != 1);
				if (type_1 == 1)
					cout << "\\item		Найдите значение выражения: $$\\frac{" << pow(osn[0], pok[0]) << "^{" << pok[1] << "}}{" << osn[0] << "^{" << pok[2] << "}}$$" << endl;
				else
					cout << "\\item		Найдите значение выраженияя: $$\\frac{" << osn[0] << "^{" << pok[2] << "}}{" << pow(osn[0],pok[0]) << "^{" << pok[1] << "}}$$" << endl;
				//cout << "\\\\" << answer << endl;
				Answer = "  \\item " + FormatDouble(answer) + " \n";
				break;

			case 5:
				type_1 = rand() % 2 + 1;
				do {
					osn[0] = rand() % 8 + 2;
					for (int i = 0; i < 3; i++)
						pok[i] = rand() % 90 + 3;
					if (type_1 == 1)
						answer = pow(pow(osn[0], pok[0]), pok[1]) / pow(osn[0], pok[2]);
					else
						answer = pow(osn[0], pok[2]) / pow(pow(osn[0], pok[0]), pok[1]);
					check = 1;
					if (answer - static_cast<int>(answer) != 0)
						check = 0;
					if (answer == 1)
						check = 0;
					if (answer > 1000)
						check = 0;
					if (answer == 0)
						check = 0;
				} while (check != 1);
				if (type_1 == 1)
					cout << "\\item		Найдите значение выражения: $$\\frac{\\left(" << osn[0] << "^{" << pok[0] << "}\\right)^{" << pok[1] << "}}{" << osn[0] << "^{" << pok[2] << "}}$$" << endl;
				else
					cout << "\\item		Найдите значение выражения: $$\\frac{" << osn[0] << "^{" << pok[2] << "}}{\\left(" << osn[0] << "^{" << pok[0] << "}\\right)^{" << pok[1] << "}}$$" << endl;
				//cout << "\\\\" << answer << endl;
				Answer = "  \\item " + FormatDouble(answer) + " \n";
				break;

			case 6:
				do {
					osn[0] = rand() % 8 + 2;
					for (int i = 0; i < 4; i++)
						pok[i] = rand() % 20 + 1;

					del = NOD(pok[0], pok[1]);
					pok[0] = pok[0] / del;
					pok[1] = pok[1] / del;

					del = NOD(pok[2], pok[3]);
					pok[2] = pok[2] / del;
					pok[3] = pok[3] / del;

					answer = pow(osn[0],(pok[0]/pok[1])) * pow(pow(osn[0],2), (pok[2] / pok[3]));

					check = 1;
					if (answer - static_cast<int>(answer) != 0)
						check = 0;
					if (answer > 800)
						check = 0;
					if (pok[0] > pok[1])
						check = 0;
					if (pok[2] > pok[3])
						check = 0;
					if ((pok[1] == 1) || (pok[3] == 1))
						check = 0;
				} while (check != 1);
				if (pow(-1, rand()) > 0)
					cout << "\\item		Найдите значение выражения: $$" << osn[0] << "^{\\frac{" << pok[0] << "}{" << pok[1] << "}}\\cdot " << pow(osn[0],2) << "^{\\frac{" << pok[2] << "}{" << pok[3] << "}}$$" << endl;
				else
					cout << "\\item		Найдите значение выражения: $$" << pow(osn[0],2) << "^{\\frac{" << pok[2] << "}{" << pok[3] << "}}\\cdot " << osn[0] << "^{\\frac{" << pok[0] << "}{" << pok[1] << "}}$$" << endl;
				//cout << "\\\\" << answer << endl;
				Answer = "  \\item " + FormatDouble(answer) + " \n";
				break;

			case 7:
				type_1 = rand() % 2 + 1;
				do {
					for (int i = 0; i < 3; i++)
						osn[i] = rand() % 40 + 2;
					if (type_1 == 1)
						answer = pow((osn[0] * sqrt(osn[1])), 2) / osn[2];
					else
						answer = osn[2] / pow((osn[0] * sqrt(osn[1])), 2);
					check = 1;
					if (answer - static_cast<int>(answer) != 0)
						check = 0;
					if (answer == 1)
						check = 0;
				} while (check != 1);
				if (type_1 == 1)
					cout << "\\item		Найдите значение выражения: $$\\frac{\\left(" << osn[0] << "\\sqrt{" << osn[1] << "}\\right)^2}{" << osn[2] << "}$$" << endl;
				else
					cout << "\\item		Найдите значение выражения: $$\\frac{" << osn[2] <<"}{\\left(" << osn[0] << "\\sqrt{" << osn[1] << "}\\right)^2}$$" << endl;
				//cout << "\\\\" << answer << endl;
				Answer = "  \\item " + FormatDouble(answer) + " \n";
				break;

			case 8:
				type_1 = rand() % 2 + 1;
				do {
					for (int i = 0; i < 3; i++)
						osn[i] = rand() % 120 + 2;
					if (type_1 == 1)
						answer = sqrt(osn[1] * osn[0]) - sqrt(osn[2] * osn[0]);
					else
						answer = sqrt(osn[1] * osn[0]) + sqrt(osn[2] * osn[0]);
					check = 1;
					if (answer - static_cast<int>(answer) != 0)
						check = 0;
					if (sqrt(osn[0]) - static_cast<int>(sqrt(osn[0])) == 0)
						check = 0;
					if (sqrt(osn[1]) - static_cast<int>(sqrt(osn[1])) == 0)
						check = 0;
					if (sqrt(osn[2]) - static_cast<int>(sqrt(osn[2])) == 0)
						check = 0;
					if (answer == 0)
						check = 0;
					if ((osn[0] == osn[1]) || (osn[0] == osn[2])||(osn[1]==osn[2]))
						check = 0;
				} while (check != 1);
				if (type_1 == 1)
					cout << "\\item		Найдите значение выражения: $\\left(\\sqrt{" << osn[1] << "}-\\sqrt{" << osn[2] << "}\\right)\\sqrt{" << osn[0] << "}$." << endl;
				else
					cout << "\\item		Найдите значение выражения: $\\left(\\sqrt{" << osn[1] << "}+\\sqrt{" << osn[2] << "}\\right)\\sqrt{" << osn[0] << "}$." << endl;
				//cout << "\\\\" << answer << endl;
				Answer = "  \\item " + FormatDouble(answer) + " \n";
				break;

			case 9:
				do {
					osn[0] = rand() % 98 + 2;
					for (int i = 0; i < 3; i++)
						pok[i] = rand() % 50 + 2;
					answer = pow(osn[0],(1/pok[0])) * pow(osn[0],(1/pok[1])) / pow(osn[0],(1/pok[2]));
					check = 1;
					if (answer - static_cast<int>(answer) != 0)
						check = 0;
					if ((answer == 0)||(answer==1))
						check = 0;
					if ((pok[0] == pok[1]) || (pok[0] == pok[2]) || (pok[1] == pok[2]))
						check = 0;
					if ((pow(osn[0], (1 / pok[0])) - static_cast<int>(pow(osn[0], (1 / pok[0]))) == 0) || (pow(osn[0], (1 / pok[1])) - static_cast<int>(pow(osn[0], (1 / pok[1]))) == 0) || (pow(osn[0], (1 / pok[2])) - static_cast<int>(pow(osn[0], (1 / pok[2]))) == 0))
						check = 0;
				} while (check != 1);
				cout << "\\item		Найдите значение выражения: $$\\frac{\\sqrt[" << pok[0] << "]{" << osn[0] << "}\\sqrt[" << pok[1] << "]{" << osn[0] << "}}{\\sqrt[" << pok[2] << "]{" << osn[0] << "}}$$" << endl;
				//cout << "\\\\" << answer << endl;
				Answer = "  \\item " + FormatDouble(answer) + " \n";
				break;

			case 10:
				do {
					for (int i = 0; i < 3; i++)
						osn[i] = rand() % 50 + 2;
					pok[0] = rand() % 8 + 2;
					answer = pow(osn[0],(1/pok[0])) * pow(osn[1],(1/pok[0])) / pow(osn[2],(1/pok[0]));
					check = 1;
					if (answer - static_cast<int>(answer) != 0)
						check = 0;
					if ((answer == 0) || (answer == 1))
						check = 0;
					if ((osn[0] == osn[1]) || (osn[0] == osn[2]) || (osn[1] == osn[2]))
						check = 0;
					if ((pow(osn[0], (1 / pok[0])) - static_cast<int>(pow(osn[0], (1 / pok[0]))) == 0) || (pow(osn[1], (1 / pok[0])) - static_cast<int>(pow(osn[1], (1 / pok[0]))) == 0) || (pow(osn[2], (1 / pok[0])) - static_cast<int>(pow(osn[2], (1 / pok[0]))) == 0))
						check = 0;
				} while (check != 1);
				cout << "\\item		Найдите значение выражения: $$\\frac{\\sqrt[" << pok[0] << "]{" << osn[0] << "}\\sqrt[" << pok[0] << "]{" << osn[1] << "}}{\\sqrt[" << pok[0] << "]{" << osn[2] << "}}$$" << endl;
				//cout << "\\\\" << answer << endl;
				Answer = "  \\item " + FormatDouble(answer) + " \n";
				break;
			}
            return Answer;
}

string LogCount(int AllType)
{
    double up[3];
			double osn[2];
			double pok[1];
			string Answer;
			int check = 0;
			double answer, change;
			int type;
            if(AllType == 0)
                type = rand()%4+1;
            else
                type = AllType;
			int type_1;
			switch (type)
			{
			case 1:
				type_1 = rand()%2+1;
				do {
					for (int i = 0; i < 2; i++)
						up[i] = rand() % 100 + 2;
					osn[0] = rand() % 8 + 2;
					if(type_1==1)
						answer = (log(up[0])/log(osn[0])) - (log(up[1]) / log(osn[0]));
					else
						answer = (log(up[0]) / log(osn[0])) + (log(up[1]) / log(osn[0]));
					check = 1;
					if (answer - static_cast<int>(answer) != 0)
						check = 0;
					if ((up[0] == osn[0]) || (up[1] == osn[0]) || (up[0] == up[1]))
						check = 0;
					if ((log(up[0]) / log(osn[0])) - static_cast<int>(log(up[0]) / log(osn[0])) == 0)
						check = 0;
					if ((log(up[1]) / log(osn[0])) - static_cast<int>(log(up[1]) / log(osn[0])) == 0)
						check = 0;
				} while (check != 1);
				if (type_1 == 1)
					cout << "\\item		Найдите значение выражения: $\\log_{" << osn[0] << "}{" << up[0] << "}-\\log_{" << osn[0] << "}{" << up[1] << "}$" << endl;
				else
					cout << "\\item		Найдите значение выражения: $\\log_{" << osn[0] << "}{" << up[0] << "}+\\log_{" << osn[0] << "}{" << up[1] << "}$" << endl;
				//cout << "\\\\" << answer << endl;
				Answer = "  \\item " + FormatDouble(answer) + " \n";
				break;

			case 2:
				do {
					for (int i = 0; i < 2; i++)
						up[i] = rand() % 12 + 2;
					osn[0] = up[1] / up[0];
					pok[0] = rand() % 3 + 1;
					if (100 * osn[0] - static_cast<int>(100 * osn[0]) == 0)
					{
						answer = -1 * pok[0];
						check = 1;
						if (osn[0] == 1)
							check = 0;
					}
					else 
						check = 0;
					if (osn[0] - static_cast<int>(osn[0]) == 0)
						check = 0;
				} while (check != 1);
				cout << "\\item		Найдите значение выражения: $\\log_{" << osn[0] << "}{" << pow(up[0], pok[0]) << "}-\\log_{" << osn[0] << "}{" << pow(up[1], pok[0]) << "}$" << endl;
				//cout << "\\\\" << answer << endl;
				Answer = "  \\item " + FormatDouble(answer) + " \n";
				break;

			case 3:
				type_1 = rand() % 2 + 1;
				do {
					for (int i = 0; i < 2; i++)
						up[i] = rand() % 20 + 2;
					osn[0] = rand() % 8 + 2;
					if (type_1 == 1)
						answer = up[0] * osn[0];
					else
						answer = up[0] / osn[0];
					check = 1;
					if (answer > 500)
						check = 0;
					if (answer - static_cast<int>(answer) != 0)
						check = 0;
				} while (check != 1);
				if (type_1 == 1)
					cout << "\\item		Найдите значение выражения: $" << up[0] << "\\log_{\\sqrt[" << osn[0] << "]{" << up[1] << "}}{" << up[1] << "}$." << endl;
				else
					cout << "\\item		Найдите значение выражения: $" << up[0] << "\\log_{" << up[1] << "}{\\sqrt[" << osn[0] << "]{" << up[1] << "}}$." << endl;
				//cout << "\\\\" << answer << endl;
				Answer = "  \\item " + FormatDouble(answer) + " \n";
				break;

			case 4:
				type_1 = rand()%4+1;
				do {
					for (int i = 0; i < 2; i++)
						osn[i] = rand() % 10 + 2;
					for (int i = 0; i < 3; i++)
						up[i] = rand() % 30 + 2;
					change = NOD(up[1], up[2]);
					up[1] = up[1] / change;
					up[2] = up[2] / change;
					switch (type_1)
					{
					case 1:
						answer = log(up[0] * up[1] / up[2]) / log(osn[0]);
							break;

					case 2:
						answer = log(up[0] * up[1] / up[2]) / log(osn[0]);
						break;

					case 3:
						answer = log(up[0] * up[2] / up[1]) / log(osn[0]);
						break;

					case 4:
						answer = log(up[1] / (up[0]*up[2])) / log(osn[0]);
							break;
					}
					check = 1;
					if (answer - static_cast<int>(answer) != 0)
						check = 0;
					if (up[2] == 1)
						check = 0;
				} while (check != 1);
				switch (type_1)
				{
				case 1:
					cout << "\\item		Найдите значение выражения: $$\\frac{\\log_{" << osn[1] << "}{" << up[0] << "}}{\\log_{" << osn[1] << "}{" << osn[0] << "}}+\\log_{" << osn[0] << "}{\\frac{" << up[1] << "}{" << up[2] << "}}$$" << endl;
					break;

				case 2:
					cout << "\\item		Найдите значение выражения: $$\\log_{" << osn[0] << "}{\\frac{" << up[1] << "}{" << up[2] << "}}+\\frac{\\log_{" << osn[1] << "}{" << up[0] << "}}{\\log_{" << osn[1] << "}{" << osn[0] << "}}$$" << endl;
					break;

				case 3:
					cout << "\\item		Найдите значение выражения: $$\\frac{\\log_{" << osn[1] << "}{" << up[0] << "}}{\\log_{" << osn[1] << "}{" << osn[0] << "}}-\\log_{" << osn[0] << "}{\\frac{" << up[1] << "}{" << up[2] << "}}$$" << endl;
					break;

				case 4:
					cout << "\\item		Найдите значение выражения: $$\\log_{" << osn[0] << "}{\\frac{" << up[1] << "}{" << up[2] << "}}-\\frac{\\log_{" << osn[1] << "}{" << up[0] << "}}{\\log_{" << osn[1] << "}{" << osn[0] << "}}$$" << endl;
					break;
				}
				//cout << "\\\\" << answer << endl;
				Answer = "  \\item " + FormatDouble(answer) + " \n";
				break;
			}
            return Answer;
}

string TrigonomCount(int AllType)
{
            int type;
            if(AllType == 0)
                type = rand() % 7 + 1;
            else
                type = AllType;
            int check = 0;
            TrigFunction a[3];
            double b[6];
            int type_1, type_2;
            double del;
            int chetvert;
            int Zsin, Zcos;
            double answer;
            string Answer;
            switch (type)
            {
            case 1:
                do {
                    a[0].name = "sin";
                    a[0].angel = rand() % 550 + 370;
                    b[0] = rand() % 8 + 1;
                    type_1 = rand() % 3 + 1; // Меняет или нет название первой функции
                    switch (type_1)
                    {
                    case 1:             // Меняет название
                        a[1].name = "cos";
                        if (pow(-1, rand()) > 0)
                            a[1].angel = (a[0].angel / 2) + 90;
                        else
                            a[1].angel = (a[0].angel / 2) - 90;
                        break;

                    case 2:             // Меняет название
                        a[1].name = "sin";
                        if (pow(-1, rand()) > 0)
                            a[1].angel = (a[0].angel / 2) + 180;
                        else
                            a[1].angel = (a[0].angel / 2) - 180;
                        break;

                    case 3:
                        a[1].name = "sin";
                        a[1].angel = a[0].angel / 2;
                        break;
                    }
                    type_1 = rand() % 3 + 1; // Меняет или нет название второй функции
                    switch (type_1)
                    {
                    case 1:             // Меняет название
                        a[2].name = "sin";
                        if (pow(-1, rand()) > 0)
                            a[2].angel = (a[0].angel / 2) + 90;
                        else
                            a[2].angel = (a[0].angel / 2) - 90;
                        break;

                    case 2:             // Меняет название
                        a[2].name = "cos";
                        if (pow(-1, rand()) > 0)
                            a[2].angel = (a[0].angel / 2) + 180;
                        else
                            a[2].angel = (a[0].angel / 2) - 180;
                        break;

                    case 3:
                        a[2].name = "cos";
                        a[2].angel = a[0].angel / 2;
                        break;
                    }
                    b[1] = ZnakTrigonFunction(a[0].name, a[0].angel);
                    b[2] = ZnakTrigonFunction(a[1].name, a[1].angel);
                    b[3] = ZnakTrigonFunction(a[2].name, a[2].angel);
                    answer = 2 * b[0] * b[1] * b[2] * b[3];
                    check = 1;
                    if ((a[0].angel / 2) - static_cast<int>(a[0].angel / 2) != 0)
                        check = 0;
                    if ((a[0].angel / 90) - static_cast<int>(a[0].angel / 90) == 0)
                        check = 0;
                } while (check != 1);
                cout << "\\item     Найдите значение выражения: $$\\frac{" << NumberCelUr(b[0], 1) << "\\" << a[0].name << "(" << a[0].angel << "^{\\circ})}{\\" << a[1].name << "(" << a[1].angel << "^{\\circ})\\" << a[2].name << "(" << a[2].angel << "^{\\circ})}$$" << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 2:
                type_1 = rand() % 2 + 1;
                switch (type_1)
                {
                case 1:
                    b[1] = 1;
                    b[3] = 12;
                    break;

                case 2:
                    b[1] = 2;
                    b[3] = 8;
                    break;
                }
                do {
                    b[0] = rand() % 9 + 1;
                    b[2] = rand() % 17 + 1;
                    del = NOD(b[2], b[3]);
                    check = 1;
                    if (del != 1)
                        check = 0;
                } while (check != 1);
                answer = b[0] * sqrt(b[1]) * sin(b[2] * PI / b[3]) * cos(b[2] * PI / b[3]);
                switch (type_1)
                {
                case 1:
                    cout << "\\item     Найдите значение выражения: $" << NumberCelUr(b[0], 1) << "\\sin\\left(\\frac{" << NumberCelUr(b[2], 1) << "\\pi}{" << b[3] << "}\\right)\\cos\\left(\\frac{" << NumberCelUr(b[2], 1) << "\\pi}{" << b[3] << "}\\right)$." << endl;
                    break;

                case 2:
                    cout << "\\item     Найдите значение выражения: $" << NumberCelUr(b[0], 1) << "\\sqrt{2} \\sin\\left(\\frac{" << NumberCelUr(b[2], 1) << "\\pi}{" << b[3] << "}\\right)\\cos\\left(\\frac{" << NumberCelUr(b[2], 1) << "\\pi}{" << b[3] << "}\\right)$." << endl;
                    break;
                }
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 3:
                type_1 = rand()%3 +1;
                b[0] = rand() % 15 + 1;
                switch (type_1)
                {
                case 1:
                    type_2 = rand() % 4 + 1;
                    switch (type_2)
                    {
                    case 1:
                        do {
                            check = 0;
                            b[2] = rand() % 15 + 1;
                            b[4] = rand() % 15 + 1;
                            b[3] = rand() % 4 + 3;
                            b[5] = rand() % 4 + 3;

                            del = NOD(b[2], b[3]);
                            b[2] = b[2] / del;
                            b[3] = b[3] / del;

                            del = NOD(b[4], b[5]);
                            b[4] = b[4] / del;
                            b[5] = b[5] / del;

                            answer = b[0] * cos(b[2] * PI / b[3]) * cos(b[4] * PI / b[5]);
                            if ((b[3] == 3) && (b[5] == 3))
                                check = 1;
                            if ((b[3] == 4) && (b[5] == 4))
                                check = 1;
                            if ((b[3] == 6) && (b[5] == 6))
                                check = 1;
                        } while (check != 1);
                        cout << "\\item     Найдите значение выражения: $" << NumberCelUr(b[0],1) << "\\cos\\left(\\frac{" << NumberCelUr(b[2],1) << "\\pi}{" << b[3] << "}\\right)\\cos\\left(\\frac{" << NumberCelUr(b[4],1) << "\\pi}{" << b[5] << "}\\right)$." << endl;
                        break;

                    case 2:
                        do {
                            check = 0;
                            b[2] = rand() % 15 + 1;
                            b[4] = rand() % 15 + 1;
                            b[3] = rand() % 4 + 3;
                            b[5] = rand() % 4 + 3;

                            del = NOD(b[2], b[3]);
                            b[2] = b[2] / del;
                            b[3] = b[3] / del;

                            del = NOD(b[4], b[5]);
                            b[4] = b[4] / del;
                            b[5] = b[5] / del;

                            answer = b[0] * cos(b[2] * PI / b[3]) * sin(b[4] * PI / b[5]);
                            if ((b[3] == 3) && (b[5] == 6))
                                check = 1;
                            if ((b[3] == 4) && (b[5] == 4))
                                check = 1;
                            if ((b[3] == 6) && (b[5] == 3))
                                check = 1;
                        } while (check != 1);
                        cout << "\\item     Найдите значение выражения: $" << NumberCelUr(b[0], 1) << "\\cos\\left(\\frac{" << NumberCelUr(b[2], 1) << "\\pi}{" << b[3] << "}\\right)\\sin\\left(\\frac{" << NumberCelUr(b[4], 1) << "\\pi}{" << b[5] << "}\\right)$." << endl;
                        break;

                    case 3:
                        do {
                            check = 0;
                            b[2] = rand() % 15 + 1;
                            b[4] = rand() % 15 + 1;
                            b[3] = rand() % 4 + 3;
                            b[5] = rand() % 4 + 3;

                            del = NOD(b[2], b[3]);
                            b[2] = b[2] / del;
                            b[3] = b[3] / del;

                            del = NOD(b[4], b[5]);
                            b[4] = b[4] / del;
                            b[5] = b[5] / del;

                            answer = b[0] * sin(b[2] * PI / b[3]) * cos(b[4] * PI / b[5]);
                            if ((b[3] == 3) && (b[5] == 6))
                                check = 1;
                            if ((b[3] == 4) && (b[5] == 4))
                                check = 1;
                            if ((b[3] == 6) && (b[5] == 3))
                                check = 1;
                        } while (check != 1);
                        cout << "\\item     Найдите значение выражения: $" << NumberCelUr(b[0], 1) << "\\sin\\left(\\frac{" << NumberCelUr(b[2], 1) << "\\pi}{" << b[3] << "}\\right)\\cos\\left(\\frac{" << NumberCelUr(b[4], 1) << "\\pi}{" << b[5] << "}\\right)$." << endl;
                        break;

                    case 4:
                        do {
                            check = 0;
                            b[2] = rand() % 15 + 1;
                            b[4] = rand() % 15 + 1;
                            b[3] = rand() % 4 + 3;
                            b[5] = rand() % 4 + 3;

                            del = NOD(b[2], b[3]);
                            b[2] = b[2] / del;
                            b[3] = b[3] / del;

                            del = NOD(b[4], b[5]);
                            b[4] = b[4] / del;
                            b[5] = b[5] / del;

                            answer = b[0] * sin(b[2] * PI / b[3]) * sin(b[4] * PI / b[5]);
                            if ((b[3] == 3) && (b[5] == 3))
                                check = 1;
                            if ((b[3] == 4) && (b[5] == 4))
                                check = 1;
                            if ((b[3] == 6) && (b[5] == 6))
                                check = 1;
                        } while (check != 1);
                        cout << "\\item     Найдите значение выражения: $" << NumberCelUr(b[0], 1) << "\\sin\\left(\\frac{" << NumberCelUr(b[2], 1) << "\\pi}{" << b[3] << "}\\right)\\sin\\left(\\frac{" << NumberCelUr(b[4], 1) << "\\pi}{" << b[5] << "}\\right)$." << endl;
                        break;
                    }
                    break;

                case 2:
                    type_2 = rand() % 4 + 1;
                    switch (type_2)
                    {
                    case 1:
                        do {
                            check = 0;
                            b[2] = rand() % 15 + 1;
                            b[4] = rand() % 15 + 1;
                            b[3] = rand() % 4 + 3;
                            b[5] = rand() % 4 + 3;

                            del = NOD(b[2], b[3]);
                            b[2] = b[2] / del;
                            b[3] = b[3] / del;

                            del = NOD(b[4], b[5]);
                            b[4] = b[4] / del;
                            b[5] = b[5] / del;

                            answer = b[0] * sqrt(2)*cos(b[2] * PI / b[3]) * cos(b[4] * PI / b[5]);
                            if ((b[3] == 4) && (b[5] == 3))
                                check = 1;
                            if ((b[3] == 3) && (b[5] == 4))
                                check = 1;
                        } while (check != 1);
                        cout << "\\item     Найдите значение выражения: $" << NumberCelUr(b[0], 1) << "\\sqrt{2}\\cos\\left(\\frac{" << NumberCelUr(b[2], 1) << "\\pi}{" << b[3] << "}\\right)\\cos\\left(\\frac{" << NumberCelUr(b[4], 1) << "\\pi}{" << b[5] << "}\\right)$." << endl;
                        break;

                    case 2:
                        do {
                            check = 0;
                            b[2] = rand() % 15 + 1;
                            b[4] = rand() % 15 + 1;
                            b[3] = rand() % 4 + 3;
                            b[5] = rand() % 4 + 3;

                            del = NOD(b[2], b[3]);
                            b[2] = b[2] / del;
                            b[3] = b[3] / del;

                            del = NOD(b[4], b[5]);
                            b[4] = b[4] / del;
                            b[5] = b[5] / del;

                            answer = b[0] * sqrt(2)*cos(b[2] * PI / b[3]) * sin(b[4] * PI / b[5]);
                            if ((b[3] == 4) && (b[5] == 6))
                                check = 1;
                            if ((b[3] == 3) && (b[5] == 4))
                                check = 1;
                        } while (check != 1);
                        cout << "\\item     Найдите значение выражения: $" << NumberCelUr(b[0], 1) << "\\sqrt{2}\\cos\\left(\\frac{" << NumberCelUr(b[2], 1) << "\\pi}{" << b[3] << "}\\right)\\sin\\left(\\frac{" << NumberCelUr(b[4], 1) << "\\pi}{" << b[5] << "}\\right)$." << endl;
                        break;

                    case 3:
                        do {
                            check = 0;
                            b[2] = rand() % 15 + 1;
                            b[4] = rand() % 15 + 1;
                            b[3] = rand() % 4 + 3;
                            b[5] = rand() % 4 + 3;

                            del = NOD(b[2], b[3]);
                            b[2] = b[2] / del;
                            b[3] = b[3] / del;

                            del = NOD(b[4], b[5]);
                            b[4] = b[4] / del;
                            b[5] = b[5] / del;

                            answer = b[0] * sqrt(2)*sin(b[2] * PI / b[3]) * cos(b[4] * PI / b[5]);
                            if ((b[3] == 6) && (b[5] == 4))
                                check = 1;
                            if ((b[3] == 4) && (b[5] == 3))
                                check = 1;
                        } while (check != 1);
                        cout << "\\item     Найдите значение выражения: $" << NumberCelUr(b[0], 1) << "\\sqrt{2}\\sin\\left(\\frac{" << NumberCelUr(b[2], 1) << "\\pi}{" << b[3] << "}\\right)\\cos\\left(\\frac{" << NumberCelUr(b[4], 1) << "\\pi}{" << b[5] << "}\\right)$." << endl;
                        break;

                    case 4:
                        do {
                            check = 0;
                            b[2] = rand() % 15 + 1;
                            b[4] = rand() % 15 + 1;
                            b[3] = rand() % 4 + 3;
                            b[5] = rand() % 4 + 3;

                            del = NOD(b[2], b[3]);
                            b[2] = b[2] / del;
                            b[3] = b[3] / del;

                            del = NOD(b[4], b[5]);
                            b[4] = b[4] / del;
                            b[5] = b[5] / del;

                            answer = b[0] * sqrt(2)*sin(b[2] * PI / b[3]) * sin(b[4] * PI / b[5]);
                            if ((b[3] == 6) && (b[5] == 4))
                                check = 1;
                            if ((b[3] == 4) && (b[5] == 6))
                                check = 1;
                        } while (check != 1);
                        cout << "\\item     Найдите значение выражения: $" << NumberCelUr(b[0], 1) << "\\sqrt{2}\\sin\\left(\\frac{" << NumberCelUr(b[2], 1) << "\\pi}{" << b[3] << "}\\right)\\sin\\left(\\frac{" << NumberCelUr(b[4], 1) << "\\pi}{" << b[5] << "}\\right)$." << endl;
                        break;
                    }
                    break;

                case 3:
                    type_2 = rand() % 4 + 1;
                    switch (type_2)
                    {
                    case 1:
                        do {
                            check = 0;
                            b[2] = rand() % 15 + 1;
                            b[4] = rand() % 15 + 1;
                            b[3] = rand() % 4 + 3;
                            b[5] = rand() % 4 + 3;

                            del = NOD(b[2], b[3]);
                            b[2] = b[2] / del;
                            b[3] = b[3] / del;

                            del = NOD(b[4], b[5]);
                            b[4] = b[4] / del;
                            b[5] = b[5] / del;

                            answer = b[0] * sqrt(3) * cos(b[2] * PI / b[3]) * cos(b[4] * PI / b[5]);
                            if ((b[3] == 6) && (b[5] == 3))
                                check = 1;
                            if ((b[3] == 3) && (b[5] == 6))
                                check = 1;
                        } while (check != 1);
                        cout << "\\item     Найдите значение выражения: $" << NumberCelUr(b[0], 1) << "\\sqrt{3}\\cos\\left(\\frac{" << NumberCelUr(b[2], 1) << "\\pi}{" << b[3] << "}\\right)\\cos\\left(\\frac{" << NumberCelUr(b[4], 1) << "\\pi}{" << b[5] << "}\\right)$." << endl;
                        break;

                    case 2:
                        do {
                            check = 0;
                            b[2] = rand() % 15 + 1;
                            b[4] = rand() % 15 + 1;
                            b[3] = rand() % 4 + 3;
                            b[5] = rand() % 4 + 3;

                            del = NOD(b[2], b[3]);
                            b[2] = b[2] / del;
                            b[3] = b[3] / del;

                            del = NOD(b[4], b[5]);
                            b[4] = b[4] / del;
                            b[5] = b[5] / del;

                            answer = b[0] * sqrt(3) * cos(b[2] * PI / b[3]) * sin(b[4] * PI / b[5]);
                            if ((b[3] == 6) && (b[5] == 6))
                                check = 1;
                            if ((b[3] == 3) && (b[5] == 3))
                                check = 1;
                        } while (check != 1);
                        cout << "\\item     Найдите значение выражения: $" << NumberCelUr(b[0], 1) << "\\sqrt{3}\\cos\\left(\\frac{" << NumberCelUr(b[2], 1) << "\\pi}{" << b[3] << "}\\right)\\sin\\left(\\frac{" << NumberCelUr(b[4], 1) << "\\pi}{" << b[5] << "}\\right)$." << endl;
                        break;

                    case 3:
                        do {
                            check = 0;
                            b[2] = rand() % 15 + 1;
                            b[4] = rand() % 15 + 1;
                            b[3] = rand() % 4 + 3;
                            b[5] = rand() % 4 + 3;

                            del = NOD(b[2], b[3]);
                            b[2] = b[2] / del;
                            b[3] = b[3] / del;

                            del = NOD(b[4], b[5]);
                            b[4] = b[4] / del;
                            b[5] = b[5] / del;

                            answer = b[0] * sqrt(3) * sin(b[2] * PI / b[3]) * cos(b[4] * PI / b[5]);
                            if ((b[3] == 3) && (b[5] == 3))
                                check = 1;
                            if ((b[3] == 6) && (b[5] == 6))
                                check = 1;
                        } while (check != 1);
                        cout << "\\item     Найдите значение выражения: $" << NumberCelUr(b[0], 1) << "\\sqrt{3}\\sin\\left(\\frac{" << NumberCelUr(b[2], 1) << "\\pi}{" << b[3] << "}\\right)\\cos\\left(\\frac{" << NumberCelUr(b[4], 1) << "\\pi}{" << b[5] << "}\\right)$." << endl;
                        break;

                    case 4:
                        do {
                            check = 0;
                            b[2] = rand() % 15 + 1;
                            b[4] = rand() % 15 + 1;
                            b[3] = rand() % 4 + 3;
                            b[5] = rand() % 4 + 3;

                            del = NOD(b[2], b[3]);
                            b[2] = b[2] / del;
                            b[3] = b[3] / del;

                            del = NOD(b[4], b[5]);
                            b[4] = b[4] / del;
                            b[5] = b[5] / del;

                            answer = b[0] * sqrt(3) * sin(b[2] * PI / b[3]) * sin(b[4] * PI / b[5]);
                            if ((b[3] == 6) && (b[5] == 3))
                                check = 1;
                            if ((b[3] == 3) && (b[5] == 6))
                                check = 1;
                        } while (check != 1);
                        cout << "\\item     Найдите значение выражения: $" << NumberCelUr(b[0], 1) << "\\sqrt{3}\\sin\\left(\\frac{" << NumberCelUr(b[2], 1) << "\\pi}{" << b[3] << "}\\right)\\sin\\left(\\frac{" << NumberCelUr(b[4], 1) << "\\pi}{" << b[5] << "}\\right)$." << endl;
                        break;
                    }
                    break;
                }
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 4:
                type_1 = rand() % 3 + 1;
                b[1] = rand() % 2 + 2;
                do {
                     check = 0;
                      b[0] = rand() % 7 + 1;
                      b[2] = rand() % 20 + 1;
                        if (b[1] == 2)
                            b[3] = 8;
                        else
                            b[3] = 12;
                        del = NOD(b[2], b[3]);
                        if (del == 1)
                            check = 1;
                    } while (check != 1);
                    answer = b[0] * sqrt(b[1]) * cos(2 * b[2] * PI / b[3]);
                if(type_1==1)
                    cout << "\\item     Найдите значение выражения: $" << NumberCelUr(b[0], 1) << "\\sqrt{" << b[1] << "}\\cos^2\\left(\\frac{" << NumberCelUr(b[2],1) << "\\pi}{" << b[3] << "}\\right)-" << NumberCelUr(b[0], 1) << "\\sqrt{" << b[1] << "}\\sin^2\\left(\\frac{" << NumberCelUr(b[2],1) << "\\pi}{" << b[3] << "}\\right)$." << endl;
                if (type_1 == 2)
                    cout << "\\item     Найдите значение выражения: $" << NumberCelUr((2*b[0]), 1) << "\\sqrt{" << b[1] << "}\\cos^2\\left(\\frac{" << NumberCelUr(b[2],1) << "\\pi}{" << b[3] << "}\\right)-" << NumberCelUr(b[0],1) << "\\sqrt{" << b[1] << "}$." << endl;
                if (type_1 == 3)
                    cout << "\\item     Найдите значение выражения: $" << NumberCelUr(b[0],1) << "\\sqrt{" << b[1] << "}-" << NumberCelUr((2*b[0]), 1) << "\\sqrt{" << b[1] << "}\\sin^2\\left(\\frac{" << NumberCelUr(b[2],1) << "\\pi}{" << b[3] << "}\\right)$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 5:
                type_1 = rand() % 2 + 1;
                switch (type_1)
                {
                case 1:
                    b[0] = rand() % 8 + 2;
                    b[1] = rand() % 9 + 1;
                    b[1] = b[1] / 10;
                    answer = b[0] * (2 * pow(b[1], 2) - 1);
                    cout << "\\item     Найдите значение выражения $" << NumberCelUr(b[0], 1) << "\\cos(2\\alpha)$, если $\\cos(\\alpha)=" << b[1] << "$." << endl;
                    break;

                case 2:
                    b[0] = rand() % 8 + 2;
                    b[1] = rand() % 9 + 1;
                    b[1] = b[1] / 10;
                    answer = b[0] * (1-2*pow(b[1],2));
                    cout << "\\item     Найдите значение выражения $" << NumberCelUr(b[0], 1) << "\\cos(2\\alpha)$, если $\\sin(\\alpha)=" << b[1] << "$." << endl;
                    break;

                }
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 6:
                type_1 = rand()%2+1;
                switch (type_1)
                {
                case 1:
                    chetvert = rand() % 4 + 1;
                    if ((chetvert == 1) || (chetvert == 2))
                        Zsin = 1;
                    else
                        Zsin = -1;

                    if ((chetvert == 1) || (chetvert == 4))
                        Zcos = 1;
                    else
                        Zcos = -1;
                    do {
                        check = 0;
                        b[0] = rand() % 99 + 1;
                        b[1] = rand() % 100 + 1;
                        del = sqrt(b[0]);
                        if (b[0] < (b[1] * b[1]))
                        {
                            b[3] = b[0] / pow(b[1], 2);
                            answer = Zcos*sqrt(1 - b[3]);
                            check = 1;
                            if (del - static_cast<int>(del) == 0)
                                check = 0;
                            if (100 * answer - static_cast<int>(100 * answer) != 0)
                                check = 0;
                            if (answer == 0)
                                check = 0;
                        }
                    } while (check != 1);
                    switch (chetvert)
                    {
                    case 1:
                        cout << "\\item     Найдите $\\cos(\\alpha)$, если $\\sin(\\alpha)=" << SIGNUr(Zsin, 1) << "\\frac{\\sqrt{" << b[0] << "}}{" << b[1] << "}$ и $\\alpha \\in \\left(0;\\frac{\\pi}{2}\\right)$." << endl;
                        break;

                    case 2:
                        cout << "\\item     Найдите $\\cos(\\alpha)$, если $\\sin(\\alpha)=" << SIGNUr(Zsin, 1) << "\\frac{\\sqrt{" << b[0] << "}}{" << b[1] << "}$ и $\\alpha \\in \\left(\\frac{\\pi}{2};\\pi\\right)$." << endl;
                        break;

                    case 3:
                        cout << "\\item     Найдите $\\cos(\\alpha)$, если $\\sin(\\alpha)=" << SIGNUr(Zsin, 1) << "\\frac{\\sqrt{" << b[0] << "}}{" << b[1] << "}$ и $\\alpha \\in \\left(\\pi;\\frac{3\\pi}{2}\\right)$." << endl;
                        break;

                    case 4:
                        cout << "\\item     Найдите $\\cos(\\alpha)$, если $\\sin(\\alpha)=" << SIGNUr(Zsin, 1) << "\\frac{\\sqrt{" << b[0] << "}}{" << b[1] << "}$ и $\\alpha \\in \\left(\\frac{3\\pi}{2};2\\pi\\right)$." << endl;
                        break;
                    }
                    break;

                case 2:
                    chetvert = rand() % 4 + 1;
                    if ((chetvert == 1) || (chetvert == 2))
                        Zsin = 1;
                    else
                        Zsin = -1;

                    if ((chetvert == 1) || (chetvert == 4))
                        Zcos = 1;
                    else
                        Zcos = -1;
                    do {
                        check = 0;
                        b[0] = rand() % 99 + 1;
                        b[1] = rand() % 100 + 1;
                        del = sqrt(b[0]);
                        if (b[0] < (b[1] * b[1]))
                        {
                            b[3] = b[0] / pow(b[1], 2);
                            answer = Zsin * sqrt(1 - b[3]);
                            check = 1;
                            if (del - static_cast<int>(del) == 0)
                                check = 0;
                            if (100 * answer - static_cast<int>(100 * answer) != 0)
                                check = 0;
                            if (answer == 0)
                                check = 0;
                        }
                    } while (check != 1);
                    switch (chetvert)
                    {
                    case 1:
                        cout << "\\item     Найдите $\\sin(\\alpha)$, если $\\cos(\\alpha)=" << SIGNUr(Zcos, 1) << "\\frac{\\sqrt{" << b[0] << "}}{" << b[1] << "}$ и $\\alpha \\in \\left(0;\\frac{\\pi}{2}\\right)$." << endl;
                        break;

                    case 2:
                        cout << "\\item     Найдите $\\sin(\\alpha)$, если $\\cos(\\alpha)=" << SIGNUr(Zcos, 1) << "\\frac{\\sqrt{" << b[0] << "}}{" << b[1] << "}$ и $\\alpha \\in \\left(\\frac{\\pi}{2};\\pi\\right)$." << endl;
                        break;

                    case 3:
                        cout << "\\item     Найдите $\\sin(\\alpha)$, если $\\cos(\\alpha)=" << SIGNUr(Zcos, 1) << "\\frac{\\sqrt{" << b[0] << "}}{" << b[1] << "}$ и $\\alpha \\in \\left(\\pi;\\frac{3\\pi}{2}\\right)$." << endl;
                        break;

                    case 4:
                        cout << "\\item     Найдите $\\sin(\\alpha)$, если $\\cos(\\alpha)=" << SIGNUr(Zcos, 1) << "\\frac{\\sqrt{" << b[0] << "}}{" << b[1] << "}$ и $\\alpha \\in \\left(\\frac{3\\pi}{2};2\\pi\\right)$." << endl;
                        break;
                    }
                    break;


                }
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 7:
                type_1 = rand()%2 + 1;
                switch (type_1)
                {
                case 1:
                    chetvert = rand() % 4 + 1;
                    if ((chetvert == 1) || (chetvert == 2))
                        Zsin = 1;
                    else
                        Zsin = -1;

                    if ((chetvert == 1) || (chetvert == 4))
                        Zcos = 1;
                    else
                        Zcos = -1;
                    do {
                        check = 0;
                        b[0] = rand() % 99 + 1;
                        b[1] = rand() % 100 + 1;
                        del = sqrt(b[0]);
                        if (b[0] < (b[1] * b[1]))
                        {
                            b[3] = b[0] / pow(b[1], 2);
                            b[4] = Zcos * sqrt(1 - b[3]);
                            b[5] = Zsin * sqrt(b[0]) / b[1];
                            answer = b[5] / b[4];
                            check = 1;
                            if (del - static_cast<int>(del) == 0)
                                check = 0;
                            if (100 * answer - static_cast<int>(100 * answer) != 0)
                                check = 0;
                            if (answer == 0)
                                check = 0;
                        }
                    } while (check != 1);
                    switch (chetvert)
                    {
                    case 1:
                        cout << "\\item     Найдите $\\tg(\\alpha)$, если $\\sin(\\alpha)=" << SIGNUr(Zsin, 1) << "\\frac{\\sqrt{" << b[0] << "}}{" << b[1] << "}$ и $\\alpha \\in \\left(0;\\frac{\\pi}{2}\\right)$." << endl;
                        break;

                    case 2:
                        cout << "\\item     Найдите $\\tg(\\alpha)$, если $\\sin(\\alpha)=" << SIGNUr(Zsin, 1) << "\\frac{\\sqrt{" << b[0] << "}}{" << b[1] << "}$ и $\\alpha \\in \\left(\\frac{\\pi}{2};\\pi\\right)$." << endl;
                        break;

                    case 3:
                        cout << "\\item     Найдите $\\tg(\\alpha)$, если $\\sin(\\alpha)=" << SIGNUr(Zsin, 1) << "\\frac{\\sqrt{" << b[0] << "}}{" << b[1] << "}$ и $\\alpha \\in \\left(\\pi;\\frac{3\\pi}{2}\\right)$." << endl;
                        break;

                    case 4:
                        cout << "\\item     Найдите $\\tg(\\alpha)$, если $\\sin(\\alpha)=" << SIGNUr(Zsin, 1) << "\\frac{\\sqrt{" << b[0] << "}}{" << b[1] << "}$ и $\\alpha \\in \\left(\\frac{3\\pi}{2};2\\pi\\right)$." << endl;
                        break;
                    }
                    break;

                case 2:
                    chetvert = rand() % 4 + 1;
                    if ((chetvert == 1) || (chetvert == 2))
                        Zsin = 1;
                    else
                        Zsin = -1;

                    if ((chetvert == 1) || (chetvert == 4))
                        Zcos = 1;
                    else
                        Zcos = -1;
                    do {
                        check = 0;
                        b[0] = rand() % 99 + 1;
                        b[1] = rand() % 100 + 1;
                        del = sqrt(b[0]);
                        if (b[0] < (b[1] * b[1]))
                        {
                            b[3] = b[0] / pow(b[1], 2);
                            b[4] = Zsin * sqrt(1 - b[3]);
                            b[5] = Zcos * sqrt(b[0]) / b[1];
                            answer = b[4] / b[5];
                            check = 1;
                            if (del - static_cast<int>(del) == 0)
                                check = 0;
                            if (100 * answer - static_cast<int>(100 * answer) != 0)
                                check = 0;
                            if (answer == 0)
                                check = 0;
                        }
                    } while (check != 1);
                    switch (chetvert)
                    {
                    case 1:
                        cout << "\\item     Найдите $\\tg(\\alpha)$, если $\\cos(\\alpha)=" << SIGNUr(Zcos, 1) << "\\frac{\\sqrt{" << b[0] << "}}{" << b[1] << "}$ и $\\alpha \\in \\left(0;\\frac{\\pi}{2}\\right)$." << endl;
                        break;

                    case 2:
                        cout << "\\item     Найдите $\\tg(\\alpha)$, если $\\cos(\\alpha)=" << SIGNUr(Zcos, 1) << "\\frac{\\sqrt{" << b[0] << "}}{" << b[1] << "}$ и $\\alpha \\in \\left(\\frac{\\pi}{2};\\pi\\right)$." << endl;
                        break;

                    case 3:
                        cout << "\\item     Найдите $\\tg(\\alpha)$, если $\\cos(\\alpha)=" << SIGNUr(Zcos, 1) << "\\frac{\\sqrt{" << b[0] << "}}{" << b[1] << "}$ и $\\alpha \\in \\left(\\pi;\\frac{3\\pi}{2}\\right)$." << endl;
                        break;

                    case 4:
                        cout << "\\item     Найдите $\\tg(\\alpha)$, если $\\cos(\\alpha)=" << SIGNUr(Zcos, 1) << "\\frac{\\sqrt{" << b[0] << "}}{" << b[1] << "}$ и $\\alpha \\in \\left(\\frac{3\\pi}{2};2\\pi\\right)$." << endl;
                        break;
                    }
                    break;
                }
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            }
            return Answer;
}

string TeorFerSimpl(int AllType)
{
            double answer;
            double a[3];
            string Answer;
            int type;
            if(AllType == 0)
                type = rand()%9+1;
            else
                type = AllType;
            int type_1;
            int check = 0;
            switch(type)
            {
            case 1:
                type_1 = rand()%2 + 1;
                do{
                    a[0] = rand()%20+2;
                    a[1] = rand()%70+30;
                    switch(type_1)
                    {
                    case 1:
                        answer = (a[1]-a[0])/a[1];
                        break;

                    case 2:
                        answer = a[0]/a[1];
                        break;
                    }
                    check = 1;
                    if(100*answer - static_cast<int>(100*answer)!=0)
                        check = 0;
                }while(check!=1);
                switch(type_1)
                {
                case 1:
                    cout << "\\item     Фабрика выпускает сумки. В среднем " << a[0] << " сумки из " << a[1] << " имеют скрытый дефект. Найдите вероятность того, что купленная сумка окажется без скрытого дефекта." << endl;
                    break;

                case 2:
                    cout << "\\item     Фабрика выпускает сумки. В среднем " << a[0] << " сумки из " << a[1] << " имеют скрытый дефект. Найдите вероятность того, что купленная сумка окажется с дефектом." << endl;
                    break;
                }
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 2:
                do{
                    a[0] = rand()%90 + 30;
                    a[1] = rand()%500 + 100;
                    answer = (a[1]-3*a[0])/a[1];
                    check = 1;
                    if(100*answer - static_cast<int>(100*answer)!=0)
                        check = 0;
                    if(a[1]<=3*a[0])
                        check = 0;
                }while(check!=1);
                cout << "\\item     На олимпиаде по математике " << a[1] << " участников разместили в четырёх аудиториях. В первых трех удалось разместить по " << a[0] << " человек, оставшихся перевели в запасную аудиторию в другом корпусе. Найдите вероятность того, что случайно выбранный участник писал олимпиаду в запасной аудитории." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 3:
                do{
                    for(int i=0;i<3;i++)
                        a[i] = rand()%25+2;
                    answer = a[2]/(a[0]+a[1]+a[2]);
                    check = 1;
                    if(100*answer - static_cast<int>(100*answer)!=0)
                        check = 0;
                    if(a[0]+a[1]+a[2]<10)
                        check = 0;
                }while(check!=1);
                cout << "\\item     На конференцию приехали ученые из трёх стран: " << a[0] << " из Австрии, " << a[1] << " из Германии и " << a[2] << " из Сербии. Каждый из них делает на конференции один доклад. Порядок докладов определяется жеребьёвкой. Найдите вероятность того, что десятым окажется доклад ученого из Сербии." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 4:
                a[0] = rand()%70+20;
                a[0]=a[0]/100;
                answer = 1 - a[0];
                cout << "\\item     Вероятность того, что в случайный момент времени температура тела здорового человека окажется ниже чем 36,8 $^{\\circ}C$, равна " << a[0] << ". Найдите вероятность того, что в случайный момент времени у здорового человека температура окажется 36,8 $^{\\circ}C$ или выше." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 5:
                type_1 = rand()%2 + 1;
                do{
                    a[0] = rand()%20 + 2;
                    a[1] = rand()%800 + 100;
                    switch(type_1)
                    {
                    case 1:
                        answer = (a[1]-a[0])/a[1];
                        break;

                    case 2:
                        answer = a[0]/a[1];
                        break;
                    }
                    check = 1;
                    if((1000*answer - static_cast<int>(1000*answer))!=0)
                        check = 0;
                }while(check!=1);
                switch(type_1)
                {
                case 1:
                    cout << "\\item     В среднем из " << a[1] << " садовых насосов, поступивших в продажу, " << a[0] << " подтекают. Найдите вероятность того, что один случайно выбранный для контроля насос не подтекает." << endl;
                    break;

                case 2:
                    cout << "\\item     В среднем из " << a[1] << " садовых насосов, поступивших в продажу, " << a[0] << " подтекают. Найдите вероятность того, что один случайно выбранный для контроля насос подтекает." << endl;
                    break;
                }
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 6:
                do{
                    a[0] = rand()%20 + 20;
                    a[1] = rand()%10 + 2;
                    a[2] = rand()%10 + 2;
                    answer = (a[0] - a[1] - a[2])/a[0];
                    check = 1;
                    if(100*answer - static_cast<int>(100*answer)!=0)
                        check = 0;
                    if(a[1]+a[2]>=a[0])
                        check = 0;
                }while(check!=1);
                cout << "\\item     В чемпионате по гимнастике участвуют " << a[0] << " спортсменок: " << a[1] << " из Венгрии, " << a[2] << " из Румынии, остальные -- из Болгарии. Порядок, в котором выступают спортсменки, определяется жребием. Найдите вероятность того, что спортсменка, выступающая первой, окажется из Болгарии." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 7:
                type_1 = rand()%2 + 1;
                do{
                    a[0] = rand()%20+10;
                    a[1] = rand()%10 + 3;
                    switch(type_1)
                    {
                    case 1:
                        answer = (a[0]-a[1])/a[0];
                        break;

                    case 2:
                        answer = a[1]/a[0];
                        break;
                    }
                    check = 1;
                    if(100*answer - static_cast<int>(100*answer)!=0)
                        check = 0;
                    if(a[1]>a[0])
                        check = 0;
                }while(check!=1);
                switch(type_1)
                {
                case 1:
                    cout << "\\item     В сборнике билетов по математике всего " << a[0] << " билетов, в " << a[1] << " из них встречаются вопрос по теме <<Логарифмы>>. Найдите вероятность того, что в случайно выбранном на экзамене билете школьнику не достанется вопрос по  теме <<Логарифмы>>." << endl;
                    break;

                case 2:
                    cout << "\\item     В сборнике билетов по математике всего " << a[0] << " билетов, в " << a[1] << " из них встречаются вопрос по теме <<Логарифмы>>. Найдите вероятность того, что в случайно выбранном на экзамене билете школьнику достанется вопрос по  теме <<Логарифмы>>." << endl;
                    break;
                }
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 8:
                type_1 = rand()%2 + 1;
                do{
                    a[0] = rand()%20+10;
                    a[1] = rand()%10 + 3;
                    switch(type_1)
                    {
                    case 1:
                        answer = (a[0]-a[1])/a[0];
                        break;

                    case 2:
                        answer = a[1]/a[0];
                        break;
                    }
                    check = 1;
                    if(100*answer - static_cast<int>(100*answer)!=0)
                        check = 0;
                    if(a[1]>=a[0])
                        check = 0;
                }while(check!=1);
                switch(type_1)
                {
                case 1:
                    cout << "\\item     В группе туристов " << a[0] << " человек. С помощью жребия они выбирают " << a[1] << " человек, которые должны идти в село в магазин за продуктами. Какая вероятность того, что турист Д., входящий в состав группы, не пойдет в магазин." << endl;
                    break;

                case 2:
                    cout << "\\item     В группе туристов " << a[0] << " человек. С помощью жребия они выбирают " << a[1] << " человек, которые должны идти в село в магазин за продуктами. Какая вероятность того, что турист Д., входящий в состав группы, пойдет в магазин." << endl;
                    break;
                }
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 9:
                do{
                    a[0] = rand()%300 + 100;
                    a[1] = rand()%20 + 10;
                    answer = a[1]/a[0];
                    check = 1;
                    if(100*answer - static_cast<int>(100*answer)!=0)
                        check = 0;
                }while(check!=1);
                cout << "\\item     В группе туристов " << a[0] << " человек. Их вертолетом доставляют в труднодоступный район, перевоза по " << a[1] << " человек за рейс. Порядок, в котором вертолет перевозит туристов, случаен. Найдите вероятность того, что турист В., полетит вторым рейсом вертолета." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;


            }
            return Answer;
}

string TeorFerDif(int AllType)
{
            string Answer;
            double a[4];
            double b, S;
            double answer;
            double change;
            int check = 0;
            int type;
            if(AllType == 0)
                type = rand()%14+1;
            else
                type = AllType;
            int type_1;
            int patron;
            switch (type)
            {
            case 1:     // Футбольный матч три игры
                type_1 = rand() % 3 + 1;
                switch (type_1)
                {
                case 1:
                    answer = 0.125;
                    cout << "\\item     Перед началом футбольного матча судья бросает монетку, чтобы определить, какая из команд начнет игру с мячом. Команда <<Сапфир>> играет три матча с разными командами. Найдите вероятность того, что в этих матчах команда <<Сапфир>> начнет игру все 3 раза." << endl;
                    break;

                case 2:
                    answer = 0.5;
                    cout << "\\item     Перед началом футбольного матча судья бросает монетку, чтобы определить, какая из команд начнет игру с мячом. Команда <<Сапфир>> играет три матча с разными командами. Найдите вероятность того, что в этих матчах команда <<Сапфир>> начнет игру не более 1го раза." << endl;
                    break;

                case 3:
                    answer = 0.875;
                    cout << "\\item     Перед началом футбольного матча судья бросает монетку, чтобы определить, какая из команд начнет игру с мячом. Команда <<Сапфир>> играет три матча с разными командами. Найдите вероятность того, что в этих матчах команда <<Сапфир>> начнет игру не более 2х раз." << endl;
                    break;
                }
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 2:     // Из районного центра в деревню
                do {
                    for (int i = 0; i < 2; i++)
                        a[i] = rand() % 40 + 45;
                    for (int i = 0; i < 2; i++)
                        a[i] = a[i] / 100;
                    if (a[0] < a[1])
                    {
                        change = a[0];
                        a[0] = a[1];
                        a[1] = change;
                    }
                    answer = a[0] - a[1];
                    check = 1;
                    if (a[0] == a[1])
                        check = 0;
                } while (check != 1);
                cout << "\\item     Из районного центра в деревню ежедневно ходит автобус. Вероятность того, что в понедельник в автобусе окажется меньше 23 пассажиров, равна " << a[0] << ". Вероятность того, что окажется меньше 14 пассажиров, равна " << a[1] << ". Найдите вероятность того, что число пассажиров будет от 14 до 22 включительно." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 3:     // Футбольный матч две игры
                type_1 = rand() % 2 + 1;
                switch (type_1)
                {
                case 1:
                    answer = 0.75;
                    cout << "\\item     Перед началом футбольного матча судья бросает монетку, чтобы определить, какая из команд начнёт игру с мячом. Команда <<Изумруд>> играет два матча с разными командами. Найдите вероятность того, что в этих матчах команда <<Изумруд>> начнёт игру с мячом не больше одного раза." << endl;
                    break;

                case 2:
                    answer = 0.25;
                    cout << "\\item     Перед началом футбольного матча судья бросает монетку, чтобы определить, какая из команд начнёт игру с мячом. Команда <<Изумруд>> играет два матча с разными командами. Найдите вероятность того, что в этих матчах команда <<Изумруд>> начнёт игру оба раза." << endl;
                    break;
                }
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 4:     // В торговом центре два автомата
                type_1 = rand() % 2 + 1;
                do {
                    a[0] = rand() % 10 + 10;
                    a[0] = a[0] / 100;
                    a[1] = rand() % 10 + 5;
                    a[1] = a[1] / 100;
                    if (a[0] < a[1])
                    {
                        change = a[0];
                        a[0] = a[1];
                        a[1] = change;
                    }
                    switch (type_1)
                    {
                    case 1:
                        answer = 1 - (a[0] + a[0] - a[1]);
                        break;

                    case 2:
                        answer = 2 * a[0] - a[1];
                        break;
                    }
                    check = 1;
                    if (a[0] == a[1])
                        check = 0;
                } while (check != 1);
                switch (type_1)
                {
                case 1:
                    cout << "\\item     В торговом центре два одинаковых автомата продают кофе. Вероятность того, что к концу дня в первом автомате закончится кофе, равна " << a[0] << ". Вероятность того, что кофе закончится во втором автомате, такая же. Вероятность того, что кофе закончится в двух автоматах, равна " << a[1] << ". Найдите вероятность того, что к концу дня кофе останется в двух автоматах." << endl;
                    break;

                case 2:
                    cout << "\\item     В торговом центре два одинаковых автомата продают кофе. Вероятность того, что к концу дня в первом автомате закончится кофе, равна " << a[0] << ". Вероятность того, что кофе закончится во втором автомате, такая же. Вероятность того, что кофе закончится в двух автоматах, равна " << a[1] << ". Найдите вероятность того, что к концу дня кофе закончится хотя бы в одном автомате." << endl;
                    break;
                }
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 5:     // Патроны стрелку
                do {
                    a[0] = rand() % 5 + 3;
                    a[0] = a[0] / 10;        // Попал
                    a[1] = 1 - a[0];        // Промах
                    a[2] = rand() % 4 + 6;      // Точность
                    a[2] = a[2] / 10;
                    b = a[0];
                    S = b;
                    answer = 1;
                    do {
                        b = b * a[1];
                        S = S + b;
                        answer++;
                        if (S > a[2])
                            check = 1;
                    } while (check != 1);
                    if (a[2] <= a[0])
                        check = 0;
                } while (check != 1);
                cout << "\\item     Стрелок в тире стреляет по мишени до тех пор, пока не поразит её. Известно, что он попадает в цель с вероятностью " << a[0] << " при каждом отдельном выстреле. Какое наименьшее количество патронов нужно дать стрелку, чтобы он поразил цель с вероятностью не меньше " << a[2] << "?" << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 6:     // Фламастеры
                do {
                    a[0] = rand() % 12 + 2;
                    a[1] = rand() % 12 + 2;
                    a[3] = rand() % 30 + 2;
                    a[2] = a[3] - a[0] - a[1];
                    answer = 2 * a[0] * a[1] / (a[3] * (a[3] - 1));
                    check = 1;
                    if (a[2] <= 0)
                        check = 0;
                    if (100 * answer - static_cast<int>(100 * answer) != 0)
                        check = 0;
                } while (check != 1);
                cout << "\\item     В коробке " << a[0] << " синих, " << a[1] << " красных и " << a[2] << " зелёных фломастеров. Случайным образом выбирают два фломастера. Найдите вероятность того, что окажутся выбраны один синий и один красный фломастеры." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 7:     // Игральную кость, какое-то число не выпало
                do {
                    S = 0;
                    a[0] = rand() % 6 + 1; // число которое убрали
                    a[1] = rand() % 11 + 2; // сумма
                    for (int i = 1; i <= 6; i++)
                    {
                        for (int m = 1; m <= 6; m++)
                        {
                            if (i != a[0])
                            {
                                if(m != a[0])
                                {
                                    if (i + m == a[1])
                                        S++;
                                }
                            }
                        }
                    }
                    answer = S / 25;
                    check = 1;
                    if (1000 * answer - static_cast<int>(1000 * answer) != 0)
                        check = 0;
                } while (check != 1);
                cout << "\\item     Игральную кость бросили два раза. Известно, что " << a[0] << " не выпало ни разу. Найдите при этом условии вероятность события <<сумма очков равна " << a[1] << ">>." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 8:     // Батарейки
                do {
                    a[0] = rand() % 9 + 1; // Вероятность брака
                    a[0] = a[0] / 100;

                    a[1] = 1 - a[0];        // Вероятность хорошей батарейки

                    a[2] = rand() % 9 + 90; // Блок брака
                    a[2] = a[2] / 100;

                    a[3] = rand() % 9 + 1;  // Блок нормальной
                    a[3] = a[3] / 100;

                    answer = a[0] * a[2] + a[1] * a[3];
                    check = 1;
                    if (10000 * answer - static_cast<int>(10000 * answer) != 0)
                        check = 0;
                } while (check != 1);
                cout << "\\item     Автоматическая линия изготавливает батарейки. Вероятность того, что готовая батарейка неисправна, равна " << a[0] << ". Перед упаковкой каждая батарейка проходит систему контроля качества.Вероятность того, что система забракует неисправную батарейку, равна " << a[2] << ". Вероятность того, что система по ошибке забракует исправную батарейку, равна " << a[3] << ". Найдите вероятность того, что случайно выбранная изготовленная батарейка будет забракована системой контроля." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 9:     // Стрелок стреляет в мишени
                type_1 = rand() % 3 + 1;
                do {
                    a[0] = rand() % 5 + 4;  // Вероятность попасть
                    a[0] = a[0] / 10;
                    a[1] = 1 - a[0];
                    switch (type_1)
                    {
                    case 1:
                        answer = pow(a[0], 2) * pow(a[1], 2);
                        break;

                    case 2:
                        answer = a[0] * pow(a[1], 3);
                        break;

                    case 3:
                        answer = pow(a[0], 3) * a[1];
                        break;
                    }
                    check = 1;
                } while (check != 1);
                switch (type_1)
                {
                case 1:
                    cout << "\\item     Стрелок стреляет по одному разу в каждую из четырёх мишеней. Вероятность попадания в мишень при каждом отдельном выстреле равна " << a[0] << ". Найдите вероятность того, что стрелок попадёт в две первые мишени и не попадёт в две последние." << endl;
                    break;

                case 2:
                    cout << "\\item     Стрелок стреляет по одному разу в каждую из четырёх мишеней. Вероятность попадания в мишень при каждом отдельном выстреле равна " << a[0] << ". Найдите вероятность того, что стрелок попадёт в первую мишень и не попадёт в остальные." << endl;
                    break;

                case 3:
                    cout << "\\item     Стрелок стреляет по одному разу в каждую из четырёх мишеней. Вероятность попадания в мишень при каждом отдельном выстреле равна " << a[0] << ". Найдите вероятность того, что стрелок попадёт в три первые мишени и не попадёт в последнюю." << endl;
                    break;
                }
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 10:    // Хлеб
                a[0] = rand() % 30 + 68;
                a[1] = rand() % 20 + 50;
                a[0] = a[0] / 100;
                a[1] = a[1] / 100;
                if (a[1] > a[0])
                {
                    change = a[0];
                    a[0] = a[1];
                    a[1] = change;
                }
                answer = a[1] + a[0] - 1;
                cout << "\\item     При выпечке хлеба производится контрольное взвешивание свежей буханки. Известно, что вероятность того, что масса окажется меньше 810 г, равна " << a[0] << ". Вероятность того, что масса окажется больше 790 г, равна " << a[1] << ". Найдите вероятность того, что масса буханки больше 790 г, но меньше 810 г." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 11:    // Лампы
                type_1 = rand() % 3 + 1;
                a[0] = rand() % 4 + 5;
                a[0] = a[0] / 10;    // Перегар
                a[1] = 1 - a[0];    // Не перегар
                switch (type_1)
                {
                case 1:
                    answer = 1 - pow(a[0], 3);
                    cout << "\\item     Помещение освещается тремя лампами. Вероятность перегорания каждой лампы в течение года равна " << a[0] << ". Лампы перегорают независимо друг от друга. Найдите вероятность того, что в течение года хотя бы одна лампа не перегорит." << endl;
                    break;

                case 2:
                    answer = pow(a[0], 3);
                    cout << "\\item     Помещение освещается тремя лампами. Вероятность перегорания каждой лампы в течение года равна " << a[0] << ". Лампы перегорают независимо друг от друга. Найдите вероятность того, что в течение года перегарят все лампы." << endl;
                    break;

                case 3:
                    answer = pow(a[1], 3);
                    cout << "\\item     Помещение освещается тремя лампами. Вероятность перегорания каждой лампы в течение года равна " << a[0] << ". Лампы перегорают независимо друг от друга. Найдите вероятность того, что в течение года не перегорит ни одна лампа." << endl;
                    break;
                }
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 12:    // Группу туристов
                do {
                    a[0] = rand() % 20 + 11;
                    a[1] = rand() % 5 + 3;
                    answer = a[1] / a[0];
                    check = 1;
                    if (answer * 100 - static_cast<int>(100 * answer) != 0)
                        check = 0;
                    if (answer >= 1)
                        check = 0;
                    if ((a[0]/a[1]) - static_cast<int>(a[0]/a[1]) != 0)
                        check = 0;
                } while (check != 1);
                cout << "\\item     В группе туристов " << a[0] << " человек.Их вертолётом доставляют в труднодоступный район, перевозя по " << a[1] << " человека за рейс.Порядок, в котором вертолёт перевозит туристов, случаен.Найдите вероятность того, что турист В., входящий в состав группы, полетит вторым рейсом вертолёта." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 13:    // Задачи на математике
                do {
                    a[0] = rand() % 40 + 50;
                    a[0] = a[0] / 100;
                    a[1] = rand() % 40 + 50;
                    a[1] = a[1] / 100;
                    if (a[1] > a[0])
                    {
                        change = a[0];
                        a[0] = a[1];
                        a[1] = change;
                    }
                    check = 1;
                    answer = a[0] - a[1];
                    if (answer == 0)
                        check = 0;
                } while (check != 1);
                cout << "\\item     Вероятность того, что на тестировании по математике учащийся А. верно решит больше четырёх задач, равна " << a[1] << ". Вероятность того, что А. верно решит больше трёх задач, равна " << a[0] << ". Найдите вероятность того, что А. верно решит ровно 4 задачи." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 14:    // Бросают монету дважды
                type_1 = rand() % 3 + 1;
                switch (type_1)
                {
                case 1:
                    answer = 0.25;
                    cout << "\\item     В случайном эксперименте симметричную монету бросают дважды. Найдите вероятность того, что решка выпадет оба раза." << endl;
                    break;

                case 2:
                    answer = 0.25;
                    cout << "\\item     В случайном эксперименте симметричную монету бросают дважды. Найдите вероятность того, что решка не выпадет ни разу." << endl;
                    break;

                case 3:
                    answer = 0.5;
                    cout << "\\item     В случайном эксперименте симметричную монету бросают дважды. Найдите вероятность того, что решка выпадет ровно один раз." << endl;
                    break;
                }
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;
            }
            return Answer;
}

string ISDUravn(int AllType)
{
    int type;
    if(AllType == 0)
        type = rand()%4+1;
    else
        type = AllType;
            int check = 0;
            double answer, del;
            int type_1;
            string Answer;
            double a[5];
            switch (type)
            {
            case 1:
                do {
                    for (int i = 0; i < 2; i++)
                        a[i] = pow(-1, rand()) * (rand() % 30 + 3);
                    a[2] = rand() % 30 + 3;
                    check = 1;
                    answer = (pow(a[2], 2) - a[1]) / a[0];
                    if (10 * answer - static_cast<int>(10 * answer) != 0)
                        check = 0;
                } while (check != 1);
                cout << "\\item     Найдите корень уравнения: $\\sqrt{" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "x" << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << "}=" << SIGNUr(a[2], 1) << NumberCelUr(a[2], 1) << "$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 2:
                do {
                    for (int i = 0; i < 3; i++)
                        a[i] = pow(-1, rand()) * (rand() % 30 + 3);
                    check = 1;
                    answer = (pow(a[2], 3) - a[1]) / a[0];
                    if (10 * answer - static_cast<int>(10 * answer) != 0)
                        check = 0;
                } while (check != 1);
                cout << "\\item     Найдите корень уравнения: $\\sqrt[3]{" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "x" << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << "}=" << SIGNUr(a[2], 1) << NumberCelUr(a[2], 1) << "$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 3:
                type_1 = rand() % 4 + 1;
                do {
                    for (int i = 0; i < 3; i++)
                        a[i] = pow(-1, rand()) * (rand() % 96 + 3);
                    switch (type_1)
                    {
                    case 1:
                        a[2] = pow(-1, rand()) * 8;
                        break;

                    case 2:
                        a[2] = pow(-1, rand()) * 27;
                        break;

                    case 3:
                        a[2] = pow(-1, rand()) * 64;
                        break;

                    case 4:
                        a[2] = pow(-1, rand()) * 125;
                        break;
                    }
                    check = 1;
                    answer = (ZnakKub(a[2])* pow(fabs(a[2]), (1./3.)) - a[1]) / a[0];
                    if (fabs(10 * answer) - static_cast<int>(fabs(10 * answer)) != 0)
                        check = 0;
                } while (check != 1);
                cout << "\\item     Найдите корень уравнения: $(" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "x" << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << ")^3=" << SIGNUr(a[2], 1) << NumberCelUr(a[2], 1) << "$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 4:
                type_1 = rand() % 2 + 1;
                switch (type_1)
                {
                case 1:
                    do {
                        for (int i = 0; i < 4; i++)
                            a[i] = pow(-1, rand()) * (rand() % 20 + 1);
                        answer = ((a[0] / a[3]) - a[2]) / a[1];
                        check = 1;
                        if (fabs(10 * answer) - static_cast<int>(fabs(10 * answer)) != 0)
                            check = 0;
                        if (fabs(a[0]) == fabs(a[3]))
                            check = 0;
                    } while (check != 1);
                    cout << "\\item     Найдите корень уравнения: $$" << SIGNUr(a[0], 1) << "\\frac{" << NumberCelUr(a[0], 2) << "}{" << SIGNUr(a[1], 1) << NumberCelUr(a[1], 1) << "x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "}=" << a[3] << "$$" << endl;
                    //cout << "\\\\" << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 2:
                    do {
                        for (int i = 0; i < 4; i++)
                            a[i] = pow(-1, rand()) * (rand() % 20 + 1);
                        a[4] = rand() % 20 + 1;
                        del = NOD(fabs(a[3]), a[4]);
                        a[3] = a[3] / del;
                        a[4] = a[4] / del;
                        answer = (((a[0] * a[4]) / a[3]) - a[2]) / a[1];
                        check = 1;
                        if (fabs(10 * answer) - static_cast<int>(fabs(10 * answer)) != 0)
                            check = 0;
                        if (a[4] == 1)
                            check = 0;
                        if (fabs(a[0]) == fabs(a[3]))
                            check = 0;
                    } while (check != 1);
                    cout << "\\item     Найдите корень уравнения: $$" << SIGNUr(a[0], 1) << "\\frac{" << NumberCelUr(a[0], 2) << "}{" << SIGNUr(a[1], 1) << NumberCelUr(a[1], 1) << "x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "}=" << SIGNUr(a[3], 1) << "\\frac{" << fabs(a[3]) << "}{" << a[4] << "}$$" << endl;
                    //cout << "\\\\" << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;
                }
                break;
            }
        return Answer;
}

string PokUravn(int AllType)
{
                double a[4];
            string Answer;
            double answer;
            int type;
            if(AllType == 0)
                type = rand()%5+1;
            else
                type = AllType;
            int check = 0;
            switch (type)
            {
            case 1:
                do {
                    a[0] = rand() % 8 + 2;
                    a[1] = pow(-1, rand()) * (rand() % 9 + 1);
                    a[2] = pow(-1, rand()) * (rand() % 9 + 1);
                    a[3] = rand() % 9 + 1;
                    answer = (-1 * a[3] - a[2]) / a[1];
                    check = 1;
                    if (answer * 10 - static_cast<int>(10 * answer) != 0)
                        check = 0;
                    if (pow(a[0], a[3]) > 1000)
                        check = 0;
                } while (check != 1);
                cout << "\\item     Найдите корень уравнения: $$\\left(\\frac{1}{" << a[0] << "}\\right)^{" << SIGNUr(a[1], 1) << NumberCelUr(a[1], 1) << "x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "}=" << pow(a[0], a[3]) << "$$" << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 2:
                do {
                    a[0] = rand() % 8 + 2;
                    a[1] = pow(-1, rand()) * (rand() % 9 + 1);
                    a[2] = pow(-1, rand()) * (rand() % 9 + 1);
                    a[3] = rand() % 9 + 1;
                    if (-1*a[1] != a[3])
                        answer = (-1 * a[2]) / (a[1] + a[3]);
                    else
                        answer = 0.3333;
                    check = 1;
                    if (answer * 10 - static_cast<int>(10 * answer) != 0)
                        check = 0;
                } while (check != 1);
                cout << "\\item     Найдите корень уравнения: $$\\left(\\frac{1}{" << a[0] << "}\\right)^{" << SIGNUr(a[1], 1) << NumberCelUr(a[1], 1) << "x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "}=" << a[0] << "^{" << NumberCelUr(a[3],1) << "x}$$" << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 3:
                do {
                    a[0] = rand() % 8 + 2;
                    a[1] = pow(-1, rand()) * (rand() % 9 + 1);
                    a[2] = pow(-1, rand()) * (rand() % 9 + 1);
                    a[3] = rand() % 9 + 1;
                    answer = (-1 * a[3] - a[2]) / a[1];
                    check = 1;
                    if (answer * 10 - static_cast<int>(10 * answer) != 0)
                        check = 0;
                    if (pow(a[0], a[3]) > 1000)
                        check = 0;
                } while (check != 1);
                cout << "\\item     Найдите корень уравнения: $$" << a[0] << "^{" << SIGNUr(a[1], 1) << NumberCelUr(a[1], 1) << "x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "}=\\frac{1}{" << pow(a[0], a[3]) << "}$$" << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 4:
                do {
                    a[0] = rand() % 8 + 2;
                    a[1] = pow(-1, rand()) * (rand() % 9 + 1);
                    a[2] = pow(-1, rand()) * (rand() % 9 + 1);
                    a[3] = rand() % 9 + 1;
                    if (-1 * a[1] != a[3])
                        answer = (-1 * a[2]) / (a[1] + a[3]);
                    else
                        answer = 0.3333;
                    check = 1;
                    if (answer * 10 - static_cast<int>(10 * answer) != 0)
                        check = 0;
                    if (pow(a[0], a[3]) > 1000)
                        check = 0;
                } while (check != 1);
                cout << "\\item     Найдите корень уравнения: $$" << a[0] << "^{" << SIGNUr(a[1], 1) << NumberCelUr(a[1], 1) << "x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "}=\\left(\\frac{1}{" << pow(a[0],a[3]) << "}\\right)^{x}$$" << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 5:
                do {
                    a[0] = rand() % 8 + 2;
                    a[1] = pow(-1, rand()) * (rand() % 9 + 1);
                    a[2] = pow(-1, rand()) * (rand() % 9 + 1);
                    a[3] = rand() % 9 + 1;
                    answer = (a[3] - a[2]) / a[1];
                    check = 1;
                    if (answer * 10 - static_cast<int>(10 * answer) != 0)
                        check = 0;
                    if (pow(a[0], a[3]) > 1000)
                        check = 0;
                } while (check != 1);
                cout << "\\item     Найдите корень уравнения: $$" << a[0] << "^{" << SIGNUr(a[1], 1) << NumberCelUr(a[1], 1) << "x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "}=" << pow(a[0], a[3]) << "$$" << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;
            }
            return Answer;
}

string LogUravn(int AllType)
{
                double a[4];
            double answer;
            int type;
            if(AllType == 0)
                type = rand()%4+1;
            else
                type = AllType;
            int check = 0;
            string Answer;
            switch (type)
            {
            case 1:
                do {
                    a[0] = rand() % 15 + 2;
                    for (int i = 1; i < 3; i++)
                        a[i] = pow(-1, rand()) * (rand() % 15 + 1);
                    a[3] = rand() % 15 + 1;
                    answer = (a[1] - a[3]) / (-1 * a[2]);
                    check = 1;
                    if (10 * fabs(answer) - static_cast<int>(10 * fabs(answer)) != 0)
                        check = 0;
                    if ((a[1] + a[2] * answer) < 0)
                        check = 0;
                } while (check != 1);
                cout << "\\item     Найдите корень уравнения: $\\log_{" << a[0] << "}(" << a[1] << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "x)=\\log_{" << a[0] << "}{" << a[3] << "}$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 2:
                do {
                    a[0] = rand() % 20 + 2;
                    a[3] = rand() % 15 + 1;
                    a[1] = pow(-1, rand()) * (rand() % 15 + 1);
                    a[2] = pow(-1, rand()) * (rand() % 15 + 1);
                    answer = (a[3] - a[2]) / a[1];
                    check = 1;
                    if (fabs(10 * answer) - static_cast<int>(fabs(10 * answer)) != 0)
                        check = 0;
                    if (a[1] * answer + a[2] < 0)
                        check = 0;
                } while (check != 1);
                cout << "\\item     Найдите корень уравнения: $\\log_{" << a[0] << "}(" << SIGNUr(a[1], 1) << NumberCelUr(a[1], 1) << "x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << ")=\\log_{" << a[0] << "}{" << a[3] << "}$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 3:
                do {
                    a[0] = rand() % 15 + 2;
                    for (int i = 1; i < 3; i++)
                        a[i] = pow(-1, rand()) * (rand() % 15 + 1);
                    a[3] = rand() % 15 + 1;
                    answer = (a[1] - pow(a[0],a[3])) / (-1 * a[2]);
                    check = 1;
                    if (10 * fabs(answer) - static_cast<int>(10 * fabs(answer)) != 0)
                        check = 0;
                    if ((a[1] + a[2] * answer) < 0)
                        check = 0;
                    if (fabs(answer) > 1000)
                        check = 0;
                } while (check != 1);
                cout << "\\item     Найдите корень уравнения: $\\log_{" << a[0] << "}(" << a[1] << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "x)= " << a[3] << "$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 4:
                do {
                    a[0] = rand() % 20 + 2;
                    a[3] = rand() % 15 + 1;
                    a[1] = pow(-1, rand()) * (rand() % 15 + 1);
                    a[2] = pow(-1, rand()) * (rand() % 15 + 1);
                    answer = (pow(a[0],a[3]) - a[2]) / a[1];
                    check = 1;
                    if (fabs(10 * answer) - static_cast<int>(fabs(10 * answer)) != 0)
                        check = 0;
                    if (a[1] * answer + a[2] < 0)
                        check = 0;
                    if (fabs(answer) > 1000)
                        check = 0;
                } while (check != 1);
                cout << "\\item     Найдите корень уравнения: $\\log_{" << a[0] << "}(" << SIGNUr(a[1], 1) << NumberCelUr(a[1], 1) << "x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << ")=" << a[3] << "$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;
            }
            return Answer;
}

string Treugol(int i, int AllType)
{
    double a, b, c, max, k, chisl, znam, S, h1, h2, h;
            double alpha, betta;
            int type;
            string Answer;
            string AB;
            double answer;
            int nod;
            int check = 0;
            int type_main;
            if(AllType == 0)
                type_main = rand()%5 + 1;
            else
                type_main = AllType;
            switch (type_main)
            {
            case 1:     // Тригонометрия
                type = rand() % 18 + 1;
                switch (type)
                {
                case 1: // sinA
                    do {
                        b = rand() % 90 + 9;
                        c = rand() % 99 + 9;
                        check = 1;
                        if (c > b)
                        {
                            answer = b / c;
                            if ((100 * answer) - (static_cast<int>(100 * b / c)) != 0)
                                check = 0;
                        }
                        else
                        {
                            check = 0;
                        }
                    } while (check != 1);
                    if (b > sqrt(c * c - b * b))
                        max = b;
                    else
                        max = sqrt(c * c - b * b);
                    k = max / 2.2;
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        В треугольнике $ABC$ угол $C$ равен $90^{\\circ}$, $BC=" << b << "$, $AB=" << c << "$. Найдите $\\sin(A)$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$C$]   (C) at (0,0);" << endl
                        << "            \\coordinate[label=below:$A$] (A) at (180:" << (sqrt(pow(c, 2) - pow(b, 2)) / k) << ");" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (90:" << (b / k) << ");" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A);" << endl
                        << "            \\tkzMarkRightAngle(A,C,B);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 2:     // sinB
                    do {
                        a = rand() % 90 + 9;
                        c = rand() % 99 + 9;
                        check = 1;
                        if (c > a)
                        {
                            answer = a / c;
                            if ((100 * answer) - (static_cast<int>(100 * a / c)) != 0)
                                check = 0;
                        }
                        else
                        {
                            check = 0;
                        }
                    } while (check != 1);
                    if (a > sqrt(c * c - a * a))
                        max = a;
                    else
                        max = sqrt(c * c - a * a);
                    k = max / 2.2;
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        В треугольнике $ABC$ угол $C$ равен $90^{\\circ}$, $AC=" << a << "$, $AB=" << c << "$. Найдите $\\sin(B)$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$C$]   (C) at (0,0);" << endl
                        << "            \\coordinate[label=below:$A$] (A) at (180:" << (a / k) << ");" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (90:" << (sqrt(pow(c, 2) - pow(a, 2)) / k) << ");" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A);" << endl
                        << "            \\tkzMarkRightAngle(A,C,B);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 3:     //cosA
                    do {
                        a = rand() % 90 + 9;
                        c = rand() % 99 + 9;
                        check = 1;
                        if (c > a)
                        {
                            answer = a / c;
                            if ((100 * answer) - (static_cast<int>(100 * a / c)) != 0)
                                check = 0;
                        }
                        else
                        {
                            check = 0;
                        }
                    } while (check != 1);
                    if (a > sqrt(c * c - a * a))
                        max = a;
                    else
                        max = sqrt(c * c - a * a);
                    k = max / 2.2;
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        В треугольнике $ABC$ угол $C$ равен $90^{\\circ}$, $AC=" << a << "$, $AB=" << c << "$. Найдите $\\cos(A)$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$C$]   (C) at (0,0);" << endl
                        << "            \\coordinate[label=below:$A$] (A) at (180:" << (a / k) << ");" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (90:" << (sqrt(pow(c, 2) - pow(a, 2)) / k) << ");" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A);" << endl
                        << "            \\tkzMarkRightAngle(A,C,B);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 4:
                    do {
                        b = rand() % 90 + 9;
                        c = rand() % 99 + 9;
                        check = 1;
                        if (c > b)
                        {
                            answer = b / c;
                            if ((100 * answer) - (static_cast<int>(100 * b / c)) != 0)
                                check = 0;
                        }
                        else
                        {
                            check = 0;
                        }
                    } while (check != 1);
                    if (b > sqrt(c * c - b * b))
                        max = b;
                    else
                        max = sqrt(c * c - b * b);
                    k = max / 2.2;
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        В треугольнике $ABC$ угол $C$ равен $90^{\\circ}$, $BC=" << b << "$, $AB=" << c << "$. Найдите $\\cos(B)$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$C$]   (C) at (0,0);" << endl
                        << "            \\coordinate[label=below:$A$] (A) at (180:" << (sqrt(pow(c, 2) - pow(b, 2)) / k) << ");" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (90:" << (b / k) << ");" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A);" << endl
                        << "            \\tkzMarkRightAngle(A,C,B);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 5:     // tgA
                    do {
                        a = rand() % 90 + 9;
                        b = rand() % 90 + 9;
                        answer = b / a;
                        check = 1;
                        if (100 * answer - static_cast<int>(100 * answer) != 0)
                            check = 0;
                    } while (check != 1);
                    if (b > a)
                        max = b;
                    else
                        max = a;
                    k = max / 2.2;
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        В треугольнике $ABC$ угол $C$ равен $90^{\\circ}$, $BC=" << b << "$, $AC=" << a << "$. Найдите $\\tg(A)$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$C$]   (C) at (0,0);" << endl
                        << "            \\coordinate[label=below:$A$] (A) at (180:" << (a / k) << ");" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (90:" << (b / k) << ");" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A);" << endl
                        << "            \\tkzMarkRightAngle(A,C,B);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 6:         // tgB
                    do {
                        a = rand() % 90 + 9;
                        b = rand() % 90 + 9;
                        answer = a / b;
                        check = 1;
                        if (100 * answer - static_cast<int>(100 * answer) != 0)
                            check = 0;
                    } while (check != 1);
                    if (b > a)
                        max = b;
                    else
                        max = a;
                    k = max / 2.2;
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        В треугольнике $ABC$ угол $C$ равен $90^{\\circ}$, $BC=" << b << "$, $AC=" << a << "$. Найдите $\\tg(B)$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$C$]   (C) at (0,0);" << endl
                        << "            \\coordinate[label=below:$A$] (A) at (180:" << (a / k) << ");" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (90:" << (b / k) << ");" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A);" << endl
                        << "            \\tkzMarkRightAngle(A,C,B);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 7:     // sinA kat
                    do {
                        c = rand() % 90 + 9;
                        znam = rand() % 20 + 1;
                        chisl = rand() % 20 + 1;
                        nod = NOD(znam, chisl);
                        znam = znam / nod;
                        chisl = chisl / nod;
                        b = (c * chisl) / znam;
                        a = sqrt(pow(c, 2) - pow(b, 2));
                        check = 1;
                        if (a == c)
                            check = 0;
                        if (chisl > znam)
                            check = 0;
                        if ((b - static_cast<int>(b)) != 0)
                            check = 0;
                        if (a < 1)
                            check = 0;
                    } while (check != 1);
                    if (b > a)
                        max = b;
                    else
                        max = a;
                    k = max / 2.2;
                    answer = b;
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        В треугольнике $ABC$ угол $C$ равен $90^{\\circ}$, $\\sin(A)=\\frac{" << chisl << "}{" << znam << "}$, $AB=" << c << "$. Найдите $BC$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$C$]   (C) at (0,0);" << endl
                        << "            \\coordinate[label=below:$A$] (A) at (180:" << (a / k) << ");" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (90:" << (b / k) << ");" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A);" << endl
                        << "            \\tkzMarkRightAngle(A,C,B);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 8:     //sinA gip
                    do {
                        b = rand() % 90 + 9;
                        znam = rand() % 20 + 1;
                        chisl = rand() % 20 + 1;
                        nod = NOD(znam, chisl);
                        znam = znam / nod;
                        chisl = chisl / nod;
                        c = b * znam / chisl;
                        a = sqrt(pow(c, 2) - pow(b, 2));
                        check = 1;
                        if (a == c)
                            check = 0;
                        if (chisl > znam)
                            check = 0;
                        if ((c - static_cast<int>(c)) != 0)
                            check = 0;
                        if (b > a)
                            max = b;
                        else
                            max = a;
                        k = max / 2.2;
                        if (b / k < 1)
                            check = 0;
                        if (a / k < 1)
                            check = 0;
                    } while (check != 1);
                    answer = c;
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        В треугольнике $ABC$ угол $C$ равен $90^{\\circ}$, $\\sin(A)=\\frac{" << chisl << "}{" << znam << "}$, $BC=" << b << "$. Найдите $AB$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$C$]   (C) at (0,0);" << endl
                        << "            \\coordinate[label=below:$A$] (A) at (180:" << (a / k) << ");" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (90:" << (b / k) << ");" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A);" << endl
                        << "            \\tkzMarkRightAngle(A,C,B);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 9:         // sinB kat
                    do {
                        c = rand() % 90 + 9;
                        znam = rand() % 20 + 1;
                        chisl = rand() % 20 + 1;
                        nod = NOD(znam, chisl);
                        znam = znam / nod;
                        chisl = chisl / nod;
                        a = (c * chisl) / znam;
                        b = sqrt(pow(c, 2) - pow(a, 2));
                        check = 1;
                        if (b == 0)
                            check = 0;
                        if (chisl > znam)
                            check = 0;
                        if ((a - static_cast<int>(a)) != 0)
                            check = 0;
                        if (b > a)
                            max = b;
                        else
                            max = a;
                        k = max / 2.2;
                        if (b / k < 1)
                            check = 0;
                        if (a / k < 1)
                            check = 0;
                    } while (check != 1);
                    answer = a;
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        В треугольнике $ABC$ угол $C$ равен $90^{\\circ}$, $\\sin(B)=\\frac{" << chisl << "}{" << znam << "}$, $AB=" << c << "$. Найдите $AC$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$C$]   (C) at (0,0);" << endl
                        << "            \\coordinate[label=below:$A$] (A) at (180:" << (a / k) << ");" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (90:" << (b / k) << ");" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A);" << endl
                        << "            \\tkzMarkRightAngle(A,C,B);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 10:        // sin B gip
                    do {
                        a = rand() % 90 + 9;
                        znam = rand() % 20 + 1;
                        chisl = rand() % 20 + 1;
                        nod = NOD(znam, chisl);
                        znam = znam / nod;
                        chisl = chisl / nod;
                        c = a * znam / chisl;
                        b = sqrt(pow(c, 2) - pow(a, 2));
                        check = 1;
                        if (b == 0)
                            check = 0;
                        if (chisl > znam)
                            check = 0;
                        if ((c - static_cast<int>(c)) != 0)
                            check = 0;
                        if (b > a)
                            max = b;
                        else
                            max = a;
                        k = max / 2.2;
                        if (b / k < 1)
                            check = 0;
                        if (a / k < 1)
                            check = 0;
                    } while (check != 1);
                    answer = c;
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        В треугольнике $ABC$ угол $C$ равен $90^{\\circ}$, $\\sin(B)=\\frac{" << chisl << "}{" << znam << "}$, $AC=" << a << "$. Найдите $AB$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$C$]   (C) at (0,0);" << endl
                        << "            \\coordinate[label=below:$A$] (A) at (180:" << (a / k) << ");" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (90:" << (b / k) << ");" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A);" << endl
                        << "            \\tkzMarkRightAngle(A,C,B);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 11:        // Сторона по косинусу
                    do {
                        c = rand() % 90 + 9;
                        znam = rand() % 20 + 1;
                        chisl = rand() % 20 + 1;
                        nod = NOD(znam, chisl);
                        znam = znam / nod;
                        chisl = chisl / nod;
                        b = (c * chisl) / znam;
                        a = sqrt(pow(c, 2) - pow(b, 2));
                        check = 1;
                        if (a == c)
                            check = 0;
                        if (chisl > znam)
                            check = 0;
                        if ((b - static_cast<int>(b)) != 0)
                            check = 0;
                        if (b > a)
                            max = b;
                        else
                            max = a;
                        k = max / 2.2;
                        if (b / k < 1)
                            check = 0;
                        if (a / k < 1)
                            check = 0;
                    } while (check != 1);
                    answer = b;
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        В треугольнике $ABC$ угол $C$ равен $90^{\\circ}$, $\\cos(B)=\\frac{" << chisl << "}{" << znam << "}$, $AB=" << c << "$. Найдите $BC$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$C$]   (C) at (0,0);" << endl
                        << "            \\coordinate[label=below:$A$] (A) at (180:" << (a / k) << ");" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (90:" << (b / k) << ");" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A);" << endl
                        << "            \\tkzMarkRightAngle(A,C,B);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 12:    // Сторона по косинусу
                    do {
                        b = rand() % 90 + 9;
                        znam = rand() % 20 + 1;
                        chisl = rand() % 20 + 1;
                        nod = NOD(znam, chisl);
                        znam = znam / nod;
                        chisl = chisl / nod;
                        c = b * znam / chisl;
                        a = sqrt(pow(c, 2) - pow(b, 2));
                        check = 1;
                        if (a == c)
                            check = 0;
                        if (chisl > znam)
                            check = 0;
                        if ((c - static_cast<int>(c)) != 0)
                            check = 0;
                        if (b > a)
                            max = b;
                        else
                            max = a;
                        k = max / 2.2;
                        if (b / k < 1)
                            check = 0;
                        if (a / k < 1)
                            check = 0;
                    } while (check != 1);
                    answer = c;
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        В треугольнике $ABC$ угол $C$ равен $90^{\\circ}$, $\\cos(B)=\\frac{" << chisl << "}{" << znam << "}$, $BC=" << b << "$. Найдите $AB$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$C$]   (C) at (0,0);" << endl
                        << "            \\coordinate[label=below:$A$] (A) at (180:" << (a / k) << ");" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (90:" << (b / k) << ");" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A);" << endl
                        << "            \\tkzMarkRightAngle(A,C,B);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 13:    // Сторона по косинусу
                    do {
                        c = rand() % 90 + 9;
                        znam = rand() % 20 + 1;
                        chisl = rand() % 20 + 1;
                        nod = NOD(znam, chisl);
                        znam = znam / nod;
                        chisl = chisl / nod;
                        a = (c * chisl) / znam;
                        b = sqrt(pow(c, 2) - pow(a, 2));
                        check = 1;
                        if (b == 0)
                            check = 0;
                        if (chisl > znam)
                            check = 0;
                        if ((a - static_cast<int>(a)) != 0)
                            check = 0;
                        if (b > a)
                            max = b;
                        else
                            max = a;
                        k = max / 2.2;
                        if (b / k < 1)
                            check = 0;
                        if (a / k < 1)
                            check = 0;
                    } while (check != 1);
                    answer = a;
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        В треугольнике $ABC$ угол $C$ равен $90^{\\circ}$, $\\cos(A)=\\frac{" << chisl << "}{" << znam << "}$, $AB=" << c << "$. Найдите $AC$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$C$]   (C) at (0,0);" << endl
                        << "            \\coordinate[label=below:$A$] (A) at (180:" << (a / k) << ");" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (90:" << (b / k) << ");" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A);" << endl
                        << "            \\tkzMarkRightAngle(A,C,B);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 14:    // Сторона по косинусу
                    do {
                        a = rand() % 90 + 9;
                        znam = rand() % 20 + 1;
                        chisl = rand() % 20 + 1;
                        nod = NOD(znam, chisl);
                        znam = znam / nod;
                        chisl = chisl / nod;
                        c = a * znam / chisl;
                        b = sqrt(pow(c, 2) - pow(a, 2));
                        check = 1;
                        if (b == 0)
                            check = 0;
                        if (chisl > znam)
                            check = 0;
                        if ((c - static_cast<int>(c)) != 0)
                            check = 0;
                        if (b > a)
                            max = b;
                        else
                            max = a;
                        k = max / 2.2;
                        if (b / k < 1)
                            check = 0;
                        if (a / k < 1)
                            check = 0;
                    } while (check != 1);
                    answer = c;
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        В треугольнике $ABC$ угол $C$ равен $90^{\\circ}$, $\\cos(A)=\\frac{" << chisl << "}{" << znam << "}$, $AC=" << a << "$. Найдите $AB$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$C$]   (C) at (0,0);" << endl
                        << "            \\coordinate[label=below:$A$] (A) at (180:" << (a / k) << ");" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (90:" << (b / k) << ");" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A);" << endl
                        << "            \\tkzMarkRightAngle(A,C,B);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 15:    // Сторона по тангенсу
                    do {
                        a = rand() % 90 + 9;
                        znam = rand() % 20 + 1;
                        chisl = rand() % 20 + 1;
                        nod = NOD(znam, chisl);
                        znam = znam / nod;
                        chisl = chisl / nod;
                        check = 1;
                        b = a * chisl / znam;
                        if ((b - static_cast<int>(b)) != 0)
                            check = 0;
                        if (b > a)
                            max = b;
                        else
                            max = a;
                        if (znam == 1)
                            check = 0;
                        k = max / 2.2;
                        if (b / k < 1)
                            check = 0;
                        if (a / k < 1)
                            check = 0;
                    } while (check != 1);
                    answer = b;
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        В треугольнике $ABC$ угол $C$ равен $90^{\\circ}$, $\\tg(A)=\\frac{" << chisl << "}{" << znam << "}$, $AC=" << a << "$. Найдите $BC$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$C$]   (C) at (0,0);" << endl
                        << "            \\coordinate[label=below:$A$] (A) at (180:" << (a / k) << ");" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (90:" << (b / k) << ");" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A);" << endl
                        << "            \\tkzMarkRightAngle(A,C,B);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 16:    // Сторона по тангенсу
                    do {
                        b = rand() % 90 + 9;
                        znam = rand() % 20 + 1;
                        chisl = rand() % 20 + 1;
                        nod = NOD(znam, chisl);
                        znam = znam / nod;
                        chisl = chisl / nod;
                        check = 1;
                        a = b * znam / chisl;
                        if ((a - static_cast<int>(a)) != 0)
                            check = 0;
                        if (b > a)
                            max = b;
                        else
                            max = a;
                        if (znam == 1)
                            check = 0;
                        k = max / 2.2;
                        if (b / k < 1)
                            check = 0;
                        if (a / k < 1)
                            check = 0;
                    } while (check != 1);
                    answer = a;
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        В треугольнике $ABC$ угол $C$ равен $90^{\\circ}$, $\\tg(A)=\\frac{" << chisl << "}{" << znam << "}$, $BC=" << b << "$. Найдите $AC$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$C$]   (C) at (0,0);" << endl
                        << "            \\coordinate[label=below:$A$] (A) at (180:" << (a / k) << ");" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (90:" << (b / k) << ");" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A);" << endl
                        << "            \\tkzMarkRightAngle(A,C,B);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 17:    // Сторона по тангенсу
                    do {
                        b = rand() % 90 + 9;
                        znam = rand() % 20 + 1;
                        chisl = rand() % 20 + 1;
                        nod = NOD(znam, chisl);
                        znam = znam / nod;
                        chisl = chisl / nod;
                        check = 1;
                        a = b * chisl / znam;
                        if ((a - static_cast<int>(a)) != 0)
                            check = 0;
                        if (b > a)
                            max = b;
                        else
                            max = a;
                        if (znam == 1)
                            check = 0;
                        k = max / 2.2;
                        if (b / k < 1)
                            check = 0;
                        if (a / k < 1)
                            check = 0;
                    } while (check != 1);
                    answer = a;
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        В треугольнике $ABC$ угол $C$ равен $90^{\\circ}$, $\\tg(B)=\\frac{" << chisl << "}{" << znam << "}$, $BC=" << b << "$. Найдите $AC$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$C$]   (C) at (0,0);" << endl
                        << "            \\coordinate[label=below:$A$] (A) at (180:" << (a / k) << ");" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (90:" << (b / k) << ");" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A);" << endl
                        << "            \\tkzMarkRightAngle(A,C,B);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 18:    // Сторона по тангенсу
                    do {
                        a = rand() % 90 + 9;
                        znam = rand() % 20 + 1;
                        chisl = rand() % 20 + 1;
                        nod = NOD(znam, chisl);
                        znam = znam / nod;
                        chisl = chisl / nod;
                        check = 1;
                        b = a * znam / chisl;
                        if ((b - static_cast<int>(b)) != 0)
                            check = 0;
                        if (b > a)
                            max = b;
                        else
                            max = a;
                        if (znam == 1)
                            check = 0;
                        k = max / 2.2;
                        if (b / k < 1)
                            check = 0;
                        if (a / k < 1)
                            check = 0;
                    } while (check != 1);
                    answer = b;
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        В треугольнике $ABC$ угол $C$ равен $90^{\\circ}$, $\\tg(B)=\\frac{" << chisl << "}{" << znam << "}$, $AC=" << a << "$. Найдите $BC$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$C$]   (C) at (0,0);" << endl
                        << "            \\coordinate[label=below:$A$] (A) at (180:" << (a / k) << ");" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (90:" << (b / k) << ");" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A);" << endl
                        << "            \\tkzMarkRightAngle(A,C,B);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;


                }
                break;

            case 2:     // Средняя линия по основанию и площади
                type = rand() % 7 + 1;
                switch (type)
                {
                case 1: // Средняя линия
                    do {
                        a = rand() % 100 + 1;
                        b = rand() % 100 + 1;
                        c = rand() % 100 + 1;
                        check = 1;
                        if (((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b) < 1) && ((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b) > 0))
                        {
                            alpha = acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b));
                            alpha = 180 * alpha / PI;
                            if (alpha > 70)
                                check = 0;
                        }
                        else
                            check = 0;
                        answer = a / 2;
                        if (a >= b)
                            max = a;
                        else
                            max = b;
                        if (c >= max)
                            max = c;
                        k = max / 2.2;
                        if ((a / k) < 1.3)
                            check = 0;
                        if ((b / k) < 1.3)
                            check = 0;
                        if ((c / k) < 1.3)
                            check = 0;
                    } while (check != 1);
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        Точки $M$ и $N$ являются серединами сторон $AB$ и $BC$ треугольника $ABC$, сторона $AB$ равна " << b << ", сторона $BC$ равна " << c << ", сторона $AC$ равна " << a << ". Найдите $MN$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$A$]   (A) at (0,0);" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (" << alpha << ":" << (b / k) << ");" << endl
                        << "            \\coordinate[label=below:$C$] (C) at (0:" << (a / k) << ");" << endl
                        << "            \\coordinate[label=left:$M$] (M) at ($(A)!0.5!(B)$);" << endl
                        << "            \\coordinate[label=right:$N$] (N) at ($(C)!0.5!(B)$);" << endl
                        << "            \\tkzMarkSegment[mark=|](A,M);" << endl
                        << "            \\tkzMarkSegment[mark=|](B,M);" << endl
                        << "            \\tkzMarkSegment[mark=||](N,B);" << endl
                        << "            \\tkzMarkSegment[mark=||](C,N);" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A) -- (M) -- (N);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 2:
                    do {
                        a = rand() % 100 + 1;
                        b = rand() % 100 + 1;
                        c = rand() % 100 + 1;
                        check = 1;
                        if (((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b) < 1) && ((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b) > 0))
                        {
                            alpha = acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b));
                            alpha = 180 * alpha / PI;
                            if (alpha > 70)
                                check = 0;
                        }
                        else
                            check = 0;
                        answer = a / 2;
                        if (a >= b)
                            max = a;
                        else
                            max = b;
                        if (c >= max)
                            max = c;
                        k = max / 2.2;
                        if ((a / k) < 1.3)
                            check = 0;
                        if ((b / k) < 1.3)
                            check = 0;
                        if ((c / k) < 1.3)
                            check = 0;
                        S = rand() % 100 + 2;
                        answer = S / 4;
                        if (answer - static_cast<int>(answer) != 0)
                            check = 0;
                    } while (check != 1);
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        Точки $M$ и $N$ являются серединами сторон $AB$ и $BC$ треугольника $ABC$. Площадь $ABC$ равна " << S << ". Найдите площадь треугольника $MBN$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$A$]   (A) at (0,0);" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (" << alpha << ":" << (b / k) << ");" << endl
                        << "            \\coordinate[label=below:$C$] (C) at (0:" << (a / k) << ");" << endl
                        << "            \\coordinate[label=left:$M$] (M) at ($(A)!0.5!(B)$);" << endl
                        << "            \\coordinate[label=right:$N$] (N) at ($(C)!0.5!(B)$);" << endl
                        << "            \\tkzMarkSegment[mark=|](A,M);" << endl
                        << "            \\tkzMarkSegment[mark=|](B,M);" << endl
                        << "            \\tkzMarkSegment[mark=||](N,B);" << endl
                        << "            \\tkzMarkSegment[mark=||](C,N);" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A) -- (M) -- (N);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 3:
                    do {
                        a = rand() % 100 + 1;
                        b = rand() % 100 + 1;
                        c = rand() % 100 + 1;
                        check = 1;
                        if (((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b) < 1) && ((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b) > 0))
                        {
                            alpha = acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b));
                            alpha = 180 * alpha / PI;
                            if (alpha > 70)
                                check = 0;
                        }
                        else
                            check = 0;
                        answer = a / 2;
                        if (a >= b)
                            max = a;
                        else
                            max = b;
                        if (c >= max)
                            max = c;
                        k = max / 2.2;
                        if ((a / k) < 1.3)
                            check = 0;
                        if ((b / k) < 1.3)
                            check = 0;
                        if ((c / k) < 1.3)
                            check = 0;
                        S = rand() % 100 + 2;
                        answer = 3 * S / 4;
                        if (answer - static_cast<int>(answer) != 0)
                            check = 0;
                    } while (check != 1);
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        Точки $M$ и $N$ являются серединами сторон $AB$ и $BC$ треугольника $ABC$. Площадь $ABC$ равна " << S << ". Найдите площадь трапеции $AMNC$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$A$]   (A) at (0,0);" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (" << alpha << ":" << (b / k) << ");" << endl
                        << "            \\coordinate[label=below:$C$] (C) at (0:" << (a / k) << ");" << endl
                        << "            \\coordinate[label=left:$M$] (M) at ($(A)!0.5!(B)$);" << endl
                        << "            \\coordinate[label=right:$N$] (N) at ($(C)!0.5!(B)$);" << endl
                        << "            \\tkzMarkSegment[mark=|](A,M);" << endl
                        << "            \\tkzMarkSegment[mark=|](B,M);" << endl
                        << "            \\tkzMarkSegment[mark=||](N,B);" << endl
                        << "            \\tkzMarkSegment[mark=||](C,N);" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A) -- (M) -- (N);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 4:
                    do {
                        a = rand() % 100 + 1;
                        b = rand() % 100 + 1;
                        c = rand() % 100 + 1;
                        check = 1;
                        if (((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b) < 1) && ((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b) > 0))
                        {
                            alpha = acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b));
                            alpha = 180 * alpha / PI;
                            if (alpha > 70)
                                check = 0;
                        }
                        else
                            check = 0;
                        answer = a / 2;
                        if (a >= b)
                            max = a;
                        else
                            max = b;
                        if (c >= max)
                            max = c;
                        k = max / 2.2;
                        if ((a / k) < 1.3)
                            check = 0;
                        if ((b / k) < 1.3)
                            check = 0;
                        if ((c / k) < 1.3)
                            check = 0;
                        S = rand() % 20 + 2;
                        answer = 4 * S;
                        if (answer - static_cast<int>(answer) != 0)
                            check = 0;
                    } while (check != 1);
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        Точки $M$ и $N$ являются серединами сторон $AB$ и $BC$ треугольника $ABC$. Площадь $MBN$ равна " << S << ". Найдите площадь треугольника $ABC$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$A$]   (A) at (0,0);" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (" << alpha << ":" << (b / k) << ");" << endl
                        << "            \\coordinate[label=below:$C$] (C) at (0:" << (a / k) << ");" << endl
                        << "            \\coordinate[label=left:$M$] (M) at ($(A)!0.5!(B)$);" << endl
                        << "            \\coordinate[label=right:$N$] (N) at ($(C)!0.5!(B)$);" << endl
                        << "            \\tkzMarkSegment[mark=|](A,M);" << endl
                        << "            \\tkzMarkSegment[mark=|](B,M);" << endl
                        << "            \\tkzMarkSegment[mark=||](N,B);" << endl
                        << "            \\tkzMarkSegment[mark=||](C,N);" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A) -- (M) -- (N);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 5:
                    do {
                        a = rand() % 100 + 1;
                        b = rand() % 100 + 1;
                        c = rand() % 100 + 1;
                        check = 1;
                        if (((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b) < 1) && ((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b) > 0))
                        {
                            alpha = acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b));
                            alpha = 180 * alpha / PI;
                            if (alpha > 70)
                                check = 0;
                        }
                        else
                            check = 0;
                        answer = a / 2;
                        if (a >= b)
                            max = a;
                        else
                            max = b;
                        if (c >= max)
                            max = c;
                        k = max / 2.2;
                        if ((a / k) < 1.3)
                            check = 0;
                        if ((b / k) < 1.3)
                            check = 0;
                        if ((c / k) < 1.3)
                            check = 0;
                        S = rand() % 20 + 2;
                        answer = 3 * S;
                        if (answer - static_cast<int>(answer) != 0)
                            check = 0;
                    } while (check != 1);
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        Точки $M$ и $N$ являются серединами сторон $AB$ и $BC$ треугольника $ABC$. Площадь $MBN$ равна " << S << ". Найдите площадь трапеции $AMNC$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$A$]   (A) at (0,0);" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (" << alpha << ":" << (b / k) << ");" << endl
                        << "            \\coordinate[label=below:$C$] (C) at (0:" << (a / k) << ");" << endl
                        << "            \\coordinate[label=left:$M$] (M) at ($(A)!0.5!(B)$);" << endl
                        << "            \\coordinate[label=right:$N$] (N) at ($(C)!0.5!(B)$);" << endl
                        << "            \\tkzMarkSegment[mark=|](A,M);" << endl
                        << "            \\tkzMarkSegment[mark=|](B,M);" << endl
                        << "            \\tkzMarkSegment[mark=||](N,B);" << endl
                        << "            \\tkzMarkSegment[mark=||](C,N);" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A) -- (M) -- (N);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 6:
                    do {
                        a = rand() % 100 + 1;
                        b = rand() % 100 + 1;
                        c = rand() % 100 + 1;
                        check = 1;
                        if (((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b) < 1) && ((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b) > 0))
                        {
                            alpha = acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b));
                            alpha = 180 * alpha / PI;
                            if (alpha > 70)
                                check = 0;
                        }
                        else
                            check = 0;
                        answer = a / 2;
                        if (a >= b)
                            max = a;
                        else
                            max = b;
                        if (c >= max)
                            max = c;
                        k = max / 2.2;
                        if ((a / k) < 1.3)
                            check = 0;
                        if ((b / k) < 1.3)
                            check = 0;
                        if ((c / k) < 1.3)
                            check = 0;
                        S = rand() % 70 + 2;
                        answer = S / 3;
                        if (answer - static_cast<int>(answer) != 0)
                            check = 0;
                    } while (check != 1);
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        Точки $M$ и $N$ являются серединами сторон $AB$ и $BC$ треугольника $ABC$. Площадь $AMNC$ равна " << S << ". Найдите площадь треугольника $MBN$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$A$]   (A) at (0,0);" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (" << alpha << ":" << (b / k) << ");" << endl
                        << "            \\coordinate[label=below:$C$] (C) at (0:" << (a / k) << ");" << endl
                        << "            \\coordinate[label=left:$M$] (M) at ($(A)!0.5!(B)$);" << endl
                        << "            \\coordinate[label=right:$N$] (N) at ($(C)!0.5!(B)$);" << endl
                        << "            \\tkzMarkSegment[mark=|](A,M);" << endl
                        << "            \\tkzMarkSegment[mark=|](B,M);" << endl
                        << "            \\tkzMarkSegment[mark=||](N,B);" << endl
                        << "            \\tkzMarkSegment[mark=||](C,N);" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A) -- (M) -- (N);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 7:
                    do {
                        a = rand() % 100 + 1;
                        b = rand() % 100 + 1;
                        c = rand() % 100 + 1;
                        check = 1;
                        if (((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b) < 1) && ((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b) > 0))
                        {
                            alpha = acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b));
                            alpha = 180 * alpha / PI;
                            if (alpha > 70)
                                check = 0;
                        }
                        else
                            check = 0;
                        answer = a / 2;
                        if (a >= b)
                            max = a;
                        else
                            max = b;
                        if (c >= max)
                            max = c;
                        k = max / 2.2;
                        if ((a / k) < 1.3)
                            check = 0;
                        if ((b / k) < 1.3)
                            check = 0;
                        if ((c / k) < 1.3)
                            check = 0;
                        S = rand() % 70 + 2;
                        answer = 4 * S / 3;
                        if (answer - static_cast<int>(answer) != 0)
                            check = 0;
                    } while (check != 1);
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        Точки $M$ и $N$ являются серединами сторон $AB$ и $BC$ треугольника $ABC$. Площадь $AMNC$ равна " << S << ". Найдите площадь треугольника $ABC$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$A$]   (A) at (0,0);" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (" << alpha << ":" << (b / k) << ");" << endl
                        << "            \\coordinate[label=below:$C$] (C) at (0:" << (a / k) << ");" << endl
                        << "            \\coordinate[label=left:$M$] (M) at ($(A)!0.5!(B)$);" << endl
                        << "            \\coordinate[label=right:$N$] (N) at ($(C)!0.5!(B)$);" << endl
                        << "            \\tkzMarkSegment[mark=|](A,M);" << endl
                        << "            \\tkzMarkSegment[mark=|](B,M);" << endl
                        << "            \\tkzMarkSegment[mark=||](N,B);" << endl
                        << "            \\tkzMarkSegment[mark=||](C,N);" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A) -- (M) -- (N);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;
                }
                break;

            case 3:     // Высота по двум сторонам и второй высоте
                do {
                    alpha = rand() % 40 + 30;
                    betta = rand() % 40 + 30;
                    a = rand() % 70 + 2;
                    b = rand() % 70 + 2;
                    if (a > b)
                        k = a / 2.3;
                    else
                        k = b / 2.3;
                    h1 = static_cast<int>(a * sin((180 - alpha - betta) * PI / 180));
                    h2 = h1 * b / a;
                    check = 1;
                    if (h2 - static_cast<int>(h2) != 0)
                        check = 0;
                    if ((180 - alpha - betta) > 80)
                        check = 0;
                    if ((a * cos((180 - alpha - betta) * PI / 180)) / k < 0.7)
                        check = 0;
                    if ((b * cos((180 - alpha - betta) * PI / 180)) / k < 0.7)
                        check = 0;
                    if ((b * cos((180 - alpha - betta) * PI / 180)) > a)
                        check = 0;
                    if ((a * cos((180 - alpha - betta) * PI / 180)) > b)
                        check = 0;
                    if ((b - a * cos((180 - alpha - betta) * PI / 180)) / k < 0.2)
                        check = 0;
                    if ((a - b * cos((180 - alpha - betta) * PI / 180)) / k < 0.2)
                        check = 0;
                    if (a == b)
                        check = 0;
                } while (check != 1);
                if (h1 > h2)
                {
                    answer = h1;
                    c = h2;
                }
                else
                {
                    answer = h2;
                    c = h1;
                }
                cout << "%" << (i + 1) << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        Две стороны треугольника равны " << a << " и " << b << ". Высота, опущенная на большую их этих двух сторон, равна " << c << ". Найдите длину высоты, опущенной на меньшую из этих сторон треугольника." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\coordinate (A) at (0,0);" << endl
                    << "            \\coordinate (B) at (-" << betta << ":" << a / k << ");" << endl
                    << "            \\coordinate (C) at (-" << 180 - alpha << ":" << b / k << ");" << endl
                    << "            \\coordinate (E) at (-" << betta << ":" << fabs(b * cos((180 - alpha - betta) * PI / 180) / k) << ");" << endl
                    << "            \\coordinate (D) at (-" << 180 - alpha << ":" << fabs(a * cos((180 - alpha - betta) * PI / 180) / k) << ");" << endl
                    << "            \\tkzMarkRightAngle(C,E,A);" << endl
                    << "            \\tkzMarkRightAngle(B,D,A);" << endl
                    << "            \\draw[thick, dashed] (B) -- (D);" << endl
                    << "            \\draw[thick, dashed] (C) -- (E);" << endl
                    << "            \\draw[thick] (A) -- (B) -- (C) -- (A);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 4:     // Угол по внешнему углу
                do {
                    alpha = rand() % 40 + 90;
                    betta = 180 - alpha;
                    check = 1;
                    if (tan(betta * PI / 180) > 2)
                        check = 0;
                } while (check != 1);
                answer = 180 - 2 * betta;
                cout << "%" << (i + 1) << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        В треугольнике $ABC$ стороны $AC$ и $BC$ равны. Внешний угол при вершине $B$ равен $" << alpha << "^{\\circ}$. Найдите угол $C$. Ответ дайте в градусах." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\coordinate[label=below:$B$] (B) at (0,0);" << endl
                    << "            \\coordinate[label=below:$D$] (D) at (0:0.5);" << endl
                    << "            \\coordinate[label=below:$A$] (A) at (180:2);" << endl
                    << "            \\coordinate[label=above:$C$] (C) at (" << 180 - betta << ":" << 1 / cos(betta * PI / 180) << ");" << endl
                    << "            \\draw[thick] (D) -- (A) -- (C) -- (B);" << endl
                    << "            \\tkzMarkSegment[mark=|](A,C);" << endl
                    << "            \\tkzMarkSegment[mark=|](C,B);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 5:     // Угол между биссектрисой и медианой
                do {
                    betta = rand() % 40 + 1;
                    alpha = 90 - betta;
                    answer = alpha - 45;
                    a = rand() % 50 + 1;
                    b = rand() % 50 + 1;
                    c = sqrt(a * a + b * b);
                    if (a > b)
                        k = a / 2.3;
                    else
                        k = b / 2.3;
                    check = 1;
                    if (a / b < 0.3)
                        check = 0;
                    if (b / a < 0.3)
                        check = 0;
                    if (answer < 5)
                        check = 0;
                    if (fabs((c / 2) - ((c * b) / (a + b))) / k < 0.4)
                        check = 0;
                    if(b>a)
                        check = 0;
                    if(rand()%2 == 0)
                        AB = "B";
                    else
                    {
                        AB = "A";
                        betta = 90 - betta;
                    }
                } while (check != 1);
                cout << "%" << (i + 1) << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        Острый угол $" << AB << "$ прямоугольного треугольника $ABC$ равен $" << betta << "^{\\circ}$. Найдите величину угла между биссектрисой $CD$ и медианой $CM$, проведёнными из вершины прямого угла $C$. Ответ дайте в градусах." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\coordinate[label=above:$C$] (C) at (0,0);" << endl
                    << "            \\coordinate[label=below:$B$] (B) at (-" << betta << ":" << a/k << ");" << endl
                    << "            \\coordinate[label=below:$A$] (A) at (-" << (90+betta) << ":" << b/k << ");" << endl
                    << "            \\coordinate[label=below:$M$] (M) at ($(A)!0.5!(B)$);" << endl
                    << "            \\coordinate[label=below:$D$] (D) at ($(A)!" << (b/(a+b)) << "!(B)$);" << endl
                    << "            \\tkzMarkRightAngle (A,C,B);" << endl
                    << "            \\draw[thick, dashed] (C) -- (M);" << endl
                    << "            \\draw[thick, dashed] (C) -- (D);" << endl
                    << "            \\draw[thick] (A) -- (B) -- (C)  -- (A);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;
            }
            return Answer;
}

string Mnogougol(int i, int AllType)
{
    int type_main;
    if(AllType == 0)
        type_main = rand()%3 + 1;
    else
        type_main = AllType;
            double S, a[2], h[2], change, k, dx, dy, c, max, R, side[4], alpha[4], betta[4], l[4];
            double answer;
            int check = 0;
            int type;
            string Answer;

            switch (type_main)
            {
            case 1:
                type = rand()%4+1;
                switch (type)
                {
                case 1:
                    do {
                        S = rand() % 100 + 1;
                        answer = S / 4;
                        check = 1;
                        if (answer - static_cast<int>(answer) != 0)
                            check = 0;
                    } while (check != 1);
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        Площадь параллелограмма $ABCD$ равна " << S << ". Точка $E$ -- середина стороны $AD$. Найдите площадь треугольника $ABE$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$A$] (A) at (0,0);" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (-0.7,1.5);" << endl
                        << "            \\coordinate[label=above:$C$] (C) at (1.5,1.5);" << endl
                        << "            \\coordinate[label=below:$D$] (D) at (2.2,0);" << endl
                        << "            \\coordinate[label=below:$E$] (E) at (1.1,0);"<< endl
                        << "            \\draw[thick] (A) -- (B) -- (C)  -- (D) -- (A) -- (B) -- (E);" << endl
                        << "            \\tkzMarkSegment[mark=|](A,E);" << endl
                        << "            \\tkzMarkSegment[mark=|](E,D);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 2:
                    do {
                        S = rand() % 100 + 1;
                        answer = 3*S / 4;
                        check = 1;
                        if (answer - static_cast<int>(answer) != 0)
                            check = 0;
                    } while (check != 1);
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        Площадь параллелограмма $ABCD$ равна " << S << ". Точка $E$ -- середина стороны $AD$. Найдите площадь трапеции $BCDE$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$A$] (A) at (0,0);" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (-0.7,1.5);" << endl
                        << "            \\coordinate[label=above:$C$] (C) at (1.5,1.5);" << endl
                        << "            \\coordinate[label=below:$D$] (D) at (2.2,0);" << endl
                        << "            \\coordinate[label=below:$E$] (E) at (1.1,0);" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C)  -- (D) -- (A) -- (B) -- (E);" << endl
                        << "            \\tkzMarkSegment[mark=|](A,E);" << endl
                        << "            \\tkzMarkSegment[mark=|](E,D);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 3:
                    do {
                        S = rand() % 100 + 1;
                        answer = 4*S;
                        check = 1;
                        if (answer - static_cast<int>(answer) != 0)
                            check = 0;
                    } while (check != 1);
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        Площадь треугольника $ABE$ равна " << S << ". Точка $E$ -- середина стороны $AD$. Найдите площадь параллелограмма $ABCD$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$A$] (A) at (0,0);" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (-0.7,1.5);" << endl
                        << "            \\coordinate[label=above:$C$] (C) at (1.5,1.5);" << endl
                        << "            \\coordinate[label=below:$D$] (D) at (2.2,0);" << endl
                        << "            \\coordinate[label=below:$E$] (E) at (1.1,0);" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C)  -- (D) -- (A) -- (B) -- (E);" << endl
                        << "            \\tkzMarkSegment[mark=|](A,E);" << endl
                        << "            \\tkzMarkSegment[mark=|](E,D);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;

                case 4:
                    do {
                        S = rand() % 100 + 1;
                        answer = 3*S;
                        check = 1;
                        if (answer - static_cast<int>(answer) != 0)
                            check = 0;
                    } while (check != 1);
                    cout << "%" << (i + 1) << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        Площадь треугольника $ABE$ равна " << S << ". Точка $E$ -- середина стороны $AD$. Найдите площадь трапеции $BCDE$." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\coordinate[label=below:$A$] (A) at (0,0);" << endl
                        << "            \\coordinate[label=above:$B$] (B) at (-0.7,1.5);" << endl
                        << "            \\coordinate[label=above:$C$] (C) at (1.5,1.5);" << endl
                        << "            \\coordinate[label=below:$D$] (D) at (2.2,0);" << endl
                        << "            \\coordinate[label=below:$E$] (E) at (1.1,0);" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C)  -- (D) -- (A) -- (B) -- (E);" << endl
                        << "            \\tkzMarkSegment[mark=|](A,E);" << endl
                        << "            \\tkzMarkSegment[mark=|](E,D);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                    //cout << answer << endl;
                    Answer = "  \\item " + FormatDouble(answer) + " \n";
                    break;
                }
                break;

            case 2:
                do {
                    a[0] = rand() % 70 + 1;
                    a[1] = rand() % 70 + 1;
                    h[0] = rand() % 70 + 1;
                    if (a[0] > a[1])
                    {
                        change = a[0];
                        a[0] = a[1];
                        a[1] = change;
                    }
                    h[1] = a[0] * h[0] / a[1];
                    answer = h[1];
                    k = a[1] / 2.3;
                    check = 1;
                    c = a[1] * sqrt(a[0] * a[0] - h[1] * h[1]) / a[0];
                    dx = a[1]*(a[0]*a[0]-h[1]*h[1])/(a[0]*a[0]);
                    dy = a[1]*sqrt(a[0]*a[0]-h[1]*h[1])*h[1]/(a[0]*a[0]);
                    if (h[1] / k < 1)
                        check = 0;
                    if (h[0] / k < 1)
                        check = 0;
                    if (h[1] > a[0])
                        check = 0;
                    if (h[0] > a[1])
                        check = 0;
                    if (answer - static_cast<int>(answer) != 0)
                        check = 0;
                    if ((a[0] == h[1]) || (a[1] == h[0]))
                        check = 0;
                    if (a[0] == a[1])
                        check = 0;
                    if (dx < 0)
                        check = 0;
                    if (a[0] - (a[1] * sqrt(a[0] * a[0] - h[1] * h[1]) / a[0]) / k < 0.2)
                        check = 0;
                } while (check != 1);
                cout << "%" << (i + 1) << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        Стороны параллелограмма $ABCD$ равны " << a[0] << " и " << a[1] << ". Высота, опущенная на меньшую из этих сторон, равна " << h[0] << ". Найдите длину высоты, опущенной на большую сторону этого параллелограмма." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\coordinate (A) at (0,0);" << endl
                    << "            \\coordinate (B) at (" << sqrt(a[0]*a[0]-h[1]*h[1])/k << "," << h[1]/k << ");" << endl
                    << "            \\coordinate (C) at (" << (sqrt(a[0] * a[0] - h[1] * h[1]) + a[1])/k << "," << h[1]/k << ");" << endl
                    << "            \\coordinate (D) at (" << a[1]/k << ",0);" << endl
                    << "            \\coordinate (E) at (" << sqrt(a[0]*a[0]-h[1]*h[1])/k << ",0);" << endl
                    << "            \\coordinate (M) at (" << (sqrt(a[0] * a[0] - h[1] * h[1]) + a[1]-dx) / k << "," << (h[1]-dy)/k << ");" << endl
                    << "            \\tkzMarkRightAngle(A,E,B);" << endl
                    << "            \\tkzMarkRightAngle(B,M,C);" <<  endl
                    << "            \\draw[thick] (A) -- (B) -- (C)  -- (D) -- (A) -- (B) -- (E) -- (B) -- (M);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 3:
                do {
                    max = 0;
                    R = rand() % 50 + 2;
                    for (int i = 0; i < 4; i++)
                        alpha[i] = rand() % 361;

                    for (int i = 0; i < 3; i++)
                    {
                        for (int m = i + 1; m < 4; m++)
                        {
                            if (alpha[i] > alpha[m])
                            {
                                change = alpha[i];
                                alpha[i] = alpha[m];
                                alpha[m] = change;
                            }
                        }
                    }
                    check = 1;

                    betta[0] = 360 + alpha[0] - alpha[3];
                    betta[1] = alpha[1] - alpha[0];
                    betta[2] = alpha[2] - alpha[1];
                    betta[3] = alpha[3] - alpha[2];

                    for (int i = 0; i < 4; i++)
                        l[i] = R / cos((betta[i] * PI) / 360);

                    side[0] = static_cast<int>(l[0] * sin((PI * betta[0]) / 360) + l[1] * sin((PI * betta[1]) / 360));
                    side[1] = static_cast<int>(l[1] * sin((PI * betta[1]) / 360) + l[2] * sin((PI * betta[1]) / 360));
                    side[2] = static_cast<int>(l[2] * sin((PI * betta[2]) / 360) + l[3] * sin((PI * betta[1]) / 360));
                    side[3] = static_cast<int>(l[3] * sin((PI * betta[3]) / 360) + l[0] * sin((PI * betta[1]) / 360));

                    for (int i = 0; i < 4; i++)
                    {
                        if (side[i] > max)
                            max = side[i];
                    }

                    k = max / 3;
                    answer = 2*(side[2] + side[0]);


                    if ((alpha[1] - alpha[0] < 20) || (alpha[2] - alpha[1] < 20) || (alpha[3] - alpha[2] < 20) || (360 + alpha[0] - alpha[3] < 20))
                        check = 0;

                    if ((betta[0] / 2 > 90) || (betta[1] / 2 > 90) || (betta[2] / 2 > 90) || (betta[3] / 2 > 90))
                        check = 0;

                    if ((R / k < 0.7) || (R / k) > 1)
                        check = 0;
                    if ((l[0] / k > 4) || (l[1] / k > 4) || (l[2] / k > 4) || (l[3] / k > 4))
                        check = 0;
                    if (alpha[0] + betta[1] / 2 < 80)
                        check = 0;

                } while (check != 1);
                cout << "%" << i + 1 << endl;

                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "       В четырехугольник $ABCD$ вписана окружность, $AB=" << side[2] << "$, $CD = " << side[0] << "$. Найдите периметр четырехугольника $ABCD$." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\draw[thick] (0,0) circle(" << R / k << ");" << endl
                    << "            \\coordinate[label=left:$C$] (C) at (" << (alpha[0] + (betta[1] / 2)) << ":" << l[1] / k << ");" << endl
                    << "            \\coordinate[label=left:$B$] (B) at (" << (alpha[1] + (betta[2] / 2)) << ":" << l[2] / k << ");" << endl
                    << "            \\coordinate[label=below:$A$] (A) at (" << (alpha[2] + (betta[3] / 2)) << ":" << l[3] / k << ");" << endl
                    << "            \\coordinate[label=right:$D$] (D) at (" << (alpha[3] + (betta[0] / 2)) << ":" << l[0] / k << ");" << endl
                    << "            \\draw[thick] (A) -- (B) -- (C) -- (D) -- (A);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;
            }
            return Answer;
}

string Okrugn(int i, int AllType)
{
    double alpha[6];
            double betta[6], max, R, change;
            int check = 0;
            int type_1;
            int type;
            if(AllType == 0)
                type = rand()%10+1;
            else
                type = AllType;
            double answer;
            string Answer;
            string Quest[3];
            switch (type)
            {
            case 1:
                do {
                    alpha[0] = rand() % 160 + 10;
                    alpha[1] = alpha[0] + 180;
                    answer = alpha[1] - 180;
                    check = 1;
                    if ((360 - alpha[1]) / 2 - static_cast<int>((360 - alpha[1]) / 2) != 0)
                        check = 0;
                } while (check != 1);
                cout << "%" << (i + 1) << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        Отрезки $AC$ и $BD$ -- диаметры окружности с центром $O$. Угол $ACB$ равен $" << (360-alpha[1])/2 << "^{\\circ}$. Найдите величину угла $AOD$. Ответ дайте в градусах." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\draw[thick] (0,0) circle(1.5);" << endl
                    << "            \\coordinate[label=below left:$O$] (O) at (0,0);" << endl
                    << "            \\coordinate[label=below:$A$] (A) at (" << alpha[1] << ":1.5);" << endl
                    << "            \\coordinate[label=right:$B$] (B) at (0:1.5);" << endl
                    << "            \\coordinate[label=above:$C$] (C) at (" << alpha[0] << ":1.5);" << endl
                    << "            \\coordinate[label=left:$D$] (D) at (180:1.5);" << endl
                    << "            \\draw[thick] (A) -- (C) -- (B) -- (D);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 2:
                do {
                    alpha[0] = rand() % 160 + 10;
                    alpha[1] = alpha[0] + 180;
                    answer = (360-alpha[1])/2;
                    check = 1;
                    if ((360 - alpha[1]) / 2 - static_cast<int>((360 - alpha[1]) / 2) != 0)
                        check = 0;
                } while (check != 1);
                cout << "%" << (i + 1) << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        Отрезки $AC$ и $BD$ -- диаметры окружности с центром $O$. Угол $AOD$ равен $" << alpha[1]-180 << "^{\\circ}$. Найдите величину угла $ACB$. Ответ дайте в градусах." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\draw[thick] (0,0) circle(1.5);" << endl
                    << "            \\coordinate[label=below left:$O$] (O) at (0,0);" << endl
                    << "            \\coordinate[label=below:$A$] (A) at (" << alpha[1] << ":1.5);" << endl
                    << "            \\coordinate[label=right:$B$] (B) at (0:1.5);" << endl
                    << "            \\coordinate[label=above:$C$] (C) at (" << alpha[0] << ":1.5);" << endl
                    << "            \\coordinate[label=left:$D$] (D) at (180:1.5);" << endl
                    << "            \\draw[thick] (A) -- (C) -- (B) -- (D);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 3:
                do {
                    alpha[0] = rand() % 20 + 10;
                    alpha[1] = alpha[0] + rand() % 60 + 20;
                    answer = 90 - (alpha[1] - alpha[0]);
                    check = 1;
                    if (alpha[1] - alpha[0]<30)
                        check = 0;
                    if (1.5 / cos((alpha[1] - alpha[0]) * PI / 180) > 3)
                        check = 0;
                } while (check != 1);
                cout << "%" << (i + 1) << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        Найдите величину угла $ACO$, если его сторона $CA$ касается окружности с центром в точке $O$, отрезок $CO$ пересекает окружность в точке $B$, а дуга $AB$ окружности, заключенная внутри этого угла, равна $" << alpha[1]-alpha[0] <<"^{\\circ}$. Ответ дайте в градусах." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\draw[thick] (0,0) circle(1.5);" << endl
                    << "            \\coordinate[label=below left:$O$] (O) at (0,0);" << endl
                    << "            \\coordinate[label=above:$A$] (A) at (" << alpha[1] << ":1.5);" << endl
                    << "            \\coordinate[label=below right:$B$] (B) at (" << alpha[0] << ":1.5);" << endl
                    << "            \\coordinate[label=above:$C$] (C) at (" << alpha[0] << ":" << 1.5/cos((alpha[1]-alpha[0]) * PI / 180) << ");" << endl
                    << "            \\coordinate (E) at (" << alpha[1] + 30 << ":" << 1.5/cos(30*PI/180) << ");" << endl
                    << "            \\draw[thick] (E) -- (C) -- (O) -- (A);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 4:
                do {
                    alpha[0] = rand() % 20 + 10;
                    alpha[1] = alpha[0] + rand() % 60 + 20;
                    answer = alpha[1]-alpha[0];
                    check = 1;
                    if (alpha[1] - alpha[0] < 30)
                        check = 0;
                    if (1.5 / cos((alpha[1] - alpha[0]) * PI / 180) > 3)
                        check = 0;
                } while (check != 1);
                cout << "%" << (i + 1) << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        Угол $ACO$ равен $" << 90 - alpha[1] +alpha[0] << "^{\\circ}$. Его сторона $AC$ касается окружности с центром в точке $O$. Отрезок $CO$ пересекает окружность в точке $B$. Найдите градусную меру дуги $AB$ окружности, заключенной внутри этого угла. Ответ дайте в градусах." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\draw[thick] (0,0) circle(1.5);" << endl
                    << "            \\coordinate[label=below left:$O$] (O) at (0,0);" << endl
                    << "            \\coordinate[label=above:$A$] (A) at (" << alpha[1] << ":1.5);" << endl
                    << "            \\coordinate[label=below right:$B$] (B) at (" << alpha[0] << ":1.5);" << endl
                    << "            \\coordinate[label=above:$C$] (C) at (" << alpha[0] << ":" << 1.5 / cos((alpha[1] - alpha[0]) * PI / 180) << ");" << endl
                    << "            \\coordinate (E) at (" << alpha[1] + 30 << ":" << 1.5 / cos(30 * PI / 180) << ");" << endl
                    << "            \\draw[thick] (E) -- (C) -- (O) -- (A);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 5:
                do {
                    alpha[0] = rand() % 100 + 30;
                    alpha[1] = rand() % 45 + 215;
                    alpha[2] = rand() % 45 + 275;
                    answer = alpha[2] - alpha[1];
                    check = 1;
                    if ((answer/2) - static_cast<int>(answer/2) != 0)
                        check = 0;
                } while (check != 1);
                if(rand()%2 == 0)
                {
                    Quest[0] = "центральный";
                    Quest[1] = "больше острого вписанного угла";
                    Quest[2] = FormatDouble(answer/2);
                }
                else
                {
                    Quest[0] = "вписанный";
                    Quest[1] = "меньше центрального угла";
                    Quest[2] = FormatDouble(answer);
                }
                cout << "%" << (i + 1) << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        Найдите " << Quest[0] << " угол, если он на $" << Quest[2] << "^{\\circ}$ " << Quest[1] << ", опирающегося на ту же дугу. Ответ дайте в градусах." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\draw[thick] (0,0) circle(1.5);" << endl
                    << "            \\coordinate (O) at (0,0);" << endl
                    << "            \\coordinate (A) at (" << alpha[0] << ":1.5);" << endl
                    << "            \\coordinate (B) at (" << alpha[1] << ":1.5);" << endl
                    << "            \\coordinate (C) at (" << alpha[2] << ":1.5);" << endl
                    << "            \\draw[thick] (B) -- (A) -- (C) -- (O) -- (B);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 6:
                do {
                    alpha[0] = rand() % 100 + 20;
                    alpha[1] = rand() % 30 + 10 + alpha[0];
                    alpha[2] = rand() % 100 + 190;
                    betta[0] = (alpha[0] + 360 - alpha[2]) / 2;
                    answer = 180 - betta[0];
                    check = 1;
                    if ((answer / 2) - static_cast<int>(answer / 2) != 0)
                        check = 0;
                    if (alpha[0] + alpha[1] > 170)
                        check = 0;
                } while (check != 1);
                cout << "%" << (i + 1) << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        Четырехугольник $ABCD$ вписан в окружность. Угол $BAD$ равен $" << betta[0] << "^{\\circ}$. Найдите угол $BCD$. Ответ дайте в градусах." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\draw[thick] (0,0) circle(1.5);" << endl
                    << "            \\coordinate[label=right:$C$] (C) at (0:1.5);" << endl
                    << "            \\coordinate[label=above left:$B$] (B) at (" << alpha[0] << ":1.5);" << endl
                    << "            \\coordinate[label=above left:$A$] (A) at (" << alpha[0] + alpha[1] << ":1.5);" << endl
                    << "            \\coordinate[label=below left:$D$] (D) at (" << alpha[2] << ":1.5);" << endl
                    << "            \\draw[thick] (A) -- (B) -- (C) -- (D) -- (A);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 7:
                do {
                    max = 0;
                    R = 1.5;
                    for (int i = 0; i < 4; i++)
                        alpha[i] = rand() % 361;

                    for (int i = 0; i < 3; i++)
                    {
                        for (int m = i + 1; m < 4; m++)
                        {
                            if (alpha[i] > alpha[m])
                            {
                                change = alpha[i];
                                alpha[i] = alpha[m];
                                alpha[m] = change;
                            }
                        }
                    }
                    betta[2] = (alpha[1] + 360 - alpha[3]) / 2;
                    betta[0] = 180 - betta[2];
                    betta[3] = (alpha[2] - alpha[0]) / 2;
                    betta[1] = 180 - betta[3];
                    check = 1;
                    for (int i = 0; i < 4; i++)
                    {
                        if (betta[i] < 20)
                            check = 0;
                    }
                    if (alpha[1] - alpha[0] < 60)
                        check = 0;
                    if (alpha[2] - alpha[1] < 60)
                        check = 0;
                    if (alpha[3] - alpha[2] < 60)
                        check = 0;
                    if (360 - alpha[3] + alpha[0] < 60)
                        check = 0;
                    answer = betta[1];
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        Четырехугольник $ABCD$ вписан в окружность. Угол $ABD$ равен $" << (alpha[3] - alpha[2]) / 2 << "^{\\circ}$, угол $CAD$ равен $" << (360 - alpha[3] + alpha[0]) / 2 << "^{\\circ}$. Найдите угол $ABC$. Ответ дайте в градусах." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\draw[thick] (0,0) circle(" << R << ");" << endl
                    << "            \\coordinate[label=below left:$A$] (A) at (" << alpha[2] << ":" << R << ");" << endl
                    << "            \\coordinate[label=above left:$B$] (B) at (" << alpha[1] << ":" << R << ");" << endl
                    << "            \\coordinate[label=above right:$C$] (C) at (" << alpha[0] << ":" << R << ");" << endl
                    << "            \\coordinate[label=below right:$D$] (D) at (" << alpha[3] << ":" << R << ");" << endl
                    << "            \\draw[thick] (A) -- (B) -- (C) -- (D) -- (A) -- (C) -- (B) -- (D);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 8:
                do {
                    max = 0;
                    R = 1.5;
                    for (int i = 0; i < 4; i++)
                        alpha[i] = rand() % 361;

                    for (int i = 0; i < 3; i++)
                    {
                        for (int m = i + 1; m < 4; m++)
                        {
                            if (alpha[i] > alpha[m])
                            {
                                change = alpha[i];
                                alpha[i] = alpha[m];
                                alpha[m] = change;
                            }
                        }
                    }
                    betta[2] = (alpha[1] + 360 - alpha[3]) / 2;
                    betta[0] = 180 - betta[2];
                    betta[3] = (alpha[2] - alpha[0]) / 2;
                    betta[1] = 180 - betta[3];
                    check = 1;
                    for (int i = 0; i < 4; i++)
                    {
                        if (betta[i] < 20)
                            check = 0;
                    }
                    if (alpha[1] - alpha[0] < 60)
                        check = 0;
                    if (alpha[2] - alpha[1] < 60)
                        check = 0;
                    if (alpha[3] - alpha[2] < 60)
                        check = 0;
                    if (360 - alpha[3] + alpha[0] < 60)
                        check = 0;
                    answer = (alpha[3] - alpha[2]) / 2;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        Четырехугольник $ABCD$ вписан в окружность. Угол $ABC$ равен $" << (360 - alpha[2] + alpha[0]) / 2 << "^{\\circ}$, угол $CAD$ равен $" << (360 - alpha[3] + alpha[0]) / 2 << "^{\\circ}$. Найдите угол $ABD$. Ответ дайте в градусах." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\draw[thick] (0,0) circle(" << R << ");" << endl
                    << "            \\coordinate[label=below left:$A$] (A) at (" << alpha[2] << ":" << R << ");" << endl
                    << "            \\coordinate[label=above left:$B$] (B) at (" << alpha[1] << ":" << R << ");" << endl
                    << "            \\coordinate[label=above right:$C$] (C) at (" << alpha[0] << ":" << R << ");" << endl
                    << "            \\coordinate[label=below right:$D$] (D) at (" << alpha[3] << ":" << R << ");" << endl
                    << "            \\draw[thick] (A) -- (B) -- (C) -- (D) -- (A) -- (C) -- (B) -- (D);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 9:
                do {
                    alpha[0] = rand() % 90 + 10;
                    alpha[1] = alpha[0] + rand() % 60 + 20;
                    alpha[2] = rand() % 90 + 180;
                    alpha[3] = alpha[2] + rand() % 60 + 20;
                    betta[0] = (alpha[3]-alpha[1]) / 2;
                    betta[1] = (360 + alpha[0] - alpha[2]) / 2;
                    betta[2] = 180 - betta[0];
                    betta[3] = 180 - betta[1];
                    if (betta[3] > betta[2])
                        answer = betta[3];
                    else
                        answer = betta[2];
                    check = 1;
                    if (answer - static_cast<int>(answer) != 0)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        Два угла вписанного в окружность четырехугольника равны $" << betta[0] << "^{\\circ}$ и $" << betta[1] << "^{\\circ}$. Найдите больший из оставшихся углов. Ответ дайте в градусах." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\draw[thick] (0,0) circle(1.5);" << endl
                    << "            \\coordinate (A) at (" << alpha[0] << ":1.5);" <<  endl
                    << "            \\coordinate (B) at (" << alpha[1] << ":1.5);" << endl
                    << "            \\coordinate (C) at (" << alpha[2] << ":1.5);" << endl
                    << "            \\coordinate (D) at (" << alpha[3] << ":1.5);" << endl
                    << "            \\draw[thick] (A) -- (B) -- (C) -- (D) -- (A);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 10:
                type_1 = rand() % 6 + 1;
                switch (type_1)
                {
                case 1:
                    betta[0] = 30;
                    break;

                case 2:
                    betta[0] = 45;
                    break;

                case 3:
                    betta[0] = 60;
                    break;

                case 4:
                    betta[0] = 120;
                    break;

                case 5:
                    betta[0] = 135;
                    break;

                case 6:
                    betta[0] = 150;
                    break;
                }
                do {
                    R = rand() % 40 + 2;
                    alpha[0] = rand() % 40 + 10;
                    alpha[1] = alpha[0] + rand() % 70 + 20;
                    alpha[2] = alpha[0] + 360 - 2 * betta[0];
                    answer = R;
                    check = 1;
                    if (alpha[1] - alpha[0] < 30)
                        check = 0;
                    if (alpha[2] - alpha[1] < 30)
                        check = 0;
                } while (check != 1);
                if ((type_1 == 1) || (type_1 == 6))
                {
                    cout << "%" << i + 1 << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        В треугольнике $ABC$ сторона $AB$ равна $" << R << "$, угол $C$ равен $" << betta[0] << "^{\\circ}$. Найдите радиус описанной около этого треугольнкиа окружности." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\draw[thick] (0,0) circle(1.5);" << endl
                        << "            \\coordinate[label=above:$B$] (A) at (" << alpha[0] << ":1.5);" << endl
                        << "            \\coordinate[label=above:$C$] (B) at (" << alpha[1] << ":1.5);" << endl
                        << "            \\coordinate[label=below:$A$] (C) at (" << alpha[2] << ":1.5);" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                }
                if ((type_1 == 2) || (type_1 == 5))
                {
                    cout << "%" << i + 1 << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        В треугольнике $ABC$ сторона $AB$ равна $" << R << "\\sqrt{2}$, угол $C$ равен $" << betta[0] << "^{\\circ}$. Найдите радиус описанной около этого треугольнкиа окружности." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\draw[thick] (0,0) circle(1.5);" << endl
                        << "            \\coordinate[label=above:$B$] (A) at (" << alpha[0] << ":1.5);" << endl
                        << "            \\coordinate[label=above:$C$] (B) at (" << alpha[1] << ":1.5);" << endl
                        << "            \\coordinate[label=below:$A$] (C) at (" << alpha[2] << ":1.5);" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                }
                if ((type_1 == 3) || (type_1 == 4))
                {
                    cout << "%" << i + 1 << endl;
                    cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                    cout << "        В треугольнике $ABC$ сторона $AB$ равна $" << R << "\\sqrt{3}$, угол $C$ равен $" << betta[0] << "^{\\circ}$. Найдите радиус описанной около этого треугольнкиа окружности." << endl;
                    cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                        << "            \\draw[thick] (0,0) circle(1.5);" << endl
                        << "            \\coordinate[label=above:$B$] (A) at (" << alpha[0] << ":1.5);" << endl
                        << "            \\coordinate[label=above:$C$] (B) at (" << alpha[1] << ":1.5);" << endl
                        << "            \\coordinate[label=below:$A$] (C) at (" << alpha[2] << ":1.5);" << endl
                        << "            \\draw[thick] (A) -- (B) -- (C) -- (A);" << endl;
                    cout << "\\end{tikzpicture}" << endl << endl;
                }
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;
            }
            return Answer;
}

string Vector(int i, int AllType)
{
    int type;
    if(AllType == 0)
        type = rand()%5+1;
    else
        type = AllType;
            double a[4], b[4], c[2];
            double k[2];
            double answer;
            string Answer;
            int check = 0;
            switch (type)
            {
            case 1:
                do {
                    a[0] = rand() % 6 + 1;
                    a[1] = rand() % 6 + 1;
                    a[2] = pow(-1, rand()) * (rand() % 6 + 1);
                    a[3] = pow(-1, rand()) * (rand() % 6 + 1);

                    b[0] = rand() % 6 + 1;
                    b[1] = rand() % 6 + 1;
                    b[2] = pow(-1, rand()) * (rand() % 6 + 1);
                    b[3] = pow(-1, rand()) * (rand() % 6 + 1);

                    if (pow(-1, rand()) > 0)
                    {
                        k[0] = pow(-1, rand());
                        k[1] = pow(-1, rand()) * (rand() % 10 + 1);
                    }
                    else
                    {
                        k[1] = pow(-1, rand());
                        k[0] = pow(-1, rand()) * (rand() % 10 + 1);
                    }

                    c[0] = (k[0] * a[2]) + (k[1] * b[2]);
                    c[1] = (k[0] * a[3]) + (k[1] * b[3]);
                    answer = sqrt(pow(c[0], 2) + pow(c[1], 2));

                    check = 1;
                    if ((a[0] + a[2] > 6) || (a[1] + a[3] > 6))
                        check = 0;
                    if ((a[0] + a[2] < -1) || (a[1] + a[3] < -1))
                        check = 0;
                    if ((b[0] + b[2] > 6) || (b[1] + b[3] > 6))
                        check = 0;
                    if ((b[0] + b[2] < -1) || (b[1] + b[3] < -1))
                        check = 0;
                    if ((a[0] + a[2] == b[0] + b[2]) || (a[1] + a[3] == b[1] + b[3]))
                        check = 0;
                    if (answer - static_cast<int>(answer) != 0)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        На координатной плоскости изображены векторы $\\vec{a}$ и $\\vec{b}$, координатами которых являются целые числа. Найдите длину вектора $" << SIGNUr(k[0],1) << NumberCelUr(k[0],1) << "\\vec{a}" << SIGNUr(k[1],2) << NumberCelUr(k[1],1) << "\\vec{b}$." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl << "\\pgfplotsset{compat=1.18,  width = 6cm % ширина графика%" << endl <<"}" << endl <<  "\\begin{axis}[xmin = -1.5, xmax = 6.5," << endl
                    << "ymin = -1.5, ymax = 6.5," << endl
                    << "axis lines = middle," << endl
                    << "xtick = {-1, 0, 1, 2, 3, 4, 5, 6}, % задает иксы которые будут отмечены" << endl
                    << "xticklabels = {${}$, ${}$, $1$, ${}$, ${}$, ${}$, ${}$, ${}$}, % то что нужно будет отметить по х                            xticklabel style = {anchor = north}, % где будет отмечено значение х" << endl
                    << "ytick = {-1, 0, 1, 2, 3, 4, 5, 6}," << endl
                    << "yticklabels = {${}$, ${}$, $1$, ${}$, ${}$, ${}$, ${}$, ${}$}," << endl
                    << "yticklabel style = {anchor = east}," << endl
                    << "xmajorgrids = true, % полоски от значений на оси" << endl
                    << "ymajorgrids = true," << endl
                    << "grid style = dashed, % стиль дополнительных полосок" << endl
                    << "xlabel = $x$, ylabel = $y$, ]" << endl
                    << "\\coordinate[label=below left:$0$] (O) at (0,0);" << endl;
                cout << "\\draw[thick, -latex] (" << a[0] << "," << a[1] << ") -- (" << (a[0] + a[2]) << "," << (a[1] + a[3]) << ");" << endl;
                cout << "\\draw[thick, -latex] (" << b[0] << "," << b[1] << ") -- (" << (b[0] + b[2]) << "," << (b[1] + b[3]) << ");" << endl;
                cout << "\\coordinate[label=above:$a$] (a) at (" << (a[0]+a[0]+a[2])/2 << "," << (a[1]+a[1]+a[3])/2 << ");" << endl;
                cout << "\\coordinate[label=above:$b$] (b) at (" << (b[0] + b[0] + b[2]) / 2 << "," << (b[1] + b[1] + b[3]) / 2 << ");" << endl;
                cout << "        \\end{axis}" << endl << "\\end{tikzpicture}" << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 2:
                do {
                    a[0] = rand() % 6 + 1;
                    a[1] = rand() % 6 + 1;
                    a[2] = pow(-1, rand()) * (rand() % 6 + 1);
                    a[3] = pow(-1, rand()) * (rand() % 6 + 1);

                    b[0] = rand() % 6 + 1;
                    b[1] = rand() % 6 + 1;
                    b[2] = pow(-1, rand()) * (rand() % 6 + 1);
                    b[3] = pow(-1, rand()) * (rand() % 6 + 1);

                    if (pow(-1, rand()) > 0)
                    {
                        k[0] = pow(-1, rand());
                        k[1] = pow(-1, rand()) * (rand() % 10 + 1);
                    }
                    else
                    {
                        k[1] = pow(-1, rand());
                        k[0] = pow(-1, rand()) * (rand() % 10 + 1);
                    }

                    c[0] = (k[0] * a[2]) + (k[1] * b[2]);
                    c[1] = (k[0] * a[3]) + (k[1] * b[3]);
                    answer = a[2]*b[2]+a[3]*b[3];

                    check = 1;
                    if ((a[0] + a[2] > 6) || (a[1] + a[3] > 6))
                        check = 0;
                    if ((a[0] + a[2] < -1) || (a[1] + a[3] < -1))
                        check = 0;
                    if ((b[0] + b[2] > 6) || (b[1] + b[3] > 6))
                        check = 0;
                    if ((b[0] + b[2] < -1) || (b[1] + b[3] < -1))
                        check = 0;
                    if ((a[0] + a[2] == b[0] + b[2]) || (a[1] + a[3] == b[1] + b[3]))
                        check = 0;
                    if (answer - static_cast<int>(answer) != 0)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        На координатной плоскости изображены векторы $\\vec{a}$ и $\\vec{b}$, координатами которых являются целые числа. Найдите скалярное произведение $\\vec{a}\\cdot\\vec{b}$." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl << "\\pgfplotsset{compat=1.18,  width = 6cm % ширина графика%" << endl << "}" << endl << "\\begin{axis}[xmin = -1.5, xmax = 6.5," << endl
                    << "ymin = -1.5, ymax = 6.5," << endl
                    << "axis lines = middle," << endl
                    << "xtick = {-1, 0, 1, 2, 3, 4, 5, 6}, % задает иксы которые будут отмечены" << endl
                    << "xticklabels = {${}$, ${}$, $1$, ${}$, ${}$, ${}$, ${}$, ${}$}, % то что нужно будет отметить по х                            xticklabel style = {anchor = north}, % где будет отмечено значение х" << endl
                    << "ytick = {-1, 0, 1, 2, 3, 4, 5, 6}," << endl
                    << "yticklabels = {${}$, ${}$, $1$, ${}$, ${}$, ${}$, ${}$, ${}$}," << endl
                    << "yticklabel style = {anchor = east}," << endl
                    << "xmajorgrids = true, % полоски от значений на оси" << endl
                    << "ymajorgrids = true," << endl
                    << "grid style = dashed, % стиль дополнительных полосок" << endl
                    << "xlabel = $x$, ylabel = $y$, ]" << endl
                    << "\\coordinate[label=below left:$0$] (O) at (0,0);" << endl;
                cout << "\\draw[thick, -latex] (" << a[0] << "," << a[1] << ") -- (" << (a[0] + a[2]) << "," << (a[1] + a[3]) << ");" << endl;
                cout << "\\draw[thick, -latex] (" << b[0] << "," << b[1] << ") -- (" << (b[0] + b[2]) << "," << (b[1] + b[3]) << ");" << endl;
                cout << "\\coordinate[label=above:$a$] (a) at (" << (a[0] + a[0] + a[2]) / 2 << "," << (a[1] + a[1] + a[3]) / 2 << ");" << endl;
                cout << "\\coordinate[label=above:$b$] (b) at (" << (b[0] + b[0] + b[2]) / 2 << "," << (b[1] + b[1] + b[3]) / 2 << ");" << endl;
                cout << "        \\end{axis}" << endl << "\\end{tikzpicture}" << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 3:
                do {
                    a[0] = rand() % 6 + 1;
                    a[1] = rand() % 6 + 1;
                    a[2] = pow(-1, rand()) * (rand() % 30 + 1);
                    a[3] = pow(-1, rand()) * (rand() % 30 + 1);

                    b[0] = rand() % 6 + 1;
                    b[1] = rand() % 6 + 1;
                    b[2] = pow(-1, rand()) * (rand() % 30 + 1);
                    b[3] = pow(-1, rand()) * (rand() % 30 + 1);

                    if (pow(-1, rand()) > 0)
                    {
                        k[0] = pow(-1, rand());
                        k[1] = pow(-1, rand()) * (rand() % 10 + 1);
                    }
                    else
                    {
                        k[1] = pow(-1, rand());
                        k[0] = pow(-1, rand()) * (rand() % 10 + 1);
                    }

                    c[0] = (k[0] * a[2]) + (k[1] * b[2]);
                    c[1] = (k[0] * a[3]) + (k[1] * b[3]);
                    answer = sqrt(pow(c[0],2)+pow(c[1],2));

                    check = 1;
                    if ((k[0] * a[2]) == -1 * (k[1] * b[2]))
                        check = 0;
                    if ((k[0] * a[3]) == -1 * (k[1] * b[3]))
                        check = 0;
                    if (answer - static_cast<int>(answer) != 0)
                        check = 0;
                    if (answer > 82)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item Даны векторы $\\vec{a}(" << a[2] << "," << a[3] << ")$ и $\\vec{b}(" << b[2] << "," << b[3] << ")$. Найдите длину вектора $" << SIGNUr(k[0], 1) << NumberCelUr(k[0], 1) << "\\vec{a}" << SIGNUr(k[1], 2) << NumberCelUr(k[1], 1) << "\\vec{b}$." << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 4:
                do {
                    a[0] = rand() % 6 + 1;
                    a[1] = rand() % 6 + 1;
                    a[2] = pow(-1, rand()) * (rand() % 30 + 1);
                    a[3] = pow(-1, rand()) * (rand() % 30 + 1);

                    b[0] = rand() % 6 + 1;
                    b[1] = rand() % 6 + 1;
                    b[2] = pow(-1, rand()) * (rand() % 30 + 1);
                    b[3] = pow(-1, rand()) * (rand() % 30 + 1);

                    if (pow(-1, rand()) > 0)
                    {
                        k[0] = pow(-1, rand());
                        k[1] = pow(-1, rand()) * (rand() % 10 + 1);
                    }
                    else
                    {
                        k[1] = pow(-1, rand());
                        k[0] = pow(-1, rand()) * (rand() % 10 + 1);
                    }

                    answer = a[2]*b[2]+a[3]*b[3];

                    check = 1;
                    if ((k[0] * a[2]) == -1 * (k[1] * b[2]))
                        check = 0;
                    if ((k[0] * a[3]) == -1 * (k[1] * b[3]))
                        check = 0;
                    if (answer - static_cast<int>(answer) != 0)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item Даны векторы $\\vec{a}(" << a[2] << "," << a[3] << ")$ и $\\vec{b}(" << b[2] << "," << b[3] << ")$. Найдите скалярное произведение $\\vec{a}\\cdot\\vec{b}$." << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 5:
                do {
                    a[0] = rand() % 13 + 1;
                    b[0] = rand() % 13 + 1;
                    if (pow(-1, rand()) > 0)
                    {
                        c[0] = 60;
                        k[0] = 0.5;
                    }
                    else
                    {
                        c[0] = 120;
                        k[0] = -0.5;
                    }

                    answer = a[0]*b[0]*k[0];

                    check = 1;
                    
                    if ((10*answer) - static_cast<int>(10*answer) != 0)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item Длины векторов $\\vec{a}$ и $\\vec{b}$ равны $" << a[0] << "$ и $" << b[0] << "$, а угол между ними равен $" << c[0] << "^{\\circ}$. Найдите скалярное произведение $\\vec{a}\\cdot\\vec{b}$." << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;
            }
            return Answer;
}

string Prizm(int i, int AllType)
{
    int type;
    if(AllType == 0)
        type = rand()%9+1;
    else
        type = AllType;
            double a[3], V, S, k;
            double answer;
            string Answer;
            int check = 0;
            switch (type)
            {
            case 1:
                do {
                    for (int i = 0; i < 3; i++)
                        a[i] = rand() % 48 + 2;
                    if (a[0] > a[1])
                        k = a[0] / 3;
                    else
                        k = a[1] / 3;
                    if (a[2] > k*3)
                        k = a[2] / 3;
                    answer = a[0] * a[1] * a[2] / 2;
                    check = 1;
                    if (answer > 777)
                        check = 0;
                    if (answer - static_cast<int>(answer) != 0)
                        check = 0;
                    if ((a[0] / k < 1) || (a[1] / k < 1) || (a[2] / k < 1))
                        check = 0;
                    if (a[2] / k > 2)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        В прямоугольном параллелепипеде $ABCDA_1B_1C_1D_1$ известно, что $AB=" << a[0] << "$, $BC=" << a[1] << "$, $AA_1=" << a[2] << "$. Найдите объем многогранника, вершинами которого являются точки $ABCA_1B_1C_1$." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\def\\x{" << a[0]/k << "}" << endl
                    << "            \\def\\y{" << a[2]/k << "}" << endl
                    << "            \\def\\z{" << a[1]/k << "}" << endl
                    << "            \\coordinate[label=below:${D}$] (D) at (0,0,0);" << endl
                    << "            \\coordinate[label=above:${D_1}$] (D_1) at (0,\\y,0);" << endl
                    << "            \\coordinate[label=below:${A}$] (A) at (0,0,\\z);" << endl
                    << "            \\coordinate[label=above:${A_1}$] (A_1) at (0,\\y,\\z);" << endl
                    << "            \\coordinate[label=below:${C}$] (C) at (\\x,0,0);" << endl
                    << "            \\coordinate[label=above:${C_1}$] (C_1) at (\\x,\\y,0);" << endl
                    << "            \\coordinate[label=below:${B}$] (B) at (\\x,0,\\z);" << endl
                    << "            \\coordinate[label=above:${B_1}$] (B_1) at (\\x,\\y,\\z);" << endl
                    << "            \\draw[thick] (B) -- (A) -- (A_1) -- (B_1) -- (B) -- (C) -- (C_1) -- (B_1) -- (C_1) -- (D_1) -- (A_1);" << endl
                    << "            \\draw[thick,  dashed] (A) -- (D) -- (C) -- (D) -- (D_1);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 2:
                do {
                    for (int i = 0; i < 3; i++)
                        a[i] = rand() % 48 + 2;
                    if (a[0] > a[1])
                        k = a[0] / 3;
                    else
                        k = a[1] / 3;
                    if (a[2] > k * 3)
                        k = a[2] / 3;
                    answer = a[0] * a[1] * a[2] / 3;
                    check = 1;
                    if (answer > 777)
                        check = 0;
                    if (answer - static_cast<int>(answer) != 0)
                        check = 0;
                    if ((a[0] / k < 1) || (a[1] / k < 1) || (a[2] / k < 1))
                        check = 0;
                    if (a[2] / k > 2)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        В прямоугольном параллелепипеде $ABCDA_1B_1C_1D_1$ известно, что $AB=" << a[0] << "$, $BC=" << a[1] << "$, $AA_1=" << a[2] << "$. Найдите объем многогранника, вершинами которого являются точки $ABCDD_1$." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\def\\x{" << a[0] / k << "}" << endl
                    << "            \\def\\y{" << a[2] / k << "}" << endl
                    << "            \\def\\z{" << a[1] / k << "}" << endl
                    << "            \\coordinate[label=below:${D}$] (D) at (0,0,0);" << endl
                    << "            \\coordinate[label=above:${D_1}$] (D_1) at (0,\\y,0);" << endl
                    << "            \\coordinate[label=below:${A}$] (A) at (0,0,\\z);" << endl
                    << "            \\coordinate[label=above:${A_1}$] (A_1) at (0,\\y,\\z);" << endl
                    << "            \\coordinate[label=below:${C}$] (C) at (\\x,0,0);" << endl
                    << "            \\coordinate[label=above:${C_1}$] (C_1) at (\\x,\\y,0);" << endl
                    << "            \\coordinate[label=below:${B}$] (B) at (\\x,0,\\z);" << endl
                    << "            \\coordinate[label=above:${B_1}$] (B_1) at (\\x,\\y,\\z);" << endl
                    << "            \\draw[thick] (B) -- (A) -- (A_1) -- (B_1) -- (B) -- (C) -- (C_1) -- (B_1) -- (C_1) -- (D_1) -- (A_1);" << endl
                    << "            \\draw[thick,  dashed] (A) -- (D) -- (C) -- (D) -- (D_1);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 3:
                do {
                    for (int i = 0; i < 3; i++)
                        a[i] = rand() % 48 + 2;
                    if (a[0] > a[1])
                        k = a[0] / 3;
                    else
                        k = a[1] / 3;
                    if (a[2] > k * 3)
                        k = a[2] / 3;
                    answer = a[0] * a[1] * a[2] / 6;
                    check = 1;
                    if (answer > 777)
                        check = 0;
                    if (answer - static_cast<int>(answer) != 0)
                        check = 0;
                    if ((a[0] / k < 1) || (a[1] / k < 1) || (a[2] / k < 1))
                        check = 0;
                    if (a[2] / k > 2)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        В прямоугольном параллелепипеде $ABCDA_1B_1C_1D_1$ известно, что $AB=" << a[0] << "$, $BC=" << a[1] << "$, $AA_1=" << a[2] << "$. Найдите объем многогранника, вершинами которого являются точки $ABCB_1$." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\def\\x{" << a[0] / k << "}" << endl
                    << "            \\def\\y{" << a[2] / k << "}" << endl
                    << "            \\def\\z{" << a[1] / k << "}" << endl
                    << "            \\coordinate[label=below:${D}$] (D) at (0,0,0);" << endl
                    << "            \\coordinate[label=above:${D_1}$] (D_1) at (0,\\y,0);" << endl
                    << "            \\coordinate[label=below:${A}$] (A) at (0,0,\\z);" << endl
                    << "            \\coordinate[label=above:${A_1}$] (A_1) at (0,\\y,\\z);" << endl
                    << "            \\coordinate[label=below:${C}$] (C) at (\\x,0,0);" << endl
                    << "            \\coordinate[label=above:${C_1}$] (C_1) at (\\x,\\y,0);" << endl
                    << "            \\coordinate[label=below:${B}$] (B) at (\\x,0,\\z);" << endl
                    << "            \\coordinate[label=above:${B_1}$] (B_1) at (\\x,\\y,\\z);" << endl
                    << "            \\draw[thick] (B) -- (A) -- (A_1) -- (B_1) -- (B) -- (C) -- (C_1) -- (B_1) -- (C_1) -- (D_1) -- (A_1);" << endl
                    << "            \\draw[thick,  dashed] (A) -- (D) -- (C) -- (D) -- (D_1);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 4:
                do {
                    for (int i = 0; i < 3; i++)
                        a[i] = rand() % 48 + 2;
                    if (a[0] > a[1])
                        k = a[0] / 3;
                    else
                        k = a[1] / 3;
                    if (a[2] > k * 3)
                        k = a[2] / 3;
                    answer = a[0] * a[1] * a[2] / 2;
                    check = 1;
                    if (answer > 777)
                        check = 0;
                    if (answer - static_cast<int>(answer) != 0)
                        check = 0;
                    if ((a[0] / k < 1) || (a[1] / k < 1) || (a[2] / k < 1))
                        check = 0;
                    if (a[2] / k > 2)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        В прямоугольном параллелепипеде $ABCDA_1B_1C_1D_1$ известно, что $AB=" << a[0] << "$, $BC=" << a[1] << "$, $AA_1=" << a[2] << "$. Найдите объем многогранника, вершинами которого являются точки $ABCDA_1B_1$." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\def\\x{" << a[0] / k << "}" << endl
                    << "            \\def\\y{" << a[2] / k << "}" << endl
                    << "            \\def\\z{" << a[1] / k << "}" << endl
                    << "            \\coordinate[label=below:${D}$] (D) at (0,0,0);" << endl
                    << "            \\coordinate[label=above:${D_1}$] (D_1) at (0,\\y,0);" << endl
                    << "            \\coordinate[label=below:${A}$] (A) at (0,0,\\z);" << endl
                    << "            \\coordinate[label=above:${A_1}$] (A_1) at (0,\\y,\\z);" << endl
                    << "            \\coordinate[label=below:${C}$] (C) at (\\x,0,0);" << endl
                    << "            \\coordinate[label=above:${C_1}$] (C_1) at (\\x,\\y,0);" << endl
                    << "            \\coordinate[label=below:${B}$] (B) at (\\x,0,\\z);" << endl
                    << "            \\coordinate[label=above:${B_1}$] (B_1) at (\\x,\\y,\\z);" << endl
                    << "            \\draw[thick] (B) -- (A) -- (A_1) -- (B_1) -- (B) -- (C) -- (C_1) -- (B_1) -- (C_1) -- (D_1) -- (A_1);" << endl
                    << "            \\draw[thick,  dashed] (A) -- (D) -- (C) -- (D) -- (D_1);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 5:
                do {
                    for (int i = 0; i < 3; i++)
                        a[i] = 3;
                    k = 1.5;
                    S = rand() % 777 + 2;
                    answer = S / 8;
                    check = 1;
                    if (answer > 777)
                        check = 0;
                    if (100*answer - static_cast<int>(100*answer) != 0)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        Объем куба равен $" << S << "$. Найдите объем треугольной призмы,отсекаемой от куба плоскостью, проходящей через середины двух рёбер, выходящих из одной вершины, и параллельной третьему ребру,выходящему из этой же вершины." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\def\\x{" << a[0] / k << "}" << endl
                    << "            \\def\\y{" << a[2] / k << "}" << endl
                    << "            \\def\\z{" << a[1] / k << "}" << endl
                    << "            \\coordinate (D) at (0,0,0);" << endl
                    << "            \\coordinate (D_1) at (0,\\y,0);" << endl
                    << "            \\coordinate (A) at (0,0,\\z);" << endl
                    << "            \\coordinate (A_1) at (0,\\y,\\z);" << endl
                    << "            \\coordinate (C) at (\\x,0,0);" << endl
                    << "            \\coordinate (C_1) at (\\x,\\y,0);" << endl
                    << "            \\coordinate (B) at (\\x,0,\\z);" << endl
                    << "            \\coordinate (B_1) at (\\x,\\y,\\z);" << endl
                    << "            \\coordinate (Q) at (1,0,0);" << endl
                    << "            \\coordinate (Q_1) at (1,2,0);" << endl
                    << "            \\coordinate (W) at (2,0,1);" << endl
                    << "            \\coordinate (W_1) at (2,2,1);" << endl
                    << "            \\draw (B) -- (A) -- (A_1) -- (B_1) -- (B) -- (C) -- (C_1) -- (B_1) -- (C_1) -- (D_1) -- (A_1);" << endl
                    << "            \\draw[dashed] (A) -- (D) -- (C) -- (D) -- (D_1);" << endl
                    << "            \\draw[thick, dashed] (Q) -- (Q_1) -- (C_1) -- (C) -- (Q) -- (W);" << endl
                    << "            \\draw[thick] (W) -- (W_1) -- (C_1) -- (C) -- (W) -- (W_1) -- (Q_1) -- (C_1);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 6:
                do {
                    S = rand() % 10 + 5;
                    a[0] = rand() % 10 + 5;
                    answer = S * a[0] / 3;
                    check = 1;
                    if (10 * answer - static_cast<int>(10 * answer) != 0)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        Найдите объем многогранника, вершинами которого являются вершины $A$, $B$, $C$, $B_1$, правильно треугольной призмы $ABCA_1B_1C_1$, площадь основания которой равна $" << S << "$, а боковое ребро равно $"<< a[0] << "$." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\coordinate[label=below right:${A}$] (A) at (0.5,0,2);" << endl
                    << "            \\coordinate[label=below right:${A_1}$] (A_1) at (0.5,2,2);" << endl
                    << "            \\coordinate[label=below left:${C}$] (C) at (-1,0,0);" << endl
                    << "            \\coordinate[label=below left:${C_1}$] (C_1) at (-1,2,0);" << endl
                    << "            \\coordinate[label=below right:${B}$] (B) at (1,0,0);" << endl
                    << "            \\coordinate[label=below right:${B_1}$] (B_1) at (1,2,0);" << endl
                    << "            \\draw[thick] (C_1) -- (C) -- (A) -- (A_1) -- (C_1) -- (B_1) -- (A_1) -- (A) -- (B) -- (B_1);" << endl
                    << "            \\draw[thick,  dashed] (C) -- (B);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 7:
                do {
                    S = rand() % 10 + 5;
                    a[0] = rand() % 10 + 5;
                    answer = 2*S * a[0] / 3;
                    check = 1;
                    if (10 * answer - static_cast<int>(10 * answer) != 0)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        Найдите объем многогранника, вершинами которого являются вершины $A$, $C$, $A_1$, $B_1$, $C_1$ правильно треугольной призмы $ABCA_1B_1C_1$, площадь основания которой равна $" << S << "$, а боковое ребро равно $" << a[0] << "$." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\coordinate[label=below right:${A}$] (A) at (0.5,0,2);" << endl
                    << "            \\coordinate[label=below right:${A_1}$] (A_1) at (0.5,2,2);" << endl
                    << "            \\coordinate[label=below left:${C}$] (C) at (-1,0,0);" << endl
                    << "            \\coordinate[label=below left:${C_1}$] (C_1) at (-1,2,0);" << endl
                    << "            \\coordinate[label=below right:${B}$] (B) at (1,0,0);" << endl
                    << "            \\coordinate[label=below right:${B_1}$] (B_1) at (1,2,0);" << endl
                    << "            \\draw[thick] (C_1) -- (C) -- (A) -- (A_1) -- (C_1) -- (B_1) -- (A_1) -- (A) -- (B) -- (B_1);" << endl
                    << "            \\draw[thick,  dashed] (C) -- (B);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 8:
                do {
                    V = rand() % 10 + 5;
                    a[0] = rand() % 10 + 5;
                    answer = V/4;
                    check = 1;
                    if (10 * answer - static_cast<int>(10 * answer) != 0)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        Через среднюю линию основания треугольной призмы, объём которой равен $" << V << "$, проведена плоскость, параллельная боковому ребру. Найдите объём отсеченной треугольной призмы." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\coordinate (A) at (0.5,0,2);" << endl
                    << "            \\coordinate (A_1) at (0.5,2,2);" << endl
                    << "            \\coordinate (C) at (-1,0,0);" << endl
                    << "            \\coordinate (C_1) at (-1,2,0);" << endl
                    << "            \\coordinate (B) at (1,0,0);" << endl
                    << "            \\coordinate (B_1) at (1,2,0);" << endl
                    << "            \\coordinate (W) at (0,0,0);" << endl
                    << "            \\coordinate (W_1) at (0,2,0);" << endl
                    << "            \\coordinate (Q) at (0.75,0,1);" << endl
                    << "            \\coordinate (Q_1) at (0.75,2,1);" << endl
                    << "            \\draw (C_1) -- (C) -- (A) -- (A_1) -- (C_1) -- (B_1) -- (A_1) -- (A) -- (B) -- (B_1);" << endl
                    << "            \\draw[dashed] (C) -- (B);" << endl
                    << "            \\draw[thick] (B_1) -- (W_1) -- (Q_1) -- (B_1) -- (B) -- (Q) -- (Q_1);" << endl
                    << "            \\draw[thick, dashed] (Q) -- (W) -- (W_1);" << endl
                    << "            \\draw[thick, dashed] (W) -- (B);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 9:
                do {
                    V = rand() % 10 + 5;
                    a[0] = rand() % 10 + 5;
                    answer = V / 2;
                    check = 1;
                    if (10 * answer - static_cast<int>(10 * answer) != 0)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        Площадь боковой поверхности треугольной призмы равна $" << V << "$. Через среднюю линию основания треугольной призмы, проведена плоскость, параллельная боковому ребру. Найдите площадь боковой поверхности отсеченной треугольной призмы." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\coordinate (A) at (0.5,0,2);" << endl
                    << "            \\coordinate (A_1) at (0.5,2,2);" << endl
                    << "            \\coordinate (C) at (-1,0,0);" << endl
                    << "            \\coordinate (C_1) at (-1,2,0);" << endl
                    << "            \\coordinate (B) at (1,0,0);" << endl
                    << "            \\coordinate (B_1) at (1,2,0);" << endl
                    << "            \\coordinate (W) at (0,0,0);" << endl
                    << "            \\coordinate (W_1) at (0,2,0);" << endl
                    << "            \\coordinate (Q) at (0.75,0,1);" << endl
                    << "            \\coordinate (Q_1) at (0.75,2,1);" << endl
                    << "            \\draw (C_1) -- (C) -- (A) -- (A_1) -- (C_1) -- (B_1) -- (A_1) -- (A) -- (B) -- (B_1);" << endl
                    << "            \\draw[dashed] (C) -- (B);" << endl
                    << "            \\draw[thick] (B_1) -- (W_1) -- (Q_1) -- (B_1) -- (B) -- (Q) -- (Q_1);" << endl
                    << "            \\draw[thick, dashed] (Q) -- (W) -- (W_1);" << endl
                    << "            \\draw[thick, dashed] (W) -- (B);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;
            }
            return Answer;
}

string Cilindr(int i, int AllType)
{
                double S, answer, V, k[2];
            int check = 0;
            int type;
            if(AllType == 0)
                type = rand()%7+1;
            else
                type = AllType;
            int type_1;
            string Answer;
            switch (type)
            {
            case 1:     // Площади конуса и цилиндра вписанных
                S = rand() % 10 + 2;
                type_1 = rand() % 2 + 1;
                if (type_1 == 1)
                    answer = S;
                else
                    answer = 2 * S;
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                if (type_1 == 1)
                    cout << "        Цилиндр и конус имеют общее основание и высоту. Высота цилиндра равна радиусу основания. Площадь боковой поверхности цилиндра равна $" << S << "\\sqrt{2}$. Найдите площадь боковой поверхности конуса." << endl;
                else
                    cout << "        Цилиндр и конус имеют общее основание и высоту. Высота цилиндра равна радиусу основания. Площадь боковой поверхности конуса равна $" << S << "\\sqrt{2}$. Найдите площадь боковой поверхности цилиндра." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\draw[thick, dashed] (1.5,0)  arc (0:180:1.5 and 0.5);" << endl
                    << "            \\draw[thick] (1.5,0)  arc (0:-180:1.5 and 0.5);;" << endl
                    << "            \\draw (1.5,2)  arc (0:180:1.5 and 0.5);" << endl
                    << "            \\draw (1.5,2)  arc (0:-180:1.5 and 0.5);" << endl
                    << "            \\draw (-1.5,0) -- (-1.5,2);" << endl
                    << "            \\draw (1.5,0) -- (1.5,2);" << endl
                    << "            \\draw[dashed] (0,2) -- (0,0) -- (1.5,0);" << endl
                    << "            \\draw[thick] (-1.5,0) -- (0,2) -- (1.5,0);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 2:     // Объемы цилиндра и конуса випаснных
                do {
                    V = rand() % 80 + 3;
                    type_1 = rand() % 2 + 1;
                    if (type_1 == 1)
                        answer = V / 3;
                    else
                        answer = 3 * V;
                    check = 1;
                    if(answer-static_cast<int>(answer)!=0)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                if (type_1 == 1)
                    cout << "        Цилиндр и конус имеют общее основание и высоту. Объём цилиндра равен $" << V << "$. Найдите объем конуса." << endl;
                else
                    cout << "        Цилиндр и конус имеют общее основание и высоту. Объём конуса равен $" << V << "$. Найдите объем цилиндра." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\draw[thick, dashed] (1,0)  arc (0:180:1 and 0.3);" << endl
                    << "            \\draw[thick] (1,0)  arc (0:-180:1 and 0.3);" << endl
                    << "            \\draw (1,2)  arc (0:180:1 and 0.3);" << endl
                    << "            \\draw (1,2)  arc (0:-180:1 and 0.3);" << endl
                    << "            \\draw (-1,0) -- (-1,2);" << endl
                    << "            \\draw (1,0) -- (1,2);" << endl
                    << "            \\draw[dashed] (0,2) -- (0,0) -- (1,0);" << endl
                    << "            \\draw[thick] (-1,0) -- (0,2) -- (1,0);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 3:     // Изменение объема конуса при изменении высоты и радиуса
                S = rand() % 10 + 2;
                type_1 = rand() % 2 + 1;
                if (type_1 == 1)
                    answer = S;
                else
                    answer = S * S;
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                if (type_1 == 1)
                    cout << "        Во сколько раз уменьшится объем конуса, если его высота уменьшится в $" << S << "$ раз, а радиус основания останется прежним?" << endl;
                else
                    cout << "        Во сколько раз уменьшится объем конуса, если радиус основания уменьшится в $" << S << "$ раз, а высота останется прежней?" << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\draw[thick, dashed] (1,0)  arc (0:180:1 and 0.3);" << endl
                    << "            \\draw[thick] (1,0)  arc (0:-180:1 and 0.3);" << endl
                    << "            \\draw[dashed] (0,2) -- (0,0) -- (1,0);" << endl
                    << "            \\draw[thick] (-1,0) -- (0,2) -- (1,0);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 4:     // Объем шара и конуса вписанных
                do {
                    V = rand() % 100 + 2;
                    type_1 = rand() % 2 + 1;
                    if (type_1 == 1)
                        answer = V  / 4;
                    else
                        answer = 4 * V;
                    check = 1;
                    if (answer - static_cast<int>(answer) != 0)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                if (type_1 == 1)
                    cout << "        Конус вписан в шар. Радиус основания конуса равен радиусу шара. Объем шара равен $" << V << "$. Найдите объём конуса." << endl;
                else
                    cout << "        Конус вписан в шар. Радиус основания конуса равен радиусу шара. Объем конуса равен $" << V << "$. Найдите объём шара." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\draw[thick, dashed] (1,0)  arc (0:180:1 and 0.3);" << endl
                    << "            \\draw[thick] (1,0)  arc (0:-180:1 and 0.3);" << endl
                    << "            \\draw[dashed] (0,0) -- (1,0);" << endl
                    << "            \\draw[thick] (-1,0) -- (0,1) -- (1,0);" << endl
                    << "            \\draw (0,0) circle(1);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 5:     // Объемы цилиндров при изменении радиусов и высоты
                do {
                    V = rand() % 50 + 2;
                    k[0] = rand() % 6 + 2;
                    k[1] = rand() % 6 + 2;
                    answer = V * k[1] * k[1] / k[0];
                    check = 1;
                    if (answer * 10 - static_cast<int>(10 * answer) != 0)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        Дано два цилиндра. Объём первого цилиндра равен $" << V << "$. У второго цилиндра высота в $" << k[0] << "$ раза меньше, а радиус основания в $" << k[1] << "$ раза больше, чем у первого. Найдите объем второго цилиндра." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\draw[thick, dashed] (0.7,0)  arc (0:180:0.7 and 0.2);" << endl
                    << "            \\draw[thick] (0.7,0)  arc (0:-180:0.7 and 0.2);" << endl
                    << "            \\draw[thick] (0.7,2)  arc (0:180:0.7 and 0.2);" << endl
                    << "            \\draw[thick] (0.7,2)  arc (0:-180:0.7 and 0.2);" << endl
                    << "            \\draw[thick] (0.7,0) -- (0.7,2);" << endl
                    << "            \\draw[thick] (-0.7,0) -- (-0.7,2);" << endl
                    << "            \\draw[thick, dashed] (4,0)  arc (0:180:1.5 and 0.4);" << endl
                    << "            \\draw[thick] (4,0)  arc (0:-180:1.5 and 0.4);" << endl
                    << "            \\draw[thick] (4,1)  arc (0:180:1.5 and 0.4);" << endl
                    << "            \\draw[thick] (4,1)  arc (0:-180:1.5 and 0.4);" << endl
                    << "            \\draw[thick] (4,0) -- (4,1);" << endl
                    << "            \\draw[thick] (1,0) -- (1,1);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 6:     // Шар в цилиндре объем
                do {
                    V = rand() % 50 + 10;
                    type_1 = rand() % 2 + 1;
                    if (type_1 == 1)
                        answer = 3 * V / 2;
                    else
                        answer = 2 * V / 3;
                    check = 1;
                    if (answer * 10 - static_cast<int>(10*answer) != 0)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                if(type_1==1)
                    cout << "        Шар, объём которого равен $" << V << "$, вписан в цилиндр. Найдите объём цилиндра." << endl;
                else
                    cout << "        Шар вписан в цилиндр, объём которого равен $" << V << "$. Найдите объём шара." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\draw[dashed] (1,0)  arc (0:180:1 and 0.3);" << endl
                    << "            \\draw (1,0)  arc (0:-180:1 and 0.3);" << endl
                    << "            \\draw[dashed] (1,1)  arc (0:180:1 and 0.3);" << endl
                    << "            \\draw (1,1)  arc (0:-180:1 and 0.3);" << endl
                    << "            \\draw (1,2)  arc (0:180:1 and 0.3);" << endl
                    << "            \\draw (1,2)  arc (0:-180:1 and 0.3);" << endl
                    << "            \\draw (1,0) -- (1,2);" << endl
                    << "            \\draw (-1,0) -- (-1,2);" << endl
                    << "            \\draw[thick] (0,1) circle(1);" << endl
                    << "            \\draw[fill=black] (0,1) circle(1pt);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 7:     // Шар в цилиндре площадь
                do {
                    V = rand() % 50 + 10;
                    type_1 = rand() % 2 + 1;
                    if (type_1 == 1)
                        answer = 3 * V / 2;
                    else
                        answer = 2 * V / 3;
                    check = 1;
                    if (answer * 10 - static_cast<int>(10 * answer) != 0)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                if (type_1 == 1)
                    cout << "        Шар, площадь поверхности которого равна $" << V << "$, вписан в цилиндр. Найдите площадь полной поверхности цилиндра." << endl;
                else
                    cout << "        Шар вписан в цилиндр, площадь полной поверхности которого равна $" << V << "$. Найдите площадь поверхности шара." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "            \\draw[dashed] (1,0)  arc (0:180:1 and 0.3);" << endl
                    << "            \\draw (1,0)  arc (0:-180:1 and 0.3);" << endl
                    << "            \\draw[dashed] (1,1)  arc (0:180:1 and 0.3);" << endl
                    << "            \\draw (1,1)  arc (0:-180:1 and 0.3);" << endl
                    << "            \\draw (1,2)  arc (0:180:1 and 0.3);" << endl
                    << "            \\draw (1,2)  arc (0:-180:1 and 0.3);" << endl
                    << "            \\draw (1,0) -- (1,2);" << endl
                    << "            \\draw (-1,0) -- (-1,2);" << endl
                    << "            \\draw[thick] (0,1) circle(1);" << endl
                    << "            \\draw[fill=black] (0,1) circle(1pt);" << endl;
                cout << "\\end{tikzpicture}" << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;
            }
            return Answer;
}

string Graphics(int i, int AllType)
{
    double k, b, x, y, k2, b2, a, x2, y2, c, x1, y1, D, change;
            double answer;
            string Answer;
            int type;
            if(AllType == 0)
                type = rand()%9+1;
            else
                type = AllType;
            int type_1;
            int check = 0;
            switch (type)
            {
            case 1:
                type_1 = rand() % 2 + 1;
                do {
                    k = pow(-1, rand()) * (rand() % 50 + 5);
                    k = k / 10;
                    b = pow(-1, rand()) * (rand() % 3 + 1);
                    check = 1;
                    if ((k * 3 + b > 8) || (-3 * k + b) > 8)
                        check = 0;
                    if ((k * 1 + b <-3) || (-1 * k + b) < -3)
                        check = 0;
                    x = pow(-1, rand()) * (rand() % 10 + 5);
                    y = (k * x) + b;
                    if (static_cast<int>(k * 10) % 5 != 0)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                if (type_1 == 1)
                {
                    cout << "        На рисунке изображён график функции вида $f(x)=kx+b$. Найдите значение $f(" << x << ")$." << endl;
                    answer = y;
                }
                else
                {
                    cout << "        На рисунке изображён график функции вида $f(x)=kx+b$.  Найдите значение $x$ при котором  $f(x)=" << y << "$." << endl;
                    answer = x;
                }
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "        \\pgfplotsset{compat=1.18, width = 8cm}" << endl
                    << "        \\begin{axis}[xmin=-3.5, xmax=3.5," << endl
                    << "ymin = -3.5, ymax = 8.5," << endl
                    << "axis lines = middle," << endl
                    << "xtick = {-3, -2, -1, 0, 1, 2, 3}, " << endl
                    << "xticklabels={${}$, ${}$, ${}$, ${}$, $1$, ${}$, ${}$}," << endl
                    << "ytick={-3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8}," << endl
                    << "yticklabels={${}$, ${}$, ${}$, ${}$, $1$, ${}$, ${}$, ${}$, ${}$, ${}$, ${}$, ${}$}," << endl
                    << "yticklabel style={anchor=east}, xmajorgrids = true, " << endl
                    << "ymajorgrids=true, grid style = dashed, xlabel=$x$, ylabel=$y$,]" << endl
                    << "\\coordinate[label=below left:${0}$] (O) at (0,0);" << endl
                    << "\\addplot[domain=-3.5:3.5,black, thick, samples=1000]{" << k << "*x" << SIGNUr(b,2) << NumberCelUr(b,2) << "};" << endl;

                cout << "\\end{axis}" << endl << "        \\end{tikzpicture}"  << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 2:
                type_1 = rand() % 2 + 1;
                do {
                    k = pow(-1, rand()) * (rand() % 50 + 5);
                    k = k / 10;
                    b = pow(-1, rand()) * (rand() % 3 + 1);
                    k2 = pow(-1, rand()) * (rand() % 50 + 5);
                    k2 = k2 / 10;
                    b2 = pow(-1, rand()) * (rand() % 3 + 1);
                    check = 1;
                    if ((k * 3 + b > 8) || (-3 * k + b) > 8)
                        check = 0;
                    if ((k * 1 + b < -3) || (-1 * k + b) < -3)
                        check = 0;
                    if ((k2 * 3 + b2 > 8) || (-3 * k2 + b2) > 8)
                        check = 0;
                    if ((k2 * 1 + b2 < -3) || (-1 * k2 + b2) < -3)
                        check = 0;
                    if (k != k2)
                    {
                        x = (b2 - b) / (k - k2);
                        y = k * x + b;
                    }
                    else
                        check = 0;
                    if (static_cast<int>(k * 10) % 5 != 0)
                        check = 0;
                    if (static_cast<int>(k2 * 10) % 5 != 0)
                        check = 0;
                    if ((x < 3.5) && (x > -3.5))
                        check = 0;
                    if (10 * x - static_cast<int>(10 * x) != 0)
                        check = 0;
                    if (10 * y - static_cast<int>(10 * y) != 0)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                if (type_1 == 1)
                {
                    cout << "        На рисунке изображены графики двух линейных функций, пересекающиеся в точке $A$. Найдите абсциссу точки $A$." << endl;
                    answer = x;
                }
                else
                {
                    cout << "        На рисунке изображены графики двух линейных функций, пересекающиеся в точке $A$. Найдите ординату точки $A$." << endl;
                    answer = y;
                }
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "        \\pgfplotsset{compat=1.18, width = 8cm}" << endl
                    << "        \\begin{axis}[xmin=-3.5, xmax=3.5," << endl
                    << "ymin = -3.5, ymax = 8.5," << endl
                    << "axis lines = middle," << endl
                    << "xtick = {-3, -2, -1, 0, 1, 2, 3}, " << endl
                    << "xticklabels={${}$, ${}$, ${}$, ${}$, $1$, ${}$, ${}$}," << endl
                    << "ytick={-3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8}," << endl
                    << "yticklabels={${}$, ${}$, ${}$, ${}$, $1$, ${}$, ${}$, ${}$, ${}$, ${}$, ${}$, ${}$}," << endl
                    << "yticklabel style={anchor=east}, xmajorgrids = true, " << endl
                    << "ymajorgrids=true, grid style = dashed, xlabel=$x$, ylabel=$y$,]" << endl
                    << "\\coordinate[label=below left:${0}$] (O) at (0,0);" << endl
                    << "\\addplot[domain=-3.5:3.5,black, thick, samples=1000]{" << k << "*x" << SIGNUr(b, 2) << NumberCelUr(b, 2) << "};" << endl
                    << "\\addplot[domain=-3.5:3.5,black, thick, samples=1000]{" << k2 << "*x" << SIGNUr(b2, 2) << NumberCelUr(b2, 2) << "};" << endl;

                cout << "\\end{axis}" << endl << "        \\end{tikzpicture}"  << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 3:
                type_1 = rand() % 2 + 1;
                do {
                    k = pow(-1, rand()) * (rand() % 50 + 5);
                    k = k / 10;
                    a = pow(-1, rand()) * (rand() % 4 + 1);
                    check = 1;
                    if ((k * 3  > 8) || (-3 * k ) > 8)
                        check = 0;
                    if ((k * 1  < -3) || (-1 * k ) < -3)
                        check = 0;
                    if (static_cast<int>(k * 10) % 5 != 0)
                        check = 0;
                    x = pow((a/k), 2);
                    y = k * x;
                    if (a / k < 0)
                        check = 0;
                    if (10 * x - static_cast<int>(10 * x) != 0)
                        check = 0;
                    if (10 * y - static_cast<int>(10 * y) != 0)
                        check = 0;
                    if (x < 3.5)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                if (type_1 == 1)
                {
                    cout << "        На рисунке изображены графики функций видов $f(x)=a\\sqrt{x}$ и $g(x)=kx$, пересикающиеся в точках $A$ и $B$. Найдите абсциссу точки $B$." << endl;
                    answer = x;
                }
                else
                {
                    cout << "        На рисунке изображены графики функций видов $f(x)=a\\sqrt{x}$ и $g(x)=kx$, пересикающиеся в точках $A$ и $B$. Найдите ординату точки $B$." << endl;
                    answer = y;
                }
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "        \\pgfplotsset{compat=1.18, width = 8cm}" << endl
                    << "        \\begin{axis}[xmin=-3.5, xmax=3.5," << endl
                    << "ymin = -3.5, ymax = 8.5," << endl
                    << "axis lines = middle," << endl
                    << "xtick = {-3, -2, -1, 0, 1, 2, 3}, " << endl
                    << "xticklabels={${}$, ${}$, ${}$, ${}$, $1$, ${}$, ${}$}," << endl
                    << "ytick={-3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8}," << endl
                    << "yticklabels={${}$, ${}$, ${}$, ${}$, $1$, ${}$, ${}$, ${}$, ${}$, ${}$, ${}$, ${}$}," << endl
                    << "yticklabel style={anchor=east}, xmajorgrids = true, " << endl
                    << "ymajorgrids=true, grid style = dashed, xlabel=$x$, ylabel=$y$,]" << endl
                    << "\\coordinate[label=below left:${0}$] (O) at (0,0);" << endl
                    << "\\coordinate[label=below right:${A}$] (A) at (0,0);" << endl
                    << "\\addplot[domain=-3.5:3.5,black, thick, samples=1000]{" << k << "*x};" << endl
                    << "\\addplot[domain=0:3.5,black, thick, samples=1000]{" << a <<  "*sqrt(x)};" << endl;

                cout << "\\end{axis}" << endl << "        \\end{tikzpicture}"  << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 4:
                type_1 = rand() % 2 + 1;
                do {
                    a = pow(-1, rand()) * (rand() % 5 + 1);
                    b = pow(-1, rand()) * (rand() % 5 + 1);
                    c = pow(-1, rand()) * (rand() % 3 + 1);
                    x1 = -1 * (rand() % 3 + 1);
                    x2 = rand() % 3 + 1;
                    y1 = x1 * x1 * a + x1 * b + c;
                    y2 = x2 * x2 * a + x2 * b + c;
                    check = 1;
                    if ((a * 9 + b*3 + c > 8) || (a * 9 -3* b  + c > 8))
                        check = 0;
                    if ((y1 > 8) || (y1 < -3))
                        check = 0;
                    if ((y2 > 8) || (y2 < -3))
                        check = 0;
                    if (y1 - static_cast<int>(y1) != 0)
                        check = 0;
                    if (y2 - static_cast<int>(y2) != 0)
                        check = 0;

                    x = pow(-1, rand()) * (rand() % 10 + 5);
                    y = a*x*x+b*x+c;
                    if (y > 1000)
                        check = 0;
                    
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                if (type_1 == 1)
                {
                    cout << "        На рисунке изображён график функции вида $f(x)=ax^2+bx+c$. Найдите значение $f(" << x << ")$." << endl;
                    answer = y;
                }
                else
                {
                    if(pow(-1,rand())>0)
                        cout << "        На рисунке изображён график функции вида $f(x)=ax^2+bx+c$.  Найдите наименьшее значение $x$ при котором  $f(x)=" << y << "$." << endl;
                    else
                        cout << "        На рисунке изображён график функции вида $f(x)=ax^2+bx+c$.  Найдите наибольшее значение $x$ при котором  $f(x)=" << y << "$." << endl;
                    answer = x;
                }
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "        \\pgfplotsset{compat=1.18, width = 8cm}" << endl
                    << "        \\begin{axis}[xmin=-3.5, xmax=3.5," << endl
                    << "ymin = -3.5, ymax = 8.5," << endl
                    << "axis lines = middle," << endl
                    << "xtick = {-3, -2, -1, 0, 1, 2, 3}, " << endl
                    << "xticklabels={${}$, ${}$, ${}$, ${}$, $1$, ${}$, ${}$}," << endl
                    << "ytick={-3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8}," << endl
                    << "yticklabels={${}$, ${}$, ${}$, ${}$, $1$, ${}$, ${}$, ${}$, ${}$, ${}$, ${}$, ${}$}," << endl
                    << "yticklabel style={anchor=east}, xmajorgrids = true, " << endl
                    << "ymajorgrids=true, grid style = dashed, xlabel=$x$, ylabel=$y$,]" << endl
                    << "\\coordinate[label=below left:${0}$] (O) at (0,0);" << endl
                    << "\\addplot[domain=-3.5:3.5,black, thick, samples=1000]{" << a << "*x*x" << SIGNUr(b, 2) << NumberCelUr(b, 2) << "*x" << SIGNUr(c,2) << NumberCelUr(c,2) << "};" << endl;

                cout << "\\end{axis}" << endl << "        \\end{tikzpicture}"  << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item Возможно ошибка в ответе: " + FormatDouble(answer) + " \n";
                break;

            case 5:
                do {
                    k = pow(-1, rand()) * (rand() % 3 + 1);

                    x = pow(-1, rand()) * (rand() % 10 + 5);
                    y = k/x;
                    check = 1;
                    if (1000*y-static_cast<int>(1000*y)!=0)
                        check = 0;
                    answer = y;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                cout << "        На рисунке изображён график функции вида $f(x)=\\frac{k}{x}$. Найдите значение $f(" << x << ")$." << endl;
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "        \\pgfplotsset{compat=1.18, width = 8cm}" << endl
                    << "        \\begin{axis}[xmin=-3.5, xmax=3.5," << endl
                    << "ymin = -3.5, ymax = 8.5," << endl
                    << "axis lines = middle," << endl
                    << "xtick = {-3, -2, -1, 0, 1, 2, 3}, " << endl
                    << "xticklabels={${}$, ${}$, ${}$, ${}$, $1$, ${}$, ${}$}," << endl
                    << "ytick={-3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8}," << endl
                    << "yticklabels={${}$, ${}$, ${}$, ${}$, $1$, ${}$, ${}$, ${}$, ${}$, ${}$, ${}$, ${}$}," << endl
                    << "yticklabel style={anchor=east}, xmajorgrids = true, " << endl
                    << "ymajorgrids=true, grid style = dashed, xlabel=$x$, ylabel=$y$,]" << endl
                    << "\\coordinate[label=below left:${0}$] (O) at (0,0);" << endl
                    << "\\addplot[domain=-3.5:-0.1,black, thick, samples=1000]{" << k << "/x};" << endl
                    << "\\addplot[domain=0.1:3.5,black, thick, samples=1000]{" << k << "/x};" << endl;

                cout << "\\end{axis}" << endl << "        \\end{tikzpicture}"  << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 6:
                type_1 = rand() % 2 + 1;
                do {
                    a = pow(-1, rand()) * (rand() % 5 + 1);
                    b = pow(-1, rand()) * (rand() % 5 + 1);
                    c = 0;
                    x1 = -1 * (rand() % 3 + 1);
                    x2 = rand() % 3 + 1;
                    y1 = x1 * x1 * a + x1 * b + c;
                    y2 = x2 * x2 * a + x2 * b + c;
                    check = 1;
                    if ((a * 9 + b * 3 + c > 8) || (a * 9 - 3 * b + c > 8))
                        check = 0;
                    if ((y1 > 8) || (y1 < -3))
                        check = 0;
                    if ((y2 > 8) || (y2 < -3))
                        check = 0;
                    if (y1 - static_cast<int>(y1) != 0)
                        check = 0;
                    if (y2 - static_cast<int>(y2) != 0)
                        check = 0;

                    k = pow(-1, rand()) * (rand() % 50 + 5);
                    k = k / 10;
                    if ((k * 3  > 8) || (-3 * k) > 8)
                        check = 0;
                    if ((k * 1  < -3) || (-1 * k ) < -3)
                        check = 0;
                    if (static_cast<int>(k * 10) % 5 != 0)
                        check = 0;

                    if (b == k)
                        check = 0;
                    x = (k-b) / a;
                    y = k * x;
                    if (10 * x - static_cast<int>(x * 10) != 0)
                        check = 0;

                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                if (type_1 == 1)
                {
                    cout << "        На рисунке изображёны графики функций видов $f(x)=ax^2+bx+c$ и $g(x)=kx$, пересекающиеся в точках $A$ и $B$. Найдите абсциссу точки $B$." << endl;
                    answer = x;
                }
                else
                {
                    cout << "        На рисунке изображёны графики функций видов $f(x)=ax^2+bx+c$ и $g(x)=kx$, пересекающиеся в точках $A$ и $B$. Найдите ординату точки $B$." << endl;
                    answer = y;
                }
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "        \\pgfplotsset{compat=1.18, width = 8cm}" << endl
                    << "        \\begin{axis}[xmin=-3.5, xmax=3.5," << endl
                    << "ymin = -3.5, ymax = 8.5," << endl
                    << "axis lines = middle," << endl
                    << "xtick = {-3, -2, -1, 0, 1, 2, 3}, " << endl
                    << "xticklabels={${}$, ${}$, ${}$, ${}$, $1$, ${}$, ${}$}," << endl
                    << "ytick={-3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8}," << endl
                    << "yticklabels={${}$, ${}$, ${}$, ${}$, $1$, ${}$, ${}$, ${}$, ${}$, ${}$, ${}$, ${}$}," << endl
                    << "yticklabel style={anchor=east}, xmajorgrids = true, " << endl
                    << "ymajorgrids=true, grid style = dashed, xlabel=$x$, ylabel=$y$,]" << endl
                    << "\\coordinate[label=below left:${0}$] (O) at (0,0);" << endl
                    << "\\coordinate[label=below right:${A}$] (A) at (0,0);" << endl
                    << "\\addplot[domain=-3.5:3.5,black, thick, samples=1000]{" << SIGNUr(a,1) << NumberCelUr(a,2) << "*x*x" << SIGNUr(b,2) << NumberCelUr(b,2) << "*x};" << endl
                    << "\\addplot[domain=-3.5:3.5,black, thick, samples=1000]{" << k << "*x};" << endl;

                cout << "\\end{axis}" << endl << "        \\end{tikzpicture}"  << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 7:
                type_1 = rand() % 2 + 1;
                do {
                    k = pow(-1, rand()) * (rand() % 6 + 1);

                    a = pow(-1, rand()) * (rand() % 50 + 5);
                    a = a / 10;
                    b = pow(-1, rand()) * (rand() % 3 + 1);
                    check = 1;
                    if ((a * 3 + b > 8) || (-3 * a + b) > 8)
                        check = 0;
                    if ((a * 1 + b < -3) || (-1 * a + b) < -3)
                        check = 0;
                    if (static_cast<int>(a * 10) % 5 != 0)
                        check = 0;

                    D = b * b + 4 * a * k;
                    if ((D > 0) && (D < 1000)&&(sqrt(D)-static_cast<int>(sqrt(D))==0))
                    {
                        x1 = (-1*b-sqrt(D)) / (2 * a);
                        x2 = (-1 * b + sqrt(D)) / (2 * a);
                        if (x1 > x2)
                        {
                            change = x1;
                            x1 = x2;
                            x2 = change;
                        }
                        if (x1 - static_cast<int>(x1) != 0)
                            check = 0;
                        if (x2 - static_cast<int>(x2) != 0)
                            check = 0;
                        if (x1 < -3)
                            check = 0;
                        if (a / k < 0)
                            check = 0;
                        x = x2;
                        y = a * x + b;
                        if (x2 < 4)
                            check = 0;
                    }
                    else
                    {
                        check = 0;
                    }

                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                if (type_1 == 1)
                {
                    cout << "        На рисунке изображёны графики функций видов $f(x)=\\frac{k}{x}$ и $g(x)=ax+b$, пересекающиеся в точках $A$ и $B$. Найдите абсциссу точки $B$." << endl;
                    answer = x;
                }
                else
                {
                    cout << "        На рисунке изображёны графики функций видов $f(x)=\\frac{k}{x}$ и $g(x)=ax+b$, пересекающиеся в точках $A$ и $B$. Найдите ординату точки $B$." << endl;
                    answer = y;
                }
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "        \\pgfplotsset{compat=1.18, width = 8cm}" << endl
                    << "        \\begin{axis}[xmin=-3.5, xmax=3.5," << endl
                    << "ymin = -3.5, ymax = 8.5," << endl
                    << "axis lines = middle," << endl
                    << "xtick = {-3, -2, -1, 0, 1, 2, 3}, " << endl
                    << "xticklabels={${}$, ${}$, ${}$, ${}$, $1$, ${}$, ${}$}," << endl
                    << "ytick={-3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8}," << endl
                    << "yticklabels={${}$, ${}$, ${}$, ${}$, $1$, ${}$, ${}$, ${}$, ${}$, ${}$, ${}$, ${}$}," << endl
                    << "yticklabel style={anchor=east}, xmajorgrids = true, " << endl
                    << "ymajorgrids=true, grid style = dashed, xlabel=$x$, ylabel=$y$,]" << endl
                    << "\\coordinate[label=below left:${0}$] (O) at (0,0);" << endl
                    << "\\coordinate[label=below right:${A}$] (A) at (" << x1 << "," << (a*x1+b) << ");" << endl
                    << "\\addplot[domain=-3.5:-0.1,black, thick, samples=1000]{" << SIGNUr(k, 1) << NumberCelUr(k, 2) << "/x};" << endl
                    << "\\addplot[domain=0.1:3.5,black, thick, samples=1000]{" << SIGNUr(k, 1) << NumberCelUr(k, 2) << "/x};" << endl
                    << "\\addplot[domain=-3.5:3.5,black, thick, samples=1000]{" << a << "*x" << SIGNUr(b,2) << NumberCelUr(b,2) << "};" << endl;

                cout << "\\end{axis}" << endl << "        \\end{tikzpicture}"  << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 8:
                type_1 = rand() % 2 + 1;
                do {
                    a = rand() % 4 + 2;
                    if (pow(-1, rand()) > 0)
                        a = 1 / a;
                    check = 1;
                    x = pow(-1, rand()) * (rand() % 10 + 3);
                    y = pow(a, x);
                    if (100 * y - static_cast<int>(100 * y) != 0)
                        check = 0;
                    if (y > 1000)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                if (type_1 == 1)
                {
                    cout << "        На рисунке изображён график функции вида $f(x)=a^x$. Найдите значение $f(" << x << ")$." << endl;
                    answer = y;
                }
                else
                {
                    cout << "        На рисунке изображён график функции вида $f(x)=a^x$.  Найдите значение $x$ при котором  $f(x)=" << y << "$." << endl;
                    answer = x;
                }
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "        \\pgfplotsset{compat=1.18, width = 8cm}" << endl
                    << "        \\begin{axis}[xmin=-3.5, xmax=3.5," << endl
                    << "ymin = -3.5, ymax = 8.5," << endl
                    << "axis lines = middle," << endl
                    << "xtick = {-3, -2, -1, 0, 1, 2, 3}, " << endl
                    << "xticklabels={${}$, ${}$, ${}$, ${}$, $1$, ${}$, ${}$}," << endl
                    << "ytick={-3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8}," << endl
                    << "yticklabels={${}$, ${}$, ${}$, ${}$, $1$, ${}$, ${}$, ${}$, ${}$, ${}$, ${}$, ${}$}," << endl
                    << "yticklabel style={anchor=east}, xmajorgrids = true, " << endl
                    << "ymajorgrids=true, grid style = dashed, xlabel=$x$, ylabel=$y$,]" << endl
                    << "\\coordinate[label=below left:${0}$] (O) at (0,0);" << endl
                    << "\\addplot[domain=-3.5:3.5,black, thick, samples=1000]{" << a << "^x};" << endl;

                cout << "\\end{axis}" << endl << "        \\end{tikzpicture}"  << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 9:
                type_1 = rand() % 2 + 1;
                do {
                    a = rand() % 3 + 2;
                    if (pow(-1, rand()) > 0)
                        a = 1 / a;
                    check = 1;
                    x = pow(-1, rand()) * (rand() % 10 + 3);
                    y = log(x)/log(a);
                    if (100 * y - static_cast<int>(100 * y) != 0)
                        check = 0;
                    if (y > 1000)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item\n" << endl << "\\begin{geometrytask}" << endl;
                if (type_1 == 1)
                {
                    cout << "        На рисунке изображён график функции вида $f(x)=\\log_{a}(x)$. Найдите значение $f(" << x << ")$." << endl;
                    answer = y;
                }
                else
                {
                    cout << "        На рисунке изображён график функции вида $f(x)=\\log_{a}(x)$.  Найдите значение $x$ при котором  $f(x)=" << y << "$." << endl;
                    answer = x;
                }
                cout << "\\end{geometrytask}\\hfill" << endl << "\\begin{tikzpicture}[scale=0.7, baseline=(current bounding box.center)] % Добавлено baseline" << endl
                    << "        \\pgfplotsset{compat=1.18, width = 8cm}" << endl
                    << "        \\begin{axis}[xmin=-0.5, xmax=6.5," << endl
                    << "ymin = -3.5, ymax = 8.5," << endl
                    << "axis lines = middle," << endl
                    << "xtick = {-1, 0, 1, 2, 3, 4, 5, 6}, " << endl
                    << "xticklabels={${}$, $1$, ${}$, ${}$, ${}$, ${}$, ${}$}," << endl
                    << "ytick={-3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8}," << endl
                    << "yticklabels={${}$, ${}$, ${}$, ${}$, $1$, ${}$, ${}$, ${}$, ${}$, ${}$, ${}$, ${}$}," << endl
                    << "yticklabel style={anchor=east}, xmajorgrids = true, " << endl
                    << "ymajorgrids=true, grid style = dashed, xlabel=$x$, ylabel=$y$,]" << endl
                    << "\\coordinate[label=below left:${0}$] (O) at (0,0);" << endl
                    << "\\addplot[domain=0.01:6.5,black, thick, samples=1000]{ln(x)/ln(" << a << ")};" << endl;

                cout << "\\end{axis}" << endl << "        \\end{tikzpicture}"  << endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;
             }
             return Answer;
}

string ZadPricl(int AllType)
{
                double a[10], answer, x1, x2, change, x[2], D;
            int type;
            if(AllType == 0)
                type = rand()%20+1;
            else
                type = AllType;
            int type_1;
            int check = 0;
            string Answer;
            switch (type)
            {
            case 1:
                do {
                    x1 = 1000;
                    x2 = 1000;
                    a[0] = rand() % 5 + 1;
                    a[0] = a[0] * 10;
                    a[1] = a[0] - 10;
                    a[2] = a[0] + 10;
                    a[3] = rand()%60 + 11;
                    a[4] = a[3] + 20;
                    a[5] = a[0] * a[3] / (a[3] - a[0]);
                    a[6] = a[0] * a[4] / (a[4] - a[0]);
                    check = 1;
                    if ((a[5] > a[1]) && (a[5] < a[2]))
                        x1 = a[5];
                    if ((a[6] > a[1]) && (a[6] < a[2]))
                        x1 = a[6];
                    if (((x1 > a[1]) && (x1 < a[2])) || ((x2 > a[1]) && (x2 < a[2])))
                    {
                        if (x1 > x2)
                        {
                            change = x1;
                            x1 = x2;
                            x2 = change;
                        }
                        answer = x1;
                        if (answer - static_cast<int>(answer) != 0)
                            check = 0;
                    }
                    else
                        check = 0;
                } while (check != 1);
                cout << "\\item     Для получения на экране увеличенного изображения лампочки в лаборатории используется собирающая линза с главным фокусным расстоянием $f = " << a[0] << "$ см. Расстояние $d_1$ от линзы до лампочки может изменяться в пределах от " << a[1] << " до " << a[2] << " см, а расстояние $d_2$ от линзы до экрана — в пределах от " << a[3] << " до " << a[4] << " см. Изображение на экране будет чётким, если выполнено соотношение" << endl
                    << "$$\\frac{1}{d_1}+\\frac{1}{d_2}=\\frac{1}{f}$$" << endl
                    << "Укажите, на каком наименьшем расстоянии от линзы нужно поместить лампочку, чтобы её изображение на экране было чётким. Ответ выразите в сантиметрах." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 2:
                do {
                    a[0] = rand() % 70 + 20;
                    a[1] = rand() % 20 + 5;
                    a[2] = rand() % 100 + 20;
                    check = 1;
                    D = 4 * pow(a[0], 2) + 8 * a[1] * a[2];
                    if ((D < 10000) && (sqrt(D) - static_cast<int>(sqrt(D)) == 0))
                    {
                        x[0] = (-2*a[0]-sqrt(D)) / (2 * a[1]);
                        x[1] = (-2 * a[0] + sqrt(D)) / (2 * a[1]);
                        if (x[0] < 0)
                        {
                            answer = x[1] * 60;
                            if (answer - static_cast<int>(answer) != 0)
                                check = 0;
                        }
                        else
                            check = 0;
                    }
                    else
                        check = 0;
                } while (check != 1);
                cout << "\\item     Мотоциклист, движущийся по городу со скоростью $\\upsilon_0=" << a[0] << "\\frac{\\text{км}}{\\text{ч}}$, выезжает из него и сразу после выезда начинает разгоняться с постоянным ускорением $a=" << a[1] << "\\frac{\\text{км}}{\\text{ч}^2}$. Расстояние(в км) от мотоциклиста до города вычисляется по формуле $$S=\\upsilon_0t+\\frac{at^2}{2}$$ где t — время в часах, прошедшее после выезда из города. Определите время, прошедшее после выезда мотоциклиста из города, если известно, что за это время он удалился от города на " << a[2] << " км. Ответ дайте в минутах." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 3:
                do{
                    a[0] = rand()%8+2;
                    a[1] = rand()%98+2;
                    a[1] = a[1]/10;
                    a[2] = rand()%8+2;
                    a[3] = rand()%8+2;
                    a[4] = rand()%8+2;
                    a[5] = rand()%8+2;
                    change = NOD(a[3], a[4]);
                    a[3] = a[3]/change;
                    a[4] = a[4]/change;

                    answer = pow((a[1]*pow(10,a[2])/(a[0]*pow(10,a[5]))),(a[4]/a[3]));
                    check = 1;
                    if(a[4]==1)
                        check = 0;
                    if(a[3]==1)
                        check = 0;
                    if(answer*10 - static_cast<int>(answer*10)!=0)
                        check = 0;
                    if(answer>1000)
                        check = 0;
                    if(answer == 1)
                        check = 0;
                }while(check!=1);
                cout << "\\item     При адиабатическом процессе для идеального газа выполняется закон \\\\$pV^k=" << a[1] << "\\cdot 10^{" << a[2] << "}\\text{Па}\\cdot\\text{м}^5$, где $p$ -- давление в газе в паскалях, $V$ -- объём газа (в $\\text{м}^3$), $k=\\frac{" << a[3] << "}{" << a[4] << "}$. Найдите, какой объем $V$ будет занимать газ, при давлении $p$, равном $" << a[0] << "\\cdot10^{" << a[5] << "}\\text{Па}$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 4:
                do{
                    a[0] = rand()%100 + 60;
                    a[1] = rand()%100 + 20;
                    a[2] = rand()%20 + 2;
                    D = pow(a[1],2) - 2*a[2]*a[0];
                    check = 1;
                    if((D>0)&&(D<1500)&&(sqrt(D)-static_cast<int>(sqrt(D))==0))
                    {
                        x1 = (a[1]-sqrt(D))/(a[2]);
                        x2 = (a[1]+sqrt(D))/(a[2]);
                        if(x1>x2)
                        {
                            change = x1;
                            x1 = x2;
                            x2 = change;
                        }
                        if(x1<0)
                            check = 0;
                        answer = x1;
                        if(answer*10 - static_cast<int>(10*answer)!=0)
                            check = 0;
                        if(x2- static_cast<int>(x2)!=0)
                            check = 0;
                    }
                    else
                        check = 0;
                }while(check!=1);
                cout << "\\item     Автомобиль, движущийся со скоростью $\\upsilon_0=" << a[1] << "\\frac{\\text{м}}{\\text{с}}$, начал торможение с постоянным ускорением $a=" << a[2] << "\\frac{\\text{м}}{\\text{с}^2}$. За $t$ секунд после начала торможения он прошел путь $S=\\upsilon_0t-\\frac{at^2}{2}$. Определите время, прошедшее с начала торможения, если известно, что за это время автомобиль проехал $" << a[0] << "$ метров. Ответ дайте в секундах." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 5:
                do{
                    a[0] = rand()%60 + 10;
                    a[0] = 5.7;
                    a[1] = 8;
                    a[2] = rand()%2000 + 700;
                    a[3] = rand()%40 + 10;
                    a[4] = rand()%60 + 10;
                    a[4] = a[4]/10;
                    a[5] = rand()%40 + 10;
                    answer = (a[4]*pow(10,a[5])*a[2]*pow(10,a[1]))/(pow(10,a[3])*a[0]);
                    answer = pow(answer,0.25);
                    check = 1;
                    if(answer - static_cast<int>(answer)!=0)
                        check = 0;
                    if(answer > 2000)
                        check = 0;
                    if(answer<100)
                        check = 0;
                }while(check!=1);
                cout << "\\item     Для определения эффективной температуры звёзд используют закон Стефана-Больцмана, согласно которому $P=\\sigma ST^4$, где $P$ -- мощность излучения звезды (в Вт), $\\sigma=5.7\\cdot 10^{-8} \\frac{\\text{Вт}}{\\text{м}^2\\cdot\\text{К}^4}$ -- постоянная, $S$ -- площадь поверхности звезды (в $\\text{м}^2$), а $T$ -- температура (в кельвинах). Известно, что площадь некоторой звезды равна $\\frac{1}{" << a[2] << "}\\cdot 10^{" << a[3] << "}\\text{м}^2$, а мощность её излучения равна $" << a[4] << "\\cdot 10^{" << a[5] << "}\\text{Вт}$. Найдите температуру этой звезды. Ответ дайте в кельвинах." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 6:
                do{
                    a[0] = rand()%400 + 100;
                    a[2] = 300;
                    a[1] = rand()%40 + 2;
                    answer = a[2]*(1-(a[0]/(a[0]+a[1])));
                    check = 1;
                    if(10*answer - static_cast<int>(10*answer)!=0)
                        check = 0;
                }while(check!=1);
                cout << "\\item     Перед отправкой тепловоз издал гудок с частотой $f_0=" << a[0] << "\\text{Гц}$. Чуть позже гудок издал подъезжающий к платформе тепловоз. Из-за эффекта Доплера частота второго гудка $f$ (в Гц) больше первого: она зависит от скорости тепловоза $\\upsilon$ (в $\\frac{\\text{м}}{\\text{с}}$) по закону: $$f(\\upsilon)=\\frac{f_0}{1-\\frac{\\upsilon}{c}}$$ где $c$ -- скорость звука (в $\\frac{\\text{м}}{\\text{с}}$). Человек, стоящий на платформе, различает сигналы по тону, если они отличаются не менее чем на " << a[1] << " Гц. Определите, с какой минимальной скоростью приближался к платформе тепловоз, если человек смог различить сигналы, а $c = 300 \\frac{\\text{м}}{\\text{с}}$. Ответ дайте в $\\frac{\\text{м}}{\\text{с}}$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 7:
                do{
                    a[0] = rand()%200 + 100;
                    a[1] = rand()%40 + 2;
                    answer = a[0]/a[1];
                    check = 1;
                    if(answer - static_cast<int>(answer)!=0)
                        check = 0;
                }while(check!=1);
                cout << "\\item     Сила тока $I$ (в А) в электросети вычисляется по закону Ома: $I=\\frac{U}{R}$, где $U$ — напряжение электросети (в В), $R$ — сопротивление подключаемого электроприбора (в Ом). Электросеть прекращает работать, если сила тока превышает $" << a[1] << "$ А. Определите, какое наименьшее сопротивление может быть у электроприбора, подключаемого к электросети с напряжением $" << a[0] << "$ В, чтобы электросеть продолжала работать. Ответ дайте в омах." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 8:
                do{
                    a[0] = rand()%40+10;
                    a[1] = rand()%40+10;
                    check = 1;
                    if(a[1]<a[0])
                        check = 0;
                    answer = a[0]*a[1]/(a[1]-a[0]);
                    if(answer - static_cast<int>(answer)!=0)
                        check = 0;
                }while(check!=1);
                cout << "\\item     В розетку электросети подключена электрическая духовка, сопротивление которой составляет $R_1=" << a[1] << "$ Ом. Параллельно с ней в розетку предполагается подключить электрообогреватель, сопротивление которого $R_2$ (в Ом). При параллельном соединении двух электроприборов с сопротивлениями $R_1$ и $R_2$ их общее сопротивление $R$ вычисляется по формуле: $$R=\\frac{R_1R_2}{R_1+R_2}$$ Для нормального функционирования электросети общее сопротивление в ней должно быть не меньше $" << a[0] << "$ Ом. Определите наименьшее возможное сопротивление электрообогревателя. Ответ дайте в омах." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;
                
            case 9:
                do{
                    a[0] = rand()%60+10;
                    a[1] = rand()%15+2;
                    answer = pow(a[0],2)/(2*a[1]);
                    check = 1;
                    if(answer - static_cast<int>(answer)!=0)
                        check = 0;
                }while(check!=1);
                cout << "\\item     Автомобиль разгоняется на прямолинейном участке шоссе с постоянным ускорением $a$ (в $\\frac{\\text{км}}{\\text{ч}^2}$). Скорость $\\upsilon$ (в $\\frac{\\text{км}}{\\text{ч}}$) вычисляется по формуле $\\upsilon=\\sqrt{2la}$, где $l$ — пройденный автомобилем путь (в км). Найдите ускорение, с которым должен двигаться автомобиль, чтобы, проехав $" << a[1] << "$ км, приобрести скорость $" << a[0] << "$ $\\frac{\\text{км}}{\\text{ч}}$. Ответ дайте в $\\frac{\\text{км}}{\\text{ч}^2}$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 10:
                do{
                    a[2] = rand()%15+2;
                    a[3] = rand()%15+2;
                    a[0] = rand()%200+10;
                    a[1] = rand()%200+10;
                    answer = (a[1]*a[2] + a[0]*a[3])/(a[0]-a[1]);
                    check = 1;
                    if(a[0]<a[1])
                        check = 0;
                    if(answer - static_cast<int>(answer)!=0)
                        check = 0;
                    if(answer>1000)
                        check = 0;
                }while(check!=1);
                cout << "\\item     При сближении источника и приёмника звуковых сигналов, движущихся в некоторой среде по прямой навстречу друг другу со скоростями $u$ и $\\upsilon$ (в $\\frac{\\text{м}}{\\text{с}}$) соответственно, частота звукового сигнала $f$ (в Гц), регистрируемого приёмником, вычисляется по формуле $$f=f_0\\cdot\\frac{c+u}{c-\\upsilon}$$ где $f_0 = " << a[1] << "$ Гц -- частота исходного сигнала, $c$ -- скорость распространения сигнала в среде (в $\\frac{\\text{м}}{\\text{с}}$), а $u = " << a[2] << " \\frac{\\text{м}}{\\text{с}}$ и $\\upsilon = " << a[3] << " \\frac{\\text{м}}{\\text{с}}$ -- скорости источника и приёмника относительно среды. При какой скорости распространения сигнала в среде частота сигнала в приёмнике будет равна " << a[0] << " Гц? Ответ дайте в $\\frac{\\text{м}}{\\text{с}}$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 11:
                type_1 = rand()%4 +1;
                switch(type_1)
                {
                case 1:
                    answer = 60;
                    break;

                case 2:
                    answer = 90;
                    break;

                case 3:
                    answer = 120;
                    break;

                case 4:
                    answer = 180;
                    break;
                }
                do{
                    a[0] = rand()%300 + 100;
                    a[1] = rand()%20 + 1;
                    a[2] = rand()%20 + 1;
                    check = 1;
                    switch(type_1)
                    {
                    case 1:
                        if((a[0]/(a[1]*pow(a[2],2)))!=0.25)
                            check = 0;
                        break;

                    case 2:
                        if((a[0]/(a[1]*pow(a[2],2)))!=0.5)
                            check = 0;
                        break;

                    case 3:
                        if((a[0]/(a[1]*pow(a[2],2)))!=0.75)
                            check = 0;
                        break;

                    case 4:
                        if((a[0]/(a[1]*pow(a[2],2)))!=1)
                            check = 0;
                        break;
                    }
                }while(check!=1);
                cout << "\\item     Два тела, массой $m=" << a[1] << "$ кг каждое, движутся с одинаковой скоростью $\\upsilon=" << a[2] << "\\frac{\\text{м}}{\\text{с}}$ под углом $2\\alpha$ друг к другу. Энергия (в Дж), выделяющаяся при их абсолютно неупругом соударении, вычисляется по формуле $Q=m\\upsilon^2\\sin^2(\\alpha)$, где $m$ -- масса (в кг), $\\upsilon$ -- скорость (в $\\frac{\\text{м}}{\\text{с}}$). Найдите, под каким углом $2\\alpha$ должны двигаться тела, чтобы в результате соударения выделилась энергия, равная " << a[0] << " Дж. Ответ дайте в градусах." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 12:
                do{
                    a[0] = rand()%30 + 1;
                    a[1] = rand()%30 + 1;
                    a[1] = a[1]/10;
                    a[2] = rand()%30 + 1;
                    a[2] = a[2]/10;
                    check = 1;
                    D = pow(a[0],2) - 4*5*(a[1]-a[2]);
                    if((D>0)&&(D<1300)&&(sqrt(D)-static_cast<int>(sqrt(D))==0)&&(a[1]>a[2]))
                    {
                        x1 = (a[0]-sqrt(D))/(10);
                        x2 = (a[0]+sqrt(D))/(10);
                        if(x1<0)
                            check = 0;
                        if(10*x1-static_cast<int>(10*x1)!=0)
                            check = 0;
                        if(10*x2-static_cast<int>(10*x2)!=0)
                            check = 0;
                        answer = x2 - x1;
                    }
                    else
                        check = 0;
                }while(check!=1);
                cout << "\\item     Высота над землёй подброшенного вверх мяча меняется по закону: $$h(t)=" << a[2] << "+" << a[0] << "t-5t^2$$ где $h$ --  высота в метрах, $t$ -- время в секундах, прошедшее с момента броска. Сколько секунд мяч будет находиться на высоте не менее " << a[1] << " метров?" << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 13:
                do{
                    a[0] = rand()%100 + 2;
                    a[1] = rand()%10 + 1;
                    a[2] = rand()%10 + 1;
                    a[3] = rand()%20 + 1;
                    change = NOD(a[1],a[2]);
                    a[1] = a[1]/change;
                    a[2] = a[2]/change;
                    D = pow((a[1]*a[0]),2)-4*a[2]*a[0]*a[2]*a[3];
                    check = 1;
                    if((D>0)&&(sqrt(D)-static_cast<int>(sqrt(D))==0)&&(a[2]!=1))
                    {
                        x1 = (a[1]*a[0]-sqrt(D))/(2*a[2]);
                        x2 = (a[1]*a[0]+sqrt(D))/(2*a[2]);
                        answer = x1;
                        if(x1<0)
                            check = 0;
                        if(x2<0)
                            check = 0;
                        if(x1-static_cast<int>(x1)!=0)
                            check = 0;
                        if(x2-static_cast<int>(x2)!=0)
                            check = 0;
                    }
                    else
                        check = 0;
                }while(check!=1);
                cout << "\\item     В боковой стенке высокого цилиндрического бака у самого дна закреплён кран. После его открытия вода начинает вытекать из бака, при этом высота столба воды в нём меняется по закону $H(t)=at^2+bt+H_0$, где $Н$ — высота столба воды в метрах, $H_0$ = " << a[3] << " м -- начальный уровень воды, $a = \\frac{1}{" << a[0] << "} \\frac{\\text{м}}{\\text{мин}^2}$ и $b = -\\frac{" << a[1] << "}{" << a[2] << "} \\frac{\\text{м}}{\\text{мин}}$ -- постоянные, $t$ -- время в минутах, прошедшее с момента открытия крана. Сколько минут вода будет вытекать из бака?" << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 14:
                do{
                    a[0] = rand()%400+100;
                    a[1] = rand()%50+3;
                    a[2] = 1500;
                    answer = a[0]*(a[1]+a[2])/(a[2]-a[1]);
                    check = 1;
                    if(answer-static_cast<int>(answer)!=0)
                        check = 0;
                }while(check!=1);
                cout << "\\item     Локатор батискафа, равномерно погружающегося вертикально вниз, испускает ультразвуковые импульсы частотой " << a[0] << " МГц. Скорость погружения батискафа $\\upsilon$ (в $\\frac{\\text{м}}{\\text{с}}$) вычисляется по формуле $$\\upsilon=c\\cdot\\frac{f-f_0}{f+f_0}$$ где $c=1500\\frac{\\text{м}}{\\text{с}}$ -- скорость звука в воде, $f_0$ -- частота испускаемых импульсов (в МГц), $f$ -- частота отражённого от дна сигнала (в МГц), регистрируемая приёмником. Определите частоту отражённого сигнала, если скорость погружения батискафа равна $" << a[1] << "\\frac{\\text{м}}{\\text{с}}$. Ответ дайте в МГц." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 15:
                do{
                    a[0] = rand()%10+3;
                    a[1] = rand()%1000 + 20;
                    a[2] = rand()%150 + 20;
                    check = 1;
                    if(a[1]>a[2])
                    {
                        answer = a[0]*log(a[1]/a[2])/log(2);
                        if(answer-static_cast<int>(answer)!=0)
                            check = 0;
                        if(answer==a[0])
                            check = 0;
                    }
                    else
                        check = 0;
                }while(check!=1);
                cout << "\\item     В ходе распада радиоактивного изотопа его масса $m$ (в мг) уменьшается по закону $m=m_0\\cdot 2^{-\\frac{\\tau}{T}}$, где $m_0$ -- начальная масса изотопа (в мг), $\\tau$ -- время, прошедшее от начального момента, в минутах, $T$ -- период полураспада в минутах. В начальный момент времени масса изотопа " << a[1] << " мг. Период его полураспада составляет " << a[0] << " минут. Найдите, через сколько минут масса изотопа будет равна " << a[2] << " мг." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 16:
                do{
                    a[0] = rand()%10+1;
                    a[1] = rand()%200+5;
                    a[2] = rand()%2000+100;
                    a[3] = rand()%2000+100;
                    check = 1;
                    if(a[2]>a[3])
                    {
                        D = pow(a[1],2) -4*a[0]*(a[2]-a[3]);
                        if((D>0)&&(D<1300)&&(sqrt(D)-static_cast<int>(sqrt(D))==0))
                        {
                            x1 = (a[1]-sqrt(D))/(2*a[0]);
                            x2 = (a[1]+sqrt(D))/(2*a[0]);
                            if(x1-static_cast<int>(x1)!=0)
                                check = 0;
                            if(x2-static_cast<int>(x2)!=0)
                                check = 0;
                            answer = x1;
                            if(a[0]==1)
                                check = 0;
                        }
                        else
                            check = 0;
                    }
                    else
                        check = 0;
                }while(check!=1);
                cout << "\\item     Для нагревательного элемента некоторого прибора экспериментально была получена зависимость температуры (в К) от времени работы: $T(t)=T_0+bt+at^2$, где $t$ -- время (в мин.), $T_0=" << a[3] << "\\text{К}$, $a=-" << a[0] << "\\frac{\\text{К}}{\\text{мин}^2}$, $b = " << a[1] << "\\frac{\\text{К}}{\\text{мин}}$. Известно, что при температуре нагревательного элемента свыше " << a[2] << " К прибор может испортиться, поэтому его нужно отключить. Найдите, через какое наибольшее время после начала работы нужно отключить прибор. Ответ дайте в минутах." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 17:
                do{
                    a[0] = rand()%15+2;
                    a[1] = rand()%20+3;
                    a[2] = rand()%2000+1000;
                    D=pow(a[1],2)+2*a[0]*a[2];
                    check = 1;
                    if((D>0)&&(D<20000)&&(sqrt(D)-static_cast<int>(sqrt(D))==0))
                    {
                        x1 = (-a[1]-sqrt(D))/(a[0]);
                        x2 = (-a[1]+sqrt(D))/(a[0]);
                        if(x1<0)
                        {
                            if(x2-static_cast<int>(x2)==0)
                                answer = x2;
                            else
                                check = 0;
                        }
                        else
                            check = 0;
                    }
                    else
                        check = 0;
                }while(check!=1);
                cout << "\\item     Для сматывания кабеля на заводе используют лебёдку, которая равноускоренно наматывает кабель на катушку. Угол, на который поворачивется катушка, изменяется со временем по закону $\\varphi=\\omega t+\\frac{\\beta t^2}{2}$, где $t$ -- время в минутах, прошедшее после начала работы лебёдки, $\\omega = " << a[1] << "\\frac{\\text{град.}}{\\text{мин}}$ -- начальная угловая скорость вращения катушки, а $\\beta = " << a[0] << "\\frac{\\text{град.}}{\\text{мин}^2}$ -- угловое ускорение, с которым наматывается кабель. Определите время, прошедшее после начала работы лебёдки, если известно, что за это время угол намотки у достиг $" << a[2] << "^{\\circ}$. Ответ дайте в минутах." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 18:
                do{
                    a[0] = rand()%89+10;
                    a[0] = a[0]/10;
                    a[1] = rand()%40000+1000;
                    a[3] = 10.9;
                    a[4] = rand()%10+1;
                    a[5] = rand()%500+100;
                    check = 1;
                    answer = a[0]*pow(2,(a[1]/(a[3]*a[4]*a[5])));
                    if(answer*100-static_cast<int>(answer*100)!=0)
                        check = 0;
                    if(answer>50)
                        check = 0;
                }while(check!=1);
                cout << "\\item     Водолазный колокол, содержащий $\\nu=" << a[4] << "$ моль воздуха при давлении $p_1=" << a[0] << "$ атмосферы, медленно опускают на дно водоёма. При этом происходит изотермическое сжатие воздуха до конечного давления $p_2$ (в атмосферах). Работа $A$ (в Дж), совершаемая водой при сжатии воздуха, вычисляется по формуле $A=\\alpha\\nu T\\log_2\\left(\\frac{p_2}{p_1}\\right)$, где $\\alpha=10.9\\frac{\\text{Дж}}{\\text{моль}\\cdot\\text{К}}$  — постоянная, $T=" << a[5] << "$ К — температура воздуха. Найдите давление $p_2$ воздуха в колоколе, если при сжатии воздуха была совершена работа $" << a[1] << "$ Дж. Ответ дайте в атмосферах." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 19:
                do{
                    a[0] = rand()%89+10;
                    a[0] = a[0]/10;
                    a[1] = rand()%40000+1000;
                    a[3] = 8.7;
                    a[4] = rand()%10+1;
                    a[5] = rand()%500+100;
                    check = 1;
                    answer = a[0]/pow(2,(a[1]/(a[3]*a[4]*a[5])));
                    if(answer*100-static_cast<int>(answer*100)!=0)
                        check = 0;
                    if(answer>50)
                        check = 0;
                }while(check!=1);
                cout << "\\item     Водолазный колокол, содержащий $\\nu=" << a[4] << "$ моль воздуха объёмом $V_1=" << a[0] << "$ л, медленно опускают на дно водоёма. При этом происходит изотермическое сжатие воздуха до конечного объёма $V_2$ (в л). Работа $A$ (в Дж), совершаемая водой при сжатии воздуха, вычисляется по формуле $A=\\alpha\\nu T\\log_2\\left(\\frac{V_1}{V_2}\\right)$, где $\\alpha=8.7\\frac{\\text{Дж}}{\\text{моль}\\cdot\\text{К}}$ — постоянная, $T=" << a[5] << "$ К — температура воздуха. Найдите, какой объём $V_2$ будет занимать воздух в колоколе, если при сжатии воздуха была совершена работа в $" << a[1] << "$ Дж. Ответ дайте в литрах." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 20:
                do{
                    a[0] = rand()%200+50;
                    a[1] = rand()%10+1;
                    a[2] = rand()%200+50;
                    check = 1;
                    if(a[2]>a[0])
                    {
                        answer = a[0]*a[1]/(a[2]-a[0]);
                        if(answer-static_cast<int>(answer)!=0)
                            check = 0;
                    }
                    else
                        check = 0;
                }while(check!=1);
                cout << "\\item     К источнику с ЭДС $\\varepsilon=" << a[2] << "$ В и внутренним сопротивлением $r=" << a[1] << "$ Ом хотят подключить нагрузку с сопротивлением $R$ (в Ом). Напряжение (в В) на этой нагрузке вычисляется по формуле $U=\\frac{\\varepsilon R}{R+r}$. При каком значении сопротивления нагрузки напряжение на ней будет равно " << a[0] << " В? Ответ дайте в омах." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            }   
            return Answer;
}

string ZadProc(int AllType)
{
    double a[10], answer, x1, x2, change, x[2], D, A, b, c;
            int type;
            if(AllType == 0)
                type = rand()%3+1;
            else
                type = AllType;
            int type_1;
            int check = 0;
            string Answer;
            switch(type)
            {
            case 1:
                do{
                    a[0] = rand()%20+2;
                    a[1] = rand()%50+2;
                    check = 1;
                    answer = 100*a[0]/a[1];
                    if((answer-static_cast<int>(answer)!=0)||(answer>120))
                        check = 0;
                    if(a[0]==a[1])
                        check = 0;
                }while(check!=1);
                cout << "\\item     Призёрами городской олимпиады по математике стали $" << a[0] << "$ учеников, что составило $" << a[1] << "\\%$ от числа участников. Сколько человек участвовало в олимпиаде?" << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 2:
                do{
                    a[0] = rand()%60+5;
                    a[0] = a[0]/100;
                    a[1] = rand()%60+5;
                    a[1] = a[1]/100;
                    a[3] = rand()%60+5;
                    a[3] = a[3]/100;

                    a[2] = rand()%50+4;
                    A=(a[2]*a[3]-a[0]*a[2])/(a[0]+a[1]-2*a[3]);
                    check = 1;
                    if(A>0)
                    {
                        answer = 2*A+a[2];
                        if(answer-static_cast<int>(answer)!=0)
                            check = 0;
                        if(answer>400)
                            check = 0;
                    }
                    else
                        check = 0;
                }while(check!=1);
                cout << "\\item     Имеется два сплава. Первый сплав содержит $" << a[0]*100 << "\\%$ меди, второй - $" << a[1]*100 << "\\%$ меди. Масса первого сплава больше массы второго на $" << a[2] << "$ кг. Из этих двух сплавов получили третий сплав, содержащий $" << a[3]*100 << "\\%$ меди. Найдите массу третьего сплава. Ответ дайте в килограммах." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 3:
                do{
                    a[0] = rand()%60+5;
                    a[0] = a[0]/100;
                    a[1] = rand()%60+5;
                    a[1] = a[1]/100;
                    a[2] = rand()%50 + 2;
                    a[3] = rand()%50 + 2;
                    check = 1;
                    answer = (a[0]*a[2]*a[2]+a[0]*a[2]*a[3]-2*a[1]*a[2]*a[3])/(a[2]*a[2]-a[2]*a[3])*100;
                    if((answer-static_cast<int>(answer)!=0)||(answer<=0))
                        check = 0;
                    if(2*a[1]-(answer/100)<=0)
                        check = 0;
                    if(a[0]==a[1])
                        check = 0;
                }while(check!=1);
                cout << "\\item     Имеется два сосуда. Первый содержит $" << a[2] << "$ кг, а второй -- $" << a[3] << "$ кг растворов кислоты различной концентрации. Если эти растворы смешать, то получится раствор, содержащий $" << a[0]*100 << "\\%$ кислоты. Если же смешать равные массы этих растворов, то получится раствор, содержащий $" << a[1]*100 << "\\%$ кислоты. Сколько процентов кислоты содержится в первом сосуде?" << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;



            }
            return Answer;
}

string ZadRab(int AllType)
{
    double a[10], answer, x1, x2, change, x[2], D, A, b, c;
            int type;
            if(AllType == 0)
                type = rand()%7+1;
            else
                type = AllType;
            int type_1;
            int check = 0;
            string Answer;
            switch (type)
            {
            case 1:
                do{
                    a[0] = rand()%40+6;
                    a[1] = rand()%40+6;
                    answer = a[0]*a[1]/(a[0]+a[1]);
                    check = 1;
                    if(answer - static_cast<int>(answer)!=0)
                        check = 0;
                    if(a[0]==a[1])
                        check = 0;
                }while(check!=1);
                cout << "\\item     Один мастер может выполнить заказ за $" << a[0] << "$ часов, а другой — за $" << a[1] << "$ часа. За сколько часов выполнят этот заказ оба мастера, работая вместе?" << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 2:
                do{
                    a[0] = rand()%200+100;
                    a[1] = rand()%15+1;
                    a[2] = rand()%15+1;
                    check = 1;
                    D = pow(a[1]*a[2],2)+4*a[0]*a[1]*a[2];
                    if(sqrt(D)-static_cast<int>(sqrt(D))==0)
                    {
                        answer = (a[1]*a[2]+sqrt(D))/(2*a[2]);
                        if(answer-static_cast<int>(answer)!=0)
                            check = 0;
                    }
                    else
                        check = 0;
                }while(check!=1);
                cout << "\\item     Заказ на изготовление $" << a[0] << "$ деталей первый рабочий выполняет на $" << a[2] << "$ часов быстрее, чем второй. Сколько деталей за час изготавливает первый рабочий, если известно, что он за час изготавливает на $" << a[1] << "$ деталей больше второго?" << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 3:
                do{
                    a[0] = rand()%200+100;
                    a[1] = rand()%15+1;
                    a[2] = rand()%15+1;
                    check = 1;
                    D = pow(a[1]*a[2],2)+4*a[0]*a[1]*a[2];
                    if(sqrt(D)-static_cast<int>(sqrt(D))==0)
                    {
                        answer = (a[1]*a[2]+sqrt(D))/(2*a[2]);
                        if(answer-static_cast<int>(answer)!=0)
                            check = 0;
                    }
                    else
                        check = 0;
                }while(check!=1);
                cout << "\\item     Первая труба пропускает на $" << a[1] << "$ литров воды в минуту меньше, чем вторая. Сколько литров воды в минуту пропускает вторая труба, если резервуар объёмом $" << a[0] << "$ литров она заполняет на $" << a[2] << "$ минут быстрее, чем первая труба?" << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 4:
                do{
                    a[0] = rand()%200+100;
                    a[1] = rand()%15+1;
                    a[2] = rand()%15+1;
                    check = 1;
                    D = pow(a[1]*a[2],2)+4*a[0]*a[1]*a[2];
                    if(sqrt(D)-static_cast<int>(sqrt(D))==0)
                    {
                        answer = (a[1]*a[2]+sqrt(D))/(2*a[2])-a[1];
                        if(answer-static_cast<int>(answer)!=0)
                            check = 0;
                    }
                    else
                        check = 0;
                }while(check!=1);
                cout << "\\item     Заказ на изготовление $" << a[0] << "$ деталей первый рабочий выполняет на $" << a[2] << "$ часа быстрее, чем второй. Сколько деталей за час изготавливает второй рабочий, если известно, что первый за час изготавливает на $" << a[1] << "$ детали больше?" << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 5:
                do{
                    a[0] = rand()%50+5;
                    a[1] = rand()%50+5;
                    a[2] = rand()%50+5;
                    answer = 1/((1/a[0])+(1/a[1])+(1/(60+a[2])));
                    check = 1;
                    if(answer-static_cast<int>(answer)!=0)
                        check = 0;
                }while(check!=1);
                cout << "\\item     Первый насос наполняет бак за $" << a[0] << "$ минут, второй -- за $" << a[1] << "$ минут, а третий -- за 1 час $" << a[2] << "$ минут. За сколько минут наполнят этот бак три насоса, работая одновременно?" << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 6:
                do{
                    a[0] = rand()%50+5;
                    a[1] = rand()%50+5;
                    a[2] = rand()%50+5;
                    answer = 1/((1/a[0])+(1/a[1]));
                    check = 1;
                    if(answer-static_cast<int>(answer)!=0)
                        check = 0;
                }while(check!=1);
                cout << "\\item     Один мастер может выполнить заказ за $" << a[0] << "$ часов, а другой -- за $" << a[1] << "$ часов. За сколько часов выполнят этот заказ оба мастера, работая вместе?" << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 7:
                do{
                    a[0] = rand()%50+4;
                    a[1] = rand()%50+4;
                    check = 1;
                    answer = a[0]*a[1]/(a[1]-a[0]);
                    if((answer-static_cast<int>(answer)!=0)||(a[0]>a[1]))
                        check = 0;
                }while(check!=1);
                cout << "\\item     Катя и Настя, работая вместе, пропалывают грядку за $" << a[0] << "$ минуты, а одна Настя -- за $" << a[1] << "$ минуты. За сколько минут пропалывает грядку одна Катя?" << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;





            }
            return Answer;
}

string ZadMove(int AllType)
{
                double a[10], answer, x1, x2, change, x[2], D, A, b, c;
            int type;
            if(AllType == 0)
                type = rand()%13+1;
            else
                type = AllType;
            int type_1;
            int check = 0;
            string Answer;
            switch (type)
            {
            case 1:
                do{
                    for(int i=0; i<3; i++)
                        a[i] = rand()%100 + 20;
                    check = 1;
                    answer = (a[0] + 3*a[1] + 2*a[2])/6;
                    if(answer-static_cast<int>(answer)!=0)
                        check = 0;
                }while(check!=1);
                cout << "\\item     Первый час автомобиль ехал со скоростью $" << a[0] << "\\frac{\\text{км}}{\\text{ч}}$, следующие три часа -- со скоростью $" << a[1] << "\\frac{\\text{км}}{\\text{ч}}$, а затем два часа -- со скоростью $" << a[2] << "\\frac{\\text{км}}{\\text{ч}}$. Найдите среднюю скорость автомобиля на протяжении всего пути. Ответ дайте в $\\frac{\\text{км}}{\\text{ч}}$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 2:
                do{
                    a[0] = rand()%100+50;
                    a[1] = rand()%10+1;
                    a[2] = rand()%25 + 2;
                    a[3] = rand()%25 + 2;
                    check = 1;
                    if(a[2]>a[3])
                    {
                        A = a[2]-a[3];
                        b = 2*a[0];
                        c = pow(a[1],2)*(a[2]-a[3]);
                        D = pow(b,2) + 4*pow(a[1],2)*pow(a[2]-a[3],2);
                        if((D<110000)&&(sqrt(D)-static_cast<int>(sqrt(D))==0))
                        {
                            x1 = (b-sqrt(D))/(2*A);
                            x2 = (b+sqrt(D))/(2*A);
                            answer = x2;
                            if(x1-static_cast<int>(x1)!=0)
                                check = 0;
                            if(x2-static_cast<int>(x2)!=0)
                                check = 0;
                        }
                        else
                            check = 0;
                    }
                    else
                        check = 0;
                }while(check!=1);
                cout << "\\item     Теплоход проходит по течению реки до пункта назначения $" << a[0] << "$ км и после стоянки возвращается в пункт отправления. Найдите скорость теплохода в неподвижной воде, если скорость течения равна $" << a[1] << "\\frac{\\text{км}}{\\text{ч}}$, стоянка длится $" << a[3] << "$ часа, а в пункт отправления теплоход возвращается через $" << a[2] << "$ часов. Ответ дайте в $\\frac{\\text{км}}{\\text{ч}}$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 3:
                do{
                    a[0] = rand()%100+50;
                    a[1] = rand()%60 + 20;
                    a[2] = rand()%25 + 2;
                    a[3] = rand()%25 + 2;
                    check = 1;
                    if((a[3]>a[2])&&(pow(a[1],2)*(a[3]-a[2])>2*a[0]*a[1]))
                    {
                        answer = sqrt((pow(a[1],2)*(a[3]-a[2])-2*a[0]*a[1])/(a[3]-a[2]));
                        if(answer-static_cast<int>(answer)!=0)
                            check = 0;
                    }
                    else
                        check = 0;
                }while(check!=1);
                cout << "\\item     Теплоход проходит по течению реки до пункта назначения $" << a[0] << "$ км и после стоянки возвращается в пункт отправления. Найдите скорость течения, если скорость теплохода в неподвижной воде равна $" << a[1] << "\\frac{\\text{км}}{\\text{ч}}$, стоянка длится $" << a[2] << "$ часа, а в пункт отправления теплоход возвращается через $" << a[3] << "$ часов. Ответ дайте в $\\frac{\\text{км}}{\\text{ч}}$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 4:
                do{
                    a[0] = rand()%60 + 20;
                    a[1] = rand()%10+1;
                    a[2] = rand()%25 + 2;
                    a[3] = rand()%25 + 2;
                    check = 1;
                    if((a[3]>a[2])&&(a[0]>a[1]))
                    {
                        answer = (pow(a[0],2)-pow(a[1],2))*(a[3]-a[2])/(2*a[0]);
                        if(answer - static_cast<int>(answer)!=0)
                            check = 0;
                    }
                    else
                        check = 0;
                }while(check!=1);
                cout << "\\item     Теплоход, скорость которого в неподвижной воде равна $" << a[0] << "\\frac{\\text{км}}{\\text{ч}}$, проходит некоторое расстояние по реке и после стоянки возвращается в исходный пункт. Скорость течения равна $" << a[1] << "\\frac{\\text{км}}{\\text{ч}}$, стоянка длится $" << a[2] << "$ часов, а в исходный пункт теплоход возвращается через $" << a[3] << "$ часа после отправления из него. Сколько километров проходит теплоход за весь рейс?" << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 5:
                do{
                    a[0] = rand()%300+60;
                    a[2] = rand()%300+60;
                    a[4] = rand()%300+60;

                    a[1] = rand()%100+50;
                    a[3] = rand()%100+50;
                    a[5] = rand()%100+50;
                    answer = (a[0] + a[2] + a[4])/((a[0]/a[1])+(a[2]/a[3])+(a[4]/a[5]));
                    check = 1;
                    if(answer - static_cast<int>(answer)!=0)
                        check = 0;
                    if(((a[0]/a[1])-static_cast<int>(a[0]/a[1])!=0)||((a[2]/a[3])-static_cast<int>(a[2]/a[3])!=0)||((a[4]/a[5])-static_cast<int>(a[4]/a[5])!=0))
                        check = 0;
                    if((a[0]==a[1])||(a[2]==a[3])||(a[4]==a[5]))
                        check = 0;
                }while(check!=1);
                cout << "\\item     Первые $" << a[0] << "$ км автомобиль ехал со скоростью $" << a[1] << "\\frac{\\text{км}}{\\text{ч}}$, следующие $" << a[2] << "$ км -- со скоростью $" << a[3] << "\\frac{\\text{км}}{\\text{ч}}$, а затем $" << a[4] << "$ км -- со скоростью $" << a[5] << "\\frac{\\text{км}}{\\text{ч}}$. Найдите среднюю скорость автомобиля на протяжении всего пути. Ответ дайте в $\\frac{\\text{км}}{\\text{ч}}$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 6:
                do{
                    a[0] = rand()%200+100;
                    a[1] = rand()%100+40;
                    a[2] = rand()%40+5;
                    D = 4*pow(a[0],2)+4*pow((a[1]*a[2]),2);
                    check = 1;
                    if(sqrt(D)-static_cast<int>(sqrt(D))==0)
                    {
                        answer = (-2*a[0]+sqrt(D))/(2*a[2]);
                        if(answer-static_cast<int>(answer)!=0)
                            check = 0;
                        if(answer>30)
                            check = 0;
                    }
                    else
                        check = 0;
                }while(check!=1);
                cout << "\\item     Моторная лодка прошла против течения реки $" << a[0] << "$ км и вернулась в пункт отправления, затратив на обратный путь на $" << a[2] << "$ часа меньше. Найдите скорость течения, если скорость лодки в неподвижной воде равна $" << a[1] << "\\frac{\\text{км}}{\\text{ч}}$. Ответ дайте в $\\frac{\\text{км}}{\\text{ч}}$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 7:
                do{
                    a[0] = rand()%200+100;
                    a[1] = rand()%20+1;
                    a[2] = rand()%20+1;
                    check = 1;
                    D = pow(a[1]*a[2],2) + 4*a[0]*a[1]*a[2];
                    if(sqrt(D)-static_cast<int>(sqrt(D))==0)
                    {
                        answer = (-1*a[1]*a[2]+sqrt(D))/(2*a[1]);
                        if(answer-static_cast<int>(answer)!=0)
                            check = 0;
                    }
                    else
                        check = 0;
                }while(check!=1);
                cout << "\\item     Пристани А и В расположены на озере, расстояние между ними равно $" << a[0] << "$ км. Баржа отправилась с постоянной скоростью из А в В. На следующий день после прибытия она отправилась тем же путём обратно со скоростью на $" << a[2] << "\\frac{\\text{км}}{\\text{ч}}$ больше прежней, сделав по пути остановку на $" << a[1] << "$ час. В результате она затратила на обратный путь столько же времени, сколько на путь из А в В. Найдите скорость баржи на пути из А в В. Ответ дайте в $\\frac{\\text{км}}{\\text{ч}}$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 8:
                do{
                    a[0] = rand()%200+100;
                    a[1] = rand()%12+2;
                    a[2] = rand()%24;
                    a[3] = rand()%24;
                    a[4] = rand()%24;
                    check = 1;
                    if((a[4]-a[3]-a[2]>0)&&(a[3]!=a[2]))
                    {
                        D = 4*pow(a[0],2)+4*pow(a[1]*(a[4]-a[3]-a[2]),2);
                        if(sqrt(D)-static_cast<int>(sqrt(D))==0)
                        {
                            answer = (2*a[0]+sqrt(D))/(2*(a[4]-a[3]-a[2]));
                            if(answer-static_cast<int>(answer)!=0)
                                check = 0;
                        }
                        else
                            check = 0;
                    }
                    else
                        check = 0;
                }while(check!=1);
                cout << "\\item     Катер в $" << a[3] << "$:00 вышел по течению реки из пункта А в пункт В, расположенный в $" << a[0] << "$ км от А. Пробыв в пункте В $" << a[2] << "$ часа, катер отправился назад и вернулся в пункт А в $" << a[4] << "$:00 того же дня. Определите собственную скорость катера (в $\\frac{\\text{км}}{\\text{ч}}$), если известно, что скорость течения реки $" << a[1] << "\\frac{\\text{км}}{\\text{ч}}$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 9:
                do{
                    a[0] = rand()%200+100;
                    a[1] = rand()%10+2;
                    a[2] = rand()%10+1;
                    check = 1;
                    D = pow(a[1]*a[2],2)+4*a[0]*a[1]*a[2];
                    if(sqrt(D)-static_cast<int>(sqrt(D))==0)
                    {
                        answer = (-1*a[1]*a[2]+sqrt(D))/(2*a[2]);
                        if(answer - static_cast<int>(answer)!=0)
                            check = 0;
                    }
                    else
                        check = 0;
                }while(check!=1);
                cout << "\\item     От пристани А к пристани В, расстояние между которыми равно $" << a[0] << "$ км, отправился с постоянной скоростью первый теплоход, а через $" << a[2] << "$ часа после этого следом за ним со скоростью, на $" << a[1] << "\\frac{\\text{км}}{\\text{ч}}$ большей скорости первого, отправился второй. Найдите скорость первого теплохода, если в пункт В оба теплохода прибыли одновременно. Ответ дайте в $\\frac{\\text{км}}{\\text{ч}}$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 10:
                do{
                    a[0] = rand()%200+50;
                    a[1] = rand()%10+1;
                    a[2] = rand()%10+1;
                    D = pow(a[1]*a[2],2)+4*a[0]*a[1]*a[2];
                    check = 1;
                    if(sqrt(D)-static_cast<int>(sqrt(D))==0)
                    {
                        answer = (-1*a[1]*a[2]+sqrt(D))/(2*a[2]);
                        if(answer-static_cast<int>(answer)!=0)
                            check = 0;
                    }
                    else
                        check = 0;
                }while(check!=1);
                cout << "\\item     Два велосипедиста одновременно отправились в $" << a[0] << "$-километровый пробег. Первый ехал со скоростью, на $" << a[1] << "\\frac{\\text{км}}{\\text{ч}}$ большей, чем скорость второго, и прибыл к финишу на $" << a[2] << "$ часа раньше второго. Найдите скорость велосипедиста, пришедшего к финишу вторым. Ответ дайте в $\\frac{\\text{км}}{\\text{ч}}$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 11:
                do{
                    a[0] = rand()%200+50;
                    a[1] = rand()%10+1;
                    a[2] = rand()%10+1;
                    answer = sqrt((2*a[0]*a[1]+a[2]*a[1]*a[1])/a[2]);
                    check = 1;
                    if(answer-static_cast<int>(answer)!=0)
                        check = 0;
                }while(check!=1);
                cout << "\\item     Моторная лодка прошла против течения реки $" << a[0] << "$ км и вернулась в пункт отправления, затратив на обратный путь на $" << a[2] << "$ часа меньше. Найдите скорость лодки в неподвижной воде, если скорость течения равна $" << a[1] << "\\frac{\\text{км}}{\\text{ч}}$. Ответ дайте в $\\frac{\\text{км}}{\\text{ч}}$" << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 12:
                do{
                    a[0] = rand()%200+50;
                    a[1] = rand()%10+1;
                    a[2] = rand()%50+10;
                    a[3] = rand()%10+1;
                    A=(a[2]/a[1]) - a[3];
                    check = 1;
                    D = 4*pow(a[0],2)+4*pow(A*a[1],2);
                    if((A>0)&&(A-static_cast<int>(A)==0)&&(sqrt(D)-static_cast<int>(sqrt(D))==0))
                    {
                        answer = (2*a[0]+sqrt(D))/(2*A);
                        if(answer - static_cast<int>(answer)!=0)
                            check = 0;
                    }
                    else
                        check = 0;
                }while(check!=1);
                cout << "\\item     Расстояние между пристанями А и В равно $" << a[0] << "$ км. Из А в В по течению реки отправился плот, а через $" << a[3] << "$ часа вслед за ним отправилась яхта, которая, прибыв в пункт В, тотчас повернула обратно и возвратилась в А. К этому времени плот проплыл $" << a[2] << "$ км. Найдите скорость яхты в неподвижной воде, если скорость течения реки равна $" << a[1] << "\\frac{\\text{км}}{\\text{ч}}$. Ответ дайте в $\\frac{\\text{км}}{\\text{ч}}$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 13:
                do{
                    a[0] = rand()%300+100;
                    a[1] = rand()%100+50;
                    a[2] = rand()%100+50;
                    a[3] = rand()%60+10;
                    check = 1;
                    if(a[1]>a[2])
                    {
                        answer = 1000*((a[3]/3600)*(a[1]+a[2])-(a[0]/1000));
                        if(answer - static_cast<int>(answer)!=0)
                            check = 0;
                    }
                    else
                        check = 0;
                }while(check!=1);
                cout << "\\item     По двум параллельным железнодорожным путям навстречу друг другу следуют скорый и пассажирский поезда, скорости которых равны соответственно $" << a[1] << "\\frac{\\text{км}}{\\text{ч}}$ и $" << a[2] << "\\frac{\\text{км}}{\\text{ч}}$. Длина пассажирского поезда равна $" << a[0] << "$ метрам. Найдите длину скорого поезда, если время, за которое он прошёл мимо пассажирского, равно $" << a[3] << "$ секундам. Ответ дайте в метрах." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;


            }   
            return Answer;
}

string Proizvodn(int i, int AllType)
{
    point Dots[9];
            double answer, plus, k, x1, x2, c, x[4], tang;
            int n1, n2, n[4];
            string Answer;
            int type;
            if(AllType == 0)
                type = rand()%8+1;
            else
                type = AllType;
            int type_1, type_2;
            int check = 0;
            switch (type)
            {
            case 1:
                answer = 0;
                type_1 = rand() % 2 + 1;
                do {
                    Dots[0].x = -4.5;
                    Dots[0].y = pow(-1, rand()) * (rand() % 100 + 1);
                    Dots[0].y = Dots[0].y / 50;
                    for (int i = 1; i < 9; i++)
                    {
                        plus = rand() % 2 + 16;
                        Dots[i].x = Dots[i - 1].x + (plus / 22.22);
                        Dots[i].y = pow(-1, rand()) * (rand() % 100 + 1);
                        Dots[i].y = Dots[i].y / 50;
                    }
                    k = (fabs(Dots[0].x) + fabs(Dots[8].x)) / 9;
                    check = 1;
                    for (int i = 0; i < 8; i++)
                    {
                        if (fabs(Dots[i].y - Dots[i + 1].y) / k > 2.5)
                            check = 0;
                    }
                    for (int i = 0; i < 9; i++)
                    {
                        if (fabs(Dots[i].y) / k < 0.3)
                            check = 0;
                    }
                    for (int i = 0; i < 8; i++)
                    {
                        if (fabs(Dots[i].y - Dots[i + 1].y) / k <0.3)
                            check = 0;
                    }
                } while (check != 1);
                if (type_1 == 1)
                {
                    for (int i = 0; i < 8; i++)
                    {
                        if (Dots[i].y > Dots[i + 1].y)
                            answer++;
                    }
                }
                else
                {
                    for (int i = 0; i < 8; i++)
                    {
                        if (Dots[i].y < Dots[i + 1].y)
                            answer++;
                    }
                }
                cout << "%" << i + 1 << endl;
                cout << "\\item" << endl << "\\begin{derivative}" << endl;
                if(type_1==1)
                    cout << "        На рисунке изображен график функции $y=f(x)$. Найдите количество отмеченных точек, в которых производная функции $f(x)$ отрицательна." << endl;
                else
                    cout << "        На рисунке изображен график функции $y=f(x)$. Найдите количество отмеченных точек, в которых производная функции $f(x)$ положительная." << endl;
                cout << "   \\end{derivative}\\hfill" << endl << "   \\raisebox{-70pt}{% Подберите значение смещения" << endl << "   \\begin{tikzpicture}[scale=0.7]" << endl
                    << "            \\draw [thick, -latex] (0,-2) -- (0,2);" << endl
                    << "            \\draw [thick, -latex] (" << Dots[0].x / k << ",0) -- (" << fabs(Dots[8].x) / k << ",0);" << endl
                    << "            \\coordinate[label=below:${x}$] (x) at (" << fabs(Dots[8].x) / k << ",0);" << endl
                    << "            \\coordinate[label=left:${y}$] (y) at (0,2);" << endl
                    << "            \\coordinate[label=below left:$0$] (O) at (0,0);" << endl;
                cout << "           \\coordinate[label=above right:${y=f(x)}$] (N) at (1,1.5);" << endl;

                for (int i = 0; i < 8; i++)
                {
                    cout << "       \\draw[thick] (" << Dots[i].x/k  << "," << Dots[i].y  << ") to [out=0,in=180] (" << Dots[i + 1].x/k  << "," << Dots[i + 1].y  << ");" << endl;
                    cout << "       \\draw[thin, dashed, gray!50] (" << (Dots[i].x + Dots[i + 1].x) / (2*k) << ",-2) -- (" << (Dots[i].x + Dots[i + 1].x) / (2*k) << ",2);" << endl;
                    cout << "       \\coordinate[label=below left:${x_" << i+1 << "}$] (x" << i+1 << ") at (" << (Dots[i].x + Dots[i + 1].x) / (2*k) << ",0);" << endl;
                }
                cout << "        \\end{tikzpicture}" << endl << "     }" <<  endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 2:
                answer = 0;
                type_1 = rand() % 2 + 1;
                do {
                    Dots[0].x = -4.5;
                    Dots[0].y = pow(-1, rand()) * (rand() % 100 + 1);
                    Dots[0].y = Dots[0].y / 50;
                    for (int i = 1; i < 9; i++)
                    {
                        plus = rand() % 2 + 16;
                        Dots[i].x = Dots[i - 1].x + (plus / 22.22);
                        Dots[i].y = pow(-1, rand()) * (rand() % 100 + 1);
                        Dots[i].y = Dots[i].y / 50;
                    }
                    k = (fabs(Dots[0].x) + fabs(Dots[8].x)) / 9;
                    check = 1;
                    for (int i = 0; i < 8; i++)
                    {
                        if (fabs(Dots[i].y - Dots[i + 1].y) / k > 2.5)
                            check = 0;
                    }
                    for (int i = 0; i < 9; i++)
                    {
                        if (fabs(Dots[i].y) / k < 0.3)
                            check = 0;
                    }
                    for (int i = 0; i < 8; i++)
                    {
                        if (fabs(Dots[i].y+Dots[i+1].y) / (2*k) <0.2)
                            check = 0;
                    }
                    for (int i = 0; i < 8; i++)
                    {
                        if (fabs(Dots[i].y - Dots[i + 1].y) / k < 0.3)
                            check = 0;
                    }
                } while (check != 1);
                if (type_1 == 1)
                {
                    for (int i = 0; i < 8; i++)
                    {
                        if ((Dots[i].y+Dots[i+1].y)<0)
                            answer++;
                    }
                }
                else
                {
                    for (int i = 0; i < 8; i++)
                    {
                        if ((Dots[i].y + Dots[i + 1].y) > 0)
                            answer++;
                    }
                }
                cout << "%" << i + 1 << endl;
                cout << "\\item" << endl << "\\begin{derivative}" << endl;
                if (type_1 == 1)
                    cout << "        На рисунке изображен график $y=f'(x)$ -- производной функции $f(x)$. Сколько из этих точек принадлежит промежуткам убывания функции $f(x)$." << endl;
                else
                    cout << "        На рисунке изображен график $y=f'(x)$ -- производной функции $f(x)$. Сколько из этих точек принадлежит промежуткам возрастания функции $f(x)$." << endl;
                cout << "   \\end{derivative}\\hfill" << endl << "   \\raisebox{-70pt}{% Подберите значение смещения" << endl << "   \\begin{tikzpicture}[scale=0.7]" << endl
                    << "            \\draw [thick, -latex] (0,-2) -- (0,2);" << endl
                    << "            \\draw [thick, -latex] (" << Dots[0].x / k << ",0) -- (" << fabs(Dots[8].x) / k << ",0);" << endl
                    << "            \\coordinate[label=below:${x}$] (x) at (" << fabs(Dots[8].x) / k << ",0);" << endl
                    << "            \\coordinate[label=left:${y}$] (y) at (0,2);" << endl
                    << "            \\coordinate[label=below left:$0$] (O) at (0,0);" << endl;
                cout << "           \\coordinate[label=above right:${y=f'(x)}$] (N) at (1,1.5);" << endl;

                for (int i = 0; i < 8; i++)
                {
                    cout << "       \\draw[thick] (" << Dots[i].x / k << "," << Dots[i].y << ") to [out=0,in=180] (" << Dots[i + 1].x / k << "," << Dots[i + 1].y << ");" << endl;
                    cout << "       \\draw[thin, dashed, gray!50] (" << (Dots[i].x + Dots[i + 1].x) / (2 * k) << ",-2) -- (" << (Dots[i].x + Dots[i + 1].x) / (2 * k) << ",2);" << endl;
                    cout << "       \\coordinate[label=below left:${x_" << i + 1 << "}$] (x" << i + 1 << ") at (" << (Dots[i].x + Dots[i + 1].x) / (2 * k) << ",0);" << endl;
                }
                cout << "        \\end{tikzpicture}" << endl << "     }" <<  endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 3:
                answer = 0;
                type_1 = rand() % 3 + 1;
                type_2 = rand() % 2 + 1;
                do {
                    answer = 0;
                    Dots[0].x = -1 * (rand() % 15 + 1);;
                    Dots[0].y = pow(-1, rand()) * (rand() % 4 + 1);
                    for (int i = 1; i < 9; i++)
                    {
                        plus = rand() % 3+1;
                        Dots[i].x = Dots[i - 1].x + plus;
                        if (pow(-1, rand()) > 0)
                            Dots[i].y = 0;
                        else
                        {
                            if (Dots[i - 1].y != 0)
                            {
                                Dots[i].y = (rand() % 4 + 1);
                                Dots[i].y = Dots[i].y * Dots[i - 1].y / (fabs(Dots[i - 1].y));
                            }
                            else
                            {
                                Dots[i].y = (rand() % 4 + 1);
                                Dots[i].y = -1*Dots[i].y * Dots[i - 2].y / (fabs(Dots[i - 2].y));
                            }
                        }
                    }
                    x1 = pow(-1, rand()) * (rand() % 10 + 1);
                    x2 = x1 + rand() % 10 + 5;
                    k = 2;
                    check = 1;
                    for (int i = 0; i < 8; i++)
                    {
                        if (fabs(Dots[i].y - Dots[i + 1].y)/2 > 1.5)
                            check = 0;
                    }
                    for (int i = 0; i < 8; i++)
                    {
                        if (fabs(Dots[i].y - Dots[i + 1].y) / 2 < 0.5)
                            check = 0;
                    }
                    if ((x1 <= Dots[0].x) || (x2 >= Dots[8].x))
                        check = 0;
                    if (type_1 == 1)
                    {
                        for (int i = 0; i < 9; i++)
                        {
                            if ((x1 <= Dots[i].x) && (x2 >= Dots[i].x) && (Dots[i].y == 0))
                                answer++;
                        }
                    }
                    if (type_1 == 2)
                    {
                        for (int i = 0; i < 9; i++)
                        {
                            if ((x1 <= Dots[i].x) && (x2 >= Dots[i].x) && (Dots[i].y == 0) && (Dots[i + 1].y - Dots[i - 1].y > 0))    // минимум
                                answer++;
                        }
                    }
                    if (type_1 == 3)
                    {
                        for (int i = 0; i < 9; i++)
                        {
                            if ((x1 <= Dots[i].x) && (x2 >= Dots[i].x) && (Dots[i].y == 0) && (Dots[i + 1].y - Dots[i - 1].y < 0))    // максимум
                                answer++;
                        }
                    }
                    if ((type_1 != 1) && (type_2 == 1))
                    {
                        if (answer == 0)
                            check = 0;
                    }
                    if ((type_1 != 1) && (type_2 == 2))
                    {
                        if (answer <=1)
                            check = 0;
                    }
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item" << endl << "\\begin{derivative}" << endl;
                if (type_1 == 1)
                    cout << "        На рисунке изображен график $y=f'(x)$ -- производной функции $f(x)$, определенной на интервале $(" << Dots[0].x << "," << Dots[8].x << ")$. Найдите количество точек экстремума функции $f(x)$, принадлежащих отрезку $[" << x1 << "," << x2 << "]$." << endl;
                if (type_1 == 2)
                    cout << "        На рисунке изображен график $y=f'(x)$ -- производной функции $f(x)$, определенной на интервале $(" << Dots[0].x << "," << Dots[8].x << ")$. Найдите количество точек минимума функции $f(x)$, принадлежащих отрезку $[" << x1 << "," << x2 << "]$." << endl;
                if (type_1 == 3)
                    cout << "        На рисунке изображен график $y=f'(x)$ -- производной функции $f(x)$, определенной на интервале $(" << Dots[0].x << "," << Dots[8].x << ")$. Найдите количество точек максимума функции $f(x)$, принадлежащих отрезку $[" << x1 << "," << x2 << "]$." << endl;
                cout << "   \\end{derivative}\\hfill" << endl << "   \\raisebox{-70pt}{% Подберите значение смещения" << endl << "   \\begin{tikzpicture}[scale=0.7]" << endl
                    << "            \\draw [thin, gray!50, step = 0.5] (" << (Dots[0].x / k)-0.5 << ",-2) grid (" << (fabs(Dots[8].x) / k)+0.5 << ", 2);" << endl
                    << "            \\draw [thick, -latex] (0,-2) -- (0,2);" << endl
                    << "            \\draw [thick, -latex] (" << (Dots[0].x / k)-0.5 << ",0) -- (" << (fabs(Dots[8].x) / k)+0.5 << ",0);" << endl
                    << "            \\coordinate[label=below:${x}$] (x) at (" << (fabs(Dots[8].x) / k)+0.5 << ",0);" << endl
                    << "            \\coordinate[label=left:${y}$] (y) at (0,2);" << endl
                    << "            \\coordinate[label=below:${" << Dots[0].x << "}$] (xmin) at (" << Dots[0].x/2 << ",0);" << endl
                    << "            \\coordinate[label=below:${" << Dots[8].x << "}$] (xmax) at (" << Dots[8].x / 2 << ",0);" << endl
                    << "            \\coordinate[label=below left:$0$] (O) at (0,0);" << endl;
                cout << "           \\coordinate[label=above right:${y=f'(x)}$] (N) at (1,1.5);" << endl;
                cout << "           \\coordinate[label=below:$1$] (Onex) at (0.5,0);" << endl
                     << "           \\coordinate[label=left:$1$] (Oney) at (0,0.5);" << endl;
                for (int i = 0; i < 8; i++)
                {
                    if((Dots[i].y!=0)&& (Dots[i+1].y == 0)&& (Dots[i].y<0))
                        cout << "       \\draw[thick] (" << Dots[i].x / k << "," << Dots[i].y / k << ") to [out=0,in=-90] (" << Dots[i + 1].x / k << "," << Dots[i + 1].y / k << ");" << endl;
                    if ((Dots[i].y == 0) && (Dots[i + 1].y != 0)&&(Dots[i+1].y>0))
                        cout << "       \\draw[thick] (" << Dots[i].x / k << "," << Dots[i].y / k << ") to [out=90,in=180] (" << Dots[i + 1].x / k << "," << Dots[i + 1].y / k << ");" << endl;
                    if ((Dots[i].y != 0) && (Dots[i + 1].y == 0)&&(Dots[i].y>0))
                        cout << "       \\draw[thick] (" << Dots[i].x / k << "," << Dots[i].y / k << ") to [out=0,in=90] (" << Dots[i + 1].x / k << "," << Dots[i + 1].y / k << ");" << endl;
                    if ((Dots[i].y == 0) && (Dots[i + 1].y != 0)&&(Dots[i+1].y<0))
                        cout << "       \\draw[thick] (" << Dots[i].x / k << "," << Dots[i].y / k << ") to [out=-90,in=180] (" << Dots[i + 1].x / k << "," << Dots[i + 1].y / k << ");" << endl;
                    if ((Dots[i].y != 0) && (Dots[i + 1].y != 0))
                        cout << "       \\draw[thick] (" << Dots[i].x / k << "," << Dots[i].y/k << ") to [out=0,in=180] (" << Dots[i + 1].x / k << "," << Dots[i + 1].y/k << ");" << endl;
                }
                cout << "        \\end{tikzpicture}" << endl << "     }" <<  endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 4:
                do {
                    answer = 0;
                    Dots[0].x = -1 * (rand() % 15 + 1);;
                    Dots[0].y = pow(-1, rand()) * (rand() % 4 + 1);
                    for (int i = 1; i < 9; i++)
                    {
                        plus = rand() % 3 + 1;
                        Dots[i].x = Dots[i - 1].x + plus;
                        if (pow(-1, rand()) > 0)
                            Dots[i].y = 0;
                        else
                        {
                            if (Dots[i - 1].y != 0)
                            {
                                Dots[i].y = (rand() % 4 + 1);
                                Dots[i].y = Dots[i].y * Dots[i - 1].y / (fabs(Dots[i - 1].y));
                            }
                            else
                            {
                                Dots[i].y = (rand() % 4 + 1);
                                Dots[i].y = -1 * Dots[i].y * Dots[i - 2].y / (fabs(Dots[i - 2].y));
                            }
                        }
                    }
                    x1 = pow(-1, rand()) * (rand() % 10 + 1);
                    x2 = x1 + rand() % 10 + 5;
                    k = 2;
                    check = 1;
                    for (int i = 0; i < 8; i++)
                    {
                        if ((Dots[i].x > x1) && (Dots[i].x < x2) && (Dots[i].y == 0))
                        {
                            answer++;
                            c = Dots[i].x;
                        }
                    }
                    for (int i = 0; i < 8; i++)
                    {
                        if (fabs(Dots[i].y - Dots[i + 1].y) / 2 > 1.5)
                            check = 0;
                    }
                    for (int i = 0; i < 8; i++)
                    {
                        if (fabs(Dots[i].y - Dots[i + 1].y) / 2 < 0.5)
                            check = 0;
                    }
                    if ((x1 <= Dots[0].x) || (x2 >= Dots[8].x))
                        check = 0;
                    if (answer != 1)
                        check = 0;
                } while (check != 1);
                answer = c;
                cout << "%" << i + 1 << endl;
                cout << "\\item" << endl << "\\begin{derivative}" << endl;
                cout << "        На рисунке изображен график $y=f'(x)$ -- производной функции $f(x)$, определенной на интервале $(" << Dots[0].x << "," << Dots[8].x << ")$. Найдите точку экстремума функции $f(x)$, на отрезке $[" << x1 << "," << x2 << "]$." << endl;
                cout << "   \\end{derivative}\\hfill" << endl << "   \\raisebox{-70pt}{% Подберите значение смещения" << endl << "   \\begin{tikzpicture}[scale=0.7]" << endl
                    << "            \\draw [thin, gray!50, step = 0.5] (" << (Dots[0].x / k) - 0.5 << ",-2) grid (" << (fabs(Dots[8].x) / k) + 0.5 << ", 2);" << endl
                    << "            \\draw [thick, -latex] (0,-2) -- (0,2);" << endl
                    << "            \\draw [thick, -latex] (" << (Dots[0].x / k) - 0.5 << ",0) -- (" << (fabs(Dots[8].x) / k) + 0.5 << ",0);" << endl
                    << "            \\coordinate[label=below:${x}$] (x) at (" << (fabs(Dots[8].x) / k) + 0.5 << ",0);" << endl
                    << "            \\coordinate[label=left:${y}$] (y) at (0,2);" << endl
                    << "            \\coordinate[label=below:${" << Dots[0].x << "}$] (xmin) at (" << Dots[0].x / 2 << ",0);" << endl
                    << "            \\coordinate[label=below:${" << Dots[8].x << "}$] (xmax) at (" << Dots[8].x / 2 << ",0);" << endl
                    << "            \\coordinate[label=below left:$0$] (O) at (0,0);" << endl;
                cout << "           \\coordinate[label=above right:${y=f'(x)}$] (N) at (1,1.5);" << endl;
                cout << "           \\coordinate[label=below:$1$] (Onex) at (0.5,0);" << endl
                    << "           \\coordinate[label=left:$1$] (Oney) at (0,0.5);" << endl;
                for (int i = 0; i < 8; i++)
                {
                    if ((Dots[i].y != 0) && (Dots[i + 1].y == 0) && (Dots[i].y < 0))
                        cout << "       \\draw[thick] (" << Dots[i].x / k << "," << Dots[i].y / k << ") to [out=0,in=-90] (" << Dots[i + 1].x / k << "," << Dots[i + 1].y / k << ");" << endl;
                    if ((Dots[i].y == 0) && (Dots[i + 1].y != 0) && (Dots[i + 1].y > 0))
                        cout << "       \\draw[thick] (" << Dots[i].x / k << "," << Dots[i].y / k << ") to [out=90,in=180] (" << Dots[i + 1].x / k << "," << Dots[i + 1].y / k << ");" << endl;
                    if ((Dots[i].y != 0) && (Dots[i + 1].y == 0) && (Dots[i].y > 0))
                        cout << "       \\draw[thick] (" << Dots[i].x / k << "," << Dots[i].y / k << ") to [out=0,in=90] (" << Dots[i + 1].x / k << "," << Dots[i + 1].y / k << ");" << endl;
                    if ((Dots[i].y == 0) && (Dots[i + 1].y != 0) && (Dots[i + 1].y < 0))
                        cout << "       \\draw[thick] (" << Dots[i].x / k << "," << Dots[i].y / k << ") to [out=-90,in=180] (" << Dots[i + 1].x / k << "," << Dots[i + 1].y / k << ");" << endl;
                    if ((Dots[i].y != 0) && (Dots[i + 1].y != 0))
                        cout << "       \\draw[thick] (" << Dots[i].x / k << "," << Dots[i].y / k << ") to [out=0,in=180] (" << Dots[i + 1].x / k << "," << Dots[i + 1].y / k << ");" << endl;
                }
                cout << "        \\end{tikzpicture}" << endl << "     }" <<  endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 5:
                do {
                    answer = 0;
                    Dots[0].x = -1 * (rand() % 7 + 1);;
                    Dots[0].y = pow(-1, rand()) * (rand() % 4 + 1);
                    plus = rand() % 5 + 1;
                    Dots[1].x = Dots[0].x + plus;
                    Dots[1].y = -1 * (rand() % 4 + 1)*Dots[0].y/fabs(Dots[0].y);
                    Dots[2].x = Dots[0].x + 10;
                    Dots[2].y = -1 * (rand() % 4 + 1) * Dots[1].y / fabs(Dots[1].y);
                    answer = Dots[1].x;
                    k = 2;
                    check = 1;
                    for (int i = 0; i < 2; i++)
                    {
                        if (fabs(Dots[i].y - Dots[i + 1].y) / 2 > 3)
                            check = 0;
                    }
                    for (int i = 0; i < 2; i++)
                    {
                        if (fabs(Dots[i].y - Dots[i + 1].y) / 2 < 0.5)
                            check = 0;
                    }
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item" << endl << "\\begin{derivative}" << endl;
                cout << "        На рисунке изображен график функции $y=f(x)$. Найдите корень уравнения $f'(x)=0$." << endl;
                cout << "   \\end{derivative}\\hfill" << endl << "   \\raisebox{-70pt}{% Подберите значение смещения" << endl << "   \\begin{tikzpicture}[scale=0.7]" << endl
                    << "            \\draw [thin, gray!50, step = 0.5] (" << (Dots[0].x / k) - 0.5 << ",-2) grid (" << (fabs(Dots[2].x) / k) + 0.5 << ", 2);" << endl
                    << "            \\draw [thick, -latex] (0,-2) -- (0,2);" << endl
                    << "            \\draw [thick, -latex] (" << (Dots[0].x / k) - 0.5 << ",0) -- (" << (fabs(Dots[2].x) / k) + 0.5 << ",0);" << endl
                    << "            \\coordinate[label=below:${x}$] (x) at (" << (fabs(Dots[2].x) / k) + 0.5 << ",0);" << endl
                    << "            \\coordinate[label=left:${y}$] (y) at (0,2);" << endl
                    << "            \\coordinate[label=below:${" << Dots[0].x << "}$] (xmin) at (" << Dots[0].x / 2 << ",0);" << endl
                    << "            \\coordinate[label=below:${" << Dots[2].x << "}$] (xmax) at (" << Dots[2].x / 2 << ",0);" << endl
                    << "            \\coordinate[label=below left:$0$] (O) at (0,0);" << endl;
                cout << "           \\coordinate[label=above right:${y=f(x)}$] (N) at (1,1.5);" << endl;
                cout << "           \\coordinate[label=below:$1$] (Onex) at (0.5,0);" << endl
                    << "           \\coordinate[label=left:$1$] (Oney) at (0,0.5);" << endl;
                cout << "           \\draw[thick] (" << Dots[0].x/k << "," << Dots[0].y/k << ") -- (" << Dots[1].x/k << "," << Dots[1].y/k << ") -- (" << Dots[2].x/k << "," << Dots[2].y/k << ");" << endl;
                cout << "        \\end{tikzpicture}" << endl << "     }" <<  endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 6:
                type_1 = rand() % 2 + 1;
                do {
                    x1 = 1000;
                    x2 = 1000;
                    n1 = 1000;
                    n2 = 1000;
                    answer = 0;
                    Dots[0].x = -1 * (rand() % 15 + 1);;
                    Dots[0].y = pow(-1, rand()) * (rand() % 4 + 1);
                    for (int i = 1; i < 9; i++)
                    {
                        plus = rand() % 3 + 1;
                        Dots[i].x = Dots[i - 1].x + plus;
                        if (pow(-1, rand()) > 0)
                            Dots[i].y = 0;
                        else
                        {
                            if (Dots[i - 1].y != 0)
                            {
                                Dots[i].y = (rand() % 4 + 1);
                                Dots[i].y = Dots[i].y * Dots[i - 1].y / (fabs(Dots[i - 1].y));
                            }
                            else
                            {
                                Dots[i].y = (rand() % 4 + 1);
                                Dots[i].y = -1 * Dots[i].y * Dots[i - 2].y / (fabs(Dots[i - 2].y));
                            }
                        }
                    }
                    for (int i = 0; i < 9; i++)
                    {
                        if (Dots[i].y == 0)
                        {
                            x1 = Dots[i].x;
                            n1 = i;
                            i = 8;
                        }
                    }
                    for (int i = n1+1; i < 9; i++)
                    {
                        if (Dots[i].y == 0)
                        {
                            x2 = Dots[i].x;
                            n2 = i;
                            i = 8;
                        }
                    }
                    k = 2;
                    check = 1;
                    if (n2 - n1 > 1)
                    {
                        if (Dots[n1 + 1].y > 0)
                        {
                            if (type_1 == 1)
                            {
                                answer = x2;
                            }
                            else
                            {
                                answer = x1;
                            }
                        }
                        if (Dots[n1 + 1].y < 0)
                        {
                            if (type_1 == 1)
                            {
                                answer = x1;
                            }
                            else
                            {
                                answer = x2;
                            }
                        }
                    }
                    else
                        check = 0;
                    for (int i = 0; i < 8; i++)
                    {
                        if (fabs(Dots[i].y - Dots[i + 1].y) / 2 > 1.5)
                            check = 0;
                    }
                    for (int i = 0; i < 8; i++)
                    {
                        if (fabs(Dots[i].y - Dots[i + 1].y) / 2 < 0.5)
                            check = 0;
                    }
                    if (x1==1000)
                        check = 0;
                    if (x2 == 1000)
                        check = 0;
                    if (n1 == 1000)
                        check = 0;
                    if (n2 == 1000)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item" << endl << "\\begin{derivative}" << endl;
                if(type_1==1)
                    cout << "        На рисунке изображен график $y=f'(x)$ -- производной функции $f(x)$, определенной на интервале $(" << Dots[0].x << "," << Dots[8].x << ")$. В какой точке отрезка $[" << x1 << "," << x2 << "]$ функция $f(x)$ принимает наибольшее значение." << endl;
                else
                    cout << "        На рисунке изображен график $y=f'(x)$ -- производной функции $f(x)$, определенной на интервале $(" << Dots[0].x << "," << Dots[8].x << ")$. В какой точке отрезка $[" << x1 << "," << x2 << "]$ функция $f(x)$ принимает наименьшее значение." << endl;
                cout << "   \\end{derivative}\\hfill" << endl << "   \\raisebox{-70pt}{% Подберите значение смещения" << endl << "   \\begin{tikzpicture}[scale=0.7]" << endl
                    << "            \\draw [thin, gray!50, step = 0.5] (" << (Dots[0].x / k) - 0.5 << ",-2) grid (" << (fabs(Dots[8].x) / k) + 0.5 << ", 2);" << endl
                    << "            \\draw [thick, -latex] (0,-2) -- (0,2);" << endl
                    << "            \\draw [thick, -latex] (" << (Dots[0].x / k) - 0.5 << ",0) -- (" << (fabs(Dots[8].x) / k) + 0.5 << ",0);" << endl
                    << "            \\coordinate[label=below:${x}$] (x) at (" << (fabs(Dots[8].x) / k) + 0.5 << ",0);" << endl
                    << "            \\coordinate[label=left:${y}$] (y) at (0,2);" << endl
                    << "            \\coordinate[label=below:${" << Dots[0].x << "}$] (xmin) at (" << Dots[0].x / 2 << ",0);" << endl
                    << "            \\coordinate[label=below:${" << Dots[8].x << "}$] (xmax) at (" << Dots[8].x / 2 << ",0);" << endl
                    << "            \\coordinate[label=below left:$0$] (O) at (0,0);" << endl;
                cout << "           \\coordinate[label=above right:${y=f'(x)}$] (N) at (1,1.5);" << endl;
                cout << "           \\coordinate[label=below:$1$] (Onex) at (0.5,0);" << endl
                    << "           \\coordinate[label=left:$1$] (Oney) at (0,0.5);" << endl;
                for (int i = 0; i < 8; i++)
                {
                    if ((Dots[i].y != 0) && (Dots[i + 1].y == 0) && (Dots[i].y < 0))
                        cout << "       \\draw[thick] (" << Dots[i].x / k << "," << Dots[i].y / k << ") to [out=0,in=-90] (" << Dots[i + 1].x / k << "," << Dots[i + 1].y / k << ");" << endl;
                    if ((Dots[i].y == 0) && (Dots[i + 1].y != 0) && (Dots[i + 1].y > 0))
                        cout << "       \\draw[thick] (" << Dots[i].x / k << "," << Dots[i].y / k << ") to [out=90,in=180] (" << Dots[i + 1].x / k << "," << Dots[i + 1].y / k << ");" << endl;
                    if ((Dots[i].y != 0) && (Dots[i + 1].y == 0) && (Dots[i].y > 0))
                        cout << "       \\draw[thick] (" << Dots[i].x / k << "," << Dots[i].y / k << ") to [out=0,in=90] (" << Dots[i + 1].x / k << "," << Dots[i + 1].y / k << ");" << endl;
                    if ((Dots[i].y == 0) && (Dots[i + 1].y != 0) && (Dots[i + 1].y < 0))
                        cout << "       \\draw[thick] (" << Dots[i].x / k << "," << Dots[i].y / k << ") to [out=-90,in=180] (" << Dots[i + 1].x / k << "," << Dots[i + 1].y / k << ");" << endl;
                    if ((Dots[i].y != 0) && (Dots[i + 1].y != 0))
                        cout << "       \\draw[thick] (" << Dots[i].x / k << "," << Dots[i].y / k << ") to [out=0,in=180] (" << Dots[i + 1].x / k << "," << Dots[i + 1].y / k << ");" << endl;
                }
                cout << "        \\end{tikzpicture}" << endl << "     }" <<  endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 7:
                type_1 = rand() % 2 + 1;
                do {
                    tang = 0;
                    for (int i = 0; i < 4; i++)
                        x[i] = 1000;
                    for (int i = 0; i < 4; i++)
                        n[i] = 1000;
                    n1 = 0;
                    answer = 0;
                    Dots[0].x = -1 * (rand() % 15 + 1);;
                    Dots[0].y = pow(-1, rand()) * (rand() % 4 + 1);
                    for (int i = 1; i < 9; i++)
                    {
                        plus = rand() % 3 + 1;
                        Dots[i].x = Dots[i - 1].x + plus;
                        if (pow(-1, rand()) > 0)
                            Dots[i].y = 0;
                        else
                        {
                            if (Dots[i - 1].y != 0)
                            {
                                Dots[i].y = (rand() % 4 + 1);
                                Dots[i].y = Dots[i].y * Dots[i - 1].y / (fabs(Dots[i - 1].y));
                            }
                            else
                            {
                                Dots[i].y = (rand() % 4 + 1);
                                Dots[i].y = -1 * Dots[i].y * Dots[i - 2].y / (fabs(Dots[i - 2].y));
                            }
                        }
                    }
                    for (int i = 0; i < 8; i++)
                    {
                        if (n[3] == 1000)
                        {
                            if (Dots[i + 1].x - Dots[i].x > 1)
                            {
                                x[n1] = Dots[i].x + 1;
                                n[n1] = i;
                                n1++;
                            }
                        }
                    }

                    k = 2;
                    check = 1;
                    
                    for (int i = 0; i < 8; i++)
                    {
                        if (fabs(Dots[i].y - Dots[i + 1].y) / 2 > 1.5)
                            check = 0;
                    }
                    for (int i = 0; i < 8; i++)
                    {
                        if (fabs(Dots[i].y - Dots[i + 1].y) / 2 < 0.5)
                            check = 0;
                    }
                    for (int i = 0; i < 4; i++)
                    {
                        if (x[i] == 1000)
                            check = 0;
                    }
                    for (int i = 0; i < 4; i++)
                    {
                        if (n[i] == 1000)
                            check = 0;
                    }
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item" << endl << "\\begin{derivative}" << endl;
                if (type_1 == 1)
                    cout << "        На рисунке изображен график функции $y=f(x)$, определенной на интервале $(" << Dots[0].x << "," << Dots[8].x << ")$. На оси абсцисс отмечены точки $" << x[0] << "$, $" << x[1] << "$, $" << x[2] << "$, $" << x[3] << "$. В какой из этих точек значение производной наибольшее?" << endl;
                else
                    cout << "        На рисунке изображен график функции $y=f(x)$, определенной на интервале $(" << Dots[0].x << "," << Dots[8].x << ")$. На оси абсцисс отмечены точки $" << x[0] << "$, $" << x[1] << "$, $" << x[2] << "$, $" << x[3] << "$. В какой из этих точек значение производной наименьшее?" << endl;
                cout << "   \\end{derivative}\\hfill" << endl << "   \\raisebox{-70pt}{% Подберите значение смещения" << endl << "   \\begin{tikzpicture}[scale=0.7]" << endl
                    << "            \\draw [thin, gray!50, step = 0.5] (" << (Dots[0].x / k) - 0.5 << ",-2) grid (" << (fabs(Dots[8].x) / k) + 0.5 << ", 2);" << endl
                    << "            \\draw [thick, -latex] (0,-2) -- (0,2);" << endl
                    << "            \\draw [thick, -latex] (" << (Dots[0].x / k) - 0.5 << ",0) -- (" << (fabs(Dots[8].x) / k) + 0.5 << ",0);" << endl
                    << "            \\coordinate[label=below:${x}$] (x) at (" << (fabs(Dots[8].x) / k) + 0.5 << ",0);" << endl
                    << "            \\coordinate[label=left:${y}$] (y) at (0,2);" << endl
                    << "            \\coordinate[label=below:${" << x[0] << "}$] (x1) at (" << x[0] / 2 << ",0);" << endl
                    << "            \\draw[dashed] (" << x[0]/2 << ",-2) -- (" << x[0]/2 << ",2);" << endl
                    << "            \\draw[dashed] (" << x[1]/2 << ",-2) -- (" << x[1]/2 << ",2);" << endl
                    << "            \\draw[dashed] (" << x[2]/2 << ",-2) -- (" << x[2]/2 << ",2);" << endl
                    << "            \\draw[dashed] (" << x[3]/2 << ",-2) -- (" << x[3]/2 << ",2);" << endl
                    << "            \\coordinate[label=below:${" << x[1] << "}$] (x2) at (" << x[1] / 2 << ",0);" << endl
                    << "            \\coordinate[label=below:${" << x[2] << "}$] (x3) at (" << x[2] / 2 << ",0);" << endl
                    << "            \\coordinate[label=below:${" << x[3] << "}$] (x4) at (" << x[3] / 2 << ",0);" << endl;
                cout << "           \\coordinate[label=above right:${y=f(x)}$] (N) at (1,1.5);" << endl;
                cout << "           \\coordinate[label=below:$1$] (Onex) at (0.5,0);" << endl
                    << "           \\coordinate[label=left:$1$] (Oney) at (0,0.5);" << endl;
                for (int i = 0; i < 8; i++)
                {
                    if ((Dots[i].y != 0) && (Dots[i + 1].y == 0) && (Dots[i].y < 0))
                        cout << "       \\draw[thick] (" << Dots[i].x / k << "," << Dots[i].y / k << ") to [out=0,in=-90] (" << Dots[i + 1].x / k << "," << Dots[i + 1].y / k << ");" << endl;
                    if ((Dots[i].y == 0) && (Dots[i + 1].y != 0) && (Dots[i + 1].y > 0))
                        cout << "       \\draw[thick] (" << Dots[i].x / k << "," << Dots[i].y / k << ") to [out=90,in=180] (" << Dots[i + 1].x / k << "," << Dots[i + 1].y / k << ");" << endl;
                    if ((Dots[i].y != 0) && (Dots[i + 1].y == 0) && (Dots[i].y > 0))
                        cout << "       \\draw[thick] (" << Dots[i].x / k << "," << Dots[i].y / k << ") to [out=0,in=90] (" << Dots[i + 1].x / k << "," << Dots[i + 1].y / k << ");" << endl;
                    if ((Dots[i].y == 0) && (Dots[i + 1].y != 0) && (Dots[i + 1].y < 0))
                        cout << "       \\draw[thick] (" << Dots[i].x / k << "," << Dots[i].y / k << ") to [out=-90,in=180] (" << Dots[i + 1].x / k << "," << Dots[i + 1].y / k << ");" << endl;
                    if ((Dots[i].y != 0) && (Dots[i + 1].y != 0))
                        cout << "       \\draw[thick] (" << Dots[i].x / k << "," << Dots[i].y / k << ") to [out=0,in=180] (" << Dots[i + 1].x / k << "," << Dots[i + 1].y / k << ");" << endl;
                }
                cout << "        \\end{tikzpicture}" << endl << "     }" <<  endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 8:
                do {
                    Dots[0].x = -1 * (rand() % 15 + 1);;
                    Dots[0].y = pow(-1, rand()) * (rand() % 4 + 1);
                    Dots[1].x = Dots[0].x + rand() % 10 + 5;
                    Dots[1].y = pow(-1, rand()) * (rand() % 4 + 1);
                    check = 1;
                    k = 2;
                    answer = (Dots[1].y-Dots[0].y) / (Dots[1].x - Dots[0].x);
                    if (Dots[0].y == Dots[1].y)
                        check = 0;
                    if (100 * answer - static_cast<int>(100 * answer) != 0)
                        check = 0;
                } while (check != 1);
                cout << "%" << i + 1 << endl;
                cout << "\\item" << endl << "\\begin{derivative}" << endl;
                cout << "        На рисунке изображена касательная к графику функции $y=f(x)$ в определенной точке $x_0$. Найдите производную функции в точке $x_0$." << endl;
                cout << "   \\end{derivative}\\hfill" << endl << "   \\raisebox{-70pt}{% Подберите значение смещения" << endl << "   \\begin{tikzpicture}[scale=0.7]" << endl
                    << "            \\draw [thin, gray!50, step = 0.5] (" << (Dots[0].x / k) - 0.5 << ",-2) grid (" << (fabs(Dots[1].x) / k) + 0.5 << ", 2);" << endl
                    << "            \\draw [thick, -latex] (0,-2) -- (0,2);" << endl
                    << "            \\draw [thick, -latex] (" << (Dots[0].x / k) - 0.5 << ",0) -- (" << (fabs(Dots[1].x) / k) + 0.5 << ",0);" << endl
                    << "            \\coordinate[label=below:${x}$] (x) at (" << (fabs(Dots[1].x) / k) + 0.5 << ",0);" << endl
                    << "            \\coordinate[label=left:${y}$] (y) at (0,2);" << endl;
                cout << "           \\coordinate[label=above right:${y=kx+b}$] (N) at (-3,1.5);" << endl;
                cout << "           \\coordinate[label=below:$1$] (Onex) at (0.5,0);" << endl
                    << "           \\coordinate[label=left:$1$] (Oney) at (0,0.5);" << endl;
                cout << "           \\draw[thick] (" << Dots[0].x/k << "," << Dots[0].y/k << ") -- (" << Dots[1].x/k << "," << Dots[1].y/k << ");" << endl;
                cout << "        \\end{tikzpicture}" << endl << "     }" <<  endl << endl;
                //cout << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;
            }
            return Answer;
}

string ProizvStep(int AllType)
{
    int type;
    if(AllType == 0)
        type = rand()%4+1;
    else
        type = AllType;
            double a[4], x[3], D, answer, change;
            string Answer;
            int check = 0;
            int type_1, type_2;
            switch (type)
            {
            case 1:
                type_1 = rand() % 2 + 1;
                do {
                    for (int i = 0; i < 4; i++)
                    {
                        a[i] = pow(-1, rand()) * (rand() % 100 + 1);
                    }
                    D = (4 * a[1] * a[1]) - 12 * a[0] * a[2];
                    if ((D < 1000) && (D > 0) && (a[0] != 0)&&(sqrt(D)-static_cast<int>(sqrt(D))==0))
                    {
                        x[0] = (-2*a[1]-sqrt(D)) / (6*a[0]);
                        x[1] = (-2 * a[1] + sqrt(D)) / (6 * a[0]);

                        if (x[0] > x[1])
                        {
                            change = x[0];
                            x[0] = x[1];
                            x[1] = change;
                        }
                        if (type_1 == 1)
                        {
                            if (a[0] > 0)
                                answer = x[1];
                            else
                                answer = x[0];
                        }
                        if (type_1 == 2)
                        {
                            if (a[0] > 0)
                                answer = x[0];
                            else
                                answer = x[1];
                        }
                        check = 1;
                        if(x[0]-static_cast<int>(x[0])!=0)
                            check = 0;
                        if (x[1] - static_cast<int>(x[1]) != 0)
                            check = 0;
                        if (fabs(x[1]) == fabs(x[0]))
                            check = 0;
                    }
                    else
                        check = 0;
                } while (check != 1);
                if (type_1 == 1)
                {
                    if (a[1] != 0)
                        cout << "\\item     Найдите точку минимума функции: $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "x^3" << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << "x^2" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "x" << SIGNUr(a[3], 2) << NumberCelUr(a[3], 2) << "$." << endl;
                    else
                        cout << "\\item     Найдите точку минимума функции: $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "x^3"  << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "x" << SIGNUr(a[3], 2) << NumberCelUr(a[3], 2) << "$." << endl;
                }
                if (type_1 == 2)
                {
                    if (a[1] != 0)
                        cout << "\\item     Найдите точку максимума функции: $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "x^3" << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << "x^2" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "x" << SIGNUr(a[3], 2) << NumberCelUr(a[3], 2) << "$." << endl;
                    else
                        cout << "\\item     Найдите точку максимума функции: $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "x^3" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "x" << SIGNUr(a[3], 2) << NumberCelUr(a[3], 2) << "$." << endl;
                }
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 2:
                type_1 = rand() % 2 + 1;
                do {
                    for (int i = 0; i < 4; i++)
                    {
                        a[i] = pow(-1, rand()) * (rand() % 100 + 1);
                    }
                    a[1] = 0;
                    D = -1 * a[2] / (3 * a[0]);
                    if ((D > 0) && (sqrt(D) - static_cast<int>(sqrt(D)) == 0)&&(D<1000))
                    {
                        check = 1;
                        x[0] = -1 * sqrt(D);
                        x[1] = sqrt(D);
                        if (type_1 == 1)
                        {
                            if (a[0] > 0)
                                answer = x[1];
                            else
                                answer = x[0];
                        }
                        if (type_1 == 2)
                        {
                            if (a[0] > 0)
                                answer = x[0];
                            else
                                answer = x[1];
                        }
                        check = 1;
                        if (x[0] - static_cast<int>(x[0]) != 0)
                            check = 0;
                        if (x[1] - static_cast<int>(x[1]) != 0)
                            check = 0;
                    }
                    else
                        check = 0;
                } while (check != 1);
                if (type_1 == 1)
                {
                    if (a[1] != 0)
                        cout << "\\item     Найдите точку минимума функции: $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "x^3" << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << "x^2" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "x" << SIGNUr(a[3], 2) << NumberCelUr(a[3], 2) << "$." << endl;
                    else
                        cout << "\\item     Найдите точку минимума функции: $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "x^3" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "x" << SIGNUr(a[3], 2) << NumberCelUr(a[3], 2) << "$." << endl;
                }
                if (type_1 == 2)
                {
                    if (a[1] != 0)
                        cout << "\\item     Найдите точку максимума функции: $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "x^3" << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << "x^2" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "x" << SIGNUr(a[3], 2) << NumberCelUr(a[3], 2) << "$." << endl;
                    else
                        cout << "\\item     Найдите точку максимума функции: $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "x^3" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "x" << SIGNUr(a[3], 2) << NumberCelUr(a[3], 2) << "$." << endl;
                }
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 3:
                do {
                    for(int i=0;i<3;i++)
                        a[i] = pow(-1,rand())*(rand() % 50 + 1);
                    D = -2 * a[1] / (3 * a[0]);
                    if ((D > 0) &&  (D < 100))
                    {
                        x[0] = pow(D,2);
                        x[1] = x[0] - rand() % 4 - 1;
                        x[2] = x[0] + rand() % 4 + 1;
                        answer = (a[0] * x[0] * sqrt(x[0])) + (a[1] * x[0]) + a[2];
                        check = 1;
                        if (answer - static_cast<int>(answer) != 0)
                            check = 0;
                        if ((x[1] < 0) || (x[2] < 0))
                            check = 0;
                        if (answer > 1000)
                            check = 0;
                    }
                    else
                        check = 0;
                } while (check != 1);
                if (a[0] > 0)
                    cout << "\\item     Найдите наименьшее значение функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "x\\sqrt{x}" << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << "x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "$ на отрезке $[" << x[1] << "," << x[2] << "]$." << endl;
                else
                    cout << "\\item     Найдите наибольшее значение функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "x\\sqrt{x}" << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << "x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "$ на отрезке $[" << x[1] << "," << x[2] << "]$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 4:
                do {
                    for (int i = 0; i < 3; i++)
                        a[i] = pow(-1, rand()) * (rand() % 50 + 1);
                    D = -2 * a[1] / (3 * a[0]);
                    if ((D > 0) && (D < 100))
                    {
                        x[0] = pow(D, 2);
                        x[1] = x[0] - rand() % 4 - 1;
                        x[2] = x[0] + rand() % 4 + 1;
                        answer = x[0];
                        check = 1;
                        if (answer - static_cast<int>(answer) != 0)
                            check = 0;
                        if ((x[1] < 0) || (x[2] < 0))
                            check = 0;
                        if (answer > 1000)
                            check = 0;
                    }
                    else
                        check = 0;
                } while (check != 1);
                if (a[0] > 0)
                    cout << "\\item     Найдите точку минимума функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "x^{\\frac{3}{2}}" << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << "x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "$." << endl;
                else
                    cout << "\\item     Найдите точку максимума функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "x^{\\frac{3}{2}}" << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << "x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;
            }
            return Answer;
}

string ProizvLogEks(int AllType)
{
                double a[6], x[2], D, change;
            double answer, type_1;
            string Answer;
            int type;
            if(AllType == 0)
                type = rand()%5+1;
            else
                type = AllType;
            int check = 0;
            switch (type)
            {
            case 1:
                type_1 = rand() % 2 + 1;
                do {
                    for (int i = 0; i < 4; i++)
                        a[i] = pow(-1, rand()) * (rand() % 50 + 1);
                    if (a[0] != 0)
                    {
                        D = pow(a[1], 2) - 8 * a[0] * a[2];
                        if ((D > 0) && (D < 1000))
                        {
                            x[0] = (-1*a[1]-sqrt(D)) / (4*a[0]);
                            x[1] = (-1 * a[1] + sqrt(D)) / (4 * a[0]);

                            if (x[0] > x[1])
                            {
                                change = x[0];
                                x[0] = x[1];
                                x[1] = change;
                            }

                            check = 1;
                            if (sqrt(D) - static_cast<int>(sqrt(D)) != 0)
                                check = 0;
                            if (x[0] - static_cast<int>(x[0]) != 0)
                                check = 0;
                            if (x[1] - static_cast<int>(x[1]) != 0)
                                check = 0;
                            if ((x[0] <= 2) || (x[1] <= 2))
                                check = 0;

                        }
                        else
                            check = 0;
                    }
                    else
                        check = 0;
                 
                    
                } while (check != 1);
                if (type_1 == 1)
                {
                    if (a[0] > 0)
                    {
                        cout << "\\item     Найдите точку минимума функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "x^2" << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << "x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "\\cdot\\ln(x)" << SIGNUr(a[3], 2) << NumberCelUr(a[3], 2) << "$." << endl;
                        answer = x[1];
                    }
                    else
                    {
                        cout << "\\item     Найдите точку минимума функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "x^2" << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << "x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "\\cdot\\ln(x)" << SIGNUr(a[3], 2) << NumberCelUr(a[3], 2) << "$." << endl;
                        answer = x[0];
                    }
                }
                if (type_1 == 2)
                {
                    if (a[0] > 0)
                    {
                        cout << "\\item     Найдите точку максимума функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "x^2" << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << "x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "\\cdot\\ln(x)" << SIGNUr(a[3], 2) << NumberCelUr(a[3], 2) << "$." << endl;
                        answer = x[0];
                    }
                    else
                    {
                        cout << "\\item     Найдите точку максимума функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "x^2" << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << "x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "\\cdot\\ln(x)" << SIGNUr(a[3], 2) << NumberCelUr(a[3], 2) << "$." << endl;
                        answer = x[1];
                    }
                }
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 2:
                do {
                    for (int i = 0; i < 5; i++)
                        a[i] = pow(-1, rand()) * (rand() % 50 + 1);
                    answer = -1 * (a[0]*a[3]+a[1]*a[2]) / (a[0]*a[2]);
                    check = 1;
                    if ((a[2]*answer+a[3]) <= 0)
                        check = 0;
                    if (answer - static_cast<int>(answer) != 0)
                        check = 0;
                } while (check != 1);
                if ((a[0] + ((a[1] * a[2]) / (a[2] * (answer + 0.2) + a[3]))) > 0)
                {
                    cout << "\\item        Найдите точку минимума функции $y=" << SIGNUr(a[0],1) << NumberCelUr(a[0],1) << "x" << SIGNUr(a[1],2) << NumberCelUr(a[1],2) << "\\cdot\\ln(" << SIGNUr(a[2],1) << NumberCelUr(a[2],1) << "x" << SIGNUr(a[3],2) << NumberCelUr(a[3],2) << ")" << SIGNUr(a[4],2) << NumberCelUr(a[4],2) << "$." << endl;
                }
                else
                    cout << "\\item        Найдите точку максимума функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "x" << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << "\\cdot\\ln(" << SIGNUr(a[2], 1) << NumberCelUr(a[2], 1) << "x" << SIGNUr(a[3], 2) << NumberCelUr(a[3], 2) << ")" << SIGNUr(a[4], 2) << NumberCelUr(a[4], 2) << "$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 3:
                a[0] = rand() % 30 + 10;
                a[1] = pow(-1, rand());
                a[2] = pow(-1, rand()) * (rand() % 10 + 1);
                a[3] = -1 * a[1];
                answer = a[3] + a[2];
                if (a[3] > 0)
                    cout << "\\item     Найдите наименьшее значение функции $y=" << SIGNUr(a[3], 1) << NumberCelUr(a[0], 1) << "x" << SIGNUr(a[1], 2) << "\\ln(" << NumberCelUr(a[0], 1) << "x)" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "$ на отрезке $[\\frac{1}{" << 2*a[0] << "};\\frac{5}{" << 2*a[0] << "}]$." << endl;
                else
                    cout << "\\item     Найдите наибольшее значение функции $y=" << SIGNUr(a[3], 1) << NumberCelUr(a[0], 1) << "x" << SIGNUr(a[1], 2) << "\\ln(" << NumberCelUr(a[0], 1) << "x)" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "$ на отрезке $[\\frac{1}{" << 2 * a[0] << "};\\frac{5}{" << 2 * a[0] << "}]$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 4:
                a[0] = pow(-1, rand());
                a[1] = rand() % 15 + 2;
                a[2] = pow(-1, rand()) * (rand() % 20 + 1);
                a[3] = -1 * a[0];
                a[4] = pow(-1, rand()) * (rand() % 10 + 1);
                x[0] = 1 - a[2];
                answer = a[3] * a[1] * x[0] + a[4];
                if (a[3] > 0)
                {
                    if (pow(-1, rand()) > 0)
                        cout << "\\item     Найдите наименьшее значение функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[1], 1) << "\\ln(x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << ")" << SIGNUr(a[3], 2) << NumberCelUr(a[1], 2) << "x" << SIGNUr(a[4], 2) << NumberCelUr(a[4], 2) << "$ на отрезке $["<< x[0]-0.5 << ";" << (x[0]+rand()%5+1) << "]$." << endl;
                    else
                        cout << "\\item     Найдите наименьшее значение функции $y=" << SIGNUr(a[0], 1) << "\\ln(x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << ")^{" << NumberCelUr(a[1],2) <<"}" << SIGNUr(a[3], 2) << NumberCelUr(a[1], 2) << "x" << SIGNUr(a[4], 2) << NumberCelUr(a[4], 2) << "$ на отрезке $[" << x[0] - 0.5 << ";" << (x[0] + rand() % 5 + 1) << "]$." << endl;
                }
                else
                {
                    if (pow(-1, rand()) > 0)
                        cout << "\\item     Найдите наибольшее значение функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[1], 1) << "\\ln(x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << ")" << SIGNUr(a[3], 2) << NumberCelUr(a[1], 2) << "x" << SIGNUr(a[4], 2) << NumberCelUr(a[4], 2) << "$ на отрезке $[" << x[0] - 0.5 << ";" << (x[0] + rand() % 5 + 1) << "]$." << endl;
                    else
                        cout << "\\item     Найдите наибольшее значение функции $y=" << SIGNUr(a[0], 1) << "\\ln(x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << ")^{" << NumberCelUr(a[1], 2) << "}" << SIGNUr(a[3], 2) << NumberCelUr(a[1], 2) << "x" << SIGNUr(a[4], 2) << NumberCelUr(a[4], 2) << "$ на отрезке $[" << x[0] - 0.5 << ";" << (x[0] + rand() % 5 + 1) << "]$." << endl;
                }
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 5:
                do {
                    for (int i = 0; i < 4; i++)
                        a[i] = pow(-1, rand()) * (rand() % 10 + 2);
                    answer = -1 * (a[1] + a[0] * a[3]) / (a[3] * a[1]);
                    check = 1;
                    if (answer - static_cast<int>(answer) != 0)
                        check = 0;
                } while (check != 1);
                if (a[3] * a[1] > 0)
                    cout << "\\item     Найдите точку минимума функции $y=(" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << "x)e^{" << SIGNUr(a[2], 1) << NumberCelUr(a[2], 1) << SIGNUr(a[3], 2) << NumberCelUr(a[3], 2) << "x}$." << endl;
                else
                    cout << "\\item     Найдите точку максимума функции $y=(" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << "x)e^{" << SIGNUr(a[2], 1) << NumberCelUr(a[2], 1) << SIGNUr(a[3], 2) << NumberCelUr(a[3], 2) << "x}$." << endl;
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;
            }
            return Answer;
}

string ProizvTrigonom(int AllType)
{
            double a[3];
            double answer;
            string Answer;
            int type;
            if(AllType == 0)
                type = rand() % 4 + 1;
            else
                type = AllType;
            int check = 0;
            int TYPe;
            switch (type)
            {
            case 1:     // cos
                do {
                    for (int i = 0; i < 3; i++)
                        a[i] = pow(-1, rand()) * (rand() % 30 + 3);
                    answer = a[2]+a[0];
                    check = 1;
                    if (fabs(a[1]) < fabs(a[0]))
                        check = 0;
                } while (check != 1);
                if (pow(-1, rand()) > 0)
                {
                    if (a[1] > 0)
                        cout << "\\item     Найдите наименьшее значение функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "\\cos(x)" << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << "x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "$ на отрезке $[0;\\frac{3\\pi}{2}]$." << endl;
                    else
                        cout << "\\item     Найдите наибольшее значение функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "\\cos(x)" << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << "x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "$ на отрезке $[0;\\frac{3\\pi}{2}]$." << endl;
                }
                else
                {
                    if (a[1] > 0)
                        cout << "\\item     Найдите наибольшее значение функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "\\cos(x)" << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << "x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "$ на отрезке $[-\\frac{3\\pi}{2},0]$." << endl;
                    else
                        cout << "\\item     Найдите наименьшее значение функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "\\cos(x)" << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << "x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "$ на отрезке $[-\\frac{3\\pi}{2},0]$." << endl;
                }
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 2: // sin
                do {
                    for (int i = 0; i < 3; i++)
                        a[i] = pow(-1, rand()) * (rand() % 30 + 3);
                    answer = a[2];
                    check = 1;
                    if (fabs(a[1]) < fabs(a[0]))
                        check = 0;
                } while (check != 1);
                if (pow(-1, rand()) > 0)
                {
                    if (a[1] > 0)
                        cout << "\\item     Найдите наименьшее значение функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "\\sin(x)" << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << "x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "$ на отрезке $[0;\\frac{3\\pi}{2}]$." << endl;
                    else
                        cout << "\\item     Найдите наибольшее значение функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "\\sin(x)" << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << "x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "$ на отрезке $[0;\\frac{3\\pi}{2}]$." << endl;
                }
                else
                {
                    if (a[1] > 0)
                        cout << "\\item     Найдите наибольшее значение функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "\\sin(x)" << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << "x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "$ на отрезке $[-\\frac{3\\pi}{2},0]$." << endl;
                    else
                        cout << "\\item     Найдите наименьшее значение функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "\\sin(x)" << SIGNUr(a[1], 2) << NumberCelUr(a[1], 2) << "x" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "$ на отрезке $[-\\frac{3\\pi}{2},0]$." << endl;
                }
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 3:  //cos vs sin
                TYPe = pow(-1, rand());
                do {
                    for (int i = 0; i < 3; i++)
                        a[i] = pow(-1, rand()) * (rand() % 30 + 3);
                    if(TYPe>0)
                        answer = (-0.5*a[0])-(a[1]*2/3)+a[2];
                    else
                        answer = (-0.5*a[0])-(a[1]*5/6)+a[2];
                    check = 1;
                    if (answer - static_cast<int>(answer) != 0)
                        check = 0;
                    if (fabs(a[1])/3.5 < fabs(a[0]))
                        check = 0;
                } while (check != 1);
                if (TYPe > 0)
                {
                    if (a[1] > 0)
                        cout << "\\item     Найдите наименьшее значение функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "\\cos(x)" << SIGNUr(a[1], 2) << "\\frac{" << NumberCelUr(a[1], 2) << "x}{\\pi}" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "$ на отрезке $[-\\frac{2\\pi}{3},0]$." << endl;
                    else
                        cout << "\\item     Найдите наибольшее значение функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "\\cos(x)" << SIGNUr(a[1], 2) << "\\frac{" << NumberCelUr(a[1], 2) << "x}{\\pi}" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "$ на отрезке $[-\\frac{2\\pi}{3},0]$." << endl;
                }
                else
                {
                    if (a[1] > 0)
                        cout << "\\item     Найдите наименьшее значение функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "\\sin(x)" << SIGNUr(a[1], 2) << "\\frac{" << NumberCelUr(a[1], 2) << "x}{\\pi}" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "$ на отрезке $[-\\frac{5\\pi}{6},0]$." << endl;
                    else
                        cout << "\\item     Найдите наибольшее значение функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "\\sin(x)" << SIGNUr(a[1], 2) << "\\frac{" << NumberCelUr(a[1], 2) << "x}{\\pi}" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "$ на отрезке $[-\\frac{5\\pi}{6},0]$." << endl;
                }
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;

            case 4:
                TYPe = pow(-1, rand());
                do {
                    for (int i = 0; i < 3; i++)
                        a[i] = pow(-1, rand()) * (rand() % 30 + 3);
                    if(TYPe >   0)
                        answer = (-0.5 * a[0]) + (a[1] * 2 / 3) + a[2];
                    else
                        answer = (0.5*a[0])+(a[1]*5/6)+a[2];
                    check = 1;
                    if (answer - static_cast<int>(answer) != 0)
                        check = 0;
                    if (fabs(a[1]) / 3.5 < fabs(a[0]))
                        check = 0;
                } while (check != 1);
                if (TYPe > 0)
                {
                    if (a[1] > 0)
                        cout << "\\item     Найдите наибольшее значение функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "\\cos(x)" << SIGNUr(a[1], 2) << "\\frac{" << NumberCelUr(a[1], 2) << "x}{\\pi}" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "$ на отрезке $[0,\\frac{2\\pi}{3}]$." << endl;
                    else
                        cout << "\\item     Найдите наименьшее значение функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "\\cos(x)" << SIGNUr(a[1], 2) << "\\frac{" << NumberCelUr(a[1], 2) << "x}{\\pi}" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "$ на отрезке $[0,\\frac{2\\pi}{3}]$." << endl;
                }
                else
                {
                    if (a[1] > 0)
                        cout << "\\item     Найдите наибольшее значение функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "\\sin(x)" << SIGNUr(a[1], 2) << "\\frac{" << NumberCelUr(a[1], 2) << "x}{\\pi}" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "$ на отрезке $[0,\\frac{5\\pi}{6}]$." << endl;
                    else
                        cout << "\\item     Найдите наименьшее значение функции $y=" << SIGNUr(a[0], 1) << NumberCelUr(a[0], 1) << "\\sin(x)" << SIGNUr(a[1], 2) << "\\frac{" << NumberCelUr(a[1], 2) << "x}{\\pi}" << SIGNUr(a[2], 2) << NumberCelUr(a[2], 2) << "$ на отрезке $[0,\\frac{5\\pi}{6}]$." << endl;
                }
                //cout << "\\\\" << answer << endl;
                Answer = "  \\item " + FormatDouble(answer) + " \n";
                break;
            }
            return Answer;
}

string Uravn1(int Type)
{
    string Answer;
    int type;
    if(Type == 1)
    {
        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\frac{9^{\\sin(2x)}-3^{2\\sqrt{2}\\sin(x)}}{\\sqrt{11\\sin(x)}}=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{7\\pi}{2};5\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = "  \\item a) $\\frac{\\pi}{4}+2\\pi n$, б) $\\frac{17\\pi}{4}$ \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\frac{\\log^2_2(\\sin(x))+\\log_2(\\sin(x))}{2\\cos(x)+\\sqrt{3}}=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[0;\\frac{3\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{2}+2\\pi n; \\frac{\\pi}{6}+2\\pi n$, б) $\\frac{\\pi}{6}, \\frac{\\pi}{2}$ \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\frac{4^{\\sin(2x)}-2^{2\\sqrt{3}\\sin(x)}}{\\sqrt{7\\sin(x)}}=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-\\frac{13\\pi}{2};-5\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{6}+2\\pi n$, б) $-\\frac{35\\pi}{6}$ \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\frac{\\log^2_2(\\sin(x))+\\log_2(\\sin(x))}{2\\cos(x)-\\sqrt{3}}=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{\\pi}{2};2\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{2}+2\\pi n, \\frac{5\\pi}{6}+2\\pi n$, б) $\\frac{\\pi}{2},\\frac{5\\pi}{6}$ \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$16^{\\sin(x)}+16^{\\sin(x+\\pi)}=\\frac{17}{4}$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{3\\pi}{2};3\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\pm\\frac{\\pi}{6}+\\pi n$, б) $\\frac{\\pi}{6},\\frac{5\\pi}{6},\\frac{11\\pi}{6}$ \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\log_9\\left(3^{2x}+5\\sqrt{2}\\sin(x)-6\\cos^2(x)-2\\right)=x$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-2\\pi;-\\frac{\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{4}+2\\pi n, \\frac{3\\pi}{4}+2\\pi n$, б) $-\\frac{5\\pi}{4},-\\frac{7\\pi}{4}$ \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\left(\\frac{1}{49}\\right)^{\\sin(x+\\pi)}=7^{2\\sqrt{3}\\sin\\left(\\frac{\\pi}{2}-x\\right)}$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[3\\pi;\\frac{9\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{3}+\\pi n$, б) $\\frac{10\\pi}{3},\\frac{13\\pi}{3}$ \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\sqrt{3}\\tg^2(x)-4\\tg(x)+\\sqrt{3}=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\pi;\\frac{5\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{6}+\\pi n, \\frac{\\pi}{3}+\\pi n$, б) $\\frac{7\\pi}{6},\\frac{4\\pi}{3},\\frac{13\\pi}{6},\\frac{7\\pi}{3}$ \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$16^{\\cos(x)}+16^{\\cos(\\pi-x)}=\\frac{17}{4}$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\pi;\\frac{5\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\pm\\frac{\\pi}{3}+\\pi n$, б) $\\frac{4\\pi}{3},\\frac{5\\pi}{3},\\frac{7\\pi}{3}$ \n";
    }
    if(Type == 2)
    {
        type = rand()%9+1;
        switch(type)
        {
            case 1:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\frac{9^{\\sin(2x)}-3^{2\\sqrt{2}\\sin(x)}}{\\sqrt{11\\sin(x)}}=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{7\\pi}{2};5\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = "  \\item a) $\\frac{\\pi}{4}+2\\pi n$, б) $\\frac{17\\pi}{4}$ \n";
                break;

            case 2:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\frac{\\log^2_2(\\sin(x))+\\log_2(\\sin(x))}{2\\cos(x)+\\sqrt{3}}=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[0;\\frac{3\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{2}+2\\pi n; \\frac{\\pi}{6}+2\\pi n$, б) $\\frac{\\pi}{6}, \\frac{\\pi}{2}$ \n";
                break;

            case 3:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\frac{4^{\\sin(2x)}-2^{2\\sqrt{3}\\sin(x)}}{\\sqrt{7\\sin(x)}}=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-\\frac{13\\pi}{2};-5\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
         Answer = Answer + "  \\item а) $\\frac{\\pi}{6}+2\\pi n$, б) $-\\frac{35\\pi}{6}$ \n";
                break;

            case 4:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\frac{\\log^2_2(\\sin(x))+\\log_2(\\sin(x))}{2\\cos(x)-\\sqrt{3}}=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{\\pi}{2};2\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
         Answer = Answer + "  \\item а) $\\frac{\\pi}{2}+2\\pi n, \\frac{5\\pi}{6}+2\\pi n$, б) $\\frac{\\pi}{2},\\frac{5\\pi}{6}$ \n";
                break;

            case 5:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$16^{\\sin(x)}+16^{\\sin(x+\\pi)}=\\frac{17}{4}$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{3\\pi}{2};3\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\pm\\frac{\\pi}{6}+\\pi n$, б) $\\frac{\\pi}{6},\\frac{5\\pi}{6},\\frac{11\\pi}{6}$ \n";
                break;

            case 6:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\log_9\\left(3^{2x}+5\\sqrt{2}\\sin(x)-6\\cos^2(x)-2\\right)=x$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-2\\pi;-\\frac{\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{4}+2\\pi n, \\frac{3\\pi}{4}+2\\pi n$, б) $-\\frac{5\\pi}{4},-\\frac{7\\pi}{4}$ \n";
                break;

            case 7:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\left(\\frac{1}{49}\\right)^{\\sin(x+\\pi)}=7^{2\\sqrt{3}\\sin\\left(\\frac{\\pi}{2}-x\\right)}$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[3\\pi;\\frac{9\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{3}+\\pi n$, б) $\\frac{10\\pi}{3},\\frac{13\\pi}{3}$ \n";
                break;

            case 8:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\sqrt{3}\\tg^2(x)-4\\tg(x)+\\sqrt{3}=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\pi;\\frac{5\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{6}+\\pi n, \\frac{\\pi}{3}+\\pi n$, б) $\\frac{7\\pi}{6},\\frac{4\\pi}{3},\\frac{13\\pi}{6},\\frac{7\\pi}{3}$ \n";
                break;

            case 9:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$16^{\\cos(x)}+16^{\\cos(\\pi-x)}=\\frac{17}{4}$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\pi;\\frac{5\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\pm\\frac{\\pi}{3}+\\pi n$, б) $\\frac{4\\pi}{3},\\frac{5\\pi}{3},\\frac{7\\pi}{3}$ \n";
                break;
        }
    }
    return Answer;
}

string Uravn2(int Type)
{
    string Answer;
    int type;
    if(Type == 1)
    {
        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$8\\cdot16^{\\sin^2(x)}-2\\cdot 4^{\\cos(2x)}=63$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{7\\pi}{2};5\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = "  \\item a) $\\frac{\\pi}{3}+\\pi n,-\\frac{\\pi}{3}+\\pi n$; б) $\\frac{11\\pi}{3}$, $\\frac{13\\pi}{3}$, $\\frac{14\\pi}{3}$ \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$8^x-3\\cdot 2^{x+2}+2^{5-x}=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\log_45;\\sqrt{3}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item a) $1,1.5$; б) 1.5 \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$8^x-9\\cdot 2^{x+1}+2^{5-x}=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\log_52;\\log_520\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item a) 0.5, 2; б) 0.5 \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$16^{\\sin(x)}-6\\cdot 4^{\\sin(x)}+8=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-5\\pi;-\\frac{7\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{6}+2\\pi k, \\frac{5\\pi}{6}+2\\pi k, \\frac{\\pi}{2}+2\\pi k$; б) $-\\frac{7\\pi}{2},-\\frac{23\\pi}{6}$ \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$27^x-4\\cdot 3^{x+2}+3^{5-x}=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\log_74;\\log_716\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) 1, 1.5; б) 1 \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$4\\cdot 16^{\\sin^2(x)}-6\\cdot 4^{\\cos(2x)}=29$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{3\\pi}{2};3\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{3}+\\pi n, -\\frac{\\pi}{3}+\\pi n$; б) $\\frac{5\\pi}{3},\\frac{7\\pi}{3},\\frac{8\\pi}{3}$\n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$27^x-28\\cdot 3^{x+1}+3^{5-x}=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\sqrt{3};\\log_25\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) 0.5, 2; б) 2\n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$9\\cdot 81^{\\cos(x)}-28\\cdot 9^{\\cos(x)}+3=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{5\\pi}{2};4\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{3}+\\frac{2\\pi k}{3}$; б) $\\frac{11\\pi}{3},3\\pi$ \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$27\\cdot 81^{\\sin(x)}-12\\cdot 9^{\\sin(x)}+1=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{3\\pi}{2};3\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $-\\frac{\\pi}{2}+2\\pi k, -\\frac{5\\pi}{6}+2\\pi k, -\\frac{\\pi}{6}+2\\pi k$; б)$\\frac{3\\pi}{2}, \\frac{11\\pi}{6}$  \n";
    }
    if(Type == 2)
    {
        type = rand()%9 + 1;
        switch(type)
        {
            case 1:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$8\\cdot16^{\\sin^2(x)}-2\\cdot 4^{\\cos(2x)}=63$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{7\\pi}{2};5\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = "  \\item a) $\\frac{\\pi}{3}+\\pi n,-\\frac{\\pi}{3}+\\pi n$; б) $\\frac{11\\pi}{3}$, $\\frac{13\\pi}{3}$, $\\frac{14\\pi}{3}$ \n";
            break;

            case 2:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$8^x-3\\cdot 2^{x+2}+2^{5-x}=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\log_45;\\sqrt{3}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item a) $1,1.5$; б) 1.5 \n";
            break;

            case 3:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$8^x-9\\cdot 2^{x+1}+2^{5-x}=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\log_52;\\log_520\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item a) 0.5, 2; б) 0.5 \n";
            break;

            case 4:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$16^{\\sin(x)}-6\\cdot 4^{\\sin(x)}+8=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-5\\pi;-\\frac{7\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{6}+2\\pi k, \\frac{5\\pi}{6}+2\\pi k, \\frac{\\pi}{2}+2\\pi k$; б) $-\\frac{7\\pi}{2},-\\frac{23\\pi}{6}$ \n";
            break;

            case 5:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$27^x-4\\cdot 3^{x+2}+3^{5-x}=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\log_74;\\log_716\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) 1, 1.5; б) 1 \n";
            break;

            case 6:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$4\\cdot 16^{\\sin^2(x)}-6\\cdot 4^{\\cos(2x)}=29$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{3\\pi}{2};3\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{3}+\\pi n, -\\frac{\\pi}{3}+\\pi n$; б) $\\frac{5\\pi}{3},\\frac{7\\pi}{3},\\frac{8\\pi}{3}$\n";
            break;

            case 7:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$27^x-28\\cdot 3^{x+1}+3^{5-x}=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\sqrt{3};\\log_25\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) 0.5, 2; б) 2\n";
            break;

            case 8:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$9\\cdot 81^{\\cos(x)}-28\\cdot 9^{\\cos(x)}+3=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{5\\pi}{2};4\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{3}+\\frac{2\\pi k}{3}$; б) $\\frac{11\\pi}{3},3\\pi$ \n";
            break;

            case 9:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$27\\cdot 81^{\\sin(x)}-12\\cdot 9^{\\sin(x)}+1=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{3\\pi}{2};3\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $-\\frac{\\pi}{2}+2\\pi k, -\\frac{5\\pi}{6}+2\\pi k, -\\frac{\\pi}{6}+2\\pi k$; б)$\\frac{3\\pi}{2}, \\frac{11\\pi}{6}$  \n";
            break;
        }
    }
    return Answer;
}

string Uravn3(int Type)
{
    string Answer;
    int type;
    if(Type == 1)
    {
        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\sin(2x)+\\sqrt{2}\\cos(x+\\pi)=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[3\\pi;\\frac{9\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = "  \\item а) $\\frac{\\pi}{2}+\\pi k, \\frac{\\pi}{4}+2\\pi k, \\frac{3\\pi}{4} + 2\\pi k$; б) $\\frac{9\\pi}{2},\\frac{17\\pi}{4}, \\frac{7\\pi}{2}$   \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\cos(2x)+\\cos(-x)=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-\\frac{7\\pi}{2};-2\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{3}+\\frac{2\\pi k}{3}$;  б) $-3\\pi, -\\frac{7\\pi}{3}$  \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\cos(2x)-3\\sin(-x)-2=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[3\\pi;\\frac{9\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{6}+2\\pi k,\\frac{5\\pi}{6}+2\\pi k,\\frac{\\pi}{2}+2\\pi k$; б) $\\frac{9\\pi}{2},\\frac{25\\pi}{6}$ \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\cos(2x)-\\sqrt{2}\\sin(x+\\pi)-1=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-\\frac{7\\pi}{2};-2\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\pi k, \\frac{\\pi}{4}+2\\pi k, \\frac{3\\pi}{4}+2\\pi k$; б) $-\\frac{13\\pi}{4},-2\\pi,-3\\pi$ \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\sin(2x)+2\\sin(-x)+\\cos(-x)-1=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[2\\pi;\\frac{7\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $2\\pi k, -\\frac{\\pi}{6}+2\\pi k, -\\frac{11\\pi}{6}+2\\pi k$; б) $2\\pi, \\frac{19\\pi}{6}$  \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\cos(2x)+\\sqrt{2}\\cos(x+\\pi)+1=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-4\\pi;-\\frac{5\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{2}+\\pi k, \\frac{\\pi}{4}+2\\pi k, -\\frac{\\pi}{4}+2\\pi k$; б) $-\\frac{15\\pi}{4},-\\frac{7\\pi}{2},-\\frac{5\\pi}{2}$  \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\sin(2x)-\\sin(-x)+2\\cos(-x)+1=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{3\\pi}{2};3\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $-\\frac{\\pi}{2}+2\\pi k, \\frac{2\\pi}{3}+2\\pi k, -\\frac{2\\pi}{3}+2\\pi k$; б) $\\frac{3\\pi}{2},\\frac{8\\pi}{3}$  \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\sin(2x)+\\sqrt{2}\\sin(x+\\pi)=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-4\\pi;-\\frac{5\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\pi k, \\frac{\\pi}{4}+2\\pi k, -\\frac{\\pi}{4}+2\\pi k$; б) $-4\\pi,-\\frac{15\\pi}{4},-3\\pi$ \n";
    }
    if(Type == 2)
    {
        type = rand()%8 + 1;
        switch(type)
        {
            case 1:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\sin(2x)+\\sqrt{2}\\cos(x+\\pi)=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[3\\pi;\\frac{9\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = "  \\item а) $\\frac{\\pi}{2}+\\pi k, \\frac{\\pi}{4}+2\\pi k, \\frac{3\\pi}{4} + 2\\pi k$; б) $\\frac{9\\pi}{2},\\frac{17\\pi}{4}, \\frac{7\\pi}{2}$   \n";
            break;

            case 2:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\cos(2x)+\\cos(-x)=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-\\frac{7\\pi}{2};-2\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{3}+\\frac{2\\pi k}{3}$;  б) $-3\\pi, -\\frac{7\\pi}{3}$  \n";
            break;

            case 3:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\cos(2x)-3\\sin(-x)-2=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[3\\pi;\\frac{9\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
       Answer = Answer + "  \\item а) $\\frac{\\pi}{6}+2\\pi k,\\frac{5\\pi}{6}+2\\pi k,\\frac{\\pi}{2}+2\\pi k$; б) $\\frac{9\\pi}{2},\\frac{25\\pi}{6}$ \n";
            break;

            case 4:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\cos(2x)-\\sqrt{2}\\sin(x+\\pi)-1=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-\\frac{7\\pi}{2};-2\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\pi k, \\frac{\\pi}{4}+2\\pi k, \\frac{3\\pi}{4}+2\\pi k$; б) $-\\frac{13\\pi}{4},-2\\pi,-3\\pi$ \n";
            break;

            case 5:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\sin(2x)+2\\sin(-x)+\\cos(-x)-1=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[2\\pi;\\frac{7\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $2\\pi k, -\\frac{\\pi}{6}+2\\pi k, -\\frac{11\\pi}{6}+2\\pi k$; б) $2\\pi, \\frac{19\\pi}{6}$  \n";
            break;

            case 6:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\cos(2x)+\\sqrt{2}\\cos(x+\\pi)+1=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-4\\pi;-\\frac{5\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{2}+\\pi k, \\frac{\\pi}{4}+2\\pi k, -\\frac{\\pi}{4}+2\\pi k$; б) $-\\frac{15\\pi}{4},-\\frac{7\\pi}{2},-\\frac{5\\pi}{2}$  \n";
            break;

            case 7:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\sin(2x)-\\sin(-x)+2\\cos(-x)+1=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{3\\pi}{2};3\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $-\\frac{\\pi}{2}+2\\pi k, \\frac{2\\pi}{3}+2\\pi k, -\\frac{2\\pi}{3}+2\\pi k$; б) $\\frac{3\\pi}{2},\\frac{8\\pi}{3}$  \n";
            break;

            case 8:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\sin(2x)+\\sqrt{2}\\sin(x+\\pi)=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-4\\pi;-\\frac{5\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\pi k, \\frac{\\pi}{4}+2\\pi k, -\\frac{\\pi}{4}+2\\pi k$; б) $-4\\pi,-\\frac{15\\pi}{4},-3\\pi$ \n";
            break;
        }
    }
    return Answer;
}

string Uravn4(int Type)
{
    string Answer;
    int type;
    if(Type == 1)
    {
        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\sin\\left(x+\\frac{\\pi}{6}\\right)-2\\sqrt{3}\\cos^2(x)=\\cos(x)-2\\sqrt{3}$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-\\frac{5\\pi}{2};-\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = "  \\item а) $\\pi k, -\\frac{\\pi}{6}+2\\pi k, -\\frac{5\\pi}{6}+2\\pi k$; б)  $-\\frac{13\\pi}{6}, -2\\pi,-\\pi$\n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\cos(2x)+\\sqrt{3}\\sin\\left(\\frac{\\pi}{2}+x\\right)+1=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-3\\pi;-\\frac{3\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{2}+\\pi k, \\pm \\frac{5\\pi}{6}+2\\pi k$;  б) $-\\frac{17\\pi}{6},-\\frac{3\\pi}{2}$ \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\sqrt{2}\\sin\\left(x+\\frac{\\pi}{4}\\right)+2\\sin^2(x)=\\sin(x)+2$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[2\\pi;\\frac{7\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{2}+\\pi k,\\pm\\frac{\\pi}{3}+2\\pi k$;  б) $\\frac{7\\pi}{3},\\frac{5\\pi}{2},\\frac{7\\pi}{2}$ \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\sin\\left(x+\\frac{\\pi}{3}\\right)+\\cos(2x)=\\sqrt{3}\\cos(x)+1$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-3\\pi;-\\frac{3\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\pi k,\\frac{\\pi}{6}+2\\pi k, \\frac{5\\pi}{6}+2\\pi k$;  б) $-3\\pi, -2\\pi,-\\frac{11\\pi}{6}$ \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\sin\\left(2x+\\frac{\\pi}{6}\\right)-\\cos(x)=\\sqrt{3}\\sin(2x)-1$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{5\\pi}{2};4\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{2}+\\pi k, \\pm \\frac{\\pi}{3}+2\\pi k$;  б) $\\frac{5\\pi}{2}, \\frac{7\\pi}{2}, \\frac{11\\pi}{3}$\n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\sin(x)+2\\sin\\left(2x+\\frac{\\pi}{6}\\right)=\\sqrt{3}\\sin(2x)+1$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-\\frac{7\\pi}{2};-2\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\pi k, \\frac{\\pi}{6}+2\\pi k,\\frac{5\\pi}{6}+2\\pi k$; б) $-\\frac{23\\pi}{6},-3\\pi,-2\\pi$\n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\sin\\left(x+\\frac{\\pi}{3}\\right)-\\sqrt{3}\\cos(2x)=\\sin(x)+\\sqrt{3}$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-2\\pi;-\\frac{\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{2}+\\pi k,\\pm\\frac{\\pi}{3}+2\\pi k$;  б) $-\\frac{5\\pi}{3},-\\frac{3\\pi}{2}, -\\frac{\\pi}{2}$ \n";
    }
    if(Type == 2)
    {
        type = rand()%7 + 1;
        switch(type)
        {
            case 1:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\sin\\left(x+\\frac{\\pi}{6}\\right)-2\\sqrt{3}\\cos^2(x)=\\cos(x)-2\\sqrt{3}$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-\\frac{5\\pi}{2};-\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = "  \\item а) $\\pi k, -\\frac{\\pi}{6}+2\\pi k, -\\frac{5\\pi}{6}+2\\pi k$; б)  $-\\frac{13\\pi}{6}, -2\\pi,-\\pi$\n";
            break;

            case 2:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\cos(2x)+\\sqrt{3}\\sin\\left(\\frac{\\pi}{2}+x\\right)+1=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-3\\pi;-\\frac{3\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{2}+\\pi k, \\pm \\frac{5\\pi}{6}+2\\pi k$;  б) $-\\frac{17\\pi}{6},-\\frac{3\\pi}{2}$ \n";
            break;

            case 3:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\sqrt{2}\\sin\\left(x+\\frac{\\pi}{4}\\right)+2\\sin^2(x)=\\sin(x)+2$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[2\\pi;\\frac{7\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{2}+\\pi k,\\pm\\frac{\\pi}{3}+2\\pi k$;  б) $\\frac{7\\pi}{3},\\frac{5\\pi}{2},\\frac{7\\pi}{2}$ \n";
            break;

            case 4:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\sin\\left(x+\\frac{\\pi}{3}\\right)+\\cos(2x)=\\sqrt{3}\\cos(x)+1$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-3\\pi;-\\frac{3\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\pi k,\\frac{\\pi}{6}+2\\pi k, \\frac{5\\pi}{6}+2\\pi k$;  б) $-3\\pi, -2\\pi,-\\frac{11\\pi}{6}$ \n";
            break;

            case 5:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\sin\\left(2x+\\frac{\\pi}{6}\\right)-\\cos(x)=\\sqrt{3}\\sin(2x)-1$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{5\\pi}{2};4\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{2}+\\pi k, \\pm \\frac{\\pi}{3}+2\\pi k$;  б) $\\frac{5\\pi}{2}, \\frac{7\\pi}{2}, \\frac{11\\pi}{3}$\n";
            break;

            case 6:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\sin(x)+2\\sin\\left(2x+\\frac{\\pi}{6}\\right)=\\sqrt{3}\\sin(2x)+1$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-\\frac{7\\pi}{2};-2\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\pi k, \\frac{\\pi}{6}+2\\pi k,\\frac{5\\pi}{6}+2\\pi k$; б) $-\\frac{23\\pi}{6},-3\\pi,-2\\pi$\n";
            break;

            case 7:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\sin\\left(x+\\frac{\\pi}{3}\\right)-\\sqrt{3}\\cos(2x)=\\sin(x)+\\sqrt{3}$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-2\\pi;-\\frac{\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{2}+\\pi k,\\pm\\frac{\\pi}{3}+2\\pi k$;  б) $-\\frac{5\\pi}{3},-\\frac{3\\pi}{2}, -\\frac{\\pi}{2}$ \n";
            break;
        }
    }
    return Answer;
}

string Uravn5(int Type)
{
    string Answer;
    int type;
    if(Type == 1)
    {
        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\sin^2\\left(\\frac{\\pi}{2}-x\\right)+\\sin(2x)=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[3\\pi;\\frac{9\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = "  \\item а) $\\frac{\\pi}{2}+\\pi k, -\\frac{\\pi}{4}+\\pi k$; б) $\\frac{7\\pi}{2}, \\frac{15\\pi}{4}, \\frac{9\\pi}{2}$ \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\sin^2\\left(\\frac{3\\pi}{2}+x\\right)+\\cos(\\pi-x)=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-2\\pi;-\\frac{\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{2}+\\pi k, \\pm\\frac{\\pi}{3}+2\\pi k$; б) $-\\frac{5\\pi}{3},-\\frac{3\\pi}{2},-\\frac{\\pi}{2}$ \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\cos(2x)-\\sqrt{2}\\cos\\left(\\frac{3\\pi}{2}+x\\right)-1=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{3\\pi}{2};3\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\pi k,-\\frac{\\pi}{4}+2\\pi k, -\\frac{3\\pi}{4}+2\\pi k$; б) $\\frac{7\\pi}{4}, 2\\pi, 3\\pi$ \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\sqrt{3}\\sin^2\\left(x+\\frac{3\\pi}{2}\\right)+\\sin(2x)=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-4\\pi;-\\frac{5\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{2}+\\pi k,-\\frac{\\pi}{3}+\\pi k$;  б) $-\\frac{7\\pi}{2},-\\frac{10\\pi}{3},-\\frac{5\\pi}{2}$\n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\cos^2(x)+3\\sin(x+\\pi)-3=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[2\\pi;\\frac{7\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $-\\frac{\\pi}{2}+2\\pi k, -\\frac{\\pi}{6}+2\\pi k,-\\frac{5\\pi}{6}+2\\pi k$;  б) $\\frac{19\\pi}{6},\\frac{7\\pi}{2}$\n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\sin^2(x)+\\cos(-x)-1=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-\\frac{9\\pi}{2};-3\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{2\\pi k}{3}$;  б) $-4\\pi, -\\frac{10\\pi}{3}$\n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\cos^2(x)+3\\sin(-x)-3=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[2\\pi;\\frac{7\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $-\\frac{\\pi}{2}+2\\pi k,-\\frac{\\pi}{6}+2\\pi k,-\\frac{5\\pi}{6}+2\\pi k$;  б) $\\frac{19\\pi}{6},\\frac{7\\pi}{2}$\n";
    }
    if(Type == 2)
    {
        type = rand()%7 + 1;
        switch(type)
        {
            case 1:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\sin^2\\left(\\frac{\\pi}{2}-x\\right)+\\sin(2x)=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[3\\pi;\\frac{9\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = "  \\item а) $\\frac{\\pi}{2}+\\pi k, -\\frac{\\pi}{4}+\\pi k$; б) $\\frac{7\\pi}{2}, \\frac{15\\pi}{4}, \\frac{9\\pi}{2}$ \n";
            break;

            case 2:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\sin^2\\left(\\frac{3\\pi}{2}+x\\right)+\\cos(\\pi-x)=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-2\\pi;-\\frac{\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{2}+\\pi k, \\pm\\frac{\\pi}{3}+2\\pi k$; б) $-\\frac{5\\pi}{3},-\\frac{3\\pi}{2},-\\frac{\\pi}{2}$ \n";
            break;

            case 3:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\cos(2x)-\\sqrt{2}\\cos\\left(\\frac{3\\pi}{2}+x\\right)-1=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{3\\pi}{2};3\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\pi k,-\\frac{\\pi}{4}+2\\pi k, -\\frac{3\\pi}{4}+2\\pi k$; б) $\\frac{7\\pi}{4}, 2\\pi, 3\\pi$ \n";
            break;

            case 4:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\sqrt{3}\\sin^2\\left(x+\\frac{3\\pi}{2}\\right)+\\sin(2x)=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-4\\pi;-\\frac{5\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{2}+\\pi k,-\\frac{\\pi}{3}+\\pi k$;  б) $-\\frac{7\\pi}{2},-\\frac{10\\pi}{3},-\\frac{5\\pi}{2}$\n";
            break;

            case 5:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\cos^2(x)+3\\sin(x+\\pi)-3=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[2\\pi;\\frac{7\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $-\\frac{\\pi}{2}+2\\pi k, -\\frac{\\pi}{6}+2\\pi k,-\\frac{5\\pi}{6}+2\\pi k$;  б) $\\frac{19\\pi}{6},\\frac{7\\pi}{2}$\n";
            break;

            case 6:
                 cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\sin^2(x)+\\cos(-x)-1=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-\\frac{9\\pi}{2};-3\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{2\\pi k}{3}$;  б) $-4\\pi, -\\frac{10\\pi}{3}$\n";
            break;

            case 7:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\cos^2(x)+3\\sin(-x)-3=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[2\\pi;\\frac{7\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $-\\frac{\\pi}{2}+2\\pi k,-\\frac{\\pi}{6}+2\\pi k,-\\frac{5\\pi}{6}+2\\pi k$;  б) $\\frac{19\\pi}{6},\\frac{7\\pi}{2}$\n";
            break;           
        }
    }
    return Answer;
}

string Uravn6(int Type)
{
    string Answer;
    int type;
    if(Type == 1)
    {
        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\sin^3(x)=\\sqrt{2}\\cos^2(x)+2\\sin(x)$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-4\\pi;-\\frac{5\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = "  \\item а) $\\frac{\\pi}{2}+\\pi k,-\\frac{\\pi}{4}+2\\pi k, -\\frac{3\\pi}{4}+2\\pi k$;  б) $-\\frac{7\\pi}{2},-\\frac{11\\pi}{4},-\\frac{5\\pi}{2}$ \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\cos(x)-\\sqrt{3}\\sin^2(x)=2\\cos^3(x)$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-\\frac{7\\pi}{2};-2\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\pi k, \\pm\\frac{\\pi}{6}+2\\pi k$;  б) $-3\\pi,-\\frac{13\\pi}{6}$ \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\sin(x)\\cdot\\cos(2x)+\\sqrt{2}\\cos^2(x)+\\sin(x)=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{3\\pi}{2};3\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{2}+\\pi k,-\\frac{\\pi}{4}+2\\pi k, -\\frac{3\\pi}{4}+2\\pi k$;  б) $\\frac{3\\pi}{2},\\frac{7\\pi}{4},\\frac{5\\pi}{2}$ \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\cos^3(x)-\\cos^2(x)+2\\cos(x)-1=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[2\\pi;\\frac{7\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\pm\\frac{\\pi}{3}+2\\pi k$;  б) $\\frac{7\\pi}{3}$ \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\cos^3(x)+\\sqrt{2}\\sin^2(x)=2\\cos(x)$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{5\\pi}{2};4\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\pi k,\\pm\\frac{\\pi}{4}+2\\pi k$;  б) $3\\pi,\\frac{15\\pi}{4},4\\pi$ \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\cos(x)\\cdot\\cos(2x)=\\sqrt{2}\\sin^2(x)+\\cos(x)$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-\\frac{5\\pi}{2};-\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\pi k,\\pm\\frac{3\\pi}{4}+2\\pi k$;  б) $-2\\pi,-\\frac{5\\pi}{4},-\\pi$  \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\cos^3(x)+\\sqrt{3}\\cos^2(x)+2\\cos(x)+\\sqrt{3}=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{3\\pi}{2};3\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\pm\\frac{5\\pi}{6}+2\\pi k$;  б) $\\frac{17\\pi}{6}$  \n";

        cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\sin(x)\\cdot\\cos^2(x)+\\sqrt{3}=\\sqrt{3}\\sin^2(x)$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-\\frac{7\\pi}{2};-2\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{2}+\\pi k, -\\frac{\\pi}{3}+2\\pi k,-\\frac{2\\pi}{3}+2\\pi k$;  б) $-\\frac{7\\pi}{2},-\\frac{5\\pi}{2}, -\\frac{7\\pi}{3},-\\frac{8\\pi}{3}$ \n";
    }
    if(Type == 2)
    {
        type = rand()%8+1;
        switch(type)
        {
            case 1:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\sin^3(x)=\\sqrt{2}\\cos^2(x)+2\\sin(x)$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-4\\pi;-\\frac{5\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = "  \\item а) $\\frac{\\pi}{2}+\\pi k,-\\frac{\\pi}{4}+2\\pi k, -\\frac{3\\pi}{4}+2\\pi k$;  б) $-\\frac{7\\pi}{2},-\\frac{11\\pi}{4},-\\frac{5\\pi}{2}$ \n";
            break;

            case 2:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\cos(x)-\\sqrt{3}\\sin^2(x)=2\\cos^3(x)$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-\\frac{7\\pi}{2};-2\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\pi k, \\pm\\frac{\\pi}{6}+2\\pi k$;  б) $-3\\pi,-\\frac{13\\pi}{6}$ \n";
            break;

            case 3:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\sin(x)\\cdot\\cos(2x)+\\sqrt{2}\\cos^2(x)+\\sin(x)=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{3\\pi}{2};3\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{2}+\\pi k,-\\frac{\\pi}{4}+2\\pi k, -\\frac{3\\pi}{4}+2\\pi k$;  б) $\\frac{3\\pi}{2},\\frac{7\\pi}{4},\\frac{5\\pi}{2}$ \n";
            break;

            case 4:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\cos^3(x)-\\cos^2(x)+2\\cos(x)-1=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[2\\pi;\\frac{7\\pi}{2}\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\pm\\frac{\\pi}{3}+2\\pi k$;  б) $\\frac{7\\pi}{3}$ \n";
            break;

            case 5:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\cos^3(x)+\\sqrt{2}\\sin^2(x)=2\\cos(x)$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{5\\pi}{2};4\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\pi k,\\pm\\frac{\\pi}{4}+2\\pi k$;  б) $3\\pi,\\frac{15\\pi}{4},4\\pi$ \n";
            break;

            case 6:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$\\cos(x)\\cdot\\cos(2x)=\\sqrt{2}\\sin^2(x)+\\cos(x)$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-\\frac{5\\pi}{2};-\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\pi k,\\pm\\frac{3\\pi}{4}+2\\pi k$;  б) $-2\\pi,-\\frac{5\\pi}{4},-\\pi$  \n";
            break;

            case 7:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\cos^3(x)+\\sqrt{3}\\cos^2(x)+2\\cos(x)+\\sqrt{3}=0$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[\\frac{3\\pi}{2};3\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\pm\\frac{5\\pi}{6}+2\\pi k$;  б) $\\frac{17\\pi}{6}$  \n";
            break;

            case 8:
                cout << "\\item" << endl << "   \\begin{enumerate}" << endl <<
            "   \\item      Решите уравнение: $$2\\sin(x)\\cdot\\cos^2(x)+\\sqrt{3}=\\sqrt{3}\\sin^2(x)$$" << endl <<
            "   \\item      Найдите все корни этого уравнения, принадлежащие отрезку $\\left[-\\frac{7\\pi}{2};-2\\pi\\right]$." << endl <<
            "   \\end{enumerate}" << endl;
        Answer = Answer + "  \\item а) $\\frac{\\pi}{2}+\\pi k, -\\frac{\\pi}{3}+2\\pi k,-\\frac{2\\pi}{3}+2\\pi k$;  б) $-\\frac{7\\pi}{2},-\\frac{5\\pi}{2}, -\\frac{7\\pi}{3},-\\frac{8\\pi}{3}$ \n";
            break;
        }
    }
    return Answer;
}

string Nerav1(int Type)
{
    string Answer;
    int type;
    if(Type == 1)
    {
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{15^x-3^{x+1}-5^{x+1}+15}{-x^2+2x}\\geq0$$" << endl;
        Answer = "  \\item $(0;\\log_5(3)]\\cup[\\log_3(5);2)$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{10^x-25\\cdot 2^x-2\\cdot 5^x+50}{5x-x^2-4}\\geq0$$" << endl;
        Answer = Answer + "  \\item $[2;4)$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{4^x-3\\cdot 2^{x+1}+4}{2^x-5}+\\frac{3\\cdot 2^{x+1}-46}{2^x-8}\\leq2^x+5$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;1]\\cup(\\log_2(5);3)$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{8^{x+1}-40}{2\\cdot 64^x-32}\\leq1$$" << endl;
        Answer = Answer + "  \\item $\\{\\frac{1}{3}\\}\\cup(\\frac{2}{3};+\\infty)$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{2\\cdot 8^{x-1}}{2\\cdot 8^{x-1}-1}\\geq \\frac{3}{8^x-1}+\\frac{8}{64^x-5\\cdot 8^x+4}$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;0)\\cup \\{\\frac{1}{3}\\}\\cup(\\frac{2}{3};+\\infty)$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{13}{3^x-81}\\leq\\frac{1}{3^x-9}$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;1]\\cup(2;4)$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{8^{x+\\frac{2}{3}}-9\\cdot 4^{x+\\frac{1}{2}}+13\\cdot 2^x-13}{4^{x+\\frac{1}{2}}-9\\cdot 2^x+4}\\leq 2^{x+1}-\\frac{1}{2^x-2}+\\frac{3}{2^{x+1}-1}$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;-1)\\cup(-1;1)\\cup [\\log_2(3);2)$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{4}{3^x-27}\\geq\\frac{1}{3^x-9}$$" << endl;
        Answer = Answer + "  \\item $[1;2)\\cup(3;+\\infty)$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$12^x-8^x-2\\cdot 6^{x+1}+3\\cdot 4^{x+1}+32\\cdot 3^x-2^{x+5}\\leq0$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;0]\\cup[2;3]$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$3^x+\\frac{243}{3^x-84}\\leq0$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;1]\\cup[4;1+\\log_3(28))$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{1}{3^x+21}+\\frac{1}{3^x-27}\\geq 0$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;1]\\cup(3;+\\infty)$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{3^x+9}{3^x-9}+\\frac{3^x-9}{3^x+9}\\geq\\frac{4\\cdot 3^{x+1}+144}{9^x-81}$$" << endl;
        Answer = Answer + "  \\item $\\{1\\}\\cup(2;+\\infty)$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$3^x+\\frac{243}{3^x-36}\\geq0$$" << endl;
        Answer = Answer + "  \\item $[2;3]\\cup(2+2\\log_3(2);+\\infty)$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{2}{3^x+27}\\geq\\frac{1}{3^x-27}$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;3)\\cup[4;+\\infty)$ \n";
    }
    if(Type == 2)
    {
        type = rand()%14+1;
        switch(type)
        {
            case 1:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{15^x-3^{x+1}-5^{x+1}+15}{-x^2+2x}\\geq0$$" << endl;
        Answer = "  \\item $(0;\\log_5(3)]\\cup[\\log_3(5);2)$ \n";
            break;

            case 2:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{10^x-25\\cdot 2^x-2\\cdot 5^x+50}{5x-x^2-4}\\geq0$$" << endl;
        Answer = Answer + "  \\item $[2;4)$ \n";
            break;

            case 3:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{4^x-3\\cdot 2^{x+1}+4}{2^x-5}+\\frac{3\\cdot 2^{x+1}-46}{2^x-8}\\leq2^x+5$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;1]\\cup(\\log_2(5);3)$ \n";
            break;

            case 4:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{8^{x+1}-40}{2\\cdot 64^x-32}\\leq1$$" << endl;
        Answer = Answer + "  \\item $\\{\\frac{1}{3}\\}\\cup(\\frac{2}{3};+\\infty)$ \n";
            break;

            case 5:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{2\\cdot 8^{x-1}}{2\\cdot 8^{x-1}-1}\\geq \\frac{3}{8^x-1}+\\frac{8}{64^x-5\\cdot 8^x+4}$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;0)\\cup \\{\\frac{1}{3}\\}\\cup(\\frac{2}{3};+\\infty)$ \n";
            break;

            case 6:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{13}{3^x-81}\\leq\\frac{1}{3^x-9}$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;1]\\cup(2;4)$ \n";
            break;

            case 7:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{8^{x+\\frac{2}{3}}-9\\cdot 4^{x+\\frac{1}{2}}+13\\cdot 2^x-13}{4^{x+\\frac{1}{2}}-9\\cdot 2^x+4}\\leq 2^{x+1}-\\frac{1}{2^x-2}+\\frac{3}{2^{x+1}-1}$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;-1)\\cup(-1;1)\\cup [\\log_2(3);2)$ \n";
            break;

            case 8:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{4}{3^x-27}\\geq\\frac{1}{3^x-9}$$" << endl;
        Answer = Answer + "  \\item $[1;2)\\cup(3;+\\infty)$ \n";
            break;

            case 9:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$12^x-8^x-2\\cdot 6^{x+1}+3\\cdot 4^{x+1}+32\\cdot 3^x-2^{x+5}\\leq0$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;0]\\cup[2;3]$ \n";
            break;

            case 10:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$3^x+\\frac{243}{3^x-84}\\leq0$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;1]\\cup[4;1+\\log_3(28))$ \n";
            break;

            case 11:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{1}{3^x+21}+\\frac{1}{3^x-27}\\geq 0$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;1]\\cup(3;+\\infty)$ \n";
            break;

            case 12:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{3^x+9}{3^x-9}+\\frac{3^x-9}{3^x+9}\\geq\\frac{4\\cdot 3^{x+1}+144}{9^x-81}$$" << endl;
        Answer = Answer + "  \\item $\\{1\\}\\cup(2;+\\infty)$ \n";
            break;

            case 13:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$3^x+\\frac{243}{3^x-36}\\geq0$$" << endl;
        Answer = Answer + "  \\item $[2;3]\\cup(2+2\\log_3(2);+\\infty)$ \n";
            break;

            case 14:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{2}{3^x+27}\\geq\\frac{1}{3^x-27}$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;3)\\cup[4;+\\infty)$ \n";
            break;
        }
    }
    return Answer;
}

string Nerav2(int Type)
{
    string Answer;
    int type;
    if(Type == 1)
    {
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{\\log_2x^2-\\log_3x^2}{\\log^2_6(2x^2-10x+12,5)+1}\\geq0$$" << endl;
        Answer = "  \\item $(-\\infty;-1]\\cup [1;2.5)\\cup(2.5;+\\infty)$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{\\log_8x}{\\log_8(\\frac{x}{64})}\\geq\\frac{2}{\\log_8x}+\\frac{3}{\\log^2_8x-\\log_8x^2}$$" << endl;
        Answer = Answer + "  \\item $(0;1)\\cup\\{8\\}\\cup(64;+\\infty)$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{\\log_2(2-x)-\\log_2(x+1)}{\\log^2_2x^2+\\log_2x^4+1}\\geq 0$$" << endl;
        Answer = Answer + "  \\item $(-1;-\\frac{\\sqrt{2}}{2})\\cup(-\\frac{\\sqrt{2}}{2};0)\\cup(0;\\frac{1}{2}]$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{2\\log_3(9x)-13}{\\log^2_3x-\\log_3x^4}\\leq 1$$" << endl;
        Answer = Answer + "  \\item $(0;1)\\cup\\{27\\}\\cup(81;+\\infty))$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{\\log_2(4x^2)+35}{\\log^2_2x-36}\\geq -1$$" << endl;
        Answer = Answer + "  \\item $(0;\\frac{1}{64})\\cup\\{\\frac{1}{2}\\}\\cup(64;+\\infty)$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$1+\\frac{6}{\\log_3x-3}+\\frac{5}{\\log^2_3x-\\log_3(27x^6)+12}\\geq 0$$" << endl;
        Answer = Answer + "  \\item $(0;\\frac{1}{9}]\\cup[9;27)\\cup(27;+\\infty)$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{\\log_3(81x)}{\\log_3x-4}+\\frac{\\log_3x-4}{\\log_3(81x)}\\geq\\frac{24-\\log_3x^8}{\\log^2_3x-16}$$" << endl;
        Answer = Answer + "  \\item $(0;\\frac{1}{81})\\cup\\{\\frac{1}{9}\\}\\cup(81;+\\infty)$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_3\\left((2-x)(x^2+5)\\right)\\geq\\log_3(x^2-5x+6)+\\log_3(4-x)$$" << endl;
        Answer = Answer + "  \\item $[1;2)$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$1+\\frac{5}{\\log_4x-3}+\\frac{6}{\\log^2_4x-\\log_4\\left(64x^6\\right)+12}\\geq 0$$" << endl;
        Answer = Answer + "  \\item $(0;1]\\cup[4;64)\\cup(64;+\\infty)$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$1+\\frac{10}{\\log_2x-5}+\\frac{16}{\\log^2_2x-\\log_2\\left(32x^{10}\\right)+30}\\geq 0$$" << endl;
        Answer = Answer + "  \\item $(0;\\frac{1}{8}]\\cup[8;32)\\cup(32;+\\infty)$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{\\log_5(25x)}{\\log_5x-2}+\\frac{\\log_5x-2}{\\log_5(25x)}\\geq \\frac{6-\\log_5x^4}{\\log^2_5x-4}$$" << endl;
        Answer = Answer + "  \\item $(0;\\frac{1}{25})\\cup\\{\\frac{1}{5}\\}\\cup(25;+\\infty)$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{\\log_2(32x)}{\\log_2x-5}+\\frac{\\log_2x-5}{\\log_2(32x)}\\geq \\frac{\\log_2x^{16}+18}{\\log^2_2x-25}$$" << endl;
        Answer = Answer + "  \\item $(0;\\frac{1}{32})\\cup\\{16\\}\\cup(32;+\\infty)$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{\\log_4(16x^4)+11}{\\log^2_4(x)-9}\\geq -1$$" << endl;
        Answer = Answer + "  \\item $(0;\\frac{1}{64})\\cup\\{\\frac{1}{16}\\}\\cup(64;+\\infty)$ \n";

        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{\\log_4(64x)}{\\log_4x-3}+\\frac{\\log_4x-3}{\\log_4(64x)}\\geq \\frac{\\log_4x^4+16}{\\log^2_4x-9}$$" << endl;
        Answer = Answer + "  \\item $(0;\\frac{1}{64})\\cup\\{4\\}\\cup(64;+\\infty)$ \n";
    }
    if(Type == 2)
    {
        type = rand()%14+1;
        switch(type)
        {
            case 1:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{\\log_2x^2-\\log_3x^2}{\\log^2_6(2x^2-10x+12,5)+1}\\geq0$$" << endl;
        Answer = "  \\item $(-\\infty;-1]\\cup [1;2.5)\\cup(2.5;+\\infty)$ \n";
            break;

            case 2:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{\\log_8x}{\\log_8(\\frac{x}{64})}\\geq\\frac{2}{\\log_8x}+\\frac{3}{\\log^2_8x-\\log_8x^2}$$" << endl;
        Answer = Answer + "  \\item $(0;1)\\cup\\{8\\}\\cup(64;+\\infty)$ \n";
            break;

            case 3:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{\\log_2(2-x)-\\log_2(x+1)}{\\log^2_2x^2+\\log_2x^4+1}\\geq 0$$" << endl;
        Answer = Answer + "  \\item $(-1;-\\frac{\\sqrt{2}}{2})\\cup(-\\frac{\\sqrt{2}}{2};0)\\cup(0;\\frac{1}{2}]$ \n";
            break;

            case 4:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{2\\log_3(9x)-13}{\\log^2_3x-\\log_3x^4}\\leq 1$$" << endl;
        Answer = Answer + "  \\item $(0;1)\\cup\\{27\\}\\cup(81;+\\infty))$ \n";
            break;

            case 5:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{\\log_2(4x^2)+35}{\\log^2_2x-36}\\geq -1$$" << endl;
        Answer = Answer + "  \\item $(0;\\frac{1}{64})\\cup\\{\\frac{1}{2}\\}\\cup(64;+\\infty)$ \n";
            break;

            case 6:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$1+\\frac{6}{\\log_3x-3}+\\frac{5}{\\log^2_3x-\\log_3(27x^6)+12}\\geq 0$$" << endl;
        Answer = Answer + "  \\item $(0;\\frac{1}{9}]\\cup[9;27)\\cup(27;+\\infty)$ \n";
            break;

            case 7:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{\\log_3(81x)}{\\log_3x-4}+\\frac{\\log_3x-4}{\\log_3(81x)}\\geq\\frac{24-\\log_3x^8}{\\log^2_3x-16}$$" << endl;
        Answer = Answer + "  \\item $(0;\\frac{1}{81})\\cup\\{\\frac{1}{9}\\}\\cup(81;+\\infty)$ \n";
            break;

            case 8:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_3\\left((2-x)(x^2+5)\\right)\\geq\\log_3(x^2-5x+6)+\\log_3(4-x)$$" << endl;
        Answer = Answer + "  \\item $[1;2)$ \n";
            break;

            case 9:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$1+\\frac{5}{\\log_4x-3}+\\frac{6}{\\log^2_4x-\\log_4\\left(64x^6\\right)+12}\\geq 0$$" << endl;
        Answer = Answer + "  \\item $(0;1]\\cup[4;64)\\cup(64;+\\infty)$ \n";
            break;

            case 10:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$1+\\frac{10}{\\log_2x-5}+\\frac{16}{\\log^2_2x-\\log_2\\left(32x^{10}\\right)+30}\\geq 0$$" << endl;
        Answer = Answer + "  \\item $(0;\\frac{1}{8}]\\cup[8;32)\\cup(32;+\\infty)$ \n";
            break;

            case 11:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{\\log_5(25x)}{\\log_5x-2}+\\frac{\\log_5x-2}{\\log_5(25x)}\\geq \\frac{6-\\log_5x^4}{\\log^2_5x-4}$$" << endl;
        Answer = Answer + "  \\item $(0;\\frac{1}{25})\\cup\\{\\frac{1}{5}\\}\\cup(25;+\\infty)$ \n";
            break;

            case 12:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{\\log_2(32x)}{\\log_2x-5}+\\frac{\\log_2x-5}{\\log_2(32x)}\\geq \\frac{\\log_2x^{16}+18}{\\log^2_2x-25}$$" << endl;
        Answer = Answer + "  \\item $(0;\\frac{1}{32})\\cup\\{16\\}\\cup(32;+\\infty)$ \n";
            break;

            case 13:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{\\log_4(16x^4)+11}{\\log^2_4(x)-9}\\geq -1$$" << endl;
        Answer = Answer + "  \\item $(0;\\frac{1}{64})\\cup\\{\\frac{1}{16}\\}\\cup(64;+\\infty)$ \n";
            break;

            case 14:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{\\log_4(64x)}{\\log_4x-3}+\\frac{\\log_4x-3}{\\log_4(64x)}\\geq \\frac{\\log_4x^4+16}{\\log^2_4x-9}$$" << endl;
        Answer = Answer + "  \\item $(0;\\frac{1}{64})\\cup\\{4\\}\\cup(64;+\\infty)$ \n";
            break;
        }
    }
    return Answer;
}

string Nerav3(int Type)
{
    string Answer;
    int type;
    if(Type == 1)
    {
        //1
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{\\log_3(9x)\\cdot\\log_4(64x)}{5x^2-|x|}\\leq 0$$" << endl;
        Answer = "  \\item $(0;\\frac{1}{64}]\\cup[\\frac{1}{9};\\frac{1}{5})$ \n";

        //2
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_{16}(x+5)+\\log_{(x^2+10x+25)}2\\geq\\frac{3}{4}$$" << endl;
        Answer = Answer + "  \\item $(-4;-3]\\cup[-1;+\\infty)$ \n";

//3
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_{49}(x+4)+\\log_{(x^2+8x+16)}\\sqrt{7}\\leq -\\frac{3}{4}$$" << endl;
        Answer = Answer + "  \\item $(-4;-\\frac{27}{7}]\\cup[\\frac{\\sqrt{7}}{7}-4;;-3)$ \n";

//4
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{\\log_2(8x)\\cdot\\log_3(27x)}{x^2-|x|}\\leq0$$" << endl;
        Answer = Answer + "  \\item $(0;\\frac{1}{27}]\\cup[\\frac{1}{8};1)$ \n";
//5
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_5(3x+1)+\\log_5\\left(\\frac{1}{72x^2}+1\\right)\\geq\\log_5\\left(\\frac{1}{24x}+1\\right)$$" << endl;
        Answer = Answer + "  \\item $[-\\frac{1}{6};-\\frac{1}{24})\\cup(0;+\\infty)$ \n";
//6
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_5\\left(\\frac{2}{x}+2\\right)-\\log_5(x+3)\\leq\\log_5\\left(\\frac{x+6}{x^2}\\right)$$" << endl;
        Answer = Answer + "  \\item $[-2;-1)\\cup(0;9]$ \n";
//7
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$2\\log_2(x\\sqrt{5})-\\log_2\\left(\\frac{x}{1-x}\\right)\\leq\\log_2\\left(5x^2+\\frac{1}{x}-2\\right)$$" << endl;
        Answer = Answer + "  \\item $(0;\\frac{\\sqrt{5}}{5}]\\cup[\\frac{1}{2};1)$ \n";
//8
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log^2_2(25-x^2)-7\\log_2(25-x^2)+12\\geq 0$$" << endl;
        Answer = Answer + "  \\item $(-5;-\\sqrt{17}]\\cup[-3;3]\\cup[\\sqrt{17};5)$ \n";
//9
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_2(4x^2-1)-\\log_2x\\leq \\log_2\\left(5x+\\frac{9}{x}-11\\right)$$" << endl;
        Answer = Answer + "  \\item $(\\frac{1}{2};1]\\cup[10;+\\infty)$ \n";
//10
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_5\\left((3-x)(x^2+2)\\right)\\geq \\log_5(x^2-7x+12)+\\log_5(5-x)$$" << endl;
        Answer = Answer + "  \\item $[2;3)$ \n";
//11
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_4\\left((x-5)(x^2-2x-15)\\right)+1\\geq 0.5\\log_2(x-5)^2$$" << endl;
        Answer = Answer + "  \\item $[-\\frac{11}{4};5)\\cup(5;+\\infty)$ \n";
//12
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_{11}(2x^2+1)+\\log_{11}\\left(\\frac{1}{32x}+1\\right)\\geq \\log_{11}\\left(\\frac{x}{16}+1\\right)$$" << endl;
        Answer = Answer + "  \\item $(-16;-\\frac{1}{4}]\\cup(0;+\\infty)$ \n";
//13
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log^2_3(x^2-16)-5\\log_3(x^2-16)+6\\geq 0$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;-\\sqrt{43}]\\cup[-5;-4)\\cup(4;5]\\cup[\\sqrt{43};+\\infty)$ \n";
//14
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_{11}(8x^2+7)-\\log_{11}(x^2+x+1)\\geq \\log_{11}\\left(\\frac{x}{x+5}+7\\right)$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;-12]\\cup(-\\frac{35}{8};0]$ \n";
//15
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log^2_2(x^2-9)-9\\log_2(x^2-9)+20\\geq 0$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;-\\sqrt{41}]\\cup[-5;-3)\\cup(3;5]\\cup[\\sqrt{41};+\\infty)$ \n";
//16
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log^2_3(25-x^2)-3\\log_3(25-x^2)+2\\geq 0$$" << endl;
        Answer = Answer + "  \\item $(-5;-\\sqrt{22}]\\cup[-4;4]\\cup[\\sqrt{22};5)$ \n";
//17
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\left(\\log^2_{0.25}(x+3)-\\log_4(x^2+6x+9)+1\\right)\\cdot\\log_4(x+2)\\leq 0$$" << endl;
        Answer = Answer + "  \\item $(-2;-1]\\cup\\{1\\}$ \n";
//18
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_3\\left(\\frac{1}{x}+2\\right)-\\log_3(x+5)\\geq \\log_3\\left(\\frac{x+4}{x^2}\\right)$$" << endl;
        Answer = Answer + "  \\item $(-4;-2]\\cup[10;+\\infty)$ \n";
//19
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_{0.5}(x^3-3x^2-9x+27)\\leq \\log_{0.25}(x-3)^4$$" << endl;
        Answer = Answer + "  \\item $[-2;3)\\cup(3;+\\infty)$ \n";
//20
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_7(2x^2+12)-\\log_7(x^2-x+12)\\geq \\log_7\\left(2-\\frac{1}{x}\\right)$$" << endl;
        Answer = Answer + "  \\item $(\\frac{1}{2};\\frac{4}{3}]\\cup[3;+\\infty)$ \n";
//21
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_8(x^3-3x^2+3x-1)\\geq \\log_2(x^2-1)-5$$" << endl;
        Answer = Answer + "  \\item $(1;31]$ \n";

    }
    if(Type == 2)
    {
        type = rand()%21+1;
        switch(type)
        {
            case 1:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{\\log_3(9x)\\cdot\\log_4(64x)}{5x^2-|x|}\\leq 0$$" << endl;
        Answer = "  \\item $(0;\\frac{1}{64}]\\cup[\\frac{1}{9};\\frac{1}{5})$ \n";
            break;

            case 2:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_{16}(x+5)+\\log_{(x^2+10x+25)}2\\geq\\frac{3}{4}$$" << endl;
        Answer = Answer + "  \\item $(-4;-3]\\cup[-1;+\\infty)$ \n";
            break;

            case 3:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_{49}(x+4)+\\log_{(x^2+8x+16)}\\sqrt{7}\\leq -\\frac{3}{4}$$" << endl;
        Answer = Answer + "  \\item $(-4;-\\frac{27}{7}]\\cup[\\frac{\\sqrt{7}}{7}-4;;-3)$ \n";
            break;

            case 4:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\frac{\\log_2(8x)\\cdot\\log_3(27x)}{x^2-|x|}\\leq0$$" << endl;
        Answer = Answer + "  \\item $(0;\\frac{1}{27}]\\cup[\\frac{1}{8};1)$ \n";
            break;

            case 5:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_5(3x+1)+\\log_5\\left(\\frac{1}{72x^2}+1\\right)\\geq\\log_5\\left(\\frac{1}{24x}+1\\right)$$" << endl;
        Answer = Answer + "  \\item $[-\\frac{1}{6};-\\frac{1}{24})\\cup(0;+\\infty)$ \n";
            break;

            case 6:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_5\\left(\\frac{2}{x}+2\\right)-\\log_5(x+3)\\leq\\log_5\\left(\\frac{x+6}{x^2}\\right)$$" << endl;
        Answer = Answer + "  \\item $[-2;-1)\\cup(0;9]$ \n";
            break;

            case 7:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$2\\log_2(x\\sqrt{5})-\\log_2\\left(\\frac{x}{1-x}\\right)\\leq\\log_2\\left(5x^2+\\frac{1}{x}-2\\right)$$" << endl;
        Answer = Answer + "  \\item $(0;\\frac{\\sqrt{5}}{5}]\\cup[\\frac{1}{2};1)$ \n";
            break;

            case 8:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log^2_2(25-x^2)-7\\log_2(25-x^2)+12\\geq 0$$" << endl;
        Answer = Answer + "  \\item $(-5;-\\sqrt{17}]\\cup[-3;3]\\cup[\\sqrt{17};5)$ \n";
            break;

            case 9:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_2(4x^2-1)-\\log_2x\\leq \\log_2\\left(5x+\\frac{9}{x}-11\\right)$$" << endl;
        Answer = Answer + "  \\item $(\\frac{1}{2};1]\\cup[10;+\\infty)$ \n";
            break;

            case 10:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_5\\left((3-x)(x^2+2)\\right)\\geq \\log_5(x^2-7x+12)+\\log_5(5-x)$$" << endl;
        Answer = Answer + "  \\item $[2;3)$ \n";
            break;

            case 11:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_4\\left((x-5)(x^2-2x-15)\\right)+1\\geq 0.5\\log_2(x-5)^2$$" << endl;
        Answer = Answer + "  \\item $[-\\frac{11}{4};5)\\cup(5;+\\infty)$ \n";
            break;

            case 12:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_{11}(2x^2+1)+\\log_{11}\\left(\\frac{1}{32x}+1\\right)\\geq \\log_{11}\\left(\\frac{x}{16}+1\\right)$$" << endl;
        Answer = Answer + "  \\item $(-16;-\\frac{1}{4}]\\cup(0;+\\infty)$ \n";
            break;

            case 13:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log^2_3(x^2-16)-5\\log_3(x^2-16)+6\\geq 0$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;-\\sqrt{43}]\\cup[-5;-4)\\cup(4;5]\\cup[\\sqrt{43};+\\infty)$ \n";
            break;

            case 14:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_{11}(8x^2+7)-\\log_{11}(x^2+x+1)\\geq \\log_{11}\\left(\\frac{x}{x+5}+7\\right)$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;-12]\\cup(-\\frac{35}{8};0]$ \n";
            break;

            case 15:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log^2_2(x^2-9)-9\\log_2(x^2-9)+20\\geq 0$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;-\\sqrt{41}]\\cup[-5;-3)\\cup(3;5]\\cup[\\sqrt{41};+\\infty)$ \n";
            break;

            case 16:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log^2_3(25-x^2)-3\\log_3(25-x^2)+2\\geq 0$$" << endl;
        Answer = Answer + "  \\item $(-5;-\\sqrt{22}]\\cup[-4;4]\\cup[\\sqrt{22};5)$ \n";
            break;

            case 17:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\left(\\log^2_{0.25}(x+3)-\\log_4(x^2+6x+9)+1\\right)\\cdot\\log_4(x+2)\\leq 0$$" << endl;
        Answer = Answer + "  \\item $(-2;-1]\\cup\\{1\\}$ \n";
            break;

            case 18:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_3\\left(\\frac{1}{x}+2\\right)-\\log_3(x+5)\\geq \\log_3\\left(\\frac{x+4}{x^2}\\right)$$" << endl;
        Answer = Answer + "  \\item $(-4;-2]\\cup[10;+\\infty)$ \n";
            break;

            case 19:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_{0.5}(x^3-3x^2-9x+27)\\leq \\log_{0.25}(x-3)^4$$" << endl;
        Answer = Answer + "  \\item $[-2;3)\\cup(3;+\\infty)$ \n";
            break;

            case 20:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_7(2x^2+12)-\\log_7(x^2-x+12)\\geq \\log_7\\left(2-\\frac{1}{x}\\right)$$" << endl;
        Answer = Answer + "  \\item $(\\frac{1}{2};\\frac{4}{3}]\\cup[3;+\\infty)$ \n";
            break;

            case 21:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$\\log_8(x^3-3x^2+3x-1)\\geq \\log_2(x^2-1)-5$$" << endl;
        Answer = Answer + "  \\item $(1;31]$ \n";
            break;
        }
    }
    return Answer;
}

string Nerav4(int Type)
{
    string Answer;
    int type;
    if(Type == 1)
    {
         //1
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$x^2\\log_{243}(4-x)\\leq\\log_3(x^2-8x+16)$$" << endl;
        Answer = "  \\item $[-\\sqrt{10};3]\\cup[\\sqrt{10};4)$ \n";

        //2
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$x^2\\log_{625}(6-x)\\leq\\log_5(x^2-12x+36)$$" << endl;
        Answer = Answer + "  \\item $[-2\\sqrt{2};2\\sqrt{2}]\\cup[5;6)$ \n";

        //3
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$x^2\\log_{512}(4-x)\\geq\\log_2(x^2-8x+16)$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;-3\\sqrt{2}]\\cup[3;4)$ \n";

        //4
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$x^2\\log_{625}(-2-x)\\geq\\log_5(x^2+4x+4)$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;-3]\\cup[-2\\sqrt{2};-2)$ \n";

        //5
        cout << "\\item     Решите неравенство:" << endl <<
            "       $$x^2\\log_{512}(x+7)\\leq\\log_2(x^2+14x+49)$$" << endl;
        Answer = Answer + "  \\item $(-7;-6]\\cup[-3\\sqrt{2};3\\sqrt{2}]$ \n";
    }
    if(Type == 2)
    {
        type = rand()%5+1;
        switch(type)
        {
            case 1:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$x^2\\log_{243}(4-x)\\leq\\log_3(x^2-8x+16)$$" << endl;
         Answer = "  \\item $[-\\sqrt{10};3]\\cup[\\sqrt{10};4)$ \n";
            break;

            case 2:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$x^2\\log_{625}(6-x)\\leq\\log_5(x^2-12x+36)$$" << endl;
        Answer = Answer + "  \\item $[-2\\sqrt{2};2\\sqrt{2}]\\cup[5;6)$ \n";
            break;

            case 3:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$x^2\\log_{512}(4-x)\\geq\\log_2(x^2-8x+16)$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;-3\\sqrt{2}]\\cup[3;4)$ \n";
            break;

            case 4:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$x^2\\log_{625}(-2-x)\\geq\\log_5(x^2+4x+4)$$" << endl;
        Answer = Answer + "  \\item $(-\\infty;-3]\\cup[-2\\sqrt{2};-2)$ \n";
            break;

            case 5:
            cout << "\\item     Решите неравенство:" << endl <<
            "       $$x^2\\log_{512}(x+7)\\leq\\log_2(x^2+14x+49)$$" << endl;
        Answer = Answer + "  \\item $(-7;-6]\\cup[-3\\sqrt{2};3\\sqrt{2}]$ \n";
            break;
        }
    }
    return Answer;
}

string Finance1(int Type)
{
    string Answer;
    int type;
    if(Type == 1)
    {
        cout << "\\item     Планируется выдать льготный кредит на целое число миллионов рублей на пять лет. В середине каждого года действия кредита долг заёмщика возрастает на 20\\% по сравнению с началом года. В конце 1-го, 2-го и 3-го годов заёмщик выплачивает только проценты по кредиту, оставляя долг неизменно равным первоначальному. В конце 4-го и 5-го годов заёмщик выплачивает одинаковые суммы, погашая весь долг полностью. Найдите наибольший размер кредита, при котором общая сумма выплат заёмщика будет меньше 7 млн рублей." << endl;
        Answer = "  \\item 3 \n";

        cout << "\\item     Планируется выдать льготный кредит на целое число миллионов рублей на пять лет. В середине каждого года действия кредита долг заёмщика возрастает на 10\\% по сравнению с началом года. В конце 1-го, 2-го и 3-го годов заёмщик выплачивает только проценты по кредиту, оставляя долг неизменно равным первоначальному. В конце 4-го и 5-го годов заёмщик выплачивает одинаковые суммы, погашая весь долг полностью. Найдите наибольший размер кредита, при котором общая сумма выплат заёмщика будет меньше 6 млн рублей." << endl;
        Answer = Answer + "  \\item 4 \n";
        
        cout << "\\item     Пенсионный фонд владеет ценными бумагами, которые стоят 1 тыс. рублей в конце года $t^2$ $(t=1;2;\\ldots)$. В конце любого года пенсионный фонд может продать ценные бумаги и положить деньги на счёт в банке, при этом в конце каждого следующего года сумма на счёте будет увеличиваться на 10\\%. В конце какого года пенсионному фонду следует продать ценные бумаги, чтобы в конце двадцать пятого года сумма на его счёте была наибольшей?" << endl;
        Answer = Answer + "  \\item 21 \n";

        cout << "\\item     Пенсионный фонд владеет ценными бумагами, которые стоят 1 тыс. рублей в конце года $t^2$ $(t=1;2;\\ldots)$. В конце любого года пенсионный фонд может продать ценные бумаги и положить деньги на счёт в банке, при этом в конце каждого следующего года сумма на пенсионны фонд может продать ценные умаги и положить деньги на счет в банке, при этом в конце каждого следующего года сумма на счёте будет увеличиваться в $1+r$ раз. Пенсионный фонд хочет продать ценные бумаги в конце такого года, чтобы в конце двадцать пятого года сумма на его счёте была наибольшей. Расчёты показали, что для этого ценные бумаги нужно продавать строго в конце двадцать первого года. При каких положительных значениях $r$ это возможно?" << endl;
        Answer = Answer + "  \\item $(\\frac{43}{441};\\frac{41}{400})$ \n";

        cout << "\\item     Вклад планируется открыть на четыре года. Первоначальный вклад составляет целое число миллионов рублей. В конце каждого года вклад увеличивается на 10\\% по сравнению с его размером в начале года. Кроме этого, в начале третьего и четвёртого годов вклад ежегодно пополняется на 3 млн рублей. Найдите наименьший размер первоначального вклада, при котором через четыре года вклад будет больше 20 млн рублей." << endl;
        Answer = Answer + "  \\item 9 \n";

        cout << "\\item     Планируется выдать льготный кредит на целое число миллионов рублей на пять лет. В середине каждого года действия кредита долг заёмщика возрастает на 10\\% по сравнению с началом года. В конце 1-го, 2-го и 3-го годов заёмщик выплачивает только проценты по кредиту, оставляя долг неизменно равным первоначальному. В конце 4-го и 5-го годов заёмщик выплачивает одинаковые суммы, погашая весь долг полностью. Найдите наибольший размер кредита, при котором общая сумма выплат заёмщика будет меньше 6 млн рублей." << endl;
        Answer = Answer + "  \\item 4 \n";

        cout << "\\item     Пенсионный фонд владеет ценными бумагами, которые стоят в тыс. рублей в конце года $t^2$ $(t=1;2;\\ldots)$. В конце любого года пенсионный фонд может продать ценные бумаги и положить деньги на счёт в банке, при этом в конце каждого следующего года сумма на счёте будет увеличиваться в $1+r$ раз. Пенсионный фонд хочет продать ценные бумаги в конце такого года, чтобы в конце двадцатого года сумма на его счёте была наибольшей. Расчёты показали, что для этого ценные бумаги нужно продавать строго в конце девятого года. При каких положительных значениях $r$ это возможно?" << endl;
        Answer = Answer + "  \\item $(\\frac{19}{81};\\frac{17}{64})$ \n";
    }
    if(Type == 2)
    {
        type = rand()%7+1;
        switch(type)
        {
            case 1:
            cout << "\\item     Планируется выдать льготный кредит на целое число миллионов рублей на пять лет. В середине каждого года действия кредита долг заёмщика возрастает на 20\\% по сравнению с началом года. В конце 1-го, 2-го и 3-го годов заёмщик выплачивает только проценты по кредиту, оставляя долг неизменно равным первоначальному. В конце 4-го и 5-го годов заёмщик выплачивает одинаковые суммы, погашая весь долг полностью. Найдите наибольший размер кредита, при котором общая сумма выплат заёмщика будет меньше 7 млн рублей." << endl;
        Answer = "  \\item 3 \n";
            break;

            case 2:
            cout << "\\item     Планируется выдать льготный кредит на целое число миллионов рублей на пять лет. В середине каждого года действия кредита долг заёмщика возрастает на 10\\% по сравнению с началом года. В конце 1-го, 2-го и 3-го годов заёмщик выплачивает только проценты по кредиту, оставляя долг неизменно равным первоначальному. В конце 4-го и 5-го годов заёмщик выплачивает одинаковые суммы, погашая весь долг полностью. Найдите наибольший размер кредита, при котором общая сумма выплат заёмщика будет меньше 6 млн рублей." << endl;
        Answer = Answer + "  \\item 4 \n";
            break;

            case 3:
            cout << "\\item     Пенсионный фонд владеет ценными бумагами, которые стоят 1 тыс. рублей в конце года $t^2$ $(t=1;2;\\ldots)$. В конце любого года пенсионный фонд может продать ценные бумаги и положить деньги на счёт в банке, при этом в конце каждого следующего года сумма на счёте будет увеличиваться на 10\\%. В конце какого года пенсионному фонду следует продать ценные бумаги, чтобы в конце двадцать пятого года сумма на его счёте была наибольшей?" << endl;
        Answer = Answer + "  \\item 21 \n";
            break;

            case 4:
            cout << "\\item     Пенсионный фонд владеет ценными бумагами, которые стоят 1 тыс. рублей в конце года $t^2$ $(t=1;2;\\ldots)$. В конце любого года пенсионный фонд может продать ценные бумаги и положить деньги на счёт в банке, при этом в конце каждого следующего года сумма на пенсионны фонд может продать ценные умаги и положить деньги на счет в банке, при этом в конце каждого следующего года сумма на счёте будет увеличиваться в $1+r$ раз. Пенсионный фонд хочет продать ценные бумаги в конце такого года, чтобы в конце двадцать пятого года сумма на его счёте была наибольшей. Расчёты показали, что для этого ценные бумаги нужно продавать строго в конце двадцать первого года. При каких положительных значениях $r$ это возможно?" << endl;
        Answer = Answer + "  \\item $(\\frac{43}{441};\\frac{41}{400})$ \n";
            break;

            case 5:
            cout << "\\item     Вклад планируется открыть на четыре года. Первоначальный вклад составляет целое число миллионов рублей. В конце каждого года вклад увеличивается на 10\\% по сравнению с его размером в начале года. Кроме этого, в начале третьего и четвёртого годов вклад ежегодно пополняется на 3 млн рублей. Найдите наименьший размер первоначального вклада, при котором через четыре года вклад будет больше 20 млн рублей." << endl;
        Answer = Answer + "  \\item 9 \n";
            break;

            case 6:
            cout << "\\item     Планируется выдать льготный кредит на целое число миллионов рублей на пять лет. В середине каждого года действия кредита долг заёмщика возрастает на 10\\% по сравнению с началом года. В конце 1-го, 2-го и 3-го годов заёмщик выплачивает только проценты по кредиту, оставляя долг неизменно равным первоначальному. В конце 4-го и 5-го годов заёмщик выплачивает одинаковые суммы, погашая весь долг полностью. Найдите наибольший размер кредита, при котором общая сумма выплат заёмщика будет меньше 6 млн рублей." << endl;
        Answer = Answer + "  \\item 4 \n";
            break;

            case 7:
            cout << "\\item     Пенсионный фонд владеет ценными бумагами, которые стоят в тыс. рублей в конце года $t^2$ $(t=1;2;\\ldots)$. В конце любого года пенсионный фонд может продать ценные бумаги и положить деньги на счёт в банке, при этом в конце каждого следующего года сумма на счёте будет увеличиваться в $1+r$ раз. Пенсионный фонд хочет продать ценные бумаги в конце такого года, чтобы в конце двадцатого года сумма на его счёте была наибольшей. Расчёты показали, что для этого ценные бумаги нужно продавать строго в конце девятого года. При каких положительных значениях $r$ это возможно?" << endl;
        Answer = Answer + "  \\item $(\\frac{19}{81};\\frac{17}{64})$ \n";
            break;
        }
    }
    return Answer;
}

string Finance2(int Type)
{
    string Answer;
    int type;
    if(Type == 1)
    {
        cout << "\\item    \\begin{minipage}[t]{\\linewidth} \n В июле 2016 года планируется взять кредит в банке на три года в размере S млн рублей, где S - целое число. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг увеличивается на 30\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item в июле каждого года долг должен составлять часть кредита в соответствии со следующей таблицей:" << endl
            << "\\end{itemize}" << endl
            << "\\begin{center}" << endl
            << "\\resizebox{\\linewidth}{!}{%" << endl
            << "    \\begin{tabular}{|p{3cm}|p{2cm}|p{2cm}|p{2cm}|p{2cm}|}" << endl
            << "    \\hline" << endl
            << "    Месяц и год & Июль 2016 & Июль 2017 & Июль 2018 & Июль 2019 \\\\" << endl
            << "    \\hline" << endl
            << "    Долг (млн. руб.) & $S$ & $0.6S$ & $0.25S$ & $0$\\\\" << endl
            << "    \\hline" << endl
            << "\\end{tabular}  \n  } \n \\end{center}" << endl
            << "Найдите наибольшее значение S, при котором каждая из выплат будет меньше 5 млн рублей. \n \\end{minipage}" << endl << endl << endl; 
        Answer = "  \\item 7 \n";

        cout << "\\item   \\begin{minipage}[t]{\\linewidth} \n  В июле 2016 года планируется взять кредит в банке на три года в размере S млн рублей, где S - целое число. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг увеличивается на 15\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item в июле каждого года долг должен составлять часть кредита в соответствии со следующей таблицей:" << endl
            << "\\end{itemize}" << endl
            << "\\begin{center}" << endl
            << "\\resizebox{\\linewidth}{!}{%" << endl
            << "    \\begin{tabular}{|p{3cm}|p{2cm}|p{2cm}|p{2cm}|p{2cm}|}" << endl
            << "    \\hline" << endl
            << "    Месяц и год & Июль 2016 & Июль 2017 & Июль 2018 & Июль 2019 \\\\" << endl
            << "    \\hline" << endl
            << "    Долг (млн. руб.) & $S$ & $0.8S$ & $0.5S$ & $0$\\\\" << endl
            << "    \\hline" << endl
            << "\\end{tabular}  \n  } \n \\end{center}" << endl
            << "Найдите наибольшее значение S, при котором каждая из выплат будет меньше 4 млн рублей. \n \\end{minipage}" << endl << endl << endl; 
        Answer = Answer + "  \\item 6 \n";

    }
    if(Type == 2)
    {
        type = rand()%2+1;
        switch(type)
        {
            case 1:
            cout << "\\item    \\begin{minipage}[t]{\\linewidth} \n В июле 2016 года планируется взять кредит в банке на три года в размере S млн рублей, где S - целое число. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг увеличивается на 30\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item в июле каждого года долг должен составлять часть кредита в соответствии со следующей таблицей:" << endl
            << "\\end{itemize}" << endl
            << "\\begin{center}" << endl
            << "\\resizebox{\\linewidth}{!}{%" << endl
            << "    \\begin{tabular}{|p{3cm}|p{2cm}|p{2cm}|p{2cm}|p{2cm}|}" << endl
            << "    \\hline" << endl
            << "    Месяц и год & Июль 2016 & Июль 2017 & Июль 2018 & Июль 2019 \\\\" << endl
            << "    \\hline" << endl
            << "    Долг (млн. руб.) & $S$ & $0.6S$ & $0.25S$ & $0$\\\\" << endl
            << "    \\hline" << endl
            << "\\end{tabular}  \n  } \n \\end{center}" << endl
            << "Найдите наибольшее значение S, при котором каждая из выплат будет меньше 5 млн рублей. \n \\end{minipage}" << endl << endl << endl; 
        Answer = "  \\item 7 \n";
            break;

            case 2:
            cout << "\\item   \\begin{minipage}[t]{\\linewidth} \n  В июле 2016 года планируется взять кредит в банке на три года в размере S млн рублей, где S - целое число. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг увеличивается на 15\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item в июле каждого года долг должен составлять часть кредита в соответствии со следующей таблицей:" << endl
            << "\\end{itemize}" << endl
            << "\\begin{center}" << endl
            << "\\resizebox{\\linewidth}{!}{%" << endl
            << "    \\begin{tabular}{|p{3cm}|p{2cm}|p{2cm}|p{2cm}|p{2cm}|}" << endl
            << "    \\hline" << endl
            << "    Месяц и год & Июль 2016 & Июль 2017 & Июль 2018 & Июль 2019 \\\\" << endl
            << "    \\hline" << endl
            << "    Долг (млн. руб.) & $S$ & $0.8S$ & $0.5S$ & $0$\\\\" << endl
            << "    \\hline" << endl
            << "\\end{tabular}  \n  } \n \\end{center}" << endl
            << "Найдите наибольшее значение S, при котором каждая из выплат будет меньше 4 млн рублей. \n \\end{minipage}" << endl << endl << endl; 
        Answer = Answer + "  \\item 6 \n";
            break;
        }
    }
    return Answer;
}

string Finance3(int Type)
{
    string Answer;
    int type;
    if(Type == 1)
    {
        //1
        cout << "\\item     В июле планируется взять кредит в банке на сумму 7 млн рублей на срок 10 лет. Условия возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг возрастает на $r$\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь необходимо выплатить часть долга так, чтобы на начало июля каждого года долг уменьшался на одну и ту же сумму по сравнению с предыдущим июлем." << endl
            << "\\end{itemize}" << endl
            << "Найдите наименьшую возможную ставку $г$, если известно, что последний платёж будет не менее 0,819 млн рублей." << endl << endl << endl; 
        Answer = "  \\item 17 \n";
//2
        cout << "\\item     В июле планируется взять кредит в банке на сумму 8 млн рублей на срок 10 лет. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг возрастает на $r$\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь необходимо выплатить часть долга так, чтобы на начало июля каждого года долг уменьшался на одну и ту же сумму по сравнению с предыдущим июлем." << endl
            << "\\end{itemize}" << endl
            << "Найдите наименьшую возможную ставку $г$, если известно, что последний платёж будет не менее 0,92 млн рублей." << endl << endl << endl; 
        Answer = Answer + "  \\item 15 \n";
//3
        cout << "\\item     15-го декабря планируется взять кредит в банке на сумму 1 000 000 рублей на $(n + 1)$ месяц. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item 1-го числа каждого месяца долг возрастает на $r$\\% по сравнению с концом предыдущего месяца;" << endl
            << "    \\item со 2-го по 14-е число каждого месяца необходимо выплатить часть долга;" << endl
            << "    \\item 15-го числа каждого месяца с 1-го по $n$ -й долг должен быть на 40 тысяч рублей меньше долга на 15-е число предыдущего месяца;" << endl
            << "    \\item 15-го числа $n$ -го месяца долг составит 200 тысяч рублей;" << endl
            << "    \\item к 15-му числу $(n + 1)$ -го месяца кредит должен быть полностью погашен." << endl
            << "\\end{itemize}" << endl
            << "Найдите $r$, если известно, что общая сумма выплат после полного погашения кредита составит 1378 тысяч рублей." << endl << endl << endl; 
        Answer = Answer + "  \\item 3 \n";
//4
        cout << "\\item     5-го декабря планируется взять кредит в банке на 11 месяцев. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item 1-го числа каждого месяца долг возрастает на 1\\% по сравнению с концом предыдущего месяца;" << endl
            << "    \\item со 2-го по 14-е число каждого месяца необходимо выплатить часть долга;" << endl
            << "    \\item 15-го числа каждого месяца с 1-го по 10-й долг должен быть на одну и ту же сумму меньше долга на 15-е число предыдущего месяца;" << endl
            << "    \\item 15-го числа 10-го месяца долг составит 300 тысяч рублей;" << endl
            << "    \\item к 15-му числу 11-го месяца кредит должен быть полностью погашен." << endl
            << "\\end{itemize}" << endl
            << "Какую сумму планируется взять в кредит, если общая сумма выплат после полного его погашения составит 1388 тысяч рублей?" << endl << endl << endl; 
        Answer = Answer + "  \\item 1,3 \n";
//5
        cout << "\\item     В июле 2026 года планируется взять кредит в банке на сумму 177 120 рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг увеличивается на 25\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга." << endl
            << "\\end{itemize}" << endl
            << "Сколько рублей составит общая сумма платежей, если известно, что кредит будет полностью погашен четырьмя равными платежами (то есть за четыре года)?" << endl << endl << endl; 
        Answer = Answer + "  \\item 300 000 \n";
//6
        cout << "\\item     В июле 2026 года планируется взять кредит в банке на некоторую сумму. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг увеличивается на 20\\% по сравнению с конном предыдуушего года:" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга." << endl
            << "\\end{itemize}" << endl
            << "Сколько рублей будет выплачено банку, если известно, что кредит будет полностью погашен тремя равными платежами (то есть за три года) и общая сумма платежей после полного погашения кредита должна быть на 48 250 рублей больше суммы, взятой в кредит?" << endl << endl << endl; 
        Answer = Answer + "  \\item 162 000 \n";
//7
        cout << "\\item     В июле планируется взять кредит в банке на сумму 10 млн рублей на некоторый срок (целое число лет). Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг возрастает на 10\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить часть долга;" << endl
            << "    \\item в июле каждого года долг должен быть на одну и ту же сумму меньше долга на июль предыдущего года." << endl
            << "\\end{itemize}" << endl
            << "На сколько лет планируется взять кредит, если известно, что общая сумма выплат после его полного погашения составит 15 млн рублей?" << endl << endl << endl; 
        Answer = Answer + "  \\item 9 \n";
//8
        cout << "\\item     В июле 2020 года планируется взять кредит в банке на некоторую сумму. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг увеличивается на 10\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга." << endl
            << "\\end{itemize}" << endl
            << "Сколько рублей планируется взять в банке, если известно, что кредит будет полностью погашен четырьмя равными платежами (то есть за четыре года) и банку будет выплачено 292 820 рублей?" << endl << endl << endl;
        Answer = Answer + "  \\item 232 050 \n";
//9
        cout << "\\item     В июле 2026 года планируется взять кредит на три года в размере 800 тыс. рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг будет возрастать на 10\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item платежи в 2027 и 2028 годах должны быть равными;" << endl
            << "    \\item к июлю 2029 года долг должен быть выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Известно, что платёж в 2029 году составит 833,8 тыс. рублей. Сколько рублей составит платёж 2027 года?" << endl << endl << endl; 
        Answer = Answer + "  \\item 100 \n";
//10
        cout << "\\item     В июле 2025 года планируется взять кредит на десять лет. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг будет возрастать на 30\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо оплатить одним платежом часть долга;" << endl
            << "    \\item в июле 2026, 2027, 2028, 2029 и 2030 годов долг должен быть на какую-то одну и ту же величину меньше долга на июль предыдущего года," << endl
            << "    \\item в июле 2030 года долг должен составить 500 тыс. рублей;" << endl
            << "    \\item в июле 2031, 2032, 2033, 2034 и 2035 годов долг должен быть на другую одну и ту же величину меньше долга на июль предыдущего года;" << endl
            << "    \\item к июлю 2035 года долг должен быть выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Известно, что сумма всех платежей после полного погашения кредита будет равна 2080 тыс. рублей. Сколько рублей составит платёж в 2026 году?" << endl << endl << endl; 
        Answer = Answer + "  \\item 250 \n";
//11
        cout << "\\item     15-го декабря планируется взять кредит в банке на 21 месяц. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item 1-го числа каждого месяца долг возрастает на 3\\% по сравнению с концом предыдущего месяца;" << endl
            << "    \\item со 2-го по 14-е число каждого месяца необходимо выплатить часть долга;" << endl
            << "    \\item 15-го числа каждого месяца с 1-го по 20-й долг должен быть на 30 тысяч рублей меньше долга на 15-е число предыдущего месяца;" << endl
            << "    \\item к 15-му числу 21-го месяца кредит должен быть полностью погашен." << endl
            << "\\end{itemize}" << endl
            << "Какую сумму планируется взять в кредит, если общая сумма выплат после полного его погашения составит 1604 тысячи рублей?" << endl << endl << endl; 
        Answer = Answer + "  \\item 1,1 \n";
//12
        cout << "\\item     15-го декабря планируется взять кредит в банке на сумму 900 тысяч рублей на 11 месяцев. Условия его возврата таковы." << endl
            << "\\begin{itemize}" << endl
            << "    \\item 1-го числа каждого месяца долг возрастает на $r$\\% по сравнению с концом предыдущего месяца;" << endl
            << "    \\item со 2-го по 14-е число каждого месяца необходимо выплатить часть долга;" << endl
            << "    \\item 15-го числа каждого месяца с 1-го по 10-й долг должен быть на одну и ту же сумму меньше долга на 15-е число предыдущего месяца;" << endl
            << "    \\item 15-го числа 10-го месяца долг составит 200 тысяч рублей;" << endl
            << "    \\item к 15-му числу 11-го месяца кредит должен быть полностью погашен." << endl
            << "\\end{itemize}" << endl
            << "Найдите $r$, если известно, что общая сумма выплат после полного погашения кредита составит 1021 тысячу рублей." << endl << endl << endl; 
        Answer = Answer + "  \\item 2 \n";
//13
        cout << "\\item     В июле планируется взять кредит в банке на сумму 5 млн рублей на некоторый срок (целое число лет). Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг возрастает на 20\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить часть долга;" << endl
            << "    \\item в июле каждого года долг должен быть на одну и ту же сумму меньше долга на июль предыдущего года." << endl
            << "\\end{itemize}" << endl
            << "На сколько лет планируется взять кредит, если известно, что общая сумма выплат после его полного погашения составит 7,5 млн рублей?" << endl << endl << endl; 
        Answer = Answer + "  \\item 4 \n";
//14
        cout << "\\item     В июле 2026 года планируется взять кредит на три года. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг будет возрастать на 20\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item платежи в 2027 и в 2028 годах должны быть по 500 тыс. рублей;" << endl
            << "    \\item к июлю 2029 года долг должен быть выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Известно, что сумма всех платежей после полного погашения кредита равна 1235,2 тыс. рублей. Какую сумму планируется взять в кредит?" << endl << endl << endl; 
        Answer = Answer + "  \\item 900 \n";
//15
        cout << "\\item     В июле 2026 года планируется взять кредит на три года. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг будет возрастать на 20\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item платежи в 2027 и в 2028 годах должны быть по 300 тыс. рублей;" << endl
            << "    \\item к июлю 2029 года долг должен быть выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Известно, что платёж в 2029 году будет равен 417,6 тыс. рублей. Какую сумму планируется взять в кредит?" << endl << endl << endl; 
        Answer = Answer + "  \\item 700 \n";
//16
        cout << "\\item     В июле 2020 года планируется взять кредит в банке на некоторую сумму. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг увеличивается на 10\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга." << endl
            << "\\end{itemize}" << endl
            << "Сколько рублей планируется взять в банке, если известно, что кредит будет полностью погашен тремя равными платежами (то есть за три года) и общая сумма выплат после полного погашения кредита на 40 980 рублей больше суммы, взятой в кредит?" << endl << endl << endl; 
        Answer = Answer + "  \\item 198 600 \n";
//17
        cout << "\\item     В июле 2025 года планируется взять кредит на десять лет в размере 1400 тыс. рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг будет возрастать на 10\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо оплатить одним платежом часть долга;" << endl
            << "    \\item в июле 2026, 2027, 2028, 2029 и 2030 годов долг должен быть на какую-то одну и ту же величину меньше долга на июль предыдущего года;" << endl
            << "    \\item в июле 2031, 2032, 2033, 2034 и 2035 годов долг должен быть на другую одну и ту же величину меньше долга на июль предыдущего года;" << endl
            << "    \\item к июлю 2035 года долг должен быть выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Известно, что сумма всех платежей после полного погашения кредита будет равна 2120 тыс. рублей. Сколько рублей составит платёж в 2026 году?" << endl << endl << endl; 
        Answer = Answer + "  \\item 300 \n";
//18
        cout << "\\item     В июле 2026 года планируется взять кредит в банке на пять лет в размере S тыс. рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг возрастает на 30\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item в июле 2027, 2028 и 2029 годов долг остаётся равным S тыс. рублей;" << endl
            << "    \\item выплаты в 2030 и 2031 годах равны по 338 тыс. рублей;" << endl
            << "    \\item к июлю 2031 года долг будет выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Найдите общую сумму выплат за пять лет." << endl << endl << endl; 
        Answer = Answer + "  \\item 1 090 \n";
//19
        cout << "\\item     В июле 2025 года планируется взять кредит на десять лет. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг будет возрастать на 20\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо оплатить одним платежом часть долга;" << endl
            << "    \\item в июле 2026, 2027, 2028, 2029 и 2030 годов долг должен быть на какую-то одну и ту же величину меньше долга на июль предыдущего года;" << endl
            << "    \\item в июле 2030 года долг должен составить 600 тыс. рублей;" << endl
            << "    \\item в июле 2031, 2032, 2033, 2034 и 2035 годов долг должен быть на другую одну и ту же величину меньше долга на июль предыдущего года;" << endl
            << "    \\item к июлю 2035 года долг должен быть выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Известно, что сумма всех платежей после полного погашения кредита будет равна 2360 тыс. рублей. Какую сумму планируется взять в кредит?" << endl << endl << endl; 
        Answer = Answer + "  \\item 1 100 \n";
//20
        cout << "\\item     В июле 2026 года планируется взять кредит на пять лет в размере 1050 тыс. рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг возрастает на 10\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item в июле 2027, 2028 и 2029 годов долг остаётся равным 1050 тыс. рублей;" << endl
            << "    \\item выплаты в 2030 и 2031 годах равны;" << endl
            << "    \\item к июлю 2031 года долг будет выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "На сколько рублей последняя выплата будет больше первой?" << endl << endl << endl; 
        Answer = Answer + "  \\item 500 \n";
//21
        cout << "\\item     15-го декабря планируется взять кредит в банке на сумму 600 тысяч рублей на $(n + 1)$ месяц. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item 1-го числа каждого месяца долг возрастает на 3\\% по сравнению с концом предыдущего месяца;" << endl
            << "    \\item со 2-го по 14-е число каждого месяца необходимо выплатить часть долга;" << endl
            << "    \\item 15-го числа каждого месяца с 1-го по $n$-й долг должен быть на одну и ту же сумму меньше долга на 15-е число предыдущего месяца;" << endl
            << "    \\item 15-го числа $n$-го месяца долг составит 200 тысяч рублей;" << endl
            << "    \\item к 15-му числу $(n + 1)$-го месяца кредит должен быть полностью погашен." << endl
            << "\\end{itemize}" << endl
            << "Найдите $n$, если известно, что общая сумма выплат после полного погашения кредита составит 852 тысячи рублей." << endl << endl << endl; 
        Answer = Answer + "  \\item 20 \n";
//22
        cout << "\\item     В июле 2026 года планируется взять кредит на три года в размере 900 тыс. рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг будет возрастать на 30\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item платежи в 2027 и 2028 годах должны быть равными;" << endl
            << "    \\item к июлю 2029 года долг должен быть выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Известно, что сумма всех платежей после полного погашения кредита будет равна 1482,3 тыс. рублей. Сколько рублей составит платёж 2029 года?" << endl << endl << endl; 
        Answer = Answer + "  \\item 482,3 \n";
//23
        cout << "\\item     В июле 2025 года планируется взять кредит на десять лет в размере 800 тыс. рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг будет возрастать на $r$\\% по сравнению с концом предыдущего года ($r$ — целое число);" << endl
            << "    \\item с февраля по июнь каждого года необходимо оплатить одним платежом часть долга;" << endl
            << "    \\item в июле 2026, 2027, 2028, 2029 и 2030 годов долг должен быть на какую-то одну и ту же величину меньше долга на июль предыдущего года;" << endl
            << "    \\item в июле 2030 года долг должен составить 200 тыс. рублей;" << endl
            << "    \\item в июле 2031, 2032, 2033, 2034 и 2035 годов долг должен быть на другую одну и ту же величину меньше долга на июль предыдущего года;" << endl
            << "    \\item к июлю 2035 года долг должен быть выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Известно, что сумма всех платежей после полного погашения кредита будет равна 1480 тыс. рублей. Найдите $r$." << endl << endl << endl; 
        Answer = Answer + "  \\item 20 \n";
//24
        cout << "\\item     В июле 2025 года планируется взять кредит на десять лет в размере 1300 тыс. рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг будет возрастать на 20\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо оплатить одним платежом часть долга;" << endl
            << "    \\item в июле 2026, 2027, 2028, 2029 и 2030 годов долг должен быть на какую-то одну и ту же величину меньше долга на июль предыдущего года;" << endl
            << "    \\item в июле 2031, 2032, 2033, 2034 и 2035 годов долг должен быть на другую одну и ту же величину меньше долга на июль предыдущего года;" << endl
            << "    \\item к июлю 2035 года долг должен быть выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Известно, что сумма всех платежей после полного погашения кредита будет равна 2580 тыс. рублей. Сколько рублей составит долг в июле 2030 года?" << endl << endl << endl; 
        Answer = Answer + "  \\item 160 \n";
//25
        cout << "\\item     В июле 2026 года планируется взять кредит на пять лет в размере 1260 тыс. рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг возрастает на 10\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item в июле 2027, 2028 и 2029 годов долг остаётся равным 1260 тыс. рублей;" << endl
            << "    \\item выплаты в 2030 и 2031 годах равны;" << endl
            << "    \\item к июлю 2031 года долг будет выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Найдите общую сумму платежей за пять лет." << endl << endl << endl; 
        Answer = Answer + "  \\item 1 830 \n";

//26
        cout << "\\item     В июле 2026 года планируется взять кредит на три года в размере 900 тыс. рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг будет возрастать на 20\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item платежи в 2027 и 2028 годах должны быть равными;" << endl
            << "    \\item к июлю 2029 года долг должен быть выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Известно, что платёж в 2029 году составит 1027,2 тыс. рублей. Найдите сумму всех платежей после полного погашения кредита." << endl << endl << endl; 
        Answer = Answer + "  \\item 1 427,2 \n";
//27
        cout << "\\item     В июле 2025 года планируется взять кредит в банке на некоторую сумму. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг увеличивается на 25\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо оплатить одним платежом часть долга." << endl
            << "\\end{itemize}" << endl
            << "Сколько рублей планируется взять в банке, если известно, что кредит будет полностью погашен четырьмя равными платежами (то есть за четыре года) и банку будет выплачено 375 000 рублей?" << endl << endl << endl; 
        Answer = Answer + "  \\item 221 400 \n";
//28
        cout << "\\item     В июле 2020 года планируется взять кредит в банке на некоторую сумму. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг увеличивается на 10\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо оплатить одним платежом часть долга." << endl
            << "\\end{itemize}" << endl
            << "Сколько рублей будет выплачено банку, если известно, что кредит будет полностью погашен тремя равными платежами (то есть за три года) и общая сумма выплат после полного погашения кредита на 34 150 рублей больше суммы, взятой в кредит?" << endl << endl << endl; 
        Answer = Answer + "  \\item 199 650 \n";
//29
        cout << "\\item     В июле 2026 года планируется взять кредит в банке на некоторую сумму. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг увеличивается на 20\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга." << endl
            << "\\end{itemize}" << endl
            << "Сколько рублей планируется взять в банке, если известно, что кредит будет полностью погашен четырьмя равными платежами (то есть за четыре года) и общая сумма платежей составит 311 040 рублей?" << endl << endl << endl; 
        Answer = Answer + "  \\item 201 300 \n";
//30
        cout << "\\item     В июле 2020 года планируется взять кредит в банке на сумму 200 000 рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг увеличивается на $r$\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга." << endl
            << "\\end{itemize}" << endl
            << "Найдите $r$, если известно, что кредит будет полностью погашен за два года, причём в первый год будет выплачено 130 000 рублей, а во второй год — 150 000 рублей." << endl << endl << endl; 
        Answer = Answer + "  \\item 25 \n";
//31
        cout << "\\item     15 декабря планируется взять кредит в банке на сумму 1100 тысяч рублей на 16 месяцев. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item 1-го числа каждого месяца долг будет возрастать на $r$\\% по сравнению с концом предыдущего месяца ($r$ -- целое число);" << endl
            << "    \\item со 2-го по 14-е число каждого месяца необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item 15-го числа каждого месяца с 1-го по 15-й долг должен быть на одну и ту же сумму меньше долга на 15-е число предыдущего месяца;" << endl
            << "    \\item 15-го числа 15-го месяца долг должен быть равен 500 тысяч рублей;" << endl
            << "    \\item к 15-му числу 16-го месяца кредит должен быть полностью погашен." << endl
            << "\\end{itemize}" << endl
            << "Найдите $r$, если известно, что сумма всех платежей после полного погашения кредита будет составлять 1228 тысяч рублей." << endl << endl << endl; 
        Answer = Answer + "  \\item 1 \n";
//32
        cout << "\\item     В июле 2020 года планируется взять кредит в банке на сумму 419 375 рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг увеличивается на 20\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга." << endl
            << "\\end{itemize}" << endl
            << "Сколько рублей будет выплачено банку, если известно, что кредит будет полностью погашен четырьмя равными платежами (то есть за четыре года)?" << endl << endl << endl; 
        Answer = Answer + "  \\item 648 000 \n";
//33
        cout << "\\item     В июле 2025 года планируется взять кредит на десять лет в размере 500 тыс. рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг будет возрастать на 30\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо оплатить одним платежом часть долга;" << endl
            << "    \\item в июле 2026, 2027, 2028, 2029 и 2030 годов долг должен быть на какую-то одну и ту же величину меньше долга на июль предыдущего года," << endl
            << "    \\item в июле 2031, 2032, 2033, 2034 и 2035 годов долг должен быть на другую одну и ту же величину меньше долга на июль предыдущего года;" << endl
            << "    \\item к июлю 2035 года долг должен быть выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Известно, что сумма всех платежей после полного погашения кредита будет равна 1250 тыс. рублей. Сколько рублей составит платёж в 2035 году?" << endl << endl << endl; 
        Answer = Answer + "  \\item 52 \n";
//34
        cout << "\\item     15-го декабря планируется взять кредит в банке на 11 месяцев. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item 1-го числа каждого месяца долг возрастает на 3\\% по сравнению с концом предыдущего месяца;" << endl
            << "    \\item со 2-го по 14-е число каждого месяца необходимо выплатить часть долга;" << endl
            << "    \\item 15-го числа каждого месяца с 1-го по 10-й долг должен быть на 80 тысяч рублей меньше долга на 15-е число предыдущего месяца;" << endl
            << "    \\item к 15-му числу 11-го месяца кредит должен быть полностью погашен." << endl
            << "\\end{itemize}" << endl
            << "Какой долг будет 15-го числа 10-го месяца, если общая сумма выплат после полного погашения кредита составит 1198 тысяч рублей?" << endl << endl << endl; 
        Answer = Answer + "  \\item 280 \n";
//35
        cout << "\\item     В июле 2026 года планируется взять кредит на три года в размере 800 тыс. рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг будет возрастать на 20\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item платежи в 2027 и 2028 годах должны быть равными;" << endl
            << "    \\item к июлю 2029 года долг должен быть выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Известно, что сумма всех платежей после полного погашения кредита будет равна 1254,4 тыс. рублей. Сколько рублей составит платёж 2027 года?" << endl << endl << endl; 
        Answer = Answer + "  \\item 200 \n";
//36
        cout << "\\item     В июле 2026 года планируется взять кредит на пять лет в размере 825 тыс. рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг возрастает на 20\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item в июле 2027, 2028 и 2029 годов долг остаётся равным 825 тыс. рублей;" << endl
            << "    \\item выплаты в 2030 и 2031 годах равны;" << endl
            << "    \\item к июлю 2031 года долг будет выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Найдите общую сумму выплат за пять лет." << endl << endl << endl; 
        Answer = Answer + "  \\item 1 575 \n";
    }
    if(Type == 2)
    {
        type = rand()%36+1;
        switch(type)
        {
            case 1:
                    //1
        cout << "\\item     В июле планируется взять кредит в банке на сумму 7 млн рублей на срок 10 лет. Условия возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг возрастает на $r$\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь необходимо выплатить часть долга так, чтобы на начало июля каждого года долг уменьшался на одну и ту же сумму по сравнению с предыдущим июлем." << endl
            << "\\end{itemize}" << endl
            << "Найдите наименьшую возможную ставку $г$, если известно, что последний платёж будет не менее 0,819 млн рублей." << endl << endl << endl; 
        Answer = "  \\item 17 \n";
        break;
//2
        case 2:
        cout << "\\item     В июле планируется взять кредит в банке на сумму 8 млн рублей на срок 10 лет. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг возрастает на $r$\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь необходимо выплатить часть долга так, чтобы на начало июля каждого года долг уменьшался на одну и ту же сумму по сравнению с предыдущим июлем." << endl
            << "\\end{itemize}" << endl
            << "Найдите наименьшую возможную ставку $г$, если известно, что последний платёж будет не менее 0,92 млн рублей." << endl << endl << endl; 
        Answer = Answer + "  \\item 15 \n";
        break;
//3
        case 3:
        cout << "\\item     15-го декабря планируется взять кредит в банке на сумму 1 000 000 рублей на $(n + 1)$ месяц. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item 1-го числа каждого месяца долг возрастает на $r$\\% по сравнению с концом предыдущего месяца;" << endl
            << "    \\item со 2-го по 14-е число каждого месяца необходимо выплатить часть долга;" << endl
            << "    \\item 15-го числа каждого месяца с 1-го по $n$ -й долг должен быть на 40 тысяч рублей меньше долга на 15-е число предыдущего месяца;" << endl
            << "    \\item 15-го числа $n$ -го месяца долг составит 200 тысяч рублей;" << endl
            << "    \\item к 15-му числу $(n + 1)$ -го месяца кредит должен быть полностью погашен." << endl
            << "\\end{itemize}" << endl
            << "Найдите $r$, если известно, что общая сумма выплат после полного погашения кредита составит 1378 тысяч рублей." << endl << endl << endl; 
        Answer = Answer + "  \\item 3 \n";
        break;
//4 
        case 4:
        cout << "\\item     5-го декабря планируется взять кредит в банке на 11 месяцев. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item 1-го числа каждого месяца долг возрастает на 1\\% по сравнению с концом предыдущего месяца;" << endl
            << "    \\item со 2-го по 14-е число каждого месяца необходимо выплатить часть долга;" << endl
            << "    \\item 15-го числа каждого месяца с 1-го по 10-й долг должен быть на одну и ту же сумму меньше долга на 15-е число предыдущего месяца;" << endl
            << "    \\item 15-го числа 10-го месяца долг составит 300 тысяч рублей;" << endl
            << "    \\item к 15-му числу 11-го месяца кредит должен быть полностью погашен." << endl
            << "\\end{itemize}" << endl
            << "Какую сумму планируется взять в кредит, если общая сумма выплат после полного его погашения составит 1388 тысяч рублей?" << endl << endl << endl; 
        Answer = Answer + "  \\item 1,3 \n";
        break;
//5
        case 5:
        cout << "\\item     В июле 2026 года планируется взять кредит в банке на сумму 177 120 рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг увеличивается на 25\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга." << endl
            << "\\end{itemize}" << endl
            << "Сколько рублей составит общая сумма платежей, если известно, что кредит будет полностью погашен четырьмя равными платежами (то есть за четыре года)?" << endl << endl << endl; 
        Answer = Answer + "  \\item 300 000 \n";
        break;
//6

        case 6:
        cout << "\\item     В июле 2026 года планируется взять кредит в банке на некоторую сумму. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг увеличивается на 20\\% по сравнению с конном предыдуушего года:" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга." << endl
            << "\\end{itemize}" << endl
            << "Сколько рублей будет выплачено банку, если известно, что кредит будет полностью погашен тремя равными платежами (то есть за три года) и общая сумма платежей после полного погашения кредита должна быть на 48 250 рублей больше суммы, взятой в кредит?" << endl << endl << endl; 
        Answer = Answer + "  \\item 162 000 \n";
        break;
//7
        case 7:
        cout << "\\item     В июле планируется взять кредит в банке на сумму 10 млн рублей на некоторый срок (целое число лет). Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг возрастает на 10\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить часть долга;" << endl
            << "    \\item в июле каждого года долг должен быть на одну и ту же сумму меньше долга на июль предыдущего года." << endl
            << "\\end{itemize}" << endl
            << "На сколько лет планируется взять кредит, если известно, что общая сумма выплат после его полного погашения составит 15 млн рублей?" << endl << endl << endl; 
        Answer = Answer + "  \\item 9 \n";
        break;
//8
        case 8:
        cout << "\\item     В июле 2020 года планируется взять кредит в банке на некоторую сумму. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг увеличивается на 10\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга." << endl
            << "\\end{itemize}" << endl
            << "Сколько рублей планируется взять в банке, если известно, что кредит будет полностью погашен четырьмя равными платежами (то есть за четыре года) и банку будет выплачено 292 820 рублей?" << endl << endl << endl;
        Answer = Answer + "  \\item 232 050 \n";
        break;
//9
        case 9:
        cout << "\\item     В июле 2026 года планируется взять кредит на три года в размере 800 тыс. рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг будет возрастать на 10\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item платежи в 2027 и 2028 годах должны быть равными;" << endl
            << "    \\item к июлю 2029 года долг должен быть выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Известно, что платёж в 2029 году составит 833,8 тыс. рублей. Сколько рублей составит платёж 2027 года?" << endl << endl << endl; 
        Answer = Answer + "  \\item 100 \n";
        break;
//10
        case 10:
        cout << "\\item     В июле 2025 года планируется взять кредит на десять лет. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг будет возрастать на 30\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо оплатить одним платежом часть долга;" << endl
            << "    \\item в июле 2026, 2027, 2028, 2029 и 2030 годов долг должен быть на какую-то одну и ту же величину меньше долга на июль предыдущего года," << endl
            << "    \\item в июле 2030 года долг должен составить 500 тыс. рублей;" << endl
            << "    \\item в июле 2031, 2032, 2033, 2034 и 2035 годов долг должен быть на другую одну и ту же величину меньше долга на июль предыдущего года;" << endl
            << "    \\item к июлю 2035 года долг должен быть выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Известно, что сумма всех платежей после полного погашения кредита будет равна 2080 тыс. рублей. Сколько рублей составит платёж в 2026 году?" << endl << endl << endl; 
        Answer = Answer + "  \\item 250 \n";
        break;
//11
        case 11:
        cout << "\\item     15-го декабря планируется взять кредит в банке на 21 месяц. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item 1-го числа каждого месяца долг возрастает на 3\\% по сравнению с концом предыдущего месяца;" << endl
            << "    \\item со 2-го по 14-е число каждого месяца необходимо выплатить часть долга;" << endl
            << "    \\item 15-го числа каждого месяца с 1-го по 20-й долг должен быть на 30 тысяч рублей меньше долга на 15-е число предыдущего месяца;" << endl
            << "    \\item к 15-му числу 21-го месяца кредит должен быть полностью погашен." << endl
            << "\\end{itemize}" << endl
            << "Какую сумму планируется взять в кредит, если общая сумма выплат после полного его погашения составит 1604 тысячи рублей?" << endl << endl << endl; 
        Answer = Answer + "  \\item 1,1 \n";
        break;
//12
        case 12:
        cout << "\\item     15-го декабря планируется взять кредит в банке на сумму 900 тысяч рублей на 11 месяцев. Условия его возврата таковы." << endl
            << "\\begin{itemize}" << endl
            << "    \\item 1-го числа каждого месяца долг возрастает на $r$\\% по сравнению с концом предыдущего месяца;" << endl
            << "    \\item со 2-го по 14-е число каждого месяца необходимо выплатить часть долга;" << endl
            << "    \\item 15-го числа каждого месяца с 1-го по 10-й долг должен быть на одну и ту же сумму меньше долга на 15-е число предыдущего месяца;" << endl
            << "    \\item 15-го числа 10-го месяца долг составит 200 тысяч рублей;" << endl
            << "    \\item к 15-му числу 11-го месяца кредит должен быть полностью погашен." << endl
            << "\\end{itemize}" << endl
            << "Найдите $r$, если известно, что общая сумма выплат после полного погашения кредита составит 1021 тысячу рублей." << endl << endl << endl; 
        Answer = Answer + "  \\item 2 \n";
        break;
//13
        case 13:
        cout << "\\item     В июле планируется взять кредит в банке на сумму 5 млн рублей на некоторый срок (целое число лет). Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг возрастает на 20\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить часть долга;" << endl
            << "    \\item в июле каждого года долг должен быть на одну и ту же сумму меньше долга на июль предыдущего года." << endl
            << "\\end{itemize}" << endl
            << "На сколько лет планируется взять кредит, если известно, что общая сумма выплат после его полного погашения составит 7,5 млн рублей?" << endl << endl << endl; 
        Answer = Answer + "  \\item 4 \n";
        break;
//14
        case 14:
        cout << "\\item     В июле 2026 года планируется взять кредит на три года. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг будет возрастать на 20\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item платежи в 2027 и в 2028 годах должны быть по 500 тыс. рублей;" << endl
            << "    \\item к июлю 2029 года долг должен быть выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Известно, что сумма всех платежей после полного погашения кредита равна 1235,2 тыс. рублей. Какую сумму планируется взять в кредит?" << endl << endl << endl; 
        Answer = Answer + "  \\item 900 \n";
        break;
//15
        case 15:
        cout << "\\item     В июле 2026 года планируется взять кредит на три года. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг будет возрастать на 20\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item платежи в 2027 и в 2028 годах должны быть по 300 тыс. рублей;" << endl
            << "    \\item к июлю 2029 года долг должен быть выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Известно, что платёж в 2029 году будет равен 417,6 тыс. рублей. Какую сумму планируется взять в кредит?" << endl << endl << endl; 
        Answer = Answer + "  \\item 700 \n";
        break;
//16
        case 16:
        cout << "\\item     В июле 2020 года планируется взять кредит в банке на некоторую сумму. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг увеличивается на 10\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга." << endl
            << "\\end{itemize}" << endl
            << "Сколько рублей планируется взять в банке, если известно, что кредит будет полностью погашен тремя равными платежами (то есть за три года) и общая сумма выплат после полного погашения кредита на 40 980 рублей больше суммы, взятой в кредит?" << endl << endl << endl; 
        Answer = Answer + "  \\item 198 600 \n";
        break;
//17
        case 17:
        cout << "\\item     В июле 2025 года планируется взять кредит на десять лет в размере 1400 тыс. рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг будет возрастать на 10\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо оплатить одним платежом часть долга;" << endl
            << "    \\item в июле 2026, 2027, 2028, 2029 и 2030 годов долг должен быть на какую-то одну и ту же величину меньше долга на июль предыдущего года;" << endl
            << "    \\item в июле 2031, 2032, 2033, 2034 и 2035 годов долг должен быть на другую одну и ту же величину меньше долга на июль предыдущего года;" << endl
            << "    \\item к июлю 2035 года долг должен быть выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Известно, что сумма всех платежей после полного погашения кредита будет равна 2120 тыс. рублей. Сколько рублей составит платёж в 2026 году?" << endl << endl << endl; 
        Answer = Answer + "  \\item 300 \n";
        break;
//18
        case 18:
        cout << "\\item     В июле 2026 года планируется взять кредит в банке на пять лет в размере S тыс. рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг возрастает на 30\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item в июле 2027, 2028 и 2029 годов долг остаётся равным S тыс. рублей;" << endl
            << "    \\item выплаты в 2030 и 2031 годах равны по 338 тыс. рублей;" << endl
            << "    \\item к июлю 2031 года долг будет выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Найдите общую сумму выплат за пять лет." << endl << endl << endl; 
        Answer = Answer + "  \\item 1 090 \n";
        break;
//19
        case 19:
        cout << "\\item     В июле 2025 года планируется взять кредит на десять лет. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг будет возрастать на 20\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо оплатить одним платежом часть долга;" << endl
            << "    \\item в июле 2026, 2027, 2028, 2029 и 2030 годов долг должен быть на какую-то одну и ту же величину меньше долга на июль предыдущего года;" << endl
            << "    \\item в июле 2030 года долг должен составить 600 тыс. рублей;" << endl
            << "    \\item в июле 2031, 2032, 2033, 2034 и 2035 годов долг должен быть на другую одну и ту же величину меньше долга на июль предыдущего года;" << endl
            << "    \\item к июлю 2035 года долг должен быть выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Известно, что сумма всех платежей после полного погашения кредита будет равна 2360 тыс. рублей. Какую сумму планируется взять в кредит?" << endl << endl << endl; 
        Answer = Answer + "  \\item 1 100 \n";
        break;
//20
        case 20:
        cout << "\\item     В июле 2026 года планируется взять кредит на пять лет в размере 1050 тыс. рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг возрастает на 10\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item в июле 2027, 2028 и 2029 годов долг остаётся равным 1050 тыс. рублей;" << endl
            << "    \\item выплаты в 2030 и 2031 годах равны;" << endl
            << "    \\item к июлю 2031 года долг будет выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "На сколько рублей последняя выплата будет больше первой?" << endl << endl << endl; 
        Answer = Answer + "  \\item 500 \n";
        break;
//21
        case 21:
        cout << "\\item     15-го декабря планируется взять кредит в банке на сумму 600 тысяч рублей на $(n + 1)$ месяц. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item 1-го числа каждого месяца долг возрастает на 3\\% по сравнению с концом предыдущего месяца;" << endl
            << "    \\item со 2-го по 14-е число каждого месяца необходимо выплатить часть долга;" << endl
            << "    \\item 15-го числа каждого месяца с 1-го по $n$-й долг должен быть на одну и ту же сумму меньше долга на 15-е число предыдущего месяца;" << endl
            << "    \\item 15-го числа $n$-го месяца долг составит 200 тысяч рублей;" << endl
            << "    \\item к 15-му числу $(n + 1)$-го месяца кредит должен быть полностью погашен." << endl
            << "\\end{itemize}" << endl
            << "Найдите $n$, если известно, что общая сумма выплат после полного погашения кредита составит 852 тысячи рублей." << endl << endl << endl; 
        Answer = Answer + "  \\item 20 \n";
        break;
//22
        case 22:
        cout << "\\item     В июле 2026 года планируется взять кредит на три года в размере 900 тыс. рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг будет возрастать на 30\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item платежи в 2027 и 2028 годах должны быть равными;" << endl
            << "    \\item к июлю 2029 года долг должен быть выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Известно, что сумма всех платежей после полного погашения кредита будет равна 1482,3 тыс. рублей. Сколько рублей составит платёж 2029 года?" << endl << endl << endl; 
        Answer = Answer + "  \\item 482,3 \n";
        break;
//23
        case 23:
        cout << "\\item     В июле 2025 года планируется взять кредит на десять лет в размере 800 тыс. рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг будет возрастать на $r$\\% по сравнению с концом предыдущего года ($r$ — целое число);" << endl
            << "    \\item с февраля по июнь каждого года необходимо оплатить одним платежом часть долга;" << endl
            << "    \\item в июле 2026, 2027, 2028, 2029 и 2030 годов долг должен быть на какую-то одну и ту же величину меньше долга на июль предыдущего года;" << endl
            << "    \\item в июле 2030 года долг должен составить 200 тыс. рублей;" << endl
            << "    \\item в июле 2031, 2032, 2033, 2034 и 2035 годов долг должен быть на другую одну и ту же величину меньше долга на июль предыдущего года;" << endl
            << "    \\item к июлю 2035 года долг должен быть выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Известно, что сумма всех платежей после полного погашения кредита будет равна 1480 тыс. рублей. Найдите $r$." << endl << endl << endl; 
        Answer = Answer + "  \\item 20 \n";
        break;
//24
        case 24:
        cout << "\\item     В июле 2025 года планируется взять кредит на десять лет в размере 1300 тыс. рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг будет возрастать на 20\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо оплатить одним платежом часть долга;" << endl
            << "    \\item в июле 2026, 2027, 2028, 2029 и 2030 годов долг должен быть на какую-то одну и ту же величину меньше долга на июль предыдущего года;" << endl
            << "    \\item в июле 2031, 2032, 2033, 2034 и 2035 годов долг должен быть на другую одну и ту же величину меньше долга на июль предыдущего года;" << endl
            << "    \\item к июлю 2035 года долг должен быть выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Известно, что сумма всех платежей после полного погашения кредита будет равна 2580 тыс. рублей. Сколько рублей составит долг в июле 2030 года?" << endl << endl << endl; 
        Answer = Answer + "  \\item 160 \n";
        break;
//25
        case 25:
        cout << "\\item     В июле 2026 года планируется взять кредит на пять лет в размере 1260 тыс. рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг возрастает на 10\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item в июле 2027, 2028 и 2029 годов долг остаётся равным 1260 тыс. рублей;" << endl
            << "    \\item выплаты в 2030 и 2031 годах равны;" << endl
            << "    \\item к июлю 2031 года долг будет выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Найдите общую сумму платежей за пять лет." << endl << endl << endl; 
        Answer = Answer + "  \\item 1 830 \n";
        break;

//26
        case 26:
        cout << "\\item     В июле 2026 года планируется взять кредит на три года в размере 900 тыс. рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг будет возрастать на 20\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item платежи в 2027 и 2028 годах должны быть равными;" << endl
            << "    \\item к июлю 2029 года долг должен быть выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Известно, что платёж в 2029 году составит 1027,2 тыс. рублей. Найдите сумму всех платежей после полного погашения кредита." << endl << endl << endl; 
        Answer = Answer + "  \\item 1 427,2 \n";
        break;
//27
        case 27:
        cout << "\\item     В июле 2025 года планируется взять кредит в банке на некоторую сумму. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг увеличивается на 25\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо оплатить одним платежом часть долга." << endl
            << "\\end{itemize}" << endl
            << "Сколько рублей планируется взять в банке, если известно, что кредит будет полностью погашен четырьмя равными платежами (то есть за четыре года) и банку будет выплачено 375 000 рублей?" << endl << endl << endl; 
        Answer = Answer + "  \\item 221 400 \n";
        break;
//28
        case 28:
        cout << "\\item     В июле 2020 года планируется взять кредит в банке на некоторую сумму. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг увеличивается на 10\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо оплатить одним платежом часть долга." << endl
            << "\\end{itemize}" << endl
            << "Сколько рублей будет выплачено банку, если известно, что кредит будет полностью погашен тремя равными платежами (то есть за три года) и общая сумма выплат после полного погашения кредита на 34 150 рублей больше суммы, взятой в кредит?" << endl << endl << endl; 
        Answer = Answer + "  \\item 199 650 \n";
        break;
//29
        case 29:
        cout << "\\item     В июле 2026 года планируется взять кредит в банке на некоторую сумму. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг увеличивается на 20\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга." << endl
            << "\\end{itemize}" << endl
            << "Сколько рублей планируется взять в банке, если известно, что кредит будет полностью погашен четырьмя равными платежами (то есть за четыре года) и общая сумма платежей составит 311 040 рублей?" << endl << endl << endl; 
        Answer = Answer + "  \\item 201 300 \n";
        break;
//30
        case 30:
        cout << "\\item     В июле 2020 года планируется взять кредит в банке на сумму 200 000 рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг увеличивается на $r$\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга." << endl
            << "\\end{itemize}" << endl
            << "Найдите $r$, если известно, что кредит будет полностью погашен за два года, причём в первый год будет выплачено 130 000 рублей, а во второй год — 150 000 рублей." << endl << endl << endl; 
        Answer = Answer + "  \\item 25 \n";
        break;
//31
        case 31:
        cout << "\\item     15 декабря планируется взять кредит в банке на сумму 1100 тысяч рублей на 16 месяцев. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item 1-го числа каждого месяца долг будет возрастать на $r$\\% по сравнению с концом предыдущего месяца ($r$ -- целое число);" << endl
            << "    \\item со 2-го по 14-е число каждого месяца необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item 15-го числа каждого месяца с 1-го по 15-й долг должен быть на одну и ту же сумму меньше долга на 15-е число предыдущего месяца;" << endl
            << "    \\item 15-го числа 15-го месяца долг должен быть равен 500 тысяч рублей;" << endl
            << "    \\item к 15-му числу 16-го месяца кредит должен быть полностью погашен." << endl
            << "\\end{itemize}" << endl
            << "Найдите $r$, если известно, что сумма всех платежей после полного погашения кредита будет составлять 1228 тысяч рублей." << endl << endl << endl; 
        Answer = Answer + "  \\item 1 \n";
        break;
//32
        case 32:
        cout << "\\item     В июле 2020 года планируется взять кредит в банке на сумму 419 375 рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг увеличивается на 20\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга." << endl
            << "\\end{itemize}" << endl
            << "Сколько рублей будет выплачено банку, если известно, что кредит будет полностью погашен четырьмя равными платежами (то есть за четыре года)?" << endl << endl << endl; 
        Answer = Answer + "  \\item 648 000 \n";
        break;
//33
        case 33:
        cout << "\\item     В июле 2025 года планируется взять кредит на десять лет в размере 500 тыс. рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг будет возрастать на 30\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо оплатить одним платежом часть долга;" << endl
            << "    \\item в июле 2026, 2027, 2028, 2029 и 2030 годов долг должен быть на какую-то одну и ту же величину меньше долга на июль предыдущего года," << endl
            << "    \\item в июле 2031, 2032, 2033, 2034 и 2035 годов долг должен быть на другую одну и ту же величину меньше долга на июль предыдущего года;" << endl
            << "    \\item к июлю 2035 года долг должен быть выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Известно, что сумма всех платежей после полного погашения кредита будет равна 1250 тыс. рублей. Сколько рублей составит платёж в 2035 году?" << endl << endl << endl; 
        Answer = Answer + "  \\item 52 \n";
        break;
//34
        case 34:
        cout << "\\item     15-го декабря планируется взять кредит в банке на 11 месяцев. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item 1-го числа каждого месяца долг возрастает на 3\\% по сравнению с концом предыдущего месяца;" << endl
            << "    \\item со 2-го по 14-е число каждого месяца необходимо выплатить часть долга;" << endl
            << "    \\item 15-го числа каждого месяца с 1-го по 10-й долг должен быть на 80 тысяч рублей меньше долга на 15-е число предыдущего месяца;" << endl
            << "    \\item к 15-му числу 11-го месяца кредит должен быть полностью погашен." << endl
            << "\\end{itemize}" << endl
            << "Какой долг будет 15-го числа 10-го месяца, если общая сумма выплат после полного погашения кредита составит 1198 тысяч рублей?" << endl << endl << endl; 
        Answer = Answer + "  \\item 280 \n";
        break;
//35
        case 35:
        cout << "\\item     В июле 2026 года планируется взять кредит на три года в размере 800 тыс. рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг будет возрастать на 20\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item платежи в 2027 и 2028 годах должны быть равными;" << endl
            << "    \\item к июлю 2029 года долг должен быть выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Известно, что сумма всех платежей после полного погашения кредита будет равна 1254,4 тыс. рублей. Сколько рублей составит платёж 2027 года?" << endl << endl << endl; 
        Answer = Answer + "  \\item 200 \n";
        break;
//36
    case 36:
        cout << "\\item     В июле 2026 года планируется взять кредит на пять лет в размере 825 тыс. рублей. Условия его возврата таковы:" << endl
            << "\\begin{itemize}" << endl
            << "    \\item каждый январь долг возрастает на 20\\% по сравнению с концом предыдущего года;" << endl
            << "    \\item с февраля по июнь каждого года необходимо выплатить одним платежом часть долга;" << endl
            << "    \\item в июле 2027, 2028 и 2029 годов долг остаётся равным 825 тыс. рублей;" << endl
            << "    \\item выплаты в 2030 и 2031 годах равны;" << endl
            << "    \\item к июлю 2031 года долг будет выплачен полностью." << endl
            << "\\end{itemize}" << endl
            << "Найдите общую сумму выплат за пять лет." << endl << endl << endl; 
        Answer = Answer + "  \\item 1 575 \n";
        break;
        }
    }
    return Answer;
}

string StereomPrizm(int Type)
{
    string Answer;
    int type;
    if(Type == 1)
    {
        //1
        cout << "\\item     На ребре $AA_1$, прямоугольного параллелепипеда $ABCDA_1B_1C_1D_1$, взята точка $E$ так, что $A_1E:EA=1:2$, на ребре $BB_1$, -- точка $F$ так, что $B_1F:FB=1:5$, а точка $T$ -- середина ребра $B_1C_1$. Известно, что $AB=2$, $AD=6$, $AA_1=6$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $EFT$ проходит через вершину $D_1$." << endl
            << "    \\item Найдите угол между плоскостью $EFT$ и плоскостью $AA_1B_1$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = "  \\item $\\arccos\\left(\\frac{2}{7}\\right)$ \n";
//2
        cout << "\\item     Сечением прямоугольного параллелепипеда $ABCDA_1B_1C_1D_1$, плоскостью $\\alpha$, содержащей прямую $BD_1$, и параллельной прямой $AC$, является ромб." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что грань $ABCD$ -- квадрат." << endl
            << "    \\item Найдите угол между плоскостями $\\alpha$ и $BCC_1$, если $AA_1=10$, $AB=12$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\arctg(2,6)$ \n";
//3
        cout << "\\item     В основании прямой призмы $ABCDA_1B_1C_1D_1$, лежит параллелограмм $ABCD$ с углом $60^{\\circ}$ при вершине $А$. На рёбрах $A_1B_1$, $B_1C_1$ и $BC$ отмечены точки $M$, $K$ и $N$ соответственно так, что четырёхугольник $AMKN$ -- равнобедренная трапеция с основаниями 1 и 2." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что точка $M$ -- середина ребра $A_1B_1$." << endl
            << "    \\item Найдите высоту призмы, если её объём равен 5 и известно, что точка $K$ делит ребро $B_1C_1$, в отношении $B_1K:KC_1 = 2 : 3$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $2\\sqrt{3}$ \n";
//4
        cout << "\\item     Дана правильная четырёхугольная призма $ABCDA_1B_1C_1D_1$. Плоскость $\\alpha$ проходит через вершины $B_1$ и $D$ и пересекает рёбра $AA_1$ и $CC_1$ в точках $M$ и $K$ соответственно. Известно, что четырёхугольник $MB_1KD$ -- ромб." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что точка $M$ -- середина ребра $AA_1$." << endl
            << "    \\item Найдите высоту призмы $ABCDA_1B_1C_1D_1$, если площадь её основания $ABCD$ равна 3, а площадь ромба $MB_1KD$ равна 6." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $3\\sqrt{2}$ \n";
//5
        cout << "\\item     В основании прямой призмы $ABCDA_1B_1C_1D_1$, лежит равнобедренная трапеция $ABCD$ с основаниями $AD = 3$ и $BC = 2$. Точка $M$ делит ребро $A_1D_1$, в отношении $A_1M:MD_1=1:2$, а точка $K$ -- середина ребра $DD_1$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $MKC$ параллельна прямой $BD$." << endl
            << "    \\item Найдите тангенс угла между плоскостью $MKC$ и плоскостью основания призмы, если $\\angle MKC=90^{\\circ}$, $\\angle ADC=60^{\\circ}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\arctg\\left(\\sqrt{\\frac{7}{3}}\\right)$ \n";
//6
        cout << "\\item     В прямоугольном параллелепипеде $ABCDA_1B_1C_1D_1$, известны длины рёбер: $AB=6\\sqrt{2}$, $AD=10$, $AA_1=16$. На рёбрах $AA_1$ и $BB_1$, отмечены точки $E$ и $F$ соответственно, причём $A_1E:EA=5:3$ и $B_1F:FB=5:11$. Точка $T$ -- середина ребра $B_1C_1$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $EFT$ проходит через точку $D_1$." << endl
            << "    \\item Найдите площадь сечения параллелепипеда плоскостью $EFT$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $97,5$ \n";
//7
        cout << "\\item     В правильной треугольной призме $ABCA_1B_1C_1$, сторона $AB$ основания равна 6, а боковое ребро $AA_1$ равно 4. На рёбрах $AA_1$ и $BB_1$ отмечены точки $M$ и $N$ соответственно, причём $AM=BN=3$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Точки $O$ и $O_1$ -- центры окружностей, описанных около треугольников $ABC$ и $A_1B_1C_1$ соответственно. Докажите, что прямая $OO_1$ содержит точку пересечения медиан треугольника $CMN$." << endl
            << "    \\item Найдите расстояние от точки $C_1$ до плоскости $CMN$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $2\\sqrt{3}$ \n";
//8
        cout << "\\item     В прямоугольном параллелепипеде $ABCDA_1B_1C_1D_1$ через середину $М$ диагонали $AC_1$ проведена плоскость $\\alpha$ перпендикулярно этой диагонали, $AB = 5$, $BC = 3$, $AA_1 = 4$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $\\alpha$ содержит точку $D_1$." << endl
            << "    \\item Найдите отношение, в котором плоскость $\\alpha$ делит ребро $A_1B_1$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{9}{16}$ \n";
//9
        cout << "\\item     В прямоугольном параллелепипеде $ABCDA_1B_1C_1D_1$ известны длины рёбер: $AB = 2\\sqrt{2}$, $AD = 6$, $AA_1 = 10$. На рёбрах $AA_1$ и $BB_1$ отмечены точки $E$ и $F$ соответственно, причём $A_1E:EA=3:2$ и $B_1F:FB=3:7$. Точка $T$ -- середина ребра $B_1C_1$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $EFT$ проходит через точку $D_1$." << endl
            << "    \\item Найдите площадь сечения параллелепипеда плоскостью $EFT$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $22,5$ \n";
//10
        cout << "\\item     В основании прямой призмы $ABCA_1B_1C_1$ лежит равнобедренный треугольник $АВС$ с основанием $AB$. Точка $P$ делит ребро $AB$ в отношении $AP:PB = 1 : 3$, а точка $Q$ -- середина ребра $A_1C_1$. Через середину $M$ ребра $BC$ провели плоскость $\\alpha$, перпендикулярную отрезку $PQ$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $\\alpha$ параллельна ребру $AB$." << endl
            << "    \\item Найдите отношение, в котором плоскость $\\alpha$ делит отрезок $PQ$, считая от точки $P$, если известно, что $AB = AA_1$, $AB : BC = 2 : 5$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{3}{2}$ \n";
//11
        cout << "\\item     В основании прямой призмы $ABCDA_1B_1C_1D_1$ лежит параллелограмм $ABCD$. На рёбрах $A_1B_1$, $B_1C_1$ и $BC$ отмечены точки $M$, $K$ и $N$ соответственно, причём $B_1K : KC_1 = 1 : 2$. Четырёхугольник $AMKN$ -- равнобедренная трапеция с основаниями 2 и 3." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что точка $N$ -- середина ребра $BC$." << endl
            << "    \\item Найдите площадь трапеции $AMKN$, если объём призмы равен 12, а высота призмы равна 2." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{5\\sqrt{37}}{6}$ \n";
//12
        cout << "\\item     В основании прямой призмы $ABCDA_1B_1C_1D_1$ лежит равнобедренная трапеция $ABCD$ с основаниями $AD = 3$ и $BC = 2$. Точка $M$ делит ребро $A_1D_1$ в отношении $A_1M : MD_1 = 1 : 2$, а точка $K$ -- середина ребра $DD_1$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $MKC$ делит отрезок $BB_1$ пополам." << endl
            << "    \\item Найдите площадь сечения призмы плоскостью $MKC$, если $\\angle MKC = 90^{\\circ}$, $\\angle ADC = 60^{\\circ}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{7\\sqrt{10}}{6}$ \n";
//13
        cout << "\\item     Сечением прямоугольного параллелепипеда $ABCDA_1B_1C_1D_1$ плоскостью $\\alpha$, содержащей прямую $BD_1$ и параллельной прямой $AC$, является ромб." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что грань $ABCD$ -- квадрат." << endl
            << "    \\item Найдите угол между плоскостями $\\alpha$ и $BCC_1$, если $AA_1 = 6$, $AB = 4$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\arctg\\left(\\frac{5}{3}\\right)$ \n";
//14
        cout << "\\item     В основании прямой призмы $ABCA_1B_1C_1$ лежит равнобедренный треугольник $АВС$ с основанием $AB$. Точка $P$ делит ребро $AB$ в отношении $AP:PB = 1 : 3$, а точка $Q$ -- середина ребра $A_1C_1$. Через середину $M$ ребра $BC$ провели плоскость $\\alpha$, перпендикулярную отрезку $PQ$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $\\alpha$ делит ребро $AC$ пополам." << endl
            << "    \\item Найдите отношение, в котором плоскость $\\alpha$ делит ребро $A_1C_1$ считая от точки $A_1$, если известно, что $AB = AA_1$, $AB : BC = 2 : 5$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{1}{5}$ \n";

        //15
        cout << "\\item     В основании прямой треугольной призмы $ABCA_1B_1C_1$ лежит равнобедренный ($AB = BC$) треугольник $ABC$. Точка $K$ -- середина ребра $A_1B_1$, а точка $M$ делит ребро $AC$ в отношении $AM : MC = 1 : 3$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $KM\\perp AC$." << endl
            << "    \\item Найдите угол между прямой $KM$ и плоскостью $ABB_1$, если $AB = 6$, $AC = 8$ и $AA_1 = 3$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\arctg\\left(\\sqrt{\\frac{10}{53}}\\right)$ \n";
    }
    if(Type == 2)
    {
        type = rand()%15 + 1;
        switch(type)
        {
            case 1:
            cout << "\\item     На ребре $AA_1$, прямоугольного параллелепипеда $ABCDA_1B_1C_1D_1$, взята точка $E$ так, что $A_1E:EA=1:2$, на ребре $BB_1$, -- точка $F$ так, что $B_1F:FB=1:5$, а точка $T$ -- середина ребра $B_1C_1$. Известно, что $AB=2$, $AD=6$, $AA_1=6$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $EFT$ проходит через вершину $D_1$." << endl
            << "    \\item Найдите угол между плоскостью $EFT$ и плоскостью $AA_1B_1$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = "  \\item $\\arccos\\left(\\frac{2}{7}\\right)$ \n";
            break;

            case 2:
            cout << "\\item     Сечением прямоугольного параллелепипеда $ABCDA_1B_1C_1D_1$, плоскостью $\\alpha$, содержащей прямую $BD_1$, и параллельной прямой $AC$, является ромб." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что грань $ABCD$ -- квадрат." << endl
            << "    \\item Найдите угол между плоскостями $\\alpha$ и $BCC_1$, если $AA_1=10$, $AB=12$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\arctg(2,6)$ \n";
            break;

            case 3:
            cout << "\\item     В основании прямой призмы $ABCDA_1B_1C_1D_1$, лежит параллелограмм $ABCD$ с углом $60^{\\circ}$ при вершине $А$. На рёбрах $A_1B_1$, $B_1C_1$ и $BC$ отмечены точки $M$, $K$ и $N$ соответственно так, что четырёхугольник $AMKN$ -- равнобедренная трапеция с основаниями 1 и 2." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что точка $M$ -- середина ребра $A_1B_1$." << endl
            << "    \\item Найдите высоту призмы, если её объём равен 5 и известно, что точка $K$ делит ребро $B_1C_1$, в отношении $B_1K:KC_1 = 2 : 3$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $2\\sqrt{3}$ \n";
            break;

            case 4:
            cout << "\\item     Дана правильная четырёхугольная призма $ABCDA_1B_1C_1D_1$. Плоскость $\\alpha$ проходит через вершины $B_1$ и $D$ и пересекает рёбра $AA_1$ и $CC_1$ в точках $M$ и $K$ соответственно. Известно, что четырёхугольник $MB_1KD$ -- ромб." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что точка $M$ -- середина ребра $AA_1$." << endl
            << "    \\item Найдите высоту призмы $ABCDA_1B_1C_1D_1$, если площадь её основания $ABCD$ равна 3, а площадь ромба $MB_1KD$ равна 6." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $3\\sqrt{2}$ \n";
            break;

            case 5:
            cout << "\\item     В основании прямой призмы $ABCDA_1B_1C_1D_1$, лежит равнобедренная трапеция $ABCD$ с основаниями $AD = 3$ и $BC = 2$. Точка $M$ делит ребро $A_1D_1$, в отношении $A_1M:MD_1=1:2$, а точка $K$ -- середина ребра $DD_1$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $MKC$ параллельна прямой $BD$." << endl
            << "    \\item Найдите тангенс угла между плоскостью $MKC$ и плоскостью основания призмы, если $\\angle MKC=90^{\\circ}$, $\\angle ADC=60^{\\circ}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\arctg\\left(\\sqrt{\\frac{7}{3}}\\right)$ \n";
            break;

            case 6:
            cout << "\\item     В прямоугольном параллелепипеде $ABCDA_1B_1C_1D_1$, известны длины рёбер: $AB=6\\sqrt{2}$, $AD=10$, $AA_1=16$. На рёбрах $AA_1$ и $BB_1$, отмечены точки $E$ и $F$ соответственно, причём $A_1E:EA=5:3$ и $B_1F:FB=5:11$. Точка $T$ -- середина ребра $B_1C_1$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $EFT$ проходит через точку $D_1$." << endl
            << "    \\item Найдите площадь сечения параллелепипеда плоскостью $EFT$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $97,5$ \n";
            break;

            case 7:
            cout << "\\item     В правильной треугольной призме $ABCA_1B_1C_1$, сторона $AB$ основания равна 6, а боковое ребро $AA_1$ равно 4. На рёбрах $AA_1$ и $BB_1$ отмечены точки $M$ и $N$ соответственно, причём $AM=BN=3$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Точки $O$ и $O_1$ -- центры окружностей, описанных около треугольников $ABC$ и $A_1B_1C_1$ соответственно. Докажите, что прямая $OO_1$ содержит точку пересечения медиан треугольника $CMN$." << endl
            << "    \\item Найдите расстояние от точки $C_1$ до плоскости $CMN$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $2\\sqrt{3}$ \n";
            break;

            case 8:
            cout << "\\item     В прямоугольном параллелепипеде $ABCDA_1B_1C_1D_1$ через середину $М$ диагонали $AC_1$ проведена плоскость $\\alpha$ перпендикулярно этой диагонали, $AB = 5$, $BC = 3$, $AA_1 = 4$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $\\alpha$ содержит точку $D_1$." << endl
            << "    \\item Найдите отношение, в котором плоскость $\\alpha$ делит ребро $A_1B_1$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{9}{16}$ \n";
            break;

            case 9:
            cout << "\\item     В прямоугольном параллелепипеде $ABCDA_1B_1C_1D_1$ известны длины рёбер: $AB = 2\\sqrt{2}$, $AD = 6$, $AA_1 = 10$. На рёбрах $AA_1$ и $BB_1$ отмечены точки $E$ и $F$ соответственно, причём $A_1E:EA=3:2$ и $B_1F:FB=3:7$. Точка $T$ -- середина ребра $B_1C_1$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $EFT$ проходит через точку $D_1$." << endl
            << "    \\item Найдите площадь сечения параллелепипеда плоскостью $EFT$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $22,5$ \n";
            break;

            case 10:
            cout << "\\item     В основании прямой призмы $ABCA_1B_1C_1$ лежит равнобедренный треугольник $АВС$ с основанием $AB$. Точка $P$ делит ребро $AB$ в отношении $AP:PB = 1 : 3$, а точка $Q$ -- середина ребра $A_1C_1$. Через середину $M$ ребра $BC$ провели плоскость $\\alpha$, перпендикулярную отрезку $PQ$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $\\alpha$ параллельна ребру $AB$." << endl
            << "    \\item Найдите отношение, в котором плоскость $\\alpha$ делит отрезок $PQ$, считая от точки $P$, если известно, что $AB = AA_1$, $AB : BC = 2 : 5$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{3}{2}$ \n";
            break;

            case 11:
            cout << "\\item     В основании прямой призмы $ABCDA_1B_1C_1D_1$ лежит параллелограмм $ABCD$. На рёбрах $A_1B_1$, $B_1C_1$ и $BC$ отмечены точки $M$, $K$ и $N$ соответственно, причём $B_1K : KC_1 = 1 : 2$. Четырёхугольник $AMKN$ -- равнобедренная трапеция с основаниями 2 и 3." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что точка $N$ -- середина ребра $BC$." << endl
            << "    \\item Найдите площадь трапеции $AMKN$, если объём призмы равен 12, а высота призмы равна 2." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{5\\sqrt{37}}{6}$ \n";
            break;

            case 12:
            cout << "\\item     В основании прямой призмы $ABCDA_1B_1C_1D_1$ лежит равнобедренная трапеция $ABCD$ с основаниями $AD = 3$ и $BC = 2$. Точка $M$ делит ребро $A_1D_1$ в отношении $A_1M : MD_1 = 1 : 2$, а точка $K$ -- середина ребра $DD_1$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $MKC$ делит отрезок $BB_1$ пополам." << endl
            << "    \\item Найдите площадь сечения призмы плоскостью $MKC$, если $\\angle MKC = 90^{\\circ}$, $\\angle ADC = 60^{\\circ}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{7\\sqrt{10}}{6}$ \n";
            break;

            case 13:
            cout << "\\item     Сечением прямоугольного параллелепипеда $ABCDA_1B_1C_1D_1$ плоскостью $\\alpha$, содержащей прямую $BD_1$ и параллельной прямой $AC$, является ромб." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что грань $ABCD$ -- квадрат." << endl
            << "    \\item Найдите угол между плоскостями $\\alpha$ и $BCC_1$, если $AA_1 = 6$, $AB = 4$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\arctg\\left(\\frac{5}{3}\\right)$ \n";
            break;

            case 14:
            cout << "\\item     В основании прямой призмы $ABCA_1B_1C_1$ лежит равнобедренный треугольник $АВС$ с основанием $AB$. Точка $P$ делит ребро $AB$ в отношении $AP:PB = 1 : 3$, а точка $Q$ -- середина ребра $A_1C_1$. Через середину $M$ ребра $BC$ провели плоскость $\\alpha$, перпендикулярную отрезку $PQ$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $\\alpha$ делит ребро $AC$ пополам." << endl
            << "    \\item Найдите отношение, в котором плоскость $\\alpha$ делит ребро $A_1C_1$ считая от точки $A_1$, если известно, что $AB = AA_1$, $AB : BC = 2 : 5$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{1}{5}$ \n";
            break;

            case 15:
            cout << "\\item     В основании прямой треугольной призмы $ABCA_1B_1C_1$ лежит равнобедренный ($AB = BC$) треугольник $ABC$. Точка $K$ -- середина ребра $A_1B_1$, а точка $M$ делит ребро $AC$ в отношении $AM : MC = 1 : 3$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $KM\\perp AC$." << endl
            << "    \\item Найдите угол между прямой $KM$ и плоскостью $ABB_1$, если $AB = 6$, $AC = 8$ и $AA_1 = 3$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\arctg\\left(\\sqrt{\\frac{10}{53}}\\right)$ \n";
            break;
        }
    }
    return Answer;
}

string StereomPiramid(int Type)
{
    string Answer;
    int type;
    if(Type == 1)
    {
        //1
        cout << "\\item     В основании правильной треугольной пирамиды $ABCD$ лежит треугольник $ABC$ со стороной, равной 5. Боковое ребро пирамиды равно 9. На ребре $AD$ отмечена точка $T$ так, что $AT:TD = 1 : 2$. Через точку $T$ параллельно прямым $AC$ и $BD$ проведена плоскость." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что сечение пирамиды указанной плоскостью является прямоугольником." << endl
            << "    \\item Найдите площадь сечения." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = "  \\item 10 \n";
        //2
        cout << "\\item     В основании пирамиды $SABCD$ лежит прямоугольник $ABCD$ со стороной $AB = 5$ и диагональю $BD = 9$. Все боковые рёбра пирамиды равны 5. На диагонали $BD$ основания $ABCD$ отмечена точка $E$, а на ребре $AS$ -- точка $F$ так, что $SF=BE= 4$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $CEF$ параллельна ребру $SB$." << endl
            << "    \\item Плоскость $CEF$ пересекает ребро $SD$ в точке $Q$. Найдите расстояние от точки $Q$ до плоскости $ABC$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{5\\sqrt{19}}{18}$ \n";

        //3
        cout << "\\item     В правильной четырёхугольной пирамиде $SABCD$ сторона основания $AB$ равна 8, а боковое ребро $SA$ равно 7. На рёбрах $AB$ и $SB$ отмечены точки $M$ и $K$ соответственно, причём $AM = 2$ , $SK =1$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $CKM$ перпендикулярна плоскости $ABC$." << endl
            << "    \\item Найдите объём пирамиды $BCKM$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{48\\sqrt{17}}{7}$ \n";

        //4
        cout << "\\item     В правильной четырёхугольной пирамиде $SABCD$ с основанием $ABCD$ точка $O$ -- центр основания пирамиды, точка $M$ -- середина ребра $SC$, точка $K$ делит ребро $BC$ в отношении $BK : KC = 3 : 1$, а $AB = 2$ и $SO = \\sqrt{14}$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $OMK$ параллельна прямой $SA$." << endl
            << "    \\item Найдите длину отрезка, по которому плоскость $OMK$ пересекает грань $SAD$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 3 \n";

        //5
        cout << "\\item     В основании пирамиды $SABCD$ лежит трапеция $ABCD$ с большим основанием $AD$. Диагонали трапеции пересекаются в точке $O$. Точки $M$ и $N$ -- середины боковых сторон $AB$ и $CD$ соответственно. Плоскость $\\alpha$ проходит через точки $M$ и $N$ параллельно прямой $SO$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что сечение пирамиды $SABCD$ плоскостью $\\alpha$ является трапецией." << endl
            << "    \\item Найдите площадь сечения пирамиды $SABCD$ плоскостью $\\alpha$, если $AD = 10$, $BC = 8$, $SO = 8$, а прямая $SO$ перпендикулярна прямой $AD$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 36 \n";

        //6
        cout << "\\item     В правильной шестиугольной пирамиде $SABCDEF$ сторона основания $AB$ равна 2, а боковое ребро $SA$ равно 8. Точка $M$ -- середина ребра $AB$ . Плоскость $\\alpha$ перпендикулярна плоскости $ABC$ и содержит точки $M$ и $D$. Прямая $SC$ пересекает плоскость $\\alpha$ в точке $K$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $KM=KD$." << endl
            << "    \\item Найдите объём пирамиды $CDKM$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{9\\sqrt{5}}{4}$ \n";

        //7
        cout << "\\item     В правильной шестиугольной пирамиде $SABCDEF$ сторона основания $AB$ равна 5, а боковое ребро $SA$ равно 9. Точка $M$ лежит на ребре $AB$, $AM = 1$, а точка $K$ лежит на ребре $SC$. Известно, что $MK=KD$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $DKM$ перпендикулярна плоскости $ABC$." << endl
            << "    \\item Найдите площадь треугольника $DKM$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{63\\sqrt{26}}{10}$ \n";

        //8
        cout << "\\item     В правильной четырёхугольной пирамиде $SABCD$ сторона основания $AB$ равна 8, а боковое ребро $SA$ равно 7. На рёбрах $AB$ и $SB$ отмечены точки $M$ и $K$ соответственно, причём $AM = 2$, $SK =1$. Плоскость $\\alpha$ и перпендикулярна плоскости $ABC$ и содержит точки $M$ и $K$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $\\alpha$ содержит точку $C$." << endl
            << "    \\item Найдите площадь сечения пирамиды $SABCD$ плоскостью $\\alpha$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{30\\sqrt{17}}{7}$ \n";

        //9
        cout << "\\item     В правильной треугольной пирамиде $SABC$ сторона основания $AB$ равна 6, а боковое ребро $SA$ равно $\\sqrt{21}$. На рёбрах $AB$ и $SB$ отмечены точки $M$ и $K$ соответственно, причём $AM =4$, $SK:KB=1:3$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $CKM$ перпендикулярна плоскости $ABC$." << endl
            << "    \\item Найдите объём пирамиды $BCKM$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{9\\sqrt{3}}{4}$ \n";

        //10
        cout << "\\item     В пирамиде $ABCD$ рёбра $DA$, $DB$ и $DC$ попарно перпендикулярны, а $AB = BC = AC = 6\\sqrt{2}$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что эта пирамида правильная." << endl
            << "    \\item На рёбрах $DA$ и $DC$ отмечены точки $M$ и $N$ соответственно, причём $DM : MA = DN : NC = 1 : 2$. Найдите расстояние от точки $D$ до плоскости $MNB$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{6\\sqrt{19}}{19}$ \n";

        //11
        cout << "\\item     В правильном тетраэдре $ABCD$ точки $M$ и $N$ -- середины рёбер $AB$ и $CD$ соответственно. Плоскость $\\alpha$ перпендикулярна прямой $MN$ и пересекает ребро $BC$ в точке $K$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что прямая $MN$ перпендикулярна рёбрам $AB$ и $CD$." << endl
            << "    \\item Найдите площадь сечения тетраэдра $ABCD$ плоскостью $\\alpha$, если известно, что $BK = 1$, $KC = 3$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 3 \n";

        //12
        cout << "\\item     В правильной четырёхугольной пирамиде $SABCD$ сторона основания $AB$ равна 6, а боковое ребро $SA$ равно 7. На рёбрах $CD$ и $SC$ отмечены точки $N$ и $K$ соответственно, причём $DN : NC = SK : KC = 1 : 2$. Плоскость $\\alpha$ содержит прямую $KN$ и параллельна прямой $BC$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $\\alpha$ параллельна прямой $SA$." << endl
            << "    \\item Найдите угол между плоскостями $\\alpha$ и $SBC$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\arccos\\left(\\frac{11}{20}\\right)$ \n";

        //13
        cout << "\\item     Основанием четырёхугольной пирамиды $SABCD$ является прямоугольник $ABCD$, причём $AB = 2\\sqrt{2}$, $BC = 4$. Основанием высоты пирамиды является центр прямоугольника. Из вершин $A$ и $C$ опущены перпендикуляры $AP$ и $CQ$ на ребро $SB$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $P$ -- середина отрезка $BQ$." << endl
            << "    \\item Найдите угол между гранями $SBA$ и $SBC$, если $SD = 4$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\arccos\\left(-\\frac{1}{\\sqrt{21}}\\right)$ \n";

        //14
        cout << "\\item     Все рёбра правильной четырёхугольной пирамиды $SABCD$ с основанием $ABCD$ равны 4. Точка $O$ -- центр основания пирамиды. Плоскость, параллельная прямой $SA$ и проходящая через точку $O$, пересекает рёбра $SC$ и $SD$ в точках $M$ и $N$ соответственно. Точка $N$ делит ребро $SD$ в отношении $SN : ND = 1 : 3$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что точка $M$ -- середина ребра $SC$." << endl
            << "    \\item Найдите длину отрезка, по которому плоскость $OMN$ пересекает грань $SBC$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\sqrt{3}$ \n";

        //15
        cout << "\\item     В правильной четырёхугольной пирамиде $SABCD$ сторона основания $AB$ равна 4, а боковое ребро $SA$ равно 7. На рёбрах $CD$ и $SC$ отмечены точки $N$ и $K$ соответственно, причём $DN : NC = SK : KC = 1 : 3$. Плоскость $\\alpha$ содержит прямую $KN$ и параллельна прямой $BC$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $\\alpha$ параллельна прямой $SA$." << endl
            << "    \\item Найдите угол между плоскостями $\\alpha$ и $SBC$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\arccos\\left(\\frac{37}{45}\\right)$ \n";

        //16
        cout << "\\item     В пирамиде $ABCD$ рёбра $DA$, $DB$ и $DC$ попарно перпендикулярны, a $AB = BC = AC = 5\\sqrt{2}$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что эта пирамида правильная." << endl
            << "    \\item На рёбрах $DA$ и $DC$ отмечены точки $M$ и $N$ соответственно, причём $DM : MA = DN : NC = 2 : 3$. Найдите площадь сечения $MNB$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $3\\sqrt{6}$ \n";

        //17
        cout << "\\item     Основанием четырёхугольной пирамиды $PABCD$ является трапеция $ABCD$, причём $\\angle BAD + \\angle ADC = 90^{\\circ}$. Плоскости $PAB$ и $PCD$ перпендикулярны плоскости основания, $K$ -- точка пересечения прямых $AB$ и $CD$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскости $PAB$ и $PCD$ перпендикулярны." << endl
            << "    \\item Найдите объём пирамиды $KBCP$, если $AB = BC = CD = 4$, а высота пирамиды $PABCD$ равна 9." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 12 \n";

        //18
        cout << "\\item     Точка $M$ -- середина ребра $SA$ правильной четырёхугольной пирамиды $SABCD$ с основанием $ABCD$. Точка $N$ лежит на ребре $SB$, $SN : NB = 1 : 2$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $CMN$ параллельна прямой $SD$." << endl
            << "    \\item Найдите площадь сечения пирамиды $SABCD$ плоскостью $CMN$, если все рёбра пирамиды равны 6." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{15\\sqrt{19}}{4}$ \n";

        //19
        cout << "\\item     На рёбрах $AB$ и $BC$ треугольной пирамиды $ABCD$ отмечены точки $M$ и $N$ соответственно, причём $AM : MB = CN : NB = 1 : 2$. Точки $P$ и $Q$ -- середины рёбер $DA$ и $DC$ соответственно." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что точки $P$, $Q$, $M$ и $N$ лежат в одной плоскости." << endl
            << "    \\item Найдите отношение объёмов многогранников, на которые плоскость $PQM$ разбивает пирамиду." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{13}{23}$ \n";

        //20
        cout << "\\item     Точка $M$ -- середина бокового ребра $SC$ правильной четырёхугольной пирамиды $SABCD$. Точка $N$ лежит на стороне основания $BC$. Плоскость $\\alpha$ проходит через точки $M$ и $N$ параллельно боковому ребру $SA$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Плоскость $\\alpha$ пересекает боковое ребро $SD$ в точке $L$. Докажите, что $BN : NC = DL : LS$." << endl
            << "    \\item Плоскость $\\alpha$ делит пирамиду $SABCD$ на два многогранника. Найдите отношение их объёмов, если $BN : NC = 1 : 3$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{17}{47}$ \n";

        //21
        cout << "\\item     На ребре $SD$ правильной четырёхугольной пирамиды $SABCD$ с основанием $ABCD$ отмечена точка $M$, причём $SM : MD = 2 : 1$. Точки $P$ и $Q$ -- середины рёбер $BC$ и $AD$ соответственно." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что сечение пирамиды плоскостью $MPQ$ является равнобедренной трапецией." << endl
            << "    \\item Найдите отношение объёмов многогранников, на которые плоскость $MPQ$ разбивает пирамиду." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{2}{7}$ \n";

        //22
        cout << "\\item     В правильной треугольной пирамиде $SABC$ с основанием $ABC$ точки $M$ и $K$ -- середины рёбер $AB$ и $SC$ соответственно, а точки $N$ и $L$ отмечены на рёбрах $SA$ и $BC$ соответственно так, что отрезки $MK$ и $NL$ пересекаются, а $AN = 3NS$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что прямые $MN$, $KL$ и $SB$ пересекаются в одной точке." << endl
            << "    \\item Найдите отношение $BL : LC$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{3}{2}$ \n";

        //23
        cout << "\\item     В правильной треугольной пирамиде $SABC$ с основанием $ABC$ точки $M$ и $K$ -- середины рёбер $AB$ и $SC$ соответственно. На продолжении ребра $SB$ за точку $S$ отмечена точка $R$. Прямые $RM$ и $RK$ пересекают рёбра $AS$ и $BC$ в точках $N$ и $L$ соответственно, причём $BL = 3LC$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что отрезки $MK$ и $NL$ пересекаются." << endl
            << "    \\item Найдите отношение $AN : NS$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{3}{2}$ \n";

        //24
        cout << "\\item     На рёбрах $AC$, $AD$, $BD$ и $BC$ тетраэдра $ABCD$ отмечены точки $K$, $L$, $M$ и $N$ соответственно, причём $AK : KC = 2 : 3$. Четырёхугольник $KLMN$ -- квадрат со стороной 2." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что прямые $AB$ и $CD$ перпендикулярны." << endl
            << "    \\item Найдите расстояние от вершины $B$ до плоскости $KLM$, если объём тетраэдра $ABCD$ равен 25." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{18}{5}$ \n";

        //25
        cout << "\\item     В основании правильной треугольной пирамиды $ABCD$ лежит греугольник $ABC$ со стороной, равной 6. Боковое ребро пирамиды равно 5. На ребре $AD$ отмечена точка $T$ так, что $AT : TD = 2 : 1$. Через точку $T$ параллельно прямым $AC$ и $BD$ проведена плоскость." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что сечение пирамиды указанной плоскостью является прямоугольником." << endl
            << "    \\item Найдите площадь сечения." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{20}{3}$ \n";

        //26
        cout << "\\item     В основании пирамиды $SABCD$ лежит трапеция $ABCD$ с основаниями $AD$ и $BC$, равными 8 и 3 соответственно. Точки $M$ и $N$ лежат на рёбрах $SD$ и $BC$ соответственно, причём $SM : MD = 3 : 2$, $BN : NC = 1 : 2$. Плоскость $AMN$ пересекает ребро $SC$ в точке $K$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $SK : KC = 6 : 1$." << endl
            << "    \\item Плоскость $AMN$ делит пирамиду $SABCD$ на два многогранника. Найдите отношение их объёмов." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{239}{146}$ \n";
    }
    if(Type == 2)
    {
        type = rand()%26 + 1;
        switch(type)
        {
            case 1:
            cout << "\\item     В основании правильной треугольной пирамиды $ABCD$ лежит треугольник $ABC$ со стороной, равной 5. Боковое ребро пирамиды равно 9. На ребре $AD$ отмечена точка $T$ так, что $AT:TD = 1 : 2$. Через точку $T$ параллельно прямым $AC$ и $BD$ проведена плоскость." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что сечение пирамиды указанной плоскостью является прямоугольником." << endl
            << "    \\item Найдите площадь сечения." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
         Answer = "  \\item 10 \n";
            break;

            case 2:
            cout << "\\item     В основании пирамиды $SABCD$ лежит прямоугольник $ABCD$ со стороной $AB = 5$ и диагональю $BD = 9$. Все боковые рёбра пирамиды равны 5. На диагонали $BD$ основания $ABCD$ отмечена точка $E$, а на ребре $AS$ -- точка $F$ так, что $SF=BE= 4$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $CEF$ параллельна ребру $SB$." << endl
            << "    \\item Плоскость $CEF$ пересекает ребро $SD$ в точке $Q$. Найдите расстояние от точки $Q$ до плоскости $ABC$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{5\\sqrt{19}}{18}$ \n";
            break;

            case 3:
            cout << "\\item     В правильной четырёхугольной пирамиде $SABCD$ сторона основания $AB$ равна 8, а боковое ребро $SA$ равно 7. На рёбрах $AB$ и $SB$ отмечены точки $M$ и $K$ соответственно, причём $AM = 2$ , $SK =1$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $CKM$ перпендикулярна плоскости $ABC$." << endl
            << "    \\item Найдите объём пирамиды $BCKM$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{48\\sqrt{17}}{7}$ \n";
            break;

            case 4:
            cout << "\\item     В правильной четырёхугольной пирамиде $SABCD$ с основанием $ABCD$ точка $O$ -- центр основания пирамиды, точка $M$ -- середина ребра $SC$, точка $K$ делит ребро $BC$ в отношении $BK : KC = 3 : 1$, а $AB = 2$ и $SO = \\sqrt{14}$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $OMK$ параллельна прямой $SA$." << endl
            << "    \\item Найдите длину отрезка, по которому плоскость $OMK$ пересекает грань $SAD$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 3 \n";
            break;

            case 5:
            cout << "\\item     В основании пирамиды $SABCD$ лежит трапеция $ABCD$ с большим основанием $AD$. Диагонали трапеции пересекаются в точке $O$. Точки $M$ и $N$ -- середины боковых сторон $AB$ и $CD$ соответственно. Плоскость $\\alpha$ проходит через точки $M$ и $N$ параллельно прямой $SO$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что сечение пирамиды $SABCD$ плоскостью $\\alpha$ является трапецией." << endl
            << "    \\item Найдите площадь сечения пирамиды $SABCD$ плоскостью $\\alpha$, если $AD = 10$, $BC = 8$, $SO = 8$, а прямая $SO$ перпендикулярна прямой $AD$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 36 \n";
            break;

            case 6:
            cout << "\\item     В правильной шестиугольной пирамиде $SABCDEF$ сторона основания $AB$ равна 2, а боковое ребро $SA$ равно 8. Точка $M$ -- середина ребра $AB$ . Плоскость $\\alpha$ перпендикулярна плоскости $ABC$ и содержит точки $M$ и $D$. Прямая $SC$ пересекает плоскость $\\alpha$ в точке $K$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $KM=KD$." << endl
            << "    \\item Найдите объём пирамиды $CDKM$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{9\\sqrt{5}}{4}$ \n";
            break;

            case 7:
            cout << "\\item     В правильной шестиугольной пирамиде $SABCDEF$ сторона основания $AB$ равна 5, а боковое ребро $SA$ равно 9. Точка $M$ лежит на ребре $AB$, $AM = 1$, а точка $K$ лежит на ребре $SC$. Известно, что $MK=KD$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $DKM$ перпендикулярна плоскости $ABC$." << endl
            << "    \\item Найдите площадь треугольника $DKM$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{63\\sqrt{26}}{10}$ \n";
            break;

            case 8:
            cout << "\\item     В правильной четырёхугольной пирамиде $SABCD$ сторона основания $AB$ равна 8, а боковое ребро $SA$ равно 7. На рёбрах $AB$ и $SB$ отмечены точки $M$ и $K$ соответственно, причём $AM = 2$, $SK =1$. Плоскость $\\alpha$ и перпендикулярна плоскости $ABC$ и содержит точки $M$ и $K$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $\\alpha$ содержит точку $C$." << endl
            << "    \\item Найдите площадь сечения пирамиды $SABCD$ плоскостью $\\alpha$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{30\\sqrt{17}}{7}$ \n";
            break;

            case 9:
            cout << "\\item     В правильной треугольной пирамиде $SABC$ сторона основания $AB$ равна 6, а боковое ребро $SA$ равно $\\sqrt{21}$. На рёбрах $AB$ и $SB$ отмечены точки $M$ и $K$ соответственно, причём $AM =4$, $SK:KB=1:3$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $CKM$ перпендикулярна плоскости $ABC$." << endl
            << "    \\item Найдите объём пирамиды $BCKM$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{9\\sqrt{3}}{4}$ \n";
            break;

            case 10:
            cout << "\\item     В пирамиде $ABCD$ рёбра $DA$, $DB$ и $DC$ попарно перпендикулярны, а $AB = BC = AC = 6\\sqrt{2}$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что эта пирамида правильная." << endl
            << "    \\item На рёбрах $DA$ и $DC$ отмечены точки $M$ и $N$ соответственно, причём $DM : MA = DN : NC = 1 : 2$. Найдите расстояние от точки $D$ до плоскости $MNB$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{6\\sqrt{19}}{19}$ \n";
            break;

            case 11:
            cout << "\\item     В правильном тетраэдре $ABCD$ точки $M$ и $N$ -- середины рёбер $AB$ и $CD$ соответственно. Плоскость $\\alpha$ перпендикулярна прямой $MN$ и пересекает ребро $BC$ в точке $K$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что прямая $MN$ перпендикулярна рёбрам $AB$ и $CD$." << endl
            << "    \\item Найдите площадь сечения тетраэдра $ABCD$ плоскостью $\\alpha$, если известно, что $BK = 1$, $KC = 3$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 3 \n";
            break;

            case 12:
            cout << "\\item     В правильной четырёхугольной пирамиде $SABCD$ сторона основания $AB$ равна 6, а боковое ребро $SA$ равно 7. На рёбрах $CD$ и $SC$ отмечены точки $N$ и $K$ соответственно, причём $DN : NC = SK : KC = 1 : 2$. Плоскость $\\alpha$ содержит прямую $KN$ и параллельна прямой $BC$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $\\alpha$ параллельна прямой $SA$." << endl
            << "    \\item Найдите угол между плоскостями $\\alpha$ и $SBC$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\arccos\\left(\\frac{11}{20}\\right)$ \n";
            break;

            case 13:
            cout << "\\item     Основанием четырёхугольной пирамиды $SABCD$ является прямоугольник $ABCD$, причём $AB = 2\\sqrt{2}$, $BC = 4$. Основанием высоты пирамиды является центр прямоугольника. Из вершин $A$ и $C$ опущены перпендикуляры $AP$ и $CQ$ на ребро $SB$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $P$ -- середина отрезка $BQ$." << endl
            << "    \\item Найдите угол между гранями $SBA$ и $SBC$, если $SD = 4$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
       Answer = Answer + "  \\item $\\arccos\\left(-\\frac{1}{\\sqrt{21}}\\right)$ \n";
            break;

            case 14:
            cout << "\\item     Все рёбра правильной четырёхугольной пирамиды $SABCD$ с основанием $ABCD$ равны 4. Точка $O$ -- центр основания пирамиды. Плоскость, параллельная прямой $SA$ и проходящая через точку $O$, пересекает рёбра $SC$ и $SD$ в точках $M$ и $N$ соответственно. Точка $N$ делит ребро $SD$ в отношении $SN : ND = 1 : 3$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что точка $M$ -- середина ребра $SC$." << endl
            << "    \\item Найдите длину отрезка, по которому плоскость $OMN$ пересекает грань $SBC$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\sqrt{3}$ \n";
            break;

            case 15:
            cout << "\\item     В правильной четырёхугольной пирамиде $SABCD$ сторона основания $AB$ равна 4, а боковое ребро $SA$ равно 7. На рёбрах $CD$ и $SC$ отмечены точки $N$ и $K$ соответственно, причём $DN : NC = SK : KC = 1 : 3$. Плоскость $\\alpha$ содержит прямую $KN$ и параллельна прямой $BC$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $\\alpha$ параллельна прямой $SA$." << endl
            << "    \\item Найдите угол между плоскостями $\\alpha$ и $SBC$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\arccos\\left(\\frac{37}{45}\\right)$ \n";
            break;

            case 16:
            cout << "\\item     В пирамиде $ABCD$ рёбра $DA$, $DB$ и $DC$ попарно перпендикулярны, a $AB = BC = AC = 5\\sqrt{2}$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что эта пирамида правильная." << endl
            << "    \\item На рёбрах $DA$ и $DC$ отмечены точки $M$ и $N$ соответственно, причём $DM : MA = DN : NC = 2 : 3$. Найдите площадь сечения $MNB$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $3\\sqrt{6}$ \n";
            break;

            case 17:
            cout << "\\item     Основанием четырёхугольной пирамиды $PABCD$ является трапеция $ABCD$, причём $\\angle BAD + \\angle ADC = 90^{\\circ}$. Плоскости $PAB$ и $PCD$ перпендикулярны плоскости основания, $K$ -- точка пересечения прямых $AB$ и $CD$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскости $PAB$ и $PCD$ перпендикулярны." << endl
            << "    \\item Найдите объём пирамиды $KBCP$, если $AB = BC = CD = 4$, а высота пирамиды $PABCD$ равна 9." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 12 \n";
            break;

            case 18:
            cout << "\\item     Точка $M$ -- середина ребра $SA$ правильной четырёхугольной пирамиды $SABCD$ с основанием $ABCD$. Точка $N$ лежит на ребре $SB$, $SN : NB = 1 : 2$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что плоскость $CMN$ параллельна прямой $SD$." << endl
            << "    \\item Найдите площадь сечения пирамиды $SABCD$ плоскостью $CMN$, если все рёбра пирамиды равны 6." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{15\\sqrt{19}}{4}$ \n";
            break;

            case 19:
            cout << "\\item     На рёбрах $AB$ и $BC$ треугольной пирамиды $ABCD$ отмечены точки $M$ и $N$ соответственно, причём $AM : MB = CN : NB = 1 : 2$. Точки $P$ и $Q$ -- середины рёбер $DA$ и $DC$ соответственно." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что точки $P$, $Q$, $M$ и $N$ лежат в одной плоскости." << endl
            << "    \\item Найдите отношение объёмов многогранников, на которые плоскость $PQM$ разбивает пирамиду." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{13}{23}$ \n";
            break;

            case 20:
            cout << "\\item     Точка $M$ -- середина бокового ребра $SC$ правильной четырёхугольной пирамиды $SABCD$. Точка $N$ лежит на стороне основания $BC$. Плоскость $\\alpha$ проходит через точки $M$ и $N$ параллельно боковому ребру $SA$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Плоскость $\\alpha$ пересекает боковое ребро $SD$ в точке $L$. Докажите, что $BN : NC = DL : LS$." << endl
            << "    \\item Плоскость $\\alpha$ делит пирамиду $SABCD$ на два многогранника. Найдите отношение их объёмов, если $BN : NC = 1 : 3$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{17}{47}$ \n";
            break;

            case 21:
            cout << "\\item     На ребре $SD$ правильной четырёхугольной пирамиды $SABCD$ с основанием $ABCD$ отмечена точка $M$, причём $SM : MD = 2 : 1$. Точки $P$ и $Q$ -- середины рёбер $BC$ и $AD$ соответственно." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что сечение пирамиды плоскостью $MPQ$ является равнобедренной трапецией." << endl
            << "    \\item Найдите отношение объёмов многогранников, на которые плоскость $MPQ$ разбивает пирамиду." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{2}{7}$ \n";
            break;

            case 22:
            cout << "\\item     В правильной треугольной пирамиде $SABC$ с основанием $ABC$ точки $M$ и $K$ -- середины рёбер $AB$ и $SC$ соответственно, а точки $N$ и $L$ отмечены на рёбрах $SA$ и $BC$ соответственно так, что отрезки $MK$ и $NL$ пересекаются, а $AN = 3NS$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что прямые $MN$, $KL$ и $SB$ пересекаются в одной точке." << endl
            << "    \\item Найдите отношение $BL : LC$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{3}{2}$ \n";
            break;

            case 23:
            cout << "\\item     В правильной треугольной пирамиде $SABC$ с основанием $ABC$ точки $M$ и $K$ -- середины рёбер $AB$ и $SC$ соответственно. На продолжении ребра $SB$ за точку $S$ отмечена точка $R$. Прямые $RM$ и $RK$ пересекают рёбра $AS$ и $BC$ в точках $N$ и $L$ соответственно, причём $BL = 3LC$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что отрезки $MK$ и $NL$ пересекаются." << endl
            << "    \\item Найдите отношение $AN : NS$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{3}{2}$ \n";
            break;

            case 24:
            cout << "\\item     На рёбрах $AC$, $AD$, $BD$ и $BC$ тетраэдра $ABCD$ отмечены точки $K$, $L$, $M$ и $N$ соответственно, причём $AK : KC = 2 : 3$. Четырёхугольник $KLMN$ -- квадрат со стороной 2." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что прямые $AB$ и $CD$ перпендикулярны." << endl
            << "    \\item Найдите расстояние от вершины $B$ до плоскости $KLM$, если объём тетраэдра $ABCD$ равен 25." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{18}{5}$ \n";
            break;

            case 25:
            cout << "\\item     В основании правильной треугольной пирамиды $ABCD$ лежит греугольник $ABC$ со стороной, равной 6. Боковое ребро пирамиды равно 5. На ребре $AD$ отмечена точка $T$ так, что $AT : TD = 2 : 1$. Через точку $T$ параллельно прямым $AC$ и $BD$ проведена плоскость." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что сечение пирамиды указанной плоскостью является прямоугольником." << endl
            << "    \\item Найдите площадь сечения." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{20}{3}$ \n";
            break;

            case 26:
            cout << "\\item     В основании пирамиды $SABCD$ лежит трапеция $ABCD$ с основаниями $AD$ и $BC$, равными 8 и 3 соответственно. Точки $M$ и $N$ лежат на рёбрах $SD$ и $BC$ соответственно, причём $SM : MD = 3 : 2$, $BN : NC = 1 : 2$. Плоскость $AMN$ пересекает ребро $SC$ в точке $K$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $SK : KC = 6 : 1$." << endl
            << "    \\item Плоскость $AMN$ делит пирамиду $SABCD$ на два многогранника. Найдите отношение их объёмов." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{239}{146}$ \n";
            break;
        }
    }
    return Answer;
}

string StereomCilindr(int Type)
{
    string Answer;
    int type;
    if(Type == 1)
    {
        //1
        cout << "\\item     В цилиндре образующая перпендикулярна плоскости основания. На окружности одного из оснований цилиндра выбраны точки $A$, $B$ и $C$, а на окружности другого основания -- точка $C_1$, причем $CC_1$ -- образующая цилиндра, а $AC$ -- диаметр основания. Известно, что $\\angle ACB = 45^{\\circ}$, $AB = 2\\sqrt{3}$, $CC_1 = 2\\sqrt{6}$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что угол между прямыми $AC_1$ и $BC$ равен $60^{\\circ}$." << endl
            << "    \\item Найдите расстояние от точки $B$ до прямой $AC_1$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = "  \\item 3 \n";
        //2
        cout << "\\item     Различные точки $A$, $B$ и $C$ лежат на окружности основания конуса с вершиной $S$ так, что отрезок $AB$ является её диаметром. Угол между образующей конуса и плоскостью основания равен $60^{\\circ}$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $\\cos(\\angle ASC)+\\cos(\\angle BSC)=1.5$." << endl
            << "    \\item Найдите объём тетраэдра $SABC$, если $SC = 1$, $\\cos(\\angle ASC) =\\frac{2}{3}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{\\sqrt{6}}{36}$ \n";

        //3
        cout << "\\item     В цилиндре образующая перпендикулярна плоскости основания. На окружности одного из оснований цилиндра выбраны точки $A$ и $B$, а на окружности другого основания -- точки $B_1$ и $C_1$, причём $BB_1$ -- образующая цилиндра, а отрезок $AC_1$ пересекает ось цилиндра." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что угол $ABC_1$ прямой." << endl
            << "    \\item Найдите площадь боковой поверхности цилиндра, если $AB = 20$, $BB_1 = 15$, $B_1C_1 = 21$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 4355 \n";

        //4
        cout << "\\item     В цилиндре образующая перпендикулярна плоскости основания. На окружности одного из оснований цилиндра выбраны точки $A$ и $B$, а на окружности другого основания -- точки $B_1$ и $C_1$, причём $BB_1$ -- образующая цилиндра, а отрезок $AC_1$ пересекает ось цилиндра." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что угол $ABC_1$ прямой." << endl
            << "    \\item Найдите объём цилиндра, если $AB = 7$, $BB_1 = 24$, $B_1C_1 = 10$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $894\\pi$ \n";

        //5
        cout << "\\item     В цилиндре образующая перпендикулярна плоскости основания. На окружности одного из оснований цилиндра выбраны точки $A$, $B$ и $C$, а на окружности другого основания -- точка $C_1$, причём $CC_1$ -- образующая цилиндра, а $AC$ -- диаметр основания. Известно, что $\\angle ACB= 30^{\\circ}$, $AB = \\sqrt{2}$, $CC_1 = 2$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что угол между прямыми $AC_1$ и $BC$ равен $45^{\\circ}$." << endl
            << "    \\item Найдите объём цилиндра." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $4\\pi$ \n";

        //6
        cout << "\\item     В цилиндре образующая перпендикулярна плоскости основания. На окружности одного из оснований цилиндра выбраны точки $A$, $B$ и $C$, а на окружности другого основания -- точка $C_1$, причём $CC_1$ -- образующая цилиндра, а $AC$ -- диаметр основания. Известно, что $\\angle ACB = 30^{\\circ}$, $AB = 1$, $CC_1 = 2\\sqrt{2}$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что угол между прямыми $AC_1$, и $BC$ равен $60^{\\circ}$." << endl
            << "    \\item Найдите площадь боковой поверхности цилиндра." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $4\\sqrt{2}\\pi$ \n";

        //7
        cout << "\\item     В цилиндре образующая перпендикулярна плоскости основания. На окружности одного из оснований цилиндра выбраны точки $A$ и $B$, а на окружности другого основания -- точки $B_1$ и $C_1$ причём $BB_1$ -- образующая цилиндра, а отрезок $AC_1$ пересекает ось цилиндра." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что угол $ABC_1$ прямой." << endl
            << "    \\item Найдите угол между прямыми $BB_1$ и $AC_1$, если $AB = 6$, $BB_1 = 15$, $B_1C_1 = 8$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\arctg\\left(\\frac{2}{3}\\right)$ \n";

        //8
        cout << "\\item     В цилиндре образующая перпендикулярна плоскости основания. На окружности одного из оснований цилиндра выбраны точки $A$ и $B$, а на окружности другого основания -- точки $B_1$ и $C_1$, причём $BB_1$ -- образующая цилиндра, а отрезок $AC$ пересекает ось цилиндра." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что угол $ABC_1$ прямой." << endl
            << "    \\item Найдите расстояние от точки $B$ до прямой $AC_1$, если $AB = 21$, $BB_1 = 12$, $B_1C_1 = 16$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{420}{29}$ \n";
    }
    if(Type == 2)
    {
        type = rand()%8 + 1;
        switch(type)
        {
            case 1:
            cout << "\\item     В цилиндре образующая перпендикулярна плоскости основания. На окружности одного из оснований цилиндра выбраны точки $A$, $B$ и $C$, а на окружности другого основания -- точка $C_1$, причем $CC_1$ -- образующая цилиндра, а $AC$ -- диаметр основания. Известно, что $\\angle ACB = 45^{\\circ}$, $AB = 2\\sqrt{3}$, $CC_1 = 2\\sqrt{6}$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что угол между прямыми $AC_1$ и $BC$ равен $60^{\\circ}$." << endl
            << "    \\item Найдите расстояние от точки $B$ до прямой $AC_1$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = "  \\item 3 \n";
            break;

            case 2:
            cout << "\\item     Различные точки $A$, $B$ и $C$ лежат на окружности основания конуса с вершиной $S$ так, что отрезок $AB$ является её диаметром. Угол между образующей конуса и плоскостью основания равен $60^{\\circ}$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $\\cos(\\angle ASC)+\\cos(\\angle BSC)=1.5$." << endl
            << "    \\item Найдите объём тетраэдра $SABC$, если $SC = 1$, $\\cos(\\angle ASC) =\\frac{2}{3}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{\\sqrt{6}}{36}$ \n";
            break;

            case 3:
            cout << "\\item     В цилиндре образующая перпендикулярна плоскости основания. На окружности одного из оснований цилиндра выбраны точки $A$ и $B$, а на окружности другого основания -- точки $B_1$ и $C_1$, причём $BB_1$ -- образующая цилиндра, а отрезок $AC_1$ пересекает ось цилиндра." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что угол $ABC_1$ прямой." << endl
            << "    \\item Найдите площадь боковой поверхности цилиндра, если $AB = 20$, $BB_1 = 15$, $B_1C_1 = 21$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 4355 \n";
            break;

            case 4:
            cout << "\\item     В цилиндре образующая перпендикулярна плоскости основания. На окружности одного из оснований цилиндра выбраны точки $A$ и $B$, а на окружности другого основания -- точки $B_1$ и $C_1$, причём $BB_1$ -- образующая цилиндра, а отрезок $AC_1$ пересекает ось цилиндра." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что угол $ABC_1$ прямой." << endl
            << "    \\item Найдите объём цилиндра, если $AB = 7$, $BB_1 = 24$, $B_1C_1 = 10$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $894\\pi$ \n";
            break;

            case 5:
            cout << "\\item     В цилиндре образующая перпендикулярна плоскости основания. На окружности одного из оснований цилиндра выбраны точки $A$, $B$ и $C$, а на окружности другого основания -- точка $C_1$, причём $CC_1$ -- образующая цилиндра, а $AC$ -- диаметр основания. Известно, что $\\angle ACB= 30^{\\circ}$, $AB = \\sqrt{2}$, $CC_1 = 2$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что угол между прямыми $AC_1$ и $BC$ равен $45^{\\circ}$." << endl
            << "    \\item Найдите объём цилиндра." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $4\\pi$ \n";
            break;

            case 6:
            cout << "\\item     В цилиндре образующая перпендикулярна плоскости основания. На окружности одного из оснований цилиндра выбраны точки $A$, $B$ и $C$, а на окружности другого основания -- точка $C_1$, причём $CC_1$ -- образующая цилиндра, а $AC$ -- диаметр основания. Известно, что $\\angle ACB = 30^{\\circ}$, $AB = 1$, $CC_1 = 2\\sqrt{2}$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что угол между прямыми $AC_1$, и $BC$ равен $60^{\\circ}$." << endl
            << "    \\item Найдите площадь боковой поверхности цилиндра." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $4\\sqrt{2}\\pi$ \n";
            break;

            case 7:
            cout << "\\item     В цилиндре образующая перпендикулярна плоскости основания. На окружности одного из оснований цилиндра выбраны точки $A$ и $B$, а на окружности другого основания -- точки $B_1$ и $C_1$ причём $BB_1$ -- образующая цилиндра, а отрезок $AC_1$ пересекает ось цилиндра." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что угол $ABC_1$ прямой." << endl
            << "    \\item Найдите угол между прямыми $BB_1$ и $AC_1$, если $AB = 6$, $BB_1 = 15$, $B_1C_1 = 8$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\arctg\\left(\\frac{2}{3}\\right)$ \n";
            break;

            case 8:
            cout << "\\item     В цилиндре образующая перпендикулярна плоскости основания. На окружности одного из оснований цилиндра выбраны точки $A$ и $B$, а на окружности другого основания -- точки $B_1$ и $C_1$, причём $BB_1$ -- образующая цилиндра, а отрезок $AC$ пересекает ось цилиндра." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что угол $ABC_1$ прямой." << endl
            << "    \\item Найдите расстояние от точки $B$ до прямой $AC_1$, если $AB = 21$, $BB_1 = 12$, $B_1C_1 = 16$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{420}{29}$ \n";
            break;
        }
    }
    return Answer;
}

string SecondTreugol(int Type)
{
    string Answer;
    int type;
    if(Type == 1)
    {
        //1
        cout << "\\item     Прямая, проходящая через середину $M$ гипотенузы $AB$ прямоугольного треугольника $ABC$, перпендикулярна $CM$ и пересекает катет $AC$ в точке $K$. При этом $AK : KC = 1 : 2$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $\\angle BAC = 30^{\\circ}$." << endl
            << "    \\item Пусть прямые $MK$ и $BC$ пересекаются в точке $P$, а прямые $AP$ и $BK$ -- в точке $Q$. Найдите $KQ$, если $BC = \\sqrt{21}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = "  \\item 14 \n";

        //2
        cout << "\\item     На сторонах $AB$, $BC$ и $AC$ треугольника $ABC$ отмечены точки $C_1$, $A_1$ и $B_1$ соответственно, причём $AC_1:C_1B=8:3$, $BA_1:A_1C=1:2$, $AB_1:B_1C=1:3$. Отрезки $BB_1$ и $CC_1$ пересекаются в точке $D$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что четырёхугольник $ADA_1B_1$ -- параллелограмм." << endl
            << "    \\item Найдите радиус окружности, описанной около треугольника $ABC$, если отрезки $AD$ и $BC$ перпендикулярны, $AC =16$, $BC= 15$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{27\\sqrt{11}}{11}$ \n";

        //3
        cout << "\\item     В треугольнике $ABC$ точки $A_1$, $B_1$ и $C_1$ -- середины сторон $BC$, $AC$ и $AB$ соответственно, $AH$ -- высота, $\\angle BAC = 60^{\\circ}$, $\\angle BCA= 45^{\\circ}$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что точки $A_1$, $B_1$, $C_1$ и $H$ лежат на одной окружности." << endl
            << "    \\item Найдите $A_1H$, если $BC = 2\\sqrt{3}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 1 \n";

        //4
        cout << "\\item     В треугольнике $ABC$ угол $A$ равен $120^{\\circ}$. Прямые, содержащие высоты $BM$ и $CN$ треугольника $ABC$, пересекаются в точке $H$. Точка $O$ -- центр окружности, описанной около треугольника $ABC$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $AH = AO$." << endl
            << "    \\item Найдите площадь треугольника $AHO$, если $BC = \\sqrt{15}$, $\\angle ABC = 45^{\\circ}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 1,25 \n";

        //5
        cout << "\\item     В треугольнике $ABC$ продолжения высоты $CC_1$ и биссектрисы $BB_1$ пересекают описанную окружность в точках $N$ и $M$ соответственно, $\\angle ABC = 40^{\\circ}$, $\\angle ACB = 85^{\\circ}$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $BM = CN$." << endl
            << "    \\item Прямые $BC$ и $MN$ пересекаются в точке $D$. Найдите площадь треугольника $BDN$, если его высота $BH$ равна 6." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 36 \n";

        //6
        cout << "\\item     На стороне $AC$ равностороннего треугольника $ABC$ отмечена точка $M$. Серединный перпендикуляр к отрезку $BM$ пересекает стороны $AB$ и $BC$ в точках $E$ и $K$ соответственно." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что треугольники $AEM$ и $CMK$ подобны." << endl
            << "    \\item Найдите отношение $AM : MC$, если площади треугольников $AEM$ и $CMK$ равны 4 и 9 соответственно." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 0,25 \n";

        //7
        cout << "\\item     Прямая, проходящая через середину $M$ гипотенузы $AB$ прямоугольного треугольника $ABC$, перпендикулярна $CM$ и пересекает катет $AC$ в точке $K$. При этом $AK : KC = 1 : 2$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $\\angle BAC = 30^{\\circ}$." << endl
            << "    \\item Пусть прямые $MK$ и $BC$ пересекаются в точке $P$, а прямые $AP$ и $BK$ -- в точке $Q$. Найдите $KQ$, если $BC = \\sqrt{21}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 14 \n";

        //8
        cout << "\\item     Высоты $BB_1$ и $CC_1$ остроугольного треугольника $ABC$ пересекаются в точке $H$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $\\angle BB_1C_1 = \\angle BAH$." << endl
            << "    \\item Найдите расстояние от центра окружности, описанной около треугольника $ABC$, до стороны $BC$, если $B_1C_1 = 18$ и $\\angle BAC = 30^{\\circ}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 18 \n";

        //9
        cout << "\\item     В треугольнике $ABC$ точки $M$ и $N$ лежат на сторонах $AB$ и $BC$ соответственно так, что $AM : MB = CN : NB = 2 : 3$. Окружность, вписанная в треугольник $ABC$, касается отрезка $MN$ в точке $L$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $AB + BC = 4AC$." << endl
            << "    \\item Найдите радиус окружности, вписанной в треугольник $ABC$, если $ML = \\frac{9}{5}$, $LN = 3$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 3 \n";

        //10
        cout << "\\item     В треугольнике $ABC$ точки $A_1$, $B_1$ и $C_1$ -- середины сторон $BC$, $AC$ и $AB$ соответственно, $AH$ -- высота, $\\angle BAC = 120^{\\circ}$, $\\angle BCA= 45^{\\circ}$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что точки $A_1$, $B_1$, $C_1$ и $H$ лежат на одной окружности." << endl
            << "    \\item Найдите $A_1H$, если $BC = 6\\sqrt{3}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 3 \n";

        //11
        cout << "\\item     В прямоугольном треугольнике $ABC$ точка $M$ лежит на катете $AC$, а точка $N$ лежит на продолжении катета $BC$ за точку $C$, причём $CM = BC$ и $CN = AC$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Отрезки $CP$ и $CQ$ -- медианы треугольников $ABC$ и $NCM$ соответственно. Докажите, что прямые $CP$ и $CQ$ перпендикулярны." << endl
            << "    \\item Прямые $MN$ и $AB$ пересекаются в точке $K$, а прямые $BM$ и $AN$ -- в точке $L$. Найдите $KL$, если $BC = 1$, а $AC = 5$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{12\\sqrt{13}}{13}$ \n";

        //12
        cout << "\\item     В треугольнике $ABC$ точки $A_1$, $B_1$ и $C_1$ -- середины сторон $BC$, $AC$ и $AB$ соответственно, $AH$ -- высота, $\\angle BAC = 30^{\\circ}$, $\\angle BCA= 45^{\\circ}$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что точки $A_1$, $B_1$, $C_1$ и $H$ лежат на одной окружности." << endl
            << "    \\item Найдите $A_1H$, если $BC = 4\\sqrt{3}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 6 \n";

        //13
        cout << "\\item     В треугольнике $ABC$ точки $A_1$, $B_1$ и $C_1$ -- середины сторон $BC$, $AC$ и $AB$ соответственно, $AH$ -- высота, $\\angle BAC = 120^{\\circ}$, $\\angle BCA= 15^{\\circ}$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что точки $A_1$, $B_1$, $C_1$ и $H$ лежат на одной окружности." << endl
            << "    \\item Найдите $A_1H$, если $BC = 4\\sqrt{3}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 2 \n";

        //14
        cout << "\\item     Периметр треугольника $ABC$ равен 36. Точки $E$ и $F$ -- середины сторон $AB$ и $BC$ соответственно. Отрезок $EF$ касается окружности, вписанной в треугольник $ABC$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $AC = 9$." << endl
            << "    \\item Найдите площадь треугольника $ABC$, если $\\angle ACB = 90^{\\circ}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 54 \n";

        //15
        cout << "\\item     На стороне $AC$ равностороннего треугольника $ABC$ отмечена точка $M$. Серединный перпендикуляр к отрезку $BM$ пересекает стороны $AB$ и $BC$ в точках $E$ и $K$ соответственно." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $\\angle AEM = \\angle CMK$." << endl
            << "    \\item Найдите отношение площадей треугольников $AEM$ и $CMK$, если $AM : MC = 1 : 4$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{9}{4}$ \n";

        //16
        cout << "\\item     В остроугольном треугольнике $ABC$ высоты $AA_1$, $BB_1$ и $CC_1$ пересекаются в точке $H$. Через точку $C_1$ параллельно высоте $BB_1$ проведена прямая, пересекающая высоту $AA_1$ в точке $K$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $AB\\cdot KH = BC \\cdot C_1H$." << endl
            << "    \\item Найдите отношение площадей треугольников $C_1HK$ и $ABC$, если $AB = 6$, $BC = 4$, $AC = 5$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{448}{81}$ \n";

        //17
        cout << "\\item     На сторонах $AB$, $BC$ и $AC$ треугольника $ABC$ отмечены точки $C_1$, $A_1$ и $B_1$ соответственно, причём $AC_1 : C_1B = 21 : 10$, $BA_1 : A_1C = 2: 3$, $AB_1 : B_1C = 2 : 5$. Отрезки $BB_1$ и $CC_1$ пересекаются в точке $D$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что четырёхугольник $ADA_1B_1$ -- параллелограмм." << endl
            << "    \\item Найдите $CD$, если отрезки $AD$ и $BC$ перпендикулярны, $AC = 63$, $BC = 25$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 27 \n";

        //18
        cout << "\\item     В треугольнике $ABC$ угол $A$ равен $120^{\\circ}$. Прямые, содержащие высоты $BM$ и $CN$ треугольника $ABC$, пересекаются в точке $H$. Точка $O$ -- центр окружности, описанной около треугольника $ABC$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $AH = AO$." << endl
            << "    \\item Найдите площадь треугольника $AHO$, если $BC = 3$, $\\angle ABC = 15^{\\circ}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 0,75 \n";
    }
    if(Type == 2)
    {
        type = rand()%18 +1;
        switch(type)
        {
            case 1:
            cout << "\\item     Прямая, проходящая через середину $M$ гипотенузы $AB$ прямоугольного треугольника $ABC$, перпендикулярна $CM$ и пересекает катет $AC$ в точке $K$. При этом $AK : KC = 1 : 2$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $\\angle BAC = 30^{\\circ}$." << endl
            << "    \\item Пусть прямые $MK$ и $BC$ пересекаются в точке $P$, а прямые $AP$ и $BK$ -- в точке $Q$. Найдите $KQ$, если $BC = \\sqrt{21}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = "  \\item 14 \n";
            break;

            case 2:
            cout << "\\item     На сторонах $AB$, $BC$ и $AC$ треугольника $ABC$ отмечены точки $C_1$, $A_1$ и $B_1$ соответственно, причём $AC_1:C_1B=8:3$, $BA_1:A_1C=1:2$, $AB_1:B_1C=1:3$. Отрезки $BB_1$ и $CC_1$ пересекаются в точке $D$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что четырёхугольник $ADA_1B_1$ -- параллелограмм." << endl
            << "    \\item Найдите радиус окружности, описанной около треугольника $ABC$, если отрезки $AD$ и $BC$ перпендикулярны, $AC =16$, $BC= 15$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{27\\sqrt{11}}{11}$ \n";
            break;

            case 3:
            cout << "\\item     В треугольнике $ABC$ точки $A_1$, $B_1$ и $C_1$ -- середины сторон $BC$, $AC$ и $AB$ соответственно, $AH$ -- высота, $\\angle BAC = 60^{\\circ}$, $\\angle BCA= 45^{\\circ}$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что точки $A_1$, $B_1$, $C_1$ и $H$ лежат на одной окружности." << endl
            << "    \\item Найдите $A_1H$, если $BC = 2\\sqrt{3}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 1 \n";
            break;

            case 4:
            cout << "\\item     В треугольнике $ABC$ угол $A$ равен $120^{\\circ}$. Прямые, содержащие высоты $BM$ и $CN$ треугольника $ABC$, пересекаются в точке $H$. Точка $O$ -- центр окружности, описанной около треугольника $ABC$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $AH = AO$." << endl
            << "    \\item Найдите площадь треугольника $AHO$, если $BC = \\sqrt{15}$, $\\angle ABC = 45^{\\circ}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 1,25 \n";
            break;

            case 5:
            cout << "\\item     В треугольнике $ABC$ продолжения высоты $CC_1$ и биссектрисы $BB_1$ пересекают описанную окружность в точках $N$ и $M$ соответственно, $\\angle ABC = 40^{\\circ}$, $\\angle ACB = 85^{\\circ}$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $BM = CN$." << endl
            << "    \\item Прямые $BC$ и $MN$ пересекаются в точке $D$. Найдите площадь треугольника $BDN$, если его высота $BH$ равна 6." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 36 \n";
            break;

            case 6:
            cout << "\\item     На стороне $AC$ равностороннего треугольника $ABC$ отмечена точка $M$. Серединный перпендикуляр к отрезку $BM$ пересекает стороны $AB$ и $BC$ в точках $E$ и $K$ соответственно." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что треугольники $AEM$ и $CMK$ подобны." << endl
            << "    \\item Найдите отношение $AM : MC$, если площади треугольников $AEM$ и $CMK$ равны 4 и 9 соответственно." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 0,25 \n";
            break;

            case 7:
            cout << "\\item     Прямая, проходящая через середину $M$ гипотенузы $AB$ прямоугольного треугольника $ABC$, перпендикулярна $CM$ и пересекает катет $AC$ в точке $K$. При этом $AK : KC = 1 : 2$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $\\angle BAC = 30^{\\circ}$." << endl
            << "    \\item Пусть прямые $MK$ и $BC$ пересекаются в точке $P$, а прямые $AP$ и $BK$ -- в точке $Q$. Найдите $KQ$, если $BC = \\sqrt{21}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 14 \n";
            break;

            case 8:
            cout << "\\item     Высоты $BB_1$ и $CC_1$ остроугольного треугольника $ABC$ пересекаются в точке $H$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $\\angle BB_1C_1 = \\angle BAH$." << endl
            << "    \\item Найдите расстояние от центра окружности, описанной около треугольника $ABC$, до стороны $BC$, если $B_1C_1 = 18$ и $\\angle BAC = 30^{\\circ}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 18 \n";
            break;

            case 9:
            cout << "\\item     В треугольнике $ABC$ точки $M$ и $N$ лежат на сторонах $AB$ и $BC$ соответственно так, что $AM : MB = CN : NB = 2 : 3$. Окружность, вписанная в треугольник $ABC$, касается отрезка $MN$ в точке $L$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $AB + BC = 4AC$." << endl
            << "    \\item Найдите радиус окружности, вписанной в треугольник $ABC$, если $ML = \\frac{9}{5}$, $LN = 3$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 3 \n";
            break;

            case 10:
            cout << "\\item     В треугольнике $ABC$ точки $A_1$, $B_1$ и $C_1$ -- середины сторон $BC$, $AC$ и $AB$ соответственно, $AH$ -- высота, $\\angle BAC = 120^{\\circ}$, $\\angle BCA= 45^{\\circ}$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что точки $A_1$, $B_1$, $C_1$ и $H$ лежат на одной окружности." << endl
            << "    \\item Найдите $A_1H$, если $BC = 6\\sqrt{3}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 3 \n";
            break;

            case 11:
            cout << "\\item     В прямоугольном треугольнике $ABC$ точка $M$ лежит на катете $AC$, а точка $N$ лежит на продолжении катета $BC$ за точку $C$, причём $CM = BC$ и $CN = AC$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Отрезки $CP$ и $CQ$ -- медианы треугольников $ABC$ и $NCM$ соответственно. Докажите, что прямые $CP$ и $CQ$ перпендикулярны." << endl
            << "    \\item Прямые $MN$ и $AB$ пересекаются в точке $K$, а прямые $BM$ и $AN$ -- в точке $L$. Найдите $KL$, если $BC = 1$, а $AC = 5$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{12\\sqrt{13}}{13}$ \n";
            break;

            case 12:
            cout << "\\item     В треугольнике $ABC$ точки $A_1$, $B_1$ и $C_1$ -- середины сторон $BC$, $AC$ и $AB$ соответственно, $AH$ -- высота, $\\angle BAC = 30^{\\circ}$, $\\angle BCA= 45^{\\circ}$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что точки $A_1$, $B_1$, $C_1$ и $H$ лежат на одной окружности." << endl
            << "    \\item Найдите $A_1H$, если $BC = 4\\sqrt{3}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 6 \n";
            break;

            case 13:
            cout << "\\item     В треугольнике $ABC$ точки $A_1$, $B_1$ и $C_1$ -- середины сторон $BC$, $AC$ и $AB$ соответственно, $AH$ -- высота, $\\angle BAC = 120^{\\circ}$, $\\angle BCA= 15^{\\circ}$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что точки $A_1$, $B_1$, $C_1$ и $H$ лежат на одной окружности." << endl
            << "    \\item Найдите $A_1H$, если $BC = 4\\sqrt{3}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 2 \n";
            break;

            case 14:
            cout << "\\item     Периметр треугольника $ABC$ равен 36. Точки $E$ и $F$ -- середины сторон $AB$ и $BC$ соответственно. Отрезок $EF$ касается окружности, вписанной в треугольник $ABC$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $AC = 9$." << endl
            << "    \\item Найдите площадь треугольника $ABC$, если $\\angle ACB = 90^{\\circ}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 54 \n";
            break;

            case 15:
            cout << "\\item     На стороне $AC$ равностороннего треугольника $ABC$ отмечена точка $M$. Серединный перпендикуляр к отрезку $BM$ пересекает стороны $AB$ и $BC$ в точках $E$ и $K$ соответственно." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $\\angle AEM = \\angle CMK$." << endl
            << "    \\item Найдите отношение площадей треугольников $AEM$ и $CMK$, если $AM : MC = 1 : 4$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{9}{4}$ \n";
            break;

            case 16:
            cout << "\\item     В остроугольном треугольнике $ABC$ высоты $AA_1$, $BB_1$ и $CC_1$ пересекаются в точке $H$. Через точку $C_1$ параллельно высоте $BB_1$ проведена прямая, пересекающая высоту $AA_1$ в точке $K$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $AB\\cdot KH = BC \\cdot C_1H$." << endl
            << "    \\item Найдите отношение площадей треугольников $C_1HK$ и $ABC$, если $AB = 6$, $BC = 4$, $AC = 5$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{448}{81}$ \n";
            break;

            case 17:
            cout << "\\item     На сторонах $AB$, $BC$ и $AC$ треугольника $ABC$ отмечены точки $C_1$, $A_1$ и $B_1$ соответственно, причём $AC_1 : C_1B = 21 : 10$, $BA_1 : A_1C = 2: 3$, $AB_1 : B_1C = 2 : 5$. Отрезки $BB_1$ и $CC_1$ пересекаются в точке $D$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что четырёхугольник $ADA_1B_1$ -- параллелограмм." << endl
            << "    \\item Найдите $CD$, если отрезки $AD$ и $BC$ перпендикулярны, $AC = 63$, $BC = 25$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 27 \n";
            break;

            case 18:
            cout << "\\item     В треугольнике $ABC$ угол $A$ равен $120^{\\circ}$. Прямые, содержащие высоты $BM$ и $CN$ треугольника $ABC$, пересекаются в точке $H$. Точка $O$ -- центр окружности, описанной около треугольника $ABC$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $AH = AO$." << endl
            << "    \\item Найдите площадь треугольника $AHO$, если $BC = 3$, $\\angle ABC = 15^{\\circ}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 0,75 \n";
            break;
        }
    }
    return Answer;
}

string SecondChetir(int Type)
{
    string Answer;
    int type;
    if(Type == 1)
    {
        //1
        cout << "\\item     Диагонали равнобедренной трапеции $ABCD$ с основаниями $BC$ и $AD$ перпендикулярны. Окружность с диаметром $AD$ пересекает боковую сторону $CD$ в точке $M$, а окружность с диаметром $CD$ пересекает основание $AD$ в точке $N$. Отрезки $AM$ и $CN$ пересекаются в точке $P$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что в четырёхугольник $ABCP$ можно вписать окружность." << endl
            << "    \\item Найдите радиус этой окружности, если $BC = 7$, $AD = 23$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = "  \\item $\\frac{35}{8}$ \n";
        
        //2
        cout << "\\item     Дана трапеция $ABCD$ с основаниями $AD$ и $BC$. Диагональ $BD$ разбивает её на два равнобедренных треугольника с основаниями $AD$ и $CD$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что луч $AC$ -- биссектриса угла $BAD$." << endl
            << "    \\item Найдите $CD$, если известны диагонали трапеции: $AC = 12$ и $BD = 6,5$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 5 \n";

        //3
        cout << "\\item     Диагонали равнобедренной трапеции $ABCD$ с основаниями $BC$ и $AD$ перпендикулярны. Окружность с диаметром $AD$ пересекает боковую сторону $CD$ в точке $M$, а окружность с диаметром $CD$ пересекает основание $AD$ в точке $N$. Отрезки $AM$ и $CN$ пересекаются в точке $P$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что в четырёхугольник $ABCP$ можно вписать окружность." << endl
            << "    \\item Найдите радиус этой окружности, если $BC = 7$, $AD = 17$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 4,2 \n";

        //4
        cout << "\\item     Точки $P$, $Q$, $W$ делят стороны выпуклого четырёхугольника $ABCD$ в отношении $AP : PB = CQ : QB = CW : WD = 3 : 4$, радиус окружности, описанной около треугольника $PQW$, равен 10, $PQ = 16$, $QW = 12$, угол $PWQ$ -- острый." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что треугольник $PQW$ -- прямоугольный." << endl
            << "    \\item Найдите площадь четырёхугольника $ABCD$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 392 \n";

        //5
        cout << "\\item     Точки $P$, $Q$, $W$ делят стороны выпуклого четырёхугольника $ABCD$ в отношении $AP : PB = CQ : QB = CW : WD = 1 : 4$, радиус окружности, описанной около треугольника $PQW$, равен 10, $PQ = 16$, $QW = 12$, угол $PWQ$ -- острый." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что треугольник $PQW$ -- прямоугольный." << endl
            << "    \\item Найдите площадь четырёхугольника $ABCD$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 600 \n";

        //6
        cout << "\\item     Прямая, проходящая через вершину $B$ прямоугольника $ABCD$ перпендикулярно диагонали $AC$, пересекает сторону $AD$ в точке $M$, равноудалённой от вершин $B$ и $D$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $\\angle ABM = \\angle DBC = 30^{\\circ}$." << endl
            << "    \\item Найдите расстояние от центра прямоугольника до прямой $CM$, если $BC = 9$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{3\\sqrt{21}}{14}$ \n";

        //7
        cout << "\\item     Дана трапеция $ABCD$ с основаниями $AD$ и $BC$. Диагональ $BD$ разбивает её на два равнобедренных треугольника с основаниями $AD$ и $CD$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что луч $AC$ -- биссектриса угла $BAD$." << endl
            << "    \\item Найдите $CD$, если известны диагонали трапеции: $AC = 15$ и $BD = 8,5$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 8 \n";

        //8
        cout << "\\item     В трапеции $ABCD$ основание $AD$ в два раза больше основания $BC$. Внутри трапеции взяли точку $M$ так, что углы $ABM$ и $DCM$ прямые." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $AM = DM$." << endl
            << "    \\item Найдите угол $BAD$, если угол $ADC$ равен $70^{\\circ}$, а расстояние от точки $M$ до прямой $AD$ равно стороне $BC$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 65 \n";

        //9
        cout << "\\item     Биссектрисы углов $BAD$ и $BCD$ равнобедренной трапеции $ABCD$ пересекаются в точке $O$. На боковых сторонах $AB$ и $CD$ отмечены точки $M$ и $N$ соответственно так, что $AM = MO$, $CN = NO$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что точки $M$, $O$ и $N$ лежат на одной прямой." << endl
            << "    \\item Найдите отношение $AM : MB$, если $AO = CO$ и $BC : AD = 17 : 31$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{3}{4}$ \n";

        //10
        cout << "\\item     На стороне $BC$ параллелограмма $ABCD$ выбрана точка $M$ такая, что $AM = MC$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что центр вписанной в треугольник $AMD$ окружности лежит на диагонали $AC$." << endl
            << "    \\item Найдите радиус вписанной в треугольник $AMD$ окружности, если $AB = 5$, $BC = 10$, $\\angle BAD = 60^{\\circ}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{\\sqrt{3}\\left(17-\\sqrt{39}\\right)}{10}$ \n";

        //11
        cout << "\\item     В равнобедренной трапеции $ABCD$ основание $AD$ в три раза больше основания $BC$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что высота $CH$ трапеции разбивает основание $AD$ на отрезки, один из которых вдвое больше другого." << endl
            << "    \\item Найдите расстояние от вершины $C$ до середины диагонали $BD$, если $AD = 15$ и $AC = 2\\sqrt{61}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 6 \n";

        //12
        cout << "\\item     В трапеции $ABCD$ угол $BAD$ прямой. Окружность, построенная на большем основании $AD$ как на диаметре, пересекает меньшее основание $BC$ в точках $C$ и $M$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $\\angle BAM = \\angle CAD$." << endl
            << "    \\item Диагонали трапеции $ABCD$ пересекаются в точке $O$. Найдите площадь треугольника $AOB$, если $AB = \\sqrt{10}$, а $BC = 2BM$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $3\\sqrt{2}$ \n";

        //13
        cout << "\\item     В параллелограмме $ABCD$ угол $BAC$ вдвое больше угла $CAD$. Биссектриса угла $BAC$ пересекает отрезок $BC$ в точке $L$. На продолжении стороны $CD$ за точку $D$ выбрана такая точка $E$, что $AE = CE$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $AL \\cdot BC = AB \\cdot AC$." << endl
            << "    \\item Найдите $EL$, если $AC = 8$, $\\tg(\\angle BCA) = \\frac{1}{2}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{22}{3}$ \n";

        //14
        cout << "\\item     Сумма оснований трапеции равна 10, а её диагонали равны 6 и 8." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что диагонали трапеции перпендикулярны." << endl
            << "    \\item Найдите высоту трапеции." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 4,8 \n";

        //15
        cout << "\\item     Прямая, перпендикулярная стороне $BC$ ромба $ABCD$, пересекает его диагональ $AC$ в точке $M$, а диагональ $BD$ в точке $N$, причём $AM: MC = 1: 2$, $BN : ND = 1 : 3$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $\\cos(\\angle BAD)=\\frac{1}{5}$." << endl
            << "    \\item Найдите площадь ромба, если $MN = 5$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $60\\sqrt{6}$ \n";

        //16
        cout << "\\item     В квадрате $ABCD$ точки $M$ и $N$ -- середины сторон $AB$ и $BC$ соответственно. Отрезки $CM$ и $DN$ пересекаются в точке $K$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $\\angle BKM = 45^{\\circ}$." << endl
            << "    \\item Найдите радиус окружности, описанной около треугольника $ABK$, если сторона $AB = 2\\sqrt{10}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{10}{3}$ \n";

        //17
        cout << "\\item     Прямая, перпендикулярная стороне $BC$ ромба $ABCD$, пересекает его диагональ $AC$ в точке $M$, а диагональ $BD$ в точке $N$, причём $AM : MC = 1: 2$, $BN : ND = 1 : 3$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что прямая $MN$ делит сторону ромба $BC$ в отношении $1 : 4$." << endl
            << "    \\item Найдите сторону ромба, если $MN = \\sqrt{6}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 6 \n";

        //18
        cout << "\\item     Точка $E$ -- середина боковой стороны $CD$ трапеции $ABCD$. На стороне $AB$ взяли точку $K$ так, что прямые $CK$ и $AE$ параллельны. Отрезки $CK$ и $BE$ пересекаются в точке $O$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $CO = KO$." << endl
            << "    \\item Найдите отношение оснований трапеции $BC$ и $AD$, если площадь треугольника $BCK$ составляет $\\frac{9}{100}$ площади трапеции $ABCD$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{3}{7}$ \n";

        //19
        cout << "\\item     В равнобедренной трапеции $ABCD$ основание $AD$ в два раза больше основания $BC$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что высота $CH$ трапеции разбивает основание $AD$ на отрезки, один из которых втрое больше другого." << endl
            << "    \\item Пусть $O$ -- точка пересечения диагоналей трапеции $ABCD$. Найдите расстояние от вершины $C$ до середины отрезка $OD$, если $BC = 16$ и $AB = 10$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 4 \n";

        //20
        cout << "\\item     Биссектрисы углов $BAD$ и $BCD$ равнобедренной трапеции $ABCD$ пересекаются в точке $O$. Через точку $O$ провели прямую, параллельную основаниям $BC$ и $AD$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что отрезок этой прямой внутри трапеции равен её боковой стороне." << endl
            << "    \\item Найдите отношение длин оснований трапеции, если $AO = CO$ и данная прямая делит сторону $AB$ в отношении $AM : MB = 1 : 2$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{1}{7}$ \n";
    }
    if(Type == 2)
    {
        type = rand()%20 + 1;
        switch(type)
        {
            case 1:
            cout << "\\item     Диагонали равнобедренной трапеции $ABCD$ с основаниями $BC$ и $AD$ перпендикулярны. Окружность с диаметром $AD$ пересекает боковую сторону $CD$ в точке $M$, а окружность с диаметром $CD$ пересекает основание $AD$ в точке $N$. Отрезки $AM$ и $CN$ пересекаются в точке $P$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что в четырёхугольник $ABCP$ можно вписать окружность." << endl
            << "    \\item Найдите радиус этой окружности, если $BC = 7$, $AD = 23$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = "  \\item $\\frac{35}{8}$ \n"; 
            break;

            case 2:
            cout << "\\item     Дана трапеция $ABCD$ с основаниями $AD$ и $BC$. Диагональ $BD$ разбивает её на два равнобедренных треугольника с основаниями $AD$ и $CD$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что луч $AC$ -- биссектриса угла $BAD$." << endl
            << "    \\item Найдите $CD$, если известны диагонали трапеции: $AC = 12$ и $BD = 6,5$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 5 \n"; 
            break;

            case 3:
            cout << "\\item     Диагонали равнобедренной трапеции $ABCD$ с основаниями $BC$ и $AD$ перпендикулярны. Окружность с диаметром $AD$ пересекает боковую сторону $CD$ в точке $M$, а окружность с диаметром $CD$ пересекает основание $AD$ в точке $N$. Отрезки $AM$ и $CN$ пересекаются в точке $P$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что в четырёхугольник $ABCP$ можно вписать окружность." << endl
            << "    \\item Найдите радиус этой окружности, если $BC = 7$, $AD = 17$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 4,2 \n";
            break;

            case 4:
            cout << "\\item     Точки $P$, $Q$, $W$ делят стороны выпуклого четырёхугольника $ABCD$ в отношении $AP : PB = CQ : QB = CW : WD = 3 : 4$, радиус окружности, описанной около треугольника $PQW$, равен 10, $PQ = 16$, $QW = 12$, угол $PWQ$ -- острый." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что треугольник $PQW$ -- прямоугольный." << endl
            << "    \\item Найдите площадь четырёхугольника $ABCD$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 392 \n";
            break;

            case 5:
            cout << "\\item     Точки $P$, $Q$, $W$ делят стороны выпуклого четырёхугольника $ABCD$ в отношении $AP : PB = CQ : QB = CW : WD = 1 : 4$, радиус окружности, описанной около треугольника $PQW$, равен 10, $PQ = 16$, $QW = 12$, угол $PWQ$ -- острый." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что треугольник $PQW$ -- прямоугольный." << endl
            << "    \\item Найдите площадь четырёхугольника $ABCD$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 600 \n";
            break;

            case 6:
            cout << "\\item     Прямая, проходящая через вершину $B$ прямоугольника $ABCD$ перпендикулярно диагонали $AC$, пересекает сторону $AD$ в точке $M$, равноудалённой от вершин $B$ и $D$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $\\angle ABM = \\angle DBC = 30^{\\circ}$." << endl
            << "    \\item Найдите расстояние от центра прямоугольника до прямой $CM$, если $BC = 9$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{3\\sqrt{21}}{14}$ \n";
            break;

            case 7:
            cout << "\\item     Дана трапеция $ABCD$ с основаниями $AD$ и $BC$. Диагональ $BD$ разбивает её на два равнобедренных треугольника с основаниями $AD$ и $CD$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что луч $AC$ -- биссектриса угла $BAD$." << endl
            << "    \\item Найдите $CD$, если известны диагонали трапеции: $AC = 15$ и $BD = 8,5$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 8 \n";
            break;

            case 8:
            cout << "\\item     В трапеции $ABCD$ основание $AD$ в два раза больше основания $BC$. Внутри трапеции взяли точку $M$ так, что углы $ABM$ и $DCM$ прямые." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $AM = DM$." << endl
            << "    \\item Найдите угол $BAD$, если угол $ADC$ равен $70^{\\circ}$, а расстояние от точки $M$ до прямой $AD$ равно стороне $BC$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 65 \n";
            break;

            case 9:
            cout << "\\item     Биссектрисы углов $BAD$ и $BCD$ равнобедренной трапеции $ABCD$ пересекаются в точке $O$. На боковых сторонах $AB$ и $CD$ отмечены точки $M$ и $N$ соответственно так, что $AM = MO$, $CN = NO$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что точки $M$, $O$ и $N$ лежат на одной прямой." << endl
            << "    \\item Найдите отношение $AM : MB$, если $AO = CO$ и $BC : AD = 17 : 31$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{3}{4}$ \n";
            break;

            case 10:
            cout << "\\item     На стороне $BC$ параллелограмма $ABCD$ выбрана точка $M$ такая, что $AM = MC$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что центр вписанной в треугольник $AMD$ окружности лежит на диагонали $AC$." << endl
            << "    \\item Найдите радиус вписанной в треугольник $AMD$ окружности, если $AB = 5$, $BC = 10$, $\\angle BAD = 60^{\\circ}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{\\sqrt{3}\\left(17-\\sqrt{39}\\right)}{10}$ \n";
            break;

            case 11:
            cout << "\\item     В равнобедренной трапеции $ABCD$ основание $AD$ в три раза больше основания $BC$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что высота $CH$ трапеции разбивает основание $AD$ на отрезки, один из которых вдвое больше другого." << endl
            << "    \\item Найдите расстояние от вершины $C$ до середины диагонали $BD$, если $AD = 15$ и $AC = 2\\sqrt{61}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 6 \n";
            break;

            case 12:
            cout << "\\item     В трапеции $ABCD$ угол $BAD$ прямой. Окружность, построенная на большем основании $AD$ как на диаметре, пересекает меньшее основание $BC$ в точках $C$ и $M$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $\\angle BAM = \\angle CAD$." << endl
            << "    \\item Диагонали трапеции $ABCD$ пересекаются в точке $O$. Найдите площадь треугольника $AOB$, если $AB = \\sqrt{10}$, а $BC = 2BM$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $3\\sqrt{2}$ \n";
            break;

            case 13:
            cout << "\\item     В параллелограмме $ABCD$ угол $BAC$ вдвое больше угла $CAD$. Биссектриса угла $BAC$ пересекает отрезок $BC$ в точке $L$. На продолжении стороны $CD$ за точку $D$ выбрана такая точка $E$, что $AE = CE$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $AL \\cdot BC = AB \\cdot AC$." << endl
            << "    \\item Найдите $EL$, если $AC = 8$, $\\tg(\\angle BCA) = \\frac{1}{2}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{22}{3}$ \n";
            break;

            case 14:
            cout << "\\item     Сумма оснований трапеции равна 10, а её диагонали равны 6 и 8." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что диагонали трапеции перпендикулярны." << endl
            << "    \\item Найдите высоту трапеции." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 4,8 \n";
            break;

            case 15:
            cout << "\\item     Прямая, перпендикулярная стороне $BC$ ромба $ABCD$, пересекает его диагональ $AC$ в точке $M$, а диагональ $BD$ в точке $N$, причём $AM: MC = 1: 2$, $BN : ND = 1 : 3$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $\\cos(\\angle BAD)=\\frac{1}{5}$." << endl
            << "    \\item Найдите площадь ромба, если $MN = 5$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $60\\sqrt{6}$ \n";
            break;

            case 16:
            cout << "\\item     В квадрате $ABCD$ точки $M$ и $N$ -- середины сторон $AB$ и $BC$ соответственно. Отрезки $CM$ и $DN$ пересекаются в точке $K$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $\\angle BKM = 45^{\\circ}$." << endl
            << "    \\item Найдите радиус окружности, описанной около треугольника $ABK$, если сторона $AB = 2\\sqrt{10}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{10}{3}$ \n";
            break;

            case 17:
            cout << "\\item     Прямая, перпендикулярная стороне $BC$ ромба $ABCD$, пересекает его диагональ $AC$ в точке $M$, а диагональ $BD$ в точке $N$, причём $AM : MC = 1: 2$, $BN : ND = 1 : 3$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что прямая $MN$ делит сторону ромба $BC$ в отношении $1 : 4$." << endl
            << "    \\item Найдите сторону ромба, если $MN = \\sqrt{6}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 6 \n";
            break;

            case 18:
            cout << "\\item     Точка $E$ -- середина боковой стороны $CD$ трапеции $ABCD$. На стороне $AB$ взяли точку $K$ так, что прямые $CK$ и $AE$ параллельны. Отрезки $CK$ и $BE$ пересекаются в точке $O$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $CO = KO$." << endl
            << "    \\item Найдите отношение оснований трапеции $BC$ и $AD$, если площадь треугольника $BCK$ составляет $\\frac{9}{100}$ площади трапеции $ABCD$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{3}{7}$ \n";
            break;

            case 19:
            cout << "\\item     В равнобедренной трапеции $ABCD$ основание $AD$ в два раза больше основания $BC$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что высота $CH$ трапеции разбивает основание $AD$ на отрезки, один из которых втрое больше другого." << endl
            << "    \\item Пусть $O$ -- точка пересечения диагоналей трапеции $ABCD$. Найдите расстояние от вершины $C$ до середины отрезка $OD$, если $BC = 16$ и $AB = 10$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 4 \n";
            break;

            case 20:
            cout << "\\item     Биссектрисы углов $BAD$ и $BCD$ равнобедренной трапеции $ABCD$ пересекаются в точке $O$. Через точку $O$ провели прямую, параллельную основаниям $BC$ и $AD$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что отрезок этой прямой внутри трапеции равен её боковой стороне." << endl
            << "    \\item Найдите отношение длин оснований трапеции, если $AO = CO$ и данная прямая делит сторону $AB$ в отношении $AM : MB = 1 : 2$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{1}{7}$ \n";
            break;
        }
    }
    return Answer;
}

string SecondOkrug(int Type)
{
    string Answer;
    int type;
    if(Type == 1)
    {
        //1
        cout << "\\item     Окружность проходит через вершины $B$ и $C$ треугольника $ABC$ и пересекает $AB$ и $AC$ в точках $C_1$ и $B_1$ соответственно." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что треугольник $ABC$ подобен треугольнику $AB_1C_1$." << endl
            << "    \\item Вычислите длину стороны $BC$ и радиус данной окружности, если $\\angle A= 30^{\\circ}$, $B_1C_1= 5$ и площадь треугольника $AB_1C_1$ в пять раз меньше площади четырёхугольника $BCB_1C_1$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = "  \\item $\\frac{5}{2}\\sqrt{27\\sqrt{2}+30}$ \n";
        
        //2
        cout << "\\item     Окружность проходит через вершины $B$ и $C$ треугольника $ABC$ и пересекает $AB$ и $AC$ в точках $C_1$ и $B_1$ соответственно." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что треугольник $ABC$ подобен треугольнику $AB_1C_1$." << endl
            << "    \\item Вычислите длину стороны $BC$ и радиус данной окружности, если $\\angle A= 45^{\\circ}$, $B_1C_1= 6$ и площадь треугольника $AB_1C_1$ в восемь раз меньше площади четырёхугольника $BCB_1C_1$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $3\\sqrt{20-6\\sqrt{2}}$ \n";

        //3
        cout << "\\item     Окружность проходит через вершины $B$ и $C$ треугольника $ABC$ и пересекает $AB$ и $AC$ в точках $C_1$ и $B_1$ соответственно." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что треугольник $ABC$ подобен треугольнику $AB_1C_1$." << endl
            << "    \\item Вычислите длину стороны $BC$ и радиус данной окружности, если $\\angle A= 135^{\\circ}$, $B_1C_1= 10$ и площадь треугольника $AB_1C_1$ в семь раз меньше площади четырёхугольника $BCB_1C_1$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $5\\sqrt{26}$ \n";

        //4
        cout << "\\item     Окружность проходит через вершины $B$ и $C$ треугольника $ABC$ и пересекает $AB$ и $AC$ в точках $C_1$ и $B_1$ соответственно." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что треугольник $ABC$ подобен треугольнику $AB_1C_1$." << endl
            << "    \\item Вычислите длину стороны $B_1C_1$ и радиус данной окружности, если $\\angle A= 150^{\\circ}$, $BC= 5\\sqrt{5}$ и площадь треугольника $AB_1C_1$ в четыре раза меньше площади четырёхугольника $BCB_1C_1$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $5\\sqrt{6+\\sqrt{15}}$ \n";

        //5
        cout << "\\item     Окружность проходит через вершины $B$ и $C$ треугольника $ABC$ и пересекает $AB$ и $AC$ в точках $C_1$ и $B_1$ соответственно." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что треугольник $ABC$ подобен треугольнику $AB_1C_1$." << endl
            << "    \\item Вычислите длину стороны $B_1C_1$ и радиус данной окружности, если $\\angle A= 120^{\\circ}$, $BC= 10\\sqrt{7}$ и площадь треугольника $AB_1C_1$ в три раза меньше площади четырёхугольника $BCB_1C_1$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{35\\sqrt{3}}{3}$ \n";
        //6
        cout << "\\item     Четырёхугольник $ABCD$ вписан в окружность радиуса $R = 8$. Известно, что $AB = BC = CD = 12$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что прямые $BC$ и $AD$ параллельны." << endl
            << "    \\item Найдите $AD$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 9 \n";

        //7
        cout << "\\item     Окружность проходит через вершины $A$, $B$ и $C$ параллелограмма $ABCD$, пересекает продолжение стороны $AD$ за точку $D$ в точке $E$ и пересекает продолжение стороны $CD$ за точку $D$ в точке $K$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $BK = BE$." << endl
            << "    \\item Найдите отношение $KE : AC$, если $\\angle BAD = 30^{\\circ}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\sqrt{3}$ \n";

        //8
        cout << "\\item     Окружность с центром в точке $O$ касается сторон угла с вершиной $N$ в точках $A$ и $B$. Отрезок $BC$ -- диаметр этой окружности." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что прямая $AC$ параллельна биссектрисе угла $ANB$." << endl
            << "    \\item Найдите длину отрезка $NO$, если известно, что $AC = 10$ и $AB = 24$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 33,8 \n";

        //9
        cout << "\\item     Окружность с центром в точке $O$ высекает на всех сторонах трапеции $ABCD$ равные хорды." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что биссектрисы всех углов трапеции пересекаются в одной точке." << endl
            << "    \\item Найдите высоту трапеции, если окружность пересекает боковую сторону $AB$ в точках $K$ и $L$ так, что $AK = 15$, $KL = 6$, $LB = 5$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 24 \n";

        //10
        cout << "\\item     Пятиугольник $ABCDE$ вписан в окружность. Диагонали $AD$ и $BE$ пересекаются в точке $M$. Известно, что $BCDM$ -- параллелограмм." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $BC = DE$." << endl
            << "    \\item Найдите длину стороны $AB$, если известно, что $DE = 4$, $AD = 7$, $BE = 8$ и $AB > BC$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 6 \n";

        //11
        cout << "\\item     Окружность проходит через вершины $A$, $B$ и $D$ параллелограмма $ABCD$, пересекает сторону $BC$ в точках $B$ и $E$ и пересекает продолжение стороны $CD$ за точку $D$ в точке $K$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $AE = AK$." << endl
            << "    \\item Найдите отношение $KE : BD$, если $\\angle BAD = 60^{\\circ}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 1 \n";

        //12
        cout << "\\item     Окружность проходит через вершины $A$, $B$ и $D$ параллелограмма $ABCD$, пересекает сторону $BC$ в точках $B$ и $E$ и пересекает продолжение стороны $CD$ за точку $D$ в точке $K$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $AE = AK$." << endl
            << "    \\item Найдите $AD$, если $CE = 10$, $DK = 9$ и $\\cos(\\angle BAD) = 0,2$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 85 \n";

        //13
        cout << "\\item     Пятиугольник $ABCDE$ вписан в окружность. Известно, что $AB = CD = 3$, $BC = DE = 4$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $AC = CE$." << endl
            << "    \\item Найдите длину диагонали $BE$, если $AD = 6$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{17}{3}$ \n";

        //14
        cout << "\\item     Две окружности касаются внутренним образом в точке $C$. Вершины $A$ и $B$ равнобедренного прямоугольного треугольника $ABC$ с прямым углом $C$ лежат на меньшей и большей окружностях соответственно. Прямая $AC$ вторично пересекает бльшую окружность в точке $E$, а прямая $BC$ вторично пересекает меньшую окружность в точке $D$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что прямые $AD$ и $BE$ параллельны." << endl
            << "    \\item Найдите $AC$, если радиусы окружностей равны 3 и 4." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 4,8 \n";

        //15
        cout << "\\item     Окружность с центром в точке $O$ касается сторон угла с вершиной $N$ в точках $A$ и $B$. Отрезок $BC$ -- диаметр этой окружности." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $\\angle ANB = 2\\angle ABC$." << endl
            << "    \\item Найдите расстояние от точки $N$ до прямой $AB$, если известно, что $AC = 14$ и $AB = 36$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{324}{7}$ \n";

        //16
        cout << "\\item     Две окружности касаются внутренним образом в точке $A$, причём меньшая проходит через центр большей. Хорда $BC$ большей окружности касается меньшей в точке $P$. Хорды $AB$ и $AC$ пересекают меньшую окружность в точках $K$ и $M$ соответственно." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что прямые $KM$ и $BC$ параллельны." << endl
            << "    \\item Пусть $L$ -- точка пересечения отрезков $KM$ и $AP$. Найдите длину отрезка $AL$, если радиус большей окружности равен 34, а $BC = 32$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\sqrt{34}$ \n";

        //17
        cout << "\\item     Две окружности разных радиусов касаются внешним образом в точке $C$. Вершины $A$ и $B$ равнобедренного прямоугольного треугольника $ABC$ с прямым углом $C$ лежат на меньшей и большей окружностях соответственно. Прямая $AC$ вторично пересекает большую окружность в точке $E$, а прямая $BC$ вторично пересекает меньшую окружность в точке $D$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что прямые $AD$ и $BE$ параллельны." << endl
            << "    \\item Найдите $BC$, если радиусы окружностей равны $\\sqrt{15}$ и $15$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 7,5 \n";

        //18
        cout << "\\item     Окружность с центром $O_1$ касается оснований $BC$ и $AD$ и боковой стороны $AB$ трапеции $ABCD$. Окружность с центром $O_2$ касается сторон $BC$, $CD$ и $AD$. Известно, что $AB = 10$, $BC = 9$, $CD = 30$, $AD = 39$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что прямая $O_1O_2$ параллельна основаниям трапеции $ABCD$." << endl
            << "    \\item Найдите $O_1O_2$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 4 \n";

        //19
        cout << "\\item     Окружность проходит через вершины $A$, $B$ и $D$ параллелограмма $ABCD$, пересекает сторону $BC$ в точках $B$ и $M$ и пересекает продолжение стороны $CD$ за точку $D$ в точке $N$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $AM = AN$." << endl
            << "    \\item Найдие отношение $CD : DN$, если $AB : BC = 1 : 2$, a $\\cos(\\angle BAD) = 3$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{3}{5}$ \n";

        //20
        cout << "\\item     Окружность, вписанная в равнобедренную трапецию $ABCD$ , касается её боковой стороны $CD$ в точке $M$ . Луч $AM$ вторично пересекает окружность в точке $N$, а прямую $BC$ -- в точке $K$, причём $AN = 4$, $MN = 12$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $\\angle AMD = \\angle MCK$." << endl
            << "    \\item Найдите основания трапеции." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 9,6; 16 \n";
    }
    if(Type == 2)
    {
        type = rand()%20 + 1;
        switch(type)
        {
            case 1:
            cout << "\\item     Окружность проходит через вершины $B$ и $C$ треугольника $ABC$ и пересекает $AB$ и $AC$ в точках $C_1$ и $B_1$ соответственно." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что треугольник $ABC$ подобен треугольнику $AB_1C_1$." << endl
            << "    \\item Вычислите длину стороны $BC$ и радиус данной окружности, если $\\angle A= 30^{\\circ}$, $B_1C_1= 5$ и площадь треугольника $AB_1C_1$ в пять раз меньше площади четырёхугольника $BCB_1C_1$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = "  \\item $\\frac{5}{2}\\sqrt{27\\sqrt{2}+30}$ \n";
            break;

            case 2:
            cout << "\\item     Окружность проходит через вершины $B$ и $C$ треугольника $ABC$ и пересекает $AB$ и $AC$ в точках $C_1$ и $B_1$ соответственно." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что треугольник $ABC$ подобен треугольнику $AB_1C_1$." << endl
            << "    \\item Вычислите длину стороны $BC$ и радиус данной окружности, если $\\angle A= 45^{\\circ}$, $B_1C_1= 6$ и площадь треугольника $AB_1C_1$ в восемь раз меньше площади четырёхугольника $BCB_1C_1$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $3\\sqrt{20-6\\sqrt{2}}$ \n";
            break;

            case 3:
            cout << "\\item     Окружность проходит через вершины $B$ и $C$ треугольника $ABC$ и пересекает $AB$ и $AC$ в точках $C_1$ и $B_1$ соответственно." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что треугольник $ABC$ подобен треугольнику $AB_1C_1$." << endl
            << "    \\item Вычислите длину стороны $BC$ и радиус данной окружности, если $\\angle A= 135^{\\circ}$, $B_1C_1= 10$ и площадь треугольника $AB_1C_1$ в семь раз меньше площади четырёхугольника $BCB_1C_1$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $5\\sqrt{26}$ \n";
            break;

            case 4:
            cout << "\\item     Окружность проходит через вершины $B$ и $C$ треугольника $ABC$ и пересекает $AB$ и $AC$ в точках $C_1$ и $B_1$ соответственно." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что треугольник $ABC$ подобен треугольнику $AB_1C_1$." << endl
            << "    \\item Вычислите длину стороны $B_1C_1$ и радиус данной окружности, если $\\angle A= 150^{\\circ}$, $BC= 5\\sqrt{5}$ и площадь треугольника $AB_1C_1$ в четыре раза меньше площади четырёхугольника $BCB_1C_1$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $5\\sqrt{6+\\sqrt{15}}$ \n";
            break;

            case 5:
            cout << "\\item     Окружность проходит через вершины $B$ и $C$ треугольника $ABC$ и пересекает $AB$ и $AC$ в точках $C_1$ и $B_1$ соответственно." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что треугольник $ABC$ подобен треугольнику $AB_1C_1$." << endl
            << "    \\item Вычислите длину стороны $B_1C_1$ и радиус данной окружности, если $\\angle A= 120^{\\circ}$, $BC= 10\\sqrt{7}$ и площадь треугольника $AB_1C_1$ в три раза меньше площади четырёхугольника $BCB_1C_1$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{35\\sqrt{3}}{3}$ \n";
            break;

            case 6:
            cout << "\\item     Четырёхугольник $ABCD$ вписан в окружность радиуса $R = 8$. Известно, что $AB = BC = CD = 12$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что прямые $BC$ и $AD$ параллельны." << endl
            << "    \\item Найдите $AD$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 9 \n";
            break;

            case 7:
            cout << "\\item     Окружность проходит через вершины $A$, $B$ и $C$ параллелограмма $ABCD$, пересекает продолжение стороны $AD$ за точку $D$ в точке $E$ и пересекает продолжение стороны $CD$ за точку $D$ в точке $K$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $BK = BE$." << endl
            << "    \\item Найдите отношение $KE : AC$, если $\\angle BAD = 30^{\\circ}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\sqrt{3}$ \n";
            break;

            case 8:
            cout << "\\item     Окружность с центром в точке $O$ касается сторон угла с вершиной $N$ в точках $A$ и $B$. Отрезок $BC$ -- диаметр этой окружности." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что прямая $AC$ параллельна биссектрисе угла $ANB$." << endl
            << "    \\item Найдите длину отрезка $NO$, если известно, что $AC = 10$ и $AB = 24$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 33,8 \n";
            break;

            case 9:
            cout << "\\item     Окружность с центром в точке $O$ высекает на всех сторонах трапеции $ABCD$ равные хорды." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что биссектрисы всех углов трапеции пересекаются в одной точке." << endl
            << "    \\item Найдите высоту трапеции, если окружность пересекает боковую сторону $AB$ в точках $K$ и $L$ так, что $AK = 15$, $KL = 6$, $LB = 5$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 24 \n";
            break;

            case 10:
            cout << "\\item     Пятиугольник $ABCDE$ вписан в окружность. Диагонали $AD$ и $BE$ пересекаются в точке $M$. Известно, что $BCDM$ -- параллелограмм." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $BC = DE$." << endl
            << "    \\item Найдите длину стороны $AB$, если известно, что $DE = 4$, $AD = 7$, $BE = 8$ и $AB > BC$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 6 \n";
            break;

            case 11:
            cout << "\\item     Окружность проходит через вершины $A$, $B$ и $D$ параллелограмма $ABCD$, пересекает сторону $BC$ в точках $B$ и $E$ и пересекает продолжение стороны $CD$ за точку $D$ в точке $K$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $AE = AK$." << endl
            << "    \\item Найдите отношение $KE : BD$, если $\\angle BAD = 60^{\\circ}$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 1 \n";
            break;

            case 12:
            cout << "\\item     Окружность проходит через вершины $A$, $B$ и $D$ параллелограмма $ABCD$, пересекает сторону $BC$ в точках $B$ и $E$ и пересекает продолжение стороны $CD$ за точку $D$ в точке $K$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $AE = AK$." << endl
            << "    \\item Найдите $AD$, если $CE = 10$, $DK = 9$ и $\\cos(\\angle BAD) = 0,2$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 85 \n";
            break;

            case 13:
            cout << "\\item     Пятиугольник $ABCDE$ вписан в окружность. Известно, что $AB = CD = 3$, $BC = DE = 4$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $AC = CE$." << endl
            << "    \\item Найдите длину диагонали $BE$, если $AD = 6$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{17}{3}$ \n";
            break;

            case 14:
            cout << "\\item     Две окружности касаются внутренним образом в точке $C$. Вершины $A$ и $B$ равнобедренного прямоугольного треугольника $ABC$ с прямым углом $C$ лежат на меньшей и большей окружностях соответственно. Прямая $AC$ вторично пересекает бльшую окружность в точке $E$, а прямая $BC$ вторично пересекает меньшую окружность в точке $D$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что прямые $AD$ и $BE$ параллельны." << endl
            << "    \\item Найдите $AC$, если радиусы окружностей равны 3 и 4." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 4,8 \n";
            break;

            case 15:
            cout << "\\item     Окружность с центром в точке $O$ касается сторон угла с вершиной $N$ в точках $A$ и $B$. Отрезок $BC$ -- диаметр этой окружности." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $\\angle ANB = 2\\angle ABC$." << endl
            << "    \\item Найдите расстояние от точки $N$ до прямой $AB$, если известно, что $AC = 14$ и $AB = 36$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{324}{7}$ \n";
            break;

            case 16:
            cout << "\\item     Две окружности касаются внутренним образом в точке $A$, причём меньшая проходит через центр большей. Хорда $BC$ большей окружности касается меньшей в точке $P$. Хорды $AB$ и $AC$ пересекают меньшую окружность в точках $K$ и $M$ соответственно." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что прямые $KM$ и $BC$ параллельны." << endl
            << "    \\item Пусть $L$ -- точка пересечения отрезков $KM$ и $AP$. Найдите длину отрезка $AL$, если радиус большей окружности равен 34, а $BC = 32$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\sqrt{34}$ \n";
            break;

            case 17:
            cout << "\\item     Две окружности разных радиусов касаются внешним образом в точке $C$. Вершины $A$ и $B$ равнобедренного прямоугольного треугольника $ABC$ с прямым углом $C$ лежат на меньшей и большей окружностях соответственно. Прямая $AC$ вторично пересекает большую окружность в точке $E$, а прямая $BC$ вторично пересекает меньшую окружность в точке $D$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что прямые $AD$ и $BE$ параллельны." << endl
            << "    \\item Найдите $BC$, если радиусы окружностей равны $\\sqrt{15}$ и $15$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 7,5 \n";
            break;

            case 18:
            cout << "\\item     Окружность с центром $O_1$ касается оснований $BC$ и $AD$ и боковой стороны $AB$ трапеции $ABCD$. Окружность с центром $O_2$ касается сторон $BC$, $CD$ и $AD$. Известно, что $AB = 10$, $BC = 9$, $CD = 30$, $AD = 39$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что прямая $O_1O_2$ параллельна основаниям трапеции $ABCD$." << endl
            << "    \\item Найдите $O_1O_2$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 4 \n";
            break;

            case 19:
            cout << "\\item     Окружность проходит через вершины $A$, $B$ и $D$ параллелограмма $ABCD$, пересекает сторону $BC$ в точках $B$ и $M$ и пересекает продолжение стороны $CD$ за точку $D$ в точке $N$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $AM = AN$." << endl
            << "    \\item Найдие отношение $CD : DN$, если $AB : BC = 1 : 2$, a $\\cos(\\angle BAD) = 3$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item $\\frac{3}{5}$ \n";
            break;

            case 20:
            cout << "\\item     Окружность, вписанная в равнобедренную трапецию $ABCD$ , касается её боковой стороны $CD$ в точке $M$ . Луч $AM$ вторично пересекает окружность в точке $N$, а прямую $BC$ -- в точке $K$, причём $AN = 4$, $MN = 12$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Докажите, что $\\angle AMD = \\angle MCK$." << endl
            << "    \\item Найдите основания трапеции." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 9,6; 16 \n";
            break;
        }
    }
    return Answer;
}

string ParamN(int Type)
{
    string Answer;
    int type;
    if(Type == 1)
    {
        //1
        cout << "\\item     Найдите все значения $a$, при которых уравнение:" << endl
            << "    $$\\left(x+\\ln(x+a)\\right)^2=\\left(x-\\ln(x+a)\\right)^2$$" << endl
            << "имеет единственное решение на отрезке $[0;1].$" << endl << endl << endl; 
        Answer = "  \\item $[1;+\\infty)\\cup{0}$ \n";
        
        //2
        cout << "\\item     Найдите все значения $a$, для каждого из которых уравнение:" << endl
            << "    $$4^x+(a-6)2^x=(2+3|a|)2^x+(a-6)(3|a|+2)$$" << endl
            << "имеет единственное решение." << endl << endl << endl; 
        Answer = Answer + "  \\item $[6;+\\infty)\\cup{-2}\\cup{1}$ \n";

        //3
        cout << "\\item     Найдите все значения $a$, для каждого из которых уравнение:" << endl
            << "    $$25^x-(a+6)5^x=(5+3|a|)5^x-(a+6)(3|a|+5)$$" << endl
            << "имеет единственное решение." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;-6]\\cup{-\\frac{1}{4},\\frac{1}{2}}$ \n";

        //4
        cout << "\\item     Найдите все значения параметра $a$, при каждом из которых уравнение:" << endl
            << "    $$\\sqrt{x^4-4x^2+9a^2}=x^2+2x-3a$$" << endl
            << "имеет ровно 3 решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;-\\frac{4}{3})\\cup(-\\frac{4}{3};0)$ \n";

        //5
        cout << "\\item     Найдите все значения $a$, при которых уравнение:" << endl
            << "    $$(2x+a+1-\\tg(x))^2=(2x+a-1+\\tg(x))^2$$" << endl
            << "имеет единственное решение на отрезке $[0;\\pi]$." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;-2\\pi)\\cup{-\\frac{\\pi}{2}}\\cup(0;+\\infty)\\cup{-\\pi}$ \n";

        //6
        cout << "\\item     Найдите все значения параметра $a$, при каждом из которых уравнение:" << endl
            << "    $$\\sqrt{x^4-16x^2+64a^2}=x^2+4x-8a$$" << endl
            << "имеет ровно 3 решения.." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;-2)\\cup(-2;0)$ \n";

        //7
        cout << "\\item     Найдите все значения $a$, при которых уравнение:" << endl
            << "    $$(2x+a+1+\\tg(x))^2=(2x+a-1-\\tg(x))^2$$" << endl
            << "имеет единственное решение на отрезке $\\left[-\\frac{\\pi}{2};\\frac{\\pi}{2}\\right]$." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;-\\pi]\\cup{\\frac{\\pi}{2}}\\cup[\\pi;+\\infty)$ \n";

        //8
        cout << "\\item     Найдите все значения $a$, при которых уравнение:" << endl
            << "    $$(2x+\\ln(x+2a))^2=(2x-\\ln(x+2a))^2$$" << endl
            << "имеет единственный корень на отрезке $[0;1]$." << endl << endl << endl; 
        Answer = Answer + "  \\item ${0}\\cup[\\frac{1}{2};+\\infty)$ \n";

        //9
        cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$\\sqrt{2-3x}\\cdot\\ln\\left(16x^2-a^2\\right)=\\sqrt{2-3x}\\cdot \\ln(4x+a)$$" << endl
            << "имеет ровно один корень." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\frac{8}{3};-\\frac{1}{2}]\\cup[\\frac{5}{3};\\frac{8}{3})$ \n";

        //10
        cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$\\sqrt{4x-1}\\cdot\\ln\\left(x^2-2x+2-a^2\\right)=0$$" << endl
            << "имеет ровно один корень на отрезке $[0;1]$." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\frac{5}{4};-\\frac{3}{4}]\\cup[\\frac{3}{4};\\frac{5}{4})$ \n";

        //11
        cout << "\\item     Найдите все значения а, при каждом из которых уравнение:" << endl
            << "    $$x^2+a^2-x-7a=|7x-a|$$" << endl
            << "имеет ровно два различных корня." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-2;-1)\\cup(0;7)\\cup(8;9)$ \n";

        //12
        cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$\\frac{9x^2-a^2}{x^2+8x+16-a^2}=0$$" << endl
            << "имеет ровно два различных корня." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;-6)\\cup(-6;-3)\\cup(-3;0)\\cup(0;3)\\cup(3;6)\\cup(6;+\\infty)$ \n";

        //13
        cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$|x^2+a^2-6x+4a|=2x-2a$$" << endl
            << "имеет ровно два различных корня." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-8;-1-\\sqrt{5})\\cup(-1+\\sqrt{5};2)\\cup(0;1)$ \n";

        //14
        cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$(5x-2)\\cdot\\ln(x+a)=(5x-2)\\cdot\\ln(2x-a)$$" << endl
            << "имеет ровно один корень на отрезке $[0;1]$." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\frac{2}{5};0)\\cup[\\frac{1}{2};\\frac{4}{5})$ \n";

        //15
        cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$x^2+a^2+x-7a=|7x+a|$$" << endl
            << "имеет больше двух различных корней." << endl << endl << endl; 
        Answer = Answer + "  \\item $[-1;0]\\cup[7;8]$ \n";

        //16
        cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$a^2+ax-2x^2-6a-3x+9|x|=0$$" << endl
            << "имеет меньше четырёх различных корней." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;0]\\cup{2}\\cup{4}\\cup[6;+\\infty)$ \n";

        //17
        cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$\\sqrt{x^2-a^2}=\\sqrt{4x^2-(4a+2)x+2a}$$" << endl
            << "на отрезке $[0; 1]$ имеет ровно один корень." << endl << endl << endl; 
        Answer = Answer + "  \\item $[-\\frac{1}{2};0)\\cup{1}$ \n";

        //18
        cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$\\sqrt{7x-4}\\cdot\\ln\\left(x^2-8x+17-a^2\\right)=0$$" << endl
            << "имеет на отрезке $[0; 4]$ ровно один корень." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\frac{25}{7};-\\frac{24}{7}]\\cup[\\frac{24}{7};\\frac{25}{7})$ \n";

        //19
        cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$a^2-ax-2x^2-6a+3x+9|x|=0$$" << endl
            << "имеет четыре различных корня." << endl << endl << endl; 
        Answer = Answer + "  \\item $(0;2)\\cup(2;4)\\cup(4;6)$ \n";

        //20
        cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$\\ln(4x-1)\\cdot\\sqrt{x^2-6x+6a-a^2}=0$$" << endl
            << "имеет ровно один корень на отрезке $[0; 3]$." << endl << endl << endl; 
        Answer = Answer + "  \\item $(\\frac{1}{4};\\frac{1}{2}]\\cup[5\\frac{1}{2};5\\frac{3}{5})$ \n";

        //21
        cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$|x^2+a^2-6x-4a|=2x+2a$$" << endl
            << "имеет четыре различных корня." << endl << endl << endl; 
        Answer = Answer + "  \\item $(1-\\sqrt{5};-1)\\cup(0;1+\\sqrt{5})$ \n";

        //22
        cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$\\frac{4x^2-a^2}{x^2+6x+9-a^2}=0$$" << endl
            << "имеет ровно два различных корня." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;-6)\\cup(-6;-2)\\cup(-2;0)\\cup(0;2)\\cup(2;6)\\cup(6;+\\infty)$ \n";

        //23
        cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$\\sqrt{x+2a}\\cdot\\ln(x-a)=(x-1)\\cdot\\ln(x-a)$$" << endl
            << "имеет ровно один корень на отрезке $[0; 1]$." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\frac{1}{3};0]\\cup{-\\frac{1}{2}}$ \n";

        //24
        cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$\\sqrt{2x-1}\\cdot\\ln(4x-a)=\\sqrt{2x-1}\\cdot\\ln(5x+a)$$" << endl
            << "имеет ровно один корень на отрезке $[0; 1]$." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-2.5;-0.5)\\cup[-0.25;2)$ \n";
    }
    if(Type == 2)
    {
        type = rand()%24 + 1;
        switch(type)
        {
            case 1:
            cout << "\\item     Найдите все значения $a$, при которых уравнение:" << endl
            << "    $$\\left(x+\\ln(x+a)\\right)^2=\\left(x-\\ln(x+a)\\right)^2$$" << endl
            << "имеет единственное решение на отрезке $[0;1].$" << endl << endl << endl; 
        Answer = "  \\item $[1;+\\infty)\\cup{0}$ \n";
            break;

            case 2:
            cout << "\\item     Найдите все значения $a$, для каждого из которых уравнение:" << endl
            << "    $$4^x+(a-6)2^x=(2+3|a|)2^x+(a-6)(3|a|+2)$$" << endl
            << "имеет единственное решение." << endl << endl << endl; 
        Answer = Answer + "  \\item $[6;+\\infty)\\cup{-2}\\cup{1}$ \n";
            break;

            case 3:
            cout << "\\item     Найдите все значения $a$, для каждого из которых уравнение:" << endl
            << "    $$25^x-(a+6)5^x=(5+3|a|)5^x-(a+6)(3|a|+5)$$" << endl
            << "имеет единственное решение." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;-6]\\cup{-\\frac{1}{4},\\frac{1}{2}}$ \n";
            break;

            case 4:
            cout << "\\item     Найдите все значения параметра $a$, при каждом из которых уравнение:" << endl
            << "    $$\\sqrt{x^4-4x^2+9a^2}=x^2+2x-3a$$" << endl
            << "имеет ровно 3 решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;-\\frac{4}{3})\\cup(-\\frac{4}{3};0)$ \n";
            break;

            case 5:
            cout << "\\item     Найдите все значения $a$, при которых уравнение:" << endl
            << "    $$(2x+a+1-\\tg(x))^2=(2x+a-1+\\tg(x))^2$$" << endl
            << "имеет единственное решение на отрезке $[0;\\pi]$." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;-2\\pi)\\cup{-\\frac{\\pi}{2}}\\cup(0;+\\infty)\\cup{-\\pi}$ \n";
            break;

            case 6:
            cout << "\\item     Найдите все значения параметра $a$, при каждом из которых уравнение:" << endl
            << "    $$\\sqrt{x^4-16x^2+64a^2}=x^2+4x-8a$$" << endl
            << "имеет ровно 3 решения.." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;-2)\\cup(-2;0)$ \n";
            break;

            case 7:
            cout << "\\item     Найдите все значения $a$, при которых уравнение:" << endl
            << "    $$(2x+a+1+\\tg(x))^2=(2x+a-1-\\tg(x))^2$$" << endl
            << "имеет единственное решение на отрезке $\\left[-\\frac{\\pi}{2};\\frac{\\pi}{2}\\right]$." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;-\\pi]\\cup{\\frac{\\pi}{2}}\\cup[\\pi;+\\infty)$ \n";
            break;

            case 8:
            cout << "\\item     Найдите все значения $a$, при которых уравнение:" << endl
            << "    $$(2x+\\ln(x+2a))^2=(2x-\\ln(x+2a))^2$$" << endl
            << "имеет единственный корень на отрезке $[0;1]$." << endl << endl << endl; 
        Answer = Answer + "  \\item ${0}\\cup[\\frac{1}{2};+\\infty)$ \n";
            break;

            case 9:
            cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$\\sqrt{2-3x}\\cdot\\ln\\left(16x^2-a^2\\right)=\\sqrt{2-3x}\\cdot \\ln(4x+a)$$" << endl
            << "имеет ровно один корень." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\frac{8}{3};-\\frac{1}{2}]\\cup[\\frac{5}{3};\\frac{8}{3})$ \n";
            break;

            case 10:
            cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$\\sqrt{4x-1}\\cdot\\ln\\left(x^2-2x+2-a^2\\right)=0$$" << endl
            << "имеет ровно один корень на отрезке $[0;1]$." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\frac{5}{4};-\\frac{3}{4}]\\cup[\\frac{3}{4};\\frac{5}{4})$ \n";
            break;

            case 11:
            cout << "\\item     Найдите все значения а, при каждом из которых уравнение:" << endl
            << "    $$x^2+a^2-x-7a=|7x-a|$$" << endl
            << "имеет ровно два различных корня." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-2;-1)\\cup(0;7)\\cup(8;9)$ \n";
            break;

            case 12:
            cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$\\frac{9x^2-a^2}{x^2+8x+16-a^2}=0$$" << endl
            << "имеет ровно два различных корня." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;-6)\\cup(-6;-3)\\cup(-3;0)\\cup(0;3)\\cup(3;6)\\cup(6;+\\infty)$ \n";
            break;

            case 13:
            cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$|x^2+a^2-6x+4a|=2x-2a$$" << endl
            << "имеет ровно два различных корня." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-8;-1-\\sqrt{5})\\cup(-1+\\sqrt{5};2)\\cup(0;1)$ \n";
            break;

            case 14:
            cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$(5x-2)\\cdot\\ln(x+a)=(5x-2)\\cdot\\ln(2x-a)$$" << endl
            << "имеет ровно один корень на отрезке $[0;1]$." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\frac{2}{5};0)\\cup[\\frac{1}{2};\\frac{4}{5})$ \n";
            break;

            case 15:
            cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$x^2+a^2+x-7a=|7x+a|$$" << endl
            << "имеет больше двух различных корней." << endl << endl << endl; 
        Answer = Answer + "  \\item $[-1;0]\\cup[7;8]$ \n";
            break;

            case 16:
            cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$a^2+ax-2x^2-6a-3x+9|x|=0$$" << endl
            << "имеет меньше четырёх различных корней." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;0]\\cup{2}\\cup{4}\\cup[6;+\\infty)$ \n";
            break;

            case 17:
            cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$\\sqrt{x^2-a^2}=\\sqrt{4x^2-(4a+2)x+2a}$$" << endl
            << "на отрезке $[0; 1]$ имеет ровно один корень." << endl << endl << endl; 
        Answer = Answer + "  \\item $[-\\frac{1}{2};0)\\cup{1}$ \n";
            break;

            case 18:
            cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$\\sqrt{7x-4}\\cdot\\ln\\left(x^2-8x+17-a^2\\right)=0$$" << endl
            << "имеет на отрезке $[0; 4]$ ровно один корень." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\frac{25}{7};-\\frac{24}{7}]\\cup[\\frac{24}{7};\\frac{25}{7})$ \n";
            break;

            case 19:
            cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$a^2-ax-2x^2-6a+3x+9|x|=0$$" << endl
            << "имеет четыре различных корня." << endl << endl << endl; 
        Answer = Answer + "  \\item $(0;2)\\cup(2;4)\\cup(4;6)$ \n";
            break;

            case 20:
            cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$\\ln(4x-1)\\cdot\\sqrt{x^2-6x+6a-a^2}=0$$" << endl
            << "имеет ровно один корень на отрезке $[0; 3]$." << endl << endl << endl; 
        Answer = Answer + "  \\item $(\\frac{1}{4};\\frac{1}{2}]\\cup[5\\frac{1}{2};5\\frac{3}{5})$ \n";
            break;

            case 21:
            cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$|x^2+a^2-6x-4a|=2x+2a$$" << endl
            << "имеет четыре различных корня." << endl << endl << endl; 
        Answer = Answer + "  \\item $(1-\\sqrt{5};-1)\\cup(0;1+\\sqrt{5})$ \n";
            break;

            case 22:
            cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$\\frac{4x^2-a^2}{x^2+6x+9-a^2}=0$$" << endl
            << "имеет ровно два различных корня." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;-6)\\cup(-6;-2)\\cup(-2;0)\\cup(0;2)\\cup(2;6)\\cup(6;+\\infty)$ \n";
            break;

            case 23:
            cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$\\sqrt{x+2a}\\cdot\\ln(x-a)=(x-1)\\cdot\\ln(x-a)$$" << endl
            << "имеет ровно один корень на отрезке $[0; 1]$." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\frac{1}{3};0]\\cup{-\\frac{1}{2}}$ \n";
            break;

            case 24:
            cout << "\\item     Найдите все значения $a$, при каждом из которых уравнение:" << endl
            << "    $$\\sqrt{2x-1}\\cdot\\ln(4x-a)=\\sqrt{2x-1}\\cdot\\ln(5x+a)$$" << endl
            << "имеет ровно один корень на отрезке $[0; 1]$." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-2.5;-0.5)\\cup[-0.25;2)$ \n";
            break;
        }
    }
    return Answer;
}

string ParamS(int Type)
{
    string Answer;
    int type;
    if(Type == 1)
    {
        //1
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            (xy^2-3xy-3y+9)\\sqrt{3-x}=0 \\\\" << endl
            << "            y=ax" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно три различных решения." << endl << endl << endl;  
        Answer = "  \\item $(\\frac{1}{3};1)\\cup\\{3\\}$ \n";
        
        //2
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            x+ay+a-2=0 \\\\" << endl
            << "            x|y|+x-2=0" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет единственное решение." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;0]\\cup(\\frac{1}{2};+\\infty)$ \n";

        //3
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            \\log_7\\left(36-y^2\\right)=\\log_7\\left(36-a^2x^2\\right) \\\\" << endl
            << "            x^2+y^2=2x+6y" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;-3]\\cup\\{-\\frac{1}{3};0;\\frac{1}{3}\\}\\cup(3;+\\infty)$ \n";

        //4
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            x^4+y^2=a^2 \\\\" << endl
            << "            x^2+y=|2a-4|" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно четыре различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $4-2\\sqrt{2};\\frac{4}{3})\\cup(4;4+2\\sqrt{2})$ \n";

        //5
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            y=|x-a|-4 \\\\" << endl
            << "            4|y|+x^2+8x=0" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно четыре различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-5;-4)\\cup(-4;-3)$ \n";

        //6
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            x^2+y^2-4(a+1)x-2ay+5a^2+8a+3=0 \\\\" << endl
            << "           y^2=x^2" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно четыре различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(\\frac{-2-\\sqrt{2}}{3};-1)\\cup(-1;-0.6)\\cup(-0.6;-2+\\sqrt{2})$ \n";

        //7
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            x+y=a \\\\" << endl
            << "           |y|=|x^2-2x|" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;-\\frac{1}{4})\\cup(\\frac{9}{4};+\\infty)$ \n";

        //8
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            2a\\leq x \\\\" << endl
            << "           6x>x^2+a^2 \\\\" << endl
            << "           x+a\\leq 6" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет хотя бы одно решение на отрезке $[4; 5]$." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-2\\sqrt{2};2)$ \n";

        //9
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            ax^2+ay^2-(2a-5)x+2ay+1=0 \\\\" << endl
            << "           x^2+y=xy+x" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно четыре различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;-3)\\cup(-3;0)\\cup(3;\\frac{25}{8})$ \n";

        //10
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            (x+ay-5)(x+ay-5a)=0\\\\" << endl
            << "           x^2+y^2=16" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно четыре различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\frac{4}{3};-\\frac{3}{4})\\cup(\\frac{3}{4};1)\\cup(1;\\frac{4}{3})$ \n";

        //11
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            (x^2-5x-y+3)\\cdot\\sqrt{x-y+3}=0\\\\" << endl
            << "           y=3x+a" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $\\{-13\\}\\cup[-9;3)$ \n";

        //12
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            a(x-1)\\geq 4 \\\\" << endl
            << "           2\\sqrt{x-2}\\geq a \\\\" << endl
            << "           3x<a+14" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет хотя бы одно решение на отрезке $[4; 5]$." << endl << endl << endl; 
        Answer = Answer + "  \\item $(1;2\\sqrt{3})$ \n";

        //13
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            y=(a+2)x^2+2ax+a-2\\\\" << endl
            << "           y^2=x^2" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно четыре различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\frac{17}{4};-2)\\cup(-2;2)\\cup(2;\\frac{17}{4})$ \n";

        //14
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            (x^2-5x-y+3)\\cdot\\sqrt{x-y+3}=0\\\\" << endl
            << "           y=ax+a" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $\\{-1;1\\}\\cup[\\frac{9}{7};3)$ \n";

        //15
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            (x^2+y^2+4x)\\cdot\\sqrt{2x+y+6}=0\\\\" << endl
            << "           y=ax-2a" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $\\{-\\frac{\\sqrt{3}}{3};\\frac{\\sqrt{3}}{3}\\}\\cup[-\\frac{3}{14};\\frac{1}{2})$ \n";

        //16
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            (x^2+y^2+4x)\\cdot\\sqrt{2x+y+6}=0\\\\" << endl
            << "           y=x+a" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $\\{2-2\\sqrt{2};2+2\\sqrt{2}\\}\\cup[0;4.8]$ \n";

        //17
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            \\log_{11}\\left(a-y^2\\right)=\\log_{11}\\left(a-x^2\\right)\\\\" << endl
            << "           x^2+y^2=2x+6y" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(4;16]$ \n";

        //18
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            4x-y+a=0\\\\" << endl
            << "           2|y|-x^2+4x=0" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;-18)\\cup(-16;0)\\cup(2;+\\infty)$ \n";

        //19
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            (xy-2x+12)\\cdot\\sqrt{y-2x+12}=0\\\\" << endl
            << "           y=ax-10" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;0)\\cup(0;\\frac{5}{3}]\\cup\\{2;3\\}$ \n";

        //20
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            (xy-2x+12)\\cdot\\sqrt{y-2x+12}=0\\\\" << endl
            << "           y=3x+a" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-18;-13]\\cup\\{-10;14\\}$ \n";

        //21
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            ax\\geq 2 \\\\" << endl
            << "           \\sqrt{x-1} >a \\\\" << endl
            << "           3x\\leq 2a+11" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет хотя бы одно решение на отрезке $[3; 4]$." << endl << endl << endl; 
        Answer = Answer + "  \\item $[0.5;\\sqrt{3})$ \n";

        //22
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            x\\leq 2a+6 \\\\" << endl
            << "           6x\\geq x^2 + a^2 \\\\" << endl
            << "           x+a>0" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет хотя бы одно решение на отрезке $[1; 2]$." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-2;2\\sqrt{2}]$ \n";

        //23
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            x^2+y^2=6x+8y-9\\\\" << endl
            << "           x^2+y^2=a^2" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(1;9)$ \n";

        //24
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            \\log_3\\left(16-y^2\\right)=\\log_3\\left(16-a^2x^2\\right)\\\\" << endl
            << "           x^2+y^2=8x+4y" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(1;9)$ \n";

        //25
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            ax^2+ay^2+2ax+(a+2)y+1=0\\\\" << endl
            << "           xy+1=x+y" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно четыре различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-2;2)$ \n";

        //26
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            x^4-y^4=12a-28\\\\" << endl
            << "           x^2+y^2=a" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно четыре различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $[2;6-2\\sqrt{2}]\\cup[6+2\\sqrt{2};+\\infty)$ \n";

        //27
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            \\sqrt{36-y^2}=\\sqrt{36-a^2x^2}\\\\" << endl
            << "           x^2+y^2=2x+6y" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;-3)\\cup\\{-\\frac{1}{3};0;\\frac{1}{3}\\}$ \n";

        //28
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            |x|+|y|=a\\\\" << endl
            << "           y=\\sqrt{x+4}" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(2;4)\\cup\\{\\frac{17}{4}\\}$ \n";

        //29
        cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            \\sqrt{a-y^2}=\\sqrt{a-x^2}\\\\" << endl
            << "           x^2+y^2=2x+4y" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $[1;9)$ \n";
    }
    if(Type == 2)
    {
        type = rand()%29 +1;
        switch(type)
        {
            case 1:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            (xy^2-3xy-3y+9)\\sqrt{3-x}=0 \\\\" << endl
            << "            y=ax" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно три различных решения." << endl << endl << endl;  
        Answer = "  \\item $(\\frac{1}{3};1)\\cup\\{3\\}$ \n";
            break;

            case 2:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            x+ay+a-2=0 \\\\" << endl
            << "            x|y|+x-2=0" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет единственное решение." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;0]\\cup(\\frac{1}{2};+\\infty)$ \n";
            break;

            case 3:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            \\log_7\\left(36-y^2\\right)=\\log_7\\left(36-a^2x^2\\right) \\\\" << endl
            << "            x^2+y^2=2x+6y" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;-3]\\cup\\{-\\frac{1}{3};0;\\frac{1}{3}\\}\\cup(3;+\\infty)$ \n";
            break;

            case 4:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            x^4+y^2=a^2 \\\\" << endl
            << "            x^2+y=|2a-4|" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно четыре различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $4-2\\sqrt{2};\\frac{4}{3})\\cup(4;4+2\\sqrt{2})$ \n";
            break;

            case 5:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            y=|x-a|-4 \\\\" << endl
            << "            4|y|+x^2+8x=0" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно четыре различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-5;-4)\\cup(-4;-3)$ \n";
            break;

            case 6:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            x^2+y^2-4(a+1)x-2ay+5a^2+8a+3=0 \\\\" << endl
            << "           y^2=x^2" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно четыре различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(\\frac{-2-\\sqrt{2}}{3};-1)\\cup(-1;-0.6)\\cup(-0.6;-2+\\sqrt{2})$ \n";
            break;

            case 7:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            x+y=a \\\\" << endl
            << "           |y|=|x^2-2x|" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;-\\frac{1}{4})\\cup(\\frac{9}{4};+\\infty)$ \n";
            break;

            case 8:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            2a\\leq x \\\\" << endl
            << "           6x>x^2+a^2 \\\\" << endl
            << "           x+a\\leq 6" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет хотя бы одно решение на отрезке $[4; 5]$." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-2\\sqrt{2};2)$ \n";
            break;

            case 9:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            ax^2+ay^2-(2a-5)x+2ay+1=0 \\\\" << endl
            << "           x^2+y=xy+x" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно четыре различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;-3)\\cup(-3;0)\\cup(3;\\frac{25}{8})$ \n";
            break;

            case 10:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            (x+ay-5)(x+ay-5a)=0\\\\" << endl
            << "           x^2+y^2=16" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно четыре различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\frac{4}{3};-\\frac{3}{4})\\cup(\\frac{3}{4};1)\\cup(1;\\frac{4}{3})$ \n";
            break;

            case 11:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            (x^2-5x-y+3)\\cdot\\sqrt{x-y+3}=0\\\\" << endl
            << "           y=3x+a" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $\\{-13\\}\\cup[-9;3)$ \n";
            break;

            case 12:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            a(x-1)\\geq 4 \\\\" << endl
            << "           2\\sqrt{x-2}\\geq a \\\\" << endl
            << "           3x<a+14" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет хотя бы одно решение на отрезке $[4; 5]$." << endl << endl << endl; 
        Answer = Answer + "  \\item $(1;2\\sqrt{3})$ \n";
            break;

            case 13:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            y=(a+2)x^2+2ax+a-2\\\\" << endl
            << "           y^2=x^2" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно четыре различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\frac{17}{4};-2)\\cup(-2;2)\\cup(2;\\frac{17}{4})$ \n";
            break;

            case 14:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            (x^2-5x-y+3)\\cdot\\sqrt{x-y+3}=0\\\\" << endl
            << "           y=ax+a" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $\\{-1;1\\}\\cup[\\frac{9}{7};3)$ \n";
            break;

            case 15:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            (x^2+y^2+4x)\\cdot\\sqrt{2x+y+6}=0\\\\" << endl
            << "           y=ax-2a" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $\\{-\\frac{\\sqrt{3}}{3};\\frac{\\sqrt{3}}{3}\\}\\cup[-\\frac{3}{14};\\frac{1}{2})$ \n";
            break;

            case 16:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            (x^2+y^2+4x)\\cdot\\sqrt{2x+y+6}=0\\\\" << endl
            << "           y=x+a" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $\\{2-2\\sqrt{2};2+2\\sqrt{2}\\}\\cup[0;4.8]$ \n";
            break;

            case 17:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            \\log_{11}\\left(a-y^2\\right)=\\log_{11}\\left(a-x^2\\right)\\\\" << endl
            << "           x^2+y^2=2x+6y" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(4;16]$ \n";
            break;

            case 18:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            4x-y+a=0\\\\" << endl
            << "           2|y|-x^2+4x=0" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;-18)\\cup(-16;0)\\cup(2;+\\infty)$ \n";
            break;

            case 19:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            (xy-2x+12)\\cdot\\sqrt{y-2x+12}=0\\\\" << endl
            << "           y=ax-10" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;0)\\cup(0;\\frac{5}{3}]\\cup\\{2;3\\}$ \n";
            break;

            case 20:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            (xy-2x+12)\\cdot\\sqrt{y-2x+12}=0\\\\" << endl
            << "           y=3x+a" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-18;-13]\\cup\\{-10;14\\}$ \n";
            break;

            case 21:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            ax\\geq 2 \\\\" << endl
            << "           \\sqrt{x-1} >a \\\\" << endl
            << "           3x\\leq 2a+11" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет хотя бы одно решение на отрезке $[3; 4]$." << endl << endl << endl; 
        Answer = Answer + "  \\item $[0.5;\\sqrt{3})$ \n";
            break;

            case 22:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            x\\leq 2a+6 \\\\" << endl
            << "           6x\\geq x^2 + a^2 \\\\" << endl
            << "           x+a>0" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет хотя бы одно решение на отрезке $[1; 2]$." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-2;2\\sqrt{2}]$ \n";
            break;

            case 23:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            x^2+y^2=6x+8y-9\\\\" << endl
            << "           x^2+y^2=a^2" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(1;9)$ \n";
            break;

            case 24:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            \\log_3\\left(16-y^2\\right)=\\log_3\\left(16-a^2x^2\\right)\\\\" << endl
            << "           x^2+y^2=8x+4y" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(1;9)$ \n";
            break;

            case 25:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            ax^2+ay^2+2ax+(a+2)y+1=0\\\\" << endl
            << "           xy+1=x+y" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно четыре различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-2;2)$ \n";
            break;

            case 26:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            x^4-y^4=12a-28\\\\" << endl
            << "           x^2+y^2=a" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно четыре различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $[2;6-2\\sqrt{2}]\\cup[6+2\\sqrt{2};+\\infty)$ \n";
            break;

            case 27:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            \\sqrt{36-y^2}=\\sqrt{36-a^2x^2}\\\\" << endl
            << "           x^2+y^2=2x+6y" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(-\\infty;-3)\\cup\\{-\\frac{1}{3};0;\\frac{1}{3}\\}$ \n";
            break;

            case 28:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            |x|+|y|=a\\\\" << endl
            << "           y=\\sqrt{x+4}" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $(2;4)\\cup\\{\\frac{17}{4}\\}$ \n";
            break;

            case 29:
            cout << "\\item     Найдите все значения $a$, при каждом из которых система уравнений:" << endl
            << "    \\[" << endl 
            << "        \\begin{cases}" << endl
            << "            \\sqrt{a-y^2}=\\sqrt{a-x^2}\\\\" << endl
            << "           x^2+y^2=2x+4y" << endl
            << "        \\end{cases}" << endl
            << "    \\]" << endl
            << "имеет ровно два различных решения." << endl << endl << endl; 
        Answer = Answer + "  \\item $[1;9)$ \n";
            break;
        }
    }
    return Answer;
}

string TeorChisl(int Type)
{
    string Answer;
    int type;
    if(Type == 1)
    {
        //1
        cout << "\\item     С трёхзначным числом производят следующую операцию: к нему прибавляют цифру десятков, умноженную на 10, а затем к получившейся сумме прибавляют 3." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Могло ли в результате такой операции получиться число 224?" << endl
            << "    \\item Могло ли в результате такой операции получиться число 314?" << endl
            << "    \\item Найдите наибольшее отношение получившегося числа к исходному." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = "  \\item да, 211;нет;283/190 \n";
        
        //2
        cout << "\\item     В школах Nº1 и Nº2 учащиеся писали тест. Из каждой школы тест писали по крайней мере 2 учащихся, а суммарно тест писал 51 учащийся. Каждый учащийся, писавший тест, набрал натуральное количество баллов. Оказалось, что в каждой школе средний балл за тест был целым числом. После этого один из учащихся, писавших тест, перешёл из школы Nº1 в школу Nº2, а средние баллы за тест были пересчитаны в обеих школах." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Мог ли средний балл в школе Nº1 вырасти в 2 раза?" << endl
            << "    \\item Средний балл в школе Nº1 вырос на 10\\%, средний балл в школе Nº2 также вырос на 10\\%. Мог ли первоначальный средний балл в школе Nº2 равняться 1?" << endl
            << "    \\item Средний балл в школе Nº1 вырос на 10\\%, средний балл в школе Nº2 также вырос на 10\\%. Найдите наименьшее значение первоначального среднего балла в школе Nº2." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item нет;нет;3 \n";

        //3
        cout << "\\item     На доске написано 30 различных натуральных чисел, десятичная запись каждого из которых оканчивается или на цифру 2, или на цифру 6. Сумма написанных чисел равна 2454." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли на доске быть поровну чисел, оканчивающихся на 2 и на 6?" << endl
            << "    \\item Может ли ровно одно число на доске оканчиваться на 6?" << endl
            << "    \\item Какое наименьшее количество чисел, оканчивающихся на б, может быть на доске?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
       Answer = Answer + "  \\item нет;нет;11 \n";

        //4
        cout << "\\item     Есть три коробки: в первой коробке 97 камней, во второй - 104, а в третьей коробке камней нет. За один ход берут по одному камню из любых двух коробок и кладут в оставшуюся. Сделали некоторое количество таких ходов." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Могло ли в первой коробке оказаться 97 камней, во второй — 89, а в третьей - 15?" << endl
            << "    \\item Мог ли в третьей коробке оказаться 201 камень?" << endl
            << "    \\item В первой коробке оказался 1 камень. Какое наибольшее число камней могло оказаться в третьей коробке?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;нет;198 \n";

        //5
        cout << "\\item     По кругу расставлено N различных натуральных чисел, каждое из которых не превосходит 365. Сумма любых четырёх идущих подряд чисел делится на 4, а сумма любых трёх идущих подряд чисел нечётна." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли N быть равным 200?" << endl
            << "    \\item Может ли N быть равным 109?" << endl
            << "    \\item Найдите наибольшее значение N." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item нет;нет;182 \n";

        //6
        cout << "\\item     Есть четыре коробки: в первой коробке 101 камень, во второй - 102, в третьей - 103, а в четвёртой коробке камней нет. За один ход берут по одному камню из любых трёх коробок и кладут в оставшуюся. Сделали некоторое количество таких ходов." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Могло ли в первой коробке оказаться 97 камней, во второй - 102, в третьей - 103, а в четвёртой — 4?" << endl
            << "    \\item Могло ли в четвёртой коробке оказаться 306 камней?" << endl
            << "    \\item Какое наибольшее число камней могло оказаться в первой коробке?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;нет;303 \n";

        //7
        cout << "\\item     В порту имеются только заполненные контейнеры, масса каждого из которых равна 20 тонн или 60 тонн. В некоторых из этих контейнеров находится сахарный песок. Количество контейнеров с сахарным песком составляет 25\\% от общего количества контейнеров." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли масса контейнеров с сахарным песком составить 20 \\% от общей массы всех контейнеров?" << endl
            << "    \\item Может ли масса контейнеров с сахарным песком составить 60 \\% от общей массы всех контейнеров?" << endl
            << "    \\item Какую наименьшую долю (в процентах) может составить масса контейнеров с сахарным песком от общей массы всех контейнеров?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;нет;10 \n";

        //8
        cout << "\\item     На доске написано несколько различных натуральных чисел, произведение любых двух из которых больше 60 и меньше 140." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли на доске быть 5 чисел?" << endl
            << "    \\item Может ли на доске быть 6 чисел?" << endl
            << "    \\item Какое наименьшее значение может принимать сумма чисел на доске, если их четыре?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
       Answer = Answer + "  \\item да;нет;37 \n";

        //9
        cout << "\\item     В классе больше 10, но не больше 26 учащихся, а доля девочек не превышает 21\\%." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли в этом классе быть 5 девочек?" << endl
            << "    \\item Может ли доля девочек составить 30\\%, если в этот класс придёт новая девочка?" << endl
            << "    \\item В этот класс пришла новая девочка. Доля девочек в классе составила целое число процентов. Какое наибольшее число процентов может составить доля девочек в классе?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;нет;25 \n";

        //10
        cout << "\\item     Каждое из четырёх последовательных натуральных чисел, последние цифры которых не равны нулю, поделили на его последнюю цифру. Сумма получившихся чисел равна S." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли S быть равной $16\\frac{5}{6}$?" << endl
            << "    \\item Может ли S быть равной $569\\frac{29}{126}$?" << endl
            << "    \\item Найдите наибольшее целое значение S, если каждое из исходных чисел было трёхзначным." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;нет;2004 \n";

        //11
        cout << "\\item     На доске написано 11 различных натуральных чисел. Среднее арифметическое шести наименьших из них равно 5, а среднее арифметическое шести наибольших равно 15." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли наименьшее из этих одиннадцати чисел равняться 3?" << endl
            << "    \\item Может ли среднее арифметическое всех одиннадцати чисел равняться 9?" << endl
            << "    \\item Пусть В - шестое по величине число, а S — среднее арифметическое всех одиннадцати чисел. Найдите наибольшее значение выражения S - B." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item нет;нет;8 \n";

        //12
        cout << "\\item     На доске написано 30 различных натуральных чисел, каждое из которых либо чётное, либо его десятичная запись оканчивается на цифру 7. Сумма написанных чисел равна 810." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли на доске быть ровно 24 чётных числа?" << endl
            << "    \\item Могут ли ровно два числа на доске оканчиваться на 7?" << endl
            << "    \\item Какое наименьшее количество чисел, оканчивающихся на 7, может быть на доске?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;нет;4 \n";

        //13
        cout << "\\item     На доске было написано несколько различных натуральных чисел. Эти числа разбили на три группы, в каждой из которых оказалось хотя бы одно число. К каждому числу из первой группы приписали справа цифру 1, к каждому числу из второй группы - цифру 8, а числа из третьей группы оставили без изменений." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Могла ли сумма всех этих чисел увеличиться в 4 раза?" << endl
            << "    \\item Могла ли сумма всех этих чисел увеличиться в 18 раз?" << endl
            << "    \\item Сумма всех этих чисел увеличилась в 11 раз. Какое наибольшее количество чисел могло быть написано на доске?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;нет;10 \n";

        //14
        cout << "\\item     На доске написано 100 различных натуральных чисел, сумма которых равна 5120." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли оказаться, что на доске написано число 230?" << endl
            << "    \\item Может ли оказаться, что на доске нет числа 14?" << endl
            << "    \\item Какое наименьшее количество чисел, кратных 14, может быть на доске?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item нет;нет;4 \n";

        //15
        cout << "\\item     Тройку различных натуральных чисел назовём удачной, если любое число в ней хотя бы на 5 больше, чем треть суммы двух других чисел. Например, 40, 45, 50 — удачная тройка." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Сколько существует удачных троек, содержащих числа 50, 60 и ещё одно число, большее 60?" << endl
            << "    \\item Найдётся ли удачная тройка, одно из чисел которой равно 15?" << endl
            << "    \\item Какое наибольшее количество чисел от 1 до 100 включительно можно расставить по кругу так, чтобы каждое число встречалось не более одного раза и любые три подряд идущих числа образовывали удачную тройку?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
       Answer = Answer + "  \\item да 15; нет; 29 \n";

        //16
        cout << "\\item     На доске написано и единиц подряд. Между некоторыми из них расставляют знаки «+» и считают получившуюся сумму. Например, если было написано 10 единиц, то можно получить сумму 136: $1+1+111+11+11+1=136$" << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Можно ли получить сумму 132, если п=60?" << endl
            << "    \\item Можно ли получить сумму 132, если n = 80 ?" << endl
            << "    \\item Для скольких значений п можно получить сумму 132?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;нет;14 \n";

        //17
        cout << "\\item     В порту имеются только заполненные контейнеры, масса каждого из которых равна 20 тонн или 60 тонн. В некоторых из этих контейнеров находится сахарный песок. Количество контейнеров с сахарным песком составляет 75\\% от общего количества контейнеров." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли масса контейнеров с сахарным песком составить 80\\% от общей массы всех контейнеров?" << endl
            << "    \\item Может ли масса контейнеров с сахарным песком составить 40\\% от общей массы всех контейнеров?" << endl
            << "    \\item Какую наибольшую долю (в процентах) может составить масса контейнеров с сахарным песком от общей массы всех контейнеров?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;нет;90 \n";

        //18
        cout << "\\item     В школах Nº1 и Nº2 учащиеся писали тест. Из каждой школы тест писали по крайней мере 2 учащихся. Каждый учащийся, писавший тест, набрал натуральное количество баллов. Оказалось, что в каждой школе средний балл за тест был целым числом, причём в школе Nº2 средний балл равнялся 42. Один из учащихся, писавших тест, перешёл из школы Nº1 в школу Nº2, а средние баллы за тест были пересчитаны в обеих школах. В результате средний балл в школе Nº1 уменьшился на 10\\%, средний балл в школе Nº2 также уменьшился на 10\\%." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Сколько учащихся могло писать тест в школе Nº2 изначально?" << endl
            << "    \\item Каждый учащийся школы Nº2, писавший тест, набрал больше баллов, чем перешедший в неё учащийся школы Nº 1. Какое наибольшее количество баллов мог набрать учащийся школы Nº2?" << endl
            << "    \\item Какое наибольшее количество учащихся могло писать тест в школе Nº1 изначально?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 4;102;12 \n";

        //19
        cout << "\\item     На доске написано несколько различных натуральных чисел, произведение любых двух из которых больше 40 и меньше 100." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли на доске быть 5 чисел?" << endl
            << "    \\item Может ли на доске быть 6 чисел?" << endl
            << "    \\item Какое наибольшее значение может принимать сумма чисел на доске, если их четыре?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;нет;35 \n";

        //20
        cout << "\\item     На доске написано и единиц подряд. Между некоторыми из них расставляют знаки «t» и считают получившуюся сумму. Например, если было написано 10 единиц, то можно получить сумму 136: $1+1+111+11+11+1=136$" << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Можно ли получить сумму 113, если п = 50?" << endl
            << "    \\item Можно ли получить сумму 114, если п= 50?" << endl
            << "    \\item Какую наибольшую четырёхзначную сумму можно получить, если п = 50?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;нет;9554 \n";

        //21
        cout << "\\item     В школах Nº1 и Nº2 учащиеся писали тест. Из каждой школы тест писали по крайней мере 2 учащихся. Каждый учащийся, писавший тест, набрал натуральное количество баллов. Оказалось, что в каждой школе средний балл за тест был целым числом, причём в школе Nº1 средний балл равнялся 18. Один из учащихся, писавших тест, перешёл из школы Nº1 в школу Nº2, а средние баллы за тест были пересчитаны в обеих школах. В результате средний балл в школе Nº1 вырос на 10\\%, средний балл в школе Nº2 также вырос на 10\\%." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Сколько учащихся могло писать тест в школе Nº1 изначально?" << endl
            << "    \\item В школе Nº1 все писавшие тест набрали разное количество баллов. Какое наибольшее количество баллов мог набрать учащийся этой школы?" << endl
            << "    \\item Известно, что изначально в школе Nº2 писали тест более 10 учащихся. Какое наименьшее количество учащихся могло писать тест в школе Nº2 изначально?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
       Answer = Answer + "  \\item 6;89;19 \n";

        //22
        cout << "\\item     На доске написано 10 различных натуральных чисел. Среднее арифметическое шести наименьших из них равно 5, а среднее арифметическое шести наибольших равно 15." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли наименьшее из этих десяти чисел равняться 3?" << endl
            << "    \\item Может ли среднее арифметическое всех десяти чисел равняться 11?" << endl
            << "    \\item Найдите наибольшее значение среднего арифметического всех десяти чисел." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item нет;нет;10,5 \n";

        //23
        cout << "\\item     В школах Nº1 и Nº2 учащиеся писали тест. Из каждой школы тест писали по крайней мере 2 учащихся, а суммарно тест писали 9 учащихся. Каждый учащийся, писавший тест, набрал натуральное количество баллов. Оказалось, что в каждой школе средний балл за тест был целым числом. После этого один из учащихся, писавших тест, перешёл из школы Nº1 в школу Nº2, а средние баллы за тест были пересчитаны в обеих школах." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Мог ли средний балл в школе Nº1 уменьшиться в 10 раз?" << endl
            << "    \\item Средний балл в школе Nº1 уменьшился на 10\\%, средний балл в школе Nº2 также уменьшился на 10\\%. Мог ли первоначальный средний балл в школе Nº2 равняться 7?" << endl
            << "    \\item Средний балл в школе Nº1 уменьшился на 10\\%, средний балл в школе Nº2 также уменьшился на 10\\%. Найдите наименьшее значение первоначального среднего балла в школе Nº2." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
       Answer = Answer + "  \\item да;нет;5 \n";

        //24
        cout << "\\item     Из пары натуральных чисел $(a; b)$ за один ход можно получить пару $(a + 2; b - 1)$ или $(a - 1; b + 2)$ при условии, что оба числа в новой паре положительны. Сначала есть пара $(5; 7)$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Можно ли за 50 таких ходов получить пару, в которой одно из чисел равно 100?" << endl
            << "    \\item За какое число ходов получится пара, сумма чисел в которой равна 400?" << endl
            << "    \\item Какое наибольшее число ходов можно сделать так, чтобы после каждого хода оба числа в паре не превосходили 100?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item нет;388;187 \n";

        //25
        cout << "\\item     Для чисел А и В, состоящих из одинакового количества цифр, вычисляют s - сумму произведений соответствующих цифр. Например, для чисел А = 123 и В = 579 получается сумма $S=1\\cdot5+2\\cdot7+3\\cdot9=46$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Существуют ли трёхзначные числа А и В, для которых S = 200?" << endl
            << "    \\item Существуют ли четырёхзначные числа А и В, для которых S = 320?" << endl
            << "    \\item Верно ли, что любое натуральное число от 1 до 340 является суммой S для некоторых пятизначных чисел А и В?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;нет;да \n";

        //26
        cout << "\\item     По кругу расставлено N различных натуральных чисел, каждое из которых не превосходит 400. Сумма любых четырёх идущих подряд чисел делится на 3, а сумма любых трёх идущих подряд чисел не делится на 3." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли N быть равным 360?" << endl
            << "    \\item Может ли N быть равным 149?" << endl
            << "    \\item Найдите наибольшее значение N." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
       Answer = Answer + "  \\item нет;нет;266 \n";

        //27
        cout << "\\item     На доске написано несколько различных натуральных чисел, в записи которых могут быть только цифры 4 и 9 (возможно, только одна из этих цифр)." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли сумма этих чисел быть равна 107?" << endl
            << "    \\item Может ли сумма этих чисел быть равна 289?" << endl
            << "    \\item Какое наименьшее количество чисел может быть на доске, если их сумма равна 3986?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;нет;9 \n";

        //28
        cout << "\\item     На доске написано 30 натуральных чисел (числа могут повторяться), каждое из которых либо зелёного, либо красного цвета. Каждое зелёное число кратно 3, а каждое красное число кратно 7. При этом все зелёные числа различны и все красные различны (какое-то зелёное число может равняться какому-то красному числу)." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли сумма написанных чисел быть меньше $1395 = 3 + 6 + \\ldots + 90$, если все числа на доске кратны 3?" << endl
            << "    \\item Может ли ровно одно число на доске быть красным, если сумма написанных чисел равна 1067?" << endl
            << "    \\item Какое наименьшее количество красных чисел может быть на доске, если сумма написанных чисел равна 1067?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;нет;6 \n";

        //29
        cout << "\\item     Есть 16 монет по 2 рубля и 29 монет по 5 рублей." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Можно ли этими монетами набрать сумму 175 рублей?" << endl
            << "    \\item Можно ли этими монетами набрать сумму 176 рублей?" << endl
            << "    \\item Какое наименьшее количество монет, каждая по 1 рублю, нужно добавить, чтобы иметь возможность набрать любую целую сумму от 1 рубля до 180 рублей включительно?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;нет;9 \n";

        //30
        cout << "\\item     Маша и Наташа делали фотографии в течение некоторого количества подряд идущих дней. В первый день Маша сделала m фотографий, а Наташа — n фотографий. В каждый следующий день каждая из девочек делала на одну фотографию больше, чем в предыдущий день. Известно, что Наташа за всё время сделала суммарно на 1001 фотографию больше, чем Маша, и что фотографировали они больше одного дня." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Могли ли они фотографировать в течение 7 дней?" << endl
            << "    \\item Могли ли они фотографировать в течение 8 дней?" << endl
            << "    \\item Какое наибольшее суммарное число фотографий могла сделать Наташа за все дни фотографирования, если известно, что в последний день Маша сделала меньше 40 фотографий?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;нет;1430 \n";

        //31
        cout << "\\item     По окружности в некотором порядке расставлены натуральные числа от 1 до 12. Между каждыми двумя соседними числами написали модуль их разности. Затем исходные числа стёрли." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Приведите пример расстановки, когда сумма полученных чисел равна 32." << endl
            << "    \\item Может ли сумма полученных чисел быть равна 29?" << endl
            << "    \\item Какое наибольшее значение может принимать сумма полученных чисел?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
       Answer = Answer + "  \\item да;нет;712 \n";

        //32
        cout << "\\item     В течение и дней каждый день на доску записывают натуральные числа, каждое из которых меньше 6. При этом каждый день (кроме первого) сумма чисел, записанных на доску в этот день, больше, а количество меньше, чем в предыдущий день." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли п быть больше 6?" << endl
            << "    \\item Может ли среднее арифметическое чисел, записанных в первый день, быть меньше 2, а среднее арифметическое всех чисел, записанных за все дни, быть больше 4?" << endl
            << "    \\item Известно, что сумма чисел, записанных в первый день, равна 5. Какое наибольшее значение может принимать сумма всех чисел, записанных за все дни?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;да;34 \n";

        //33
        cout << "\\item     Из набора цифр 0, 1, 2, 3, 5, 7 и 9 составляют пару чисел, используя каждую цифру ровно один раз. Оказалось, что одно из этих чисел четырёхзначное, другое — трёхзначное и оба кратны 45." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли сумма такой пары чисел равняться 2205?" << endl
            << "    \\item Может ли сумма такой пары чисел равняться 3435?" << endl
            << "    \\item Какое наибольшее значение может принимать сумма чисел в такой паре?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;нет;10035 \n";

        //34
        cout << "\\item     В течение n дней каждый день на доску записывают натуральные числа, каждое из которых меньше 6. При этом каждый день (кроме первого) сумма чисел, записанных на доску в этот день, больше, а количество меньше, чем в предыдущий день." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли n быть больше 5?" << endl
            << "    \\item Может ли среднее арифметическое чисел, записанных в первый день, быть меньше 3, а среднее арифметическое всех чисел, записанных за все дни, быть больше 4?" << endl
            << "    \\item Известно, что сумма чисел, записанных в первый день, равна 6. Какое наибольшее значение может принимать сумма всех чисел, записанных за все дни?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;да;48 \n";

        //35
        cout << "\\item     На доске написано несколько различных натуральных чисел, произведение любых двух из которых больше 25 и меньше 85." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли на доске быть 5 чисел?" << endl
            << "    \\item Может ли на доске быть 6 чисел?" << endl
            << "    \\item Какое наибольшее значение может принимать сумма чисел на доске, если их четыре?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;нет;31 \n";

        //36
        cout << "\\item     Деревянную линейку, длина которой выражается целым числом сантиметров, разрезают на куски. За один ход можно взять один или несколько кусков линейки, положить их друг на друга и разрезать каждый из них на две части, длины которых выражаются целые числом сантиметров." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Можно ли за четыре хода разрезать линейку длиной 16 см на куски длиной 1 см?" << endl
            << "    \\item Можно ли за пять ходов разрезать линейку длиной 100 см на куски длиной 1 см?" << endl
            << "    \\item Какое наименьшее число ходов нужно сделать, чтобы разрезать линейку длиной 200 см на куски длиной 1 см?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;нет;8 \n";

        //37
        cout << "\\item     Есть 4 камня, каждый массой 7 тонн, и 9 камней, каждый массой 22 тонны." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Можно ли разложить все эти камни на две группы так, чтобы разность суммарных масс камней в этих группах составила 8 тонн?" << endl
            << "    \\item Можно ли разложить все эти камни на две группы, суммарные массы камней в которых равны?" << endl
            << "    \\item Все камни хотят разложить на две группы. Какое наименьшее положительное значение (в тоннах) может принимать разность суммарных масс камней в этих группах?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
       Answer = Answer + "  \\item да;нет;6 \n";

        //38
        cout << "\\item     Из правильной несократимой дроби $\\frac{a}{b}$, где $a$ и $b$ — натуральные числа, за один ход получают дробь $\\frac{a+b}{2a+b}$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Можно ли за несколько таких ходов из дроби $\\frac{1}{3}$ получить дробь $\\frac{22}{31}$?" << endl
            << "    \\item Можно ли за два таких хода из некоторой дроби получить дробь $\\frac{7}{12}$?" << endl
            << "    \\item Несократимая дробь $\\frac{c}{d}$ больше 0,7. Найдите наименьшую дробь $\\frac{c}{d}$, которую нельзя получить ни из какой правильной несократимой дроби за два таких хода?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;нет;5/7 \n";

        //39
        cout << "\\item     На доске написано несколько различных натуральных чисел, произведение любых двух из которых больше 45 и меньше 120." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли на доске быть 5 чисел?" << endl
            << "    \\item Может ли на доске быть 6 чисел?" << endl
            << "    \\item Какое наименьшее значение может принимать сумма чисел на доске, если их четыре?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;нет;33 \n";

        //40
        cout << "\\item     Ваня написал на доске трёхзначное число А. Петя переписал это число А, вычеркнул из него одну цифру и получил двузначное число В. Коля тоже переписал это число А, вычеркнул из него одну цифру (возможно, ту же самую, что и Петя) и получил двузначное число С." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли быть верным равенство $A = B\\cdot C$, если $A>150$?" << endl
            << "    \\item Может ли быть верным равенство $A = B\\cdot C$, если $540 \\leq A < 600$?" << endl
            << "    \\item в) Найдите наибольшее число А, для которого может быть верным равенство $A = B\\cdot C$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
       Answer = Answer + "  \\item да;нет;910 \n";

        //41
        cout << "\\item     Из пары натуральных чисел $(a;b)$ , где $a > b$ , за один ход получают пару $(a+b;a-b)$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Можно ли за несколько таких ходов получить из пары (100;1) пару, большее число в которой равно 400?" << endl
            << "    \\item Можно ли за несколько таких ходов получить из пары (100;1) пару (806; 788) ?" << endl
            << "    \\item Какое наименьшее $a$ может быть в паре (а; b) , из которой за несколько ходов можно получить пару (806; 788) ?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;нет;403 \n";

        //42
        cout << "\\item     На доске было написано несколько различных натуральных чисел. Эти числа разбили на три группы, в каждой из которых оказалось хотя бы одно число. К каждому числу из первой группы приписали справа цифру 3, к каждому числу из второй группы — цифру 7, а числа из третьей группы оставили без изменений." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Могла ли сумма всех этих чисел увеличиться в 8 раз?" << endl
            << "    \\item Могла ли сумма всех этих чисел увеличиться в 17 раз?" << endl
            << "    \\item В какое наибольшее число раз могла увеличиться сумма всех этих чисел?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;нет;232/21 \n";

        //43
        cout << "\\item     Над парами целых чисел проводится операция: из пары (а; b) получается пара (За + b; 3b - а)." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Можно ли из какой-то пары получить пару (5; 5)?" << endl
            << "    \\item Верно ли, что если пара (с; d) может быть получена из какой-то пары с помощью данной операции, то и пара (-d; с) тоже может быть получена из какой-то пары с помощью данной операции?" << endl
            << "    \\item Зададим расстояние между парами целых чисел (а; b) и (с; d) выражением $|a-c|+|b-d|$. Найдите наименьшее расстояние от пары (9; 2) до пары, полученной из какой-то пары с помощью данной операции." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;да;3 \n";

        //44
        cout << "\\item     На доске написано 10 различных натуральных чисел. Среднее арифметическое шести наименьших из них равно 6, а среднее арифметическое шести наибольших равно 12." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли наибольшее из этих десяти чисел равняться 14?" << endl
            << "    \\item Может ли среднее арифметическое всех десяти чисел равняться 8,4?" << endl
            << "    \\item Наидите наименьшее значение среднего арифметического всех десяти чисел." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item нет;нет;8,9 \n";

        //45
        cout << "\\item     С трёхзначным числом производят следующую операцию: вычитают из него сумму его цифр, а затем получившуюся разность делят на 3." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Могло ли в результате такой операции получиться число 300?" << endl
            << "    \\item Могло ли в результате такой операции получиться число 151?" << endl
            << "    \\item Сколько различных чисел может получиться в результате такой операции из чисел от 100 до 600 включительно?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да;нет;51 \n";
    }
    if(Type == 2)
    {
        type = rand()%45+1;
        switch(type)
        {
            //1
            case 1:
        cout << "\\item     С трёхзначным числом производят следующую операцию: к нему прибавляют цифру десятков, умноженную на 10, а затем к получившейся сумме прибавляют 3." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Могло ли в результате такой операции получиться число 224?" << endl
            << "    \\item Могло ли в результате такой операции получиться число 314?" << endl
            << "    \\item Найдите наибольшее отношение получившегося числа к исходному." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = "  \\item да 211; нет; 283/190 \n";
        break;
        
        //2
        case 2:
        cout << "\\item     В школах Nº1 и Nº2 учащиеся писали тест. Из каждой школы тест писали по крайней мере 2 учащихся, а суммарно тест писал 51 учащийся. Каждый учащийся, писавший тест, набрал натуральное количество баллов. Оказалось, что в каждой школе средний балл за тест был целым числом. После этого один из учащихся, писавших тест, перешёл из школы Nº1 в школу Nº2, а средние баллы за тест были пересчитаны в обеих школах." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Мог ли средний балл в школе Nº1 вырасти в 2 раза?" << endl
            << "    \\item Средний балл в школе Nº1 вырос на 10\\%, средний балл в школе Nº2 также вырос на 10\\%. Мог ли первоначальный средний балл в школе Nº2 равняться 1?" << endl
            << "    \\item Средний балл в школе Nº1 вырос на 10\\%, средний балл в школе Nº2 также вырос на 10\\%. Найдите наименьшее значение первоначального среднего балла в школе Nº2." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item нет; нет; 3 \n";
        break;
        //3
        case 3:
        cout << "\\item     На доске написано 30 различных натуральных чисел, десятичная запись каждого из которых оканчивается или на цифру 2, или на цифру 6. Сумма написанных чисел равна 2454." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли на доске быть поровну чисел, оканчивающихся на 2 и на 6?" << endl
            << "    \\item Может ли ровно одно число на доске оканчиваться на 6?" << endl
            << "    \\item Какое наименьшее количество чисел, оканчивающихся на б, может быть на доске?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
       Answer = Answer + "  \\item нет;нет; 11 \n";
        break;

        //4
        case 4:
        cout << "\\item     Есть три коробки: в первой коробке 97 камней, во второй - 104, а в третьей коробке камней нет. За один ход берут по одному камню из любых двух коробок и кладут в оставшуюся. Сделали некоторое количество таких ходов." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Могло ли в первой коробке оказаться 97 камней, во второй — 89, а в третьей - 15?" << endl
            << "    \\item Мог ли в третьей коробке оказаться 201 камень?" << endl
            << "    \\item В первой коробке оказался 1 камень. Какое наибольшее число камней могло оказаться в третьей коробке?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; нет; 198 \n";
        break;

        //5
        case 5:
        cout << "\\item     По кругу расставлено N различных натуральных чисел, каждое из которых не превосходит 365. Сумма любых четырёх идущих подряд чисел делится на 4, а сумма любых трёх идущих подряд чисел нечётна." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли N быть равным 200?" << endl
            << "    \\item Может ли N быть равным 109?" << endl
            << "    \\item Найдите наибольшее значение N." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item нет; нет; 182 \n";
        break;
    
        //6
        case 6:
        cout << "\\item     Есть четыре коробки: в первой коробке 101 камень, во второй - 102, в третьей - 103, а в четвёртой коробке камней нет. За один ход берут по одному камню из любых трёх коробок и кладут в оставшуюся. Сделали некоторое количество таких ходов." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Могло ли в первой коробке оказаться 97 камней, во второй - 102, в третьей - 103, а в четвёртой — 4?" << endl
            << "    \\item Могло ли в четвёртой коробке оказаться 306 камней?" << endl
            << "    \\item Какое наибольшее число камней могло оказаться в первой коробке?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; нет; 303 \n";
        break;

        //7
        case 7:
        cout << "\\item     В порту имеются только заполненные контейнеры, масса каждого из которых равна 20 тонн или 60 тонн. В некоторых из этих контейнеров находится сахарный песок. Количество контейнеров с сахарным песком составляет 25\\% от общего количества контейнеров." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли масса контейнеров с сахарным песком составить 20\\% от общей массы всех контейнеров?" << endl
            << "    \\item Может ли масса контейнеров с сахарным песком составить 60\\% от общей массы всех контейнеров?" << endl
            << "    \\item Какую наименьшую долю (в процентах) может составить масса контейнеров с сахарным песком от общей массы всех контейнеров?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; нет; 10 \n";
        break;

        //8
        case 8:
        cout << "\\item     На доске написано несколько различных натуральных чисел, произведение любых двух из которых больше 60 и меньше 140." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли на доске быть 5 чисел?" << endl
            << "    \\item Может ли на доске быть 6 чисел?" << endl
            << "    \\item Какое наименьшее значение может принимать сумма чисел на доске, если их четыре?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
       Answer = Answer + "  \\item да; нет; 37 \n";
       break;

        //9
        case 9:
        cout << "\\item     В классе больше 10, но не больше 26 учащихся, а доля девочек не превышает 21\\%." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли в этом классе быть 5 девочек?" << endl
            << "    \\item Может ли доля девочек составить 30\\%, если в этот класс придёт новая девочка?" << endl
            << "    \\item В этот класс пришла новая девочка. Доля девочек в классе составила целое число процентов. Какое наибольшее число процентов может составить доля девочек в классе?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; нет; 25 \n";
        break;

        //10
        case 10:
        cout << "\\item     Каждое из четырёх последовательных натуральных чисел, последние цифры которых не равны нулю, поделили на его последнюю цифру. Сумма получившихся чисел равна S." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли S быть равной $16\\frac{5}{6}$?" << endl
            << "    \\item Может ли S быть равной $569\\frac{29}{126}$?" << endl
            << "    \\item Найдите наибольшее целое значение S, если каждое из исходных чисел было трёхзначным." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; нет; 2004 \n";
        break;

        //11
        case 11:
        cout << "\\item     На доске написано 11 различных натуральных чисел. Среднее арифметическое шести наименьших из них равно 5, а среднее арифметическое шести наибольших равно 15." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли наименьшее из этих одиннадцати чисел равняться 3?" << endl
            << "    \\item Может ли среднее арифметическое всех одиннадцати чисел равняться 9?" << endl
            << "    \\item Пусть В - шестое по величине число, а S — среднее арифметическое всех одиннадцати чисел. Найдите наибольшее значение выражения S - B." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item нет; нет; 8 \n";
        break;

        //12
        case 12:
        cout << "\\item     На доске написано 30 различных натуральных чисел, каждое из которых либо чётное, либо его десятичная запись оканчивается на цифру 7. Сумма написанных чисел равна 810." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли на доске быть ровно 24 чётных числа?" << endl
            << "    \\item Могут ли ровно два числа на доске оканчиваться на 7?" << endl
            << "    \\item Какое наименьшее количество чисел, оканчивающихся на 7, может быть на доске?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; нет; 4 \n";
        break;

        //13
        case 13:
        cout << "\\item     На доске было написано несколько различных натуральных чисел. Эти числа разбили на три группы, в каждой из которых оказалось хотя бы одно число. К каждому числу из первой группы приписали справа цифру 1, к каждому числу из второй группы - цифру 8, а числа из третьей группы оставили без изменений." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Могла ли сумма всех этих чисел увеличиться в 4 раза?" << endl
            << "    \\item Могла ли сумма всех этих чисел увеличиться в 18 раз?" << endl
            << "    \\item Сумма всех этих чисел увеличилась в 11 раз. Какое наибольшее количество чисел могло быть написано на доске?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; нет; 10 \n";
        break;

        //14
        case 14:
        cout << "\\item     На доске написано 100 различных натуральных чисел, сумма которых равна 5120." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли оказаться, что на доске написано число 230?" << endl
            << "    \\item Может ли оказаться, что на доске нет числа 14?" << endl
            << "    \\item Какое наименьшее количество чисел, кратных 14, может быть на доске?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item нет; нет; 4 \n";
        break;

        //15
        case 15:
        cout << "\\item     Тройку различных натуральных чисел назовём удачной, если любое число в ней хотя бы на 5 больше, чем треть суммы двух других чисел. Например, 40, 45, 50 — удачная тройка." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Сколько существует удачных троек, содержащих числа 50, 60 и ещё одно число, большее 60?" << endl
            << "    \\item Найдётся ли удачная тройка, одно из чисел которой равно 15?" << endl
            << "    \\item Какое наибольшее количество чисел от 1 до 100 включительно можно расставить по кругу так, чтобы каждое число встречалось не более одного раза и любые три подряд идущих числа образовывали удачную тройку?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
       Answer = Answer + "  \\item да 15; нет; 29 \n";
        break;

        //16
        case 16:
        cout << "\\item     На доске написано и единиц подряд. Между некоторыми из них расставляют знаки «+» и считают получившуюся сумму. Например, если было написано 10 единиц, то можно получить сумму 136: $1+1+111+11+11+1=136$" << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Можно ли получить сумму 132, если п=60?" << endl
            << "    \\item Можно ли получить сумму 132, если n = 80 ?" << endl
            << "    \\item Для скольких значений п можно получить сумму 132?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; нет; 14 \n";
        break;

        //17
        case 17:
        cout << "\\item     В порту имеются только заполненные контейнеры, масса каждого из которых равна 20 тонн или 60 тонн. В некоторых из этих контейнеров находится сахарный песок. Количество контейнеров с сахарным песком составляет 75\\% от общего количества контейнеров." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли масса контейнеров с сахарным песком составить 80\\% от общей массы всех контейнеров?" << endl
            << "    \\item Может ли масса контейнеров с сахарным песком составить 40\\% от общей массы всех контейнеров?" << endl
            << "    \\item Какую наибольшую долю (в процентах) может составить масса контейнеров с сахарным песком от общей массы всех контейнеров?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; нет; 90 \n";
        break;

        //18
        case 18:
        cout << "\\item     В школах Nº1 и Nº2 учащиеся писали тест. Из каждой школы тест писали по крайней мере 2 учащихся. Каждый учащийся, писавший тест, набрал натуральное количество баллов. Оказалось, что в каждой школе средний балл за тест был целым числом, причём в школе Nº2 средний балл равнялся 42. Один из учащихся, писавших тест, перешёл из школы Nº1 в школу Nº2, а средние баллы за тест были пересчитаны в обеих школах. В результате средний балл в школе Nº1 уменьшился на 10\\%, средний балл в школе Nº2 также уменьшился на 10\\%." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Сколько учащихся могло писать тест в школе Nº2 изначально?" << endl
            << "    \\item Каждый учащийся школы Nº2, писавший тест, набрал больше баллов, чем перешедший в неё учащийся школы Nº 1. Какое наибольшее количество баллов мог набрать учащийся школы Nº2?" << endl
            << "    \\item Какое наибольшее количество учащихся могло писать тест в школе Nº1 изначально?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item 4; 102; 12 \n";
        break;

        //19
        case 19:
        cout << "\\item     На доске написано несколько различных натуральных чисел, произведение любых двух из которых больше 40 и меньше 100." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли на доске быть 5 чисел?" << endl
            << "    \\item Может ли на доске быть 6 чисел?" << endl
            << "    \\item Какое наибольшее значение может принимать сумма чисел на доске, если их четыре?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; нет; 35 \n";
        break;

        //20
        case 20:
        cout << "\\item     На доске написано и единиц подряд. Между некоторыми из них расставляют знаки «t» и считают получившуюся сумму. Например, если было написано 10 единиц, то можно получить сумму 136: $1+1+111+11+11+1=136$" << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Можно ли получить сумму 113, если п = 50?" << endl
            << "    \\item Можно ли получить сумму 114, если п= 50?" << endl
            << "    \\item Какую наибольшую четырёхзначную сумму можно получить, если п = 50?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; нет; 9554 \n";
        break;

        //21
        case 21:
        cout << "\\item     В школах Nº1 и Nº2 учащиеся писали тест. Из каждой школы тест писали по крайней мере 2 учащихся. Каждый учащийся, писавший тест, набрал натуральное количество баллов. Оказалось, что в каждой школе средний балл за тест был целым числом, причём в школе Nº1 средний балл равнялся 18. Один из учащихся, писавших тест, перешёл из школы Nº1 в школу Nº2, а средние баллы за тест были пересчитаны в обеих школах. В результате средний балл в школе Nº1 вырос на 10\\%, средний балл в школе Nº2 также вырос на 10\\%." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Сколько учащихся могло писать тест в школе Nº1 изначально?" << endl
            << "    \\item В школе Nº1 все писавшие тест набрали разное количество баллов. Какое наибольшее количество баллов мог набрать учащийся этой школы?" << endl
            << "    \\item Известно, что изначально в школе Nº2 писали тест более 10 учащихся. Какое наименьшее количество учащихся могло писать тест в школе Nº2 изначально?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
       Answer = Answer + "  \\item 6, 89, 19 \n";
       break;

        //22
        case 22:
        cout << "\\item     На доске написано 10 различных натуральных чисел. Среднее арифметическое шести наименьших из них равно 5, а среднее арифметическое шести наибольших равно 15." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли наименьшее из этих десяти чисел равняться 3?" << endl
            << "    \\item Может ли среднее арифметическое всех десяти чисел равняться 11?" << endl
            << "    \\item Найдите наибольшее значение среднего арифметического всех десяти чисел." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item нет; нет; 10,5 \n";
        break;

        //23
        case 23:
        cout << "\\item     В школах Nº1 и Nº2 учащиеся писали тест. Из каждой школы тест писали по крайней мере 2 учащихся, а суммарно тест писали 9 учащихся. Каждый учащийся, писавший тест, набрал натуральное количество баллов. Оказалось, что в каждой школе средний балл за тест был целым числом. После этого один из учащихся, писавших тест, перешёл из школы Nº1 в школу Nº2, а средние баллы за тест были пересчитаны в обеих школах." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Мог ли средний балл в школе Nº1 уменьшиться в 10 раз?" << endl
            << "    \\item Средний балл в школе Nº1 уменьшился на 10\\%, средний балл в школе Nº2 также уменьшился на 10\\%. Мог ли первоначальный средний балл в школе Nº2 равняться 7?" << endl
            << "    \\item Средний балл в школе Nº1 уменьшился на 10\\%, средний балл в школе Nº2 также уменьшился на 10\\%. Найдите наименьшее значение первоначального среднего балла в школе Nº2." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
       Answer = Answer + "  \\item да; нет; 5 \n";
       break;

        //24
        case 24:
        cout << "\\item     Из пары натуральных чисел $(a; b)$ за один ход можно получить пару $(a + 2; b - 1)$ или $(a - 1; b + 2)$ при условии, что оба числа в новой паре положительны. Сначала есть пара $(5; 7)$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Можно ли за 50 таких ходов получить пару, в которой одно из чисел равно 100?" << endl
            << "    \\item За какое число ходов получится пара, сумма чисел в которой равна 400?" << endl
            << "    \\item Какое наибольшее число ходов можно сделать так, чтобы после каждого хода оба числа в паре не превосходили 100?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item нет; 388; 187 \n";
        break;

        //25
        case 25:
        cout << "\\item     Для чисел А и В, состоящих из одинакового количества цифр, вычисляют s - сумму произведений соответствующих цифр. Например, для чисел А = 123 и В = 579 получается сумма $S=1\\cdot5+2\\cdot7+3\\cdot9=46$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Существуют ли трёхзначные числа А и В, для которых S = 200?" << endl
            << "    \\item Существуют ли четырёхзначные числа А и В, для которых S = 320?" << endl
            << "    \\item Верно ли, что любое натуральное число от 1 до 340 является суммой S для некоторых пятизначных чисел А и В?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; нет; да \n";
        break;

        //26
        case 26:
        cout << "\\item     По кругу расставлено N различных натуральных чисел, каждое из которых не превосходит 400. Сумма любых четырёх идущих подряд чисел делится на 3, а сумма любых трёх идущих подряд чисел не делится на 3." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли N быть равным 360?" << endl
            << "    \\item Может ли N быть равным 149?" << endl
            << "    \\item Найдите наибольшее значение N." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
       Answer = Answer + "  \\item нет; нет; 266 \n";
       break;

        //27
        case 27:
        cout << "\\item     На доске написано несколько различных натуральных чисел, в записи которых могут быть только цифры 4 и 9 (возможно, только одна из этих цифр)." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли сумма этих чисел быть равна 107?" << endl
            << "    \\item Может ли сумма этих чисел быть равна 289?" << endl
            << "    \\item Какое наименьшее количество чисел может быть на доске, если их сумма равна 3986?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; нет; 9 \n";
        break;

        //28
        case 28:
        cout << "\\item     На доске написано 30 натуральных чисел (числа могут повторяться), каждое из которых либо зелёного, либо красного цвета. Каждое зелёное число кратно 3, а каждое красное число кратно 7. При этом все зелёные числа различны и все красные различны (какое-то зелёное число может равняться какому-то красному числу)." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли сумма написанных чисел быть меньше $1395 = 3 + 6 + \\ldots + 90$, если все числа на доске кратны 3?" << endl
            << "    \\item Может ли ровно одно число на доске быть красным, если сумма написанных чисел равна 1067?" << endl
            << "    \\item Какое наименьшее количество красных чисел может быть на доске, если сумма написанных чисел равна 1067?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; нет; 6 \n";
        break;

        //29
        case 29:
        cout << "\\item     Есть 16 монет по 2 рубля и 29 монет по 5 рублей." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Можно ли этими монетами набрать сумму 175 рублей?" << endl
            << "    \\item Можно ли этими монетами набрать сумму 176 рублей?" << endl
            << "    \\item Какое наименьшее количество монет, каждая по 1 рублю, нужно добавить, чтобы иметь возможность набрать любую целую сумму от 1 рубля до 180 рублей включительно?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; нет; 3 \n";
        break;

        //30
        case 30:
        cout << "\\item     Маша и Наташа делали фотографии в течение некоторого количества подряд идущих дней. В первый день Маша сделала m фотографий, а Наташа — n фотографий. В каждый следующий день каждая из девочек делала на одну фотографию больше, чем в предыдущий день. Известно, что Наташа за всё время сделала суммарно на 1001 фотографию больше, чем Маша, и что фотографировали они больше одного дня." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Могли ли они фотографировать в течение 7 дней?" << endl
            << "    \\item Могли ли они фотографировать в течение 8 дней?" << endl
            << "    \\item Какое наибольшее суммарное число фотографий могла сделать Наташа за все дни фотографирования, если известно, что в последний день Маша сделала меньше 40 фотографий?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; нет; 1430 \n";
        break;

        //31
        case 31:
        cout << "\\item     По окружности в некотором порядке расставлены натуральные числа от 1 до 12. Между каждыми двумя соседними числами написали модуль их разности. Затем исходные числа стёрли." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Приведите пример расстановки, когда сумма полученных чисел равна 32." << endl
            << "    \\item Может ли сумма полученных чисел быть равна 29?" << endl
            << "    \\item Какое наибольшее значение может принимать сумма полученных чисел?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
       Answer = Answer + "  \\item да; нет; 712 \n";
       break;

        //32
        case 32:
        cout << "\\item     В течение n дней каждый день на доску записывают натуральные числа, каждое из которых меньше 6. При этом каждый день (кроме первого) сумма чисел, записанных на доску в этот день, больше, а количество меньше, чем в предыдущий день." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли n быть больше 6?" << endl
            << "    \\item Может ли среднее арифметическое чисел, записанных в первый день, быть меньше 2, а среднее арифметическое всех чисел, записанных за все дни, быть больше 4?" << endl
            << "    \\item Известно, что сумма чисел, записанных в первый день, равна 5. Какое наибольшее значение может принимать сумма всех чисел, записанных за все дни?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; да; 34 \n";
        break;

        //33
        case 33:
        cout << "\\item     Из набора цифр 0, 1, 2, 3, 5, 7 и 9 составляют пару чисел, используя каждую цифру ровно один раз. Оказалось, что одно из этих чисел четырёхзначное, другое — трёхзначное и оба кратны 45." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли сумма такой пары чисел равняться 2205?" << endl
            << "    \\item Может ли сумма такой пары чисел равняться 3435?" << endl
            << "    \\item Какое наибольшее значение может принимать сумма чисел в такой паре?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; нет; 10035 \n";
        break;

        //34
        case 34:
        cout << "\\item     В течение и дней каждый день на доску записывают натуральные числа, каждое из которых меньше 6. При этом каждый день (кроме первого) сумма чисел, записанных на доску в этот день, больше, а количество меньше, чем в предыдущий день." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли п быть больше 5?" << endl
            << "    \\item Может ли среднее арифметическое чисел, записанных в первый день, быть меньше 3, а среднее арифметическое всех чисел, записанных за все дни, быть больше 4?" << endl
            << "    \\item Известно, что сумма чисел, записанных в первый день, равна 6. Какое наибольшее значение может принимать сумма всех чисел, записанных за все дни?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; да; 48 \n";
        break;

        //35
        case 35:
        cout << "\\item     На доске написано несколько различных натуральных чисел, произведение любых двух из которых больше 25 и меньше 85." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли на доске быть 5 чисел?" << endl
            << "    \\item Может ли на доске быть 6 чисел?" << endl
            << "    \\item Какое наибольшее значение может принимать сумма чисел на доске, если их четыре?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; нет; 31 \n";
        break;

        //36
        case 36:
        cout << "\\item     Деревянную линейку, длина которой выражается целым числом сантиметров, разрезают на куски. За один ход можно взять один или несколько кусков линейки, положить их друг на друга и разрезать каждый из них на две части, длины которых выражаются целые числом сантиметров." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Можно ли за четыре хода разрезать линейку длиной 16 см на куски длиной 1 см?" << endl
            << "    \\item Можно ли за пять ходов разрезать линейку длиной 100 см на куски длиной 1 см?" << endl
            << "    \\item Какое наименьшее число ходов нужно сделать, чтобы разрезать линейку длиной 200 см на куски длиной 1 см?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; нет; 8 \n";
        break;

        //37
        case 37:
        cout << "\\item     Есть 4 камня, каждый массой 7 тонн, и 9 камней, каждый массой 22 тонны." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Можно ли разложить все эти камни на две группы так, чтобы разность суммарных масс камней в этих группах составила 8 тонн?" << endl
            << "    \\item Можно ли разложить все эти камни на две группы, суммарные массы камней в которых равны?" << endl
            << "    \\item Все камни хотят разложить на две группы. Какое наименьшее положительное значение (в тоннах) может принимать разность суммарных масс камней в этих группах?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
       Answer = Answer + "  \\item да; нет; 6 \n";
       break;

        //38
        case 38:
        cout << "\\item     Из правильной несократимой дроби $\\frac{a}{b}$, где $a$ и $b$ — натуральные числа, за один ход получают дробь $\\frac{a+b}{2a+b}$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Можно ли за несколько таких ходов из дроби $\\frac{1}{3}$ получить дробь $\\frac{22}{31}$?" << endl
            << "    \\item Можно ли за два таких хода из некоторой дроби получить дробь $\\frac{7}{12}$?" << endl
            << "    \\item Несократимая дробь $\\frac{c}{d}$ больше 0,7. Найдите наименьшую дробь $\\frac{c}{d}$, которую нельзя получить ни из какой правильной несократимой дроби за два таких хода?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; нет; 5/7 \n";
        break;

        //39
        case 39:
        cout << "\\item     На доске написано несколько различных натуральных чисел, произведение любых двух из которых больше 45 и меньше 120." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли на доске быть 5 чисел?" << endl
            << "    \\item Может ли на доске быть 6 чисел?" << endl
            << "    \\item Какое наименьшее значение может принимать сумма чисел на доске, если их четыре?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; нет; 33 \n";

        //40
        case 40:
        cout << "\\item     Ваня написал на доске трёхзначное число А. Петя переписал это число А, вычеркнул из него одну цифру и получил двузначное число В. Коля тоже переписал это число А, вычеркнул из него одну цифру (возможно, ту же самую, что и Петя) и получил двузначное число С." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли быть верным равенство $A = B\\cdot C$, если $A>150$?" << endl
            << "    \\item Может ли быть верным равенство $A = B\\cdot C$, если $540 \\leq A < 600$?" << endl
            << "    \\item в) Найдите наибольшее число А, для которого может быть верным равенство $A = B\\cdot C$." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
       Answer = Answer + "  \\item да; нет; 910 \n";
       break;

        //41
        case 41:
        cout << "\\item     Из пары натуральных чисел $(a;b)$ , где $a > b$ , за один ход получают пару $(a+b;a-b)$." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Можно ли за несколько таких ходов получить из пары (100;1) пару, большее число в которой равно 400?" << endl
            << "    \\item Можно ли за несколько таких ходов получить из пары (100;1) пару (806; 788) ?" << endl
            << "    \\item Какое наименьшее $a$ может быть в паре (а; b) , из которой за несколько ходов можно получить пару (806; 788) ?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; нет; 403 \n";
        break;

        //42
        case 42:
        cout << "\\item     На доске было написано несколько различных натуральных чисел. Эти числа разбили на три группы, в каждой из которых оказалось хотя бы одно число. К каждому числу из первой группы приписали справа цифру 3, к каждому числу из второй группы — цифру 7, а числа из третьей группы оставили без изменений." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Могла ли сумма всех этих чисел увеличиться в 8 раз?" << endl
            << "    \\item Могла ли сумма всех этих чисел увеличиться в 17 раз?" << endl
            << "    \\item В какое наибольшее число раз могла увеличиться сумма всех этих чисел?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; нет; 232/21 \n";
        break;

        //43
        case 43:
        cout << "\\item     Над парами целых чисел проводится операция: из пары (а; b) получается пара (За + b; 3b - а)." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Можно ли из какой-то пары получить пару (5; 5)?" << endl
            << "    \\item Верно ли, что если пара (с; d) может быть получена из какой-то пары с помощью данной операции, то и пара (-d; с) тоже может быть получена из какой-то пары с помощью данной операции?" << endl
            << "    \\item Зададим расстояние между парами целых чисел (а; b) и (с; d) выражением $|a-c|+|b-d|$. Найдите наименьшее расстояние от пары (9; 2) до пары, полученной из какой-то пары с помощью данной операции." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; да; 3 \n";
        break;

        //44
        case 44:
        cout << "\\item     На доске написано 10 различных натуральных чисел. Среднее арифметическое шести наименьших из них равно 6, а среднее арифметическое шести наибольших равно 12." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Может ли наибольшее из этих десяти чисел равняться 14?" << endl
            << "    \\item Может ли среднее арифметическое всех десяти чисел равняться 8,4?" << endl
            << "    \\item Наидите наименьшее значение среднего арифметического всех десяти чисел." << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item нет; нет; 8,9 \n";
        break;

        //45
        case 45:
        cout << "\\item     С трёхзначным числом производят следующую операцию: вычитают из него сумму его цифр, а затем получившуюся разность делят на 3." << endl
            << "\\begin{enumerate}" << endl
            << "    \\item Могло ли в результате такой операции получиться число 300?" << endl
            << "    \\item Могло ли в результате такой операции получиться число 151?" << endl
            << "    \\item Сколько различных чисел может получиться в результате такой операции из чисел от 100 до 600 включительно?" << endl
            << "\\end{enumerate}" <<  endl << endl << endl; 
        Answer = Answer + "  \\item да; нет; 51 \n";
        break;
        }
    }
    return Answer;
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int count_task[70];              // Создает массив из номеров заданий
    for (int i = 0; i < 70; i++)     // Обнуляет количество заданий в номерах
        count_task[i] = 0;
    int choice = 0;
    string Answers = "";
    do {
        choice = main_menu();       // Выводит на экран главное меню
        switch (choice)
        {
        case 1:
            do {
                cout << "\033[2J\033[1;1H";
                cout << "Выберите темы:" << endl;
                cout << " Задание 1: Планиметрия (" << count_task[10] + count_task[11] + count_task[12] + count_task[13] + count_task[62] << ")" << endl;
                cout << " Задание 2: Векторы  (" << count_task[14] + count_task[63] << ")" << endl;
                cout << " Задание 3: Стереометрия  (" << count_task[15] + count_task[16] + count_task[17] + count_task[64] << ")" << endl;
                cout << " Задание 4: Простая теория вероятности  (" << count_task[4] + count_task[59] << ")" << endl;
                cout << " Задание 5: Сложная теория вероятности  (" << count_task[5] + count_task[60] << ")" << endl;
                cout << " Задание 6: Уравнения  (" << count_task[6] + count_task[7] + count_task[8] + count_task[9] + count_task[61] << ")" << endl;
                cout << " Задание 7: Вычисления и преобразования (" << count_task[0] + count_task[1] + count_task[2] + count_task[3] + count_task[58] << ")" << endl;
                cout << " Задание 8: Производная  (" << count_task[24] + count_task[68] << ")" << endl; 
                cout << " Задание 9: Задачи с прикладным содержанием  (" << count_task[19] + count_task[66] << ")" << endl;
                cout << " Задание 10: Текстовые задачи (" << count_task[20] + count_task[21] + count_task[22] + count_task[23] + count_task[67] << ")" << endl; 
                cout << " Задание 11: Графики  (" << count_task[18] + count_task[65] << ")" << endl;
                cout << " Задание 12: Максимальное и минимальное значение (" << count_task[25] + count_task[26] + count_task[27] + count_task[28] + count_task[69] << ")" << endl;
                cout << " Задание 13: Уравнения (" << count_task[29] + count_task[30] + count_task[31] + count_task[32] + count_task[33]  + count_task[34]  + count_task[35]  << ")" << endl;
                cout << " Задание 14. Стереометрические задачи (" << count_task[45] + count_task[46] + count_task[47] + count_task[48] << ")" << endl;
                cout << " Задание 15. Неравенства (" << count_task[36] + count_task[37] + count_task[38] + count_task[39] + count_task[40]  << ")" << endl;
                cout << " Задание 16. Экономические задачи (" << count_task[41] + count_task[42] + count_task[43] + count_task[44]  << ")" << endl;
                cout << " Задание 17. Планиметрические задачи (" << count_task[49] + count_task[50] + count_task[51] + count_task[52] << ")" << endl;
                cout << " Задание 18. Параметры (" << count_task[53] + count_task[54] + count_task[55] << ")"  << endl;
                cout << " Задание 19. Теория чисел (" << count_task[56] + count_task[57]  << ")" << endl << endl;
                cout << "69. Сгенерировать" << endl;
                cout << "0. Назад" << endl;
                cout << "Ваш выбор: ";
                cin >> choice;
                switch(choice)
                {
                case 7:
                    do{
                        cout << "\033[2J\033[1;1H";
                        cout << "Выберите темы:" << endl;
                        cout << "1. Степени и корни (" << count_task[0] << ")" << endl;
                        cout << "2. Логарифмы (" << count_task[1]  << ")" << endl;
                        cout << "3. Тригонометрия (" << count_task[2]  << ")" << endl;
                        cout << "4. Все целиком (" << count_task[3] << ")" << endl;
                        cout << "5. Все типы этого номера (" << count_task[58] << ")" << endl;
                        cout << endl  << "0. Назад" << endl;
                        cout << "Ваш выбор: ";
                        cin >> choice;
                        switch(choice)
                        {
                        case 1:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[0];
                            break;

                        case 2:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[1];
                            break;

                        case 3:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[2];
                            break;

                        case 4:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[3];
                            break;

                        case 5:
                            count_task[58] = 1;
                            break;
                        }
                    }while(choice != 0);
                    choice = -1;
                    break;

                case 4:
                    do{
                        cout << "\033[2J\033[1;1H";
                        cout << "Выберите темы:" << endl;
                        cout << "1. Произвольное количество (" << count_task[4] << ")" << endl;
                        cout << "2. Все типы этого номера (" << count_task[59] << ")" << endl;
                        cout << endl  << "0. Назад" << endl;
                        cout << "Ваш выбор: ";
                        cin >> choice;
                        switch(choice)
                        {
                        case 1:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[4];
                            break;

                        case 2:
                            count_task[59] = 1;
                            break;
                        }
                    }while(choice != 0);
                    choice = -1;
                    break;

                case 5:
                    do{
                        cout << "\033[2J\033[1;1H";
                        cout << "Выберите темы:" << endl;
                        cout << "1. Произвольное количество (" << count_task[5] << ")" << endl;
                        cout << "2. Все типы этого номера (" << count_task[60] << ")" << endl;
                        cout << endl  << "0. Назад" << endl;
                        cout << "Ваш выбор: ";
                        cin >> choice;
                        switch(choice)
                        {
                        case 1:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[5];
                            break;

                        case 2:
                            count_task[60] = 1;
                            break;
                        }
                    }while(choice != 0);
                    choice = -1;
                    break;

                case 6:
                    do{
                        cout << "\033[2J\033[1;1H";
                        cout << "Выберите темы:" << endl;
                        cout << "1. ИСД (" << count_task[6] << ")" << endl;
                        cout << "2. Показательные уравнения (" << count_task[7]  << ")" << endl;
                        cout << "3. Логарифмические уравнения (" << count_task[8]  << ")" << endl;
                        cout << "4. Все целиком (" << count_task[9] << ")" << endl;
                        cout << "5. Все типы этого номера (" << count_task[61] << ")" << endl;
                        cout << endl << "0. Назад" << endl;
                        cout << "Ваш выбор: ";
                        cin >> choice;
                        switch(choice)
                        {
                        case 1:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[6];
                            break;

                        case 2:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[7];
                            break;

                        case 3:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[8];
                            break;

                        case 4:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[9];
                            break;

                        case 5:
                            count_task[61] = 1;
                            break;
                        }
                    }while(choice != 0);
                    choice = -1;
                    break;

                case 1:
                    do{
                        cout << "\033[2J\033[1;1H";
                        cout << "Выберите темы:" << endl;
                        cout << "1. Треугольники (" << count_task[10] << ")" << endl;
                        cout << "2. Многоугольники (" << count_task[11]  << ")" << endl;
                        cout << "3. Окружности (" << count_task[12]  << ")" << endl;
                        cout << "4. Все целиком (" << count_task[13] << ")" << endl;
                        cout << "5. Все типы этого номера (" << count_task[62] << ")" << endl;
                        cout << endl << "0. Назад" << endl;
                        cout << "Ваш выбор: ";
                        cin >> choice;
                        switch(choice)
                        {
                        case 1:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[10];
                            break;

                        case 2:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[11];
                            break;

                        case 3:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[12];
                            break;

                        case 4:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[13];
                            break;
                        
                        case 5:
                            count_task[62] = 1;
                            break;
                        }
                    }while(choice != 0);
                    choice = -1;
                    break;

                case 2:
                    do{
                        cout << "\033[2J\033[1;1H";
                        cout << "Выберите темы:" << endl;
                        cout << "1. Произвольное количество (" << count_task[14] << ")" << endl;
                        cout << "2. Все типы этого номера (" << count_task[63] << ")" << endl;
                        cout << endl  << "0. Назад" << endl;
                        cout << "Ваш выбор: ";
                        cin >> choice;
                        switch(choice)
                        {
                        case 1:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[14];
                            break;

                        case 2:
                            count_task[63] = 1;
                            break;
                        }
                    }while(choice != 0);
                    choice = -1;
                    break;

                case 3:
                    do{
                        cout << "\033[2J\033[1;1H";
                        cout << "Выберите темы:" << endl;
                        cout << "1. Призмы (" << count_task[15] << ")" << endl;
                        cout << "2. Цилиндры (" << count_task[16]  << ")" << endl;
                        cout << "3. Все целиком (" << count_task[17] << ")" << endl;
                        cout << "4. Все типы этого номера (" << count_task[64] << ")" << endl;
                        cout << endl << "0. Назад" << endl;
                        cout << "Ваш выбор: ";
                        cin >> choice;
                        switch(choice)
                        {
                        case 1:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[15];
                            break;

                        case 2:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[16];
                            break;

                        case 3:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[17];
                            break;

                        case 4:
                            count_task[64] = 1;
                            break;
                        }
                    }while(choice != 0);
                    choice = -1;
                    break;

                case 11:
                    do{
                        cout << "\033[2J\033[1;1H";
                        cout << "Выберите темы:" << endl;
                        cout << "1. Все целиком (" << count_task[18] << ")" << endl;
                        cout << "2. Все типы этого номера (" << count_task[65] << ")" << endl;
                        cout << endl << "0. Назад" << endl;
                        cout << "Ваш выбор: ";
                        cin >> choice;
                        switch(choice)
                        {
                        case 1:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[18];
                            break;

                        case 2:
                            count_task[65] = 1;
                            break;
                        }
                    }while(choice != 0);
                    choice = -1;
                    break;

                case 9:
                    do{
                        cout << "\033[2J\033[1;1H";
                        cout << "Выберите темы:" << endl;
                        cout << "1. Все целиком (" << count_task[19] << ")" << endl;
                        cout << "2. Все типы этого номера (" << count_task[66] << ")" << endl;
                        cout << endl << "0. Назад" << endl;
                        cout << "Ваш выбор: ";
                        cin >> choice;
                        switch(choice)
                        {
                        case 1:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[19];
                            break;

                        case 2:
                            count_task[66] = 1;
                            break;
                        }
                    }while(choice != 0);
                    choice = -1;
                    break;

                case 10:
                    do{
                        cout << "\033[2J\033[1;1H";
                        cout << "Выберите темы:" << endl;
                        cout << "1. Задачи на проценты (" << count_task[20] << ")" << endl;
                        cout << "2. Задачи на совместную работу (" << count_task[21]  << ")" << endl;
                        cout << "3. Задачи на движение (" << count_task[22]  << ")" << endl;
                        cout << "4. Все целиком (" << count_task[23] << ")" << endl;
                        cout << "5. Все типы этого номера (" << count_task[67] << ")" << endl;
                        cout << endl << "0. Назад" << endl;
                        cout << "Ваш выбор: ";
                        cin >> choice;
                        switch(choice)
                        {
                        case 1:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[20];
                            break;

                        case 2:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[21];
                            break;

                        case 3:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[22];
                            break;

                        case 4:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[23];
                            break;

                        case 5:
                            count_task[67] = 1;
                            break;
                        }
                    }while(choice != 0);
                    choice = -1;
                    break;

                case 8:
                    do{
                        cout << "\033[2J\033[1;1H";
                        cout << "Выберите темы:" << endl;
                        cout << "1. Производное количество (" << count_task[24] << ")" << endl;
                        cout << "2. Все типы этого номера (" << count_task[68] << ")" << endl;
                        cout << endl << "0. Назад" << endl;
                        cout << "Ваш выбор: ";
                        cin >> choice;
                        switch(choice)
                        {
                        case 1:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[24];
                            break;

                        case 2:
                            count_task[68] = 1;
                            break;
                        }
                    }while(choice != 0);
                    choice = -1;
                    break;

                case 12:
                    do{
                        cout << "\033[2J\033[1;1H";
                        cout << "Выберите темы:" << endl;
                        cout << "1. Степенные функции (" << count_task[25] << ")" << endl;
                        cout << "2. Логарифмы и экспонента (" << count_task[26]  << ")" << endl;
                        cout << "3. Тригонометрические функции (" << count_task[27]  << ")" << endl;
                        cout << "4. Все целиком (" << count_task[28] << ")" << endl;
                        cout << "5. Все типы этого номера (" << count_task[69] << ")" << endl;
                        cout << endl << "0. Назад" << endl;
                        cout << "Ваш выбор: ";
                        cin >> choice;
                        switch(choice)
                        {
                        case 1:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[25];
                            break;

                        case 2:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[26];
                            break;

                        case 3:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[27];
                            break;

                        case 4:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[28];
                            break;

                        case 5:
                            count_task[69] = 1;
                            break;
                        }
                    }while(choice != 0);
                    choice = -1;
                    break;

                case 13:
                    do{
                        cout << "\033[2J\033[1;1H";
                        cout << "Выберите темы:" << endl;
                        cout << "1. Тип 1 (" << count_task[29] << ")" << endl;
                        cout << "2. Тип 2 (" << count_task[30]  << ")" << endl;
                        cout << "3. Тип 3 (" << count_task[31]  << ")" << endl;
                        cout << "4. Тип 4 (" << count_task[32] << ")" << endl;
                        cout << "5. Тип 5 (" << count_task[33]  << ")" << endl;
                        cout << "6. Тип 6 (" << count_task[34]  << ")" << endl;
                        cout << "7. Все целиком (" << count_task[35] << ")" << endl << endl;
                        cout << "0. Назад" << endl;
                        cout << "Ваш выбор: ";
                        cin >> choice;
                        switch(choice)
                        {
                        case 1:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[29];
                            break;

                        case 2:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[30];
                            break;

                        case 3:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[31];
                            break;

                        case 4:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[32];
                            break;

                        case 5:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[33];
                            break;

                        case 6:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[34];
                            break;

                        case 7:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[35];
                            break;
                        }
                    }while(choice != 0);
                    choice = -1;
                    break;

                case 15:
                    do{
                        cout << "\033[2J\033[1;1H";
                        cout << "Выберите темы:" << endl;
                        cout << "1. Тип 1 (" << count_task[36] << ")" << endl;
                        cout << "2. Тип 2 (" << count_task[37]  << ")" << endl;
                        cout << "3. Тип 3 (" << count_task[38]  << ")" << endl;
                        cout << "4. Тип 4 (" << count_task[39] << ")" << endl;
                        cout << "5. Все целиком (" << count_task[40] << ")" << endl << endl;
                        cout << "0. Назад" << endl;
                        cout << "Ваш выбор: ";
                        cin >> choice;
                        switch(choice)
                        {
                        case 1:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[36];
                            break;

                        case 2:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[37];
                            break;

                        case 3:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[38];
                            break;

                        case 4:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[39];
                            break;

                        case 5:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[40];
                            break;
                        }
                    }while(choice != 0);
                    choice = -1;
                    break;

                case 16:
                    do{
                        cout << "\033[2J\033[1;1H";
                        cout << "Выберите темы:" << endl;
                        cout << "1. Тип 1 (" << count_task[41] << ")" << endl;
                        cout << "2. Тип 2 (" << count_task[42]  << ")" << endl;
                        cout << "3. Тип 3 (" << count_task[43]  << ")" << endl;
                        cout << "4. Все целиком (" << count_task[44] << ")" << endl << endl;
                        cout << "0. Назад" << endl;
                        cout << "Ваш выбор: ";
                        cin >> choice;
                        switch(choice)
                        {
                        case 1:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[41];
                            break;

                        case 2:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[42];
                            break;

                        case 3:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[43];
                            break;

                        case 4:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[44];
                            break;
                        }
                    }while(choice != 0);
                    choice = -1;
                    break;

                case 14:
                    do{
                        cout << "\033[2J\033[1;1H";
                        cout << "Выберите темы:" << endl;
                        cout << "1. Призмы (" << count_task[45] << ")" << endl;
                        cout << "2. Пирамиды (" << count_task[46]  << ")" << endl;
                        cout << "3. Цилиндры и Конусы (" << count_task[47]  << ")" << endl;
                        cout << "4. Все целиком (" << count_task[48] << ")" << endl << endl;
                        cout << "0. Назад" << endl;
                        cout << "Ваш выбор: ";
                        cin >> choice;
                        switch(choice)
                        {
                        case 1:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[45];
                            break;

                        case 2:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[46];
                            break;

                        case 3:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[47];
                            break;

                        case 4:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[48];
                            break;
                        }
                    }while(choice != 0);
                    choice = -1;
                    break;

                case 17:
                    do{
                        cout << "\033[2J\033[1;1H";
                        cout << "Выберите темы:" << endl;
                        cout << "1. Треугольники (" << count_task[49] << ")" << endl;
                        cout << "2. Четырехугольники (" << count_task[50]  << ")" << endl;
                        cout << "3. Окружности (" << count_task[51]  << ")" << endl;
                        cout << "4. Все целиком (" << count_task[52] << ")" << endl << endl;
                        cout << "0. Назад" << endl;
                        cout << "Ваш выбор: ";
                        cin >> choice;
                        switch(choice)
                        {
                        case 1:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[49];
                            break;

                        case 2:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[50];
                            break;

                        case 3:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[51];
                            break;

                        case 4:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[52];
                            break;
                        }
                    }while(choice != 0);
                    choice = -1;
                    break;

                case 18:
                    do{
                        cout << "\033[2J\033[1;1H";
                        cout << "Выберите темы:" << endl;
                        cout << "1. Не системы (" << count_task[53] << ")" << endl;
                        cout << "2. Системы (" << count_task[54]  << ")" << endl;
                        cout << "3. Все целиком (" << count_task[55] << ")" << endl << endl;
                        cout << "0. Назад" << endl;
                        cout << "Ваш выбор: ";
                        cin >> choice;
                        switch(choice)
                        {
                        case 1:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[53];
                            break;

                        case 2:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[54];
                            break;

                        case 3:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[55];
                            break;
                        }
                    }while(choice != 0);
                    choice = -1;
                    break;

                case 19:
                    do{
                        cout << "\033[2J\033[1;1H";
                        cout << "Выберите темы:" << endl;
                        cout << "1. Целиком (" << count_task[56] << ")" << endl;
                        cout << "2. Произвольное количество (" << count_task[57] << ")" << endl << endl;
                        cout << "0. Назад" << endl;
                        cout << "Ваш выбор: ";
                        cin >> choice;
                        switch(choice)
                        {
                        case 1:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[56];
                            break;

                        case 2:
                            cout << "\033[2J\033[1;1H";
                            cout << "Введите количество заданий: ";
                            cin >> count_task[57];
                            break;
                        }
                    }while(choice != 0);
                    choice = -1;
                    break;

                case 69:
                    cout << "\033[2J\033[1;1H";
                    int Count = 0;
                    if (count_task[0] != 0)
                    {
                        for (int i = 0; i < count_task[0]; i++)
                        {
                            Answers = Answers + StepKoren(0);
                            Count++;
                        }
                        count_task[0] = 0;
                    }
                    if (count_task[1] != 0)
                    {
                        for (int i = 0; i < count_task[1]; i++)
                        {
                            Answers = Answers + LogCount(0);
                            Count++;
                        }
                        count_task[1] = 0;
                    }
                    if (count_task[2] != 0)
                    {
                        for (int i = 0; i < count_task[2]; i++)
                        {
                            Answers = Answers + TrigonomCount(0);
                            Count++;
                        }
                        count_task[2] = 0;
                    }
                    if (count_task[3] != 0)
                    {
                        for (int i = 0; i < count_task[3]; i++)
                        {
                            int z = rand()%3+1;
                            switch(z)
                            {
                            case 1:
                                Answers = Answers + StepKoren(0);
                                Count++;
                                break;

                            case 2:
                                Answers = Answers + LogCount(0);
                                Count++;
                                break;

                            case 3:
                                Answers = Answers + TrigonomCount(0);
                                Count++;
                                break;
                            }
                        }
                        count_task[3] = 0;
                    }
                    if (count_task[4] != 0)
                    {
                        for (int i = 0; i < count_task[4]; i++)
                        {
                            Answers = Answers + TeorFerSimpl(0);
                            Count++;
                        }
                        count_task[4] = 0;
                    }
                    if (count_task[5] != 0)
                    {
                        for (int i = 0; i < count_task[5]; i++)
                        {
                            Answers = Answers + TeorFerDif(0);
                            Count++;
                        }
                        count_task[5] = 0;
                    }
                    if (count_task[6] != 0)
                    {
                        for (int i = 0; i < count_task[6]; i++)
                        {
                            Answers = Answers + ISDUravn(0);
                            Count++;
                        }
                        count_task[6] = 0;
                    }
                    if (count_task[7] != 0)
                    {
                        for (int i = 0; i < count_task[7]; i++)
                        {
                            Answers = Answers + PokUravn(0);
                            Count++;
                        }
                        count_task[7] = 0;
                    }
                    if (count_task[8] != 0)
                    {
                        for (int i = 0; i < count_task[8]; i++)
                        {
                            Answers = Answers + LogUravn(0);
                            Count++;
                        }
                        count_task[8] = 0;
                    }
                    if (count_task[9] != 0)
                    {
                        for (int i = 0; i < count_task[9]; i++)
                        {
                            int z = rand()%3+1;
                            switch(z)
                            {
                            case 1:
                                Answers = Answers + ISDUravn(0);
                                Count++;
                                break;

                            case 2:
                                Answers = Answers + PokUravn(0);
                                Count++;
                                break;

                            case 3:
                                Answers = Answers + LogUravn(0);
                                Count++;
                                break;
                            }
                        }
                        count_task[9] = 0;
                    }
                    if (count_task[10] != 0)
                    {
                        for (int i = 0; i < count_task[10]; i++)
                        {
                            Answers = Answers + Treugol(Count, 0);
                            Count++;
                        }
                        count_task[10] = 0;
                    }
                    if (count_task[11] != 0)
                    {
                        for (int i = 0; i < count_task[11]; i++)
                        {
                            Answers = Answers + Mnogougol(Count, 0);
                            Count++;
                        }
                        count_task[11] = 0;
                    }
                    if (count_task[12] != 0)
                    {
                        for (int i = 0; i < count_task[12]; i++)
                        {
                            Answers = Answers + Okrugn(Count, 0);
                            Count++;
                        }
                        count_task[12] = 0;
                    }
                    if (count_task[13] != 0)
                    {
                        for (int i = 0; i < count_task[13]; i++)
                        {
                            int z = rand()%3+1;
                            switch(z)
                            {
                            case 1:
                                Answers = Answers + Treugol(Count, 0);
                                Count++;
                                break;

                            case 2:
                                Answers = Answers + Mnogougol(Count, 0);
                                Count++;
                                break;

                            case 3:
                                Answers = Answers + Okrugn(Count, 0);
                                Count++;
                                break;
                            }
                        }
                        count_task[13] = 0;
                    }
                    if (count_task[14] != 0)
                    {
                        for (int i = 0; i < count_task[14]; i++)
                        {
                            Answers = Answers + Vector(Count, 0);
                            Count++;
                        }
                        count_task[14] = 0;
                    }
                    if (count_task[15] != 0)
                    {
                        for (int i = 0; i < count_task[15]; i++)
                        {
                            Answers = Answers + Prizm(Count, 0);
                            Count++;
                        }
                        count_task[15] = 0;
                    }
                    if (count_task[16] != 0)
                    {
                        for (int i = 0; i < count_task[16]; i++)
                        {
                            Answers = Answers + Cilindr(Count, 0);
                            Count++;
                        }
                        count_task[16] = 0;
                    }
                    if (count_task[17] != 0)
                    {
                        for (int i = 0; i < count_task[17]; i++)
                        {
                            int z = rand()%2+1;
                            switch(z)
                            {
                            case 1:
                                Answers = Answers + Prizm(Count, 0);
                                Count++;
                                break;

                            case 2:
                                Answers = Answers + Cilindr(Count, 0);
                                Count++;
                                break;
                            }
                        }
                        count_task[17] = 0;
                    }
                    if (count_task[18] != 0)
                    {
                        for (int i = 0; i < count_task[18]; i++)
                        {
                            Answers = Answers + Graphics(Count, 0);
                            Count++;
                        }
                        count_task[18] = 0;
                    }
                    if (count_task[19] != 0)
                    {
                        for (int i = 0; i < count_task[19]; i++)
                        {
                            Answers = Answers + ZadPricl(0);
                            Count++;
                        }
                        count_task[19] = 0;
                    }
                    if (count_task[20] != 0)
                    {
                        for (int i = 0; i < count_task[20]; i++)
                        {
                            Answers = Answers + ZadProc(0);
                            Count++;
                        }
                        count_task[20] = 0;
                    }
                    if (count_task[21] != 0)
                    {
                        for (int i = 0; i < count_task[21]; i++)
                        {
                            Answers = Answers + ZadRab(0);
                            Count++;
                        }
                        count_task[21] = 0;
                    }
                    if (count_task[22] != 0)
                    {
                        for (int i = 0; i < count_task[22]; i++)
                        {
                            Answers = Answers + ZadMove(0);
                            Count++;
                        }
                        count_task[22] = 0;
                    }
                    if (count_task[23] != 0)
                    {
                        for (int i = 0; i < count_task[23]; i++)
                        {
                            int z = rand()%3+1;
                            switch(z)
                            {
                            case 1:
                                Answers = Answers + ZadProc(0);
                                Count++;
                                break;

                            case 2:
                                Answers = Answers + ZadRab(0);
                                Count++;
                                break;

                            case 3:
                                Answers = Answers + ZadMove(0);
                                Count++;
                                break;
                            }
                        }
                        count_task[23] = 0;
                    }
                    if (count_task[24] != 0)
                    {
                        for (int i = 0; i < count_task[24]; i++)
                        {
                            Answers = Answers + Proizvodn(Count, 0);
                            Count++;
                        }
                        count_task[24] = 0;
                    }
                    if (count_task[25] != 0)
                    {
                        for (int i = 0; i < count_task[25]; i++)
                        {
                            Answers = Answers + ProizvStep(0);
                            Count++;
                        }
                        count_task[25] = 0;
                    }
                    if (count_task[26] != 0)
                    {
                        for (int i = 0; i < count_task[26]; i++)
                        {
                            Answers = Answers + ProizvLogEks(0);
                            Count++;
                        }
                        count_task[26] = 0;
                    }
                    if (count_task[27] != 0)
                    {
                        for (int i = 0; i < count_task[27]; i++)
                        {
                            Answers = Answers + ProizvTrigonom(0);
                            Count++;
                        }
                        count_task[27] = 0;
                    }
                    if (count_task[28] != 0)
                    {
                        for (int i = 0; i < count_task[28]; i++)
                        {
                            int z = rand()%3+1;
                            switch(z)
                            {
                            case 1:
                                Answers = Answers + ProizvStep(0);
                                Count++;
                                break;

                            case 2:
                                Answers = Answers + ProizvLogEks(0);
                                Count++;
                                break;

                            case 3:
                                Answers = Answers + ProizvTrigonom(0);
                                Count++;
                                break;
                            }
                        }
                        count_task[28] = 0;
                    }
                    if (count_task[29] != 0)
                    {
                        Answers = Answers + Uravn1(1);
                        count_task[29] = 0;
                    }
                    if (count_task[30] != 0)
                    {
                        Answers = Answers + Uravn2(1);
                        count_task[30] = 0;
                    }
                    if (count_task[31] != 0)
                    {
                        Answers = Answers + Uravn3(1);
                        count_task[31] = 0;
                    }
                    if (count_task[32] != 0)
                    {
                        Answers = Answers + Uravn4(1);
                        count_task[32] = 0;
                    }
                    if (count_task[33] != 0)
                    {
                        Answers = Answers + Uravn5(1);
                        count_task[33] = 0;
                    }
                    if (count_task[34] != 0)
                    {
                        Answers = Answers + Uravn6(1);
                        count_task[34] = 0;
                    }
                    if(count_task[35] != 0)
                    {
                        for (int i = 0; i < count_task[35]; i++)
                        {
                            int z = rand()%6+1;
                            switch(z)
                            {
                                case 1:
                                    Answers = Answers + Uravn1(2);
                                    break;
                                
                                case 2:
                                    Answers = Answers + Uravn2(2);
                                    break;

                                case 3:
                                    Answers = Answers + Uravn3(2);
                                    break;

                                case 4:
                                    Answers = Answers + Uravn4(2);
                                    break;

                                case 5:
                                    Answers = Answers + Uravn5(2);
                                    break;

                                case 6:
                                    Answers = Answers + Uravn6(2);
                                    break;

                            }
                        }
                        count_task[35] = 0;
                    }
                    if(count_task[36] != 0)
                    {
                        Answers = Answers + Nerav1(1);
                        count_task[36] = 0;
                    }
                    if(count_task[37] != 0)
                    {
                        Answers = Answers + Nerav2(1);
                        count_task[37] = 0;
                    }
                    if(count_task[38] != 0)
                    {
                        Answers = Answers + Nerav3(1);
                        count_task[38] = 0;
                    }
                    if(count_task[39] != 0)
                    {
                        Answers = Answers + Nerav4(1);
                        count_task[39] = 0;
                    }
                    if(count_task[40] != 0)
                    {
                        for (int i = 0; i < count_task[40]; i++)
                        {
                            int z = rand()%4+1;
                            switch(z)
                            {
                                case 1:
                                    Answers = Answers + Nerav1(2);
                                    break;
                                
                                case 2:
                                    Answers = Answers + Nerav2(2);
                                    break;

                                case 3:
                                    Answers = Answers + Nerav3(2);
                                    break;

                                case 4:
                                    Answers = Answers + Nerav4(2);
                                    break;
                            }
                        }
                        count_task[40] = 0;
                    }
                    if(count_task[41] != 0)
                    {
                        Answers = Answers + Finance1(1);
                        count_task[41] = 0;
                    }
                    if(count_task[42] != 0)
                    {
                        Answers = Answers + Finance2(1);
                        count_task[42] = 0;
                    }
                    if(count_task[43] != 0)
                    {
                        Answers = Answers + Finance3(1);
                        count_task[43] = 0;
                    }
                    if(count_task[44] != 0)
                    {
                        for (int i = 0; i < count_task[44]; i++)
                        {
                            int z = rand()%5+1;
                            switch(z)
                            {
                                case 1:
                                    Answers = Answers + Finance1(2);
                                    break;
                                
                                case 2:
                                    Answers = Answers + Finance2(2);
                                    break;

                                case 3:
                                    Answers = Answers + Finance3(2);
                                    break;

                                case 4:
                                    Answers = Answers + Finance3(2);
                                    break;

                                case 5:
                                    Answers = Answers + Finance3(2);
                                    break;
                            }
                        }
                        count_task[44] = 0;
                    }
                    if(count_task[45] != 0)
                    {
                        Answers = Answers + StereomPrizm(1);
                        count_task[45] = 0;
                    }
                    if(count_task[46] != 0)
                    {
                        Answers = Answers + StereomPiramid(1);
                        count_task[46] = 0;
                    }
                    if(count_task[47] != 0)
                    {
                        Answers = Answers + StereomCilindr(1);
                        count_task[47] = 0;
                    }
                    if(count_task[48] != 0)
                    {
                        for (int i = 0; i < count_task[48]; i++)
                        {
                            int z = rand()%3+1;
                            switch(z)
                            {
                                case 1:
                                    Answers = Answers + StereomPrizm(2);
                                    break;
                                
                                case 2:
                                    Answers = Answers + StereomPiramid(2);
                                    break;

                                case 3:
                                    Answers = Answers + StereomCilindr(2);
                                    break;

                            }
                        }
                        count_task[48] = 0;
                    }
                    if(count_task[49] != 0)
                    {
                        Answers = Answers + SecondTreugol(1);
                        count_task[49] = 0;
                    }
                    if(count_task[50] != 0)
                    {
                        Answers = Answers + SecondChetir(1);
                        count_task[50] = 0;
                    }
                    if(count_task[51] != 0)
                    {
                        Answers = Answers + SecondOkrug(1);
                        count_task[51] = 0;
                    }
                    if(count_task[52] != 0)
                    {
                        for (int i = 0; i < count_task[52]; i++)
                        {
                            int z = rand()%3+1;
                            switch(z)
                            {
                                case 1:
                                    Answers = Answers + SecondTreugol(2);
                                    break;
                                
                                case 2:
                                    Answers = Answers + SecondChetir(2);
                                    break;

                                case 3:
                                    Answers = Answers + SecondOkrug(2);
                                    break;

                            }
                        }
                        count_task[52] = 0;
                    }
                    if(count_task[53] != 0)
                    {
                        Answers = Answers + ParamN(1);
                        count_task[53] = 0;
                    }
                    if(count_task[54] != 0)
                    {
                        Answers = Answers + ParamS(1);
                        count_task[54] = 0;
                    }
                    if(count_task[55] != 0)
                    {
                        for (int i = 0; i < count_task[55]; i++)
                        {
                            int z = rand()%2+1;
                            switch(z)
                            {
                                case 1:
                                    Answers = Answers + ParamN(2);
                                    break;
                                
                                case 2:
                                    Answers = Answers + ParamS(2);
                                    break;
                            }
                        }
                        count_task[55] = 0;
                    }
                    if(count_task[56] != 0)
                    {
                        Answers = Answers + TeorChisl(1);
                        count_task[56] = 0;
                    }
                    if(count_task[57] != 0)
                    {
                        for (int i = 0; i < count_task[57]; i++)
                        {
                            Answers = Answers + TeorChisl(2);
                        }
                        count_task[57] = 0;
                    }
                    if(count_task[58] != 0)
                    {
                        for(int i = 1; i <= 10; i++)
                            Answers = Answers + StepKoren(i);
                        for(int i = 1; i <= 4; i++)
                            Answers = Answers + LogCount(i);
                        for(int i = 1; i <= 7; i++)
                            Answers = Answers + TrigonomCount(i);
                        count_task[58] = 0;
                    }
                    if(count_task[59] != 0)
                    {
                        for(int i = 1; i <= 9; i++)
                            Answers = Answers + TeorFerSimpl(i);
                        count_task[59] = 0;
                    }
                    if(count_task[60] != 0)
                    {
                        for(int i = 1; i <= 14; i++)
                            Answers = Answers + TeorFerDif(i);
                        count_task[60] = 0;
                    }
                    if(count_task[61] != 0)
                    {
                        for(int i = 1; i <= 4; i++)
                            Answers = Answers + ISDUravn(i);
                        for(int i = 1; i <= 5; i++)
                            Answers = Answers + PokUravn(i);
                        for(int i = 1; i <= 4; i++)
                            Answers = Answers + LogUravn(i);
                        count_task[61] = 0;
                    }
                    if(count_task[62] != 0)
                    {
                        for(int i = 1; i <= 5; i++)
                        {
                            Answers = Answers + Treugol(Count, i);
                            Count++;
                        }
                        for(int i = 1; i <= 3; i++)
                        {
                            Answers = Answers + Mnogougol(Count, i);
                            Count++;
                        }
                        for(int i = 1; i <= 10; i++)
                        {
                            Answers = Answers + Okrugn(Count, i);
                            Count++;
                        }
                        count_task[62] = 0;
                    }
                    if(count_task[63] != 0)
                    {
                        for(int i = 1; i <= 5; i++)
                        {
                            Answers = Answers + Vector(Count, i);
                            Count++;
                        }
                        count_task[63] = 0;
                    }
                    if(count_task[64] != 0)
                    {
                        for(int i = 1; i <= 9; i++)
                        {
                            Answers = Answers + Prizm(Count, i);
                            Count++;
                        }
                        for(int i = 1; i <= 7; i++)
                        {
                            Answers = Answers + Cilindr(Count, i);
                            Count++;
                        }
                        count_task[64] = 0;
                    }
                    if(count_task[65] != 0)
                    {
                        for(int i = 1; i <= 9; i++)
                        { 
                            Answers = Answers + Graphics(Count, i);
                            Count++;
                        }
                        count_task[65] = 0;
                    }
                    if(count_task[66] != 0)
                    {
                        for(int i = 1; i <= 20; i++)
                        { 
                            Answers = Answers + ZadPricl(i);
                            Count++;
                        }
                        count_task[66] = 0;
                    }
                    if(count_task[67] != 0)
                    {
                        for(int i = 1; i <= 3; i++)
                        { 
                            Answers = Answers + ZadProc(i);
                            Count++;
                        }
                        for(int i = 1; i <= 7; i++)
                        { 
                            Answers = Answers + ZadRab(i);
                            Count++;
                        }
                        for(int i = 1; i <= 13; i++)
                        { 
                            Answers = Answers + ZadMove(i);
                            Count++;
                        }
                        count_task[67] = 0;
                    }
                    if(count_task[68] != 0)
                    {
                        for(int i = 1; i <= 8; i++)
                        { 
                            Answers = Answers + Proizvodn(Count, i);
                            Count++;
                        }
                        count_task[68] = 0;
                    }
                    if(count_task[69] != 0)
                    {
                        for(int i = 1; i <= 4; i++)
                        { 
                            Answers = Answers + ProizvStep(i);
                            Count++;
                        }
                        for(int i = 1; i <= 5; i++)
                        { 
                            Answers = Answers + ProizvLogEks(i);
                            Count++;
                        }
                        for(int i = 1; i <= 4; i++)
                        { 
                            Answers = Answers + ProizvTrigonom(i);
                            Count++;
                        }
                        count_task[69] = 0;
                    }
                    cout << "}" << endl << "\\end{enumerate}" << endl << "\\newpage \n {\\centering \\subsubsection*{Ответы}} \n \\begin{enumerate} \n" << Answers << endl << "\\end{enumerate}" << endl << endl;
                    Answers = "";
                    cout << "0. Назад" << endl;
                    cout << "Ваш выбор: ";
                    cin >> choice;
                    choice = -1;
                    break;
                }
            } while (choice != 0);
            choice = -1;
            break;

    case 2:
        do{
            cout << "\033[2J\033[1;1H";
            int Count = 0;
            for (int i = 0; i < 1; i++)
                        {
                            int z = rand()%3+1;
                            switch(z)
                            {
                            case 1:
                                Answers = Answers + Treugol(Count, 0);
                                Count++;
                                break;

                            case 2:
                                Answers = Answers + Mnogougol(Count, 0);
                                Count++;
                                break;

                            case 3:
                                Answers = Answers + Okrugn(Count, 0);
                                Count++;
                                break;
                            }
                        }
            for (int i = 0; i < 1; i++)
                        {
                            Answers = Answers + Vector(Count, 0);
                            Count++;
                        }
            for (int i = 0; i < 1; i++)
                        {
                            int z = rand()%2+1;
                            switch(z)
                            {
                            case 1:
                                Answers = Answers + Prizm(Count, 0);
                                Count++;
                                break;

                            case 2:
                                Answers = Answers + Cilindr(Count, 0);
                                Count++;
                                break;
                            }
                        }
            for (int i = 0; i < 1; i++)
                        {
                            Answers = Answers + TeorFerSimpl(0);
                            Count++;
                        }
            for (int i = 0; i < 1; i++)
                        {
                            Answers = Answers + TeorFerDif(0);
                            Count++;
                        }
            for (int i = 0; i < 1; i++)
                        {
                            int z = rand()%3+1;
                            switch(z)
                            {
                            case 1:
                                Answers = Answers + ISDUravn(0);
                                Count++;
                                break;

                            case 2:
                                Answers = Answers + PokUravn(0);
                                Count++;
                                break;

                            case 3:
                                Answers = Answers + LogUravn(0);
                                Count++;
                                break;
                            }
                        }
            for (int i = 0; i < 1; i++)
                        {
                            int z = rand()%3+1;
                            switch(z)
                            {
                            case 1:
                                Answers = Answers + StepKoren(0);
                                Count++;
                                break;

                            case 2:
                                Answers = Answers + LogCount(0);
                                Count++;
                                break;

                            case 3:
                                Answers = Answers + TrigonomCount(0);
                                Count++;
                                break;
                            }
                        }
            for (int i = 0; i < 1; i++)
                        {
                            cout << "\\newpage" << endl;
                            Answers = Answers + Proizvodn(Count, 0);
                            Count++;
                        }
            for (int i = 0; i < 1; i++)
                        {
                            Answers = Answers + ZadPricl(0);
                            Count++;
                        }
            for (int i = 0; i < 1; i++)
                        {
                            int z = rand()%3+1;
                            switch(z)
                            {
                            case 1:
                                Answers = Answers + ZadProc(0);
                                Count++;
                                break;

                            case 2:
                                Answers = Answers + ZadRab(0);
                                Count++;
                                break;

                            case 3:
                                Answers = Answers + ZadMove(0);
                                Count++;
                                break;
                            }
                        }
            for (int i = 0; i < 1; i++)
                        {
                            Answers = Answers + Graphics(Count, 0);
                            Count++;
                        }
            for (int i = 0; i < 1; i++)
                        {
                            int z = rand()%3+1;
                            switch(z)
                            {
                            case 1:
                                Answers = Answers + ProizvStep(0);
                                Count++;
                                break;

                            case 2:
                                Answers = Answers + ProizvLogEks(0);
                                Count++;
                                break;

                            case 3:
                                Answers = Answers + ProizvTrigonom(0);
                                Count++;
                                break;
                            }
                        }
            
            cout << "}" << endl << "\\end{enumerate}" << endl << "\\newpage \n {\\centering \\subsubsection*{Ответы}} \n \\begin{enumerate} \n" << Answers << endl << "\\end{enumerate}" << endl << endl;
            Answers = "";
            cout << "0. Назад" << endl;
            cout << "Ваш выбор: ";
            cin >> choice;
            choice = -1;
            break;
        }while(choice != 0);
        choice = -1;
        break;

    case 3:
        do{
            cout << "\033[2J\033[1;1H";
            int Count = 0;
            for (int i = 0; i < 1; i++)
                        {
                            int z = rand()%3+1;
                            switch(z)
                            {
                            case 1:
                                Answers = Answers + Treugol(Count, 0);
                                Count++;
                                break;

                            case 2:
                                Answers = Answers + Mnogougol(Count, 0);
                                Count++;
                                break;

                            case 3:
                                Answers = Answers + Okrugn(Count, 0);
                                Count++;
                                break;
                            }
                        }
            for (int i = 0; i < 1; i++)
                        {
                            Answers = Answers + Vector(Count, 0);
                            Count++;
                        }
            for (int i = 0; i < 1; i++)
                        {
                            int z = rand()%2+1;
                            switch(z)
                            {
                            case 1:
                                Answers = Answers + Prizm(Count, 0);
                                Count++;
                                break;

                            case 2:
                                Answers = Answers + Cilindr(Count, 0);
                                Count++;
                                break;
                            }
                        }
            for (int i = 0; i < 1; i++)
                        {
                            Answers = Answers + TeorFerSimpl(0);
                            Count++;
                        }
            for (int i = 0; i < 1; i++)
                        {
                            Answers = Answers + TeorFerDif(0);
                            Count++;
                        }
            for (int i = 0; i < 1; i++)
                        {
                            int z = rand()%3+1;
                            switch(z)
                            {
                            case 1:
                                Answers = Answers + ISDUravn(0);
                                Count++;
                                break;

                            case 2:
                                Answers = Answers + PokUravn(0);
                                Count++;
                                break;

                            case 3:
                                Answers = Answers + LogUravn(0);
                                Count++;
                                break;
                            }
                        }
            for (int i = 0; i < 1; i++)
                        {
                            int z = rand()%3+1;
                            switch(z)
                            {
                            case 1:
                                Answers = Answers + StepKoren(0);
                                Count++;
                                break;

                            case 2:
                                Answers = Answers + LogCount(0);
                                Count++;
                                break;

                            case 3:
                                Answers = Answers + TrigonomCount(0);
                                Count++;
                                break;
                            }
                        }
            for (int i = 0; i < 1; i++)
                        {
                            Answers = Answers + Proizvodn(Count, 0);
                            Count++;
                        }
            for (int i = 0; i < 1; i++)
                        {
                            Answers = Answers + ZadPricl(0);
                            Count++;
                        }
            for (int i = 0; i < 1; i++)
                        {
                            int z = rand()%3+1;
                            switch(z)
                            {
                            case 1:
                                Answers = Answers + ZadProc(0);
                                Count++;
                                break;

                            case 2:
                                Answers = Answers + ZadRab(0);
                                Count++;
                                break;

                            case 3:
                                Answers = Answers + ZadMove(0);
                                Count++;
                                break;
                            }
                        }
            for (int i = 0; i < 1; i++)
                        {
                            Answers = Answers + Graphics(Count, 0);
                            Count++;
                        }
            for (int i = 0; i < 1; i++)
                        {
                            int z = rand()%3+1;
                            switch(z)
                            {
                            case 1:
                                Answers = Answers + ProizvStep(0);
                                Count++;
                                break;

                            case 2:
                                Answers = Answers + ProizvLogEks(0);
                                Count++;
                                break;

                            case 3:
                                Answers = Answers + ProizvTrigonom(0);
                                Count++;
                                break;
                            }
                        }
            for (int i = 0; i < 1; i++)
                        {
                            int z = rand()%6+1;
                            switch(z)
                            {
                                case 1:
                                    Answers = Answers + Uravn1(2);
                                    break;
                                
                                case 2:
                                    Answers = Answers + Uravn2(2);
                                    break;

                                case 3:
                                    Answers = Answers + Uravn3(2);
                                    break;

                                case 4:
                                    Answers = Answers + Uravn4(2);
                                    break;

                                case 5:
                                    Answers = Answers + Uravn5(2);
                                    break;

                                case 6:
                                    Answers = Answers + Uravn6(2);
                                    break;

                            }
                        }
            for (int i = 0; i < 1; i++)
                        {
                            int z = rand()%3+1;
                            switch(z)
                            {
                                case 1:
                                    Answers = Answers + StereomPrizm(2);
                                    break;
                                
                                case 2:
                                    Answers = Answers + StereomPiramid(2);
                                    break;

                                case 3:
                                    Answers = Answers + StereomCilindr(2);
                                    break;

                            }
                        }
            for (int i = 0; i < 1; i++)
                        {
                            int z = rand()%4+1;
                            switch(z)
                            {
                                case 1:
                                    Answers = Answers + Nerav1(2);
                                    break;
                                
                                case 2:
                                    Answers = Answers + Nerav2(2);
                                    break;

                                case 3:
                                    Answers = Answers + Nerav3(2);
                                    break;

                                case 4:
                                    Answers = Answers + Nerav4(2);
                                    break;
                            }
                        }
            for (int i = 0; i < 1; i++)
                        {
                            int z = rand()%5+1;
                            switch(z)
                            {
                                case 1:
                                    Answers = Answers + Finance1(2);
                                    break;
                                
                                case 2:
                                    Answers = Answers + Finance2(2);
                                    break;

                                case 3:
                                    Answers = Answers + Finance3(2);
                                    break;

                                case 4:
                                    Answers = Answers + Finance3(2);
                                    break;

                                case 5:
                                    Answers = Answers + Finance3(2);
                                    break;
                            }
                        }
            for (int i = 0; i < 1; i++)
                        {
                            int z = rand()%3+1;
                            switch(z)
                            {
                                case 1:
                                    Answers = Answers + SecondTreugol(2);
                                    break;
                                
                                case 2:
                                    Answers = Answers + SecondChetir(2);
                                    break;

                                case 3:
                                    Answers = Answers + SecondOkrug(2);
                                    break;

                            }
                        }
            for (int i = 0; i < 1; i++)
                        {
                            int z = rand()%2+1;
                            switch(z)
                            {
                                case 1:
                                    Answers = Answers + ParamN(2);
                                    break;
                                
                                case 2:
                                    Answers = Answers + ParamS(2);
                                    break;
                            }
                        }
            for (int i = 0; i < 1; i++)
                        {
                            Answers = Answers + TeorChisl(2);
                        }
            cout << "}" << endl << "\\end{enumerate}" << endl << "\\newpage \n {\\centering \\subsubsection*{Ответы}} \n \\begin{enumerate} \n" << Answers << endl << "\\end{enumerate}" << endl << endl;
            Answers = "";
            cout << "0. Назад" << endl;
            cout << "Ваш выбор: ";
            cin >> choice;
            choice = -1;
            break;
        }while(choice != 0);
        choice = -1;
        break;





        }
    } while (choice != 0);
}

