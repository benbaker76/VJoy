@ECHO OFF
Signtool sign /v /s "GlobalSign ObjectSign CA" /n "Headsoft" /t http://timestamp.verisign.com/scripts/timestamp.dll amd64\vjoy.sys
Signtool sign /v /s "GlobalSign ObjectSign CA" /n "Headsoft" /t http://timestamp.verisign.com/scripts/timestamp.dll i386\vjoy.sys
Signtool sign /v /s "GlobalSign ObjectSign CA" /n "Headsoft" /t http://timestamp.verisign.com/scripts/timestamp.dll ia64\vjoy.sys
