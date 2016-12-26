/*
Getting numbers from the keyboard or from file
Then writing numbers in scientific format to another file or console
*/
#include "stdafx.h"
#include "SciNumb.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//std::shared_ptr<InputType> file_input(GetInputType(File));
	std::shared_ptr<InputType> console_input(GetInputType(Console));
	//std::shared_ptr<OutputType> console_output(GetOutputType(Console));
	std::shared_ptr<OutputType> file_output(GetOutputType(File));

	std::shared_ptr<SciNumb> science_number(new SciNumb());

	//file_input->GetInfo("input.txt");
	console_input->GetInfo("input.txt");
	science_number->SetSciNumb(console_input);
	//console_output->SetOutInfo(science_number->GetSciNumb());
	file_output->SetOutInfo(science_number->GetSciNumb());
	//console_output->WriteInfo("output.txt");
	file_output->WriteInfo("output.txt");
	return 0;
}

