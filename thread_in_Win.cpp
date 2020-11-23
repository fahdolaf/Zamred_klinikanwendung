/*
 ============================================================================
 Name        : C_Play.c
 Author      : Ahmed Elghamry
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <Windows.h>
#include <sapi.h>

ISpVoice *pVoice = NULL;

void printSmoothly(wchar_t *Str);

int main(void)
{
    if (FAILED(::CoInitialize(NULL)))
        return FALSE;

    HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, 
                    IID_ISpVoice, (void **)&pVoice);

    wchar_t *sentence = L"Greetings professor falken,What would you like to do ?";

    // how can i execute these two at the same time ?
pVoice->Speak(sentence, SPF_ASYNC, NULL);
printSmoothly(sentence);

    pVoice->Release();

    CoUninitialize();

    return 0;
}

void printSmoothly(wchar_t *Str)
{
    size_t len = wcslen( Str ) , n ;

    for( n = 0 ; n < len ; n++ )
    {
        wprintf( L"%c", Str[n] );

        Sleep(50);
    }
}
