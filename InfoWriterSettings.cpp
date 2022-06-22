#include "InfoWriterSettings.h"

std::string InfoWriterSettings::GetOutputFormat() const
{
   return OutputFormat;
}

std::string InfoWriterSettings::GetFilename() const
{
   return Filename;
}

std::string InfoWriterSettings::GetFormat() const
{
   return Format;
}

std::string InfoWriterSettings::GetHotkeyText(const int hotkeynum) const
{
	return HotKeyText[hotkeynum - 1];
}

std::string InfoWriterSettings::GetHotkeyColor(const int hotkeynum) const
{
	return HotKeyColor[hotkeynum - 1];
}

bool InfoWriterSettings::GetShouldLogSceneChanges() const
{
	return ShouldLogSceneChanges;
}

bool InfoWriterSettings::GetShouldLogStreaming() const
{
	return ShouldLogStreaming;
}

bool InfoWriterSettings::GetShouldLogAbsoluteTime() const
{
   return this->ShouldLogAbsoluteTime;
}

bool InfoWriterSettings::GetShouldLogHotkeySpecifics() const
{
   return this->ShouldLogHotkeySpecifics;
}

void InfoWriterSettings::SetOutputFormat(std::string formatname)
{
   OutputFormat = formatname;
}

void InfoWriterSettings::SetFilename(std::string filename)
{
   this->Filename = filename;
}

void InfoWriterSettings::SetFormat(std::string format)
{
   this->Format = format;
}

void InfoWriterSettings::SetHotkeyText(const int hotkeynum, std::string text)
{
	HotKeyText[hotkeynum - 1] = text;
}

void InfoWriterSettings::SetHotkeyColor(const int hotkeynum, std::string text)
{
	HotKeyColor[hotkeynum - 1] = text;
}

void InfoWriterSettings::SetShouldLogSceneChanges(bool logchanges)
{
	ShouldLogSceneChanges = logchanges;
}

void InfoWriterSettings::SetShouldLogStreaming(bool logchanges)
{
	ShouldLogStreaming = logchanges;
}

void InfoWriterSettings::SetShouldLogAbsoluteTime(bool log)
{
   this->ShouldLogAbsoluteTime = log;
}

void InfoWriterSettings::SetShouldLogHotkeySpecifics(bool log)
{
   this->ShouldLogHotkeySpecifics = log;
}
