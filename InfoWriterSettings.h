#pragma once

#include <string>

class InfoWriterSettings
{
protected:
   std::string OutputFormat;
   std::string Filename;
   std::string Format;

   std::string HotKeyText[14] = {};
   std::string HotKeyColor[14] = {};

   bool ShouldLogSceneChanges;
   bool ShouldLogStreaming;
   bool ShouldLogAbsoluteTime;
   bool ShouldLogHotkeySpecifics;

public:
   std::string GetOutputFormat() const;
   std::string GetFilename() const;
   std::string GetFormat() const;
   std::string GetHotkeyText(const int hotkeynum) const;
   std::string GetHotkeyColor(const int hotkeynum) const;

   bool GetShouldLogSceneChanges() const;
   bool GetShouldLogStreaming() const;
   bool GetShouldLogAbsoluteTime() const;
   bool GetShouldLogHotkeySpecifics() const;

   void SetOutputFormat(std::string formatname);
   void SetFilename(std::string filename);
   void SetFormat(std::string format);
   void SetHotkeyText(const int hotkeynum, std::string text);
   void SetHotkeyColor(const int hotkeynum, std::string text);
   void SetShouldLogSceneChanges(bool logchanges);
   void SetShouldLogStreaming(bool logchanges);
   void SetShouldLogAbsoluteTime(bool log);
   void SetShouldLogHotkeySpecifics(bool log);
};
