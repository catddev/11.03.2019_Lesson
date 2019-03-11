#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>
#include<cstring>

using namespace std;

// own itoa // case 1
char* int_to_str(int a) {
	char* str;
	int i = 0;
	int tmp = a;

	while (tmp)
	{
		tmp /= 10;
		i++;
	}
	str = new char[i + 1]; // на нулевой символ - конец строки

	str[i] = '\0'; // сразу закинем нулевой символ в конец
	while (a)
	{
		str[--i] = a % 10 + 48; //чтобы получить не само число 9, а символ 9 - то есть из таблицы ASCII кодов нужно прибавить 48 (ноль)
		a/= 10;
	}
	
	return str;
}

//23.	**Подсчитать среднюю длину слова во введенном предложении.
// Рекомендации:
// с клавиатуры с помощью cin не позволяет ввести пробелы, поэтому можно вместо пробелов вводить символ подчеркивания «_» или воспользоваться cin.getline().
// char Mas[250];
// cin.getline(Mas, 250);
// cout << Mas;
double countOnlyWords(const char*s) {
	double count = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i - 1] == ' ') continue;
		if (s[i] == ' ') count++;
	}
	if (s[0] == ' ') count--;
	if (s[strlen(s) - 1] == ' ') count--;

	return count + 1;
}
double w_len(char*str) {
	double n = countOnlyWords(str);
	double k = 0;
	while (*str != '\0')
		if (*str++ != ' ') k++;

	return k / n;
}

// 24.	**Написать функцию, которая преобразует строку в целое число.
// Если строка содержит не цифровые символы – подсчет останавливается.
// Так строка 123abc даст число 123, а строка a23f даст число 0.
int str_to_int(char*str) {
	int a = 0;
	while (*str >= 48 && *str <= 57)
	{
		a = a * 10 + (*str - 48);
		str++;
	}
	return a;

// менее оптимально, просто для наглядности:
//	while (*str!='\0')
//	{
//		if (*str >= 48 && *str <= 57)
//		{
//			a = a * 10 + (*str - 48);
//			str++;
//		}
//		else break;
//	}
//	return a;
}

// 25.	*Заменить в строке все гласные буквы на их номер по алфавиту.
bool vowels(char s) { // завести привычку исп чаще bool функции
	char vowels[8] = "aeiouy";
	for (int i = 0; i < strlen(vowels); i++)
	{
		if (vowels[i] == s)
			return true;
	}
	return false;
}
char *replaceVowels(char*str) {
	char tmp[100];
	char*p_tmp = tmp, *p_str = str;
	char buf[4];

	while (*p_str != '\0')
	{
		if (vowels(*p_str))
		{
			_itoa_s(*p_str - 'a' + 1 , buf, 10); // например my example: #y = 121 - 97(ASCII y - ASCII a) +1(алфавит начинается не с нуля, а с 1)=25;
			strcat_s(tmp, buf); // s-версия нельзя для динамической памяти, только с заданным размером
			p_str++;
			p_tmp += strlen(buf);
		}
		else
		{
			*p_tmp = *p_str;
			*(p_tmp + 1) = '\0';
			p_tmp++;
			p_str++;
		}
	}
	strcpy(str, tmp);
	// если функцию strcpy не принимает, то просто циклом копируем
	//for (int i = 0; i <= strlen(tmp); i++) // обязательно <=, чтобы копировал включительно \0;
	//	str[i] = tmp[i];
	return str;
}

bool isEven(int *n) {
	return (*n % 2 == 0);
}

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn; cin.get();

		switch (tn)
		{
		case 1:
		{
			int a;
			cin >> a;
			char* str = int_to_str(a);
			cout << str << endl;
			delete[] str; // потому что внутри функции была выделена память
		}
		break;
		case 2:
		{
			char str[100];
			cin.getline(str, 100, '\n');
			double a = w_len(str);
			cout << a << endl;
		}
		break;
		case 3:
		{
			char str[100];
			cin.getline(str, 100, '\n');

			int n = str_to_int(str);
			cout << n << endl;
		}
		break;
		case 4:
		{
			char str[50];
			cin.getline(str, 50, '\n');
			
			char *p = replaceVowels(str);
			cout << p << endl;
		}
		break;
		case 5:
		{
			int x;
			cin >> x;
			cout << isEven(&x) << endl; // функция требует указатель, но чтобы не создавать лишний указатель можно просто переменную передать по & ссылке, т.е. адрес напрямую
		}
		break;
		case 6:
		{

		}
		break;
		case 7:
		{

		}
		break;
		case 8:
		{

		}
		break;
		case 9:
		{

		}
		break;
		case 10:
		{

		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}