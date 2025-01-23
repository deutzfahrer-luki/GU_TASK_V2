#ifndef LOADDATA_H
#define LOADDATA_H

class LoadData
{
public:
    static LoadData* getInstance();



private:
    LoadData();
    static LoadData* instance;
    LoadData(const LoadData&) = delete;
    LoadData& operator=(const LoadData&) = delete;
};

#endif // LOADDATA_H
