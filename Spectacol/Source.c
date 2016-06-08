#define _CRT_SECURE_NO_WARNINGS
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<conio.h>
#include<limits.h>


int inceput[100], sfarsit[100], nr[100];

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CHAR:
	{
					if (wParam == VK_ESCAPE)
						SendMessage(hwnd, WM_CLOSE, 0, 0);
					return 0;
	}; break;
	case WM_DESTROY:
	{
					  DeleteObject(hBitmap);
					   PostQuitMessage(0);
					   return 0;
	}; break;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
	
}


int WINAPI WinMain(HINSTANCE hIns, HINSTANCE hPrev, LPSTR lpszArgument, int nCmdShow)
{
	char szClassName[] = "TEstare";
	WNDCLASSEX wc;
	MSG messages;
	HWND hwnd;

	wc.hInstance = hIns;
	wc.lpszClassName = szClassName, wc.lpfnWndProc = WndProc;
	wc.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW, wc.cbSize = sizeof(WNDCLASSEX);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION), wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW), wc.lpszMenuName = NULL;
	wc.cbClsExtra = 0, wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetSysColorBrush(32);
	RegisterClassEx(&wc);



	hwnd = CreateWindow(szClassName, szClassName, WS_OVERLAPPEDWINDOW, 25, 10, 1100, 720, HWND_DESKTOP, NULL, hIns, NULL);
	ShowWindow(hwnd, nCmdShow);



	while (GetMessage(&messages, NULL, 0, 0))
	{
		TranslateMessage(&messages);
		DispatchMessage(&messages);
	}


	return messages.wParam;
}
/*

int main()
{
	int n, i, h, m, schimb, ultim, aux;
	printf("n="); scanf("%d", &n);

	printf("Introduceti inceputul si sfarsitul spectacolelor");
	for (i = 0; i<n; i++)


	{
		nr[i] = i + 1; //transform timpul in minute
		scanf("%d %d", &h, &m); inceput[i] = h * 60 + m;
		scanf("%d %d", &h, &m); sfarsit[i] = h * 60 + m;
	}
	//ordonez spectacolele crescator dupa ora de final
	do
	{
		schimb = 0;
		for (i = 0; i<n - 1; i++)
		if (sfarsit[nr[i]]>sfarsit[nr[i + 1]])
		{
			aux = nr[i]; nr[i] = nr[i + 1]; nr[i + 1] = aux; schimb = 1;
		}
	} while (schimb);
	printf("Spectacolele selectate sunt : \n %d ", nr[0]);
	for (ultim = 0, i = 1; i<n; i++)
	if (inceput[nr[i]] >= sfarsit[nr[ultim]])
	{
		printf("%d ", nr[i]); ultim = i;
	}
	printf("\n");

}*/