#pragma once



#include <msclr\marshal.h> 
using namespace System; 
using namespace System::IO;
using namespace msclr::interop; 

public ref class ReduxEx
{
private:
	String^ input;
	String^ function;
	String^ params;
public:
	ReduxEx(String^ _input);
	String^ execute();

	static String^ Process(String^ input);
};