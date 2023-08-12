@ECHO OFF
CD %~dp0
copy VJoy32.dll "..\..\dlls\"
copy VJoy32.lib "..\..\dlls\"
copy VJoy32.dll "..\..\C#\bin\Debug\"
copy VJoy32.dll "..\..\VB.NET\bin\Debug\"
copy VJoy32.lib "..\..\C++\"
copy VJoy64.dll "..\..\dlls\"
copy VJoy64.lib "..\..\dlls\"
copy VJoy64.dll "..\..\C#\bin\Debug\"
copy VJoy64.dll "..\..\VB.NET\bin\Debug\"
copy VJoy64.lib "..\..\C++\"
copy ..\VJoy.h "..\..\C++"
