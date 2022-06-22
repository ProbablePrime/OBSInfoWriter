
// note: the external symbols are defined in obs-module.h

#include <obs-module.h>
#include <obs-frontend-api/obs-frontend-api.h>
#include <Groundfloor/Materials/FileWriter.h>
#include <Groundfloor/Materials/Functions.h>
#include <Groundfloor/Atoms/Defines.h>
#include "InfoWriter.h"

const char *infowriter_idname = "infowriter";
const char *logfile_filter = "All formats (*.*)";
const char *setting_file = "file";
const char *setting_format = "format";
const char* setting_outputformat = "outputformat";
const char *setting_shouldlogscenechanges = "logscenechanges";
const char *setting_shouldlogstreaming = "logstreaming";
const char* setting_shouldlogabsolutetime = "logabsolutetime";
const char* setting_shouldloghotkeyspecifics = "loghotkeyspecifics";
const int numberOfHotkeys = 14;

std::string colors[16] = { "Blue","Cyan","Green","Yellow","Red","Pink","Purple","Fuchsia","Rose","Lavender","Sky","Mint","Lemon","Sand","Cocoa","Cream" };

void obstudio_infowriter_write_hotkey1(void *data, obs_hotkey_id id, obs_hotkey_t *hotkey, bool pressed)
{
   UNUSED_PARAMETER(id);
   UNUSED_PARAMETER(hotkey);

   if (pressed)
   {
      InfoWriter *Writer = static_cast<InfoWriter *>(data);

      Writer->WriteInfo(1);
   }
}

void obstudio_infowriter_write_hotkey2(void *data, obs_hotkey_id id, obs_hotkey_t *hotkey, bool pressed)
{
   UNUSED_PARAMETER(id);
   UNUSED_PARAMETER(hotkey);

   if (pressed)
   {
      InfoWriter *Writer = static_cast<InfoWriter *>(data);

      Writer->WriteInfo(2);
   }
}

void obstudio_infowriter_write_hotkey3(void *data, obs_hotkey_id id, obs_hotkey_t *hotkey, bool pressed)
{
   UNUSED_PARAMETER(id);
   UNUSED_PARAMETER(hotkey);

   if (pressed)
   {
      InfoWriter *Writer = static_cast<InfoWriter *>(data);

      Writer->WriteInfo(3);
   }
}

void obstudio_infowriter_write_hotkey4(void *data, obs_hotkey_id id, obs_hotkey_t *hotkey, bool pressed)
{
   UNUSED_PARAMETER(id);
   UNUSED_PARAMETER(hotkey);

   if (pressed)
   {
      InfoWriter *Writer = static_cast<InfoWriter *>(data);

      Writer->WriteInfo(4);
   }
}

void obstudio_infowriter_write_hotkey5(void *data, obs_hotkey_id id, obs_hotkey_t *hotkey, bool pressed)
{
   UNUSED_PARAMETER(id);
   UNUSED_PARAMETER(hotkey);

   if (pressed)
   {
      InfoWriter *Writer = static_cast<InfoWriter *>(data);

      Writer->WriteInfo(5);
   }
}

void obstudio_infowriter_write_hotkey6(void *data, obs_hotkey_id id, obs_hotkey_t *hotkey, bool pressed)
{
	UNUSED_PARAMETER(id);
	UNUSED_PARAMETER(hotkey);

	if (pressed)
	{
		InfoWriter *Writer = static_cast<InfoWriter *>(data);

		Writer->WriteInfo(6);
	}
}

