#include "stdafx.h"
#include "SciNumb.h"



InputType* GetInputType(InOutTypes i_o_type)
{
	InputType *new_type = NULL;
	switch (i_o_type){
	case Console:{
		new_type = new InputConsole();
		break;
	}
	case File:{
		new_type = new InputFile();
		break;
	}
	}
	return new_type;
}

OutputType* GetOutputType(InOutTypes i_o_type)
{
	OutputType* new_type = NULL;
	switch (i_o_type){
	case Console:{
		new_type = new OutputConsole();
		break;
	}
	case File:{
		new_type = new OutputFile();
		break;
	}
	}
	return new_type;
}

void OutputConsole::WriteInfo(std::string output_name)
{
	std::cout << "Valid numbers are: \n";
	for (int i = 0; i < GetOutInfo().size(); i++){
		std::cout << GetOutInfo()[i]<<std::endl;
	}
}

void OutputFile::WriteInfo(std::string output_name)
{
	std::ofstream output_file(output_name);
	std::cout << "Valid numbers are written in: "<<output_name<<std::endl;
	for (int i = 0; i < GetOutInfo().size(); i++){
		output_file << GetOutInfo()[i] << std::endl;
	}
}

void InputConsole::GetInfo(std::string input_name)
{
	std::cout << "Enter numbers or 'quit' to exit\n";
	std::string name_format = R"((\+|-)?([[:digit:]]+)(\.[[:digit:]]+)?((e|E)?(\+|-)?([[:digit:]]+))?)";
	std::regex reg(name_format);
	std::string number;
	std::vector<std::string> new_vect;
	SetNumberFormat(reg);
	while (true){
		std::getline(std::cin, number);
		if (!std::cin){
			std::cout << "Something went wrong... Closing app\n";
			break;
		}
		if (number == "quit"){
			std::cout << "Nothing more to read... Forming the list of numbers...\n";
			break;
		}
		if (std::regex_match(number, reg)){
			new_vect.push_back(number);
		}
		else{
			std::cout << "Wrong input!\n";
		}
	}
	SetInfo(new_vect);
}

void InputFile::GetInfo(std::string input_name)
{
	std::ifstream input_file(input_name);
	std::vector<std::string> numbers;
	std::string numb="";
	std::string name_format = R"((\+|-)?([[:digit:]]+)(\.[[:digit:]]+)?((e|E)?(\+|-)?([[:digit:]]+))?)";
	std::regex reg(name_format);
	SetNumberFormat(reg);
	char ch;
	if (input_file){
		while (input_file.get(ch)){
			if (ch == '\n'){
				if (std::regex_match(numb, reg)){
					numbers.push_back(numb);
				}
				numb.clear();
			}
			if (ch != '\n'){
				numb += ch;
			}
		}
	}
	input_file.close();
	SetInfo(numbers);
}
