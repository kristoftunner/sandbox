#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#define CHANNELS 3 
#define DEAFULT_NR_ROWS 1024
#define LOG(x) std::cout << x << std::endl;

struct chData
{
    unsigned int ch0,ch1,ch2;
};

std::ostream& operator<<(std::ostream& stream, const chData& data)
{
    stream << data.ch0 << "," << data.ch1 << "," << data.ch2 << std::endl;
    return stream;
}

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
    int i = 0;
    std::vector<string>* p = NULL;
    while(getline(file,temp,'\n'))
    {
        //getline(file,temp,',');

        std::istringstream reader(temp);
        std::cout << "i is:"  << std::endl;
        LOG(temp);
        int tmp = i%3;
        if(i%3 == 0)
            reader >> val.ch0;
        else if(i%3 == 1)
            reader >> val.ch1;
        else if(i%3 == 2)
        {
            reader >>val.ch2;
            data.push_back(val);
            LOG("Data is pushed");
        }
        i++;
    }
}

int main()
{
    std::string dataFile = "../sample";
    DataBuffer buff(dataFile);
    buff.ReadData(dataFile);
    
    for(int i = 0;  i < buff.data.size(); i++)
    {
        std::cout << buff.data[i] << std::endl;
    }
    //for(chData d : buff.data)
     //   std::cout << d << std::endl;
}