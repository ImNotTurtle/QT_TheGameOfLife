#include "shareddata.h"


QVector<QString> SharedData::Split(QString str, QString splitBy, int splitCount){
    QVector<QString> retList;
    QString accumStr;
    QString tempStr;
    int splitIndex = 0;
    int curSplitCount = 0;
    if (splitCount == -1) {
        splitCount = (int)(str.length());//if no split count provided, make it largest as possible
    }
    //if the split by is null, split the list into list of character
    if (splitBy == "") {
        for (auto x : str) {
            retList.push_back(x);
        }
    }
    else {//split by is not null
        for (int i = 0; i < str.length(); i++) {
            //if the string start to match with the split by string
            if (str[i] == splitBy[splitIndex] && curSplitCount < splitCount) {
                splitIndex++;
                tempStr += str[i];
                //if the string fully match with the split by string
                if (splitIndex == splitBy.length()) {
                    //add accum str to the list and reset
                    splitIndex = 0;
                    curSplitCount++;
                    if (accumStr != "") retList.push_back(accumStr);
                    accumStr = "";
                    tempStr = "";
                }
            }
            else {
                //if the string does not match with the split by string
                if (splitIndex != 0) {//if the string nearly match with the split by string before
                    //add them to the accum string
                    accumStr += tempStr;
                    tempStr = "";
                    splitIndex = 0;
                }

                else accumStr += str[i];
            }
        }
        if (accumStr != "") {
            if (tempStr != "") accumStr += tempStr;
            retList.push_back(accumStr);
        }
    }

    return retList;
}
