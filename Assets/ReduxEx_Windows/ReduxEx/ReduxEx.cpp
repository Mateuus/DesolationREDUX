#include "includes.h"

//--- Processor
String^ ReduxEx::Process(String^ input)
{
	ReduxEx^ manager = gcnew ReduxEx(input);
	return manager->execute();
}

ReduxEx::ReduxEx(String^ _input)
{
	this->input = _input;
	int index = input->IndexOf("[");
	this->function = input->Substring(0, index)->ToLower();
	this->params = input->Substring(index + 1, input->Length - (index + 2));
}
String^ ReduxEx::execute()
{
	if (function->Equals("get_player"))
	{
		return "[DATA HERE AS ARMA ARRAY]";
	} 
	if (function->Equals("kill_player"))
	{
		return "TRUE"; //true/false based on success
	}
	if (function->Equals("save_player"))
	{
		return "TRUE"; //true/false based on success
	}
}