void obstudio_infowriter_write_hotkey7(void *data, obs_hotkey_id id, obs_hotkey_t *hotkey, bool pressed)
{
	UNUSED_PARAMETER(id);
	UNUSED_PARAMETER(hotkey);

	if (pressed)
	{
		InfoWriter *Writer = static_cast<InfoWriter *>(data);

		Writer->WriteInfo(7);
	}
}
void obstudio_infowriter_write_hotkey8(void *data, obs_hotkey_id id, obs_hotkey_t *hotkey, bool pressed)
{
	UNUSED_PARAMETER(id);
	UNUSED_PARAMETER(hotkey);

	if (pressed)
	{
		InfoWriter *Writer = static_cast<InfoWriter *>(data);

		Writer->WriteInfo(8);
	}
}
void obstudio_infowriter_write_hotkey9(void *data, obs_hotkey_id id, obs_hotkey_t *hotkey, bool pressed)
{
	UNUSED_PARAMETER(id);
	UNUSED_PARAMETER(hotkey);

	if (pressed)
	{
		InfoWriter *Writer = static_cast<InfoWriter *>(data);

		Writer->WriteInfo(9);
	}
}
void obstudio_infowriter_write_hotkey10(void *data, obs_hotkey_id id, obs_hotkey_t *hotkey, bool pressed)
{
	UNUSED_PARAMETER(id);
	UNUSED_PARAMETER(hotkey);

	if (pressed)
	{
		InfoWriter *Writer = static_cast<InfoWriter *>(data);

		Writer->WriteInfo(10);
	}
}
void obstudio_infowriter_write_hotkey11(void *data, obs_hotkey_id id, obs_hotkey_t *hotkey, bool pressed)
{
	UNUSED_PARAMETER(id);
	UNUSED_PARAMETER(hotkey);

	if (pressed)
	{
		InfoWriter *Writer = static_cast<InfoWriter *>(data);

		Writer->WriteInfo(11);
	}
}
void obstudio_infowriter_write_hotkey12(void *data, obs_hotkey_id id, obs_hotkey_t *hotkey, bool pressed)
{
	UNUSED_PARAMETER(id);
	UNUSED_PARAMETER(hotkey);

	if (pressed)
	{
		InfoWriter *Writer = static_cast<InfoWriter *>(data);

		Writer->WriteInfo(12);
	}
}
void obstudio_infowriter_write_hotkey13(void *data, obs_hotkey_id id, obs_hotkey_t *hotkey, bool pressed)
{
	UNUSED_PARAMETER(id);
	UNUSED_PARAMETER(hotkey);

	if (pressed)
	{
		InfoWriter *Writer = static_cast<InfoWriter *>(data);

		Writer->WriteInfo(13);
	}
}
void obstudio_infowriter_write_hotkey14(void *data, obs_hotkey_id id, obs_hotkey_t *hotkey, bool pressed)
{
	UNUSED_PARAMETER(id);
	UNUSED_PARAMETER(hotkey);

	if (pressed)
	{
		InfoWriter *Writer = static_cast<InfoWriter *>(data);

		Writer->WriteInfo(14);
	}
}

const char *obstudio_infowriter_get_name(void *type_data)
{
   UNUSED_PARAMETER(type_data);

   return infowriter_idname;
}

void LogSceneChange(InfoWriter *Writer, const std::string scenename)
{
   auto WriterSettings = Writer->GetSettings();

   if (WriterSettings->GetShouldLogSceneChanges())
   {
      Writer->WriteSceneChange(scenename);
   }
}

void obsstudio_infowriter_frontend_event_callback(enum obs_frontend_event event, void *private_data)
{
   InfoWriter *Writer = static_cast<InfoWriter *>(private_data);

   if (event == OBS_FRONTEND_EVENT_STREAMING_STARTED)
   {
	  Writer->MarkStart(imtStream);   
   }
   else if (event == OBS_FRONTEND_EVENT_RECORDING_STARTED)
   {
      Writer->MarkStart(imtRecording);
   }
   else if (event == OBS_FRONTEND_EVENT_STREAMING_STOPPED)
   {
		if (Writer->IsStreaming()) Writer->MarkStop(imtStream); 
   }
   else if (event == OBS_FRONTEND_EVENT_RECORDING_STOPPED)
   {
	   Writer->MarkStop(imtRecording);
   }
   else if (event == OBS_FRONTEND_EVENT_RECORDING_PAUSED)
   {
	   Writer->MarkPauseStart(imtRecordingPauseStart);
   }
   else if (event == OBS_FRONTEND_EVENT_RECORDING_UNPAUSED)
   {
	   Writer->MarkPauseResume(imtRecordingPauseResume);
   }
   else if (event == OBS_FRONTEND_EVENT_SCENE_CHANGED)
   {
      auto scene = obs_frontend_get_current_scene();
      std::string scenename = obs_source_get_name(scene);
      obs_source_release(scene);

      LogSceneChange(Writer, scenename);
   }
}

