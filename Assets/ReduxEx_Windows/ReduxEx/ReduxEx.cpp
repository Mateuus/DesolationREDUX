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
	if (function->Equals("create_world"))
	{
		// is not meant to be run in arma
		return "[]";
	}
	if (function->Equals("link_worlds"))
	{
		// is not meant to be run in arma
		return "[]";
	}
	if (function->Equals("player_login"))
	{
		return "[]";
	} 
	if (function->Equals("get_information"))
	{
		return "[]";
	}
	if (function->Equals("link_death"))
	{
		return "[]";
	}
	if (function->Equals("get_character"))
	{
		return "[]"; 
	}
	if (function->Equals("create_character"))
	{
		return "[]";
	}
	if (function->Equals("update_character"))
	{
		return "[]";
	}
	if (function->Equals("update_character_loconly"))
	{
		return "[]";
	}
	if (function->Equals("create_object"))
	{
		return "[]";
	}
	if (function->Equals("update_object"))
	{
		return "[]";
	}
	if (function->Equals("request_object"))
	{
		return "[]";
	}
	if (function->Equals("get_objects"))
	{
		return "[]";
	}
}