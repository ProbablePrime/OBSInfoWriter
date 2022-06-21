#include "OutputFormat.EDL.h"
#include <Groundfloor/Materials/FileWriter.h>
#include <algorithm>
#include <cmath>

const char* REELNAME = "OBSIW";

OutputFormatEDL::OutputFormatEDL(const InfoWriterSettings &settings, const std::string filename) : IOutputFormat(), settings(settings), currentFilename(filename), markercount(0), lastMarker(0)
{
}

void OutputFormatEDL::WriteGFStringToFile(const Groundfloor::String& SData) const
{
   Groundfloor::FileWriter Writer;
   Writer.open(this->currentFilename.c_str(), true);
   Writer.start();
   Writer.add(&SData);

   while (!Writer.isEmpty())
   {
      GFMillisleep(10);
   }

   Writer.stopAndWait();
   Writer.close();
}

std::string OutputFormatEDL::SecsToHMSString(const int64_t totalseconds) const
{
   uint32_t hr = (uint32_t)trunc(totalseconds / 60.0 / 60.0);
   uint32_t min = (uint32_t)trunc(totalseconds / 60.0) - (hr * 60);
   uint32_t sec = totalseconds % 60;

   const char* timeformat = "%02d:%02d:%02d:%02d";

   char buffer[14];
   sprintf(&buffer[0], timeformat, hr, min, sec, 0);

   return buffer;
}

void OutputFormatEDL::writeMarker(const int64_t start, const int64_t stop, const std::string text) const
{
   char crlf[] = GFNATIVENEXTLINE;

   auto formattedStartTime = SecsToHMSString(start);
   auto formattedStopTime = SecsToHMSString(stop);

   // Standard EDL Line
   const char *edlformat = "%03d  %s V     C        %s %s %s %s  ";
   char line[200];
   sprintf(&line[0], edlformat, markercount, REELNAME, formattedStartTime.c_str(), formattedStopTime.c_str(), formattedStartTime.c_str(), formattedStopTime.c_str());

   Groundfloor::String EdlMarkerLine(line);

   // CRLF between standard EDL and EDL "user note"
   EdlMarkerLine.append_ansi(crlf);

   // User note line, based on DaVinci Resolve format.

   // Notes (we're not using these), Color, Marker name, Duration(which we'll leave at 1(millisecond)) for now.
   const char* edlMetadataFormat = "%s |C:%s |M:%s |D:1";
   char metadataLine[200];
   sprintf(&metadataLine[0], edlMetadataFormat, "", "ResolveColorCyan", text);
   EdlMarkerLine.append(metadataLine);

   // Double line break to match resolve
   EdlMarkerLine.append_ansi(crlf);
   EdlMarkerLine.append_ansi(crlf);

   WriteGFStringToFile(EdlMarkerLine);
}

void OutputFormatEDL::Start()
{
   this->markercount = 1;
   this->lastMarker = 0;
   this->lastMarkerText = "START";
}

void OutputFormatEDL::Stop(const int64_t timestamp)
{
   // -1 second because if the length is longer than the written video, software might like this EDL even less than it already does
   writeMarker(lastMarker, timestamp - 1, lastMarkerText);
}

void OutputFormatEDL::HotkeyMarker(const int64_t timestamp, const std::string text)
{
   writeMarker(lastMarker, timestamp, lastMarkerText);

   lastMarker = timestamp;
   lastMarkerText = text;

   markercount++;
}

void OutputFormatEDL::ScenechangeMarker(const int64_t timestamp, const std::string scenename)
{
   writeMarker(lastMarker, timestamp, lastMarkerText);

   lastMarker = timestamp;
   lastMarkerText = scenename;

   markercount++;
}

void OutputFormatEDL::PausedMarker(const int64_t timestamp)
{
}

void OutputFormatEDL::ResumedMarker(const int64_t timestamp, const int64_t pauselength)
{
}

void OutputFormatEDL::TextMarker(const std::string text)
{
}
