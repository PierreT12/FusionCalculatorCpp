#include "dbaccess.h"



DbAccess::DbAccess(const QString& path)
{
   m_db = QSqlDatabase::addDatabase("QSQLITE");
   m_db.setDatabaseName(path);

   if (!m_db.open())
   {
      qDebug() << "Error: connection with database fail";
   }
   else
   {
      qDebug() << "Database: connection ok";
   }
}

QStringList  DbAccess::GetAll(QSqlQuery query)
{
    QStringList list;
    int id = query.record().indexOf("name");
    while(query.next())
    {
        QString name = query.value(id).toString();
           list << name;
    }

    return list;
}

Persona DbAccess::GetSinglePersona(QString indexName)
{
    //Creates Query and Persona
    QSqlQuery query("SELECT Name, Arcana, Level FROM Personas_Final WHERE Name = ?");
    query.addBindValue(indexName);
    Persona single;
    //Looks for a Persona that matches the name of the
    //Selected Persona in the ListView

//Working now
    if(query.exec())
    {

        while(query.next())
        {
            QString temp;
            single.m_name = query.value(0).toString();
            single.m_arcana = query.value(1).toString();
            //Database still stores these as strings for some reason
            //Changed it to int like a month ago :/
            temp = query.value(2).toString();
            single.m_level = temp.toUInt();

        }

    }
return single;
}




QPixmap DbAccess::GetSinglePersonaImage(QString indexName)
{
    //Creates pixmap that'll store image
    QPixmap outPixmap = QPixmap();
    //Creates Query and Persona
    QSqlQuery query("SELECT Image FROM Personas_Final WHERE Name = ?");
    query.addBindValue(indexName);

    //Looks for a Persona that matches the name of the
    //Selected Persona in the ListView

//Working now
    if(query.exec())
    {
    QByteArray outByteArray;
        while(query.next())
        {
            outByteArray = query.value( 0 ).toByteArray();
        }

        outPixmap.loadFromData( outByteArray );
    }
return outPixmap;
}

QStringList DbAccess::GetInfoStat(QString name)
{
    //Creating List and Query
    QStringList statInfo;
    QSqlQuery query("SELECT Stats_Final.Strength, Stats_Final.Magic, Stats_Final.Endureance, Stats_Final.Agility, Stats_Final.Luck FROM Personas_Final INNER JOIN Stats_Final ON Stats_Final.Stat_ID = Personas_Final.Stat_ID WHERE Name =?");
    query.addBindValue(name);

    if(query.exec())
    {

        while(query.next())
        {
               statInfo.append(query.value(0).toString());
               statInfo.append(query.value(1).toString());
               statInfo.append(query.value(2).toString());
               statInfo.append(query.value(3).toString());
               statInfo.append(query.value(4).toString());
        }
    }


    return statInfo;
}



QStringList DbAccess::GetInfoMagic(QString name)
{
    //Creating List and Query
    QStringList magicInfo;
    QSqlQuery query("SELECT Str_Wea_Final.Phys, Str_Wea_Final.Gun, Str_Wea_Final.Fire, Str_Wea_Final.Ice, Str_Wea_Final.Electric, Str_Wea_Final.Wind, Str_Wea_Final.Psych, Str_Wea_Final.Nuke, Str_Wea_Final.Bless, Str_Wea_Final.Curse FROM Personas_Final INNER JOIN Str_Wea_Final ON Str_Wea_Final.Str_Wea_ID = Personas_Final.Str_Wea_ID WHERE Name = ?");
    query.addBindValue(name);

    if(query.exec())
    {

        while(query.next())
        {
               magicInfo.append(query.value(0).toString());
               magicInfo.append(query.value(1).toString());
               magicInfo.append(query.value(2).toString());
               magicInfo.append(query.value(3).toString());
               magicInfo.append(query.value(4).toString());
               magicInfo.append(query.value(5).toString());
               magicInfo.append(query.value(6).toString());
               magicInfo.append(query.value(7).toString());
               magicInfo.append(query.value(8).toString());
               magicInfo.append(query.value(9).toString());
        }
    }


    return magicInfo;
}
