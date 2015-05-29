/*
Author: Fredrik Bakke, bakkefredrik@gmail.com
Date: 8.6-2015
License: GNU GENERAL PUBLIC LICENSE Version 2, June 1991
*/
#ifndef GPXFILE_H
#define GPXFILE_H
#include <QString>
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include <vector>
#include "DataCache.h"
#include <memory>   //unique_vector
#include <algorithm> //for_each
class GpxFile
{
public:
    GpxFile();
   void doParse(QString fileName);

   std::vector <DataCache>& getCaches();
   bool getFileParsed() const;

private:
   void parseXmlElement(QXmlStreamReader &xmlStream);
   QFile m_file;
   std::vector <DataCache>m_caches;
   bool m_fileParsed;
};

#endif // GPXFILE_H