void *obstudio_infowriter_create(obs_data_t *settings, obs_source_t *source)
{
   InfoWriter *Writer = new InfoWriter();

   UNUSED_PARAMETER(settings);

   obs_hotkey_register_source(source, "InfoWriter", "Hotkey 1", obstudio_infowriter_write_hotkey1, Writer);
   obs_hotkey_register_source(source, "InfoWriter.Hotkey2", "Hotkey 2", obstudio_infowriter_write_hotkey2, Writer);
   obs_hotkey_register_source(source, "InfoWriter.Hotkey3", "Hotkey 3", obstudio_infowriter_write_hotkey3, Writer);
   obs_hotkey_register_source(source, "InfoWriter.Hotkey4", "Hotkey 4", obstudio_infowriter_write_hotkey4, Writer);
   obs_hotkey_register_source(source, "InfoWriter.Hotkey5", "Hotkey 5", obstudio_infowriter_write_hotkey5, Writer);
   obs_hotkey_register_source(source, "InfoWriter.Hotkey6", "Hotkey 6", obstudio_infowriter_write_hotkey6, Writer);
   obs_hotkey_register_source(source, "InfoWriter.Hotkey7", "Hotkey 7", obstudio_infowriter_write_hotkey7, Writer);
   obs_hotkey_register_source(source, "InfoWriter.Hotkey8", "Hotkey 8", obstudio_infowriter_write_hotkey8, Writer);
   obs_hotkey_register_source(source, "InfoWriter.Hotkey9", "Hotkey 9", obstudio_infowriter_write_hotkey9, Writer);
   obs_hotkey_register_source(source, "InfoWriter.Hotkey10", "Hotkey 10", obstudio_infowriter_write_hotkey10, Writer);
   obs_hotkey_register_source(source, "InfoWriter.Hotkey11", "Hotkey 11", obstudio_infowriter_write_hotkey11, Writer);
   obs_hotkey_register_source(source, "InfoWriter.Hotkey12", "Hotkey 12", obstudio_infowriter_write_hotkey12, Writer);
   obs_hotkey_register_source(source, "InfoWriter.Hotkey13", "Hotkey 13", obstudio_infowriter_write_hotkey13, Writer);
   obs_hotkey_register_source(source, "InfoWriter.Hotkey14", "Hotkey 14", obstudio_infowriter_write_hotkey14, Writer);

   obs_frontend_add_event_callback(obsstudio_infowriter_frontend_event_callback, Writer);

   return Writer;
}

void obstudio_infowriter_add_hotkey(obs_properties_t* props, int number) {
	std::string settingKey = "hotkey" + std::to_string(number);
	std::string settingKeyText = settingKey + "text";
	std::string settingKeyColor = settingKey + "color";

	std::string textLabel = "Hotkey " + std::to_string(number) + " Text";
	std::string colorLabel = "Hotkey " + std::to_string(number) + " Color";

	obs_properties_add_text(props, settingKeyText.c_str(), obs_module_text(textLabel.c_str()), OBS_TEXT_DEFAULT);

	auto list = obs_properties_add_list(props, settingKeyColor.c_str(), obs_module_text(colorLabel.c_str()), OBS_COMBO_TYPE_LIST, OBS_COMBO_FORMAT_STRING);
	for (int i = 0; i <= numberOfHotkeys; i++) {
		const char* colorText = colors[i].c_str();
		obs_property_list_add_string(list, colorText, colorText);
	}
}

void obstudio_infowriter_set_defaults(obs_data_t* settings, int number) {
	std::string settingKey = "hotkey" + std::to_string(number);
	std::string settingKeyText = settingKey + "text";
	std::string settingKeyColor = settingKey + "color";
	
	std::string defaultValue = "Hotkey " + std::to_string(number) + " was pressed";
	obs_data_set_default_string(settings, settingKeyText.c_str(), defaultValue.c_str());

	obs_data_set_default_string(settings, settingKeyColor.c_str(), "Blue");
}

obs_properties_t *obstudio_infowriter_properties(void *unused)
{
   UNUSED_PARAMETER(unused);

   obs_properties_t *props = obs_properties_create();

   auto list = obs_properties_add_list(props, setting_outputformat, obs_module_text("Output format"), OBS_COMBO_TYPE_LIST, OBS_COMBO_FORMAT_STRING);
   obs_property_list_add_string(list, "Default", "default");
   obs_property_list_add_string(list, "CSV", "csv");
   obs_property_list_add_string(list, "EDL", "edl");
   obs_property_list_add_string(list, "SRT", "srt");

   obs_properties_add_text(props, setting_format, obs_module_text("Format"), OBS_TEXT_DEFAULT);
   obs_properties_add_path(props, setting_file, obs_module_text("Logfile"), OBS_PATH_FILE_SAVE, logfile_filter, NULL);

   for (int i = 1; i <= numberOfHotkeys; i++) {
	   obstudio_infowriter_add_hotkey(props, i);
   }

   obs_properties_add_bool(props, setting_shouldlogscenechanges, obs_module_text("Log Scene changes"));
   obs_properties_add_bool(props, setting_shouldlogstreaming, obs_module_text("Log Streaming events (applies to default output)"));
   obs_properties_add_bool(props, setting_shouldlogabsolutetime, obs_module_text("Log intermediate absolute times (applies to default output)"));
   obs_properties_add_bool(props, setting_shouldloghotkeyspecifics, obs_module_text("Log hotkey specifics (applies to default output)"));

   return props;
}


