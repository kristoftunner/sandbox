#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#define CHANNELS 3 
#define DEAFULT_NR_ROWS 1024

struct chData
{
    unsigned ch0,ch1,ch2;
};

class DataBuffer
{
    public:
        unsigned int rows = 0;
        unsigned int cols = 3;
        std::vector<chData> data;
        
        DataBuffer(std::string fName);
        void ReadData(std::string fName);
};

DataBuffer::DataBuffer(std::string fName)
{
    std::string temp = "";
    std::ifstream file;
    file.open(fName);

    while(getline(file,temp,'\n'))
    {
        rows++;
    }
    std::cout << "There is " << rows << " number of data" << std::endl;
    file.close();
    cols = 3;
}

void DataBuffer::ReadData(std::string fName)
{
    std::string temp = "";
    std::ifstream file;
    file.open(fName);
    struct chData val = {0,0,0};
    unsigned int i = 0;
    while(getline(file,temp,','))
    {
        std::istringstream reader(temp);
        reader >> val;
        if((i%3 == 0) & (i !=0 ))
        {
            data.push_back(val);
            std::cout << "data pushed" << std::endl;
        }
        i++;
    }
           //data.push_back(val);

}

int main()
{
    std::string dataFile = "../sample";
    DataBuffer buff(dataFile);
    buff.ReadData(dataFile);
    struct chData data = {0,1,2};
    std::cout << data[0] << std::endl;
    //for(int i = 0; i < buff.data.size(); i++)
    //    std::cout << buff.data[i].ch0 << std::endl;
    
    
}