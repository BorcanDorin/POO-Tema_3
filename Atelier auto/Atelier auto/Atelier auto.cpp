#include "pch.h"
#include <iostream>
#include "vehicle.h"
#include "Atelier.h"
#include <locale>

using namespace std;
//convention: true --> check result OK,  false --> check result NOT OK;  

int main()
{
    cout << "Hello World!\n";
	car b("12", 1998);
	b.total_destruction();
	Atelier a;
	auto result = a.diagnose_vehicle(b);
	cout << result;
}