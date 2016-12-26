#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <memory>

enum InOutTypes{ Console, File };

//abstract class for input
class InputType{
	std::vector<std::string> info;
	std::regex number_format;
public:
	virtual void GetInfo(std::string input_name)=0;
	std::vector<std::string> ReturnInput(){ return info; }
	void SetInfo(std::vector<std::string> v){ info = v; }
protected:
	void SetNumberFormat(std::regex reg_expr){ number_format = reg_expr; }
	
};

class InputConsole : public InputType{
public:
	void GetInfo(std::string input_name);//in this case input_name means nothing
};

class InputFile :public InputType{
public:
	void GetInfo(std::string input_name);
};


//abstract class for output
class OutputType{
	std::vector<std::string> info_out;
public:
	virtual void WriteInfo(std::string output_name) = 0;
	void SetOutInfo(std::shared_ptr<InputType> i_type_info){ info_out = i_type_info->ReturnInput(); }
protected:
	
	std::vector<std::string> GetOutInfo(){ return info_out; } 
};


class OutputFile :public OutputType{
	void WriteInfo(std::string output_name);
};

class OutputConsole :public OutputType{
	void WriteInfo(std::string output_name);//in this case output_name means nothing
};

//for manipulating with numbers
class SciNumb{
	std::shared_ptr<InputType> i_type_number;
public:
	void SetSciNumb(std::shared_ptr<InputType> v){ i_type_number = v; }
	std::shared_ptr<InputType> GetSciNumb(){ return i_type_number; }
};

InputType* GetInputType(InOutTypes i_o_type);//input factory
OutputType* GetOutputType(InOutTypes i_o_type);//output factory
