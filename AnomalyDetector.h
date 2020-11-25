#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>

class TimeSeries
{
public:
    std::map<char *, std::vector<double>> m;
    TimeSeries()
    {
    }
    std::vector<std::string> parserStr(std::string s)
    {
        size_t pos = 0;
        std::vector<std::string> v;
        std::string word;
        int counter = 0;
        while ((pos = s.find(',')) != std::string::npos)
        {
            word = s.substr(0, pos);
            v[counter] = word;
            counter++;
            s.erase(0, pos + word.length());
        }
        return v;
    }
    void initDict(const std::string c)
    {
        std::fstream f;
        f.open(c);
        std::string line;
        if (f.is_open())
        {
            getline(f, line);
            std::vector<std::string> vec;
            vec = parserStr(c);
        }
        else
            std::cout << "not able to read file";
    }
};
class AnomalyReport
{
public:
    const std::string description;
    const long timeStep;
    AnomalyReport(std::string description, long timeStep) : description(description), timeStep(timeStep) {}
};
class TimeSerieasAnomalyDetector
{
public:
    virtual void learnNormal(const TimeSeries &ts) = 0;
    virtual std::vector<AnomalyReport> detect(const TimeSeries &ts) = 0;
    virtual ~TimeSerieasAnomalyDetector() {}
};