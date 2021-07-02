#include <iostream>
#include <fstream>
#include <sstream>

class PrepData{
	public:
		void printName()
		{
				int a = 2;
				std::cout << "hello world" << a;
		}

		void readTxt(std::string fName);
	public:
		//data specific variables
		int dataRow = 0;
		int dataCol = 3;
	private:
};

class Data
{
	public:
		Data(int row,int col);
}

void PrepData::readTxt(std::string fName)
{
	std::string temp = "";
	std::ifstream file;
	file.open(fName);
	while(getline(file,temp,'\n'))
	{
		dataRow++;
	}		
	std::cout << "Datarow is:" << dataRow << std::endl;
	file.close();
	file.open(fName);
	unsigned int funcData[dataRow][dataCol];
	for(int row = 0; row < dataRow; row++)
	{
		for(int col = 0; col < dataCol; col++)
		{
			getline(file,temp,',');
			std::istringstream reader(temp);
			uint32_t val = 0;
			reader >> funcData[row][col];
			std::cout << funcData[row][col] << std::endl;
		}
	}
	data = funcData;
}

Data::Data(int row, int col)
{
	
}

int main()
{	
	std::string dataFile = "../sample";
	Data data;
	data.readTxt(dataFile);
	//data.readTxt(dataFile);
	//std::ifstream file;
/*	std::string data = "";
	while(getline(file,data,','))
	{
		std::cout << data <<std::endl;
	}*/
	return 0;
}
