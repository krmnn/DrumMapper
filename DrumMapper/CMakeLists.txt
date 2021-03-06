cmake_minimum_required(VERSION 3.4)

project("DrumMapper")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../FRUT/prefix/FRUT/cmake")
include(Reprojucer)

set(JUCE_MODULES_GLOBAL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../JUCE/modules")
set(EXT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../Ext")

jucer_project_begin(
  JUCER_FORMAT_VERSION "1"
)

jucer_project_settings(
    PROJECT_NAME "DrumMapper"
  PROJECT_VERSION "0.0.1"
  COMPANY_NAME "krmnn"
  REPORT_JUCE_APP_USAGE OFF # Required for closed source applications without an Indie or Pro JUCE license
  DISPLAY_THE_JUCE_SPLASH_SCREEN OFF # Required for closed source applications without an Indie or Pro JUCE license
  PROJECT_TYPE "Audio Plug-in"
  BUNDLE_IDENTIFIER "com.krmnn.DrumMapper"
  CXX_LANGUAGE_STANDARD "C++14"
  HEADER_SEARCH_PATHS 
  "${EXT_PATH}/JBPluginBase/Ext/json/include"
)

jucer_audio_plugin_settings(
  PLUGIN_FORMATS
    "VST3"
    "AU"
    "Standalone"
  PLUGIN_CHARACTERISTICS
    "Plugin MIDI Input"
    "Plugin MIDI Output"
    "MIDI Effect Plugin"
  PLUGIN_NAME "DrumMapper"
  PLUGIN_DESCRIPTION "DrumMapper"
  PLUGIN_MANUFACTURER "krmnn"
  PLUGIN_MANUFACTURER_CODE "Manu"
  PLUGIN_CODE "Jwxw"
  # PLUGIN_CHANNEL_CONFIGURATIONS
  PLUGIN_AAX_IDENTIFIER "com.krmnn.DrumMapper"
  PLUGIN_AU_EXPORT_PREFIX "DrumMapperAU"
  PLUGIN_AU_MAIN_TYPE "kAudioUnitType_MIDIProcessor"
  PLUGIN_VST_NUM_MIDI_INPUTS "16"
  PLUGIN_VST_NUM_MIDI_OUTPUTS "16"
  PLUGIN_VST3_CATEGORY
    "Fx"
  PLUGIN_RTAS_CATEGORY
    "ePlugInCategory_None"
  PLUGIN_AAX_CATEGORY
    "AAX_ePlugInCategory_None"
  PLUGIN_VST_LEGACY_CATEGORY "kPlugCategEffect"
)

jucer_project_files("DrumMapper/Source/Source"
# Compile   Xcode     Binary    File
#           Resource  Resource
  .         .         .         "Source/OJDLookAndFeel.h"
  x         .         .         "Source/OJDParameters.cpp"
  .         .         .         "Source/OJDParameters.h"
  x         .         .         "Source/PluginProcessor.cpp"
  .         .         .         "Source/PluginProcessor.h"
  x         .         .         "Source/ProcessorEditor.cpp"
  .         .         .         "Source/ProcessorEditor.h"
)

jucer_project_module(
  jb_plugin_base
  PATH "${EXT_PATH}/JBPluginBase"
  JB_INCLUDE_JSON YES
)

jucer_project_module(
  juce_audio_basics
  PATH "${JUCE_MODULES_GLOBAL_PATH}"
)

jucer_project_module(
  juce_audio_devices
  PATH "${JUCE_MODULES_GLOBAL_PATH}"
  # JUCE_USE_WINRT_MIDI
  # JUCE_ASIO
  # JUCE_WASAPI
  # JUCE_DIRECTSOUND
  # JUCE_ALSA
  # JUCE_JACK
  # JUCE_BELA
  # JUCE_USE_ANDROID_OBOE
  # JUCE_USE_OBOE_STABILIZED_CALLBACK
  # JUCE_USE_ANDROID_OPENSLES
  # JUCE_DISABLE_AUDIO_MIXING_WITH_OTHER_APPS
)

jucer_project_module(
  juce_audio_formats
  PATH "${JUCE_MODULES_GLOBAL_PATH}"
  # JUCE_USE_FLAC
  # JUCE_USE_OGGVORBIS
  # JUCE_USE_MP3AUDIOFORMAT
  # JUCE_USE_LAME_AUDIO_FORMAT
  # JUCE_USE_WINDOWS_MEDIA_FORMAT
)

jucer_project_module(
  juce_audio_plugin_client
  PATH "${JUCE_MODULES_GLOBAL_PATH}"
  JUCE_VST3_CAN_REPLACE_VST2 OFF
  # JUCE_FORCE_USE_LEGACY_PARAM_IDS
  # JUCE_FORCE_LEGACY_PARAMETER_AUTOMATION_TYPE
  # JUCE_USE_STUDIO_ONE_COMPATIBLE_PARAMETERS
  # JUCE_AU_WRAPPERS_SAVE_PROGRAM_STATES
  # JUCE_STANDALONE_FILTER_WINDOW_USE_KIOSK_MODE
)

jucer_project_module(
  juce_audio_processors
  PATH "${JUCE_MODULES_GLOBAL_PATH}"
  # JUCE_PLUGINHOST_VST
  # JUCE_PLUGINHOST_VST3
  # JUCE_PLUGINHOST_AU
  # JUCE_PLUGINHOST_LADSPA
  # JUCE_CUSTOM_VST3_SDK
)

jucer_project_module(
  juce_audio_utils
  PATH "${JUCE_MODULES_GLOBAL_PATH}"
  # JUCE_USE_CDREADER
  # JUCE_USE_CDBURNER
)

jucer_project_module(
  juce_core
  PATH "${JUCE_MODULES_GLOBAL_PATH}"
  # JUCE_FORCE_DEBUG
  # JUCE_LOG_ASSERTIONS
  # JUCE_CHECK_MEMORY_LEAKS
  # JUCE_DONT_AUTOLINK_TO_WIN32_LIBRARIES
  # JUCE_INCLUDE_ZLIB_CODE
  # JUCE_USE_CURL
  # JUCE_LOAD_CURL_SYMBOLS_LAZILY
  # JUCE_CATCH_UNHANDLED_EXCEPTIONS
  # JUCE_ALLOW_STATIC_NULL_VARIABLES
  JUCE_STRICT_REFCOUNTEDPOINTER ON
  # JUCE_ENABLE_ALLOCATION_HOOKS
)

jucer_project_module(
  juce_data_structures
  PATH "${JUCE_MODULES_GLOBAL_PATH}"
)

jucer_project_module(
  juce_events
  PATH "${JUCE_MODULES_GLOBAL_PATH}"
  # JUCE_EXECUTE_APP_SUSPEND_ON_BACKGROUND_TASK
)

jucer_project_module(
  juce_graphics
  PATH "${JUCE_MODULES_GLOBAL_PATH}"
  # JUCE_USE_COREIMAGE_LOADER
  # JUCE_USE_DIRECTWRITE
  # JUCE_DISABLE_COREGRAPHICS_FONT_SMOOTHING
)

jucer_project_module(
  juce_gui_basics
  PATH "${JUCE_MODULES_GLOBAL_PATH}"
  # JUCE_ENABLE_REPAINT_DEBUGGING
  # JUCE_USE_XRANDR
  # JUCE_USE_XINERAMA
  # JUCE_USE_XSHM
  # JUCE_USE_XRENDER
  # JUCE_USE_XCURSOR
  # JUCE_WIN_PER_MONITOR_DPI_AWARE
)

jucer_project_module(
  juce_gui_extra
  PATH "${JUCE_MODULES_GLOBAL_PATH}"
  # JUCE_WEB_BROWSER
  # JUCE_USE_WIN_WEBVIEW2
  # JUCE_ENABLE_LIVE_CONSTANT_EDITOR
)

jucer_export_target(
  "Xcode (MacOSX)"
  TARGET_PROJECT_FOLDER "Builds/MacOSX" # used by HEADER_SEARCH_PATHS
  # VST3_SDK_FOLDER
)

jucer_export_target_configuration(
  "Xcode (MacOSX)"
  NAME "Debug"
  DEBUG_MODE ON
  BINARY_NAME "DrumMapper"
  HEADER_SEARCH_PATHS
  "${EXT_PATH}/JBPluginBase/Ext/json/include"
)

jucer_export_target_configuration(
  "Xcode (MacOSX)"
  NAME "Release"
  DEBUG_MODE OFF
  BINARY_NAME "DrumMapper"
  HEADER_SEARCH_PATHS
  "${EXT_PATH}/JBPluginBase/Ext/json/include"
)

jucer_export_target(
  "Linux Makefile"
  # EXTRA_COMPILER_FLAGS
  # EXTRA_LINKER_FLAGS
)

jucer_export_target_configuration(
    "Linux Makefile"
    NAME "Debug"
    DEBUG_MODE ON
    ADD_RECOMMENDED_COMPILER_WARNING_FLAGS Disabled
    BINARY_NAME "DrumMapper"
    HEADER_SEARCH_PATHS
    "${EXT_PATH}/JBPluginBase/Ext/json/include"
    )

jucer_export_target_configuration(
    "Linux Makefile"
    NAME "Release"
    DEBUG_MODE OFF
    ADD_RECOMMENDED_COMPILER_WARNING_FLAGS Disabled
    BINARY_NAME "DrumMapper"
    HEADER_SEARCH_PATHS
    "${EXT_PATH}/JBPluginBase/Ext/json/include"
    )

jucer_export_target("Visual Studio 2019")

jucer_export_target_configuration(
  "Visual Studio 2019"
  NAME "Debug"
  DEBUG_MODE ON
  HEADER_SEARCH_PATHS
  "${EXT_PATH}/JBPluginBase/Ext/json/include"
)

jucer_export_target_configuration(
  "Visual Studio 2019"
  NAME "Release"
  DEBUG_MODE OFF
  HEADER_SEARCH_PATHS
  "${EXT_PATH}/JBPluginBase/Ext/json/include"
)

jucer_project_end()