void obstudio_infowriter_get_defaults(obs_data_t *settings)
{
   obs_data_set_default_string(settings, setting_outputformat, "default");
   obs_data_set_default_string(settings, setting_file, "/tmp/log.txt");
   obs_data_set_default_string(settings, setting_format, "%d:%02d:%02d");

   for (int i = 1; i <= numberOfHotkeys; i++) {
	   obstudio_infowriter_set_defaults(settings, i);
   }

   obs_data_set_default_bool(settings, setting_shouldlogscenechanges, true);
   obs_data_set_default_bool(settings, setting_shouldlogstreaming, false);
   obs_data_set_default_bool(settings, setting_shouldlogabsolutetime, true);
   obs_data_set_default_bool(settings, setting_shouldloghotkeyspecifics, true);
}

void  obsudio_infowriter_set_settings(InfoWriterSettings* WriterSettings, obs_data_t *settings, int number) {
	std::string settingKey = "hotkey" + std::to_string(number);
	std::string settingKeyText = settingKey + "text";
	std::string settingKeyColor = settingKey + "color";
	
	const char* hotkeytext;
	hotkeytext = obs_data_get_string(settings, settingKeyText.c_str());
	WriterSettings->SetHotkeyText(number, hotkeytext);

	const char* hotkeyColor;
	hotkeyColor = obs_data_get_string(settings, settingKeyColor.c_str());
	WriterSettings->SetHotkeyColor(number, hotkeyColor);
}

void obstudio_infowriter_update(void *data, obs_data_t *settings)
{
   InfoWriter *Writer = static_cast<InfoWriter *>(data);

   const char *outputformat = obs_data_get_string(settings, setting_outputformat);

   const char *file = obs_data_get_string(settings, setting_file);
   const char *format = obs_data_get_string(settings, setting_format);

   auto WriterSettings = Writer->GetSettings();

   WriterSettings->SetOutputFormat(outputformat);
   WriterSettings->SetFilename(file);
   WriterSettings->SetFormat(format);

   for (int i = 1; i <= numberOfHotkeys; i++) {
	   obsudio_infowriter_set_settings(WriterSettings, settings, i);
   }

   WriterSettings->SetShouldLogSceneChanges(obs_data_get_bool(settings, setting_shouldlogscenechanges));
   WriterSettings->SetShouldLogStreaming(obs_data_get_bool(settings, setting_shouldlogstreaming));
   WriterSettings->SetShouldLogAbsoluteTime(obs_data_get_bool(settings, setting_shouldlogabsolutetime));
   WriterSettings->SetShouldLogHotkeySpecifics(obs_data_get_bool(settings, setting_shouldloghotkeyspecifics));
}

uint32_t obstudio_infowriter_get_width(void *data)
{
   UNUSED_PARAMETER(data);

   return 0;
}

uint32_t obstudio_infowriter_get_height(void *data)
{
   UNUSED_PARAMETER(data);

   return 0;
}

void obstudio_infowriter_destroy(void *data)
{
   InfoWriter *Writer = static_cast<InfoWriter *>(data);
   if (Writer != nullptr)
   {
      if (Writer->HasStarted())
      {
         Writer->MarkStop(imtUnknown);
      }

      obs_frontend_remove_event_callback(obsstudio_infowriter_frontend_event_callback, Writer);

      delete Writer;
   }
}

struct obs_source_info obstudio_infowriter_source;

OBS_DECLARE_MODULE()
OBS_MODULE_USE_DEFAULT_LOCALE("OBSInfoWriter", "en-US")

void obstudio_infowriter_setup()
{
   obstudio_infowriter_source.id = infowriter_idname;
   obstudio_infowriter_source.type = OBS_SOURCE_TYPE_INPUT;
   obstudio_infowriter_source.get_name = obstudio_infowriter_get_name;
   obstudio_infowriter_source.create = obstudio_infowriter_create;
   obstudio_infowriter_source.destroy = obstudio_infowriter_destroy;
   obstudio_infowriter_source.get_width = obstudio_infowriter_get_width;
   obstudio_infowriter_source.get_height = obstudio_infowriter_get_height;
   obstudio_infowriter_source.get_properties = obstudio_infowriter_properties;
   obstudio_infowriter_source.update = obstudio_infowriter_update;
   obstudio_infowriter_source.load = obstudio_infowriter_update;
   obstudio_infowriter_source.get_defaults = obstudio_infowriter_get_defaults;

   obs_register_source(&obstudio_infowriter_source);
}

bool obs_module_load(void)
{
   obstudio_infowriter_setup();

   return true;
}

void obs_module_unload(void)
{
}
