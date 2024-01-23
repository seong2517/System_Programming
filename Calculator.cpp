#include <iostream>
#include <Windows.h>
using namespace std;

enum
{
	DIV = 1,
	MUL,
	ADD,
	MIN,
	ELSE,
	EXIT
};

DWORD ShowMenu();
void Divide(double a, double b);
void Multiple(double a, double b);
void Add(double a, double b);
void Min(double a, double b);

int main()
{
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;
	si.cb = sizeof(si);

	WCHAR command[] = L"calc.exe";
	SetCurrentDirectory(L"C:\\WINDOWS\\system32");

	DWORD sel;
	double num1, num2;
	while(1)
	{
		sel = ShowMenu();
		if(sel == EXIT)
			return 0;

		if(sel != ELSE)
		{
			fputws(L"Input Num1 Num2 : ", stdout);
			wscanf_s(L"%lf %lf", &num1, &num2);
		}

		switch(sel)
		{
		case DIV:
			Divide(num1, num2);
			break;
		case MUL:
			Multiple(num1, num2);
			break;
		case ADD:
			Add(num1, num2);
			break;
		case MIN:
			Min(num1, num2);
			break;
		case ELSE:
			ZeroMemory(&pi, sizeof(pi));
			CreateProcess(NULL, command, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi); // 사칙연산을 제외한 연산의 경우, 계산기 프로그램을 실행시킨다.
			CloseHandle(pi.hProcess); // 자식 프로세스 생성과 동시에 핸들을 반환함으로써, 자식 프로세스의 커널 오브젝트의 Usage Count값을 1로 해주었다.
			CloseHandle(pi.hThread);  // 이렇게 하면, 자식 프로세스를 종료하면 Usage Count값이 0이 됨으로써 커널 오브젝트도 함께 소멸될 것이다.
			break;
		}
	}

	return 0;
}


DWORD ShowMenu()
{
	DWORD sel;

	fputws(L"-----Menu-----\n", stdout);
	fputws(L"num 1 : Divide\n", stdout);
	fputws(L"num 2 : Multiple\n", stdout);
	fputws(L"num 3 : Add\n", stdout);
	fputws(L"num 4 : Minus\n", stdout);
	fputws(L"num 5 : Any other operations\n", stdout);
	fputws(L"num 6 : Exit\n", stdout);
	fputws(L"SELECTION >> ", stdout);
	wscanf_s(L"%d", &sel);

	return sel;
}

void Divide(double a, double b)
{
	wprintf_s(L"%f / %f = %f \n\n", a, b, a / b);
}

void Multiple(double a, double b)
{
	wprintf_s(L"%f * %f = %f \n\n", a, b, a * b);
}

void Add(double a, double b)
{
	wprintf_s(L"%f + %f = %f \n\n", a, b, a + b);
}

void Min(double a, double b)
{
	wprintf_s(L"%f - %f = %f \n\n", a, b, a - b);
}
