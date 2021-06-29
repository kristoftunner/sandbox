#include <iostream>
#include <fstream>

class Data{
	public:
		//data specific variables
		int dataRow = 0;
		int dataCol = 3;
		unsigned int *data;

		void printName()
		{
				int a = 2;
				std::cout << "hello world" << a;
		}

		void readTxt(std::string fName)
		{
			std::string data = "";
			std::ifstream file;
			file.open(fName);
			while(getline(file,data,'\n'))
			{
				dataRow++;
				std::cout << data <<std::endl;
			}		
			std::cout << "Datarow is:" << dataRow << std::endl;
			file.close();
			file.open(fName);
			for(int row = 0; row < dataRow; row++)
			{
				for(int col = 0, col < dataCol; col++)
				{
					getline(file,)
				}
			}
		}
	private:
};

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
