/*
Author: Fredrik Bakke, bakkefredrik@gmail.com
Date: 8.6-2015
License: GNU GENERAL PUBLIC LICENSE Version 2, June 1991
*/
#include "GpxFile.h"

GpxFile::GpxFile(): m_fileParsed(false)
{

}


void GpxFile::parseXmlElement(QXmlStreamReader &xmlStream){

    QString sec;
    if(xmlStream.isStartElement() && xmlStream.qualifiedName().toString() == "wpt")
    {
    double latitude = 0;
    double longitude = 0;
    QString name = "";
   //find lat+long
    for(int i = 0; i < xmlStream.attributes().size(); ++i){
        if(      xmlStream.attributes()[i].name().toString() == "lat"){
            latitude = xmlStream.attributes()[i].value().toDouble();
        }else if(xmlStream.attributes()[i].name().toString()== "lon"){
            longitude = xmlStream.attributes()[i].value().toDouble();
        }
    }



//look throug sub-elements for the rest
    while(!(xmlStream.qualifiedName() == "wpt" && xmlStream.isEndElement()) && !xmlStream.atEnd()){

            if(xmlStream.isStartElement() && xmlStream.qualifiedName().toString() == "groundspeak:name"){
                    if(xmlStream.qualifiedName().toString() == "groundspeak:name"){

                        xmlStream.readNext();
                        if(xmlStream.tokenType() == QXmlStreamReader::Characters){
                            name =xmlStream.text().toString();
                        }


                    }

        }

            xmlStream.readNext();

    }


//    else if(xmlStream.isCharacters()){
  //          sec = xmlStream.qualifiedName().toString() + ": " + xmlStream.text().toString();



     qDebug() << "GOT: " +name + " lat:"+QString::number(latitude)+" long:"+QString::number(longitude);

    DataCache tmpCache(0,name,latitude,longitude);
    m_caches.push_back(tmpCache);
    }//end wpt

}//end parseXmlElemet


void GpxFile::doParse(QString fileName)
{

    std::unique_ptr<DataCache> p_tmpCache;
    bool ok = false;
    m_file.setFileName(fileName);
    bool isOpen = m_file.open(QIODevice::ReadOnly | QIODevice::Text);
       if (!isOpen)
       {
           qDebug() << "Couldn't open file";
           return;
       }else{
           QXmlStreamReader xmlStream(&m_file);
           while(!xmlStream.atEnd())
           {
               xmlStream.readNext();
               parseXmlElement(xmlStream);
           }
       }


    m_fileParsed = true;
    return;
}

std::vector<DataCache> &GpxFile::getCaches()
{
 return m_caches;
}
bool GpxFile::getFileParsed() const
{
    return m_fileParsed;
}
