# PluginTemplate

Plugin templates for x64dbg.

## Installation & Usage

Grab the latest [release](https://github.com/x64dbg/PluginTemplate/releases/latest) and copy `*.zip` to `Documents\Visual Studio 2013\Templates\ProjectTemplates\Visual C++ Project\`. You can now use `File -> New -> Project...` and select a template to create an x64dbg plugin.

## Building (not relevant if you just want to use the template)

1. Use `File -> Export Template...`.
2. Append the content of `templatefiles.txt` to `<TemplateContent>` in `MyTemplate.vstemplate`.
3. Set `ReplaceParameters="true"` for `plugin.h` in `MyTemplate.vstemplate`.
3. Copy the `pluginsdk\*.lib` inside the ZIP.
