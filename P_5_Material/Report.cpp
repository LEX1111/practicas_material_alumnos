/** 
 * @file Informe.cpp
 * @author Casipro Gramo
 * 
 * @date Stellar date 20160309
 */

#include <stdexcept>
#include <sstream>

#include "Report.h"

long Report::_numReports = 0;

Report::Report ( ): _pilotID(0), _stellarDate(0), _reportData("")
{
   _numReports++;
   _reportID = _numReports;
}

Report::Report( int pilotId, long date, string data ): _pilotID(pilotId),
                                                             _stellarDate(date),
                                                             _reportData(data)
{
   if ( pilotId < 0 )
   {
      throw std::invalid_argument ( "Report::Report: the identifier of the"
                                            " pilot can't be negative" );
   }

   if ( date < 0 )
   {
      throw std::invalid_argument ( "Report::Report: the date can't be negative" );
   }

   _numReports++;
   _reportID = _numReports;
}

Report::Report ( const Report& orig ): _pilotID(orig._pilotID),
                                          _stellarDate(orig._stellarDate),
                                          _reportData(orig._reportData)
{
   _numReports++;
   _reportID = _numReports;
}

Report::~Report ( )
{
}

void Report::setReportData( string reportData )
{
   this->_reportData = reportData;
}

string Report::getReportData( ) const
{
   return _reportData;
}

/**
 * @todo Check the value, and if it is negative, throw an exception
 */
void Report::setStellarDate( long stellarDate )
{
   this->_stellarDate = stellarDate;
}

long Report::getStellarDate( ) const
{
   return _stellarDate;
}

/**
 * @todo Check the value, and if it is negative, throw an exception
 */
void Report::setPilotId( int pilotID )
{
   this->_pilotID = pilotID;
}

int Report::getPilotID( ) const
{
   return _pilotID;
}

int Report::getIncidentID( ) const
{
   return _reportID;
}

string Report::toCSV () const
{
   std::stringstream aux;

   aux << "Stellar date: " << _stellarDate << " ; "
       << "Pilot ID: " << _pilotID << " ; "
       << _reportData;

   return ( aux.str () );
}

Report& Report::operator =( const Report &other )
{
   if ( this != &other )
   {
      _pilotID = other._pilotID;
      _stellarDate = other._stellarDate;
      _reportData = other._reportData;
   }
   
   return ( *this );
}
